# Add the library (including all module files)
add_library(meta_data STATIC)

# Add module files to the library using FILE_SET
target_sources(meta_data
    PUBLIC FILE_SET CXX_MODULES
    TYPE
        CXX_MODULES
    FILES
        meta_funcData.ixx
)

# Enable module support
target_compile_features(meta_data PUBLIC cxx_std_23)
target_compile_options(meta_data PRIVATE -fmodules-ts)


