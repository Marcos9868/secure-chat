add_library(secure_identity STATIC identity.cpp)
target_include_directories(secure_identity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR1})