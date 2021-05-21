#include "smart_ocr/sequence.h"
#include "gtest/gtest.h"

struct SequenceTest : testing::Test 
{
protected:
  static void expect(
    Sequence::Lines lines, const std::string& expected) {
    ASSERT_EQ(expected, Sequence(lines).str());
  }
};

TEST_F(SequenceTest, no_guess_for_711_111_111) {
  expect({
      " _                         ",
      "  |  |  |  |  |  |  |  |  |",
      "  |  |  |  |  |  |  |  |  |",
  }, "711111111");
}
