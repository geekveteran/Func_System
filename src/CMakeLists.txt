# CMakeList.txt : CMake project for FunctionSystem, include source and define
# project specific logic here.
#

# Create executable target
add_executable(FunctionSystem main.cpp)

# Add sources with module interface
target_sources(FunctionSystem
    PRIVATE
        main.cpp
    PUBLIC FILE_SET CXX_MODULES
    TYPE
        CXX_MODULES
    FILES
        math_operations.ixx
)

# Add compiler-specific flags for module support
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(FunctionSystem PRIVATE -fmodules-ts)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(FunctionSystem PRIVATE -fmodules)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(FunctionSystem PRIVATE /std:c++23 /experimental:module)
endif()

# TODO: Add FunctionSystems and install targets if needed.