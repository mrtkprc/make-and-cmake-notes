#include <iostream>
#include "foo/foo.h"

using namespace std;

int main()
{
    foo f;
    f.sayHello();
    
    cout << "Hello" << endl;
    return 0;
}