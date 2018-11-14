#include<iostream>
#include<cstdlib>
#include "stack.h"
using namespace std;
stack::stack(int a=10)
{
	if(a<1)
	{
		size=10;
	}
	else
	{
		size=a;
	}
	array=(int*)malloc(sizeof(int)*size);
	if(array==NULL)
	{
		cout<<"Field to allocate memory\n";
	}
	T=0;
}
stack::~stack()
{
	if(array!=NULL)
	{
		free(array);
	}
}

void stack::clear()
{
	T=0;
}

int stack::push(int a)
{
	if(array!=NULL)
	{
		if(size<=T)	
		{
			int *array2=(int *)malloc(sizeof(int)*size*2);
			if(array2==NULL)
			{
				cout<<"Field to allocate memory\n";
				return -1;
			}
			else
			{
				for(int i=0;i<size;i++)
				{
					array2[i]=array[i];
				}
				free(array);
				array=array2;
				array2=NULL;
				size*=2;
				array[T++]=a;
				return 0;
			}
		}
		else
		{
			array[T++]=a;
			return 0;
		}
	}	
	return -1;
}


int stack::pop()
{
	if(array!=NULL&&size>0)
	{
		if(T<=0)
		{
			cout<<"Stack is empty\n";
			return -1;
		}
		else
		{
			return array[--T];
		}
	}
	return -1;
}


