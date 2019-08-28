TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        DDoS.cpp \
        ETHERNET.cpp \
        IPHEADER.cpp \
        PacketManager.cpp \
        UDPHeader.cpp \
        etc_function.cpp \
        main.cpp \
        TCPHeader.cpp

LIBS += -lpcap
LIBS += -pthread

HEADERS += \
    DDoS.h \
    DDoSTool.h \
    ETHERNET.h \
    Header.h \
    IPHEADER.h \
    PacketManager.h \
    TCPHeader.h \
    UDPHeader.h \
    etc_function.h
