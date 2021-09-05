#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, x, x1, x2;

    cout << "解一元二次方程程序  coded by TYX\nax^2+bx+c=0\n请输入a、b、c的值(输入一个值后按回车键以输入下一个值)" << endl;

    cin >> a >> b >> c;

    if( a == 0 )
{
        x = -c/b;
        cout << "这不是一个二次方程\nx的值为" << x << endl;
}
    else

        if(b*b - 4*a*c < 0)
{
           cout << "方程无实根" << endl;
}
        else if(b*b - 4*a*c > 0)
{
            x1 = (-b + sqrt(b*b - 4*a*c)) / 2*a;
            x2 = (-b - sqrt(b*b - 4*a*c)) / 2*a;
            cout << "方程解为：" << x1 << "或" << x2 << endl;
}
        else if(b*b - 4*a*c == 0)
{
            x = -b / 2*a;
            cout << "方程解为：" << x << endl;
}
    cout << "按任意键退出";
    getch();

    return 0;

}
