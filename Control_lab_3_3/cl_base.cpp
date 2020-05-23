#include "cl_base.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"

// Конструктор
cl_base::cl_base (cl_base* p_parent, string _object_name, int _state)
{
	this->object_name = _object_name;
	if (p_parent)
	{
		this ->p_parent = p_parent;
		p_parent ->add_child (this);
	}
	else
	{
		this->p_parent = 0;
	}
	set_state (_state);
}

bool cl_base::is_only (string parent_name, string child_name)
{
	vector <cl_base*> temp = parent_object_map[parent_name]->children;
	for (int i=0; i < parent_object_map[parent_name]->children.size(); i++)
	{
		if (temp[i]->object_name == child_name)
		{
			return false;
		}
	}
	return true;
}

void cl_base::find()
{
	string path="";
	string search_object="";
	while (path != "//")
	{
		cin >> path;
		if (path == "//")
		{
			break;
		}
		else if (path[0]=='/' and path[1]=='/')
		{
			string name = path.substr(2);
			if (parent_object_map.count (name) > 0)
			{
				cout << endl << path << " Object name: " << name;
			}
			else
			{
				cout << endl << path << " Object not found";
			}
		}
		else
		{
			if (find_by_path (path) != nullptr)
			{
				cout << endl << path << " Object name: " << path.substr(path.rfind('/')+1);
			}
			else
			{
				cout << endl << path << " Object not found";
			}
		}
	}
}

// Установление имени
void cl_base::set_object_name (string object_name)
{
	this->object_name = object_name;
}

//Получение имени
string cl_base::get_object_name()
{
	return object_name;
}

//Установление родителя
void cl_base::set_parent (cl_base* p_parent)
{
	if (p_parent)
	{
		this->p_parent = p_parent;
		p_parent->children.push_back(this);
	}
}

// Добавление потомка
void cl_base::add_child (cl_base* p_child)
{
	this->children.push_back (p_child);
}

//Установление состояния готовности
void cl_base::set_state (int state)
{
	this->state = state;
}

void cl_base::show_object_state()
{
	show_state_next((cl_base*)this);
}

//Вывод дерева
int level=0;
void cl_base::show_state_next (cl_base* parent)
{
	cout << endl;
	for (int i=0; i < level; i++)
	{
		cout << " ";
	}
	cout << parent->get_object_name();
	if (parent->children.size() == 0) return;
	
	parent->it_child = parent->children.begin();
	
	while (parent->it_child != parent->children.end())
	{
		level = level + 4;
		show_state_next ((*(parent->it_child)));
		parent->it_child++;
		level = level - 4;
	}
}

string get_next_name (string& path)
{
	if (path.length() == 0)
	{
		return "";
	}
	if (path[0] != '/')
	{
		return "";
	}
	string next_name="";
	for (int i=1; i < path.length() and path[i] != '/'; i++)
	{
		next_name = next_name + path[i];
	}
	path.erase (path.begin(), path.begin()+next_name.length()+1);
	return next_name;
}

cl_base* cl_base::find_by_path (string path)
{
	if (get_next_name(path) != this->object_name)
	{
		return nullptr;
	}
	if (path.length()==0)
	{
		return this;
	}
	for (int i=0; i < children.size(); i++)
	{
		cl_base* temp = children[i]->find_by_path(path);
		if (temp != nullptr)
		{
			return temp;
		}
	}
	return nullptr;
}
