# 模式变量

在 GUN 的 make 中，还支持模式变量（Pattern-specific Variable）。
模式变量就是给定一种“模式”，可以把变量定义在符合这种模式的所有目标上。

make 的模式一般都含有一个 '%'，所以可以以如下方式给所有以 .o 结尾的目标定义目标变量

`%.o : CFLAGS = -O`

模式变量的语法如下：
```
<pattern ...>; : <variable-assignment>
<pattern ...>; : override <variable-assignment>
```

1. override 同样是针对系统环境传入的变量，或是 make 命令行指定的变量