cmake_minimum_required(VERSION 3.22)

project(profitview_socketio_cpp LANGUAGES CXX VERSION 1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

#set(CMAKE_C_COMPILER "/usr/bin/gcc-10")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECTS_DIR "$ENV{HOME}/projects")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

find_package(OpenSSL REQUIRED SSL Crypto)

find_package(Poco REQUIRED 
    Net 
    JSON 
    Net 
    Util
    Encodings 
    NetSSL 
    Foundation 
    Data 
    Crypto 
    XML
)

find_package(Threads REQUIRED)

add_subdirectory(src)

add_library(profitview_socketio "")
target_sources(profitview_socketio
    PUBLIC
        MarketDataAdapter.h
        profitview_util.h
    PRIVATE
        MarketDataAdapter.cpp
        profitview_util.cpp
)

target_link_libraries(profitview_socketio
    PRIVATE 
        SIOClient
)

target_include_directories(profitview_socketio 
    PUBLIC 
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/src/include"
)

# add the executable
add_executable(profitview_socketio_cpp "")
target_sources(profitview_socketio_cpp
    PUBLIC
        DataStreamer.h
        profitview_socketio_cppConfig.h
    PRIVATE
        DataStreamer.cpp
        streaming_example.cpp
)

configure_file(profitview_socketio_cppConfig.h.in profitview_socketio_cppConfig.h)

target_link_libraries(profitview_socketio_cpp
    PRIVATE
        profitview_socketio
        SIOClient
        Threads::Threads
        Poco::Net
        Poco::NetSSL
)