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

    
    http_header tmp2("GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nsec-ch-ua: \"Chromium\";v=\"107\", \"Not=A?Brand\";v=\"24\"\r\nsec-ch-ua-mobile: ?0\r\nsec-ch-ua-platform: \"Windows\"\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.5304.107 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\r\nSec-Fetch-Site: none\r\nSec-Fetch-Mode: navigate\r\nSec-Fetch-User: ?1\r\nSec-Fetch-Dest: document\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: zh-CN,zh;q=0.9\r\nConnection: close");
    //tmp2.show();
    cout << tmp2["Request"] << endl
        << tmp2["Path"] << endl
        << tmp2["Http_version"] << endl
        << tmp2["Host"] << endl
        << tmp2["User-Agent"] << endl << endl;
    
    tmp2.add_server_version_status();
    tmp2.add_server_header("aaa") = "111";
    tmp2.add_server_header("bbb") = "222";
    cout << tmp2.init_server_header() << endl;
    
    return 0;
}



