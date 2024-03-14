# Set the minimum required version of cmake for a project.
cmake_minimum_required(VERSION 3.10)

# Define the project name and specify the languages used.
project(st VERSION 1.0 LANGUAGES C)

# Set the C standard and flags.
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
find_package(X11 REQUIRED)

pkg_check_modules(FREETYPE REQUIRED freetype2)
pkg_check_modules(XFT REQUIRED xft)
pkg_check_modules(FONTCONFIG REQUIRED fontconfig)

# Include the user-defined config file if it exists, otherwise use defaults.
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/config.h")
    configure_file(config.def.h config.h COPYONLY)
endif()

# Add compiler flags from config.mk if needed (not directly translatable).
# For example:
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I. -Wall -Wextra -pedantic -Os")

# Define sources and objects.
set(SRC st.c x.c)
# set(OBJ ${SRC:.c=.o})

# Add executable target.
add_executable(st ${SRC})

target_include_directories(st PRIVATE ${FREETYPE_INCLUDE_DIRS} ${X11_INCLUDE_DIR} ${XFT_INCLUDE_DIRS} ${FONTCONFIG_INCLUDE_DIRS})

target_link_libraries(st PRIVATE ${X11_LIBRARIES} ${XFT_LIBRARIES} ${FONTCONFIG_LIBRARIES} m util)

# Link against libraries specified in STLDFLAGS from config.mk (not directly translatable).
# For example, you may need to link against X11 or fontconfig, etc.
# target_link_libraries(st ...)

# Build options.
# target_compile_options(st PRIVATE ...)

# Clean target is not needed with CMake.

# Install targets.
install(TARGETS st RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

# Install man page after replacing version placeholder.
add_custom_command(
    OUTPUT st.1
    COMMAND sed "s/VERSION/${PROJECT_VERSION}/g" < "${CMAKE_CURRENT_SOURCE_DIR}/st.1" > "${CMAKE_CURRENT_BINARY_DIR}/st.1"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/st.1"
)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/st.1" DESTINATION "${CMAKE_INSTALL_MANDIR}/man1")

# Additional install commands from the Makefile.
install(CODE "execute_process(COMMAND tic -sx ${CMAKE_CURRENT_SOURCE_DIR}/st.info)")

# Uninstall command isn't native to CMake, would need to be added manually if required.

# Add dist custom target equivalent.
add_custom_target(dist
    COMMAND ${CMAKE_COMMAND} -E tar "czf" "${CMAKE_BINARY_DIR}/st-${PROJECT_VERSION}.tar.gz" --format=gnutar -- ${SRC} st.h arg.h win.h config.def.h st.1 st.info README FAQ LEGACY TODO LICENSE Makefile config.mk
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Provide messages or instructions post-install.
install(CODE "message(STATUS \"Please see the README file regarding the terminfo entry of st.\")")

# Specify that certain targets are not files.
set_property(DIRECTORY PROPERTY ADDITIONAL_MAKE_CLEAN_FILES st-${PROJECT_VERSION}.tar.gz)
