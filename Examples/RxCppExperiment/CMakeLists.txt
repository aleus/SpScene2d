set(SOURCES main.cpp)

add_executable(RxCppExperiment ${SOURCES})

target_link_libraries(RxCppExperiment PRIVATE RxCpp)
