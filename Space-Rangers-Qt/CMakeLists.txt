cmake_minimum_required(VERSION 3.5)

project(Space-Rangers-Qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    t_main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Space-Rangers-Qt MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        t_common_entities.h                                             t_common_entities.cpp

        extra/t_value_stepper.h                                         extra/t_value_stepper.cpp

        t_game_loop.h                                                   t_game_loop.cpp
        t_game_components.h                                             t_game_components.cpp
        t_game_systems.h                                                t_game_systems.cpp

        t_sprite_render_system.h                                        t_sprite_render_system.cpp
        t_game_render_system.h                                          t_game_render_system.cpp

        t_minimap_component.h                                           t_minimap_component.cpp

        interfaces/i_game_system.h                                      interfaces/i_game_system.cpp

        linear_algebra/run_test_store_exception.h

        linear_algebra/t_2d_common_entities.h                                    linear_algebra/t_2d_common_entities.cpp
        linear_algebra/t_2d_container_entity.h                          linear_algebra/t_2d_container_entity.cpp

        linear_algebra/t_2d_position_systems.h                          linear_algebra/t_2d_position_systems.cpp

        linear_algebra/t_2d_vector_systems.h                            linear_algebra/t_2d_vector_systems.cpp

        planetsystems/t_component_planetsystem.h                        planetsystems/t_component_planetsystem.cpp

        planets/t_component_planet.h                                    planets/t_component_planet.cpp
        planets/t_system_make_planets.h                                 planets/t_system_make_planets.cpp
        planets/t_system_planet_circle_moving.h                         planets/t_system_planet_circle_moving.cpp

        spaceships/t_spaceship_trajectory_moving_system.h               spaceships/t_spaceship_trajectory_moving_system.cpp
        spaceships/t_spaceship_following_another_system.h               spaceships/t_spaceship_following_another_system.cpp
        spaceships/t_component_spaceship.h                              spaceships/t_component_spaceship.cpp
        spaceships/t_spaceship_systems.h                                spaceships/t_spaceship_systems.cpp
        spaceships/t_spaceship_landing_planet_system.h                  spaceships/t_spaceship_landing_planet_system.cpp

        spaceships/equipments/weapons/t_component_rocket.h              spaceships/equipments/weapons/t_component_rocket.cpp
        spaceships/equipments/weapons/t_system_rocket_launcher.h        spaceships/equipments/weapons/t_system_rocket_launcher.cpp
        spaceships/equipments/weapons/t_component_rocket_weapon.h       spaceships/equipments/weapons/t_component_rocket_weapon.cpp
    )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Space-Rangers-Qt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Space-Rangers-Qt SHARED ${PROJECT_SOURCES})
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Space-Rangers-Qt ${PROJECT_SOURCES})
    endif()
endif()

target_link_libraries(Space-Rangers-Qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Space-Rangers-Qt)
endif()
set_target_properties(Space-Rangers-Qt PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Space-Rangers-Qt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Space-Rangers-Qt)
endif()
