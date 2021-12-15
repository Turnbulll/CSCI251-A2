#include "Octathalon.h"
#include "Event.h"
#include "Team.h"

//TRACKEVENT CONSTRUCTOR
TrackEvent :: TrackEvent()
{

}

//100 METRE CONSTRUCTOR
Race100 :: Race100()
{
  std::cout << "100 Metre Race is being set up" << std::endl;
}

//CALC PERFORMANCE FOR 100M
float Race100::calcPerformance(float speed)
{
  float performance =  speed;
  return performance; //returns max 10s for performance
}

//CALC SCORE FOR 100M
int Race100::calcScore(float performance)
{
  if(performance>B){
    performance=B;
  }
  int score = pow(A*(B-performance),C);
  if (score>1250)
  {
    score = 1250;
  }
  return score;
}

//1500M RACE CONSTRUCTOR
Race1500 :: Race1500()
{
  std::cout << "1500 Metre Race is being set up" << std::endl;
}

//CALC PERFORMANCE FOR 1500M
float Race1500::calcPerformance(float speed)
{
  float performance =  speed*24;
  
  return performance; //returns max 240s for performance
}

//CALC SCORE FOR 100M
int Race1500::calcScore(float performance)
{
  if(performance>B){
    performance=B;
  }
  int score = pow(A*(B-performance),C);
  if (score>1250)
  {
    score = 1250;
  }
  return score;
}

//50M RETRORUNNING CONSTRUCTOR
RetroRunningRace :: RetroRunningRace()
{
  std::cout << "Retro Running Race is being set up" << std::endl;
}

//CALC PERFORMANCE FOR RETRO 50M
float RetroRunningRace::calcPerformance(float speed)
{
  float performance =  speed;
  return performance; //returns max 20s for performance
}

//CALC SCORE FOR RETRO 50M
int RetroRunningRace::calcScore(float performance)
{
  if(performance>B){
    performance=B;
  }
  int score = pow(A*(B-performance),C);
  if (score>1250)
  {
    score = 1250;
  }
  return score;
}

//BEER MILE CONSTRUCTOR
BeerMile :: BeerMile()
{
  std::cout << "Beer Mile is being set up" << std::endl;
}

//CALC PERFORMANCE FOR BEERMILE
float BeerMile::calcPerformance(float speed)
{
  float performance =  speed*30;
  return performance; //returns max 300s for performance
}

//CALC SCORE FOR BEER MILE
int BeerMile::calcScore(float performance)
{
  if(performance>B){
    performance=B;
  }
  int score = pow(A*(B-performance),C);
  if (score>1250)
  {
    score = 1250;
  }
  return score;
}