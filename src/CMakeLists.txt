# CMakeList.txt : CMake project for FunctionSystem, include source and define
# project specific logic here.
#

# Create executable target
add_executable(FunctionSystem main.cpp)

# Add compiler-specific flags for module support
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(FunctionSystem PRIVATE -fmodules-ts)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(FunctionSystem PRIVATE -fmodules)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(FunctionSystem PRIVATE /std:c++23 /experimental:module)
endif()


# Link the library to the executable
target_link_libraries(FunctionSystem PRIVATE base_dataStruct)
target_link_libraries(FunctionSystem PRIVATE meta_data)
target_link_libraries(FunctionSystem PRIVATE meta_func)
target_link_libraries(FunctionSystem PRIVATE func_dataBase)
target_link_libraries(FunctionSystem PRIVATE base_func)
# TODO: Add FunctionSystems and install targets if needed.