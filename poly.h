#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
using namespace std;
string give_me_formula(const float a)
{	
	string odp;
	if(a>0)
	{
		odp+="+";
	}
	if((int)(a*100)%100==0)
	{
		odp+="%.0f";
	}
	else
	{
		odp+="%.2f";	
	}	
	return odp;
}
class poly
{
	private:
	vector <float>array;
	public:
	poly(double a=0)
	{
		if(array.size()==0)
		{
			array.push_back(a);
		}
		else
		{
			array[0]=a;
		}
	}
	float& operator[](unsigned int a)
	{
		if(a>=array.size())
		{
			array.resize(a+1,0);
		}
		return array[a];
	}
	//a.array.at[j]
	/*float operator[](unsigned int a) const
	{
		if(a>=array.size())
		{
			throw bbbb;
		}
		return array[a];
	}*/
	poly operator+(const poly &a)
	{
		poly c;
		unsigned int i;
		for(i=0;i<array.size();i++)
		{
			c[i]=array[i]+a.array[i];
		}
		for(;i<a.array.size();i++)
		{
			c[i]=a.array[i];	
		}
		return c;
	}
	friend poly operator*(const poly &a,const poly &p)
	{
		poly c;
		for(unsigned int i=0;i<p.array.size();i++)
		{
			for(unsigned int j=0;j<a.array.size();j++)
			{
				c[i+j]+=p.array[i]*a.array[j];
			}
		}
		return c;
	}
	friend ostream & operator <<(ostream & out,const poly &a)
	{
		string odp;
		string help;
		if(a.array.size()<=0)
		{
			return out<<"0";
		}
		for(unsigned int i=a.array.size()-1;i>1;i--)
		{
			if(a.array[i]!=0)
			{
				sprintf((char*)help.c_str(),(give_me_formula(a.array[i])+"x^%d").c_str(),a.array[i],i);
				odp+=help.c_str();
			}	
		}
		if(a.array.size()>1&&a.array[1]!=0)
		{
			sprintf((char*)help.c_str(),(give_me_formula(a.array[1])+"x").c_str(),a.array[1]);
			odp+=help.c_str();
		}
		if(a.array[0]!=0)
		{
			sprintf((char*)help.c_str(),give_me_formula(a.array[0]).c_str(),a.array[0]);
			odp+=help.c_str();
		}
		if(odp[0]=='+')
		{
			for(int i=0;odp[i]!='\0';i++)
			{
				odp[i]=odp[i+1];
			}
		}
		for(int i=0;odp[i]!='\0';i++)
		{
			if(odp[i]=='1'&&odp[i+1]=='x')
			{
				for(int j=i;odp[j]!='\0';j++)
				{
					odp[j]=odp[j+1];
				}
			}
		}
		return out<<odp;
	}
	double operator() (double a)
	{
		double sum=0;
		for(unsigned int i=0;i<array.size();i++)
		{
			sum+=pow(a,i)*array[i];
		}
		return sum;	
	}	
};

