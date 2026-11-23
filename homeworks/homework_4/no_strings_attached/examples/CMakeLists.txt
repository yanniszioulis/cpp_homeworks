# A program target, built from this .cpp file
add_executable(split_strings split_strings.cpp)
add_executable(trim_strings trim_strings.cpp)

# Connect it to the library. PRIVATE because nothing links to a program
target_link_libraries(split_strings PRIVATE string_split)
target_link_libraries(trim_strings PRIVATE string_trim)