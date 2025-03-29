cmake_minimum_required(VERSION 3.10.0)
project(tic_tac_toe VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2.5.1 
)

FetchContent_MakeAvailable(SFML)

include_directories("Include")

file(GLOB SOURCES 
"Source/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(tic_tac_toe PROPERTIES LINK_FLAGS "-mwindows")

target_link_libraries(tic_tac_toe PRIVATE sfml-graphics sfml-window sfml-system)
