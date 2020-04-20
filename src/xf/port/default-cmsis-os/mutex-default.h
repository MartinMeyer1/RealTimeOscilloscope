#ifndef XF_MUTEX_DEFAULT_CMSIS_OS_H
#define XF_MUTEX_DEFAULT_CMSIS_OS_H

#include <config/xf-config.h>

#if (USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION != 0)

#include <stdint.h>
#include <cmsis_os.h>
#include "xf/interface/mutex.h"

/** @ingroup port_default_cmsis_os
 *  @{
 */

/**
 * @brief Default CMSIS-OS imlementation XFMutex interface.
 *
 */
class XFMutexDefault : public interface::XFMutex
{
public:
	XFMutexDefault();
	virtual ~XFMutexDefault();

	virtual void lock();
	virtual void unlock();

	virtual bool tryLock(int32_t timeout = 0);

protected:
	osMutexDef_t _mutexDefinition;
	osMutexId _mutexId;
};

/** @} */ // end of port_default_cmsis_os group
#endif // USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION
#endif // XF_MUTEX_DEFAULT_CMSIS_OS_H
