# CMake file for src directory

# Add the library (including all module files)
add_library(base_pointer STATIC)

# Add module files to the library using FILE_SET
target_sources(base_pointer
    PUBLIC FILE_SET CXX_MODULES
    TYPE
        CXX_MODULES
    FILES
        simple_pointer.ixx
)

# Enable module support
target_compile_features(base_pointer PUBLIC cxx_std_23)
target_compile_options(base_pointer PRIVATE -fmodules-ts)



