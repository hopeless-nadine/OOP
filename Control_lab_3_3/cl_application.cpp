#include "cl_application.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"

// Построение дерева
void cl_application::build_tree_objects() 
{
	cin >> object_name;
	parent_object_map.emplace (object_name, this);
	string parent_name = this->object_name;
	string child_name ="";
	int state=0;
	int class_type=0;
	
	cout << "Object tree";
	
	while (parent_name != "endtree")
	{
		cin >> parent_name;
		string path = parent_name;
		if (parent_name == "endtree")
		{
			break;
		}
		parent_name = parent_name.substr(parent_name.rfind('/')+1);
		parent_object_map.emplace(parent_name, this);
		cin >> child_name >> class_type >> state;
		if (is_only(parent_name, child_name))
		{
			if (class_type == 2)
			{
				p_ob_2 = new cl_2 (child_name, state, parent_object_map);
				p_ob_2->set_parent(find_by_path(path));
			}
			if (class_type == 3)
			{
				p_ob_3 = new cl_3 (child_name, state, parent_object_map);
				p_ob_3->set_parent(find_by_path(path));
			}
			if (class_type == 4)
			{
				p_ob_4 = new cl_4 (child_name, state, parent_object_map);
				p_ob_4->set_parent(find_by_path(path));
			}
			if (class_type == 5)
			{
				p_ob_5 = new cl_5 (child_name, state, parent_object_map);
				p_ob_5->set_parent(find_by_path(path));
			}
			if (class_type == 6)
			{
				p_ob_6 = new cl_6 (child_name, state, parent_object_map);
				p_ob_6->set_parent(find_by_path(path));
			}
		}
	}
}

int cl_application::exec_app()
{
	show_object_state();
	find();
	return (0);
}
