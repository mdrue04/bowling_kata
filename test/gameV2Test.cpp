#include "gtest/gtest.h"
#include "../src/gameV2.hpp"


class gameV2Test
    : public ::testing::Test
{
protected:
    GameV2 m_game;

    virtual void SetUp() override
    {
        m_game = GameV2();
    }

    void rollOnlyThisNumber(int nRolls, int rollResult)
    {
        for (int i = 0; i < nRolls; ++i)
        {
            m_game.roll(rollResult);
        }
    }
};


TEST_F(gameV2Test, ScoreIsZeroWithOnlyZeroRolls)
{
    rollOnlyThisNumber(0, 20);
    EXPECT_EQ(0, m_game.getScore());
}

TEST_F(gameV2Test, ScoreIsTenWithOnlyOnesRolled)
{
    rollOnlyThisNumber(20, 1);
    EXPECT_EQ(20, m_game.getScore());
}

TEST_F(gameV2Test, testOneSpare)
{
    m_game.roll(5);
    m_game.roll(5);
    m_game.roll(3);
    rollOnlyThisNumber(17, 0);
    EXPECT_EQ(16, m_game.getScore());
}

TEST_F(gameV2Test, testOneStrike)
{
    m_game.roll(10);
    m_game.roll(5);
    rollOnlyThisNumber(17, 0);
    EXPECT_EQ(20, m_game.getScore());
}

TEST_F(gameV2Test, testPerfectGame)
{
    rollOnlyThisNumber(12, 10);
    EXPECT_EQ(300, m_game.getScore());
}
