
cmake_minimum_required(VERSION 3.10)
project(hako
    VERSION 0.0.1
    DESCRIPTION "???"
    HOMEPAGE_URL "https://github.com/Kuuhaku31/KH_EX_Hako"
    LANGUAGES CXX)

# 项目信息↑

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 设置build文件夹路径

# 设置生成的可执行文件的输出路径为bin目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 添加源文件
# 查找并包含src目录下的全部源文件
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# 打印找到的源文件列表
message(STATUS "Source files: ${SRC_FILES}")

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC_FILES})

# 添加头文件
include_directories(./include)

# 添加第三方库路径
include_directories(./third_party)

# 添加第三方库
link_directories(./third_party)

set(EASYX_PATH "${CMAKE_SOURCE_DIR}/third_party/libeasyx.a")

# 添加链接库
target_link_libraries(${PROJECT_NAME} ${EASYX_PATH})

# # 链接到 EasyX 图形库
# include_directories(./easyx)
# link_directories(./easyx)
# link_libraries(./EasyX/libeasyx.a)

# # 如果库文件名和路径正确，尝试直接指定库文件的完整路径
# target_link_libraries(run "${CMAKE_SOURCE_DIR}/easyx/libeasyx.a")
