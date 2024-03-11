# origin 函数

origin 函数不会操作变量的值，他指出这个变量来自于哪里

## 语法

`$(origin <variable>)`

1. <variable> 是变量的名称，不应该是引用，最好不要在  <variable> 中使用 $ 字符。
   1. origin 函数会以返回值来表明这个变量的“出生情况”
2. origin 返回值有以下几种情况：
   1. undefined：该变量变量从来未被定义过
   2. default：该变量是一个默认的定义，比如 “CC”
   3. environment：该变量是环境变量，并且当 Makefile 被执行时，-e 参数没有被打开
   4. file：该变量被定义在 Makefile 中
   5. command line：在命令行中定义的
   6. override：该变量被 override 指示符重新定义
   7. automatic，该变量是一个命令运行中的自动化变量

## 示例

1. 假如我们有一个 Makefile 其包了一个定义文件 Make.def
2. 在 Make.def 中定义了一个变量 “bletch”
3. 而我们的环境中也有一个环境变量 “bletch”
4. 如果这个时候我们想要判断一下，如果变量来源于环境，那么我们把它重定义了，如果来源于 Make.def 文件，或是命令行等非环境，那么我们就不重新定义它

```
ifdef bletch
    ifeq "$(origin bletch)" "environment"
        bletch = barf, gag, etc.
    endif
endif
```

## 注意
override 也能够重新定义环境变量中的变量，但是它也会把从命令行定义的变量覆盖了，而我们只想重新定义环境传来的，而不想重新定义命令行传来的