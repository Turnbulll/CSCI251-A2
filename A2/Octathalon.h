#ifndef Octathalon_h
#define Octathalon_h

#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<cmath>
#include<algorithm>

void runDay(int day, int meetNo);
void runBreak(int meetNo, int numberOfMeets, int breakValues);

class Award
{
  public:
    Award();
    void sortWinners();
    //void printAwards();
  private:
  //

};


class Location
{
  public:
    Location(std::string location, std::string attribute);
    std::string getLocation();
    void printLocationAttributes(std::string location);
    //void attributeImpact(Athlete athlete);
  private:
    std::string location;
    std::string attribute;
};

class Weather
{
  public:
    Weather();
    std::string getWeather();
    //void weatherEffects(Athlete athlete);
  private:
    std::string weather;
};

#endif