In the CMakeLists.txt, add this line:

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

in order to read in the file in the same directory as compiled executable file so that no need for absolute directory.