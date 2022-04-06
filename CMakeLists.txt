cmake_minimum_required(VERSION 3.14)

project(seed
  VERSION 0.1.0
  DESCRIPTION "A C++ application"
  HOMEPAGE_URL "https://github.com/legends2k/cpp-vcpkg-seed"
  LANGUAGES CXX)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not supported. "
    "Please delete 'CMakeCache.txt' and 'CMakeFiles/' first.")
endif()

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# https://vcpkg.io/en/docs/examples/manifest-mode-cmake.html

add_executable(${PROJECT_NAME}
  src/main.cc src/main.h)

# Confirm strictly to C++17.  FlatBuffers needs C++11 or newer.
# https://cliutils.gitlab.io/modern-cmake/chapters/features/cpp11.html
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_EXTENSIONS OFF
  CXX_STANDARD_REQUIRED ON)

# Find and include third-party libraries here
find_package(FLTK CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE
  fltk fltk_images
  spdlog::spdlog_header_only)
