noinst_LIBRARIES = libwoodycxx_net.a

bin_PROGRAMS = Test_InetSocketAddress Test_InetAddress Test_AbstractSocketImpl

libwoodycxx_net_a_SOURCES = SocketsOpt.cpp InetAddress.cpp InetSocketAddress.cpp SocketInputStream.cpp SocketOutputStream.cpp AbstractSocketImpl.cpp

Test_InetAddress_SOURCES = Test_InetAddress.cpp
Test_InetAddress_LDADD = libwoodycxx_net.a
Test_InetSocketAddress_SOURCES = Test_InetSocketAddress.cpp
Test_InetSocketAddress_LDADD = libwoodycxx_net.a ../sysipc/libsysipc.a
Test_AbstractSocketImpl_SOURCES = Test_AbstractSocketImpl.cpp
Test_AbstractSocketImpl_LDADD = libwoodycxx_net.a ../io/libwoodycxx_io.a ../sysipc/libsysipc.a
