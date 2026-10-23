cmake_minimum_required(VERSION 3.15)

project(MatrixBattle VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# WIN32 表示生成窗口程序，等价于 g++ 的 -mwindows
add_executable(MatrixBattle WIN32
    src/main.cpp
    src/Matrix.cpp
)

target_include_directories(MatrixBattle PRIVATE src)

# 输出文件名保持中文，和原版一致
set_target_properties(MatrixBattle PROPERTIES OUTPUT_NAME "矩阵对战")

if(MINGW)
    # 源码为 GBK 编码，告诉 GCC 输入与执行字符集都是 GBK，
    # 这样 TextOutA / MessageBoxA 等 ANSI 接口能正确显示中文
    target_compile_options(MatrixBattle PRIVATE -finput-charset=GBK -fexec-charset=GBK)
endif()

if(MSVC)
    # 源码以 GBK 保存，显式指定源字符集与执行字符集，保证 ANSI 接口显示中文
    target_compile_options(MatrixBattle PRIVATE /W4 /source-charset:.936 /execution-charset:.936)
    target_compile_definitions(MatrixBattle PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

# 运行需要 rules.txt 与程序同目录，构建完成后自动复制
add_custom_command(TARGET MatrixBattle POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_CURRENT_SOURCE_DIR}/rules.txt"
            "$<TARGET_FILE_DIR:MatrixBattle>/rules.txt"
    COMMENT "复制 rules.txt 到可执行文件目录"
)
