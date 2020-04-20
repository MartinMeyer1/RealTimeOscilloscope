#include "config/trace-config.h"
#include "trace/trace.h"

#if (USE_TRACE_EXAMPLE != 0)

int main()
{
	Trace::out("Hello World");
	
	Trace::out("My name is %s and a am %d years old.", "Sarah Walker", 28);

	return 0;
}

#endif // USE_TRACE_EXAMPLE
