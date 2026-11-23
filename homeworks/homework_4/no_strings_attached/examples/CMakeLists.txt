# A program target, built from this .cpp file
add_executable(split_strings split_strings.cpp)

# Connect it to the library. PRIVATE because nothing links to a program
target_link_libraries(split_strings PRIVATE string_split)