#include <cmath>
#include <iostream>
#include "solution.cpp"


#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;  else std::cout << __FUNCTION__ << " Success "<< std::endl ; }

void test_function1()
{  
  //after checking for various test cases, it was found that 750x750 is the smallest grid in which the robot can cover largest area.
    IS_TRUE(solve(0, 0, 750) == 592597);
    IS_TRUE(solve(0, 0, 1000) == 592597 );
    //IS_TRUE(solve(0, 0, 100) == 592597);
}


int main() {

  test_function1();
  //std::cout << answer << std::endl;
}


