set(EXECUTABLE_NAME algorithms)
set(EXE_SOURCES adt_driver.cpp)

set(EXE_INCLUDES "./")
set(TARGET_LIBRARIES
        adt
        nlohmann_json::nlohmann_json
        fmt::fmt
        spdlog::spdlog
        cxxopts::cxxopts)

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${EXE_INCLUDES})
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${TARGET_LIBRARIES})

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${EXECUTABLE_NAME}
            ${ENABLE_WARNINGS}
            ${ENABLE_WARNINGS_AS_ERRORS})
endif()
