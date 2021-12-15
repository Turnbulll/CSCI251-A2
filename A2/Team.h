#ifndef Team_h
#define Team_h

#include<vector>

class Athlete
{
  public:
    Athlete(std::string name, std::string gender);
    std::string getName();
    float getSpeed();
    float getStrength();
    int getScore();
    int getTotalScore();
    void setScore(int score);
    int getFatigue();
    int incrementFatigue();
    void setFatigue(int fat);
    void setSpeed(float speed);
    void setStrength(float strength);
    bool isInjured();
    void injure();
  private:
    std::string name, gender;
    float strength, speed;
    int score, totalScore, fatigue;
    bool injured;
};

class TeamManager
{
  public:
    TeamManager(std::string name);
  private:
    std::string name;
};

class Trainer
{
  public:
    Trainer(std::string name, std::string specialisation);
    void train(Athlete a);
    std::string getSpecialisation();
  private:
    std::string name, specialisation;
    float experience;
};

class Physiotherapist
{
  public:
    Physiotherapist(std::string name, std::string teamName);
    float getRecovery();
    void recover(Athlete a);
  private:
    std::string name;
    std::string teamName;
    float recovery;
};

class Psychologist
{
  public:
    Psychologist(std::string name);
    float getTherapy();
    void psychSession(Athlete a);
  private:
    std::string name;
    float therapy;
};


class Team
{
  public:
    Team(std::string teamName, int teamSerial);
    Athlete athleteM(std::string name, std::string gender), athleteF(std::string name, std::string gender);
    TeamManager teamManager(std::string name);
    Trainer trainerF(std::string name, std::string specialisation), trainerT(std::string name, std::string specialisation);
    Physiotherapist physio(std::string name);
    Psychologist psychologist(std::string name);
    std::vector<Athlete> maleAthletes{};
    std::vector<Athlete> femaleAthletes{};
    std::vector<Physiotherapist> physiotherapists{};
    std::vector<Psychologist> psychologists{};
    std::vector<Trainer> trainers {};
    void callPhysio(Physiotherapist physio, Athlete athlete);
    void callPsychologist(Psychologist psych, Athlete athlete);
    void callTrainers(Trainer trainer, Athlete athlete);
  private:
    std::string name;
};

static std::vector<Team> teamList;
std::string setLevel(float level);

#endif