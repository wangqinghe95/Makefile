# Makefile 另一种风格

在 Makefile 中，可以收拢重复的头文件

比如以下的 Makefile

```
objects = main.o kbd.o command.o display.o \
            insert.o search.o files.o utils.o
edit : $(objects)
    cc -o edit $(objects)

$(objects) : defs.h
kbd.o command.o files.o : command.h
display.o insert.o search.o files.o : buffer.h
.PHONY : clean
clean :
    rm edit $(objects)
```

Make 就能推导出，$(objects) 中所有的文件都依赖 defs.h 文件

kbd.o, command.o, files.o 这三个文件还依赖 command.h 头文件

则 display.o, insert.o, search.o, files.o 还依赖 buffer.h 头文件

虽然这种方法显得 makefile 很简短，但是不推荐该种方法，因为文件依赖关系就不太直观，而且如果需要添加新文件，那么就很麻烦。