#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, x, x1, x2;

    cout << "��һԪ���η��̳���  coded by TYX\nax^2+bx+c=0\n������a��b��c��ֵ(����һ��ֵ�󰴻س�����������һ��ֵ)" << endl;

    cin >> a >> b >> c;

    if( a == 0 )
{
        x = -c/b;
        cout << "�ⲻ��һ�����η���\nx��ֵΪ" << x << endl;
}
    else

        if(b*b - 4*a*c < 0)
{
           cout << "������ʵ��" << endl;
}
        else if(b*b - 4*a*c > 0)
{
            x1 = (-b + sqrt(b*b - 4*a*c)) / 2*a;
            x2 = (-b - sqrt(b*b - 4*a*c)) / 2*a;
            cout << "���̽�Ϊ��" << x1 << "��" << x2 << endl;
}
        else if(b*b - 4*a*c == 0)
{
            x = -b / 2*a;
            cout << "���̽�Ϊ��" << x << endl;
}
    cout << "��������˳�";
    getch();

    return 0;

}
