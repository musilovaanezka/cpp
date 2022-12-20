
#include <iostream>
#include "Header.h"

int main()
{
    RuleOfThree o1("Ahoj");

    // nutnost něčeho jako metody toString()
    // -> přetížení operátoru ()
    std::cout << o1 << std::endl;

    // nutnost definice kopírovacího konstruktoru 
    RuleOfThree o2(o1);
    std::cout << o1 << std::endl;

   /* RuleOfThree o3;
    o3 = o1;*/

    return 0;
}
