cmake_minimum_required(VERSION 3.6)
project(Link)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cc src/link/menu.h src/link/menu.cc src/link/io.cc src/link/io.h src/link/date.cc src/link/date.h src/link/list.h)

add_executable(Link ${SOURCE_FILES})

find_program(CMAKE_PYTHON_EXECUTABLE NAMES python DOC "The Python executable")
find_file(GOOGLE_CPP_LINT_PY NAMES cpplint.py DOC "google cpp style scan program.")
if (NOT GOOGLE_CPP_LINT_PY)
    message ("cpplint.py not found")
endif()

add_custom_target(google_style_scan
        COMMAND ${CMAKE_PYTHON_EXECUTABLE} ${GOOGLE_CPP_LINT_PY} --output=vs7 --filter=-build/header_guard,-build/include ${SOURCE_FILES}
        DEPENDS ${GOOGLE_CPP_LINT_PY} ${SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Google CPP Code Style scan."
        SOURCES ${SOURCE_FILES}
        )
