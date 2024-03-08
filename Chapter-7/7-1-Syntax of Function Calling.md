# 函数调用

函数调用，类似于变量的使用，以 $ 标识

语法为
`$(<function> <arguments>)`

或者
`${<function> <arguments>}`

1. <function> 是函数名，<arguments> 是函数参数，参数是以逗号分开，函数名和参数之间以空格隔开
2. 函数调用以 $ 开头，以圆括号或者花括号把函数名和参数括起来。
3. 函数和变量的括号最好保持一致，都是用圆括号或者都使用中括号

## Example

```
comma:= ,
empty:=

space:= $(empty) $(empty)
foo:= a b c
bar:= $(subset $(space),$(comma),$(foo))
```

1. $(comma) 是一个逗号
2. $(space) 定义了一个空格
3. $(foo) 是字符串 " a b c"
4. subst 是一个替换函数，有三个参数
   1. 被替换参数
   2. 替换字串
   3. 替换操作作用的字串
5. 最后一行的代码意思是，将 $(foo) 中的空格替换成逗号，所以 $(bar) 的值是 a,b,a