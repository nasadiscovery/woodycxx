/*
 * InetAddress.cpp
 *
 *  Created on: 2015-1-13
 *      Author: qianchj
 */
#include "InetAddress.h"
#include "SocketsOpt.h"
#include <stdint.h>
#include <assert.h>
#ifdef WIN32
#include <WinSock2.h>
#define bzero(x,y) ZeroMemory(x,y)
typedef uint32_t in_addr_t;
#else
#include <netinet/in.h>
#endif

using namespace woodycxx::net;

InetAddress::InetAddress(uint16_t port, bool loopbackOnly)
{
    bzero(&addr_, sizeof addr_);
    addr_.sin_family = AF_INET;
    in_addr_t ip = loopbackOnly ? INADDR_LOOPBACK : INADDR_ANY;
    addr_.sin_addr.s_addr = htonl(ip);
    addr_.sin_port = htons(port);
}

InetAddress::InetAddress(string ip, uint16_t port)
{
    bzero(&addr_, sizeof addr_);
    sockets::fromIpPort(ip.c_str(), port, &addr_);
}

string InetAddress::getIpPort() const
{
    char buf[32];
    sockets::toIpPort(buf, sizeof buf, addr_);
    return buf;
}

string InetAddress::getIp() const
{
    char buf[32];
    sockets::toIp(buf, sizeof buf, addr_);
    return buf;
}

uint16_t InetAddress::getPort() const
{
    return ntohs(addr_.sin_port);
}

bool InetAddress::resolve(string hostname, InetAddress* result)
{
    /*
    assert(out != NULL);
    struct hostent hent;
    struct hostent* he = NULL;
    int herrno = 0;
    bzero(&hent, sizeof(hent));

    int ret = gethostbyname_r(hostname.c_str(), &hent, t_resolveBuffer, sizeof t_resolveBuffer, &he, &herrno);
    if (ret == 0 && he != NULL)
    {
        assert(he->h_addrtype == AF_INET && he->h_length == sizeof(uint32_t));
        out->addr_.sin_addr = *reinterpret_cast<struct in_addr*>(he->h_addr);
        return true;
    }
    else
    {
        if (ret)
        {
            LOG_SYSERR << "InetAddress::resolve";
        }
        return false;
    }
    */
    return false;
}