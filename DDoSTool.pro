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
        main.cpp

HEADERS += \
    DDoS.h \
    DDoSTool.h \
    ETHERNET.h \
    Header.h \
    IPHEADER.h \
    PacketManager.h \
    UDPHeader.h