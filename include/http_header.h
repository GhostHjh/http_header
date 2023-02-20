#include <iostream>
#include <string>
#include <vector>
#include <map>

class http_header
{
public:
    http_header() = delete;
    http_header(std::string argv_client_header_str);
    ~http_header();

    void show();
    bool client_is_ok();

    const std::string& operator[](std::string argv_key);
    
private:
    void client_header_map_init();


public:
    std::string client_header_str;
    std::map<std::string, std::string> client_header_map;

    std::string server_header_str;
    std::map<std::string, std::string> server_header_map;
};







