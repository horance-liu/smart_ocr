/*
 *   Copyright (c) 2021, Horance Liu and the respective contributors
 *   All rights reserved.
 *
 *   Use of this source code is governed by a Apache 2.0 license that can be found
 *   in the LICENSE file.
 */

#ifndef H616B6931_30DB_4BA3_861E_0A60F59A537E
#define H616B6931_30DB_4BA3_861E_0A60F59A537E

#include <iostream>
#include <vector>

#include "smart_ocr/line.h"

struct Sequence {
  using Lines = std::vector<std::string>;

  Sequence() = default;
  Sequence(Lines&);

  void parse(Lines&);
  std::string str() const;

private:
  std::string guess() const;

private:
  Line line;
  std::string value;
};

std::istream& operator>>(std::istream&, Sequence&);
std::ostream& operator<<(std::ostream&, const Sequence&);

#endif
