#include <iostream>
#include <string>
#include "course.h"
using namespace std;


void course::setCname(string Cname)
{
CourseName=Cname;
}



string course::getCname()
{
return(CourseName);
}



void course::setCnum(int Cnum)
{
CourseNum=Cnum;
}



int course::getCnum()
{
return(CourseNum);
}



void course::setAmount(int a)
{
amount=a;
}



int course::getAmount()
{
return(amount);
}



void course::setID(int* arrid, int index)
{
m_arrid = new int[index];
for (int i=0; i<index;i++)
{
m_arrid[i]=arrid[i];
}

}


int course::getID(int index)
{

return m_arrid[index];
}




course::~course()
{
delete[] m_arrid;
}
