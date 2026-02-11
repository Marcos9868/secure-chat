add_library(secure_transport STATIC
  ITransport.cpp
  LocalTransport.cpp
)

target_include_directories(secure_transport
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(secure_transport PUBLIC cxx_std_20)
