#include "gameV2.hpp"


GameV2::GameV2()
: m_currentRoll{0},
  m_rollResults{0}
{
}


void GameV2::roll(int rollResult)
{
   m_rollResults[m_currentRoll] = rollResult;
   m_currentRoll++;
}


int GameV2::getScore()
{
   int score = 0;
   int frameIdx = 0;
   for (int frame = 0; frame < 10; ++frame)
   {
      if (isStrike(frameIdx))
      {
         score += 10 + getStrikeBonus(frameIdx);
         frameIdx++;
      }
      else if (isSpare(frameIdx))
      {
         score += 10 + getSpareBonus(frameIdx);
         frameIdx += 2;
      }
      else
      {
         score += getRegularPointsInFrame(frameIdx);
         frameIdx += 2;
      }
   }
   return score;
}


bool GameV2::isStrike(int frameIdx)
{
   return (m_rollResults[frameIdx] == 10);
}


bool GameV2::isSpare(int frameIdx)
{
   return ((m_rollResults[frameIdx] + m_rollResults[frameIdx + 1]) == 10);
}


int GameV2::getStrikeBonus(int frameIdx)
{
   return (m_rollResults[frameIdx + 1] + m_rollResults[frameIdx + 2]);
}


int GameV2::getSpareBonus(int frameIdx)
{
   return (m_rollResults[frameIdx + 2]);
}


int GameV2::getRegularPointsInFrame(int frameIdx)
{
   return (m_rollResults[frameIdx] + m_rollResults[frameIdx + 1]);
}
