/* Homework 7
*
* Learn to implement classes to replace structs, and public functions to manipulate information stored 
* in the class private members.
*
* GitHub: https://github.com/YuanZhou2015/Homework-7/network
*
* By Yuan Zhou
* March/21/2015
 */
#include "earthquake.h"
#include "station.h" 
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

void print(ofstream &outputfile, ofstream &logfile,
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

void open_log(string logfilename, ofstream &logfile){
    string information;
    ofstream outputfile;
    logfile.open(logfilename.c_str());
    if (!logfile.is_open()){
        cout<< "Cannot open log file: "
            << logfilename
            << endl;
        return;
    }
}

void open_input(string inputfilename, ifstream &inputfile, stringstream &slog, int &flag){
    ofstream outputfile, logfile;
    string  sout;
    inputfile.open(inputfilename.c_str());
    if (!inputfile.is_open()){
        sout = "\nCannot open input file: ";
        slog << sout;
        int F = 2;
        print(outputfile, logfile, slog.str(), sout, F);
        sout = inputfilename;
        slog << sout;
        F = 2;
        print(outputfile, logfile, slog.str(), sout, F);
        sout = "\n";
        slog << sout;
        F = 2;
        print(outputfile, logfile, slog.str(), sout, F);
        flag = 1;
        exit(0);
    } 
    return;
}

void open_output(string outputfilename, ofstream &outputfile, stringstream &slog){
    ofstream logfile;
    string sout;
    outputfile.open(outputfilename.c_str());
    logfile.open("yuan.log");
    if (!outputfile.is_open() ){
        sout = "\nCannot open output file: ";
        slog << sout;
        int F = 2;
        print(outputfile, logfile, slog.str(), sout, F);
        sout = outputfilename;
        slog << sout;
        F = 2;
        print(outputfile, logfile, slog.str(), sout, F);
        exit(0);
        return;
    }
}

string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

int main(){
    ifstream inputfile;
    ofstream logfile, outputfile;
    string inputfilename, logfilename, outputfilename;
    string sout, d, information;
    stringstream slog;
    int flag=0,F;
    open_log("yuan.log",logfile);
    logfile.close();
    sout = "> Enter input file name: ";
    F = 2;
    print(outputfile,logfile,slog.str(),sout,F);
    cin >> inputfilename;
    if (flag ==1)
    return 0;
    sout = "Opening file: ";
    slog << sout;
    F = 2;
    print(outputfile,logfile,slog.str(),sout,F);
    sout =inputfilename;
    slog << sout;
    F = 2;
    print(outputfile,logfile,slog.str(),sout,F);
    open_input(inputfilename,inputfile,slog,flag);
    sout = "\nProcessing input...\n";
    slog << sout;
    F = 2;
    print(outputfile,logfile,slog.str(),sout,F);
    logfile.close();
    if (flag == 1)
    return 0;
   
    //Reading the header

    string id,t,tz,eqname,magtype;
    float magnitude;
    earthquake eqinfor;
    double longitude,latitude,depth;
    stringstream epicenter, ss;

    inputfile >> id;
    eqinfor.set_ID(id);
    inputfile >> d;
    eqinfor.set_date(d,slog);
    inputfile >> t;
    eqinfor.set_time(t,slog);
    inputfile >> tz;
    eqinfor.set_timezone(tz,slog);
    getline(inputfile,eqname);
    getline(inputfile,eqname);
    eqinfor.set_earthquakename(eqname);
    inputfile >> longitude >> latitude >> depth;
    epicenter << "(" << longitude << ", " << latitude << ", " << depth << ")\n";
    inputfile >> magtype;
    eqinfor.set_magtype(magtype,slog);
    inputfile >> magnitude;
    eqinfor.set_magnitude(magnitude, slog); 

    // If the header read successfully, then open the output file.
    // Print the header information into output file.

    open_output("yuan.out",outputfile,slog);
    outputfile.close();
    sout = "Header read correctly!\n";
    slog << sout;
    F = 2;
    print(outputfile,logfile,slog.str(),sout,F);
    ss << eqinfor.get_date(); 
    ss << eqinfor.get_time ()<< ' ' << eqinfor.get_timezone() << ' ';
    ss << eqinfor.get_magtype() << ' ' << eqinfor.get_magnitude() << ' ';
    ss << eqinfor.get_eqname() << "\n";
    ss << "[" << eqinfor.get_ID() <<"] \n";
    ss << eqinfor.get_epicenter();
    F = 1;
    print(outputfile,logfile,ss.str(),sout,F);

    // Reading the table of earthquake information. 
    // The number of valid information will not more than 300.

    const int MAXSIZE = 300;
    station signal,Signaldata[MAXSIZE];
    int size = 0, i, a = 0, flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0,flag5 = 0;
    string networkcode, stname, typeofband, typeofinstru, orientation,orien;

    for(i = 1;inputfile != NULL && size<MAXSIZE; i++){
        inputfile >> networkcode;
        if(inputfile == NULL)
            break;
        Signaldata[size].set_networkcode(networkcode,slog,ss,i,flag1);
        inputfile >> stname;
        Signaldata[size].set_stationname(stname,slog,ss,i,flag2);
        inputfile >> typeofband;
        Signaldata[size].set_typeofband(typeofband,slog,ss,i,flag3);
        inputfile >> typeofinstru;
        Signaldata[size].set_typeofinstru(typeofinstru,slog,ss,i,flag4);
        inputfile >> orientation;
        Signaldata[size].set_orientation(orientation,slog,ss,i,flag5);
        orien = Signaldata[size].get_orientation();
        int n = (int)orientation.size(), j = 0;
        if(flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0){
            while (j<n){
                Signaldata[size].set_networkcode(networkcode,slog,ss,i,flag1);
                Signaldata[size].set_stationname(stname,slog,ss,i,flag2);
                Signaldata[size].set_typeofband(typeofband,slog,ss,i,flag3);
                Signaldata[size].set_typeofinstru(typeofinstru,slog,ss,i,flag4);
                Signaldata[size].set_orientation(orien, j);
                size++;
                j++;
            }
        }
        else a++;
    }

    // Generat the report for total information read.

    F = 2;
    sout = "\nTotal invalid entries igored: ";
    slog << sout;
    print(outputfile,logfile,slog.str(),sout,F); 
    sout = itos(a);
    slog << sout; 
    print(outputfile,logfile,slog.str(),sout,F); 
    sout = "\nTotal valid entries read: ";
    slog << sout;
    print(outputfile,logfile,slog.str(),sout,F);
    sout = itos(i-a-1);
    slog << sout; 
    print(outputfile,logfile,slog.str(),sout,F);
    sout = "\nSignal names produced: ";
    slog << sout;
    print(outputfile,logfile,slog.str(),sout,F);
    sout = itos(size);
    slog << sout <<"\n";
    print(outputfile, logfile,slog.str(),sout,F);
    F = 1;
    sout = '\0';
    ss << itos(size) <<"\n";
    print(outputfile, logfile,ss.str(),sout,F);     
    for (int j = 0; j<size; j++){
        ss << eqinfor.get_ID() << "." << Signaldata[j].get_networkcode() << "." << Signaldata[j].get_stationname() << "." 
           << Signaldata[j].get_bandtype() << Signaldata[j].get_instrutype() << Signaldata[j].get_orientation() <<"\n"; 
    }
    F = 1;
    print(outputfile,logfile,ss.str(),sout,F); 
    F = 2;
    sout = "\nFinished!\n";
    slog << sout;
    print(outputfile,logfile,slog.str(),sout,F);

}