# Makefile 的文件名

默认情况下，make 命令会在当前目录下按顺序寻找文件名为 GUNmakefile，makefile 和 Makefile 的文件

当然也可以使用其他文件名来，格式为 "Makefile.<suffix>", 如文件 Makefile.Linux

如果想要指定的 Makefile 编译，那么可以使用参数 -f 或者 --file

比如
`make -f Makefile.Linux`

如果使用多条 -f 或者 --file, 可以指定多个 makefile