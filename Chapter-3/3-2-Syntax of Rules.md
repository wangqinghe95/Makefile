# 规则的语法

```
targets: prerequisites
    command
    ...

targets: prerequisites; command
    command
    ...
```

target 是文件名，以空格分开，可以使用通配符。一般来说目标基本上是一个文件，但也可能是多个文件

command 是命令行，如果不与 “targets: prerequisites” 在一行，那么必须以 tab 键开头，反之，可以用分号作为分隔

prerequisites 也是目标所依赖的文件（或是目标文件），如果其中某个文件要比文件目标新，那么目标就会被认定为“过时的”，是需要重新生成的。

如果命令太长，可以使用反斜杠作为换行符。

make 对于一行没有多少个字符的限制，规则告诉 make 两件事，文件的依赖关系和如何生成目标文件。

一般来说， make 会以 Unix 的标准 shell，也就是 /bin/bash 来执行命令

