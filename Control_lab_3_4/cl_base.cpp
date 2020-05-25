#include "cl_base.h"
#include "cl_2.h"
#include "cl_3.h"


cl_base::cl_base(cl_base* p_parent, string _object_name, int _is_ready) {
	this->object_name = _object_name;
	if (p_parent) {
		this->p_parent = p_parent;
		p_parent->add_child(this);
	}
	else {
		this->p_parent = 0;
	}
	set_state(_is_ready);
}



void cl_base::set_object_name(string object_name) {
	this->object_name = object_name;
}

string cl_base::get_object_name() {
	return object_name;
}

void cl_base::set_parent(cl_base* p_parent) {
	if (p_parent) {
		this->p_parent = p_parent;
		p_parent->children.push_back(this);
	}
}

void cl_base::add_child(cl_base* p_child) {
	this->children.push_back(p_child);
}

void cl_base::set_state(int is_ready) {
	this->is_ready = is_ready;
}

void cl_base::show_object_state() {
	show_state_next((cl_base*)this);
}


int lvl = 0;
void cl_base::show_state_next(cl_base* parent) {

	for (int i = 0; i < lvl; i++) {
		cout << " ";
	}
	cout << parent->get_object_name();

	if (parent->children.size() == 0) return;

	parent->it_child = parent->children.begin();

	while (parent->it_child != parent->children.end()) {
		cout << "\n";
		lvl += 4;
		show_state_next((*(parent->it_child)));
		parent->it_child++;
		lvl -= 4;
	}
}



void cl_base::set_connect(TYPE_SIGNAL p_signal,
	cl_base* p_object,
	TYPE_HANDLER p_ob_handler)
{
	o_sh* p_value;
	for (int i = 0; i < connections.size(); i++)
	{
		if (connections[i]->p_signal == p_signal and
			connections[i]->p_cl_base == p_object and
			connections[i]->p_handler == p_ob_handler)
		{
			return;
		}
	}
	p_value = new o_sh();
	p_value->p_signal == p_signal;
	p_value->p_cl_base == p_object;
	p_value->p_handler == p_ob_handler;
	connections.push_back(p_value);
}

void cl_base::delete_connect(TYPE_SIGNAL p_signal,
	cl_base* p_object,
	TYPE_HANDLER p_ob_handler)
{
	for (int i = 0; i < connections.size(); i++)
	{
		if (connections[i]->p_signal == p_signal and
			connections[i]->p_cl_base == p_object and
			connections[i]->p_handler == p_ob_handler)
		{
			connections.erase(connections.begin() + i);
			return;
		}
}

void emit_signal(TYPE_SIGNAL p_signal, string & s_command)
{

}
