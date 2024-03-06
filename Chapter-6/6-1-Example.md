# 示例

1. 判断 $(CC) 变量是否是 gcc，如果是的话，则使用 GNU 函数编译目标

```
libs_for_gcc = -lgnu
normal_libs=

foo: $(objects)

ifeq ($(CC), gcc)
    $(CC) -o foo $(objects) $(libs_for_gcc)
else
    $(CC) -o foo $(objects) $(normal_libs)
```

条件判断的三个关键字，ifeq,else,endif
1. ifeq 表示条件语句的开始，并指定一个条件表达式
   1. 表达式包含两个参数，以逗号隔开，表达式以圆括号括起。
2. else 表示条件表达式为假时的情况
3. endif 表示一个条件语句的结束，任何一个条件表达式都应该以 endif 结束

2. 上述例子中更简洁的写法
```
libs_for_gcc = -lgnu
normal_libs=

ifeq ($(CC), gcc)
    libs = $(libs_for_gcc)
else
    libs = $(normal_libs)

foo: $(objects)
    $(CC) -o foo $(objects) $(libs)

```