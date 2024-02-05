# 静态模式

静态模式可以更加容易地定义多目标的规则，使 Makefile 规则更加的有弹性和灵活性。

静态模式语法如下：
```
<targets ...> : <target-pattern> : <prereq-patterns ...>
    <command>
    ...
```

1. targets 定义了一系列的目标文件，可以有通配符，是一个目标的集合
2. target-patterns 指明了 targets 的模式，也就是目标集模式
   + 如果<target-pattern> 定义为 %.o ， <targets> 都是以 .o 结尾的 
3. prereq-patterns 使目标的依赖模式，它对 target-patterns 形成的模式再进行一次依赖目标的定义
   + 如果 <prereq-patterns> 定义为 %.c，意思是对 <target-pattern> 所形成的目标集进行二次定义，计算方式为区 <target-pattern> 中的 % ,再加上 .c 这个结尾，形成新的集合

目标模式或者依赖模式，都应该有 % 这个字符，如果文件名中有 % 这个字符，那么就需要使用转移表示原意。

## 示例

```
objects = foo.o bar.o
all : $(objects)

$(objects): %.o : %.c
    $(CC) -c $(CFLAGS) $< -o $@
```

例子中：指定从 $(obejcts) 中获取目标，
+ %.o ：要所有以 .o 为结尾的目标，也就是 foo.o, bar.o, 也就是变量 $obejct 集合的模式
+ %.c ：则取 %.o 中 %，也就是 foo, bar, 并未其加下 .c d的后缀，于是，依赖目标就是  foo.c, bar.c 
+ $< ：自动化变量，表示第一个依赖文件
+ $@ ：是自动化变量，表示目标集（foo.o bar.o）

以上的规则展开后等价于以下的规则
```
foo.o : foo.c
    $(CC) -c $(CFLAGS) foo.c -o foo.o
bar.o : bar.c
    $(CC) -c $(CFLAGS) bar.c -o bar.o
```

这种规则有利于生成的静态文件很多的工程编译。

以下是另一例子
```
files = foo.elc bar.o lose.o

$(filter %.o, $(files)): %.o : %c
    $(CC) -c $(CFLAGS) $< -o $@
$(filter %.elc,$(files)): %.elc : %el
    emacs -f batch-byte-compile $<
```

$(filter %.o, $(files)) 表示调用 Makefile 中的 filter 函数，过滤 "$files" 集，只要其中模式为 "%.o" 的内容
