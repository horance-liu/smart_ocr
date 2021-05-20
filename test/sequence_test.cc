#include "smart_ocr/sequence.h"
#include "cctest/cctest.h"
#include <stdexcept>

FIXTURE(SequenceTest) {
  static void expect(
    Sequence::Lines lines, const std::string& expected) {
    ASSERT_EQ(expected, Sequence(lines).str());
  }

  TEST("711111111") {
    expect({
      " _                         ",
      "  |  |  |  |  |  |  |  |  |",
      "  |  |  |  |  |  |  |  |  |",
    }, "711111111");
  }
};
