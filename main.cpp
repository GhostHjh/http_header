#include <iostream>
#include "http_header.h"

using std::cout;
using std::endl;


int main(int argc, char** argv)
{

    // std::string tmp("GET / HTTP/1.1");
    // cout << atof(tmp.substr(11, 13).c_str()) << endl;
    http_header tmp("asd\nef\"gas\ndw\"ad\n\rwaoheo\rwaheoiwah");
    tmp.update_lin_str();
    tmp.show();
    cout << endl << endl;

    tmp.update_lin_str();
    tmp.show();
    cout << endl << endl;

    tmp.update_lin_str();
    tmp.show();
    cout << endl << endl;
    
    tmp.update_lin_str();
    tmp.show();


    return 0;
}



