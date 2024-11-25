# CMake file for src directory

# Add the library (including all module files)
add_library(base_func STATIC)

# Add module files to the library using FILE_SET
target_sources(base_func
    PUBLIC FILE_SET CXX_MODULES
    TYPE
        CXX_MODULES
    FILES
        base_func.ixx
)

# Enable module support
target_compile_features(base_func PUBLIC cxx_std_23)
target_compile_options(base_func PRIVATE -fmodules-ts)

target_link_libraries(base_func PRIVATE base_dataStruct)
target_link_libraries(base_func PRIVATE meta_data)
target_link_libraries(base_func PRIVATE meta_func)