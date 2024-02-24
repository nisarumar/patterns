// Type your code here, or load an example.
// reference to array does not decay in to a pointer type rather keep the array type, int (&) [7] of keyVals as key vals is int [7]
#include <cstdio>
#include <iostream>

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&) [N])
{
    std::cout<<typeid(T).name()<<std::endl;
    return N;
}

int keyVals[] = {1,3,7,9,11,22,35};

int main()
{
    std::cout<<"Val: "<<arraySize(keyVals)<<std::endl;
    return 0;
}
