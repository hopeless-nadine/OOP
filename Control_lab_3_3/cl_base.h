#ifndef CL_BASE_H
#define CL_BASE_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>

using namespace std;

class cl_base 
{
	public:
		cl_base (cl_base* p_parent = 0, string _object_name ="", int _state = 1);// конструктор
	
		void set_object_name(string _object_name); // установка имени объекта
		string get_object_name(); // получение имени объекта
	
		void set_parent (cl_base* p_parent); // установка родителя
		void add_child (cl_base* p_parent); // добавление потомка
	
		void set_state (int state); // установка состояния
	
		void show_object_state(); // вывод дерева
		cl_base* find_by_path(string path); // поиск по пути
		bool is_only (string parent_name, string child_name); // проверка на уникальность
		void find(); // метод всего поиска
		
		map <string, cl_base*> parent_object_map = {}; // словарь
		
	protected:
		vector <cl_base*> children; // ссылки на детей
		vector <cl_base*> ::iterator it_child;
		string object_name; // имя объекта
		cl_base* p_parent; // ссылка на родителя
		int state; // готовность
		
		void show_state_next (cl_base* ob_parent);
};

#endif //CL_BASE_H
	
