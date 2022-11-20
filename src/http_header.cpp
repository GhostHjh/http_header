#include "http_header.h"

http_header::http_header() {}
http_header::http_header(const string& argv_client_header_str) : client_header_str(argv_client_header_str), client_header_str_index(0) {}
http_header::~http_header() {}

void http_header::set_client_header(const string& argv_client_header_str)
{   
    client_header_str = argv_client_header_str;
}

void http_header::show()
{
    cout << lin_str << endl;
}

void http_header::next_char(const string& str, int& str_index)
{
    for (;str[str_index] == '\n' || str[str_index] == '\r' || str[str_index] == ' ' || str[str_index] == '\t';)
        ++str_index;
}

void http_header::update_lin_str()
{
    next_char(client_header_str, client_header_str_index);
    string().swap(lin_str);
    int jsq = 0;
    for (int& i = client_header_str_index; i < client_header_str.size(); ++i)
    {
        if (client_header_str[i] == '\"')
        {
            if (jsq == 0)
                jsq = 1;
            else
                jsq = 0;
        }
        
        if ((client_header_str[i] == '\n' || client_header_str[i] == '\r') && jsq == 0)
            return;
        
        lin_str += client_header_str[i];   
    }
}

void http_header::add_header_map()
{
    for (int& i = client_header_str_index; i < client_header_str.size();)
    {
        update_lin_str();
        
    }
}



