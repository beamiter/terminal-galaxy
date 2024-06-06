# Set the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(xiate VERSION 1.0.0 LANGUAGES C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

# Add compiler flags
# add_compile_options(-Wall -Wextra -O3)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(VTE REQUIRED vte-2.91)

# Target executable
add_executable(xiate terminal.c)

# Define macros
target_compile_definitions(xiate PRIVATE __NAME__="xiate" __NAME_CAPITALIZED__="Xiate")

# Include directories and link libraries for the target
target_include_directories(xiate PRIVATE ${GLIB_INCLUDE_DIRS} ${GTK3_INCLUDE_DIRS} ${VTE_INCLUDE_DIRS})
target_link_libraries(xiate PRIVATE ${GLIB_LIBRARIES} ${GTK3_LIBRARIES} ${VTE_LIBRARIES})

# Set default install prefix (can be overridden by passing -DCMAKE_INSTALL_PREFIX=<path> to cmake)
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "..." FORCE)
endif()

# Install the program and man page
install(TARGETS xiate RUNTIME DESTINATION bin)
install(FILES "xiate.1" DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1")
install(FILES "config.example.ini" DESTINATION "${CMAKE_INSTALL_PREFIX}/share/xiate")

# Clean custom target
add_custom_target(clean-all COMMAND ${CMAKE_COMMAND} -P clean-all.cmake)

# Create clean-all.cmake script
file(WRITE clean-all.cmake "
file(GLOB_RECURSE TARGET_FILES
     \"*${CMAKE_PROJECT_NAME}*\"
     \"CMakeCache.txt\"
     \"CMakeFiles\"
     \"Makefile\"
     \"cmake_install.cmake\"
     \"*.cmake\")
foreach(FILE \${TARGET_FILES})
    if(IS_DIRECTORY \"\${FILE}\")
        file(REMOVE_RECURSE \"\${FILE}\")
    else()
        file(REMOVE \"\${FILE}\")
    endif()
endforeach()
")
