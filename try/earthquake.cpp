
#include "earthquake.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

void earthquake::printeq(ofstream &outputfile, ofstream &logfile,
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
void earthquake::set_ID(string id){
    earthquake::ID = id;
    return;
}
enum Months{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    Auguest,
    September,
    October,
    November,
    December
};
Months int_to_months(int m){
    if (m == 1) return January;
    if (m == 2) return February;
    if (m == 3) return March;
    if (m == 4) return April;
    if (m == 5) return May;
    if (m == 6) return June;
    if (m == 7) return July;
    if (m == 8) return Auguest;
    if (m == 9) return September;
    if (m == 10) return October;
    if (m == 11) return November;
    if (m == 12) return December;
    exit (EXIT_FAILURE);
}  
string months_to_string(Months m){
    switch(m){
        case January: return "January";
        case February: return "February";
        case March: return "March";
        case April: return "April";
        case May: return "May";
        case June: return "June";
        case July: return "July";
        case Auguest: return "Auguest";
        case September: return "September";
        case October: return "October";
        case November: return "November";
        case December: return "December";
    }
    exit(EXIT_FAILURE);
}
void earthquake::set_date(string date, stringstream &slog){
    string sout;
    ofstream outputfile, logfile;
    Date_format Date;
    if (date.size()!=10){
        sout = "Invalid date.(Hint: Size should be 10 as 'MM/DD/YYYY or MM-DD-YYYY')\n";
        slog << sout;
        int F = 2;
        printeq(outputfile, logfile, slog.str(), sout, F);
        exit (0);
    }
    if (!isdigit(date[0])||!isdigit(date[1])||!isdigit(date[3])||!isdigit(date[4])
        ||!isdigit(date[6])||!isdigit(date[7])||!isdigit(date[8])||!isdigit(date[9])){
        sout = "Invalid date. (Hint: The date should be numbers.)\n";
        slog << sout;
        int F = 2;
        printeq(outputfile, logfile, slog.str(), sout, F);
        exit(0);
    }   
    if((date[2] != '-' || date[5] != '-')&&(date[2] != '/' || date[5] != '/')){
        sout = "Invalid fomat of date.(Hint: MM/DD/YYYY or MM-DD-YYYY)\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout, F);
        exit(0);
    }
    string d1,d2,d3,d4,d5,d6,d7,d8;
    d1 = date[0];
    d2 = date[1];
    d3 = date[3];
    d4 = date[4];
    d5 = date[6];
    d6 = date[7];
    d7 = date[8];
    d8 = date[9];
    string month = d1+d2, day = d3+d4, year = d5+d6+d7+d8;
    int m = atoi(month.c_str()), d = atoi(day.c_str()), y = atoi(year.c_str());

    // Check on correcness of the date.

    if (y<0){
        sout = "Invalid year.\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);
    }
    if (m<1 || m>12){
        sout = "Invalid month.(Hint: Month should between 1 to 12.)\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);
    }
    else{
        month = months_to_string(int_to_months(m)); 
    }
    if ((m == 1||m == 3||m == 5||m == 7||m == 8||m == 10||m == 12)&&(d>31 || d<0)){
        sout = "Invalid date of the month.\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);    
    }
    if ((m == 4||m == 6||m == 9||m == 11)&&(d>30 || d<0)){
        sout = "Invalid date of the month.\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);    
    }

    // Checking about the leapyear.

    if (m == 2){
        if (((y%4) == 0 && (y%100))||(y%400 == 0)){
            if (d>29||d<0){
                sout = "Invalid date of the month(for Feburary in leadyear).\n";
                slog << sout;
                int F = 2;
                printeq(outputfile,logfile,slog.str(),sout,F);
                exit(0);
            }
        }
        else{
            if (d>28||d<0){
                sout = "Invalid date of the month(for Feburary not in leadyear).\n";
                slog << sout;
                int F = 2;
                printeq(outputfile,logfile,slog.str(),sout,F);
                exit(0);
            }
        }
    }
    earthquake::Date.date = day;
    earthquake::Date.month = month;
    earthquake::Date.year = year;
    return;
}
string earthquake::get_date(){ 
    stringstream dd;
    dd << "# " << Date.date <<' '<< Date.month << ' ' << Date.year <<' ';
    string d = dd.str();
    return d;
}
void earthquake::set_time(string time, stringstream &slog){
    string sout;
    ofstream outputfile, logfile;
    if (time.size()!=12){
        sout = "Invalid format of time.(Hint: Size should be 12 as 'hh:mm:ss.fff')\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit (0);
    }
    if (!isdigit(time[0])||!isdigit(time[1])
        ||!isdigit(time[3])||!isdigit(time[4])
        ||!isdigit(time[6])||!isdigit(time[7])
        ||!isdigit(time[9])||!isdigit(time[10])||!isdigit(time[11])){
        sout = "Invalid time. (Hint: The time should be numbers.)\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);
    }   
    if(time[2] != ':' || time[5] != ':'||time[8] != '.' ){
        sout = "Invalid fomat of time.(Hint: hh:mm:ss.fff)\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);
    }

    // Check the corrctness of time.

    string t1,t2,t3,t4,t5,t6,t7,t8,t9;
    t1 = time[0];
    t2 = time[1];
    t3 = time[3];
    t4 = time[4];
    t5 = time[6];
    t6 = time[7];
    t7 = time[9];
    t8 = time[10];
    t9 = time[11];
    string hour = t1+t2, minute = t3+t4, second = t5+t6, ms = t7+t8+t9;
    int h = atoi(hour.c_str()), m = atoi(minute.c_str());
    int s = atoi(second.c_str()), f = atoi(ms.c_str());
    if(h<0||h>23){
        sout = "Invalid hour.\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);      
    }
    if(m<0||m>59){
        sout = "Invalid minute.\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);      
    }
    if(s<0||s>59){
        sout = "Invalid second.\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);      
    }
    if(f<0||f>999){
        sout = "Invalid millisecond.\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit(0);      
    }
    return;
} 
void earthquake::set_timezone(string tzone, stringstream &slog){
    string sout;
    ofstream outputfile, logfile;
    if (tzone.size()!=3){
        sout = "Invalid format of timezone.(Hint: Size should be 3.)\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit (0);
    }
    else{
        if (!isalpha(tzone[0])||!isalpha(tzone[1])||!isalpha(tzone[2])){
            sout = "Invalid format of timezone. (Hint: The timezone should be 3 chars)\n";
            slog << sout;
            int F = 2;
            printeq(outputfile,logfile,slog.str(),sout,F);
            exit(0);
        }
        else{
            timezone = tzone;
        }
    }
    return;
}
void earthquake::set_epicenter(stringstream ecenter){
     epicenter = ecenter.str();
     return;
}
string earthquake::uppercase (string &s){
    string result = s;
    for (int i = 0; i<(int)result.size(); i++)
        result[i] = toupper(result[i]);
    return result;
}
bool earthquake::is_valid_magtype(string mt){
    string ss = uppercase(mt);
    return((ss == "ML")||(ss == "MS")||(ss == "MB")||(ss == "MW"));
}
enum Magnitude_type{ 
    ML, 
    MS, 
    MB, 
    MW 
    };  
string earthquake::magtype_to_string(Magnitude_type m){
    switch(m){
        case ML: return "ML";
        case MS: return "MS";
        case MB: return "MB";
        case MW: return "MW";
    }
    exit(EXIT_FAILURE);
}
void earthquake::set_magtype(string magnitude, stringstream &slog){
    string sout;
    ofstream outputfile, logfile;
    if(!is_valid_magtype(magnitude)){
        sout = "Invalid magnitude.\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit (0);
    }
    else{
        string ss = earthquake::uppercase(magnitude);
        if (ss == "ML") magnitudetype= ML;
        if (ss == "MS") magnitudetype= MS;
        if (ss == "MB") magnitudetype= MB;
        if (ss == "MW") magnitudetype= MW;
    }
    return;
}
void earthquake::set_magnitude(float mag,stringstream &slog){
    string sout;
    ofstream outputfile, logfile;
    if (mag<0){
        sout =  "Invalid magnitude value.\n";
        slog << sout;
        int F = 2;
        printeq(outputfile,logfile,slog.str(),sout,F);
        exit (0);
    }
    else{
        magnitude = mag;
    }
} 
