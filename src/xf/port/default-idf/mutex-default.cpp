#include <config/xf-config.h>

#if (USE_XF_MUTEX_DEFAULT_IDF_IMPLEMENTATION != 0)

#include "critical/critical.h"	// Provided by the platform used
#include "mutex-default.h"

/**
 * @brief Implementation of interface::XFMutex::create method.
 */
interface::XFMutex * interface::XFMutex::create()
{
    return new XFMutexDefault;
}

XFMutexDefault::XFMutexDefault()
{
}

XFMutexDefault::~XFMutexDefault()
{
}

void XFMutexDefault::lock()
{
	enterCritical();
}


void XFMutexDefault::unlock()
{
	exitCritical();
}

bool XFMutexDefault::tryLock(int32_t timeout /* = 0 */)
{
	return true;	// Always allow
}

#endif // USE_XF_MUTEX_DEFAULT_IDF_IMPLEMENTATION
