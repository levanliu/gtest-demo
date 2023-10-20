add_library(tokenizer 
)

target_sources(tokenizer
  PRIVATE
    tokenizer.cpp

  PUBLIC
    tokenizer.hpp
    parser.hpp
  )

target_include_directories(tokenizer
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )


# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(tokenizer
    PUBLIC
      "--coverage"
    )
  target_link_options(tokenizer
    INTERFACE
      "--coverage"
    )
endif()
