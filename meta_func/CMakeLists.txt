# CMake file for src directory

# Add the library (including all module files)
add_library(meta_func STATIC)

# Add module files to the library using FILE_SET
target_sources(meta_func
    PUBLIC FILE_SET CXX_MODULES
    TYPE
        CXX_MODULES
    FILES
        meta_func.ixx
)

# Enable module support
target_compile_features(meta_func PUBLIC cxx_std_23)
target_compile_options(meta_func PRIVATE -fmodules-ts)

target_link_libraries(meta_func PRIVATE base_dataStruct)
target_link_libraries(meta_func PRIVATE meta_data)



