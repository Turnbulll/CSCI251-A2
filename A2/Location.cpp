#include "Octathalon.h"
#include "Event.h"
#include "Team.h"


//LOCATION CONSTRUCTOR
Location::Location(std::string loc, std::string attr)
{
  location = loc;
  attribute = attr;
}

//GETTER FOR LOCATION
std::string Location::getLocation()
{
  return location;
}

//GET MODIFIER FOR LOCATION
void Location::printLocationAttributes(std::string location)
{
  if(location == "Sydney")
  {
    std::cout << "The grounds are hot in Sydney, the athletes might get exhausted quicker" << std::endl;
  }
  else if(location == "Paris")
  {
    std::cout << "The grounds are on a lean in Paris, its going to take more effort to get around the track" << std::endl;
  } 
  else if(location == "Tokyo") 
  {
    std::cout << "The grounds are surrounded by smog Tokyo, this will slightly effect athletes" << std::endl;
  }
  else if (location == "Cairo") 
  {
    std::cout << "The grounds coated with sand in Cairo, this might be a slip hazard" << std::endl;
  }
  else if(location =="Las Vegas")
  {
    std::cout << "The grounds are covered with glitter in Las Vegas, this might be a fabulous slip hazard" << std::endl;
  }
  else if(location == "Rome")
  {
    std::cout << "The grounds are grand in Rome, the athlete might be inspired" << std::endl;
  } 
  else if(location == "Venice")
  {
    std::cout << "The grounds smell funny in Venice, this might disgust the athletes" << std::endl;
  }
  else if(location == "New York")
  {
    std::cout << "The grounds have a singular small apple in the centre in New York, this has a very small chance to distract athletes" << std::endl;
  }
  else
  {
    std::cerr << "Wrong location recieved by getLocationAttribute()" << std::endl;
  } 
}

/*void Location::attributeImpact(Athlete athlete)
{
  if(location == "Sydney")
  {
    athlete.setFatigue(athlete.getFatigue()*2);
  }
  else if(location == "Paris")
  {
    athlete.setSpeed(athlete.getSpeed()*0.98);
  } 
  else if(location == "Tokyo") 
  {
    athlete.setFatigue(athlete.getFatigue()*1.1);
  }
  else if (location == "Cairo") 
  {
    int injuryChance = rand()%100+1;
    if (injuryChance>95)
    {
      athlete.injure();
    }
  }
  else if(location =="Las Vegas")
  {
    int injuryChance = rand()%100+1;
    if (injuryChance>95)
    {
      athlete.injure();
    }
  }
  else if(location == "Rome")
  {
    athlete.setStrength(athlete.getStrength()*1.1);
    athlete.setSpeed(athlete.getSpeed()*1.1);
  } 
  else if(location == "Venice")
  {
    athlete.setStrength(athlete.getStrength()*0.99);
    athlete.setSpeed(athlete.getSpeed()*0.98);
  }
  else if(location == "New York")
  {
    int injuryChance = rand()%100+1;
    if (injuryChance==100)
    {
      athlete.injure();
    }
  }
  else
  {
    std::cerr << "Wrong location recieved by getLocationAttribute()" << std::endl;
  }
}*/

