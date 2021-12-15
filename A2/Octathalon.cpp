#include "Octathalon.h"
#include "Event.h"
#include "Team.h"


//MAIN FUNCTION
int main(int argc, char* argv[])
{
  if(atoi(argv[1])>= 1 && atoi(argv[1])<=8 && atoi(argv[2])>= 1 && atoi(argv[2])<=8)
  {
    //ASSIGN NO' OF TEAMS/MEETS
    int numberOfTeams = atoi(argv[1]);
    int numberOfMeets = atoi(argv[2]);
    int meetNo = 1;

    //VECTORS TO STORE INFORMATION ABOUT OCTATHALON
    static const std::vector<std::string> teamNames {"All Stars", "Outliers", "Warriors", "Wrecking Crew", "The Cavalry", "Strength Collective", "Full Impact", "Wrong Code"};
    static const std::vector<std::string> locations {"Sydney", "Paris", "Tokyo", "Cairo", "Las Vegas", "Rome", "Venice", "New York" };
    static const std::vector<std::string> attributes {"Hot","Lean","Smog","Sand","Glitter","Grand","Smelly","Apple"};
    static std::vector<int> breakValues {};
    
    

    //REPORT NO OF TEAMS/MEETS
    std::cout << "Number of Teams: " << numberOfTeams << std::endl;
    std::cout << "Number of Meets: " << numberOfMeets << std::endl;
    std::cout << "--------------------------" << std::endl;

    //REPORT LOCATIONS
    int day = 1;
    int breakTemp;
    for (int k = 0; k<numberOfMeets; k++)
    {
      std::cout << "Meet " << meetNo << " has day " << day++ << " and " << day++ << std::endl; 
      Location l(locations[k], attributes[k]);
      std::cout << "Location for meeting " << meetNo << " is in " << locations[k] << std::endl;
      l.printLocationAttributes(locations[k]);
      breakTemp =+ rand()%(2 + 1) + 5;
      breakValues.push_back(breakTemp);
      day += breakTemp;
      if(k==numberOfMeets-1)
      {
        std::cout << "--------------------------" << std::endl;
        continue;
      }
      std::cout << "The break for meet " << meetNo++ << " is " << breakValues[k] << " days" << std::endl;
      std::cout << "--------------------------" << std::endl;
    }


    
    //CREATE TEAMS
    for(int l = 0; l<numberOfTeams ; l++)
    {
      Team t(teamNames[l], l);
      teamList.push_back(t);
    }

    //RUN OCTATHALON
    meetNo = 1;
    for (int i = 0; i< numberOfMeets; i++)
    {
      Location l(locations[i], attributes[i]);
      Weather w1;
      std::cout << "It is " << w1.getWeather() << " in " << l.getLocation() << std::endl;
      std::cout << "------------------------------" << std::endl;
      runDay(1, meetNo);
      std::cout << "------------------------------" << std::endl;
      Weather w2;
      std::cout << "It is " << w2.getWeather() << " in " << l.getLocation() << std::endl;
      std::cout << "------------------------------" << std::endl;
      runDay(2, meetNo);
      std::cout << "------------------------------" << std::endl;
      runBreak(meetNo, numberOfMeets, breakValues.at(i));
      std::cout << "------------------------------" << std::endl;
      meetNo++;
    }
    return 0;
    
  }
  else
  {
    std::cerr << "Please enter Team Number and Meet Number as an integer value (1 to 8 inclusive)" << std::endl; 
    return 1;
  }
}











//RUN THROUGH A FULL DAY OF THE OCTATHALON
void runDay(int day, int meetNo)
{
  if(day==1) //ON OCTATHALON IS DAY ONE
  {
    std::cout << "Meet " << meetNo << " day 1 started" << std::endl;
    Race100 race100; DiscusThrow discus; StoneSkipping skipping; RetroRunningRace retroRace;


    TrackEvent *e1 = &race100;
    FieldEvent *e2 = &discus;
    FieldEvent *e3 = &skipping;
    TrackEvent *e4 = &retroRace;

    Event *events[4] = {e1,e2,e3,e4};

    std::cout << "------------------------------" << std::endl;

  for(int eventCount = 0; eventCount<=3; eventCount++)
  {
    for(Team team: teamList)
    {
      for(Athlete athlete : team.maleAthletes)
      {
        if(events[eventCount]->getType()=="Field Event")
        {   
          int performance = events[eventCount]->calcPerformance(athlete.getStrength());
          int score = events[eventCount]->calcScore(performance);
          athlete.setScore(score);
          std::cout << athlete.getName() << " in " << events[eventCount]->getName() << " got " << performance << "m and scored " << athlete.getScore() << std::endl;
        }
        else
        {
          int performance = events[eventCount]->calcPerformance(athlete.getSpeed());
          int score = events[eventCount]->calcScore(performance);
          athlete.setScore(score);
          std::cout << athlete.getName() << " in " << events[eventCount]->getName() << " ran it in " << performance << "s and scored " << athlete.getScore() << std::endl;
        }
        athlete.incrementFatigue();
      }  
    }
    std::cout << "------------------------------" << std::endl;
    for(Team team: teamList)
    {
      for(Athlete athlete : team.femaleAthletes)
      {
        if(events[eventCount]->getType()=="Field Event")
        {   
          int performance = events[eventCount]->calcPerformance(athlete.getStrength());
          int score = events[eventCount]->calcScore(performance);
          athlete.setScore(score);
          std::cout << athlete.getName() << " in " << events[eventCount]->getName() << " got " << performance << "m and scored " << athlete.getScore() << std::endl;
        }
        else
        {
          int performance = events[eventCount]->calcPerformance(athlete.getSpeed());
          int score = events[eventCount]->calcScore(performance);
          athlete.setScore(score);
          std::cout << athlete.getName() << " in " << events[eventCount]->getName() << " ran it in " << performance << "s and scored " << athlete.getScore() << std::endl;
        }
        athlete.incrementFatigue();
      }   
    }
    std::cout << "------------------------------" << std::endl;
  }
  
  std::cout << "Day " << day << " finished" << std::endl;
  }
  else if(day==2)
  {
    std::cout << "Meet " << meetNo << " day 2 started" << std::endl;

    BeerMile beerMile;TunaToss tunaToss;HighJump highJump;Race1500 race1500;

    TrackEvent *e1 = &beerMile;
    FieldEvent *e2 = &tunaToss;
    FieldEvent *e3 = &highJump;
    TrackEvent *e4 = &race1500;

    Event *events[4] = {e1,e2,e3,e4};

    std::cout << "------------------------------" << std::endl;

  for(int eventCount = 0; eventCount<=3; eventCount++)
  {
    for(Team team: teamList)
    {
      for(Athlete athlete : team.maleAthletes)
      {
        if(events[eventCount]->getType()=="Field Event")
        {   
          int performance = events[eventCount]->calcPerformance(athlete.getStrength());
          int score = events[eventCount]->calcScore(performance);
          athlete.setScore(score);
          std::cout << athlete.getName() << " in " << events[eventCount]->getName() << " got " << performance << "m and scored " << athlete.getScore() << std::endl;
        }
        else
        {
          int performance = events[eventCount]->calcPerformance(athlete.getSpeed());
          int score = events[eventCount]->calcScore(performance);
          athlete.setScore(score);
          std::cout << athlete.getName() << " in " << events[eventCount]->getName() << " ran it in " << performance << "s and scored " << athlete.getScore() << std::endl;
        }
        athlete.incrementFatigue();
      }   
    }
    std::cout << "------------------------------" << std::endl;
    for(Team team: teamList)
    {
      for(Athlete athlete : team.femaleAthletes)
      {
        if(events[eventCount]->getType()=="Field Event")
        {   
          int performance = events[eventCount]->calcPerformance(athlete.getStrength());
          int score = events[eventCount]->calcScore(performance);
          athlete.setScore(score);
          std::cout << athlete.getName() << " in " << events[eventCount]->getName() << " got " << performance << "m and scored " << athlete.getScore() << std::endl;
        }
        else
        {
          int performance = events[eventCount]->calcPerformance(athlete.getSpeed());
          int score = events[eventCount]->calcScore(performance);
          athlete.setScore(score);
          std::cout << athlete.getName() << " in " << events[eventCount]->getName() << " ran it in " << performance << "s and scored " << athlete.getScore() << std::endl;
        } 
        athlete.incrementFatigue();
      }   
    }
    std::cout << "------------------------------" << std::endl;
  }   
    std::cout << "day " << day << " finished" << std::endl;
    std::cout << "Meet " << meetNo << " finished" << std::endl;

    std::cout << "------------------------------" << std::endl;

    Award a;
    //a.sortWinners()

    for(Team team: teamList)
    {
      for(Athlete athlete : team.maleAthletes)
      {
        std::cout << athlete.getName() << " got a total score of " << athlete.getTotalScore() << std::endl;
      }
      for(Athlete athlete : team.femaleAthletes)
      {
        std::cout << athlete.getName() << " got a total score of " << athlete.getTotalScore() << std::endl;
      }
    }

  }
  else
  {
    std::cerr << "Wrong day/meetNo in Day constructor" << std::endl;
  }
}

//RUN THROUGH A BREAK
void runBreak(int meetNo, int numberOfMeets, int breakValues)
{
   if(meetNo<numberOfMeets)
  {
    std::cout << "The Break has started for meet " << meetNo << " it is " << breakValues << " days" << std::endl;

    for(Team team: teamList) //recover and train male athletes
    {
      for(Athlete athlete : team.maleAthletes)
      {
        for(Physiotherapist phys: team.physiotherapists)
        {
          team.callPhysio(phys, athlete);
        }
        for(Psychologist psych: team.psychologists)
        {
          team.callPsychologist(psych, athlete);
        }
        for(Trainer train: team.trainers)
        {
          team.callTrainers(train, athlete);
        }
      }
    }
    
    for(Team team: teamList) //recover and train female athletes
    {
      for(Athlete athlete : team.femaleAthletes)
      {
        for(Physiotherapist phys: team.physiotherapists)
        {
          team.callPhysio(phys, athlete);
        }
        for(Psychologist psych: team.psychologists)
        {
          team.callPsychologist(psych, athlete);
        }
        for(Trainer train: team.trainers)
        {
          team.callTrainers(train, athlete);
        }
      }
    }

  }

  else if(meetNo==numberOfMeets)
  {
    std::cout << "The Octathalon has finished" << std::endl;
  }
}

