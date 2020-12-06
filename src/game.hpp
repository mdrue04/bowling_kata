#ifndef GAME_HPP
#define GAME_HPP

struct Roll
{
    int nPins;
    int frameId;
};

struct Multiplier
{
    int nextRoll;
    int nextNextRoll;
};

class Game
{
public:
    Game();
    void roll(int);
    int getScore();

private:
    int getScoreOfFirstRoll(Roll);
    int getScoreOfRoll(Roll);
    void addMultiplier(Roll);

    int m_totalScore;
    Roll m_lastRoll;
    int m_currentFrameId;
    Multiplier m_multiplier;
};

#endif // GAME_HPP
