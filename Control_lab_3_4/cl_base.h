#ifndef CL_BASE_H
#define CL_BASE_H
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class cl_base;

typedef void (cl_base::* TYPE_SIGNAL) (string&);
typedef void (cl_base::* TYPE_HANDLER) (string);

#define SIGNAL_D (signal_f)(TYPE_SIGNAL)(&signal_f);
#define HANDLER_D (handler_f)(TYPE_HANDLER)(&handler_f);

// Структура задания одной связи
struct o_sh
{
	TYPE_SIGNAL p_signal; // указатель на метод сигнала
	cl_base* p_cl_base; // указатель на второй объект
	TYPE_HANDLER p_handler; // указатель на метода обработчика
};

class cl_base
{
public:
	cl_base(cl_base* p_parent = 0, string s_object_name = "", int _is_ready = 1);

	void set_object_name(string _object_name);
	string get_object_name();

	void set_parent(cl_base* p_parent);
	void add_child(cl_base* p_child);

	void set_state(int is_ready);

	void show_object_state();

	void set_connect(TYPE_SIGNAL p_signal,
		cl_base* p_cl_base,
		TYPE_HANDLER p_handler);

	void delete_connect(TYPE_SIGNAL p_signal,
		cl_base* p_cl_base,
		TYPE_HANDLER p_handler);

	void emit_signal(TYPE_SIGNAL p_signal, string& s_command);

protected:
	vector<cl_base*> children;
	vector<cl_base*> ::iterator it_child;
	vector <o_sh*> connections;
	map<string, cl_base*> parent_object_map;
	string object_name;
	cl_base* p_parent;
	int is_ready;

	void show_state_next(cl_base* ob_parent);
};

#endif //CL_BASE_H
