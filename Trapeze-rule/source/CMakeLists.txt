cmake_minimum_required(VERSION 3.5)
project (nome_do_projeto VERSION 1.0.0 LANGUAGES CXX )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )

# Include dir
include_directories( "src" "lib" )

#=== Test target ===

add_executable(main "src/main.cpp")

target_compile_features( main PUBLIC cxx_std_11 )
