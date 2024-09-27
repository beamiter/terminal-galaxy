# Set the minimum required version of cmake for this project
cmake_minimum_required(VERSION 3.5)

# Define the project and the language used
project(dwm C)

# Read the VERSION from config.mk
set(VERSION "6.5") # Replace with your actual version

# Configure compiler options here if necessary
add_compile_options(
    # Put your compile options here (e.g., -Wall -Wextra -O2)
)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR} # You might want to include other directories
)

find_package(Freetype REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(XFT REQUIRED xft)

# List of source files
set(SRC_FILES
    drw.c
    dwm.c
    util.c
)

# Define the executable target
add_executable(dwm ${SRC_FILES})

# Include the FreeType header directories
target_include_directories(dwm PRIVATE
    ${FREETYPE_INCLUDE_DIRS}
    ${XFT_INCLUDE_DIRS}
)

# Link the FreeType libraries
target_link_libraries(dwm PRIVATE X11
    fontconfig
    Xinerama 
    ${FREETYPE_LIBRARIES} 
    ${XFT_LIBRARIES}
 )

# Installation rules
install(TARGETS dwm DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES dwm.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1)

# Custom targets
add_custom_target(dist
    COMMAND git archive --prefix=dwm-${DWM_VERSION}/ HEAD
            | gzip > dwm-${DWM_VERSION}.tar.gz
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Uninstallation is not directly supported in CMake, but you can write a script for it or use a custom target
