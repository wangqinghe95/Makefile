# 一个示例

## 文件列表
有如下源文件：

```
.
├── common.cpp
├── common.h
├── main
├── main.cpp
├── utils.cpp
└── utils.h

0 directories, 6 files
```

[源文件链接](/Code/Chapter-2-2/main.c)

## Makefile

1. Makefile 书写
如果我们想要使用 Makefile 脚本来完成编译命令，那么 Makefile 文件如下
```
edit : common.o main.o utils.o
	cc -o edit main.o common.o utils.o

main.o : main.c
	cc -c main.c

common.o : common.c common.h
	cc -c common.c 

utils.o : utils.c utils.h
	cc -c utils.c

clean : 
	rm edit common.o main.o utils.o
```

2. Make 编译命令
Makefile 和源文件在同一目录下后，那么就可以直接执行 `make` 进行编译，而使用 `make clean` 清除文件

3. Makefile 内容介绍

+ 目标文件包括：可执行文件（edit）、中间目标文件（*.o）
+ 依赖文件：所有冒号后的 .c 文件和 .h 文件
+ reciple：需要以一个 tab 键作为开头。

make 会比较 target 和 prerequisites 文件的修改日期，如果后者的文件日期要比前者的文件日期要新的话，或者 target 不存在的话，那么 make 就会执行后续定义的命令

+ clean：不是一个文件，是一个命令名称。make 不会去找它的依赖项，也不会自动执行其后所定义的命令。要想执行其他的命令，需要在 make 命令后显示的写出命令名称，即 `make clean`

这个方法允许使用者在一个 makefile 中定义不用的编译或者与编译无关的命令，比如程序的打包，备份等