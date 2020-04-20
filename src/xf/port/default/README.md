# XF Default Port

This folder provides default implementations for some platform
indipendent XF classes. 
You can use these classes to construct the XF needed.

If these classes do not suit your needs, they can be reimplemented for
your platform. Create an additional folder in the 'port' folder and
implement there the classes you need for your platform.

# Available Default Port Classes

| Class name | File location | Define to set |
|--|--|--|
| XF | xf/port/default/xf-default.cpp | USE_XF_DEFAULT_IMPLEMENTATION |
| XFResourceFactoryDefault | xf/port/default/resourcefactory-default.cpp | USE_XF_RESOURCE_FACTORY_DEFAULT_IMPLEMENTATION |
| XFTimeoutManagerDefault | xf/port/default/timeoutmanager-default.cpp | USE_XF_TIMEOUTMANAGER_DEFAULT_IMPLEMENTATION |
| XFDispatcherDefault | xf/port/default/dispatcher-default.cpp | USE_XF_DISPATCHER_DEFAULT_IMPLEMENTATION |
| XFDispatcherActiveDefault | xf/port/default/dispatcher-active.cpp | USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION |

If you need more information about the classes mentioned above, please
have a look into their header files and the doxygen comments in code.

# Platform Dependend Default Port Classes
In the following folders you can pick some platform dependend
port classes:

| Platform | Folder |
|--|--|
| CMSIS-OS | [default-cmsis-os](../default-cmsis-os) |
| IDF | [default-idf](../default-idf) |
| QT | [default-qt](../default-qt) |

# Example _config/xf-config.h_ File
Following you will find some examples giving you a basic idea which define
to set in the application specific _config/xf-config.h_ file.

The _IDF Stm32Cube_ port uses quite all default implementations:

```c++
// Defines to set to use the IDF Stm32Cube port
#define USE_XF_DEFAULT_IMPLEMENTATION                                   1
#define USE_XF_DISPATCHER_DEFAULT_IMPLEMENTATION                        1
#define USE_XF_TIMEOUTMANAGER_DEFAULT_IMPLEMENTATION                    1
#define USE_XF_RESOURCE_FACTORY_DEFAULT_IMPLEMENTATION                  1
#define USE_XF_MUTEX_DEFAULT_IDF_IMPLEMENTATION                         1
#define USE_XF_EVENT_QUEUE_DEFAULT_IDF_IMPLEMENTATION                   1
#define USE_XF_PORT_IDF_STM32CUBE_PORT_FUNCTIONS_IMPLEMENTATION         1

#include "default-idf/eventqueue-default.h"
#ifdef __cplusplus
    using XFEventQueue = XFEventQueueDefault;
#endif // __cplusplus
```

If you want to build an XF on Windows, macOS or Linux use the _IDF Qt_ port.
Following defines need to be set in the application specific
_config/xf-config.h_ file:
```c++
// Defines to set to use the IDF Qt port
#define USE_XF_TIMEOUTMANAGER_DEFAULT_IMPLEMENTATION        1
#define USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION     1
#define USE_XF_MUTEX_DEFAULT_QT_IMPLEMENTATION              1
#define USE_XF_THREAD_DEFAULT_QT_IMPLEMENTATION             1

#define USE_XF_PORT_IDF_QT_XF_IMPLEMENTATION                1
#define USE_XF_PORT_IDF_QT_RESOURCE_FACTORY_IMPLEMENTATION  1
#define USE_XF_PORT_IDF_QT_EVENT_QUEUE_IMPLEMENTATION       1
#define USE_XF_PORT_IDF_QT_PORT_FUNCTIONS_IMPLEMENTATION    1

#include "idf-qt/eventqueue.h"
```
