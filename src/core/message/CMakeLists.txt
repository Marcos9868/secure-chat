add_library(secure_message STATIC
  Message.cpp
)

target_include_directories(secure_message PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(secure_message PUBLIC cxx_std_20)
