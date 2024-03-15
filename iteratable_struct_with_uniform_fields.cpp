#include <sys/user.h>
#include <iostream>
#include <array>

using namespace std;

#define GET_FIELD(STRUCT, FIELD)    ((STRUCT *)0)->FIELD

using type = decltype(GET_FIELD(user_regs_struct,rax));

constexpr auto reg_num = sizeof(user_regs_struct)/sizeof(type);

struct arch_regs{
    union{
        user_regs_struct ptrace_regs;
        array<type, reg_num>reg_array;
    };
};

template<typename T>
class TD;

int main()
{
    arch_regs a;
    cout<<hex<<&a.ptrace_regs.r15<<endl;
    cout<<hex<<&a.ptrace_regs.r14<<endl;
    //...
    cout<<"Iteratable Entries"<<endl;
    for (auto& a : a.reg_array)
    {
        cout<<hex<<&a<<endl;
    }

    //TD<type> b; //error; compiler error messages exposes deduced type;

    return 0;
}
