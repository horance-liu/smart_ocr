add_executable(example_smart_ocr main.cc)

target_link_libraries(example_smart_ocr
  PRIVATE smart_ocr
)