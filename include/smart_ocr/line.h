/*
 *   Copyright (c) 2021, Horance Liu and the respective contributors
 *   All rights reserved.
 *
 *   Use of this source code is governed by a Apache 2.0 license that can be found
 *   in the LICENSE file.
 */

#ifndef HFC416880_5F5C_463A_B0D0_48027742AA56
#define HFC416880_5F5C_463A_B0D0_48027742AA56

#include <deque>
#include <string>

struct Alternative {
  virtual void accept(const std::string&) = 0;
  virtual ~Alternative() {}
};

struct Line {
  Line(const std::string& = "");

  void reset();
  void merge(const Line&);

  std::string value() const;
  void alternatives(Alternative&) const;

private:
  void zip(const Line&);

private:
  std::deque<std::string> nums;
};

#endif
