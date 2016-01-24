cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
set(INSTALL_PREFIX /usr)

set(PROJECT_NAME "jnxlogcpp")

add_definitions(-std=c++11)

project(${PROJECT_NAME})

set(SOURCE "")
set(HEADERS "")

add_subdirectory(src/logger)
add_subdirectory(src/appender)
add_subdirectory(src/utils)

include_directories(${PROJECT_INC_DIR}src)
include_directories(${PROJECT_INC_DIR}src/logger)
include_directories(${PROJECT_INC_DIR}src/appender)
include_directories(${PROJECT_INC_DIR}src/utils)


message("${SOURCE}")
message("${HEADERS}")

file(MAKE_DIRECTORY jnxlogcpp_headers)
file(COPY ${HEADERS} DESTINATION jnxlogcpp_headers)

find_package (Threads)
add_library(jnxlogcpp STATIC ${SOURCE})
add_library(jnxlogcpps SHARED ${SOURCE})

target_link_libraries(jnxlogcpp ${LINKER_LIBRARIES})
target_link_libraries(jnxlogcpps ${LINKER_LIBRARIES})

install(TARGETS jnxlogcpp DESTINATION ${INSTALL_PREFIX}/lib)
install(TARGETS jnxlogcpps DESTINATION ${INSTALL_PREFIX}/lib)
install(DIRECTORY jnxlogcpp_headers DESTINATION ${INSTALL_PREFIX}/include)
