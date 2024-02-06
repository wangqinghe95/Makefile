# 定义命令包

如果 Makefile 中出现一些相同命令序列，可以为这些相同的命令序列定义一个变量，定义这种命令序列的语法以 define 开始，以 endef 结束，如

```
define run-yacc
yacc $(firstword $^)
my y.tab.c $@
endef
```

1. define 后跟命令包名，即 “run-yacc”，名称不能与 Makefile 中变量名重复。
2. define 和 endef 中间的内容是命令集
   1. 第一个行命令是运行 yacc 命令
   2. 第二行命令修改文件 “y.tab.c” 文件名为 $@，即目标文件. 因为 yacc 程序会生成 “y.tab.c” 文件

使用的话是直接 $(package_command) 即可，和使用变量类似

make 在执行命令包时，命令包中的每个命令都会依次独立执行。