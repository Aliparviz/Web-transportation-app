#include "handlers.hpp"
#include "my_server.hpp"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  Application utaxi(argv[1]);

  try {
    MyServer server(5000);
    server.setNotFoundErrPage("static/404.html");
    server.get("/goodrequest", new ShowPage("static/goodrequest.html"));
    server.get("/badrequest", new ShowPage("static/badrequest.html"));
    server.get("/notfound", new ShowPage("static/notfound.html"));
    server.get("/permission", new ShowPage("static/permission.html"));

    server.get("/enter_show_travels", new ShowPage("static/enter_show_travels.html"));
    //server.post("/show_travels", new travels_table_handler(&utaxi));

    server.get("/signup", new ShowPage("static/signup.html"));
    server.post("/signup", new signup_handler(&utaxi));

    server.get("/delete", new ShowPage("static/delete.html"));
    server.post("/delete", new delete_handler(&utaxi));

    server.get("/reserve_travel", new ShowPage("static/reserve_travel.html"));
    server.post("/reserve_travel", new reserve_handler(&utaxi));

    server.get("/ok", new ShowPage("static/goodrequest.html"));
    server.get("/home.png", new ShowImage("static/home.png"));
    server.get("/", new ShowPage("static/home.html"));
    server.run();
  } catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
}
