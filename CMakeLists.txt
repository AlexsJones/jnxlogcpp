cmake_minimum_required(VERSION 2.8)
set(INSTALL_PREFIX /usr)

set(PROJECT_NAME "jnxlogcpp")

project(${PROJECT_NAME})

set(SOURCE "")
set(HEADERS "")

add_subdirectory(src/logger)
add_subdirectory(src/appender)
add_subdirectory(tests)

include_directories(${PROJECT_INC_DIR}src)
include_directories(${PROJECT_INC_DIR}src/logger)
include_directories(${PROJECT_INC_DIR}tests)

message("${SOURCE}")
message("${HEADERS}")

file(MAKE_DIRECTORY jnxlogcpp_headers)
file(COPY ${HEADERS} DESTINATION jnxlogcpp_headers)

add_library(jnxlogcpp STATIC ${SOURCE})
add_library(jnxlogcpps SHARED ${SOURCE})

target_link_libraries(jnxlogcpp ${LINKER_LIBRARIES})
target_link_libraries(jnxlogcpps ${LINKER_LIBRARIES})

install(TARGETS jnxlogcpp DESTINATION ${INSTALL_PREFIX}/lib)
install(TARGETS jnxlogcpps DESTINATION ${INSTALL_PREFIX}/lib)
install(DIRECTORY jnxlogcpp_headers DESTINATION ${INSTALL_PREFIX}/include)
