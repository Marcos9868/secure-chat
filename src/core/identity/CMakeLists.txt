add_library(secure_identity STATIC identity.cpp Fingerprint.cpp)
target_include_directories(secure_identity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR1})
target_link_libraries(secure_identity PUBLIC sodium)