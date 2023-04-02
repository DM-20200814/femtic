file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp src/*.h)
add_library(femtic_lib STATIC ${srcs})
target_include_directories(femtic_lib PUBLIC include)
