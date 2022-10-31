@[TOC](文章目录)



----



# 1. Linux编译器-gcc/g++使用  



## C 语言

在 *Linux* 下，一般使用 *gcc* 编译 *C* 语言代码。*gcc* 可以通过包管理工具进行安装，以 *Centos* 为例：

```shell
$ sudo yum install gcc
```

接下来，我们编译一个非常简单的 *C* 语言程序 [hello_world.c](http://github.com/fasionchan/learn-linux/tree/master/src/development-environment/c-cpp/c/hello_world.c) 。代码如下：

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301948795.png" alt="image-20221030133218837" style="zoom:50%;" />



你可以使用任何编辑工具来编写代码，*nano* 、 *vim* ，甚至记事本均可(这里我使用vim)。



代码编辑完毕后，运行 *gcc* 命令进行编译：

```shell
$ gcc test.c -o mybin
```

其中， *-o* 选项指定可执行程序名， *hello_world.c* 是源码文件。不出意外，当前目录下将出现一个可执行文件：

```shell
$ mybin
```

最后，还是在命令行下，将程序运行起来。看，程序输出预期内容：

```shell
$ ./mybin
```



![image-20221030133733296](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301337383.png)



---



## C++ 语言

*C++* 语言编译与 *C* 语言类似，只不过编译工具不再是 *gcc* ，而是 *g++* 。同样地， *g++* 也可以通过包管理工具来安装：

```shell
$ sudo yum install gcc-c++
```

还是编译一个简单的程序 [hello_world.cpp](http://github.com/fasionchan/learn-linux/tree/master/src/development-environment/c-cpp/cpp/hello_world.cpp) ，代码如下：

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301341377.png" alt="image-20221030134133220" style="zoom: 50%;" />



运行 *g++* 命令进行编译，用法与 *gcc* 一样：

```shell
$ g++ test.cpp -o mybin
```

编译完毕后，执行程序：

```shell
$ ./mybin
```

![image-20221030134307669](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301343726.png)





---



## 编译流程





![image-20221030134941093](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301349226.png)

我们以下面这个代码为例子去了解编译流程

![image-20221030135302614](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301353746.png)



1. **预处理(进行宏替换)**  

> 预处理功能主要包括宏定义,文件包含,条件编译,去注释等。预处理指令是以#号开头的代码行。
> 实例: gcc –E hello.c –o hello.i
> 选项“-E”,该选项的作用是让 gcc 在预处理结束后停止编译过程。
> 选项“-o”是指目标文件,“.i”文件为已经过预处理的C原始程序  



生成预处理后的.i文件

```shell
$ gcc -E hello.c -o hello.i
```



![image-20221030135453448](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301354557.png)





用vim打开hello.i文件查看内容

```shell
$ vim hello.i
```

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301402614.png" style="zoom:80%;" />

可以看到对比hello.c 和hello.i 文件后，.i文件的代码一下子变成了八百多行，原因就是头文件在.i中展开了，然后在.i

文件中注释也被删掉，宏定义也完成了替换！





2. **编译（生成汇编）**  

>在这个阶段中,gcc 首先要检查代码的规范性、是否有语法错误等,以确定代码的实际要做的工作,在检查
>无误后,gcc 把代码翻译成汇编语言。
>用户可以使用“-S”选项来进行查看,该选项只进行编译而不进行汇编,生成汇编代码。
>实例: gcc –S hello.i –o hello.s  



生成预处理后的.s文件

```shell
$ gcc -S hello.i -o hello.s
```

![image-20221030140709330](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301407433.png)

用vim打开hello.s文件查看内容

```shell
$ vim hello.s
```



<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301408441.png" alt="image-20221030140804256" style="zoom:80%;" />

可以看到这步完成了从C语言代码转化成了汇编代码





3. **汇编（生成机器可识别代码）** 

   > 汇编阶段是把编译阶段生成的“.s”文件转成目标文件
   > 读者在此可使用选项“-c”就可看到汇编代码已转化为“.o”的二进制目标代码了
   > 实例: gcc –c hello.s –o hello.o

   

   生成预处理后的.o文件

   ```shell
   $ gcc -c hello.s -o hello.o
   ```

   <img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301411191.png" alt="image-20221030141120093" style="zoom:80%;" />





用vim打开hello.o文件查看内容

```shell
$ vim hello.o
```

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301412346.png" alt="image-20221030141258235" style="zoom:67%;" />



可以发现里面都是乱码，其实这都是二进制







4. **连接（生成可执行文件或库文件）**  

>在成功编译之后,就进入了链接阶段。
>实例: gcc hello.o –o hello  



生成可执行文件

```shell
  $ gcc hello.o -o hello
```

![image-20221030141539254](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301415366.png)

这个文件可以直接运行

```shell
$ ./hello
```

![image-20221030141740578](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301417656.png)



**在这里涉及到一个重要的概念:函数库**  

>我们的C程序中，并没有定义“printf”的函数实现,且在预编译中包含的“stdio.h”中也只有该函数的声明,而
>没有定义函数的实现,那么,是在哪里实“printf”函数的呢?
>最后的答案是:系统把这些函数实现都被做到名为 libc.so.6 的库文件中去了,在没有特别指定时,gcc 会到
>系统默认的搜索路径“/usr/lib”下进行查找,也就是链接到 libc.so.6 库函数中去,这样就能实现函
>数“printf”了,而这也就是链接的作用  



**函数库一般分为静态库和动态库两种**。  



>静态库是指编译链接时,把库文件的代码全部加入到可执行文件中,因此生成的文件比较大,但在运行时也
>就不再需要库文件了。其后缀名一般为“.a”
>动态库与之相反,在编译链接时并没有把库文件的代码加入到可执行文件中,而是在程序执行时由运行时
>链接文件加载库,这样可以节省系统的开销。动态库一般后缀名为“.so”,如前面所述的 libc.so.6 就是动态
>库。gcc 在编译时默认使用动态库。完成了链接之后,gcc 就可以生成可执行文件,如下所示。 gcc
>hello.o –o hello
>gcc默认生成的二进制程序，是动态链接的，这点可以通过 file 命令验证 ,比如我们上面生成的hello，就是动态链接的 

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301419012.png" alt="image-20221030141928946" style="zoom:80%;" />



我们使用下面的命令生成一个静态链接的程序

```shell
$ gcc -o hello_static hello.c -static
```



<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301422569.png" alt="image-20221030142235491" style="zoom:80%;" />



---





## gcc选项

  

| 选项    | 功能                                                         |
| ------- | ------------------------------------------------------------ |
| -E      | 只激活预处理,这个不生成文件,你需要把它重定向到一个输出文件里面 |
| -S      | 编译到汇编语言不进行汇编和链接                               |
| -c      | 编译到目标代码                                               |
| -o      | 文件输出到 文件                                              |
| -static | 此选项对生成的文件采用静态链接                               |
| -g      | 生成调试信息。GNU 调试器可利用该信息                         |
| -shared | 此选项将尽量使用动态库，所以生成文件比较小，但是需要系统由动态库 |
| -w      | 不生成任何警告信息                                           |
| -Wall   | 生成所有警告信息                                             |

gcc选项记忆的一些小技巧：

编译过程：ESc（对比键盘左上角的esc），生成的文件后缀iso（对比镜像文件后缀的ISO）

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301426595.png" alt="image-20221030142632191" style="zoom: 67%;" />  





----





# 2. Linux调试器-gdb使用  



### gdb 程序交互调试

GDB是一个由GNU开源组织发布的、UNIX/LINUX操作系统下的、基于命令行的、功能强大的程序调试工具。

对于一名Linux下工作的c++程序员，gdb是必不可少的工具；

GDB中的命令固然很多，但我们只需掌握其中十个左右的命令，就大致可以完成日常的基本的程序调试工作。

以下从一个完整的调试过程简单说明最基本的几个命令;

```shell
- gdb 程序名称    # 启动gdb
>break 代码行数       # 设置断点
>run                # 运行调试程序
>next               # 单步调试
>print var1         # 在调试过程中，我们需要查看当前某个变量值的时候，使用print 命令打印该值
>list               # 显示当前调试处的源代码
>info b             # 显示当前断点设置情况
```



## 注意点



> 程序的发布方式有两种，debug模式和release模式
> Linux gcc/g++出来的二进制程序，默认是release模式
> 要使用gdb调试，必须在源代码生成二进制程序的时候, 加上 -g 选项  





### 运行



| 命令全称（缩写）        | 功能                                                         |
| ----------------------- | ------------------------------------------------------------ |
| run         (简记为 r ) | 其作用是运行程序，当遇到断点后，程序会在断点处停止运行，等待用户输入下一步的命令。 |
| continue （简写c ）     | 继续执行，到下一个断点处（或运行结束）                       |
| next：（简写 n）        | 单步跟踪程序，当遇到函数调用时，也不进入此函数体；此命令同 step 的主要区别是，step 遇到用户自定义的函数，将步进到函数中去运行，而 next 则直接调用函数，不会进入到函数体内。 |
| step    （简写s）       | 单步调试如果有函数调用，则进入函数；与命令n不同，n是不进入调用的函数的 |
| until                   | 当你厌倦了在一个循环体内单步跟踪时，这个命令可以运行程序直到退出循环体。 |
| until+行号              | 运行至某行，不仅仅用来跳出循环                               |
| finish                  | 运行程序，直到当前函数完成返回，并打印函数返回时的堆栈地址和返回值及参数值等信息。 |
| call 函数(参数)         | 调用程序中可见的函数，并传递“参数”，如：call add()           |
| quit        (简记为 q)  | 退出gdb                                                      |





### 设置断点

|    命令全称（缩写）    | 功能                       |
| :--------------------: | -------------------------- |
| break n**（简写b n）** | **在第n行处设置断点**      |
|     b fn1 if a＞b      | 条件断点设置               |
|     delete 断点号n     | 删除第n个断点              |
|         info b         | 显示当前程序的断点设置情况 |



### 查看源代码



| 命令全称（缩写） | 功能                                                    |
| ---------------- | ------------------------------------------------------- |
| list(简记为 l)   | 其作用就是列出程序的源代码，默认每次显示10行            |
| list 行号        | 将显示当前文件以“行号”为中心的前后10行代码，如：list 10 |
| list 函数名      | 将显示“函数名”所在函数的源代码，如：list main           |



### 查看变量



| 命令         | 功能                                                         |
| ------------ | ------------------------------------------------------------ |
| display 变量 | 在单步运行时将非常有用，使用display命令设置一个表达式后，它将在每次单步进行指令后，紧接着输出被设置的表达式及值。如： display a |
| print a(p)   | 将显示整数 a 的值                                            |





---





# 3. Linux项目自动化构建工具-make/Makefile  



## 为什么需要make/Makefile



会不会写makefile，从一个侧面说明了一个人是否具备完成大型工程的能力  

> 一个工程中的源文件不计数，其按类型、功能、模块分别放在若干个目录中，makefile定义了一系列的
> 规则来指定，哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译，甚至于进行更复杂
> 的功能操作  



makefile带来的好处就是——“自动化编译”，一旦写好，只需要一个make命令，整个工程完全自动编
译，极大的提高了软件开发的效率。  

>make是一个命令工具，是一个解释makefile中指令的命令工具，一般来说，大多数的IDE都有这个命
>令，比如：Delphi的make，Visual C++的nmake，Linux下GNU的make。可见，makefile都成为了一
>种在工程方面的编译方法。
>



# *Makefile*介绍

make是一条命令，makefile是一个文件，两个搭配使用，完成项目自动化构建  



只要我们的*makefile*写得够好，所有的这一切，我们只用一个make命令就可以完成，make命令会自动智能地根据当前的文件修改的情况来确定哪些文件需要重编译，从而自动编译所需要的文件和链接目标程序。



## Makefile简单的用法



这里简单介绍一下它的用法

我们用test.c ,add.h,add.c三个文件当例子

![](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301528897.png)

首先需要手动创建一个Makefile文件，并打开输入以下命令

```shell
$ vim Makefile
```

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301530057.png" alt="image-20221030153007981" style="zoom:80%;" />



## *makefile*的规则

在讲述这个*makefile*之前，还是让我们先来粗略地看一看*makefile*的规则。

![image-20221030153435103](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301534204.png)

- target（对比上面的mybin）

  可以是一个object file（目标文件），也可以是一个执行文件，还可以是一个标签（label）。对于标签这种特性，

- prerequisites（相当于上面的test.c 和add.c）

  生成该target所依赖的文件和/或target

- command（编译生成程序的命令）

  该target要执行的命令（任意的shell命令）



然后我们在命令行中直接输入

```shell
$ make
```



即可直接生成mybin可执行文件

![image-20221030153701862](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301537938.png)



我们继续打开Makefile文件，并输入下面命令



<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301539853.png" alt="image-20221030153913779" style="zoom:80%;" />

![image-20221030154200384](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301542464.png)



我们回到命令行中输入

```shell
$ make clean
```



可以发现前面生成的mybin可执行文件已经被清理

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301543417.png" alt="image-20221030154301327" style="zoom:80%;" />

所谓的伪目标就是：==“总是被执行的”==

什么意思呢？

我们可以在命令上多次输入make，可以发现它并没有帮我们执行，因为mybin已经存在了，而且并没有修改源文件，它觉得没必要

重新生成了

![image-20221030154441863](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301544929.png)

但是下面的指令呢？

```shell
$ make clean
```

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301545422.png" alt="image-20221030154555328" style="zoom:80%;" />

我们回到Makefile文件中，修改成下面的画面

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301546926.png" alt="image-20221030154651793" style="zoom:80%;" />

再来多次执行make命令

![image-20221030154727896](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301547993.png)

可以看到这次将mybin设置成伪目标后，也变成了“总是被执行”





## 提出疑问

1. ### **为什么输入make命令会执行第一句指令呢**？

为什么clean需要写成

```shell
$ make clean
```

为什么mybin不需要写成

```shell
$ make mybin
```



<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301549433.png" alt="image-20221030154954301" style="zoom:67%;" />



我们来看这样的一些现象：把Makefile中的clean移动到第一行，再去make

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301750144.png" alt="image-20221030175028034" style="zoom:80%;" />



<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301752628.png" alt="image-20221030175253586" style="zoom:80%;" />

可以看到这次make执行的是rm -rf mybin这条命令

这就说明了其实

**在Makefile中，执行make命令的时候，如果不指定具体目标，它就会默认执行第一个目标**



---





2. ### **make它是怎么知道我的源文件没有被修改从而不让我多次make的原因？**



首先要理解这个的原理，需要知道一些储备知识

查看一个文件的属性信息的一个命令

```shell
$ stat 文件名
```

比如我们查看一下上面的test.c文件的属性



<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301900371.png" alt="image-20221030190014264" style="zoom:80%;" />



- **Access\Modify\Change的初始时间记录都是文件被创建的时间**
- **Access** 指最后一次读取的时间（访问）（比如在终端上用cat、more 、less、[grep](https://so.csdn.net/so/search?q=grep&spm=1001.2101.3001.7020)、 cp 、file 一个文件时）（注意它不会每次都更新，因为访问是一个很频繁的操作，每一次操作系统更新它的时间是没必要的）
- **Modify** 指最后一次修改数据的时间（修改）（意思为**更改（内容），“或者“写入**）
- **Change** 指最后一次修改元数据的时间（改变）（**状态或属性**）（比如对一个文件或者目录作mv、chown、chgrp操作）

**change时间会受到modify行为的影响**，因为如果向文件写入内容，表示着它的大小会变化，从而就是改变了它的属性

----



根据了解上面的基础知识，我们就可以很容易的解释为什么make能判断该文件有没有必要重新编译，

其实就是根据**生成的可执行程序（例如上面的mybin）的修改时间，然后再根据源文件修改时间进行判断**，如果

**可执行程序的时间比源文件的时间要更新或者说更晚，就不会进行重新生成可执行程序**，从而减少不必要编译过程

<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301912981.png" alt="image-20221030191204915" style="zoom:80%;" />



> 这里也可以更进一步理解所谓的“伪目标”，**被.PHONY修饰的目标本质是就是不采用上面的时间判断规则**，
>
> 只要你输入了，它就执行！







----



## make总结

在默认的方式下，也就是我们只输入 `make` 命令。那么，

- make会在当前目录下找名字叫“*Makefile*”或“*makefile*”的文件。
- 如果找到，它会找文件中的第一个目标文件（target），在上面的例子中，他会找到“test.c 和 add.c”这个文件，并把这个文件作为最终的目标文件。
- 如果mybin文件不存在，或是mybin所依赖的后面的 `.c` 文件的文件修改时间要比 `mybin` 这个文件新，那么，他就会执行后面所定义的命令来生成 `mybin` 这个文件。
- 如果 `mybin` 所依赖的 `.c` 文件也不存在，那么make会在当前文件中找目标为 `.o` 文件的依赖性，如果找到则再根据那一个规则生成 `.o` 文件。（这有点像一个堆栈的过程）
- 当然，你的C文件和H文件是存在的啦，他就直接生成` 可执行程序mybin`

这就是整个make的依赖性，make会一层又一层地去找文件的依赖关系，直到最终编译出第一个目标文件。在找寻的过程中，如果出现错误，比如最后被依赖的文件找不到，那么make就会直接退出，并报错，而对于所定义的命令的错误，或是编译不成功，make根本不理。make只管文件的依赖性，即，如果在我找了依赖关系之后，冒号后面的文件还是不在，那么对不起，我就不工作啦。

通过上述分析，我们知道，像clean这种，没有被第一个目标文件直接或间接关联，那么它后面所定义的命令将不会被自动执行，不过，我们可以显示要make执行。即命令—— `make clean` ，以此来清除所有的目标文件，以便重编译。

于是在我们编程中，如果这个工程已被编译过了，当我们修改了其中一个源文件，比如 `test.c` ， `test.c` 的文件修改时间要比 `mybin` 要新，所以 `mybin` 也会被重新链接了。

而如果我们改变了 `add.h` ，那么， `test.c`  和 `add.c` 都会被重编译，并且， `mybin` 会被重链接。





---





# 4. 使用 git 命令行  



## 概述

Git是分布式版本控制系统，与SVN类似的集中化版本控制系统相比，集中化版本控制系统如果中央服务器宕机则会影响数据和协同开发。

Git是分布式的版本控制系统，客户端不只是提取最新版本的快照，而且将整个代码仓库镜像复制下来。如果任何协同工作用的服务器发生故障了，也可以用任何一个代码仓库来恢复。而且在协作服务器宕机期间，你也可以提交代码到本地仓库，当协作服务器正常工作后，你再将本地仓库同步到远程仓库。

## 特性

- 能够对文件版本控制和多人协作开发
- 拥有强大的分支特性，所以能够灵活地以不同的工作流协同开发
- 分布式版本控制系统，即使协作服务器宕机，也能继续提交代码或文件到本地仓库，当协作服务器恢复正常工作时，再将本地仓库同步到远程仓库。
- 当团队中某个成员完成某个功能时，通过pull request操作来通知其他团队成员，其他团队成员能够review code后再合并代码。



# 为什么要用Git

- 能够对文件版本控制和多人协作开发
- 拥有强大的分支特性，所以能够灵活地以不同的工作流协同开发
- 分布式版本控制系统，即使协作服务器宕机，也能继续提交代码或文件到本地仓库，当协作服务器恢复正常工作时，再将本地仓库同步到远程仓库。
- 当团队中某个成员完成某个功能时，通过pull request操作来通知其他团队成员，其他团队成员能够review code后再合并代码。









# Git常用命令

| 分类 | 子类                        | git command                                                  |
| :--- | :-------------------------- | :----------------------------------------------------------- |
| 分支 | 查看当前分支                | `git branch`                                                 |
|      | 创建新分支,仍停留在当前分支 | git branch                                                   |
|      | 创建并切换到新分支          | git checkout -b                                              |
|      | 切换分支                    | git checkout                                                 |
|      | 合并分支                    | git checkout #切换到要合并的分支git merge –no-ff #合并指定分支到当前分支 |
| 提交 | 查看状态                    | git status                                                   |
|      | 查看修改部分                | git diff —color                                              |
|      | 添加文件到暂存区            | git add —all                                                 |
|      | 提交本地仓库                | git commit -m ““                                             |



# git设置忽略特殊文件

##  忽略文件的原则

1. 忽略操作系统自动生成的文件，比如缩略图等；
2. 忽略编译生成的中间文件、可执行文件等，也就是如果一个文件是通过另一个文件自动生成的，那自动生成的文件就没必要放进版本库，比如C语言编译产生的`.obj`文件；
3. 忽略你自己的带有敏感信息的配置文件，比如存放口令的配置文件。

## 设置的方法

在项目下编辑 .gitignore 文件

![image-20221030193043108](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301930203.png)



<img src="https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301930745.png" alt="image-20221030193057668" style="zoom:80%;" />





具体要把什么文件屏蔽可以手动添加

比如我不需要把后缀为.exe可执行文件上传

![image-20221030193212663](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210301932749.png)





## gitignore 不生效解决方法

原因是.gitignore只能忽略那些原来没有被track的文件，如果某些文件已经被纳入了版本管理中，则修改.gitignore是无效的。那么解决方法就是先把本地缓存删除（改变成未track状态），然后再提交：

```shell
$ git rm -r --cached .
$ git add .
$ git commit -m 'update .gitignore'
```

