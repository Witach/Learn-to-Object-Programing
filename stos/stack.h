#include<iostream>
class stack
{
	public:
	int push(int a);
	int pop();
	void clear();
	stack(int a);
	~stack();
	private:
	int T;
	int *array;
	int size;
};

