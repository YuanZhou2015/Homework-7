
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class station
{
public:
    enum Network_code{
        CE,
        CI,
        FA,
        NP,
        WR
    };
    enum Band_type{
        LONGPERIOD,
        SHORTPERIOD,
        BROADBAND
    };
    enum Instrument_type{
        HIGHGAIN,
        LOWGAIN,
        ACCELEROMETER
    };
    void printst(ofstream &outputfile, ofstream &logfile,
        string str,string termina, int &F);
    string uppercase (string &s);
    string itos(int i);
    bool is_valid_network_code(string s);
    Network_code string_to_NTcode(string s);
    string NTcode_to_string(Network_code nt);
    void set_networkcode(string networkcode, stringstream &slog, 
        stringstream &ss, int &i, int &flag);
    string get_networkcode();
    void set_stationname(string stationname,stringstream &slog,
        stringstream &ss, int &i, int &flag);
    string get_stationname(){return STN;}
    bool is_valid_typeofband (string s);
    Band_type string_to_bandtype (string s);
    string bandtype_to_string (Band_type b);
    void set_typeofband(string &typeofband,stringstream &slog,
         stringstream &ss, int &i, int flag);
    string get_bandtype(){return bandtype_to_string(B);}
    bool is_valid_typeofinstru (string s);
    Instrument_type string_to_instrutype (string s);
    string instrutype_to_string (Instrument_type instr);
    void set_typeofinstru(string &typeofinstru,stringstream &slog, 
        stringstream &ss, int&i, int &flag);
    string get_instrutype(){return instrutype_to_string(I);}
    void set_orientation(string orientation,stringstream &slog,
        stringstream &ss, int &i, int &flag);
    string get_orientation();
    string set_orientation(string o, int j);

private:
    Network_code NT;
    string STN;
    Band_type B;
    Instrument_type I;
    string O;  
};

