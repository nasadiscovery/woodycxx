#include "InetAddress.h"
#include <iostream>

using namespace woodycxx::net;
using namespace std;

int main()
{
    InetAddress address1(80);
    InetAddress address2("127.0.0.1", 12345);
    InetAddress address3("127.0.k.1", 123);
    cout << "address1.getIpPort() = " << address1.getIpPort() << endl;
    cout << "address2.getIpPort() = " << address2.getIpPort() << endl;
    cout << "address1.getIp() = " << address1.getIp() << endl;
    cout << "address2.getIp() = " << address2.getIp() << endl;
    cout << "address1.getPort() = " << address1.getPort() << endl;
    cout << "address2.getPort() = " << address2.getPort() << endl;
    cout << "address3.getIpPort() = " << address3.getIpPort() << endl;
    return 0;
}