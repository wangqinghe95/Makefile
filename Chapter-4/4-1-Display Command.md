# 显示命令

## Makefile 打印
通常，make 会将其执行的命令行再命令执行前输出到屏幕上
如果不想显示该行命令，可以在命令前加上 @ 符号

比如：[echo_Makefile](/Code/Chapter-4-1/Makefile)
`echo "Compling..."`

会输出
```
echo "Compling..."
Compling...
```

而 `@echo "Compling..."` 只会输出 `Compling...`

## make 打印参数

如果 make 执行时带上参数 -n 或者 --just-print，那么就会只显示命令，而不会执行命令。
这个功能有利于我们调试我们的 Makefile，查看书写的命令执行起来是什么样子或者什么顺序

而 make 带参数 -s 或者 --slient 或者 --quiet 则是全面禁止命令的显示