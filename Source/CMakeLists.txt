file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS ${SpScene2d_SOURCE_DIR}/Include/Sp/*.h)
file(GLOB_RECURSE PRIVATE_HEADERS CONFIGURE_DEPENDS Include/*.h)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)

# find_package(easy_profiler REQUIRED)

add_library(SpScene2d ${HEADERS} ${PRIVATE_HEADERS} ${SOURCES})

target_include_directories(SpScene2d PUBLIC ${SpScene2d_SOURCE_DIR}/Include)
target_include_directories(SpScene2d PRIVATE Include)

# target_link_libraries(SpScene2d
#     PRIVATE
#     easy_profiler
# )
