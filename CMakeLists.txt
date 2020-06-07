cmake_minimum_required(VERSION 3.10)
project(ShortestPath)
set (EXE_NAME LinkingSearch)


set (input01 "ControlFile.txt")
set (input02 "Small-Dataset.txt.txt")
set (input03 "Football-Dataset.txt.txt")
set (input04 "Karate-Dataset.txt.txt")



# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} main.cpp MissingFilesException.h SocialNetwork.cpp SocialNetwork.h FileReader.cpp FileReader.h Graph.h Vertex.cpp Vertex.h Node.h LinkedList.h MakeConnection.cpp MakeConnection.h Search.cpp Search.h)