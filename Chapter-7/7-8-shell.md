# shell 函数

shell 函数是用来执行操作系统 shell 命令的，它与反引号有相同的功能
也就是说，shell 函数把执行操作系统后的输出作为函数的返回

我们可以用操作系统命令以及字符串处理命令 awk，sed 等命令来生成一个变量

```
contents := $(shell cat foo)
files := $(shell echo *.c)
```

这个函数会生成一个 Shell 程序来执行命令，所以需要注意运行性能。

如果 Makefile 中有一些比较复杂的规则，并大量使用了这个函数，那么对系统性能是有害的
特别是 Makefile 隐式规则可能会让 shell 函数执行的次数比设计的要多