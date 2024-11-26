cmake_minimum_required(VERSION 3.13)

# Include the pico SDK
include(pico_sdk_import.cmake)

# Include the directories for submodules
include_directories(${CMAKE_SOURCE_DIR}/lib/LoRa)  # This will include LoRa library headers

# Define the StudySense project
project(StudySense)

# Initialize the Pico SDK
pico_sdk_init()

# Add the source files for the main project (add your source files like main.c here)
add_executable(StudySense
    main.c  # Include your main .c file here
    # Other modules you want to include, such as PIR, RFID, etc.
)

# Generate the PIO header if needed (for SPI)
pico_generate_pio_header(StudySense ${CMAKE_CURRENT_LIST_DIR}/SPIPIO.pio)

# Add your source files for modules (add additional files if necessary)
target_sources(StudySense PRIVATE
    main.c  # Your main source file
    # Add other module sources here (e.g., PIR, RFID)
)

# Link the necessary libraries for your project
target_link_libraries(StudySense PRIVATE 
    pico_stdlib
    hardware_gpio
    hardware_spi
    hardware_pio
    # Any other libraries you need for PIR, RFID, etc.
)

# Generate map/bin/hex files
pico_add_extra_outputs(StudySense)
