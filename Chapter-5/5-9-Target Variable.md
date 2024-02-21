# 目标变量

Makefile 中定义的变量都是全局变量，在整个文件中我们都可以访问这些变量。
自动化变量，如 $<, 属于规则型变量，这种变量的值依赖于规则的目标和依赖目标的定义。

也可以为某个目标设置局部变量，这种变量被称为“Target-specific Variable”，它可以和“全局变量”重名，因为它的作用范围只在这条规则以及连带规则中，所以其值也只在作用范围内有效，不会影响规则链外的全局变量的值

## 语法
```
<target ...> : <variable-assignment>;
<target ...> : override <variable-assignment>;
```

1. <target ...> : override <variable-assignment>; 针对的是命令行带入的变量，或是系统环境变量


这个变量会作用到由这个目标所引发的所有的规则中去，如
```
prog: CFLAGS = -g
prog: prog.o foo.o bar.o
    $(CC) $(CFLAGS) prog.o foo.o bar.o

prog.o : prog.c
    $(CC) $(CFLAGS) prog.c

foo.o : foo.c
    $(CC) $(CFLAGS) foo.c

bar.o : bar.c
    $(CC) $(CFLAGS) bar.c
```

在这个例子中，无论全局的  $(CFLAGS) 是什么，在 prog 的目标中，以及其所引发的所有规则中（prog.o foo.o bar.o 的规则），$(CFLAGS) 的值都是 -g