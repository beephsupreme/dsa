set(LIBRARY_NAME adt)
set(LIBRARY_SOURCES "adt.cc")
set(LIBRARY_HEADERS "adt.h")
set(LIBRARY_INCLUDES
        "./"
        "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(${LIBRARY_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADER})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})
