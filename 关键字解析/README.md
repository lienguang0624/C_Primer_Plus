# 关键字定义

&emsp;&emsp;关键字（Keywords）是由C语言规定的具有特定意义的字符串，通常也称为保留字，例如 int、char、long、float、unsigned 等。我们定义的标识符不能与关键字相同，否则会出现错误。

auto	声明自动变量

short	声明短整型变量或函数

int	声明整型变量或函数

long	声明长整型变量或函数

float	声明浮点型变量或函数

double	声明双精度变量或函数

char	声明字符型变量或函数

struct	声明结构体变量或函数

union	声明共用数据类型

enum	声明枚举类型

typedef	用以给数据类型取别名 √

const	声明只读变量

unsigned	声明无符号类型变量或函数

signed	声明有符号类型变量或函数

extern	声明变量是在其他文件正声明

register	声明寄存器变量

static	声明静态变量

volatile	说明变量在程序执行中可被隐含地改变

void	声明函数无返回值或无参数，声明无类型指针

if	条件语句

else	条件语句否定分支（与 if 连用）

switch	用于开关语句

case	开关语句分支

for	一种循环语句

do	循环语句的循环体

while	循环语句的循环条件

goto	无条件跳转语句

continue	结束当前循环，开始下一轮循环

break	跳出当前循环

default	开关语句中的“其他”分支

sizeof	计算数据类型长度

return	子程序返回语句（可以带参数，也可不带参数）循环条件

# 1.typedef
&emsp;&emsp;C语言允许为一个数据类型起一个新的别名，就像给人起“绰号”一样。

&emsp;&emsp;起别名的目的不是为了提高程序运行效率，而是为了编码方便。例如有一个结构体的名字是 stu，要想定义一个结构体变量就得这样写：
```c
struct stu stu1;
```
&emsp;&emsp;struct 看起来就是多余的，但不写又会报错。如果为 struct stu 起了一个别名 STU，书写起来就简单了：
```c
STU stu1;
```
&emsp;&emsp;这种写法更加简练，意义也非常明确，不管是在标准头文件中还是以后的编程实践中，都会大量使用这种别名。

&emsp;&emsp;使用关键字 typedef 可以为类型起一个新的别名。typedef 的用法一般为：
```c
typedef  oldName  newName;
```
&emsp;&emsp;oldName 是类型原来的名字，newName 是类型新的名字。例如：
```c
typedef int INTEGER;
INTEGER a, b;
a = 1;
b = 2;
```
&emsp;&emsp;INTEGER a, b;等效于int a, b;。

&emsp;&emsp;typedef 还可以给数组、指针、结构体等类型定义别名。先来看一个给数组类型定义别名的例子：
```c
typedef char ARRAY20[20];
```
&emsp;&emsp;表示 ARRAY20 是类型char [20]的别名。它是一个长度为 20 的数组类型。接着可以用 ARRAY20 定义数组：
```c
ARRAY20 a1, a2, s1, s2;
```
&emsp;&emsp;它等价于：
```c
char a1[20], a2[20], s1[20], s2[20];
```
&emsp;&emsp;又如，为结构体类型定义别名：
```c
typedef struct stu{
    char name[20];
    int age;
    char sex;
} STU;
```
&emsp;&emsp;STU 是 struct stu 的别名，可以用 STU 定义结构体变量：
```c
STU body1,body2;
```
&emsp;&emsp;它等价于：
```c
struct stu body1, body2;
```
&emsp;&emsp;再如，为指针类型定义别名：
```c
typedef int (*PTR_TO_ARR)[4];
```
&emsp;&emsp;表示 PTR_TO_ARR 是类型int * [4]的别名，它是一个二维数组指针类型。接着可以使用 PTR_TO_ARR 定义二维数组指针：
```c
PTR_TO_ARR p1, p2;
```
&emsp;&emsp;按照类似的写法，还可以为函数指针类型定义别名：
```c
typedef int (*PTR_TO_FUNC)(int, int);
PTR_TO_FUNC pfunc;
```
&emsp;&emsp;【示例】为指针定义别名
```c
#include <stdio.h>
typedef char (*PTR_TO_ARR)[30];
typedef int (*PTR_TO_FUNC)(int, int);
int max(int a, int b){
    return a>b ? a : b;
}
char str[3][30] = {
    "http://c.biancheng.net",
    "C语言中文网",
    "C-Language"
};
int main(){
    PTR_TO_ARR parr = str;
    PTR_TO_FUNC pfunc = max;
    int i;
   
    printf("max: %d\n", (*pfunc)(10, 20));
    for(i=0; i<3; i++){
        printf("str[%d]: %s\n", i, *(parr+i));
    }
    return 0;
}
```
&emsp;&emsp;需要强调的是，typedef 是赋予现有类型一个新的名字，而不是创建新的类型。为了“见名知意”，请尽量使用含义明确的标识符，并且尽量大写。

**typedef 和 #define 的区别:**

&emsp;&emsp;typedef 在表现上有时候类似于 #define，但它和宏替换之间存在一个关键性的区别。正确思考这个问题的方法就是把 typedef 看成一种彻底的“封装”类型，声明之后不能再往里面增加别的东西。

&emsp;&emsp;可以使用其他类型说明符对宏类型名进行扩展，但对 typedef 所定义的类型名却不能这样做。如下所示：
```c
#define INTERGE int
unsigned INTERGE n;  //没问题

typedef int INTERGE;
unsigned INTERGE n;  //错误，不能在 INTERGE 前面添加 **unsigned**
```
