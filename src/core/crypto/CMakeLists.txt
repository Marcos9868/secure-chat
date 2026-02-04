add_library(secure_crypto
    CryptoInit.cpp
    KeyPair.cpp
    Signature.cpp
)

target_include_directories(secure_crypto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(secure_crypto PUBLIC sodium)
