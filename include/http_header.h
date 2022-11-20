#pragma once
#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

class http_header
{
private:
    class header_map
    {
    public:
        string request;
        string path;
        double http_version;
        string host;
        string user_agent;
    };

public:
    http_header();
    http_header(const string& argv_client_header_str);
    ~http_header();

public:
    void set_client_header(const string& argv_client_header_str);

private:
    void next_char(const string& str, int& str_index);
    void client_header_init();
    void header_request_init();
    void header_path_init();
    void header_http_version_init();
    void header_host_init();

private:
    string client_header_str;
    string server_header_str;

    header_map client_header;

    int client_header_str_index;
};











