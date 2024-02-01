# Makefile 中的变量

在 [示例中的 Makefile](./2-2-An%20Example.md) 中，可以看到直接手动的指明依赖文件和对应的目标文件名的。
这种方法在 Makefile 需要扩展的情况下，如新增一些必要的源文件，就会显得很麻烦，而且一旦工程中依赖的文件很多的话，那么 Makefile 语句就会显得很臃肿。

为了将 Makefile 写的更有效率，我们可以使用 Makefile 的变量方式让书写更简单

比如我们声明一个变量叫 objects, OBEJCTS, objs, OBJ 等等，来表示 obj 文件，修改后的 Makefile 文件如下：

```
objects = common.o main.o utils.o
edit : $(objects)
	cc -o edit $(objects)

main.o : main.c
	cc -c main.c

common.o : common.c common.h
	cc -c common.c 

utils.o : utils.c utils.h
	cc -c utils.c

clean : 
	rm edit common.o main.o utils.o
```