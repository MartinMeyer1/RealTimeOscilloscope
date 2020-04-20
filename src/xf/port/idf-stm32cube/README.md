# XF Port - IDF Stm32Cube

This port folder contains specific classes for the _IDF Stm32Cube_
XF port.

# Classes used by the _IDF Stm32Cube_ Port

| Class name | File location | Define to set |
|--|--|--|
| XF | xf/port/default/xf-default.cpp | USE_XF_DEFAULT_IMPLEMENTATION |
| XFDispatcherDefault | xf/port/default/dispatcher-default.cpp | USE_XF_DISPATCHER_DEFAULT_IMPLEMENTATION |
| XFTimeoutManagerDefault | xf/port/default/timeoutmanager-default.cpp | USE_XF_TIMEOUTMANAGER_DEFAULT_IMPLEMENTATION |
| XFResourceFactoryDefault | xf/port/default/resourcefactory-default.cpp | USE_XF_RESOURCE_FACTORY_DEFAULT_IMPLEMENTATION |
| XFMutexDefault | xf/port/default-idf/mutex-default.cpp | USE_XF_MUTEX_DEFAULT_IDF_IMPLEMENTATION |
| XFEventQueueDefault | xf/port/default-idf/eventqueue-default.cpp | USE_XF_EVENT_QUEUE_DEFAULT_IDF_IMPLEMENTATION |
| Port Functions | xf/port/idf-stm32cube/port-functions.cpp | USE_XF_PORT_IDF_STM32CUBE_PORT_FUNCTIONS_IMPLEMENTATION |

# Example _config/xf-config.h_ File
```c++
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
