#include <assert.h>
#include <config/xf-config.h>

#if (USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION != 0)

#include "mutex-default.h"

/**
 * @brief Implementation of interface::XFMutex::create method.
 */
interface::XFMutex * interface::XFMutex::create()
{
    return new XFMutexDefault;
}

XFMutexDefault::XFMutexDefault() :
	_mutexId(0)
{
	_mutexId = osMutexCreate(&_mutexDefinition);
	assert(_mutexId);
}

XFMutexDefault::~XFMutexDefault()
{

}

void XFMutexDefault::lock()
{
	assert(_mutexId);
	osStatus status = osMutexWait(_mutexId, osWaitForever);
	assert(status == osOK);
}


void XFMutexDefault::unlock()
{
	osStatus status = osMutexRelease(_mutexId);
	assert(status == osOK);
}


bool XFMutexDefault::tryLock(int32_t timeout /* = 0 */)
{
	osStatus status = osMutexWait(_mutexId, timeout);
	return (status == osOK) ? true : false;
}

#endif // USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION
