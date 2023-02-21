# HTTP_Header

用于解析客户端的请求报文, 和手动生成服务器回应报文


## 安装和使用

> 将 **头文件(http_header.h)** 和 **cpp文件(http_header.cpp)** 文件添加到工程
>
> 位于根目录的 **main.cpp** 和 **CMakeLista.txt** 为示范,



## 解析请求报文

> 在初始化对象时传入接受到的 **请求报文** (std::string, const char*, char*)
>
> ```cpp
> //初始化 & 解析
> http_header tmp(http_header_str);
>
> //查看报文是否有请求方式, 请求路径, 发送的HTTP版本
> bool header_is_ok = tmp.client_header_is_ok();
>
> //获取请求协议
> std::string request_type = tmp.get_request_type();
>
> //获取请求路径
> std::string request_type = tmp.get_request_path();
>
> //获取HTTP版本
> std::string request_type = tmp.get_request_http_version();
>
> //获取请求类型有一个单独的函数
> std::string request_file_type_str = tmp.get_accept_type();
>
> //获取其他的报文
> //http_header对[]做了重载, key为字段名称, 返回值为一个 std::string 类型
> std::string request_str = tmp["Accept"];
>
> //获取POST报文
> std::map< std::string, std::string > POST_map = tmp.get_post();
> ```
>



## 生成回应报文

>
> ```cpp
> //实例化一个对象
> http_header tmp;
>
> //设置回应报文中的HTTP版本, 状态码, 状态码原因 
> //默认值为HTTP/1.1, 200, OK
> tmp.add_server_header_status(1.1, 200, "OK");
>
> //设置回应报文中对方请求的文件类型和大小
> tmp.add_server_header_type_length("text/html", 4096);
>
> //(可选))添加其他报文字段
> //key和alue必须成对出现
> tmp.add_server_header( {"key1", "value1", "key2", "value2"}} );
>
> //添加结束符号
> tmp.add_server_header_end()
>
> //获取设置的回应报文(返回值为std::string)
> std::string server_header_str = tmp.get_server_header();
> ```
