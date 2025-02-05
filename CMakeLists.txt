cmake_minimum_required(VERSION 3.13...3.27)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)
include(pico_extras_import.cmake)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)
set(PICO_CXX_ENABLE_RTTI 1)  # only if you need RTTI
set(PICO_CYW43_ARCH_THREADSAFE_BACKGROUND 1)
set(PICO_CYW43_ARCH_DEFAULT_STACK_SIZE 8192)
set(DPICO_CYW43_SUPPORTED 1)
set(DPICO_BOARD pico_w)

project(pi_proj)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# set(CJSON_BUILD_TEST OFF CACHE BOOL "" FORCE)
# # Also disable install if not needed
# set(CJSON_INSTALL OFF CACHE BOOL "" FORCE)

# add_subdirectory(./include/cJSON)
add_subdirectory(./lib/utils)  
add_subdirectory(./lib/ep_display)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(display
    display.cpp
    lib/regions/daily_info.cpp
)

# target_include_directories(display PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}
# )

target_include_directories(display PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_options(display PRIVATE -fno-exceptions)


# pull in common dependencies
target_link_libraries(display
    ep_display 
    display_region
    spi_utils
    network
    hardware_spi
    pico_cyw43_arch_lwip_threadsafe_background
    pico_stdlib)


    
# if (PICO_CYW43_SUPPORTED)
#     target_link_libraries(display pico_cyw43_arch_none)
# endif()

pico_enable_stdio_usb(display 1)
pico_enable_stdio_uart(display 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(display)

# add url via pico_set_program_url
# example_auto_set_url(blink)