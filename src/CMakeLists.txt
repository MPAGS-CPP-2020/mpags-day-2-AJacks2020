# - Set CMake requirements the declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Lists all the files
add_executable(mpags-cipher mpags-cipher.cpp  MPAGSCipher/TransformChar.cpp MPAGSCipher/processCommandLine.cpp MPAGSCipher/runCaesarCipher.cpp)

# - Adds a new directory path
target_include_directories(mpags-cipher PRIVATE MPAGSCipher)

# - Don't allow vendor extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# - Adds the desired compiler flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher 
    PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
    )