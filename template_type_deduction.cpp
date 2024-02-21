#include<iostream>

template<typename T>
void f(T* param);        // param is now a pointer

template<typename T>
void K(T& param);       // param is a reference

template<typename T>
void L(T&& param);       // param is now a universal reference

template<typename T>
void M(T param);         // param is still passed by value

int main()
{

    // Case 1: ParamType is a Reference or Pointer, but not a Universal Reference   
    
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

    //Case 2: ParamType is a Universal Reference
    L(x);                    // x is lvalue, so T is int&,
                         // param's type is also int&

    L(cx);                   // cx is lvalue, so T is const int&,
                             // param's type is also const int&

    L(rx);                   // rx is lvalue, so T is const int&,
                             // param's type is also const int&

    L(27);                   // 27 is rvalue, so T is int,
                             // param's type is therefore int&&

    //case pass by value (attributes of declared variable are not deduced, for instance const int is int or volatile is dropped)
    const char* const ptr =  // ptr is const pointer to const object
  "Fun with pointers";
    M(ptr);                  // pass arg of type const char * const

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

template<typename T>
void L(T&& param)
{
    std::cout<<"Val_L: "<<param<<std::endl;
}

template<typename T>
void M(T param)
{
    std::cout<<"Val_M: "<<param<<std::endl;
}
