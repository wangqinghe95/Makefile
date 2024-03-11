# foreach 函数

该函数是循环关键字，等同于其他语言的中的 for 关键字

## 语法
`$(foreach <var>,<list>,<text>)`

1. 把参数 <list> 中的单词逐一取出放到参数 <var> 所指定的变量中，然后执行 <text> 所包含的表达式。
2. 每一次的 <text> 会返回一个字符串，循环过程中，<text> 所返回的每个字符串以空格分隔，当整个循环结束时，<text> 所返回的每个字符串所组成的整个字符串（以空格分隔）将会是 foreach 函数的返回值
3. 所以 <var> 最好是一个变量名，<list> 可以是一个表达式，而 <text> 一般会使用 <var> 这个参数来依次枚举 <list> 中的单词

## 举例
```
names := a b c d
files := $(foreach n,$(names),$(n).o)
```

1. $(name) 中的单词会被挨个取出，并存到变量 n 中，$(n).o 每次根据 $(n) 计算出一个值，这些值以空格分开，最后作为 foreach 函数的返回，所以 $(files) 的值是 a.o b.o c.o d.o
2. foreach 中的 <var> 参数是一个临时的局部变量，foreach 函数执行完成后，参数 <var> 的变量将不再作用，其作用域只在 foreach 函数当中