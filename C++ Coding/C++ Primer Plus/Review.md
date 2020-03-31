# 简答题

## 第2章 开始学习C++

1. 函数

2. 包含头文件iostream的源代码到程序中

3. 使得程序的特定部分中的函数能够访问std命名空间

4. ```
   cout << "Hello,world" << endl;
   ```

5. ```C++
   int cheeses;
   ```

6. ```C++
   cheeses = 32;
   ```

7. ```C++
   cin >> cheeses;
   ```

8. ```C++
   cout << "We have" << X << "varieties of cheese,";（更正：X应该改为cheeses）
   ```

9. 返回值类型、函数名、形参列表

10. void函数以及在main函数中。（注：void可以只return不加返回值）

11. **原因**：程序没有包含iostream，或不具有访问std命名空间的权限且能够访问的所有对象都不包含cout。

    **修复方法**：

    1. 程序开头加上`#include<iostream>`在程序开头加上`using namespace std`
    2. main函数函数体的第一行开头加上`using namespace std;`



## 第3章：处理数据

1. 为了满足不同的计算与存储需要

2. ```c++
     short a = 80; unsigned int b = 42110; long a = 3000000000; //更正 应为 long long a=3000000000；
     //备注：
     //int is 4 bytes.
     //short is 2 bytes.
     //long long is 8 bytes.
     
     //Maximum values:
     //int: 2147483647
     //short: 32767
     //long: 2147483647
     //long long: 9223372036854775807
     
     //Minimum int value = -2147483648
     ```

3. ~~溢出后循环赋值~~ //**更正**：C++没有提供自动方之超出整形限制的功能，可以使用头文件`climits`来确定限制情况

4. `33`被存储为`const int`,而`33L`被存储为`const long`

5. ~~等价~~  //更正：不等价，首先，只有使用ASCII美国信息交换标准代码的系统上，`65`才对应`A`，其次，`65`是`const int`,而`'A'`是`const char`

6. 法一：`char a=88; cout << a;`
     法二：`cout<< char(88);`
       //备注:还有 `cout.put(cahr(88)); cout << (char)88;`

7. - `short `至少16位； 
     - `int` 至少和short一样长； 
     - `long` 至少32位，且至少和int一样长； 
     - `long long `至少64位，且至少和long一样长。 
     - 一般`double`为64位
     - 将`long`,` long long`值赋给`double`变量时，均有可能导致舍入误差；
       //参考答案：取决于类型的长度，如果`long`为4字节，则没有损失，此时最大的`long`将是20亿（10位数），`double`提供了至少13位有效数字，因而不需要进行任何舍入，`long long`可提供19位有效数字，超过了`double`保证的13位有效数字
8. `a-74 b-4 c-0 d-4.5 e-3`

9.  ```C++
   int_result=(int)double_a +(int)double_b;
   int_result= double_a + double_b;
   ```
   
10. `int;float;char;char32_t;`~~float~~ // 更正：最后一个应该为double

