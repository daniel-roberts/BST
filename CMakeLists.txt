cmake_minimum_required(VERSION 2.8.12)

project(driver C)

add_library(bst STATIC ${PROJECT_SOURCE_DIR}/src/bst.c)
add_executable(driver ${PROJECT_SOURCE_DIR}/src/driver.c)
target_include_directories(driver PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(bst PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(driver PUBLIC bst)
