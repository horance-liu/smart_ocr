/*
 *   Copyright (c) 2021, Horance Liu and the respective contributors
 *   All rights reserved.
 *
 *   Use of this source code is governed by a Apache 2.0 license that can be found
 *   in the LICENSE file.
 */

#include "smart_ocr/sequence.h"
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <memory>

namespace {

auto close = [](std::ifstream* s) {
  s->close();
};

using FileStream = std::unique_ptr<std::ifstream, decltype(close)>;

void exec(const char* file) {
  FileStream in {
      new std::ifstream(file),
      close
  };

  std::vector<Sequence> seqs {
      std::istream_iterator<Sequence>(*in),
      std::istream_iterator<Sequence>()
  };

  std::copy(seqs.cbegin(), seqs.cend(),
      std::ostream_iterator<Sequence>(std::cout, "\n")
  );
}

void usage(const char* prog) {
    std::cout << "Usage: " << prog
            << " path_to_usecase_in" 
            << std::endl;
}

}

int main(int argc, char** argv) {
  try {
    if (argc < 2) {
      usage(argv[0]);
      return EXIT_FAILURE;
    }
    exec(argv[1]);
    return EXIT_SUCCESS;
  } catch (const std::invalid_argument& e) {
    std::cerr << "bad format: " << e.what() << std::endl;
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "unknown exception" << std::endl;
    return EXIT_FAILURE;
  }
}
