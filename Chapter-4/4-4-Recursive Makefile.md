# 嵌套执行 make

在一个大的工程里，我们会把不同模块或者不同功能的源文件放在不同的目录中，我们可以将每个目录中都书写一个该目录的 Makefile，这样就有利于我们的 Makefile 变得更加简洁，而不至于将所有的东西都写在一个 Makefile 中，后续很难维护。这个技术对于模块编译和分段编译也有非常大的好处。

## 进入子目录 make 写法
假如有一个子目录 subdir，这个目录下有个 Makefile 文件，来指明这个目录下文件的编译规则，那么我们根目录的 Makefile 可以这么写：
```
subsytem:
    cd subdir && $(MAKE)
```

等价于
```
subsystem:
    $(MAKE) -C subdir
```

定义 $(MAKE) 宏定义的意思是，make 需要一些参数，那么定义为一个变量比较利于维护。

这两个例子的意思都是先进入 subdir 目录，然后执行 make

根 Makefile 可以将本文件中的变量传递给下级的 Makefile 中，而且不会覆盖下层的 Makefile 文件中所定义的变量，除非指定了 -e 参数

## 嵌套 make 的变量传递
如果想要将变量传递给下级 Makefile，可以使用如下声明：
`export <variable ...>`
如果不想将某些变量传递给下级的 Makefile 中，可以这样声明
`unexport <variable ...>`

如：
1. 例1：
`export variable = value`

等价于
```
variable = value
exprot variable
```

等价于
`export variable := value`

等价于
```
variable := value
exprot variable
```

2. 例2
`export variable += value`

等价于
```
variable += value
exprot variable
```

如果要传递所有变量，那么只需要一个 export 即可，后续什么也不用跟，就表示传递所有变量。

## make 嵌套执行的默认参数 SHELL 和 MAKEFILES
变量 SHELL 和 MAKEFILES 默认都是会传递到下层的 Makefile 中的，特别是 MAKEFILES 中包含了 make 的参数信息。

如果是上层的 Makefile 中定义了这个变量，那么 MAKEFILES 变量将会是这些参数，并且会传递到下层的 Makefile 中去，这是一个系统级的环境变量。

## 默认不会传递的参数
但是 make 命令中有几个参数是不会往下传递的，他们是 -C，-f，-h，-o 和 -W，如果不想往下层传递参数，可以这些设置
```
subsystem:
    cd subdir $$ $(MAKE) MAKEFILES=
```

如果定义了环境变量 MAKEFILES，那么得确定其中的选项下层 Makefile 能使用到，如果其中有 -t， -n，-q 参数，那么可能会有一些使用者不想接受的后果。

## 一些有用的参数
还有一个在“嵌套执行”中比较有用的参数，-w 或者是 --print-directory 会在 make 得过程中输出一些目前工作目录的信息。

假如：下级 make 目录是 "/home/hchen/gnu/make"，使用 make -w 来执行，那么进入该目录时，会看到
`make: Entering directory '/home/hchen/gnu/make'`

而在完成 make 任务后，离开当前目录，则可以看到
`make: Leaving directory '/home/hchen/gnu/make'`

可以使用 -C 参数来指定 make 下层 Makefiles 时，-w 会被自动打开，如果参数中有 -s，或者 --no-print-directory,那么 -w 总是失效的