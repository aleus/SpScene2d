# Works with 3.14 and tested through 3.28
cmake_minimum_required(VERSION 3.14...3.28)

# Project name and a few useful settings. Other commands can pick up the results
project(
  SpScene2d
  VERSION 0.1
  DESCRIPTION "Scene2d component"
  LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

# The compiled library code is here
add_subdirectory(Source)

# The executable code is here
add_subdirectory(Examples)

