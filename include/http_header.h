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
    void set_client_header(const string& argv_client_header_str);
    void update_lin_str();
    void add_header_map();
    void show();

private:
    void next_char(const string& str, int& str_index);
    


private:
    string client_header_str;
    string server_header_str;
    int client_header_str_index;

    map<string, string> header_map;

    string lin_str;
};











