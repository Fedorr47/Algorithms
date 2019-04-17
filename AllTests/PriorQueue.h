#pragma once
#include <vector>
#include <iostream>
#include <string>

class FullStack
{
private:
	size_t _stack_size;
	int64_t	   _current_pos{ 0 };
	std::vector<int64_t> _stack;

	void choose_child_up(int64_t child, bool& left, bool& right)
	{
		if (child % 2)
		{
			left = true;
			right = false;
		}
		else
		{
			right = true;
			left = false;
		}
	}

	void shift_up()
	{
		if (_current_pos == 1)
		{
			return;
		}

		bool left_elem = false;
		bool right_elem = false;

		int64_t child_elem = _current_pos-1;	
		int64_t parent_elem = child_elem;

		choose_child_up(child_elem, left_elem, right_elem);

		while (parent_elem != 0)
		{
			if (right_elem)
			{
				parent_elem = child_elem / 2 - 1;
			}
			else if (left_elem)
			{
				parent_elem = child_elem / 2;
			}
			if (_stack[parent_elem] < _stack[child_elem])
			{
				std::swap(_stack[parent_elem], _stack[child_elem]);
				child_elem = parent_elem;
				choose_child_up(child_elem, left_elem, right_elem);
			}
			else
			{
				break;
			}
		}
	}

	void shift_down()
	{
		if (_current_pos == 1)
		{
			return;
		}

		int64_t parent_elem = 0;

		int64_t left_elem = 0;
		int64_t right_elem = 0;	

		while (parent_elem < _current_pos)
		{
			left_elem = parent_elem * 2 + 1;
			right_elem = parent_elem * 2 + 2;

			if (_stack[left_elem] < _stack[right_elem] )
			{
				if (_stack[parent_elem] < _stack[right_elem])
				{
					std::swap(_stack[parent_elem], _stack[right_elem]);
					parent_elem = right_elem;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (_stack[parent_elem] < _stack[left_elem])
				{
					std::swap(_stack[parent_elem], _stack[left_elem]);
					parent_elem = left_elem;
				}
				else
				{
					break;
				}
			}		
		}
	}

public:
	void insert(int64_t value)
	{
		_stack[_current_pos] = value;
		++_current_pos;
		shift_up();
	}
	int64_t extract_max()
	{
		if (_current_pos == 0)
			return 0;
		int64_t max_value = _stack[0];
		std::swap(_stack[0], _stack[_current_pos - 1]);
		_stack[_current_pos - 1] = 0;
		--_current_pos;
		shift_down();
		return max_value;
	}
	
	FullStack(size_t size_stack = 1000000)
		: _stack_size(size_stack)
	{
		_stack.resize(_stack_size);
	}

	void print64_t_tree()
	{
		for (int64_t i = 0; i < _current_pos; ++i)
			std::cout << _stack[i] << std::endl;
	}
};

//
//	int64_t count_operation = 0;
//	std::string operation_name = "";
//	FullStack full_stack;
//	std::vector<int64_t> max_numbers;
//
//	std::cin >> count_operation;
//	if (count_operation == 0)
//		return 0;
//	std::cerr << "Count " << count_operation << std::endl;
//	for (int64_t i = 0; i < count_operation; ++i)
//	{
//		std::cin >> operation_name;
//		if (operation_name.compare("ExtractMax") == 0)
//		{
//			std::cout << full_stack.extract_max() << std::endl;
//		}
//		else if (operation_name.compare("Insert") == 0)
//		{
//			int64_t number;
//			std::cin >> number;
//			full_stack.insert(number);
//			std::cerr << number << std::endl;
//		}
//	}
