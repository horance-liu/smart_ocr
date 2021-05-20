/*
 *   Copyright (c) 2021, Horance Liu and the respective contributors
 *   All rights reserved.
 *
 *   Use of this source code is governed by a Apache 2.0 license that can be found
 *   in the LICENSE file.
 */
#include "smart_ocr/check_sum.h"
#include "utils/str_utils.h"

namespace {

int sum(const std::string& value) {
  auto num = 0;
  str_utils::foreach(value, [&value, &num](auto ch, auto i) {
    num += (ch - '0') * (value.size() - i);
  }); 
  return num;
}

int checksum(const std::string& value) {
  return sum(value) % 11;
}

}

bool check(const std::string& value) {
  return value.size() == 9 && checksum(value) == 0;
}
