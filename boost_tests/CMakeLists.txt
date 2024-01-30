set( BOOST_ROOT "/opt/homebrew/Cellar/boost/1.84.0/")
set( Boost_NO_SYSTEM_PATHS on CACHE BOOL "Do not search system for Boost" )
set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Boost_Tests_run test1.cpp)

target_link_libraries(Boost_Tests_run ${Boost_LIBRARIES} adt)