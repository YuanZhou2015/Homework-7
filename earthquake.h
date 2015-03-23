#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class earthquake
{
public:
    enum Magnitude_type{ 
        ML, 
        MS, 
        MB, 
        MW 
    };
    void printout(ofstream &outputfile, ofstream &logfile,
    string str,string termina, int &F);
    string uppercase (string &s);
    bool is_valid_magtype(string mt);
    Magnitude_type string_to_magnitude_type (string s);
    void set_ID(string id);
    string get_ID(){return ID;}
    //Months int_to_months(int m);
    void set_date(string date, stringstream &slog);
    string get_date();
    void set_time(string time, stringstream &slog);
    string get_time(){return time;}
    void set_timezone(string timezone, stringstream &slog);
    string get_timezone(){return timezone;}
    void set_earthquakename(string eqn){
        earthquakename = eqn;
        return;
    }
    string get_eqname(){return earthquakename;}
    void set_epicenter(stringstream ecenter);
    string get_epicenter(){return epicenter;}
    void set_magtype(string magnitude, stringstream &slog);

    Magnitude_type get_magtype(){return magnitudetype;}
    void set_magnitude(float mag,stringstream &slog);
    float get_magnitude(){return magnitude;}

private:
    struct Date_format{
    string date;
    string month;
    string year;
    }; 
    /*enum magnitude_type{ 
        ML, 
        MS, 
        MB, 
        MW 
    };*/

    string ID;
    Date_format Date;
    string time;
    string timezone;
    string earthquakename;
    string epicenter;
    Magnitude_type magnitudetype;
    float magnitude; 
};
