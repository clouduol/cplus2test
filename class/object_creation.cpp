#include<iostream>
using namespace std;

class Student{
public:
	Student():name("xiaoming"){}
	Student(int age, string name):age(age),name(name){}
	~Student(){}
	int age=30;
	string name;
};

int main() {
	Student stu1;
	cout<<stu1.age<<"\t"<<stu1.name<<endl;
	//Student stu6();
	//cout<<stu6.age<<"\t"<<stu6.name<<endl;
	Student stu2(3,"wangpeng");
	cout<<stu2.age<<"\t"<<stu2.name<<endl;
	Student* stu3=new Student;
	cout<<stu3->age<<"\t"<<stu3->name<<endl;
	delete stu3;
	Student* stu5=new Student();
	cout<<stu5->age<<"\t"<<stu5->name<<endl;
	delete stu5;
	Student* stu4=new Student(5,"zhanggang");
	cout<<stu4->age<<"\t"<<stu4->name<<endl;
	delete stu4;

	Student stu7[5];
	//Student stu8[5]();
	//Student stu9[5](3,"xiangfang");
	Student* stu11=new Student[5];
	Student* stu12=new Student[5]();
	//Student* stu13=new Student[5](4,"zhengshan");
	delete []stu11;
	delete []stu12;
}
