#include "Executive.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Executive::Executive(string fileName)
{
	Executive::fileName = fileName;
	cout << Executive::fileName << endl;

	string courseName;
	int courseNum;
	int A;
	int* arrid=nullptr ;
	ifstream infile;
	infile.open(fileName);

	infile>>size;
	arr= new course*[size];
	
	for(int i=0; i<size; i++)
	{
	infile>>courseName;
	infile>>courseNum;
	infile>>A;

	arrid= new int[A];

	for(int j=0; j<A; j++)
	{
	infile>>arrid[j];
	}
	
	arr[i]= new course();
	arr[i]->setCname(courseName);
	arr[i]->setCnum(courseNum);
	arr[i]->setAmount(A);
	arr[i]->setID(arrid,A);	
	delete[] arrid;
	}


}

Executive::~Executive()
{

	for(int i=0; i<size;i++)
	{
		delete arr[i];
	}


delete[] arr;

}


void Executive::run()
{
int choice=0;

while(choice!=7)
{
cout<<"Select an option: \n";
cout<<"1) Print all courses\n";
cout<<"2) Print all courses for a department\n";
cout<<"3) Print roster for a course \n";
cout<<"4) Print largest class \n";
cout<<"5) Swap two classes \n";
cout<<"6) Print schedule for student \n";
cout<<"7) Exit\n";

cout<<"Enter your choice:\n";
cin>>choice;
//1
if(choice==1)
{
for(int i=0;i<size; i++)
{
cout<<arr[i]->getCname()<<" "<<arr[i]->getCnum()<<'\n';
}
}
//1




//2
else if(choice==2)
{
cout<<"Please, enter a department code to check all courses of this department.\n";
string allDep;
cin>>allDep;

for(int i=0;i<size;i++)
{
if(allDep==arr[i]->getCname())
{

cout<<arr[i]->getCname()<<" "<<arr[i]->getCnum()<<"\n";

}
}

}
//2

//3
else if(choice==3)
{

cout<<"Please,enter a course and course number with a space to check students in this course\n";
string name;
int num=0;
int a3=0;
cin>>name;
cin>>num;

for(int i=0;i<size;i++)
{
if(name==arr[i]->getCname()&&num==arr[i]->getCnum())
{

a3=arr[i]->getAmount();

for(int j=0; j<a3;j++)
{
cout<<arr[i]->getID(j);
if(j<a3-1)
{
cout<<",";
}
else if (j==a3-1)
{
cout<<"\n";
}
}
}
}
}
//3




//4
else if(choice==4)
{
	int value=0;
	int largest=0;
	cout<<"The largest course \n";

	for(int i=0;i<size;i++)
	{
		value=arr[i]->getAmount();

		if(largest<value)
		{
			largest=arr[i]->getAmount();
		}
	}
	for(int i=0;i<size;i++)
	{
		if(arr[i]->getAmount()==largest)
		{
			cout<<arr[i]->getCname()<<" "<<arr[i]->getCnum()<<" - "<<arr[i]->getAmount()<<" students\n";
		}
	}	
}
//4







//5
else if(choice==5)
{
	string course1;
	string course2;
	int c1;
	int c2;
	cout<<"which course you want to swap?\n";
	cin>>course1;
	cin>>c1;
	cout<<"enter second course\n";
	cin>>course2;
	cin>>c2;

	int p1;
	int p2;
	course* temp;
	for(int i=0;i<size;i++)
	{
		if(arr[i]->getCname()==course1&&arr[i]->getCnum()==c1)
		{
			p1=i;	
		}
		if(arr[i]->getCname()==course2&&arr[i]->getCnum()==c2)
		{
			p2=i;	
		}
	}
	temp=arr[p1];
	arr[p1]=arr[p2];
	arr[p2]=temp;
}
//5





//6
else if(choice==6)
{
cout<<"Please, enter a student's id to check course enrolled\n";
int stid=0;
cin>>stid;
cout<<"you enrolled :\n";
for(int i=0;i<size;i++ )
{
 for(int j=0; j<arr[i]->getAmount();j ++)
{
if (stid==arr[i]->getID(j))
{
cout<<arr[i]->getCname()<<" "<<arr[i]->getCnum()<<'\n';
}

}

}
}
//6
else if(choice<1||choice>7)
{
cout<<"Invalid input.\n";
}


}
}





