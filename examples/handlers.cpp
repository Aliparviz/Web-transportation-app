#include "handlers.hpp"
#include<string>
using namespace std;

signup_handler::signup_handler(Application* utaxi)
{
  app = utaxi;
}

Response *signup_handler::callback(Request *req)
{
  try
  {
    app->sign_up(req->getBodyParam("username"), req->getBodyParam("roll"));
    Response *res = Response::redirect("/ok");
    return res;
  }
  catch (std::runtime_error &ex)
  {
    if(string(ex.what())==NOT_FOUND)
    {
      Response *res = Response::redirect("/notfound");
      return res;
    }
    else if(string(ex.what())==BAD_REQUEST)
    {
      Response *res = Response::redirect("/badrequest");
      return res;
    }
  }
}
reserve_handler::reserve_handler(Application* utaxi)
{
  app = utaxi;
}
Response *reserve_handler::callback(Request *req)
{
  try
  {
    app->post_trip(req->getBodyParam("username"), req->getBodyParam("origin"), req->getBodyParam("destination"), req->getBodyParam("hurry"));
    Response *res = new Response;
    Location* dest = app->find_location_by_name(req->getBodyParam("destination"));
    Location* org = app->find_location_by_name(req->getBodyParam("origin"));
    Travel* travel = app->find_travel_by_org_and_dest(dest, org);
    res->setHeader("Content-Type", "text/html");
    string body;
    body += "<!DOCTYPE html>";
    body += "<html>";
    body += "<body style=\"text-align: center;\">";
    body += "<h1>Travel reserved correctly</h1>";
    body += "<p>";
    body += "The id of your travel is: ";
    body += to_string(travel->get_id());
    body += "<button ";
    body += "onclick='history.back()'>Go Back";
    body += "</button>";
    body += "</p>";
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
  }
  catch(runtime_error &ex)
  {
    if(string(ex.what())==NOT_FOUND)
    {
      Response *res = Response::redirect("/notfound");
      return res;
    }
    else if(string(ex.what())==BAD_REQUEST)
    {
      Response *res = Response::redirect("/badrequest");
      return res;
    }
  }
  
}

delete_handler::delete_handler(Application* utaxi)
{
  app = utaxi;
}
Response *delete_handler::callback(Request *req)
{
  try
  {
    cout<<endl<<stoi(req->getBodyParam("id"))<<endl;
    app->delete_trip(stoi(req->getBodyParam("id")), req->getBodyParam("username")); 
    Response *res = Response::redirect("/ok");
    return res;
  }
  catch(runtime_error &ex)
  {
    if(string(ex.what()) == NOT_FOUND)
    {
      Response *res = Response::redirect("/notfound");
      return res;
    }
    else if(string(ex.what()) == BAD_REQUEST)
    {
      Response *res = Response::redirect("/badrequest");
      return res;
    }
    else if(string(ex.what()) == PERMISSION_DENIED)
    {
      Response *res = Response::redirect("/permission");
      return res;
    }
  }
}

travels_table_handler::travels_table_handler(Application* utaxi)
{
  app = utaxi;
}
Response* travels_table_handler::callback(Request* req)
{
  try
  {
    vector<Travel*>trips;
    app->get_all_trips(req->getBodyParam("username"),req->getBodyParam("sort"));
    if(req->getBodyParam("sort") == "yes")
    {
      trips = app->sort_travels_by_cost();
    }
    else
    {
      trips = app->sort_travels_by_id();
    }
  }



  
  catch(runtime_error &ex)
  {
    ////
  }
}









/*Response *RandomNumberHandler::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  string body;
  body += "<!DOCTYPE html>";
  body += "<html>";
  body += "<body style=\"text-align: center;\">";
  body += "<h1>AP HTTP</h1>";
  body += "<p>";
  body += "a random number in [1, 10] is: ";
  body += to_string(rand() % 10 + 1);
  body += "</p>";
  body += "<p>";
  body += "SeddionId: ";
  body += req->getSessionId();
  body += "</p>";
  body += "</body>";
  body += "</html>";
  res->setBody(body);
  return res;
}

Response *LoginHandler::callback(Request *req) {
  string username = req->getBodyParam("username");
  string password = req->getBodyParam("password");
  if (username == "root")
    throw Server::Exception("Remote root access has been disabled.");
  cout << "username: " << username << ",\tpassword: " << password << endl;
  Response *res = Response::redirect("/rand");
  res->setSessionId("SID");
  return res;
}

Response *UploadHandler::callback(Request *req) {
  string name = req->getBodyParam("file_name");
  string file = req->getBodyParam("file");
  cout << name << " (" << file.size() << "B):\n" << file << endl;
  Response *res = Response::redirect("/");
  return res;
}

ColorHandler::ColorHandler(string filePath) : TemplateHandler(filePath) {}

map<string, string> ColorHandler::handle(Request *req) {
  map<string, string> context;
  string newName = "I am " + req->getQueryParam("name");
  context["name"] = newName;
  context["color"] = req->getQueryParam("color");
  return context;
}*/
