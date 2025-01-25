cmake_minimum_required(VERSION 3.15)
project(PocoTest)

find_package(Poco REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} Poco::Poco)
