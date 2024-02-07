set(EXECUTABLE_NAME neural-net)

set(EXE_SOURCES
        neural-net.cpp
)

set(BOOST_REQUIRED_COMPONENTS
        filesystem)

set(BOOST_MIN_VERSION 1.84.0)

set(EXE_INCLUDES "./")

find_package(
        Boost ${BOOST_MIN_VERSION}
        REQUIRED COMPONENTS ${BOOST_REQUIRED_COMPONENTS})

set(TARGET_LIBRARIES
        Boost::filesystem)

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${EXE_INCLUDES})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${TARGET_LIBRARIES})

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${EXECUTABLE_NAME}
            ${ENABLE_WARNINGS}
            ${ENABLE_WARNINGS_AS_ERRORS})
endif()
