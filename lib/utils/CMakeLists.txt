add_library(spi_utils
    spi_utils.c
    spi_utils.h
)

target_include_directories(spi_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(spi_utils PUBLIC pico_stdlib hardware_spi)