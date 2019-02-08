#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "course.h"

#include <string>


using namespace std;

class Executive
{

private:
	string fileName;
	int size=0;
	course** arr;

	int A=0;
public:  
	Executive(string fileName);
	~Executive();	
	void run();
};

#endif
