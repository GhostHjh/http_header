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
    bool client_ok();
    void set_client_header(const string& argv_client_header_str);
    void init();
    const string& init_server_header();
    void show();
    void show_server_header();

private:
    void next_char(const string& str, int& str_index);
    void next_header(const string& str, int& str_index);
    void init_request_path_version();
    void init_header_map();


private:
    void add_next_header(string& str);

public:
    void add_server_version_status(string argv_version = "HTTP/1.1", string argv_status = "200");
    string& add_server_header(string argv_key);
    
private:
    string client_header_str;
    string server_header_str;
    int client_header_str_index;

    map<string, string> header_map;
    map<string, string> server_header_map;

    string tmp_key;
    string tmp_value;
};











