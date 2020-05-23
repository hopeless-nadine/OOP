#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H
#include "cl_base.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"

class cl_application : public cl_base
{
	public:
		cl_application(cl_base* p_parent){};
		void build_tree_objects();
		int exec_app();
	private:
		cl_2* p_ob_2;
		cl_3* p_ob_3;
		cl_4* p_ob_4;
		cl_5* p_ob_5;
		cl_6* p_ob_6;
		
};
#endif //CL_APPLICATION_H
