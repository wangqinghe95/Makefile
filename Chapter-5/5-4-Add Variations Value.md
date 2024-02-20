# 追加变量值

可以使用 += 来给变量追加值，如
```
objects = main.o foo.o bar.o utils.o
obejcts += another.o
```

objects 的值就变成了 "main.o foo.o bar.o utils.o another.o"

上述例子等同于
```
objects = main.o foo.o bar.o utils.o
obejcts := $(objects) another.o
```

1. 如果变量之前没有定义过，那么 += 就会变成 =
2. 如果变量之前已经定义过了，那么 += 就会继承前次操作的复制符
   1. 如果前一次的是  :=，那么 += 就会以 := 作为其赋值符

如
```
variable := value
variable += more
```

等价于：
```
variable := value
vairable := $(variable) more
```

但是如果 := 换成 =，make 会解决变量的递归定义。