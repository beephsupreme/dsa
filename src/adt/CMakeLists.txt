set(LIBRARY_NAME adt)
set(LIBRARY_SOURCES "adt.cpp")
set(LIBRARY_HEADERS "adt.h")
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(${LIBRARY_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADER})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${LIBRARY_NAME}
            ${ENABLE_WARNINGS}
            ${ENABLE_WARNINGS_AS_ERRORS})
endif ()
