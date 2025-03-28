cmake_minimum_required(VERSION 3.10.0)
project(tic_tac_toe VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("Include")

file(GLOB SOURCES 
"Source/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
