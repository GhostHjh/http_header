#include <iostream>
#include <string>
#include <utility>
#include "http_header.h"

using std::cout;
using std::endl;


int main(int argc, char** argv)
{
    http_header tmp("POST /index.html HTTP/1.1\r\nHost: 127.0.0.1\r\nsec-ch-ua: \"Chromium\";v=\"107\", \"Not=A?Brand\";v=\"24\"\r\nsec-ch-ua-mobile: ?0\r\nsec-ch-ua-platform: \"Windows\"\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.5304.107 Safari/537.36\r\nAccept: application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\r\nSec-Fetch-Site: none\r\nSec-Fetch-Mode: navigate\r\nSec-Fetch-User: ?1\r\nSec-Fetch-Dest: document\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: zh-CN,zh;q=0.9\r\nConnection: close\r\n\r\n1=cs1&2=cs2");
    //tmp.show();
    //cout << tmp.get_accept_type() << endl;
    //tmp.add_server_header({"cs1", "1", "cs2", "2"});
    //tmp.add_server_header("cs3") = "3";
    //cout << tmp.get_server_header() << endl;

    tmp.add_server_header_request_status();
    tmp.add_server_header_request_type_length("text/html", 4096); 
    tmp.add_server_header({"cs1", "1", "cs2", "2"});
    tmp.add_serverheader_request_end();
    cout << tmp.get_server_header() << endl;



    return 0;
}



