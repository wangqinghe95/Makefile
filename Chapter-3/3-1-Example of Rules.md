# 规则举例

```
foo.o : foo.c defs.h
    cc -c -g foo.c
```

以上就是一个 makefile 的规则，foo.o 是生成目标，fooc.c 和 defs.h 是依赖项，执行命令时 cc -c -g foo.c

1. 文件依赖关系 foo.o 依赖 foo.c defs.h，如果后两者文件任一文件日期要比前者文件日期新，或者前者文件不存在，那么依赖关系发生
2. 生成或者更新了目标文件，也就是成功执行了 cc 命令，它指明了如何生成 foo.o 文件