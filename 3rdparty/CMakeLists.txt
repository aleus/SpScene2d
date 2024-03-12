set(RXX_CPP_INCLUDE_DIR RxCpp/Rx/v2/src)

add_library(RxCpp INTERFACE)

target_include_directories(RxCpp INTERFACE ${RXX_CPP_INCLUDE_DIR})
