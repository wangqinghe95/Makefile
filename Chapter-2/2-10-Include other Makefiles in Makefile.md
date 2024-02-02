# 包含其他 Makefile

在 Makefile 使用 include 指令可以将把别的 Makefile 包含进来，类似于 C 语言的 #include，被包含的文件会原模原样的放在当前文件的包含位置

include 语法如下
`include <filename>`

<filename> 可以是当前操作系统 Shell 的文件模式，包含路径和通配符

在 include 前面可以有一些空字符，但是不能是 Tab 键开始

include 和 <filename> 可以用一个或多个空格隔开。

假如，项目中有以下几个 Makefile： a.mk, b.mk, c.mk, foo.make, 以及一个变量 $(bar)，包含了 bish 和 bash

那么以下的语句
`include foo.make *mk $(bar)`

等价于
`include foo.make a.mk b.mk c.mk bish bash`

make 命令开始的时候，会先找到 include 指向的其他 Makefile 文件， 并把其内容安置在当前位置，就好像 C/C++ 的 include 指令一样

如果文件都没有指定绝对路径和相对路径的话，make 就会在当前目录下寻找，如果当前目录下没有找到的话，它会去以下几个目录寻找
1. 如果 make 执行时，有 -I 或者 --include-dir 参数的话，那么就去在这个参数所指定的目录下去寻找
2. 接下来按照顺序去找目录 <prefix>/include（一般是指 /usr/local/bin）、/usr/gnu/include、/usr/local/include、 /usr/include

环境变量 .INCLUDE_DIRS 包含当前 make 会寻找的目录列表，如果使用 -I 参数的话，尽量不要指定以上这些默认目录，否则 make 会遗忘掉已经设好的包含目录，包括默认目录

如果有文件没有找到的话，make 会生成一个警告信息，但是不会出现致命错误。然后会继续载入其他文件，一旦完成 makefile 的读取，make 会再尝试哪些没有找到或者不能读取的文件按，如果还是不行，make 才会报一条致命错误

如果你不想 make 去理会哪些无法读取的文件，可以再 include 前加一个 - 号

`- include <filenames>`

表示无论 include 过程中出现什么错误，都不要报错继续执行，如果要和其他版本 make 兼容，可以使用 sinclude 代替 -include