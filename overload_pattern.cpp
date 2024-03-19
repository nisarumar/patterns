#include<variant>
#include<string>

template<typename ... Ls> 
struct over_load: Ls ... {
    using Ls::operator()...; //inherits operator (); in this case which are lambdas; lambdas are classes where capture are private data memebers; below it uses CTAD therefore no need to provide the class (lambda) template type
};


std::variant<int, std::string, double> var;

#include <iostream>

int main(){

    over_load overload {
        [](int &val){std::cout<<"I am an int\n";},
        [](std::string &val){std::cout<<"I am a string\n";},
        [](double &val){std::cout<<"I am a double\n";}
    };
    
    var = "We will will rock you\n";
    overload(std::get<1>(var));

    var = 10;
    overload(std::get<0>(var));

    var = 10.0;
    overload(std::get<double>(var));

    std::visit(overload, var);

  return 0;
}
