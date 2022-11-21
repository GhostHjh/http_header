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
public:
    http_header();
    http_header(const string& argv_client_header_str);
    ~http_header();

public:
    const string& operator [](const string& argv_header_map_key);
    bool count(const string& argv_header_map_key);
    void set_client_header(const string& argv_client_header_str);
    void init();
    void show();

private:
    void next_char(const string& str, int& str_index);
    void init_request_path_version();
    


private:
    string client_header_str;
    string server_header_str;
    int client_header_str_index;

    map<string, string> header_map;

    string tmp_key;
    string tmp_value;
};











