#include "gtest/gtest.h"

extern "C" {
#include "poker.h"
}

TEST (PokerTest, TestTest)
{
    EXPECT_EQ(12, giveValueToCard("QH"));
}

TEST (PokerTest, TestCardValuesInHands)
{
    player_t player = playerCreator("2H 3D 5S 9C KD");
    EXPECT_EQ(2, player.player_cards[0].value);
    EXPECT_EQ(3, player.player_cards[1].value);
    EXPECT_EQ(5, player.player_cards[2].value);
    EXPECT_EQ(9, player.player_cards[3].value);
    EXPECT_EQ(13, player.player_cards[4].value);
}

TEST (PokerTest, TestWhiteWinsByHighCard)
{
    player_t player1 = playerCreator("2H 3D 5S 9C KD");
    player_t player2 = playerCreator("2C 3H 4S 8C AH");
    char test[25] = "White wins!";
    EXPECT_STREQ(test, isHigher(player1, player2));
}

TEST (PokerTest, TestTie)
{
    player_t player1 = playerCreator("2H 3D 5S 9C KD");
    player_t player2 = playerCreator("2D 3H 5C 9S KH");
    char test[25] = "Tie.";
    EXPECT_STREQ(test, isHigher(player1, player2));
}

TEST (PokerTest, TestWhiteWinsByPair)
{
    player_t player1 = playerCreator("2H 3D 5S 9C AH");
    player_t player2 = playerCreator("2D 3H 5C KD KH");
    char test[25] = "White wins!";
    EXPECT_STREQ(test, isHigher(player1, player2));

}


