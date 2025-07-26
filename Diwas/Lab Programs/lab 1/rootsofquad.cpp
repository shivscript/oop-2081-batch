#include<iostream>
#include<math.h>
using namespace std;
main()
{
	float d,x1,x2,a,b,c;
	cout<<"The given equation is ax^2+bx+c : "<<endl;
	cout<<"a : ";
	cin>>a;
    cout<<"b : ";
    cin>>b;
    cout<<"c : ";
    cin>>c;
	if(a==0)
	{
		printf("Error: The given equation is not quadratic. \n");
	}
	else
	{
		d=(b*b)-4*a*c;
		if(d==0)
		{
			cout<<"There exists one common root. "<<endl;
			x1=-b/(2*a);
			cout<<"The root is: "<<x1;
		}
		else if(d>0)
		{
			cout<<"There exists two distinct roots. "<<endl;
			x1=(-b+sqrt(d))/(2*a);
			x2=(-b-sqrt(d))/(2*a);
			cout<<"The roots are: "<<x1<<" and "<<x2;
		}
		else 
		{
			cout<<"There exists two complex roots. "<<endl;
			x1=(-b)/(2*a);
			x2=sqrt(-d)/(2*a);
		    cout<<"The roots are: "<<x1<<"+i"<<x2<<" and "<<x1<<"-i"<<x2;
		}
	}
}