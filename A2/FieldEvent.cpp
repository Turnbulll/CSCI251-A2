
#include "Octathalon.h"
#include "Event.h"
#include "Team.h"

FieldEvent::FieldEvent()
{
  
}

DiscusThrow::DiscusThrow()
{
  std::cout << "Discus Throw is being set up" << std::endl;
}

float DiscusThrow::calcPerformance(float strength)
{
  float performance =   strength * 7 /* ((rand()%20+90)/100)*/;
  return performance; //returns max 70m for performance
}

int DiscusThrow::calcScore(float performance)
{
  if(performance<B){
    performance=B;
  }
  int score = pow(A*(performance-B),C);
  if (score>1250)
  {
    score = 1250;
  }
  return score;
}

HighJump::HighJump()
{
  std::cout << "High Jump is being set up" << std::endl;
}

float HighJump::calcPerformance(float strength)
{
  float performance = strength * 22;
  return performance; //returns max 222cm for performance
}

int HighJump::calcScore(float performance)
{ 
  if(performance<B){
    performance=B;
  }
  int score = pow(A*(performance-B),C);
  if (score>1250)
  {
    score = 1250;
  }
  return score;
}


StoneSkipping::StoneSkipping()
{
  std::cout << "Stone Skipping is being set up" << std::endl;
}

float StoneSkipping::calcPerformance(float strength)
{
  float performance =  strength*12;
  return performance; //returns max 120M for performance
}

int StoneSkipping::calcScore(float performance)
{
  if(performance<B){
    performance=B;
  }
  int score = pow(A*(performance-B),C);
  if (score>1250)
  {
    score = 1250;
  }
  return score;
}

TunaToss::TunaToss()
{
  std::cout << "Tuna Toss is being set up" << std::endl;
}

float TunaToss::calcPerformance(float strength)
{
  float performance =  strength*4;
  return performance; //returns max 40M for performance
}

int TunaToss::calcScore(float performance)
{
  if(performance<B){
    performance=B;
  }
  int score = pow(A*(performance-B),C);
  if (score>1250)
  {
    score = 1250;
  }
  return score;
}