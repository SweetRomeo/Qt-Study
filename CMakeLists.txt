cmake_minimum_required(VERSION 3.16)

project(qt6-app LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(qt6-app
  main.cpp
  Notes
  numberutil.h numberutil.cpp
)
target_link_libraries(qt6-app Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(qt6-app PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS qt6-app
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
