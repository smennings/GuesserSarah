/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}

TEST(GuesserTest, match) {
	Guesser object("Secret");
	ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, no_match) {
	Guesser object("Secret");
	ASSERT_FALSE(object.match("Guess"));
}

TEST(GuesserTest, same_length) {
	Guesser object("Secret");
	ASSERT_FALSE(object.match("Matchs"));
}

TEST(GuesserTest, near_match) {
	Guesser object("Secret");
	ASSERT_LT(0, object.distance("Secretend"));
}

TEST(GuesserTest, different) {
	Guesser object("Secret");
	ASSERT_LT(0, object.distance("Matchs"));
}

TEST(GuesserTest, sandwiched) {
	Guesser object("Secret");
	ASSERT_EQ(6, object.distance("MSecretM"));
}

TEST(GuesserTest, different_case) {
	Guesser object("Secret");
	ASSERT_EQ(1, object.distance("secret"));
}

TEST(GuesserTest, reversed) {
	Guesser object("Secret");
	ASSERT_EQ(4, object.distance("terceS"));
}

TEST(GuesserTest, three_guesses) {
	Guesser object("Secret");
	ASSERT_FALSE(object.match("Pecret"));
	ASSERT_FALSE(object.match("secret"));
	ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, many_guesses) {
	Guesser object("Secret");
	ASSERT_FALSE(object.match("Pecret"));
	ASSERT_FALSE(object.match("secret"));
	ASSERT_FALSE(object.match("lecret"));
	ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest, big_difference_guesses) {
	Guesser object("Secret");
	ASSERT_FALSE(object.match("matchs"));
	ASSERT_FALSE(object.match("secret"));
	ASSERT_FALSE(object.match("Secret"));
}
// I don't know how to test this, but the number of guesses wouldn't be going down, right?

TEST(GuesserTest, find_early_guesses) {
	Guesser object("Secret");
	ASSERT_FALSE(object.match("secret"));
	ASSERT_TRUE(object.match("Secret"));
	ASSERT_FALSE(object.match("secret"));
	ASSERT_TRUE(object.match("Secret"));
}