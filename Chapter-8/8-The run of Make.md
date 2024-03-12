# Make 的运行

命令行中执行 make 命令，然后 make 就会在当前目录下找 Makefile 文件执行。
如果只想让 make 重新编译某些文件，而不是整个工程，或者有几套编译文件，需要在不同的时刻去编译不同的文件，就需要了解 make 是如何执行的

## 8.1 Make 的退出码

make 命令有三个退出码

+ 0：退出成功
+ 1：make运行时出现任何错误，返回1
+ 2：make 使用了 -q 参数，并且 make 使得一些目标不需要更新，返回 2

## 8.2 指定 Makefile

GNU make 会去寻找默认的 Makefile 文件，“GUN-makefile”，“makefile”，“Makefile”，按其顺序寻找这三个文件，一旦找到就开始读取执行

如果想要执行指定名称的 Makefile 文件，就可以使用 -f 或者 --file 参数 --makefile 也可。

如想要执行一个叫 “hchen.mk”，在命令行输入如下命令
`make -f hchen.mk`

## 8.3 指定目标

1. make 设置的最终目标是 makefile 中的第一个目标，而其他目标是由这个目标连带出来的。
2. makefile 中的第一个目标可能会由很多目标组成，我们可以指示 make，让其完成所有指定的目标。达成这样的目的很简单，只需要在 make 命令后直接跟目标的名称。如 `make clean`
3. 任何在 makefile 中的目标都可以被指定成终极目标，除了以 `-` 或者 `=` 的目标，因为这些有这些字符的目标，会被解析成命令行参数或是变量。
4. 没有明确写出来的目标也可以成为 make 的终极目标，如 make 隐含规则推到推导出来的隐含目标

如：make 有一个环境变量叫 MAKECMDGOALS，这个变量中会存放所有指定的终极目标的列表，如果在命令行上没有指定目标，那么这个变量是空值，这个变量可以允许我们在一些比较特殊的情景做一些情况：

```
sources = foo.c bar.c
ifneq ($(MAKECMDGOALS),clean)
    include $(sources:.c=.d)
endif
```

上面的例子中，只要我们输入的命令不是 `make clean`，那么 Makefile 会自动包含 "foo.d", "bar.d" 这两个 makefile

使用终极目标的放可以可以很方便地让我们编译我们的程序，例如：
```
.PHONY: all
all: prog1 prog2 prog3 prog4
```

makefile 有四个需要编译程序。`make all` 命令来编译所有的目标（如果把 all 设置为第一个目标，那么只需要执行命令 `make` 即可）
如果想要执行单个目标文件，比如编译 prog3，可以执行 `make prog3`

make 可以指定所有 makefile 中的目标，那么也包括伪目标，我们可以根据这种性质来让我们的 makefile 根据不同的目标完成不同的事。
大型软件发布时，比如 GUN，其 makefile 包含了编译、安装、打包等功能，参照这种规则来书写我们的 makefile 中的目标
+ all：这个伪目标时所有目标的目标，其功能一般是编译所有的目标。
+ clean：这个伪目标是删除所有被 make 创建的文件
+ install：安装已编译好的程序，即把目标执行文件拷贝到指定目标中去
+ print：列出改编过的源文件
+ tar：将源程序打包，也就是一个 tar 文件
+ dist：创建一个压缩文件，一般是把 tar 文件压成 Z 或者是 gz 文件
+ TAGS：更新所有的目标，以备完整地重编译使用
+ check 和 test：两个伪目标一般用来测试 makefile 的流程

## 8.4 检查规则

有时我们只是想简单地检查我们的命令，或者执行序列，我们有以下的 make 命令参数可以使用

|参数|作用|
|--|--|
|-n,--just-print,--dry-run,recon|不执行参数，只打印命令。无论目标是否更新，把规则和连带规则的命名打印下来，对于调试 makefile 很有帮助 |
|-t,--touch|把目标文件时间更新，但是不更改目标文件。也就是说 make 假装编译目标，但是没有真正的编译目标，只是把目标变成已编译过的状态 |
|-q,--question|找目标的意思，如果目标存在，则什么也不输出，当然也不执行编译，如果目标不存在就会打印一条错误信息|
|-W <file>,--what-if=<file>,-assume-new=<file>,--new-file=<file>|该参数需要指定一个文件，一般是源文件或者依赖文件。Make 会根据规则推导来运行依赖于这个文件的命令，一般来可以和 -n 搭配使用，查看文件所发生的规则命令|

## 8.5 make 的参数

下面列举 GNU make 3.80 版本的参数定义。

|参数|作用|
| --- | --- |
| -b, -m | 忽略和其他版本 make 的兼容性 |
| -B, --always-make | 认为所有的目标都需要重新编译 |
| `-C <dir>, --directory=<dir>` | 指定读取 makefile 的目录。如果有多个“-C”参数，make 的解释是后面的路径以前面的作为相对路径，并以最后的目录作为被指定目录 |
| `-debug[=<options>]` | 输出 make 调试信息 |
| -d | = debug=a |
| `-e, --environment-override` | 指明环境变量的值覆盖 makefile 中定义的变量的值 |
| `-f=<file>,--file=<file>,--makefile=<file>` | 指定需要执行的 makefile |
| -h,--help | 显示帮助信息 |
| -i, --ignore-errors | 在执行时忽略所有错误 |
| `-I <dir>, --include-dir=<dir>` | 指定一个被包含 makefile 的搜索目录，可以使用多个 -I 参数来指定多个目录 |
| `-j [<options>], --jobs[=<jobnums>]` | 只同时运行命令的个数，默认 make 运行时能运行多少个就会运行多少个。 多个 -j 参数最后一个值有效 |
| -k, --keep-going | 出错也不停止运行，如果生成一个目标失败了，则依赖于其上的目标就不会被执行了 |
| `-l <load>, --load-average[=<load>],-max-load[=<load>]` | 指定 make 运行命令的负载 |
| -n, --just-print, --dry-run, --recon | 仅输出执行过程中的命令序列，但不执行 |
| `-i <file>, --old-file=<file>, --assume-old=<file>` | 不重新生成的指定的 <file>, 即使这个目标的依赖文件新于它 |
| -p, --print-data-base | 输出 makefile 中所有的数据，包括所有的规则和变量 |
| -q, --question | 不执行命令，也不输出。仅检查所指定的目标是否需要更新。如果是 0 则说明要更新，如果是 2 表示有错误发生 | 
| -r, --no-builtin-rules | 禁止 make 使用任何隐含规则 |
| -R, --no-builtin-variables | 禁止 make 使用任何作用于变量上的隐含规则 |
| -s, --slient, --quiet | 在命令执行时不输出命令的输出 |
| -S, --no-keep-going, -stop | 取消参数 "-k" 选项的作用 |
| -t, --touch | 将目标的修改日志变成最新，也就是阻止生成目标的命令运行 |
| -v, --version | 输出 make 程序的版本，版权等关于 make 的信息 |
| -w, --print-directory | 输出运行 makefile 之前和之后的信息，这个参数对于跟踪嵌套式调用 make 时会很有用 |
| --no-print-directory | 禁止 -w 选项 | 
| `-W <file>,--what-if=<file>,--new-file=<file>, --assume-file=<file>` | 假定目标 <file> 需要更新，如何和 “-n” 结合使用，那么这个参数会输出该目标更新时的运行动作，如果没有 “-n” 那么就像运行 UNIX 的 “touch” ，修改文件为当前动作 |
| -warn-undified-variables | 只要 make 发现有未定义的变量，那么就输出警告信息 |

1. `make -C ~hchen/test -C prog` 等价于 `make -C ~hchen/test/prog`
2. make 调试信息等级有以下几种取值
   1. a: all，输出所有调试信息
   2. b：basic，只输出简单的调试信息。即输出不需要重编译的目标
   3. v：verbose，b 级别之上的选项，输出的信息包括哪个 makefile 被解析， 不需要被重编译的依赖文件等
   4. i：impact，输出所有隐含规则
   5. j：jobs，输出执行规则中命令的详细信息，比如命令的 PID，返回码等
   6. m：makefile，输出 make 读取 makefile，更新 makefile，执行 makefile 的信息
3. 如果只是想输出信息而不执行命令，使用命令 `make -qp`
   1. 如果只是想查看执行 makefile 前的预设变量和规则，可以执行 `make -p -f /dev/null`
   2. 这个参数输出的信息包含 makefile 文件的文件名和行号，所以用这个参数调试 makefile 会很有用，特别是当环境变量特别复杂时
4. make 的选项是从环境变量 “MAKEFLAGS” 中继承下来的，所以需要在命令行中使用 “-S, --no-keep-going, -stop” 使环境变量中 -k 选项失效