#include <iostream>
#include "stack.cpp"
using namespace std;
int main()
{	
	stack s1;
	int a;
	for(a=0;a<30;a++)
	{
		if(s1.push(a)==-1)
		{
			return 1;
		}
	}
	int b;
	//s1.clear();
	for(a=0;a<40;a++)
	{
		if((b=s1.pop())==-1)
		{
			return 2;
		}
		cout<<b<<"\n";
	}
	return 0;
}
