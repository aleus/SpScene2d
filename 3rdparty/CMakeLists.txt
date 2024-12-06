# RxCpp
set(RXX_CPP_INCLUDE_DIR RxCpp/Rx/v2/src)
add_library(RxCpp INTERFACE)
target_include_directories(RxCpp INTERFACE ${RXX_CPP_INCLUDE_DIR})

# Easy Profiler
SET(EASY_PROFILER_NO_GUI ON CACHE BOOL "Build easy_profiler without the GUI application (required Qt)")
SET(EASY_PROFILER_NO_SAMPLES ON CACHE BOOL "")
add_subdirectory(easy_profiler)
set(EASY_PROFILER_INCLUDE_DIR easy_profiler/easy_profiler_core/include)
target_include_directories(easy_profiler PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${EASY_PROFILER_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${EASY_PROFILER_INCLUDE_DIR}>
)
