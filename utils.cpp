#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metric.h"
#include "inversePR.h"
using namespace std;
using namespace arma;

string getDate(){
	char date[80];
    sprintf(date,"%d-%d-%d-%d:%d:%d",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	return date;
}

string getTime(){
	char now[80];
	sprintf(now,"%d:%d:%d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	return now;
}
