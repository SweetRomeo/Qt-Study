cmake_minimum_required(VERSION 3.16)

project(qt6-app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt6 path'ini manuel belirtme (gerekirse)
set(Qt6_DIR "C:/Qt/6.x.x/msvc2019_64/lib/cmake/Qt6")  # Windows için
# veya
# set(Qt6_DIR "/home/user/Qt/6.x.x/gcc_64/lib/cmake/Qt6")  # Linux için

find_package(Qt6 REQUIRED COMPONENTS Core)

# Kaynak dosyaları
set(SOURCES
    main.cpp
    numberutil.cpp
    stringutil.cpp
    source.cpp
    destination.cpp
    station.cpp
    radio.cpp
)

# Header dosyaları
set(HEADERS
    numberutil.h
    stringutil.h
    source.h
    destination.h
    station.h
    radio.h
)

add_executable(qt6-app ${SOURCES} ${HEADERS})

target_link_libraries(qt6-app Qt6::Core)

# MOC için
set_target_properties(qt6-app PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
)
