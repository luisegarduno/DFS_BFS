
cmake_minimum_required(VERSION 3.10)
project(ShortestPath)
set (EXE_NAME LinkingSearch)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....
set (input01 "ControlFile.txt")
set (input02 "g1.txt")
set (input03 "pa03-footballdataset.txt")
set (input04 "karatedataset.txt")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} main.cpp missingFilesException.h SocialNetwork.cpp SocialNetwork.h FileReader.cpp FileReader.h Graph.h Vertex.cpp Vertex.h Node.h LinkedList.h MakeConnection.cpp MakeConnection.h Search.cpp Search.h)