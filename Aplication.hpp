#ifndef _AH_
#define _AH_
#include "Travel.hpp"
#include "Human.hpp"
#include "Location.hpp"
#include <string>
class Application
{
private:
    std::vector<Driver *> drivers;
    std::vector<Passenger *> passengers;
    std::vector<Location *> locations;
    std::vector<Travel *> travels;
    int id_counter = 0;

public:
    Application(char* path);
    std::vector<Driver*> get_drivers();
    std::vector<Passenger*> get_passengers();
    std::vector<Location*> get_locations();
    std::vector<Travel*> get_travels();
    void add_id();
    void fill_locations(std::string line);
    void read_file(char *path);
    Passenger* find_passenger_by_name(std::string username);
    Driver* find_driver_by_name(std::string driver_name);
    Travel* find_travel_by_id(int id);
    Travel* find_travel_by_org_and_dest(Location* destination,Location* origin);
    Location* find_location_by_name(std::string name);
    bool check_new(std::string username);
    double cal_price_of_travel(Location* origin, Location* destination, bool is_hurry);
    bool check_standard_appeal(std::string passenger, std::string origin, std::string destination);
    void sign_up(std::string username, std::string role);
    void post_trip(std::string user_name, std::string org, std::string dest, std::string check_in_hurry);
    bool check_accept(Driver *driver, Travel *travel);
    void accept_travel(std::vector<std::string> splited);
    bool check_finishing(Driver *driver, Travel *travel);
    void finish_travel(std::vector<std::string> splited);
   // void handle_post_commands(std::vector<std::string> splited);
    bool check_get_trip(Human *driver);
    static bool sort_id(Travel* one, Travel* two);
    static bool sort_cost(Travel* one, Travel* two);
    std::vector<Travel*>  sort_travels_by_cost();
    std::vector<Travel*>  sort_travels_by_id();
    void get_all_trips(std::string username,std::string sort);
    bool check_one_trip(Driver *driver, Travel *travel);
    void get_one_trip(std::vector<std::string> splited);
    bool check_get_cost(Location *destination, Location *origin, Human *passenger, Human *driver);
    void get_cost_of_trip(std::vector<std::string> splited);
    void handle_get_commands(std::vector<std::string> splited);
    bool check_delete_trip(Passenger *passenger, Travel *travel);
    void delete_trip(int id, std::string username);
    void handle_delete_commands(std::vector<std::string> splited);
    std::vector<std::string> split_line_by_spaces(std::string line);
    void manage_commands();
};
#endif