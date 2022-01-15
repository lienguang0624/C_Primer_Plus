# 1.宏定义

#define 叫做宏定义命令，它也是C语言预处理命令的一种。所谓宏定义，就是用一个标识符来表示一个字符串，如果在后面的代码中出现了该标识符，那么就全部替换成指定的字符串。

我们先通过一个例子来看一下 #define 的用法：
```c
#include <stdio.h>

#define N 100

int main(){
    int sum = 20 + N;
    printf("%d\n", sum);
    return 0;
}
```

可用宏定义表示数据类型，使书写方便。例如：
```c
#define UINT unsigned int
```
在程序中可用 UINT 作变量说明：
```c
UINT a, b;
```

## 1.1 带参数的宏定义

带参宏定义的一般形式为：
```c
#define 宏名(形参列表) 字符串
```

带参宏调用的一般形式为：
```c
宏名(实参列表);
```

【示例】输出两个数中较大的数
```c
#include <stdio.h>
#define MAX(a,b) (a>b) ? a : b
int main(){
    int x , y, max;
    printf("input two numbers: ");
    scanf("%d %d", &x, &y);
    max = MAX(x, y);
    printf("max=%d\n", max);
    return 0;
}
```

## 1.2 C语言带参宏定义和函数的区别
带参数的宏和函数很相似，但有本质上的区别：宏展开仅仅是字符串的替换，不会对表达式进行计算；宏在编译之前就被处理掉了，它没有机会参与编译，也不会占用内存。而函数是一段可以重复使用的代码，会被编译，会给它分配内存，每次调用函数，就是执行这块内存中的代码。

# 2.C语言#if、##ifdef、#ifndef的用法详解，C语言条件编译详解

# 2.1 #if 的用法

#if 用法的一般格式为：
```c
#if 整型常量表达式1
    程序段1
#elif 整型常量表达式2
    程序段2
#elif 整型常量表达式3
    程序段3
#else
    程序段4
#endif
```
【案例】：
```c
#include <stdio.h>
int main(){
    #if _WIN32
        printf("This is Windows!\n");
    #else
        printf("Unknown platform!\n");
    #endif
   
    #if __linux__
        printf("This is Linux!\n");
    #endif
    return 0;
}
```