cmake_minimum_required(VERSION 3.20)

project (MilkyKeyboard)

enable_language(C)
enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (LIBRARY_PATH ${PROJECT_SOURCE_DIR}/Library)
set (SRC_PREFIX ${PROJECT_SOURCE_DIR}/Source)
set (ICONS_PREFIX ${PROJECT_SOURCE_DIR}/icons)
set (IMAGES_PREFIX ${PROJECT_SOURCE_DIR}/images)

# 分别获取源码文件和图片文件
file(GLOB_RECURSE SRC_LIST ${SRC_PREFIX}/*.cpp ${SRC_PREFIX}/*.c ${SRC_PREFIX}/*.h)
file(GLOB_RECURSE ICONS_LIST ${ICONS_PREFIX}/*)
file(GLOB_RECURSE IMAGE_LIST ${IMAGES_PREFIX}/*.c)

# 合并文件列表
set(ALL_SOURCES ${SRC_LIST} ${ICONS_LIST} ${IMAGE_LIST})

if (CMAKE_SYSTEM_NAME STREQUAL Windows)
    # 分别设置源码分组
    source_group (TREE "${SRC_PREFIX}" PREFIX "Source" FILES ${SRC_LIST})
    source_group (TREE "${ICONS_PREFIX}" PREFIX "icons" FILES ${ICONS_LIST})
    source_group (TREE "${IMAGES_PREFIX}" PREFIX "images" FILES ${IMAGE_LIST})
endif ()

add_executable (${PROJECT_NAME} ${ALL_SOURCES})

list(APPEND INCLUDE_PATH ${SRC_PREFIX} ${ICONS_PREFIX} ${IMAGES_PREFIX})
if (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    list (APPEND INCLUDE_PATH   ${LIBRARY_PATH}/lvgl/9.4.0/msvc2022_64/include/)
    list (APPEND LINK_PATH      ${LIBRARY_PATH}/lvgl/9.4.0/msvc2022_64/lib/)
    list (APPEND LIBRARYS		LvglWindows)
	# 添加系统多媒体库（mciSendString 所需），32/64 位通用
	list (APPEND LIBRARYS       winmm)
elseif (CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")

endif()

target_include_directories (${PROJECT_NAME} PUBLIC ${INCLUDE_PATH})
target_link_directories (${PROJECT_NAME} PUBLIC ${LINK_PATH})
target_link_libraries (${PROJECT_NAME} PUBLIC ${LIBRARYS})
