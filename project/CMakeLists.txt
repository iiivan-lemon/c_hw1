

add_library(input_data STATIC src/input_data.c)
target_include_directories(input_data PUBLIC include)


add_library(consistent STATIC src/prog.c)
target_include_directories(consistent PUBLIC include)
target_link_libraries(consistent PUBLIC input_data)
target_link_libraries(consistent PRIVATE m)


add_library(parallel SHARED src/parallel_prog.c)
target_include_directories(parallel PUBLIC include)
target_link_libraries(parallel PUBLIC input_data)
target_link_libraries(parallel PRIVATE m)

