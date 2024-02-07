set(LIBRARY_NAME nesteruk)
set(LIBRARY_SOURCES
        HtmlElement.cpp
        HtmlBuilder.cpp
        Person.cpp
        PersonBuilder.cpp
        PersonAddressBuilder.h
        PersonJobBuilder.h
        Point.cpp
        HotDrink.h
        HotDrinkFactory.h
        DrinkFactory.h
        CoffeeFactory.h
        TeaFactory.h)

set(LIBRARY_HEADERS
        HtmlElement.h
        HtmlBuilder.h
        Person.h
        PersonBuilder.h
        Point.h)

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
