#include<iostream>
#include <memory>
#include <inttypes.h>

struct data_st;
class Quick
{
public:
    std::unique_ptr<data_st> p_data_st;
    Quick(struct data_st&& );
    ~Quick();
};

struct data_st {
        std::string name;
        uint32_t value;
    };

Quick::Quick(struct data_st&& init):p_data_st{std::make_unique<data_st>(std::move(init))}{}
Quick::~Quick() = default;

int main()
{
    std::string pr = "prog_name";
    Quick obj({pr,12});
    std::cout<<obj.p_data_st->name<<","<<obj.p_data_st->value<<std::endl;
    
    return 0;
}
