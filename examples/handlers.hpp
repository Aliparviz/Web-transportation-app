#ifndef _MY_HANDLERS_
#define _MY_HANDLERS_

#include "../server/server.hpp"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>
#include "../Aplication.hpp"

class signup_handler : public RequestHandler {
public:
    signup_handler(Application* utaxi);
    Response* callback(Request*);
private:
    Application* app;
};

class reserve_handler : public RequestHandler {
public:
    reserve_handler(Application* utaxi);
    Response* callback(Request*);
private:
    Application* app;
};

class delete_handler : public RequestHandler {
public:
    delete_handler(Application* utaxi);
    Response* callback(Request*);
private:
    Application* app;
};

class travels_table_handler : public RequestHandler {
public:
    travels_table_handler(Application* utaxi);
    Response* callback(Request*);
private:
    Application* app;
};







/*class RandomNumberHandler : public RequestHandler {
public:
  Response *callback(Request *);
};

class LoginHandler : public RequestHandler {
public:
  Response *callback(Request *);
};

class UploadHandler : public RequestHandler {
public:
  Response *callback(Request *);
};

class ColorHandler : public TemplateHandler {
public:
  ColorHandler(std::string filePath);
  std::map<std::string, std::string> handle(Request *req);
};*/

#endif
