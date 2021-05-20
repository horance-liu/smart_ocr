file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
    *.cpp
    *.cc
    *.c
)

add_executable(smart_ocr_sequence_test ${srcs})

target_link_libraries(smart_ocr_sequence_test
    PRIVATE 
        smart_ocr 
        cctest 
        cctest_main
)

add_test(NAME smart_ocr_sequence_test COMMAND smart_ocr_sequence_test)
