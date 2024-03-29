# 变量的基础

1. 变量在声明时需要给予初始值
2. 在使用时需要在变量前加 $ 符号，但最好有小括号或者大括号将使用的变量包括起来
3. 如果要使用真实的 $ 符号，需要用 $$ 表示

变量可以使用在规则中的目标，依赖，命令中，甚至还可以使用在新的变量中，因为它是展开生效的

## 依赖中使用
```
objects = program.o foo.o utils.o
program : $(objects)
    cc -o program

$(objects) : defs.h
```

变量会在使用它的地方精确的展开，就像 C/C++ 宏一样
```
foo = c
prog.o : prog.$(foo)
    $(foo)$(foo) -$(foo) prog.$(foo)

prog.o : prog.c
    cc -c prog.c
```

以上只是举个例子证明变量如何生效，不建议在 Makefile 中如此编写代码。
给变量加括号完全是为了更加安全地使用这个变量，虽然可以不加括号也可以，但是就后续维护和阅读来说，加括号更容易理解