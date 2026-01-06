include(GenerateExportHeader)

add_library(ecs SHARED
    "internal/component_manager.cpp"
    "internal/entity_manager.cpp"
    "internal/system_manager.cpp")

add_library(lib::ecs ALIAS ecs)

target_include_directories(ecs
    PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(ecs
    PUBLIC project_headers
)

generate_export_header(ecs
    BASE_NAME        ECS
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/ecs/export.h
)

add_executable(ecs_tests
    tests/core_suitetests.cpp)

target_link_libraries(ecs_tests
    PRIVATE
        lib::ecs
        GTest::gtest
        GTest::gtest_main
)