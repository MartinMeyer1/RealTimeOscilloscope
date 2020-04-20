#ifndef XF_THREAD_DEFAULT_CMSIS_OS_H
#define XF_THREAD_DEFAULT_CMSIS_OS_H

#include <config/xf-config.h>

#if (USE_XF_THREAD_DEFAULT_CMSIS_OS_IMPLEMENTATION != 0)

#include <stdint.h>
#include <cmsis_os.h>
#include "xf/interface/thread.h"

class XFThreadDefault : public interface::XFThread
{
	friend class XFResourceFactoryPort;

public:
	virtual void start();
	virtual void stop();

	virtual void setPriority(XFThreadPriority priority);
	virtual XFThreadPriority getPriority() const;

	virtual void delay(uint32_t milliseconds);

protected:
	XFThreadDefault(interface::XFThreadEntryPointProvider * pProvider,
		   	   	    interface::XFThread::EntryMethodBody entryMethod,
				    const char * threadName,
				    const uint32_t stackSize = 0);

	static void threadEntryPoint(const void * param);

protected:
	interface::XFThreadEntryPointProvider * _pEntryMethodProvider;
	interface::XFThread::EntryMethodBody _entryMethod;

	osThreadDef_t _threadDefinition;
	char _threadName[32];

	osThreadId _threadId;
};

#endif // USE_XF_THREAD_DEFAULT_CMSIS_OS_IMPLEMENTATION
#endif // XF_THREAD_DEFAULT_CMSIS_OS_H
