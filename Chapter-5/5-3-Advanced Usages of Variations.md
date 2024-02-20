# 变量的高级用法

介绍两种变量的高级用法

## 变量值的替换

### 方法一
将变量中的共有部分替换
1. 格式
   1. $(var:a=b) 或是 $(var:a=b)
2. 意思
   1. 将变量"var"中所有以 "a" 字符串结尾的的 "a" 替换成 "b" 字符串
   2. 结尾的意思是 "空格" 或者 "结束符"
3. 示例
```
foo := a.o b.o c.o
bar := $(foo:.o=.c)
```
+ 那么 bar 的值就是 "a.c b.c c.c"

### 方法二
另一种替换技术是以静态模式定义的，如
```
foo := a.o b.o c.o
bar := $(foo:%.o=%.c)
```

这依赖于被替换字符串中有相同的模式，模式中必须包含一个 % 字符，这个例子同样让 $(bar) 变量的值为 "a.c b.c c.c"

## 把变量的值再当做变量

### 例1

```
x = y
y = z
a := $($(x))
```

1. $(x) 的值为 "y", 即 $($(x)) = $(y)
2. $(a) = "z"

### 例2

```
x = y
y = z
z = u
a := $($($(x)))
```

### 复杂一点的例子

```
x = $(y)
y = z
z = Hello
a := $($(x))
```
1. 这里的 $($(x)) 会被替换成 $($(y))，因为 $(y) 的值就是 "z", 所以最终 a = $(z), 也就是 hello

### 更复杂的例子

```
x = variable1
variable2 := hello
y = $(subset 1,2,$(x))
z = y
a := $($($(z)))
```

1. $($($(z))) 会被拓展为 $($(y)), 紧接着继续被拓展为 $($(subset 1,2,$(x)))
2. $(x) 的值为 variable1，subset 会将该值中的字符串 1 替换成字符串 2，即 variable1 被替换成 variable2，再取其值
3. 最终 $(a) 的值就是 $(variable2)，即 Hello

在这种方式中，可以使用多个变量组成一个变量的名字，然后再取其值
```
first_second = Hello
a = first
b = second
all = $($a_$b)
```
1. all 的值就是 first_second，而 $(all) 的值就是 "Hello"

## 两种技术结合例子

```
a_objects := a.o b.o c.o
1_objects := 1.o 2.o 3.o

sources := $($(a1)_objects:.o=.c)
```
1. 如果 $(a1) 的值是 "a" 的话，那么 $(sources) 的值就是 "a.c b.c c.c"
2. 如果 $(a1) 的值是 "1" 的话，那么 $(sources) 的值就是 "1.c 2.c 3.c"

### 同函数于条件语句一同使用的例子
```
ifdef do_sort
    func := sort
else
    func := strip
endif

bar := a d b g q c
foo := $($(func) $(bar))
```

1. 如果定义了 "do_sort" ，那么 foo := $(sort a d b g q c)
2. 如果没有定义了 "do_sort" ，那么 foo := $(strip a d b g q c)

### 应用于操作符左边

```
dir = foo
$(dir)_sources := $(wildcard $(dir)/*.c)
define $(dir)_print
lpr $($(dir)_sources)
endef
```

该例中定义了三个变量:
1. dir
2. foo_sources
3. foo_print