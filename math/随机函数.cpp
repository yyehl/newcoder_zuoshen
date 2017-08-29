/*
给定一个等概率随机产生1~5的随机函数，除此之外，不能使用任何额外的随机机制，请实现等概率随机产生1~7的随机函数。
(给定一个可调用的Random5::random()方法,可以等概率地随机产生1～5的随机函数)
*/
// 以下内容请不要修改
class Random5 {
public:
	static int randomNumber();
};

class Random7 {
public:
    int rand5() {
        return Random5::randomNumber();
    }
    // 以上内容请不要修改
    

    int randomNumber() {
        int num = 5 * rand5() + rand5();   // 生成6~25的随机数
        while (num < 7 || num > 20)
            num = 5 * rand5() + rand5();    // 如果不是在7~20之间，则重新生成，重新生成之后的概率一定会平均分配在区间之间的
        return num % 7 + 1;
    }
};