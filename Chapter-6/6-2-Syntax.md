# 语法

## 条件表达式的语法

```
<conditional-directive>
<text-if-true>
endif
```

或者
```
<conditional-directive>
<text-if-true>
else
<text-if-false>
endif
```

1. <conditional-directive> 表示条件关键字，如 ifef.

## 条件关键字
### ifeq

```
ifeq (<arg1>,<arg2>)
ifeq '<arg1>' '<arg2>'
ifeq "<arg1>" "<arg2>"
ifeq '<arg2>' "<arg2>"
ifeq "<arg2>" '<arg2>'
```

如，比较 arg1 和 arg2 的值是否相同

```
ifeq ($(strip $(foo)) ,)
<text-if-empty>
endif
```

### ifdef

`ifdef <variation-name>`

1. 如果 <variation-name> 值非空，则表达式为真，否则表达式为假。
2. <variation-name> 可以是一个函数的返回值
3. ifdef 只是测试一个变量是否有值，而不会将变量的值扩展到当前位置

#### 示例一

```
bar =
foo = $(bar)
ifdef foo
    frobozz = yes
else
    frobozz = no
endif
```

+ 示例二

```
foo =
ifdef foo
    frobozz = yes
else
    frobozz = no
endif
```

#### 示例一中 frpbozz = yes，示例二中 frpbozz = no

### ifndef

作用于 ifdef 相反，且用法一致

### <variation-name>

1. 在 <variation-name> 中，多余的空格是被允许的，但是不能使用 tab 键开头
2. 注释符号(#) 是安全的，else 和 endif 同样如此
3. make 在读取 Makefile 时就计算条件表达式的值，并根据条件表达式的值来选择语句，所以谨慎将自动化变量（如 @$）放入到条件表达式中，因为他们在运行时才有
4. 未来避免混乱，make 不允许把整个条件语句分成两部分放在不同的文件中