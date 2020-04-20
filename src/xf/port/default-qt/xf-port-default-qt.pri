
INCLUDEPATH += $$PWD/..

# Path to default qt platform implementation of the XF port
DEFAULT_QT_PATH = $$PWD/../default-qt

INCLUDEPATH += \
    "$${DEFAULT_QT_PATH}"

HEADERS += \
    "$${DEFAULT_QT_PATH}/mutex-default.h" \
    "$${DEFAULT_QT_PATH}/thread-default.h"

SOURCES += \
    "$${DEFAULT_QT_PATH}/mutex-default.cpp" \
    "$${DEFAULT_QT_PATH}/thread-default.cpp"
