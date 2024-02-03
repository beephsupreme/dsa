set(EXECUTABLE_NAME app)
set(EXE_SOURCES "main.cpp")
set(EXE_INCLUDES "./")

add_executable(app ${EXE_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${EXE_INCLUDES})

target_link_libraries(
        ${EXECUTABLE_NAME}
        PUBLIC
        adt
        nesteruk
        nlohmann_json::nlohmann_json
        fmt::fmt
        spdlog::spdlog
        cxxopts::cxxopts)

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${EXECUTABLE_NAME}
            ${ENABLE_WARNINGS}
            ${ENABLE_WARNINGS_AS_ERRORS})
endif()
