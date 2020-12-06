#include "game.hpp"

Game::Game()
: m_totalScore{0}
, m_currentFrameId{0}
, m_lastRoll{-1, -1}
, m_multiplier{0, 0}
{
}


int Game::getScoreOfFirstRoll(Roll currentRoll)
{
    if (currentRoll.nPins == 10)
    {
        m_currentFrameId += 1;
        m_multiplier.nextRoll += 1;
        m_multiplier.nextNextRoll += 1;
    }
    return currentRoll.nPins;
}


void Game::addMultiplier(Roll currentRoll)
{
    // Multipliers are only added for first 9 frames
    if (currentRoll.frameId > 8)
    {
        return;
    }

    const bool rollWasStrike = (
        currentRoll.nPins == 10
        && currentRoll.frameId != m_lastRoll.frameId);
    if (rollWasStrike)
    {
        m_multiplier.nextRoll += 1;
        m_multiplier.nextNextRoll += 1;
    }
    const bool rollWasSpare = (
        currentRoll.nPins + m_lastRoll.nPins == 10
        && currentRoll.frameId == m_lastRoll.frameId);
    if (rollWasSpare)
    {
        m_multiplier.nextRoll += 1;
    }
}


int Game::getScoreOfRoll(Roll currentRoll)
{
    // Calculate score of current roll, multipier take strike/spare bonus into account
    int currentMultiplier = m_multiplier.nextRoll;
    int score = currentRoll.nPins * (1 + currentMultiplier);

    // Shift multipliers for next roll
    m_multiplier.nextRoll = m_multiplier.nextNextRoll;
    m_multiplier.nextNextRoll = 0;

    // Add multiplier for spares and strikes
    addMultiplier(currentRoll);

    // Increase frameId if needed
    const bool strikeOrSecondRoll = (
        currentRoll.nPins == 10) | (currentRoll.frameId == m_lastRoll.frameId);
    if (strikeOrSecondRoll)
    {
        m_currentFrameId += 1;
    }
    return score;
}


void Game::roll(int nPins)
{
    Roll currentRoll = {nPins, m_currentFrameId};

    const bool thisIsFirstRoll = (m_lastRoll.frameId == -1);
    if (thisIsFirstRoll)
    {
        m_totalScore += getScoreOfFirstRoll(currentRoll);
    }
    else
    {
        m_totalScore += getScoreOfRoll(currentRoll);
    }
    // Save last roll
    m_lastRoll = currentRoll;
}


int Game::getScore()
{
    return m_totalScore;
}
