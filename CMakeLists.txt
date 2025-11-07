# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico2_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(LogicGates C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(LogicGates LogicGates.c )
target_link_libraries(LogicGates
        pico_stdlib              # for core functionality
        pico_cyw43_arch_none     # we need Wifi to access the GPIO, but we don't need anything else
        )

pico_set_program_name(LogicGates "LogicGates")
pico_set_program_version(LogicGates "0.1")

# no_flash means the target is to run from RAM
# pico_set_binary_type(LogicGates no_flash)

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(LogicGates 0)
pico_enable_stdio_usb(LogicGates 0)

# Add the standard include files to the build
target_include_directories(LogicGates PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)



pico_add_extra_outputs(LogicGates)

