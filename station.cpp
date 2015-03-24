#include "stdafx.h"
#include "station.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

void station::printst(ofstream &outputfile, ofstream &logfile,
           string str,string termina, int &F){
    if (F == 1){
        outputfile.open("yuan.out");
        outputfile << str;
        outputfile.close();
    }
    if (F == 2){
        logfile.open("yuan.log");
        cout << termina;
        logfile << str;
        logfile.close();
    }        
}
string station::uppercase (string &s){
    string result = s;
    for (int i = 0; i<(int)result.size(); i++)
        result[i] = toupper(result[i]);
    return result;
}
string station::itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

bool station::is_valid_network_code(string s){
    return ((s == "CE")||(s == "CI")||(s == "FA")||(s == "NP")||(s == "WR"));
}
/*Network_code station::string_to_NTcode(string s){
    if (s == "CE") return CE;
    if (s == "CI") return CI;
    if (s == "FA") return FA;
    if (s == "NP") return NP;
    if (s == "WR") return WR;
    exit(EXIT_FAILURE);
} */
string station::NTcode_to_string(Network_code nt){
    switch(nt){
        case CE: return "CE";
        case CI: return "CI";
        case FA: return "FA";
        case NP: return "NP";
        case WR: return "WR";
    }
    exit(EXIT_FAILURE);
}

void station::set_networkcode(string networkcode, stringstream &slog, 
     stringstream &ss, int &i, int &flag){
    string sout;
    ofstream outputfile, logfile;
    int F;
    flag = 0;
    if (networkcode.size() != 2){
        sout = "Entry # ";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = itos(i);
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = " ignored. Invalid network. \n";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        flag = 1;
        return;
    }
    if (!is_valid_network_code(networkcode)){
        sout = "Entry # ";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = itos(i);
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = " ignored. Invalid network. \n";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        flag = 1;
        return;
    }
    if (networkcode == "CE") NT = CE;
    if (networkcode == "CI") NT = CI;
    if (networkcode == "FA") NT = FA;
    if (networkcode == "NP") NT = NP;
    if (networkcode == "WR") NT = WR;
    return;
}
string station::get_networkcode(){
    return NTcode_to_string(NT);
}
void station::set_stationname(string stationname,stringstream &slog,
                     stringstream &ss, int &i, int &flag){
    string sout;
    ofstream outputfile, logfile;
    int F;
    flag = 0;
    if (stationname.size() != 3 && stationname.size() != 5){
        sout = "Entry # ";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = itos(i);
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = " ignored. Invalid station code. \n";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        flag=1;
        return;
    }  
    if (stationname.size() == 3){
        if (!isupper(stationname[0])||!isupper(stationname[1])||!isupper(stationname[2])){
            sout = "Entry # ";
            slog << sout;
            F = 2;
            printst(outputfile,logfile,slog.str(),sout,F);
            sout =itos (i);
            slog << sout;
            F = 2;
            printst(outputfile,logfile,slog.str(),sout,F);
            sout = " ignored. Invalid station code. \n";
            slog << sout;
            F = 2;
            printst(outputfile,logfile,slog.str(),sout,F);
            flag = 1;
            return;
        }
    }

    if (stationname.size() == 5){
        if (!isdigit(stationname[0])||!isdigit(stationname[1])||!isdigit(stationname[2])
            ||!isdigit(stationname[3])||!isdigit(stationname[4])){
            sout = "Entry # ";
            slog << sout;
            F = 2;
            printst(outputfile,logfile,slog.str(),sout,F);
            sout = itos (i);
            slog << sout;
            F = 2;
            printst(outputfile,logfile,slog.str(),sout,F);
            sout = " ignored. Invalid station code. \n";
            slog << sout;
            F = 2;
            printst(outputfile,logfile,slog.str(),sout,F);
            flag = 1;
            return;
        }
    }
    STN = stationname;
    return;
}
bool station::is_valid_typeofband (string s){
    string ss = uppercase(s);
    return((ss == "LONG-PERIOD")||(ss == "SHORT-PERIOD")||(ss == "BROADBAND"));
}
/*Band_type station::string_to_bandtype (string s){
    string ss = uppercase(s);
    if (ss == "LONG-PERIOD") return LONGPERIOD;
    if (ss == "SHORT-PERIOD") return SHORTPERIOD;
    if (ss == "BROADBAND") return BROADBAND;
    exit(EXIT_FAILURE);
}*/   
string station::bandtype_to_string (Band_type b){
    switch(b){
        case LONGPERIOD: return "L";
        case SHORTPERIOD: return "B";
        case BROADBAND: return "H";
    }
    exit(EXIT_FAILURE);
}
void station::set_typeofband(string &typeofband,stringstream &slog,
                    stringstream &ss, int &i, int flag){
    string sout;
    ofstream outputfile, logfile;
    int F;
    flag = 0;
    if (!is_valid_typeofband(typeofband)){
        sout = "Entry # ";
        slog << sout;
        F = 2;
        printst(outputfile, logfile,slog.str(),sout,F);
        sout = itos (i);
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = " ignored. Invalid band type. \n";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        flag = 1;
    }
    else{
        string ss = uppercase(typeofband);
        if (ss == "LONG-PERIOD") B = LONGPERIOD;
        if (ss == "SHORT-PERIOD")  B = SHORTPERIOD;
        if (ss == "BROADBAND")  B = BROADBAND;
    }
    return;
}
bool station::is_valid_typeofinstru (string s) {
    string ss = uppercase(s);
    return((ss == "HIGH-GAIN")||(ss == "LOW-GAIN")||(ss == "ACCELEROMETER"));
}
/*Instrument_type station::string_to_instrutype (string s){
    string ss = uppercase(s);
    if (ss == "HIGH-GAIN") return HIGHGAIN;
    if (ss == "LOW-GAIN") return LOWGAIN;
    if (ss == "ACCELEROMETER") return ACCELEROMETER;
    exit(EXIT_FAILURE);
} */  
string station::instrutype_to_string (Instrument_type instr){
    switch(instr){
        case HIGHGAIN: return "H";
        case LOWGAIN: return "L";
        case ACCELEROMETER: return "N";
    }
    exit(EXIT_FAILURE);
}
void station::set_typeofinstru(string &typeofinstru,stringstream &slog, 
                      stringstream &ss, int&i, int &flag){
    string sout;
    ofstream outputfile, logfile;
    int F;
    flag = 0;
    if (!is_valid_typeofinstru(typeofinstru)){
        sout = "Entry # ";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = itos (i);
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = " ignored. Invalid type of instrument. \n";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        flag = 1; 
    }
    else{
        string ss = uppercase(typeofinstru);
        if (ss == "HIGH-GAIN") I = HIGHGAIN;
        if (ss == "LOW-GAIN") I = LOWGAIN;
        if (ss == "ACCELEROMETER") I = ACCELEROMETER;
    }
    return;
}
void station::set_orientation(string orientation,stringstream &slog,
                     stringstream &ss, int &i, int &flag){
    string sout;
    ofstream outputfile, logfile;
    int F,n,j;
    flag = 0;
    if (orientation.size()>3||orientation.size()<1){
        sout = "Entry # ";
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = itos(i);
        slog << sout;
        F = 2;
        printst(outputfile,logfile,slog.str(),sout,F);
        sout = " ignored. Invalid orientation. \n";
        slog << sout;
        F = 2;
        printst(outputfile, logfile, slog.str(), sout, F);
        flag = 1;
    }
    else{
        j=0;
        n = orientation.size();
        orientation = uppercase(orientation);
        while(j<n){
            if(isdigit(orientation[j]))
                j++;
            else{
                j=0;
                while(j<n){
                    if(isalpha(orientation[j]))
                        j++;
                    else{
                        sout = "Entry # ";
                        slog << sout;
                        F = 2;
                        printst(outputfile,logfile,slog.str(),sout,F);
                        sout = itos(i);
                        slog << sout;
                        F = 2;
                        printst(outputfile,logfile,slog.str(),sout,F);
                        sout = " ignored. Invalid orientation. \n";
                        slog << sout;
                        F = 2;
                        printst(outputfile,logfile,slog.str(),sout,F);
                        flag = 1;
                        j++;
                    }
                }
                if(flag == 1) break;
            }
        }
        j = 0;
        while(j<n){
            if ((orientation[j]!= '1' && orientation[j]!='2' && orientation[j]!= '3')
                &&(orientation[j]!='N' && orientation[j]!='E' && orientation[j]!= 'Z')){
                 sout = "Entry # ";
                        slog << sout;
                        F = 2;
                        printst(outputfile,logfile,slog.str(),sout,F);
                        sout = itos(i);
                        slog << sout;
                        F = 2;
                        printst(outputfile,logfile,slog.str(),sout,F);
                        sout = " ignored. Invalid orientation. \n";
                        slog << sout;
                        F = 2;
                        printst(outputfile,logfile,slog.str(),sout,F);
                        flag = 1;
                        j++;
            }
            else
                j++;
            if (flag == 1)break;
        }
    }
    O = orientation;
}
string station::get_orientation(){
    return O;
}
string station::set_orientation(string o, int j){
    O = o[j];
    return O;
}
