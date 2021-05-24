cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME Lab15) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(MapTreeIterLib MapTreeIterLib)
set(MapTreeLib MapTreeLib)
set(NodeTreeLib NodeTreeLib)
set(NodeLib NodeLib)
set(Main Main) 

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MapTreeIterLib
                    ${CMAKE_CURRENT_SOURCE_DIR}/MapTreeLib 
                    ${CMAKE_CURRENT_SOURCE_DIR}/NodeTreeLib
					${CMAKE_CURRENT_SOURCE_DIR}/NodeLib) 
#Добавляем директорию "${CMAKE_CURRENT_SOURCE_DIR}/vectorlib" в дополняемые каталоги включаемых файлов
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории

add_subdirectory(MapTreeIterLib)
add_subdirectory(MapTreeLib)
add_subdirectory(NodeTreeLib)
add_subdirectory(NodeLib)
add_subdirectory(Main)
add_subdirectory(gtest)
add_subdirectory(test)
