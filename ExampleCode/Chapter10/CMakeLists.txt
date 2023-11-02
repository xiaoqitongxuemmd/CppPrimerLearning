# 查找当前目录下所有的头文件
# 并将名称保存到 DIR_LIB_HEADS 变量
file(GLOB DIR_LIB_HEADS "*.h")

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library (Chapter10 ${DIR_LIB_HEADS} ${DIR_LIB_SRCS})