#include<iostream>
#include<vector>
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
			for(unsigned int i=array.size();i<=a;i++)
			{
				array.push_back(0);
			}
		}
		return array[a];
	}
	poly operator+(poly a)
	{
		poly c;
		unsigned int i;
		for(i=0;i<array.size();i++)
		{
			c[i]=array[i]+a[i];
		}
		for(;i<a.array.size();i++)
		{
			c[i]=a[i];	
		}
		return c;
	}
	poly operator*(poly a)
	{
		poly c;
		for(unsigned int i=0;i<array.size();i++)
		{
			for(unsigned int j=0;j<a.array.size();j++)
			{
				c[i+j]+=array[i]*a[j];
			}
		}
		return c;
	}
	friend poly operator*(int a, poly p)
	{
		poly c;
		for(unsigned int i=0;i<p.array.size();i++)
		{
			c[i]=p.array[i]*a;
		}
		return c;
	}

	friend ostream & operator <<(ostream & out,poly a)
	{
		string odp;
		string help;
		if(a.array.size()<=0)
		{
			return out<<"0";
		}
		for(unsigned int i=a.array.size()-1;i>1;i--)
		{
			if(a[i]!=0)
			{
				sprintf((char*)help.c_str(),(give_me_formula(a[i])+"x^%d").c_str(),a[i],i);
				odp+=help.c_str();
			}	
		}
		if(a[1]!=0)
		{
			sprintf((char*)help.c_str(),(give_me_formula(a[1])+"x").c_str(),a[1]);
			odp+=help.c_str();
		}
		if(a[0]!=0)
		{
			sprintf((char*)help.c_str(),give_me_formula(a[0]).c_str(),a[0]);
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
	void operator=(double a)
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
	double operator() (double a)
	{
		double sum=0;
		for(int i=0;i<array.size();i++)
		{
			sum+=pow(a,i)*array[i];
		}
		return sum;	
	}	
};

