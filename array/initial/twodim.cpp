#include<iostream>
#include<typeinfo>

using namespace std;

void print(int a[][4], int r, int c) {
	cout<<typeid(a).name()<<endl;
	cout<<typeid(a[0]).name()<<endl;
	cout<<typeid(a[0][0]).name()<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(a[0])<<endl;
	cout<<sizeof(a[0][0])<<endl;
	for(int i=0; i<r; i++){
		for(int j=0;j<c;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}

int main() {
	int a[3][4]={{1,9,8,10,},{3},{5},};
	print(a,3,4);
	cout<<typeid(a).name()<<endl;
	cout<<typeid(a[0]).name()<<endl;
	cout<<typeid(a[0][0]).name()<<endl;
	cout<<&a<<endl;
	cout<<&a[0]<<endl;
	cout<<&a[0][0]<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(a[0])<<endl;
	cout<<sizeof(a[0][0])<<endl;

	int b[3][4]={1,3,4,5,6,6,};
	print(b,3,4);

	int c[][4]={1,2,3,4,5,6,};
	print(c,2,4);

	//int d[][5]={1,2,3,4,5,6,67,8,9,10};
	//print(d,3,5);
	//int d[][4]={{1,3,5,4,5},{10,3}};
	int d[][4]={{1,3,4,5},{10,3}};
	print(d,2,4);

	int (*e)[4] =d;
	print(e,2,4);
	print(e+1,1,4);

	int r=3;
	int (*f)[4]=new int[r][4];
	f[0][3]=29;
	f[1][2]=30;
	print(f,r,4);
	delete []f;

	int col=4;
	int** g=new int* [r];
	for(int i=0;i<r;i++)
		g[i]=new int[col];
	g[3][2]=23;
	g[1][3]=54;
	//int (*h)[4] = g[0];
	//print(h,3,4);
	for(int i=0;i<r;i++)
		delete []g[i];
	delete []g;
}
