
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCtrl.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Motor(struct FB_Motor* inst)
{
	/*TODO: Add your code here*/
	REAL a = inst->u / inst->ke - inst->out_w;
	REAL b = a / inst->Tm;
	
	inst->integrator.in = b;
	FB_Integrator(&inst->integrator);
	
	inst->out_w = inst->integrator.out;
}
