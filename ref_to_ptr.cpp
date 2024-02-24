// Type your code here, or load an example.
#include <cstdio>
#include <iostream>
#include <vector>

template<typename T>
void func (const T& val)
{
    //val = 0x9000093; ptr value can not be modified
    //*val = 3; //value can not be modified
    std::cout<<"Val: "<<*val;
}

int main()
{
    const std::vector<int> num {1,3,4,5,6};
    func(&num[0]);
    return 0;
}
