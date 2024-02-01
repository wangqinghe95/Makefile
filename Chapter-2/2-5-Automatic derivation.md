# 自动推导

GUN 的 make 能够自动推导文件以及文件依赖关系后面的命令。

make 检查到一个 .o 文件后，会自动地把 .c 文件加载到依赖关系中
比如 make 找到一个 whatever.o 文件，那么 whatever.c 就会是 whatever.o 的依赖文件，那么命令 cc -c whatever.c 的就会被推导出来

那么，Makefile 文件就能被我们修改为以下格式

```
edit : common.o main.o utils.o
	cc -o edit main.o common.o utils.o

main.o : main.c

common.o : common.c common.h

utils.o : utils.c utils.h

clean : 
	rm edit common.o main.o utils.o
```

这种方法是 make 的隐式规则。

需要注意的是，自动推导的依赖文件需要在当前目录下，而且推导的生成命令。不涉及依赖文件的来源。
这点会在多文件夹中的多个源文件中需要注意。