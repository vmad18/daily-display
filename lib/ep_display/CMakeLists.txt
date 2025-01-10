add_library(ep_display
    ep_display.c
    ep_display.h
)

target_include_directories(ep_display PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ep_display PUBLIC spi_utils)