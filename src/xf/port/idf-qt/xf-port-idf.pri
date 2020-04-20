
INCLUDEPATH += $$PWD/..

# Path to default implementation of the XF port
DEFAULT_IMPL_PATH = $$PWD/../default

DEFAULT_IMPL_SOURCES += \
    $${DEFAULT_IMPL_PATH}/timeoutmanager-default.cpp \
    $${DEFAULT_IMPL_PATH}/dispatcher-active.cpp

DEFAULT_IMPL_HEADERS += \
    $${DEFAULT_IMPL_PATH}/timeoutmanager-default.h \
    $${DEFAULT_IMPL_PATH}/dispatcher-active.h

SOURCES += \
    $${DEFAULT_IMPL_SOURCES}$$ \
    $$PWD/xf.cpp \
    $$PWD/port-functions.cpp \
    $$PWD/resourcefactory.cpp \
    $$PWD/eventqueue.cpp

HEADERS += \
    $${DEFAULT_IMPL_HEADERS}$$ \
    $$PWD/../port-functions.h \
    $$PWD/resourcefactory.h \
    $$PWD/eventqueue.h
