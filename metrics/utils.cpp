#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <time.h>
#include <fstream>
#include <ostream>
#include <ctime>
#include "utils.h"
using namespace std;
using namespace arma;

string getDate(){
	time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
	char date[80];
    sprintf(date,"%d_%d_%d",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
	return date;
}

string getTime(){
	time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
	char now[80];
	sprintf(now,"TIME_%d_%d_%d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	return now;
}

string getSeconds(){
	time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
	char now[80];
	sprintf(now,"_%d", timeinfo->tm_hour*3600+ timeinfo->tm_min*60+ timeinfo->tm_sec);
	return now;
}
