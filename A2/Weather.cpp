#include "Octathalon.h"
#include "Event.h"
#include "Team.h"

//CONSTRUCTOR FOR WEATHER
Weather::Weather()
{
  std::vector <std::string> weatherType{"sunny","raining", "windy"};
  weather = weatherType[rand()%2];
}

//GET WEATHER
std::string Weather::getWeather()
{
  return weather;
}

/*// WEATHER EFFECT
void Weather::weatherEffects(Athlete a)
{
  if(weather=="wind")
  {
    int chanceOfInjury = rand()%100+1;
    if(chanceOfInjury>98)
    {
      a.injure();
    }
    a.setSpeed(a.getSpeed()*1.1);
  }
  if(weather=="raining")
  {
    int chanceOfInjury = rand()%100+1;
    if(chanceOfInjury>92)
    {
      a.injure();
    }
    a.setSpeed(a.getSpeed()*0.98);
  }
  else
  {
    //no effect if sunny
  }
  
}*/