/*
 * InetAddress.h
 *
 *  Created on: 2015-1-13
 *      Author: qianchj
 */

#ifndef Woodycxx_Net_InetAddress_H_
#define Woodycxx_Net_InetAddress_H_

#include <string>
#include <stdint.h>
#include <sys/types.h>
#ifdef WIN32
#include <WinSock2.h>
#else
#include <netinet/in.h>
#endif

using namespace std;

namespace woodycxx { namespace net {

class InetAddress
{
public:
    /// Constructs an endpoint with given port number.
    explicit InetAddress(uint16_t port, bool loopbackonly = false);

    /// Constructs an endpoint with given ip and port.
    InetAddress(string ip, uint16_t port);

    // Constructs an endpoint with given struct @c sockaddr_in
    InetAddress(const struct sockaddr_in& addr)
        : addr_(addr)
    { }

    string getIp() const;
    string getIpPort() const;
    uint16_t getPort() const;

    const struct sockaddr_in& getSockAddrInet() const { return addr_; }
    void setSockAddrInet(const struct sockaddr_in& addr) { addr_ = addr; }

    // resolve hostname to IP address
    // return true on success.
    // thread safe
    static bool resolve(string hostname, InetAddress* result);

private:
    struct sockaddr_in addr_;
};

}}//end of namespace woodycxx::net

#endif
