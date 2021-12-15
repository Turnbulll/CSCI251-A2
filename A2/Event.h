#ifndef Event_h
#define Event_h

class Event
{
  public:
    Event();
    virtual std::string getName(){return "Event";};
    virtual float calcPerformance(float){std::cout << "Event calc performance called" << std::endl; return 0;};
    virtual int calcScore(float){std::cout << "Event calc score called" << std::endl; return 0;};
    virtual std::string getType(){return "Event";};
  private:
};

class FieldEvent : public Event
{
  public:
    FieldEvent();
    virtual std::string getName(){return "Field Event";};
    virtual float calcPerformance(float strength){std::cout << "Field Event calc performance called" << std::endl; return 0;};
    virtual int calcScore(float performance){std::cout << "Field Event calc score called" << std::endl; return 0;};
    virtual std::string getType(){return type;};
  private:
    std::string type = "Field Event";
};

class DiscusThrow : public FieldEvent
{
  public:
    DiscusThrow();
    virtual std::string getName(){return "Discus";};
    virtual float calcPerformance(float strength);
    virtual int calcScore(float performance);
  private:
    const float A = 12.91, B = 4, C = 1.1;
};

class HighJump : public FieldEvent
{
  public:
    HighJump();
    virtual std::string getName(){return "High Jump";};
    virtual float calcPerformance(float strength);
    virtual int calcScore(float performance);
  private:
    const float A = 0.8465, B = 75, C = 1.42;
  
};

class StoneSkipping : public FieldEvent
{
  public:
    StoneSkipping();
    virtual std::string getName(){return "Stone Skipping";};
    virtual float calcPerformance(float strength);
    virtual int calcScore(float performance);
  private:
    const float A = 12.91, B = 4, C = 1.1;
  
};

class TunaToss : public FieldEvent
{
  public:
    TunaToss();
    virtual std::string getName(){return "Tuna Toss";};
    virtual float calcPerformance(float strength);
    virtual int calcScore(float performance);
  private:
    const float A = 51.39, B = 1.5, C = 1.05;
  
};

class TrackEvent : public Event
{
  public:
    TrackEvent();
    virtual std::string getName(){return "Track Event";};
    virtual float calcPerformance(float speed){std::cout << "Track Event calc performance called" << std::endl; return 0;};
    virtual int calcScore(float performance){std::cout << "Track Event calc score called" << std::endl; return 0;};
    virtual std::string getType(){return type;};
  private:
    std::string type = "Track Event";
};

class Race100 : public TrackEvent
{
  public:
    Race100();
    virtual std::string getName(){return "100M Race";};
    virtual float calcPerformance(float speed);
    virtual int calcScore(float performance);
  private:
    const float A = 25.4347, B = 18, C = 1.81;
};

class Race1500 : public TrackEvent
{
  public:
    Race1500();
    virtual std::string getName(){return "1500M Race";};
    virtual float calcPerformance(float speed);
    virtual int calcScore(float performance);
  private:
    const float A = 0.03768, B = 480, C = 1.85;
};

class RetroRunningRace : public TrackEvent
{
  public:
    RetroRunningRace();
    virtual std::string getName(){return "Retro Running 50M";};
    virtual float calcPerformance(float speed);
    virtual int calcScore(float performance);
  private:
    const float A = 25.4347, B = 18, C = 1.81;
};

class BeerMile : public TrackEvent
{
  public:
    BeerMile();
    virtual std::string getName(){return "Beer Mile";};
    virtual float calcPerformance(float speed);
    virtual int calcScore(float performance);
  private:
    const float A = 0.03768, B = 480, C = 1.85;
  
};

#endif