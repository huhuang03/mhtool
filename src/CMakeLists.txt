FILE(GLOB_RECURSE SRC_LIB *.cpp *.h *.hpp *.c *.cc ${CMAKE_CURRENT_SOURCE_DIR}/../include/*.h ${CMAKE_CURRENT_SOURCE_DIR}/../include/*.hpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(FILTER SRC_LIB EXCLUDE REGEX ".*main.cc$")
list(FILTER SRC_LIB EXCLUDE REGEX ".*pch.cc$")


# why you not complain?
# Still I can't find the tesseract name.
find_package(Tesseract REQUIRED)

add_library(mh-tool-lib ${SRC_LIB})

target_precompile_headers(mh-tool-lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include/pch.h)

# public and interface will not work
target_include_directories(mh-tool-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Boost REQUIRED COMPONENTS system filesystem)
target_link_libraries(mh-tool-lib
        ${OpenCV_LIBS} easybot Qt5::Widgets Boost::filesystem
        libtesseract)


add_executable(mh-tool ${SRC_LIB} main.cc)
target_link_libraries(mh-tool mh-tool-lib)

SET_TARGET_PROPERTIES(mh-tool PROPERTIES LINK_FLAGS  "/MANIFESTUAC:\"level='requireAdministrator'\"")
