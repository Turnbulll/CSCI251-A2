#include "Octathalon.h"
#include "Event.h"
#include "Team.h"

//SET LEVEL OF MEMBER
std::string setLevel(float level)
{
  
  if(level<=2.5)
  {
    return "Novice";
  }
  else if(level>2.5 && level<=5)
  {
    return "Competent";
  }
  else if(level>5 && level<=7.5)
  {
    return "Experienced";
  }
  else if(level>7.5 && level<=10)
  {
    return "Master";
  }
  else
  {
    return"Unranked";
  }
}

//CONSTRUCTOR FOR ATHLETE
Athlete::Athlete(std::string n, std::string g)
{
  name = n;
  gender = g;
  strength = rand()%10+1;
  speed = rand()%10+1;
  fatigue = 0;
  totalScore = 0;
  injured = false;
  std::cout << "Athlete named " << name << " who identifies as a " << gender << " has arrived to compete. ";
  
  if(strength > speed)
  {
    std::cout << name << " is strong." << std::endl;
  }
  else
    std::cout << name << " is fast." << std::endl;
}

//GETTERS FOR ATHLETE
float Athlete::getSpeed()
{
  return speed;
}

float Athlete::getStrength()
{
  return strength;
}

std::string Athlete::getName()
{
  return name;
}

int Athlete::getScore()
{
  return score;
}

int Athlete::getTotalScore()
{
  return totalScore;
}

int Athlete::getFatigue()
{
  return fatigue;
}

bool Athlete::isInjured()
{
  if(injured == true)
  {
    return true;
  }
  else
  {
    return false;
  }
  
}

//SETTER FOR ATHLETE
void Athlete::setScore(int scr)
{
  score = scr;
  totalScore += scr;
}

void Athlete::setFatigue(int fat)
{
  fatigue = fat;
}

int Athlete::incrementFatigue()
{
  fatigue += 1;
  std::cout << name << " has a fatigue level of " << fatigue << std::endl;
  return fatigue;
}

void Athlete::setSpeed(float s)
{
  speed = s;
}

void Athlete::setStrength(float s)
{
  strength = s;
}

void Athlete::injure()
{
  injured = true;
  speed = speed * 0.3;
  strength = strength * 0.3;
  std::cout << name << " has been injured " << std::endl;
}


//CONSTRUCTOR FOR TEAMMANAGER
TeamManager::TeamManager(std::string n)
{
  name = n;
  std::cout << "Team Manager named " << name << " has arrived." << std::endl;
}

//CONSTRUCTOR FOR TRAINER
Trainer::Trainer(std::string n , std::string s)
{
  name = n;
  specialisation = s;
  experience = rand()%10+1;
  
  std::cout << setLevel(experience) << " trainer named " << name << " who specialises in " << specialisation << " has arrived." << std::endl;
}

std::string Trainer::getSpecialisation()
{
  return specialisation;
}

//TRAIN FOR ATHLETE
void Trainer::train(Athlete a)
{
  if(specialisation == "Field")
  {
    experience = (experience/10) + 1;
    int training = a.getStrength() * experience;
    a.setStrength(training);
  }
  else
  {
    experience = (experience/10) + 1;
    int training = a.getSpeed() * experience;
    a.setSpeed(training);
  }
}

//CONSTRUCTOR FOR PHYSIOTHERAPIST
Physiotherapist::Physiotherapist(std::string n, std::string teamName)
{
  name = n;
  recovery = rand()%10+1;
  teamName = teamName;

  std::cout << setLevel(recovery) << " physiotherapist named " << name << " has arrived." << std::endl;
}

//GET RECOVERY FOR PHYSIO
float Physiotherapist::getRecovery()
{
  return recovery;
}

//RUN RECOVER FOR ATHLETE
void Physiotherapist::recover(Athlete a)
{
  int fatigue;
  recovery = recovery/10; 
  fatigue = a.getFatigue() * recovery;
  if(fatigue<0)
  {
    fatigue=0;
  }
  a.setFatigue(fatigue);
}


//CONSTRUCTOR FOR PSYCHOLOGIST
Psychologist::Psychologist(std::string n)
{
  name = n;
  therapy = rand()%10+1;

  std::cout << setLevel(therapy) << " psychologist named " << name << " has arrived." << std::endl;
}

float Psychologist::getTherapy()
{
  return therapy;
}

//RUN THERAPY FOR ATHLETE
void Psychologist::psychSession(Athlete a)
{
  int fatigue;
  therapy = therapy/10;
  fatigue = a.getFatigue() * therapy;
  if(fatigue<0)
  {
    fatigue=0;
  }
  a.setFatigue(fatigue);
}


//CONSTRUCTOR FOR TEAM
Team::Team(std::string teamName, int teamSerial)
{
  name = teamName;
  static const std::vector<std::string> teamMemberNames {"Jim", "Jane", "Blayne", "Kane", "Shane", "Ane", "Charlimane"};
  int incrementName = 0;
  std::string serial = std::to_string(teamSerial);

  std::cout << "A team called " << name << " bands together" << std::endl;

  Athlete athleteM(teamMemberNames[incrementName++] + serial, "male"), athleteF(teamMemberNames[incrementName++] + serial, "female");
  maleAthletes.push_back(athleteM);
  femaleAthletes.push_back(athleteF);
  TeamManager teamManager(teamMemberNames[incrementName++] + serial);
  Trainer trainerF(teamMemberNames[incrementName++] + serial, "Field"), trainerT(teamMemberNames[incrementName++] + serial, "Track");
  trainers.push_back(trainerF);
  trainers.push_back(trainerT);
  Physiotherapist physio(teamMemberNames[incrementName++] + serial, teamName);
  physiotherapists.push_back(physio);
  Psychologist psychologist(teamMemberNames[incrementName++] + serial);
  psychologists.push_back(psychologist);

  std::cout << "-----------------------------------" << std::endl;
}

//RUN RECOVERY FOR ATHLETE
void Team::callPhysio(Physiotherapist physio, Athlete athlete)
{
  physio.recover(athlete);
}

//RUN THERAPY FOR ATHLETE
void Team::callPsychologist(Psychologist psych, Athlete athlete)
{
  psych.psychSession(athlete);
}

//RUN TRAINING FOR ATHLETE
void Team::callTrainers(Trainer trainer, Athlete athlete)
{
  trainer.train(athlete);
}





