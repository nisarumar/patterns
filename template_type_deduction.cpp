#include<iostream>

template<typename T>
void f(T* param);        // param is now a pointer

template<typename T>
void K(T& param);       // param is a reference

int main()
{
    int x = 27;             // x is an int
    const int *px = &x;      // px is a ptr to x as a const int, deduced type is 

    f(&x);                   // T is int, param's type is int*

    f(px);                   // T is const int,
                         // param's type is const int*
    
    
    const int cx = x;       // cx is a const int
    const int& rx = x;      // rx is a reference to x as a const int

    
    K(x);                   // T is int, param's type is int&

    K(cx);                  // T is const int,
                        // param's type is const int&

    K(rx);                  // T is const int,
                        // param's type is const int&
    return 0;
}

template<typename T>
void f(T* param)
{
    std::cout<<"Val_T: "<<*param<<std::endl;
}


template<typename T>
void K(T& param)
{
    std::cout<<"Val_K: "<<param<<std::endl;
}
