#include "http_header.h"

http_header::http_header() {}
http_header::http_header(const string& argv_client_header_str) : client_header_str(argv_client_header_str), client_header_str_index(0) {}
http_header::~http_header() {}

void http_header::set_client_header(const string& argv_client_header_str)
{   
    client_header_str = argv_client_header_str;
    client_header_str_index = 0;
    client_header_init();
}

void http_header::next_char(const string& str, int& str_index)
{
    for (;str[str_index] == '\n' || str[str_index] == '\r' || str[str_index] == ' ' || str[str_index] == '\t';)
        ++str_index;
}

void http_header::client_header_init()
{
    if (client_header_str.size() == 0)
        std::logic_error("未初始化");
}

void http_header::header_request_init()
{
    if (client_header_str[0] == 'G' && client_header_str[2] == 'T')
    {
        client_header.request = "GET";
        client_header_str_index + 3;
    }
    else
    {
        client_header.request = "POST";
        client_header_str_index + 4;
    }
}

void http_header::header_path_init()
{
    next_char(client_header_str, client_header_str_index);

    for (;client_header_str[client_header_str_index] != ' ';)
    {
        client_header.path += client_header_str[client_header_str_index];
        ++client_header_str_index;
    }    
}

void http_header::header_http_version_init()
{
    next_char(client_header_str, client_header_str_index);

    client_header.http_version = atof(client_header_str.substr(client_header_str_index + 5, client_header_str_index + 7).c_str());
    client_header_str_index += 8;
}

void http_header::header_host_init()
{
    next_char(client_header_str, client_header_str_index);
    if (client_header_str[client_header_str_index] == 'H' && (client_header_str[client_header_str_index +3] == 't' || client_header_str[client_header_str_index +3] == 'T'))
    {
    }
}



