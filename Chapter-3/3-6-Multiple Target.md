# 多目标

Makefile 支持在同一文件中生成多目标，因为其生成的命令大体类似，所以可以将其合并起来。

需要用到自动变量 $@ 来完成多目标的任务

```
bigoutput littleoutput: text.g
    generate text.g -$(subst output,,$@) > $@
```

上述命令等价于
```
bigoutput:text.g
    generate text.g -big > bigoutput
littleoutput:text.g
    generate text.g -little > littleoutput
```

其中， -$(subst output,,$@) 的 $ 表示执行一个 Makefile 函数，函数名叫 subst，后面的输入作为参数，subst 是字符串替换的意思。

$@ 是目标的集合，像一个数组，$@ 依次取出目标，并执行命令。