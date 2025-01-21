# utils/CMakeLists.txt

# Library for spi_utils
add_library(spi_utils
    spi_utils.c
    spi_utils.h
)
# Library for spi_utils
add_library(network
    network.c
    network.h
)
# Library for display_region
add_library(display_region
    display_region.cpp
    display_region.hpp
)


# Specify include directories for spi_utils
target_include_directories(spi_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Specify include directories for display_region
target_include_directories(network PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Specify include directories for display_region
target_include_directories(display_region PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link required libraries for spi_utils
target_link_libraries(spi_utils PUBLIC pico_stdlib hardware_spi)
target_link_libraries(network PUBLIC pico_stdlib pico_cyw43_arch_lwip_threadsafe_background hardware_spi)