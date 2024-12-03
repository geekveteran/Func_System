# Add the library (including all module files)
add_library(func_dataBase STATIC)

# Add module files to the library using FILE_SET
target_sources(func_dataBase
    PUBLIC FILE_SET CXX_MODULES
    TYPE
        CXX_MODULES
    FILES
        func_dataBase.ixx
)

# Enable module support
target_compile_features(func_dataBase PUBLIC cxx_std_23)
target_compile_options(func_dataBase PRIVATE -fmodules-ts)

target_link_libraries(func_dataBase PRIVATE base_dataStruct)

