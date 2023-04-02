file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_executable(femtic ${srcs})

find_package(OpenMP REQUIRED)
find_package(MPI REQUIRED)
find_package(MKL REQUIRED)


target_include_directories(femtic PUBLIC include)

target_link_libraries(femtic PUBLIC )
target_link_libraries(femtic PUBLIC femtic_lib)
target_link_libraries(femtic PUBLIC MKL::MKL)
target_link_libraries(femtic PUBLIC MPI::MPI_CXX)
target_link_libraries(femtic PUBLIC OpenMP::OpenMP_CXX)
