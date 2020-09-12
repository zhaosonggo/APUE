#include<iostream>
using namespace std;


class A
{
public:
	int aa;
	char *str;
};
A a;
int main()
{
	static int jj;
	cout<<jj<<endl;
	cout<<a.aa<<endl;
	cout<<(int *)a.str<<endl;
	return 0;
}



