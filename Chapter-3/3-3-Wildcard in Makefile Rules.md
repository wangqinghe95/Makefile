# Makefile 中的通配符

make 支持三个通配符 *, ? , ~

~ 在文件名中也有特殊用处，表示当前用户的 $HOME 目录

通配符可以代替一系列用文件，用法等同于 Unix 下的用法

如 *.c 表示所有后缀为 .c 的文件。需要注意的是，如果要使用 * 本义，需要使用转移字符 \*

举个例子：
```
clean
    rm -rf *.o
```
删除所有后缀为 .o 的文件


通用符可以用在变量中
```
objects = *.o
```

但是，上述的 objects 不会展开，它的值就是 *.o

如果想要展开 objects 变量，可以使用以下方法
```
objects := $(wildcard *.o)
```

以下是一些常用的关于通配符的例子
1. 列出文件夹下所有 .c 文件
`objects := $(wildcard *.o)`
2. 列出 1）中所有文件对应的 .o 文件
`$patsubst %.c, %.o, $(wildcard *.c)`
3. 由 1）2）两步，编译并链接所有的 .c 和 .o 文件
```
objects := $(patsubst %.c, %.o, $(wildcard *.c))
foo: $(objects)
    cc -o foo $(objects)
```
