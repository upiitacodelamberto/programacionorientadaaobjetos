#include <string>
#include <iostream>
 
void print(std::string::size_type n, std::string const &s)
{
    if (n == std::string::npos) {
        std::cout << "not found\n";
    } else {
        std::cout << "found: " << s.substr(n) << '\n';
    }
}
 
int main()
{
    std::string::size_type n;
    std::string const s = "This is a string";
 
    // search from beginning of string
    n = s.find("is");
    print(n, s);
                              /*found: is is a string*/
 
    // search from position 5
    n = s.find("is", 5);
    print(n, s);
                              /*found: is is a string
                                found: is a string*/
 
    // find a single character
    n = s.find('a');
    print(n, s);
                              /*found: is is a string
                                found: is a string
                                found: a string*/
 
    // find a single character
    n = s.find('q');
    print(n, s);
                              /*found: is is a string
                                found: is a string
                                found: a string
                                not found*/
    
    return 0;
}
