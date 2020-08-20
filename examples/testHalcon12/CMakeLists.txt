cmake_minimum_required(VERSION 3.5)

project(testHalcon12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HAlCON_DIR "C:/Applications/MVTec/HALCON-12.0")
set(HALCON_USE_LIBS
    halcon
    halconc
    halconcpp
    halconcpp10
    halconcpp10xl
    halconcppxl
    halconcxl
    halconx
    halconxl
    halconxxl
    hdevenginecpp
    hdevenginecpp10
    hdevenginecpp10xl
    hdevenginecppxl
    hdevenginex
    hdevenginexxl)
include_directories("${HAlCON_DIR}/include")
link_directories("${HAlCON_DIR}/lib/x64-win64")

file(COPY "assets/monkey.png" DESTINATION ${PROJECT_BINARY_DIR})

set(SourceFiles
    src/main.cpp)
add_executable(${PROJECT_NAME} ${SourceFiles})
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${HALCON_USE_LIBS})
