#include <iostream>
#include "http_header.h"

using std::cout;
using std::endl;


int main(int argc, char** argv)
{

    // std::string tmp("GET / HTTP/1.1");
    // cout << atof(tmp.substr(11, 13).c_str()) << endl;
    // http_header tmp("asd\nef\"gas\ndw\"ad\n\rwaoheo\rwaheoiwah");
    // tmp.update_lin_str();
    // tmp.show();
    // cout << endl << endl;

    // tmp.update_lin_str();
    // tmp.show();
    // cout << endl << endl;

    // tmp.update_lin_str();
    // tmp.show();
    // cout << endl << endl;
    
    // tmp.update_lin_str();
    // tmp.show();


    // http_header tmp("GET / HTTP/1.1\nHost: 127.0.0.1\nHost2:999.999.999.999");
    // cout << tmp["request"] << endl
    //     << tmp["path"] << endl
    //     << tmp["http_version"] << endl
    //     << tmp["Host"] << endl
    //     << tmp["Host2"] << endl;

    
    http_header tmp2("GET / HTTP/1.1\nHost: 127.0.0.1\nsec-ch-ua: \"Chromium\";v=\"107\", \"Not=A?Brand\";v=\"24\"\nsec-ch-ua-mobile: ?0\nsec-ch-ua-platform: \"Windows\"\nUpgrade-Insecure-Requests: 1\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.5304.107 Safari/537.36\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\nSec-Fetch-Site: none\nSec-Fetch-Mode: navigate\nSec-Fetch-User: ?1\nSec-Fetch-Dest: document\nAccept-Encoding: gzip, deflate\nAccept-Language: zh-CN,zh;q=0.9\nConnection: close");
    tmp2.show();


    return 0;
}



