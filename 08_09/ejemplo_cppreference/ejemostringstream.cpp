#include <iostream>
#include <sstream>
int main()
{
    std::ostringstream s;
std::cout<<"std::ostringstream s;"<<std::endl;
    std::cout<<"s.tellp()=" << s.tellp() << '\n';
    s << 'h';
std::cout<<"s << 'h';"<<std::endl;
    std::cout<<"s.tellp()=" << s.tellp() << '\n';
    s << "ello, world ";
std::cout<<"s << \"ello, world \";"<<std::endl;
    std::cout<<"s.tellp()=" << s.tellp() << '\n';
    s << 3.14 << '\n';
std::cout<<"s << 3.14 << '\\n';"<<std::endl;
    std::cout<<"s.tellp()=" << s.tellp() << '\n' <<"s.str()="<< s.str();
}
