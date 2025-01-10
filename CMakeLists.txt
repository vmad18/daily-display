cmake_minimum_required(VERSION 3.13...3.27)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(pi_proj)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_subdirectory(./lib/utils)  
add_subdirectory(./lib/ep_display)

add_executable(display
    display.cpp
)

# target_include_directories(display PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}
# )

# pull in common dependencies
target_link_libraries(display
    ep_display 
    spi_utils
    hardware_spi
    pico_stdlib)


if (PICO_CYW43_SUPPORTED)
    target_link_libraries(display pico_cyw43_arch_none)
endif()

pico_enable_stdio_usb(display 1)
pico_enable_stdio_uart(display 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(display)

# add url via pico_set_program_url
# example_auto_set_url(blink)