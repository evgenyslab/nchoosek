cmake_minimum_required(VERSION 2.8.11)
project(nchoosek)

message("Build type=${CMAKE_BUILD_TYPE}")

add_compile_options("-Wno-deprecated")
add_compile_options("-std=c++14")
add_compile_options("-D__linux__")

file(GLOB source_files
        "src/*.h*"
        )

message("${source_files}")

file(GLOB examples
        "examples/*.c*"
        )

include_directories("src/")

foreach( example_file ${examples} )
    # I used a simple string replace, to cut off .cpp.
    get_filename_component(examplesBase ${example_file} NAME)
    string( REPLACE ".cpp" "" file_name ${examplesBase} )
    add_executable( ${file_name} ${example_file} ${source_files})
    # Make sure YourLib is linked to each app
    target_link_libraries( ${file_name} )
endforeach( example_file ${examples} )