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

// DISTANCE TESTS
TEST(GuesserTest, identical)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secret"), 0 );
}

TEST(GuesserTest, diff_length)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secrett"), 1);
}

TEST(GuesserTest, diff_long_length)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secretgjrioajgiojroapjiopjgiojiorgaji"), 6);
}

TEST(GuesserTest, diff_all_letters)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Abdvif"), 6 );
}

TEST(GuesserTest, diff_one_letter)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secref"), 1 );
}

TEST(GuesserTest, diff_two_letters)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Sefref"), 2 );
}

TEST(GuesserTest, diff_cap_end)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("SecreT"), 1 );
}

TEST(GuesserTest, diff_cap_start)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("secret"), 1 );
}

TEST(GuesserTest, diff_cap_mid)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("SeCret"), 1 );
}
TEST(GuesserTest, diff_cap_all)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("SECRET"), 5 );
}
TEST(GuesserTest, special_char)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secret!"), 1 );
}
TEST(GuesserTest, special_char2)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secre!"), 1 );
}
TEST(GuesserTest, special_char3)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("!@#$%^&*()"), 6 );
}
TEST(GuesserTest, blank)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance(""), 6 );
}
TEST(GuesserTest, long_diff_cap)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("SecretTown"), 4 );
}
TEST(GuesserTest, diff_short)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Sec"), 3 );
}

TEST(GuesserTest, xtra_long)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("QWERTYUIOPASDFGHJKLZXCVBNMQWERTYUIOPASDFGHJKLZXCVBNM"), 6 );
}

//MATCH TESTS
TEST(GuesserTest, first_try_match)
{
  Guesser object("Secret");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, second_try_match)
{
  Guesser object("Secret");
  object.match("Sefret");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, third_try_match)
{
  Guesser object("Secret");
  object.match("Sefret");
  object.match("Sefret");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, fourth_try_match)
{
  Guesser object("Secret");
  object.match("Sefret");
  object.match("Sefret");
  object.match("Sefret");
  ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest, locked_out_short)
{
  Guesser object("Secret");
  object.match("bad");
  ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest, locked_out_long)
{
  Guesser object("Secret");
  object.match("Secretbad");
  ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest, two_distance)
{
  Guesser object("Secret");
  object.match("Secr");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, two_distance2)
{
  Guesser object("Secret");
  object.match("Secretse");
  ASSERT_TRUE(object.match("Secret"));
}
TEST(GuesserTest, four_correct_matches)
{
  Guesser object("Secret");
  object.match("Secret");
  object.match("Secret");
  object.match("Secret");
  ASSERT_TRUE(object.match("Secret"));
}
TEST(GuesserTest, correct_false_matchmix)
{
  Guesser object("Secret");
  object.match("Secret");
  object.match("Sefret");
  object.match("Sefret");
  object.match("Secret");
  ASSERT_TRUE(object.match("Secret"));
}


//REMAINING TESTS
TEST(GuesserTest, initial_remaining)
{
  Guesser object("Secret");
  ASSERT_EQ(object.remaining(), 3);
}
TEST(GuesserTest, less_remaining)
{
  Guesser object("Secret");
  object.match("Sefret");
  ASSERT_EQ(object.remaining(), 2);
}
TEST(GuesserTest, less_remaining2)
{
  Guesser object("Secret");
  object.match("Sefret");
  object.match("Sefret");
  ASSERT_EQ(object.remaining(), 1);
}

TEST(GuesserTest, no_remaining)
{
  Guesser object("Secret");
  object.match("Sefret");
  object.match("Sefret");
  object.match("Sefret");
  ASSERT_EQ(object.remaining(), 0);
}
TEST(GuesserTest, keep_remaining)
{
  Guesser object("Secret");
  object.match("Secret");
  ASSERT_EQ(object.remaining(), 3);
}
TEST(GuesserTest, reset_remaining)
{
  Guesser object("Secret");
  object.match("Sefret");
  object.match("Secret");
  ASSERT_EQ(object.remaining(), 3);
}

