# 数据在内存中的存储（二进制形式存储）

&emsp;&emsp;在C语言中，每一种数据类型所占用的字节数都是固定的，知道了数据类型，也就知道了数据的长度。

&emsp;&emsp;一个字节8位二进制，在现代操作系统中，int 一般占用 4 个字节（Byte）的内存，共计 32 位（Bit）。



&emsp;&emsp;字符型char	 长度	1

&emsp;&emsp;短整型short	长度	2

&emsp;&emsp;整型int	长度	4

&emsp;&emsp;长整型long	长度	4/8

&emsp;&emsp;单精度浮点型float	长度	4

&emsp;&emsp;双精度浮点型double	长度	8

&emsp;&emsp;无类型void长度	1

```c
在 32 位环境以及 Win64 环境下的运行结果为：

short=2, int=4, long=4, char=1

在 64 位 Linux 和 Mac OS 下的运行结果为：

short=2, int=4, long=8, char=1
```