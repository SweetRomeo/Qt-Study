cmake_minimum_required(VERSION 3.16)

project(qt6-app LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# ÖNCE executable'ı oluştur
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(qt6-app
  main.cpp
  numberutil.h numberutil.cpp
  stringutil.h stringutil.cpp
  source.h source.cpp
  destination.h destination.cpp
)

# SONRA diğer kaynakları ekle (gerekirse)
target_sources(qt6-app
  PRIVATE
    # Buraya ek kaynaklar ekleyebilirsiniz
)

# Sadece bir kez target_link_libraries kullanın
target_link_libraries(qt6-app Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS qt6-app
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
