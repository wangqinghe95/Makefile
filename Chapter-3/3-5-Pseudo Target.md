# 伪目标

## 伪目标定义
伪目标不是一个文件，只是一个标签，所以 make 不需要，也无法生成它的依赖关系，也无需执行。只有显示地指明这个“目标”才会执行下面的命令。

当然，这个伪目标不能与文件名重名，否则就是去了“伪目标”的意义。

## 伪目标格式
为了避免和文件重名的情况，make 提供了一个特殊的标记，“.PHONY” 来显示指明这个是伪目标，无论是否有这个文件，这个目标都是一个“伪目标”。

`.PHONY: clean`

只有声明了 .PHONY ，那么不管是否有 "clean" 这个文件，要运行 "clean" 这个目标，就需要执行 `make clean` 命令，否则无法触发。

## 伪目标依赖

伪目标一般没有依赖文件，但是可以指定伪目标的依赖文件，目的是可以生成多个目标文件。
如下：
```
all: prog1 grg2 prog3
.PHONY: all
prog1: prog1.o utils.o
    cc -o prog1 prog1.o utils.o

prog2: prog2.o
    cc -o prog2 prog2.o

prog3: prog3.o  sort.o utils.o
    cc -o prog3 prog3.o utils.o sort.o 
```

Makefile 中的第一个目标会被认为是默认目标，即 all 是本文件最终的生成文件
但是 all 被声明为伪目标，即只是一个标签，不会生成文件，所以就不会有 all 文件产生

于是其他三个目标的规则总会被决议，也就是达到了生成多个目标的目的。

## 伪目标作为依赖
同时，目标也可以成为依赖，伪目标也可以是依赖
```
.PHONY: cleanall cleanobj cleandiff

cleanall: cleanobj cleandiff
    rm program

cleanobj:
    rm *o

cleandiff:
    rm *.diff
```

"make cleanll" 将清除所有要被清除的文件。
"cleanobj" 和 "cleanobj" 这两个命令作为清除命令的子命令。
通过伪目标的依赖，可以达到清楚不同种类文件的目的。
