set(CMAKE_INCLUDE_CURRENT_DIR ON)

cm_add_executable(shooter
    main.cpp assets.qrc
    shooterwindow.cpp
)

add_subdirectory(kernel)
add_subdirectory(scene)
add_subdirectory(item)

target_link_libraries(shooter PRIVATE Qt::Widgets Qt::Multimedia GameIO::gameio)
