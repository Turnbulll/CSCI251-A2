#include "Octathalon.h"
#include "Event.h"
#include "Team.h"

Award :: Award()
{
  std::vector<std::string> awards{"Gold", "Silver", "Bronze"} ;
  std::cout << "Award Created" << std::endl;
}

//SORT ALL WINNERS
void Award::sortWinners()
{
  for(Team team: teamList)
  {
    std::sort(team.maleAthletes.begin(), team.maleAthletes.end(), [](Athlete& athlete1, Athlete& athlete2) -> bool
    { return athlete1.getTotalScore() < athlete2.getTotalScore(); } ) ;
  }
  
}

/*//PRINT ALL AWARDS
void Award::printAwards()
{
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
}*/