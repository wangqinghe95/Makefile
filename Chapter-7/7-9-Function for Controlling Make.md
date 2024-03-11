# 控制 make 的函数

make 提供一些函数来控制 make 的运行。通常 Make 在执行 Makefile 文件时，会检测一些运行的信息，并根据这些信息来决定 Make 是否需要继续执行下去

## 语法

`$(error <text...>)`

1. 如果有一个致命错误产生，那么错误的信息将会在 <text...> 中
2. error 不会在刚被使用的时间产生错误信息，如果把其定义在某个变量中，那么后续的脚本中使用这个变量也是可以的

## 示例

```
ifdef ERROR_001
    $(error error is $(ERROR_001))
endif
```

```
ERR = $(error found an error!)
.PHONY: err
err: $(ERR)
```

1. 示例一会在变量 ERROR_01 定义了以后执行时产生 error 调用，而示例二则会在目录 err 被执行时才会发生 error 调用

`$(warning <text...>)`

这个函数和 error 类似，但是不会让 make 退出，只会输出一段警告信息，然后 make 继续执行