#include <http_header.h>
#include <string>

http_header::http_header(std::string argv_client_header_str)
    : client_header_str(std::move(argv_client_header_str))
{
    std::cout << "开始初始化\n";
    client_header_map_init();
}

http_header::~http_header() {}

void http_header::show()
{
    std::cout << client_header_map["request_type"] << ' ' << client_header_map["request_path"] << ' ' << client_header_map["request_http_version"] << "\r\n";

    for (auto i : client_header_map)
    {
        if (i.first != "request_type" && i.first != "request_path" && i.first != "request_http_version")
            std::cout << i.first << " : " << i.second << std::endl;
    }
}

bool http_header::client_is_ok()
{
    return client_header_map.count("request_type") && client_header_map.count("request_path") && client_header_map.count("request_http_version");
}

const std::string& http_header::operator[](std::string argv_key)
{
    return client_header_map[argv_key];
}

void http_header::client_header_map_init()
{
    int client_header_str_index = 0;

    //获取客户端header的请求类型
    if (client_header_str[0] == 'G' && client_header_str[1] == 'E' && client_header_str[2] == 'T')
        client_header_str_index  = 4, client_header_map["request_type"] = "GET";
    else if (client_header_str[0] == 'P' && client_header_str[1] == 'O' && client_header_str[2] == 'S' && client_header_str[3] == 'T')
        client_header_str_index = 5, client_header_map["request_type"] = "POST";

    //获取客户端请求的路径
    for (; client_header_str[client_header_str_index] != ' '; ++client_header_str_index)
        client_header_map["request_path"] += client_header_str[client_header_str_index];
    ++client_header_str_index;

    //获取客户端发送请求的HTTP版本
    for (; client_header_str[client_header_str_index] != '\r' && client_header_str[client_header_str_index] != '\n'; ++client_header_str_index)
        client_header_map["request_http_version"] += client_header_str[client_header_str_index];
    client_header_str_index +=2;

    //获取其他
    std::string header_key;
    std::string header_value;
    for (int &i = client_header_str_index; i < client_header_str.size(); )
    {
        for (; client_header_str[i] != ':'; ++i)
            header_key += client_header_str[i];
        
        i += 2;

        for (; client_header_str[i] != '\r' && client_header_str[i] != '\n'; ++i)
            header_value += client_header_str[i];

        i += 2;

        client_header_map[header_key] = header_value;
        header_key.clear();
        header_value.clear();
    }

    if (client_header_map["request_type"] == "POST")
    {

    }
}






