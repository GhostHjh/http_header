#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char** argv)
{

    std::string tmp("GET / HTTP/1.1");
    cout << atof(tmp.substr(11, 13).c_str()) << endl;


    return 0;
}



