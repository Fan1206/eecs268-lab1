#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>

using namespace std;


class course
{
private:
string CourseName;
int CourseNum=0;
int amount=0;
int* m_arrid;


public:
void setCname(string Cname);
string getCname();

void setCnum(int Cnum);
int getCnum();

void setAmount(int a);
int getAmount();

void setID(int* arrid,int index);
int getID(int index);
~course();

};
#endif
