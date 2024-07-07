cmake_minimum_required(VERSION 3.25)


include(pico_sdk_import.cmake)

project(video CXX C ASM)

pico_sdk_init()

add_executable(video main.c)

pico_generate_pio_header(video ${CMAKE_CURRENT_LIST_DIR}/output.pio)

target_sources(video PRIVATE main.c)

target_link_libraries(video PRIVATE pico_stdlib hardware_pio)

pico_add_extra_outputs(video)