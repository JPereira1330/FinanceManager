cmake_minimum_required(VERSION 3.25.1)

project(FinanceManager.out VERSION 1.0 LANGUAGES CXX)

# Encontre e configure o Boost
find_package(Boost REQUIRED COMPONENTS program_options)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "inc/*.hpp")

# Adicione seu executável e vincule a biblioteca Boost Program Options
add_executable(financeManager.out ${SOURCES} ${HEADERS})

target_link_libraries(financeManager.out Boost::program_options)
target_include_directories(financeManager.out PRIVATE inc)