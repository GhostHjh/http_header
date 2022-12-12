#include "http_header.h"

http_header::http_header() {}
http_header::http_header(const string& argv_client_header_str) : client_header_str(argv_client_header_str), client_header_str_index(0) { init(); }
http_header::~http_header() {}

const string& http_header::operator [](const string& argv_header_map_key)
{
    return header_map[argv_header_map_key];
}

bool http_header::count(const string& argv_header_map_key)
{
    return (header_map.count(argv_header_map_key) == 1);
}

bool http_header::client_ok()
{
    if (header_map.count("Request") == header_map.count("Path") == header_map.count("Http_version") == 1)
        return true;
    
    return false;
}

void http_header::set_client_header(const string& argv_client_header_str)
{   
    client_header_str = argv_client_header_str;
}

// void http_header::init_request_path_version()
// {
//     next_char(client_header_str, client_header_str_index);
//
//     if (client_header_str[client_header_str_index] == 'G' && client_header_str[client_header_str_index +2] == 'T')
//     {
//         header_map["Request"] = "GET";
//         client_header_str_index += 3;
//     }     
//     else if (client_header_str[client_header_str_index] == 'P' && client_header_str[client_header_str_index +3] == 'T')
//     {
//         header_map["Request"] = "POST";
//         client_header_str_index += 4;
//     }  
//     else
//         std::logic_error("非完整client_header");
//   
//     next_char(client_header_str, client_header_str_index);
//     for (int& a = client_header_str_index; a < client_header_str.size() && client_header_str[a] != ' ' && client_header_str[a] != '\n' && client_header_str[a] != '\t' && client_header_str[a] != '\r'; ++a)
//     {
//         header_map["Path"] += client_header_str[a];
//     }
//
//     next_char(client_header_str, client_header_str_index);
//     client_header_str_index += 5;
//     for (int& a = client_header_str_index; a < client_header_str.size() && client_header_str[a] != ' ' && client_header_str[a] != '\n' && client_header_str[a] != '\t' && client_header_str[a] != '\r'; ++a)
//     {
//         header_map["Http_version"] += client_header_str[a];
//     }
// }

void http_header::init_request_path_version()
{
    next_char(client_header_str, client_header_str_index);

    if (client_header_str[client_header_str_index] == 'G' && client_header_str[client_header_str_index +2] == 'T')
    {
        header_map["Request"] = "GET";
        client_header_str_index += 3;
    }     
    else if (client_header_str[client_header_str_index] == 'P' && client_header_str[client_header_str_index +3] == 'T')
    {
        header_map["Request"] = "POST";
        client_header_str_index += 4;
    }  
    else
        std::logic_error("非完整client_header");
    
    if (client_header_str[client_header_str_index] == ' ')
        ++client_header_str_index;
    else
        std::logic_error("非完整client_header");

    for (int& a = client_header_str_index; a < client_header_str.size() && client_header_str[a] != ' ' && client_header_str[a] != '\n' && client_header_str[a] != '\t' && client_header_str[a] != '\r'; ++a)
    {
        header_map["Path"] += client_header_str[a];
    }

    if (client_header_str[client_header_str_index] == ' ')
        ++client_header_str_index;
    else
        std::logic_error("非完整client_header");
    
    client_header_str_index += 5;
    for (int& a = client_header_str_index; a < client_header_str.size() && client_header_str[a] != ' ' && client_header_str[a] != '\n' && client_header_str[a] != '\t' && client_header_str[a] != '\r'; ++a)
    {
        header_map["Http_version"] += client_header_str[a];
    }

    next_header(client_header_str, client_header_str_index);
}

void http_header::init_header_map()
{
    while (client_header_str_index <= client_header_str.size() && client_header_str[client_header_str_index] != '\r' && client_header_str[client_header_str_index] != '\n')
    {
        for (; client_header_str_index <= client_header_str.size() && client_header_str[client_header_str_index] != ':'; ++client_header_str_index)
            tmp_key += client_header_str[client_header_str_index];
        
        ++client_header_str_index;
        ++client_header_str_index;

        for (; client_header_str_index <= client_header_str.size() && client_header_str[client_header_str_index] != '\r' && client_header_str[client_header_str_index] != '\n'; ++client_header_str_index)
            tmp_value += client_header_str[client_header_str_index];
        
        header_map[tmp_key] = tmp_value;

        string().swap(tmp_key);
        string().swap(tmp_value);

        next_header(client_header_str, client_header_str_index);
    }
}

void http_header::next_char(const string& str, int& str_index)
{
    for (;str[str_index] == '\n' || str[str_index] == '\r' || str[str_index] == ' ' || str[str_index] == '\t';)
        ++str_index;
}

void http_header::next_header(const string& str, int& str_index)
{
    if (str_index + 2 > str.size())
        std::logic_error("超过结尾");

    if (str[str_index] == '\r' && str[str_index +1] == '\n')
        str_index += 2;
}

// void http_header::init()
// {
//     int str_size = client_header_str.size();
//     init_request_path_version();
//
//     for (int& a = client_header_str_index; a < str_size; ++a)
//     {
//         next_char(client_header_str, client_header_str_index);
//         for (int& b = a; client_header_str[b] != ':' && b < str_size; ++b)
//         {
//             tmp_key += client_header_str[b];
//         }
//
//         ++client_header_str_index;
//         next_char(client_header_str, client_header_str_index);
//         for (int& b = a; client_header_str[b] != '\n' && client_header_str[b] != '\r' && b < str_size; ++b)
//         {
//             tmp_value += client_header_str[b];
//         }
//
//         header_map[tmp_key] = tmp_value;
//         string().swap(tmp_key);
//         string().swap(tmp_value);
//     }
// }

void http_header::init()
{
    init_request_path_version();

    init_header_map();
}

const string& http_header::init_server_header()
{
    for (auto a = server_header_map.begin(); a != server_header_map.end(); ++a)
    {
        server_header_str += a->first + ": " + a->second;
        add_next_header(server_header_str);
    }

    add_next_header(server_header_str);
    return server_header_str;
}

void http_header::show()
{
    for (auto a = header_map.begin(); a != header_map.end(); ++a)
        cout << a->first << "\t:\t" << a->second << endl;
}

void http_header::show_server_header()
{
    cout << server_header_str << endl;
}

void http_header::add_next_header(string& str)
{
    str += '\r';
    str += '\n';
}

void http_header::add_server_version_status(string argv_version, string argv_status)
{
    server_header_str += argv_version + ' ' + argv_status + " OK";
    add_next_header(server_header_str);
}

string& http_header::add_server_header(string argv_key)
{
    return server_header_map[argv_key];
}


