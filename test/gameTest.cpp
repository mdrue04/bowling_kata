#include "gtest/gtest.h"
#include "../src/game.hpp"


class gameTest
    : public ::testing::Test
{
protected:
    Game m_game;

    virtual void SetUp() override
    {
        m_game = Game();
    }

    void rollOnlyThisNumber(int nRolls, int rollResult)
    {
        for (int i = 0; i < nRolls; ++i)
        {
            m_game.roll(rollResult);
        }
    }
};


TEST_F(gameTest, ScoreIsZeroWithOnlyZeroRolls)
{
    rollOnlyThisNumber(20, 0);
    EXPECT_EQ(0, m_game.getScore());
}

TEST_F(gameTest, ScoreIsTenWithOnlyOnesRolled)
{
    rollOnlyThisNumber(20, 1);
    EXPECT_EQ(20, m_game.getScore());
}

TEST_F(gameTest, testOneSpare)
{
    m_game.roll(5);
    m_game.roll(5);
    m_game.roll(3);
    rollOnlyThisNumber(17, 0);
    EXPECT_EQ(16, m_game.getScore());
}

TEST_F(gameTest, testOneStrike)
{
    m_game.roll(10);
    m_game.roll(5);
    rollOnlyThisNumber(17, 0);
    EXPECT_EQ(20, m_game.getScore());
}

TEST_F(gameTest, testPerfectGame)
{
    rollOnlyThisNumber(12, 10);
    EXPECT_EQ(300, m_game.getScore());
}
