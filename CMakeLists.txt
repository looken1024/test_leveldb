cmake_minimum_required(VERSION 3.10)
project(test_leveldb)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)

find_library(
    LEVELDB_LIBRARY 
    NAMES leveldb
    HINTS 
        ./third_party/leveldb/lib       # 指定 LevelDB 库文件所在目录
)

# 添加头文件路径
include_directories(./third_party/leveldb/include)

# 添加可执行文件
add_executable(test_leveldb
    src/main.cc
)

# 链接 LevelDB 库和其他依赖
target_link_libraries(test_leveldb
    ${LEVELDB_LIBRARY}
    pthread  # LevelDB 需要 pthread
)
