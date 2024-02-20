# 变量中的变量

在定义变量的值时，可以使用其他变量来构造变量的值，在 Makefile 中有两种方法来用变量定义变量的值

## 等于号

= 号的左边时变量名，右边是变量值。右侧变量的值可以定义在文件的任何一侧，也就是说，右侧的变量不一定非要是已经定义好的值，也可以是使用后面定义的值，比如

```
foo = $(bar)
bar = $(ugh)
ugh = Huh?

all:
    echo $(foo)
```

运行结果如下：
```
echo Huh?
Huh?
```

由例子可知，变量是可以使用后面的变量来定义的。
好处是，可以把让变量的真实值推导后面定义，如
```
CFLAGS = $(include_dirs) -o
include_dirs = -Ifoo -Ibar
```

坏处是，递归定义会让 make 陷入无限变量展开过程中去
```
A = $(B)
b = $(A)
```
当然 make 由能力检测到这种定义并报错

如果变量中使用函数，会让 make 运行的非常慢
并且，make 函数 wildcard 和 shell 发生不可预知的错误。因为无法确定这两个函数会被调用多少次。

为例避免以上问题，使用 := 来定义变量
```
x := foo
y := $(x) bar
x := later
```

等价于
```
y := foo bar
x := later
```

这种方法只能使用后面的变量，不能使用前面已经定义好的变量
```
y := $(x) bar
x := foo
```
即， y 的值是 bar，而不是 “foo bar”

## 一个复杂的例子

一个复杂的例子，包含了 make 函数，条件表达式，和一个系统变量 "MAKELEVEL" 的使用

```
ifeq (0, ${MAKELEVEL})
cur-dir	:= $(shell pwd)
whoami	:= $(shell whoami)
host-type	:= $(shell arch)
MAKE	:= ${MAKE} host-type=${host-type} whoami=${whoami}
endif
```

1. MAKELEVEL 当我们的 make 有一个嵌套执行的动作时，这个变量会记录 Makefile 的调用层数

## 定义空格

如果我们需要定义空格的变量，可以使用以下方式
```
nullstring := 
space := $(nullstring) # end if the line
```

1. nullstring 是一个空变量，什么都没有
2. space 值是一个空格，因为操作符的右边很难描述一个空格，使用一个空变量来表明变量的开始，而后面使用 '#' 注释来表示变量定义的终止，这样我们可以定出一个空格的变量

## 注释符（#）的使用

`dir := /foo/bar	# directory to put the frobs in`

1. dir 这个变量的值就是 "/foo/bar"，后面跟 4 个空格，如果我们使用该变量来指定别的目录，"$(dir)/file" 就会出现大问题

## 操作符 ?=

`FOO ?= bar`

1. 含义是如果 FOO 没有被定义过，那么变量的值就是 "bar", 如果 FOO 先前被定义过了，那么这条语句就什么也不做

等同于 
```
ifeq ($(origin FOO), undefined)
	FOO = bar
endif
```