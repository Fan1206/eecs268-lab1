#include<iostream>
#include "Executive.h"
#include "course.h"


int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Executive exec(argv[1]); 
     exec.run(); 
  }

  return(0);
}
