#ifndef GAMEV2_HPP
#define GAMEV2_HPP

#include <array>

constexpr int MAX_ROLLS = 21;

class GameV2
{
public:
    GameV2();
    void roll(int);
    int getScore();
private:
    bool isStrike(int);
    bool isSpare(int);
    int getStrikeBonus(int);
    int getSpareBonus(int);
    int getRegularPointsInFrame(int);
    int m_currentRoll;
    std::array<int, MAX_ROLLS> m_rollResults;
};


#endif // GAMEV2_HPP