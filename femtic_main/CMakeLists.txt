# 
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_executable(femtic ${srcs})

# project(femtic LANGUAGES CXX)
# set(CMAKE_CXX_COMPILER mpiicpc)

target_include_directories(femtic PUBLIC include)
target_link_libraries(femtic PUBLIC )
target_link_libraries(femtic PUBLIC femtic_lib)
target_link_libraries(femtic PUBLIC MKL::MKL)
target_link_libraries(femtic PUBLIC MPI::MPI_CXX)
target_link_libraries(femtic PUBLIC OpenMP::OpenMP_CXX)
# target_link_libraries(femtic PUBLIC ${MKL_LIBRARIES})

