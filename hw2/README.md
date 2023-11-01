##test 2_1

【问题描述】

从标准输入中读入一个整数算术运算表达式，如24 / ( 1 + 2 + 36 / 6 / 2 - 2) * ( 12 / 2 / 2 )= ，计算表达式结果，并输出。

要求：
1、表达式运算符只有+、-、*、/，表达式末尾的=字符表示表达式输入结束，表达式中可能会出现空格；
2、表达式中会出现圆括号，括号可能嵌套，不会出现错误的表达式；
3、出现除号/时，以整数相除进行运算，结果仍为整数，例如：5/3结果应为1。

4、要求采用表达式树来实现表达式计算。

表达式树（expression tree）：

我们已经知道了在计算机中用后缀表达式和栈来计算中缀表达式的值。在计算机中还有一种方式是利用表达式树来计算表达式的值。表达式树是这样一种树，其根节点为操作符，非根节点为操作数，对其进行中序遍历将计算表达式的值。由后缀表达式生成表达式树的方法如下：

l  读入一个符号：

l  如果是操作数，则建立一个单节点树并将指向他的指针推入栈中；

l  如果是运算符，就从栈中弹出指向两棵树T1和T2的指针（T1先弹出）并形成一棵新树，树根为该运算符，它的左、右子树分别指向T2和T1，然后将新树的指针压入栈中。

例如输入的后缀表达为：

ab+cde+**

则生成的表达式树为：


![image](https://github.com/WHUCSstetman/Data-Structure-Experiment/assets/105272933/5e0302b4-cbee-4e31-8fef-d9ec3672528a)

【输入形式】

从键盘输入一个以=结尾的整数算术运算表达式。操作符和操作数之间可以有空格分隔。


【输出形式】

首先在屏幕上输出表达式树根、左子节点及右子节点上的运算符或操作数，中间由一个空格分隔，最后有一个回车（如果无某节点，则该项不输出）。然后输出表达式计算结果。

【样例输入】
24 / ( 1 + 2 + 36 / 6 / 2 - 2) * ( 12 / 2 / 2 )     =

【样例输出】
* / /
18

【样例说明】
按照运算符及括号优先级依次计算表达式的值。在生成的表达树中，*是根节点的运算符，/ 是根节点的左子节点上运算符，/是根节点的右子节点上运算符，按题目要求要输出。


【评分标准】

通过所有测试点得满分。

##test 2_2

【问题描述】

武大文理学部主要办公科研楼有行政楼、逸夫楼、物理楼、生科楼、化学楼、图书馆等，武大信息中心计划要给相关建筑物间铺设光缆进行网络连通，请给出用料最少的铺设方案。

编写程序输入一个办公区域分布图及建筑物之间的距离，计算出用料最少的铺设方案（只有一组最优解，不用考虑多组解)。要求采用Prim或Kruskal算法实现。


【输入形式】

办公区域分布图的顶点（即建筑物）按照自然数（0，1，2，n-1）进行编号，从标准输入中首先输入两个正整数，分别表示线路图的顶点的数目和边的数目，然后在接下的行中输入每条边的信息，每条边占一行，具体形式如下：

<n> <e>
<id> <vi> <vj> <weight>
...
即顶点vi和vj之间边的权重是weight，边的编号是id。

【输出形式】

输出铺设光缆的最小用料数，然后另起一行输出需要铺设的边的id，并且输出的id值按照升序输出。

【样例输入】

6 10
1 0 1 600
2 0 2 100
3 0 3 500
4 1 2 500
5 2 3 500
6 1 4 300
7 2 4 600
8 2 5 400
9 3 5 200
10 4 5 600

【样例输出】

1500
2 4 6 8 9

【样例说明】
样例输入说明该分布图有6个顶点，10条边；顶点0和1之间有条边，边的编号为1，权重为600；顶点0和2之间有条边，权重为100，其它类推。其对应图如下：

![image](https://github.com/WHUCSstetman/Data-Structure-Experiment/assets/105272933/dec68730-4633-42fe-9f7e-3455c0ed69e9)


经计算此图的最少用料是1500，可以使图连通，边的编号是2 4 6 8 9。其对应的最小生成树如下：

![image](https://github.com/WHUCSstetman/Data-Structure-Experiment/assets/105272933/b8ef0f61-8697-450f-b856-8e1f0a219aae)


【评分标准】

通过所有测试点满分。
