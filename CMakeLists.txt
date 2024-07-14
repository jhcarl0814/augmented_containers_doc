# Preamble
cmake_minimum_required(VERSION 3.28)
list(APPEND CMAKE_MESSAGE_CONTEXT "augmented_containers_doc")
set(CMAKE_CXX_SCAN_FOR_MODULES OFF) # https://discourse.cmake.org/t/cmake-3-28-cmake-cxx-compiler-clang-scan-deps-notfound-not-found/9244
project(augmented_containers_doc
    VERSION "0.0.0"
    DESCRIPTION "augmented_containers's documentation"
    LANGUAGES CXX
)
set(CMAKE_EXECUTABLE_SUFFIX ".html") # https://stackoverflow.com/questions/75594285/emscripten-in-cmake-doesnt-output-html-file-when-i-setcmake-executable-suffix

# Project wide setup
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Dependencies
include(FetchContent)
FetchContent_Declare(Boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG ad09f667e61e18f5c31590941e748ac38e5a81bf # boost-1.84.0
    GIT_SHALLOW TRUE
    EXCLUDE_FROM_ALL
    #SYSTEM
    FIND_PACKAGE_ARGS 1.84.0
)
FetchContent_Declare(augmented_containers
    GIT_REPOSITORY https://github.com/jhcarl0814/augmented_containers.git
    GIT_TAG main
    EXCLUDE_FROM_ALL
)
FetchContent_Declare(ext
    GIT_REPOSITORY https://github.com/jhcarl0814/ext.git
    GIT_TAG main
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(Boost augmented_containers ext)

# Targets
add_custom_target(augmented_containers_doc_administrative_files)
target_sources(augmented_containers_doc_administrative_files PRIVATE "./README.md" "./LICENSE")
set_source_files_properties("./README.md" "./LICENSE" PROPERTIES HEADER_FILE_ONLY YES)
add_custom_target(augmented_containers_doc_tooling_support)
target_sources(augmented_containers_doc_tooling_support PRIVATE "./.clang-format")
set_source_files_properties("./.clang-format" PROPERTIES HEADER_FILE_ONLY YES)

set(compile_options
    "$<$<CONFIG:Debug>:-O0>"
    "$<$<NOT:$<CONFIG:Debug>>:-O3>"
    "-sDISABLE_EXCEPTION_CATCHING=0"
    #"-sUSE_BOOST_HEADERS"

    "-Wall"
    "-Wextra"
    "-pedantic"
    "-Werror"
)
set(link_options
    "$<$<CONFIG:Debug>:-O0>"
    "$<$<NOT:$<CONFIG:Debug>>:-O3>"
    "-sDISABLE_EXCEPTION_CATCHING=0"
    #"-sUSE_BOOST_HEADERS"

    "$<$<CONFIG:Debug>:-sEXCEPTION_DEBUG>"
    "$<$<CONFIG:Debug>:-sDEMANGLE_SUPPORT>"
    "$<$<CONFIG:Debug>:-sEXCEPTION_STACK_TRACES>"
    "$<$<CONFIG:Debug>:-sSTACK_OVERFLOW_CHECK=2>"
    "$<$<CONFIG:Debug>:-sASSERTIONS=0>"
    "$<$<NOT:$<CONFIG:Debug>>:-sASSERTIONS=2>"

    "-sEXIT_RUNTIME=0"
    "-sALLOW_MEMORY_GROWTH"
    "-sINITIAL_MEMORY=64MB"
    "-sSTACK_SIZE=1MB"
    "-sSINGLE_FILE"
    "-sMINIFY_HTML=0"
)

add_library(augmented_containers_doc_augmented_deque_headers INTERFACE)
target_sources(augmented_containers_doc_augmented_deque_headers
    PUBLIC
        FILE_SET headers
            TYPE HEADERS
            BASE_DIRS "./include"
            FILES
                "./include/augmented_containers_doc/augmented_deque_visualization.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/empty.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/accumulator_only_yield_one_value_string.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/projector_and_accumulator_yield_one_value_int.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/projector_and_accumulator_yield_one_value_string.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/projector_and_accumulator_yield_multiple_values.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/projector_and_accumulator_yield_one_view.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/projector_and_accumulator_yield_multiple_views.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/find_by_monotonic_predicate.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/find_by_heap_predicate.hpp"
                "./include/augmented_containers_doc/augmented_deque_examples/find_by_heap_predicate_generator.hpp"
)
add_executable(augmented_containers_doc_augmented_deque)
target_link_libraries(augmented_containers_doc_augmented_deque PRIVATE augmented_containers_doc_augmented_deque_headers)
set_target_properties(augmented_containers_doc_augmented_deque PROPERTIES
    OUTPUT_NAME "augmented_deque"
)
target_sources(augmented_containers_doc_augmented_deque PRIVATE "./src/augmented_containers_doc/augmented_deque_template.cpp")
target_link_libraries(augmented_containers_doc_augmented_deque PRIVATE augmented_containers::headers ext::headers embind)
target_compile_options(augmented_containers_doc_augmented_deque PRIVATE ${compile_options})
target_link_options(augmented_containers_doc_augmented_deque PRIVATE
    "--shell-file" "${CMAKE_CURRENT_SOURCE_DIR}/augmented_deque_template.html"
    ${link_options}
)

add_library(augmented_containers_doc_augmented_sequence_headers INTERFACE)
target_sources(augmented_containers_doc_augmented_sequence_headers
    PUBLIC
        FILE_SET headers
            TYPE HEADERS
            BASE_DIRS "./include"
            FILES
                "./include/augmented_containers_doc/augmented_rb2p_visualization.hpp"
                "./include/augmented_containers_doc/augmented_rb3p_visualization.hpp"
                "./include/augmented_containers_doc/augmented_sequence_examples/empty.hpp"
                "./include/augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp"
                "./include/augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp"
                "./include/augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp"
                "./include/augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp"
                "./include/augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp"
                "./include/augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp"
                "./include/augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp"
)
add_executable(augmented_containers_doc_augmented_sequence)
target_link_libraries(augmented_containers_doc_augmented_sequence PRIVATE augmented_containers_doc_augmented_sequence_headers)
set_target_properties(augmented_containers_doc_augmented_sequence PROPERTIES
    OUTPUT_NAME "augmented_sequence"
)
target_sources(augmented_containers_doc_augmented_sequence PRIVATE "./src/augmented_containers_doc/augmented_sequence_template.cpp")
target_link_libraries(augmented_containers_doc_augmented_sequence PRIVATE augmented_containers::headers ext::headers embind)
target_compile_options(augmented_containers_doc_augmented_sequence PRIVATE ${compile_options})
target_link_options(augmented_containers_doc_augmented_sequence PRIVATE
    "--shell-file" "${CMAKE_CURRENT_SOURCE_DIR}/augmented_sequence_template.html"
    ${link_options}
)

add_library(augmented_containers_doc_augmented_graph_headers INTERFACE)
target_sources(augmented_containers_doc_augmented_graph_headers
    PUBLIC
        FILE_SET headers
            TYPE HEADERS
            BASE_DIRS "./include"
            FILES
                "./include/augmented_containers_doc/augmented_graph_visualization.hpp"
                "./include/augmented_containers_doc/augmented_graph_examples/empty.hpp"
                "./include/augmented_containers_doc/augmented_graph_examples/arbitrary_spanning_forest.hpp"
                "./include/augmented_containers_doc/augmented_graph_examples/minimum_spanning_forest.hpp"
                "./include/augmented_containers_doc/augmented_graph_examples/minimum_spanning_forests.hpp"
                "./include/augmented_containers_doc/augmented_graph_examples/tree_nearest_marked_vertexes.hpp"
                "./include/augmented_containers_doc/augmented_graph_examples/tree_diameter_and_centers.hpp"
                "./include/augmented_containers_doc/augmented_graph_examples/tree_medians.hpp"
                "./include/augmented_containers_doc/augmented_graph_examples/tree_jump_and_meet.hpp"
)
add_executable(augmented_containers_doc_augmented_graph)
target_link_libraries(augmented_containers_doc_augmented_graph PRIVATE augmented_containers_doc_augmented_graph_headers)
set_target_properties(augmented_containers_doc_augmented_graph PROPERTIES
    OUTPUT_NAME "augmented_graph"
)
target_sources(augmented_containers_doc_augmented_graph PRIVATE "./src/augmented_containers_doc/augmented_graph_template.cpp")
target_link_libraries(augmented_containers_doc_augmented_graph PRIVATE augmented_containers::headers ext::headers embind)
target_compile_options(augmented_containers_doc_augmented_graph PRIVATE ${compile_options})
target_link_options(augmented_containers_doc_augmented_graph PRIVATE
    "--shell-file" "${CMAKE_CURRENT_SOURCE_DIR}/augmented_graph_template.html"
    ${link_options}
)

add_custom_target(augmented_containers_doc_augmented_deque_copy
    ALL
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:augmented_containers_doc_augmented_deque>" "${PROJECT_SOURCE_DIR}/docs/augmented_deque.html"
)
add_custom_target(augmented_containers_doc_augmented_sequence_copy
    ALL
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:augmented_containers_doc_augmented_sequence>" "${PROJECT_SOURCE_DIR}/docs/augmented_sequence.html"
)
add_custom_target(augmented_containers_doc_augmented_graph_copy
    ALL
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:augmented_containers_doc_augmented_graph>" "${PROJECT_SOURCE_DIR}/docs/augmented_graph.html"
)
