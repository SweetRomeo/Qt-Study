cmake_minimum_required(VERSION 3.16)

project(qt6-app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt6'nın Core ve Test modüllerini bul
find_package(Qt6 REQUIRED COMPONENTS Core Test)

# Otomatik Qt işlemleri (MOC, UIC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# --- 1. Ana Uygulama (Main App) ---

# Sadece uygulamanın çalışması için gereken dosyalar
set(APP_SOURCES
    main.cpp
    numberutil.cpp
    stringutil.cpp
    source.cpp
    destination.cpp
    station.cpp
    radio.cpp
)

set(APP_HEADERS
    numberutil.h
    stringutil.h
    source.h
    destination.h
    station.h
    radio.h
)

add_executable(MyMainApp ${APP_SOURCES} ${APP_HEADERS})

# Ana uygulamayı Qt Core'a bağla
target_link_libraries(MyMainApp PRIVATE Qt6::Core)


# --- 2. Test Uygulaması (Unit Tests) ---

# Test için test dosyası VE test edilen sınıfın kaynak kodları (stringutil.cpp) gerekir
# main.cpp'yi BURAYA DAHİL ETMİYORUZ.
add_executable(MyTests
    teststringutil.cpp
    teststringutil.h
    stringutil.cpp       # Test edilen fonksiyonun implementasyonu burada olduğu için şart
    stringutil.h
)

# Test uygulamasını Qt Test ve Core'a bağla
target_link_libraries(MyTests PRIVATE Qt6::Core Qt6::Test)

# İsteğe bağlı: IDE üzerinden (örneğin CLion) testleri 'Run' butonuyla çalıştırmak için
enable_testing()
add_test(NAME RunAllTests COMMAND MyTests)
