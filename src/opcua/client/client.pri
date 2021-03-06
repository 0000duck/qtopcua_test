# QQtOpcUa client module

PUBLIC_HEADERS += \
    client/qopcuaclient.h \
    client/qopcuanode.h \
    client/qopcuatype.h

SOURCES += \
    client/qopcuaclient.cpp \
    client/qopcuanode.cpp \
    client/qopcuatype.cpp \
    client/qopcuaclientimpl.cpp \
    client/qopcuanodeimpl.cpp \
    client/qopcuaclientprivate.cpp \
    client/qopcuabackend.cpp \
    client/qopcuamonitoringparameters.cpp \
    client/qopcuareferencedescription.cpp \
    client/qopcuabinarydataencoding.cpp

HEADERS += \
    client/qopcuaclient_p.h \
    client/qopcuaclientimpl_p.h \
    client/qopcuanode_p.h \
    client/qopcuanodeimpl_p.h \
    client/qopcuabackend_p.h \
    client/qopcuamonitoringparameters.h \
    client/qopcuamonitoringparameters_p.h \
    client/qopcuareferencedescription.h \
    client/qopcuareferencedescription_p.h \
    client/qopcuabinarydataencoding_p.h
