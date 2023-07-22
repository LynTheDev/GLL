cmake_minimum_required(VERSION 3.10)
project(GLL LANGUAGES CXX)

find_package(glfw3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)

add_subdirectory(external/glad)

file(COPY glsl DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_executable(${PROJECT_NAME}
    src/main.cc
    
    src/graphics/init.cc
    src/graphics/callbacks/callbacks.cc

    src/utils/platform.cc
    src/utils/colour.cc

    src/graphics/entities/shader.cc
    src/graphics/entities/mesh.cc
)

target_include_directories(${PROJECT_NAME} PRIVATE
    include/
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glad

    Boost::headers
    Boost::filesystem
)