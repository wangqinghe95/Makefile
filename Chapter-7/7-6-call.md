# call 函数

call 函数是唯一一个可以用来创建新的参数化的函数。
可以写一个非常复杂的表达式，在这个表达式中，可以定义很多参数，然后使用 call 函数向这个表达式传递参数

## 语法
`$(call <expression>,<parm1>,<parm2>,...,<parm>)`

当 make 执行这个函数时，<expression> 参数中的变量，如 $(1),$(2) 等， 会被参数  <parm1>,<parm2>,<parm3> 依次取代。而 <expression> 返回值就是 call 函数的返回值，如

```
reverse = $(1) $(2)
foo = $(call reverse,a,b)
```

foo 的值就是 a,b。参数的次序可以自定义，
```
reverse = $(2) $(1)
foo = $(call reverse,a,b)
```
foo 的值就是 b a

## 注意
在向 call 函数传递参数时需要注意空格的使用。
call 函数在处理参数时，第二个及其之后的参数中的空格会被保留，因此会造成一些奇怪的效果。因而在向 call 函数提供参数时，最安全的做法就是去除掉多余的空格。