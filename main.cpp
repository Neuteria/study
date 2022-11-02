#include <iostream>
#include <graphics.h>//easyx.h
#include <conio.h>
#include <sstream>
using namespace std;
void yydz(int rec[20][20])//classification aka. yi yan ding zhen
{
    int left=0,right=0,up=0,down=0;
    for(int i=0; i<=19&&up==0; ++i)
    {
        for(int o=0; o<=19&&up==0; ++o)
        {
            if(rec[i][o]==1)
            {
                up=i+1;
            }
        }
    }
    if(up==0)
    {
        outtextxy(70,483,"未检测到输入");
        return;
    }
    for(int i=0; i<=19&&down==0; ++i)
    {
        for(int o=0; o<=19&&down==0; ++o)
        {
            if(rec[19-i][o]==1)
                down=20-i;
        }
    }
    for(int i=0; i<=19&&left==0; ++i)
    {
        for(int o=0; o<=19&&left==0; ++o)
        {
            if(rec[o][i]==1)
                left=i+1;
        }
    }
    for(int i=0; i<=19&&right==0; ++i)
    {
        for(int o=0; o<=19&&right==0; ++o)
        {
            if(rec[o][19-i]==1)
                right=20-i;
        }
    }
    int width=right-left+1,length=down-up+1,widthremain=5-width%5,lengthremain=5-length%5;
    if(width%5==0)
        widthremain=0;
    if(length%5==0)
        lengthremain=0;
    if(width<5&&length<5)
    {
        outtextxy(70,483,"无匹配数字");
        return;
    }
    width=widthremain+width;
    length=lengthremain+length;
    up=up-lengthremain/2-lengthremain%2;
    down=down+lengthremain/2;
    left=left-widthremain/2-widthremain%2;
    right=right-widthremain/2;
    int corewidth=width/5, corelength=length/5;
    int finrec[5][5]= {{0}};
    int X=0,Y=0;
    for(int x=left-1; x<=right-1; x+=corewidth,X++)
    {
        for(int y=up-1; y<=down-1; y+=corelength,Y++)
        {
            for(int i=x,tmp=0; (i<=(x+corewidth-1))&&(tmp==0); ++i)
            {
                for(int o=y; o<=(y+corelength-1); ++o)
                {
                    if(rec[i][o]==1)
                    {
                        finrec[X][Y]=1;
                        tmp=1;
                        break;
                    }
                }
            }

        }
        Y=0;
    }
    int onerec[5][5]= {{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}},
    tworec[5][5]= {{0,1,1,1,0},{1,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{1,1,1,1,1}},
    threerec[5][5]= {{0,1,1,1,0},{1,0,0,0,1},{0,0,0,1,0},{1,0,0,0,1},{0,1,1,1,0}},
    fourrec[5][5]= {{0,0,1,1,0},{0,1,0,1,0},{1,0,0,1,0},{1,1,1,1,1},{0,0,0,1,0}},
    fiverec[5][5]= {{1,1,1,1,1},{1,0,0,0,0},{1,1,1,1,0},{0,0,0,0,1},{1,1,1,1,0}},
    sixrec[5][5]= {{0,1,1,1,0},{1,0,0,0,0},{1,1,1,1,0},{1,0,0,0,1},{0,1,1,1,0}},
    sevenrec[5][5]= {{1,1,1,1,1},{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,0,1,0,0}},
    eightrec[5][5]= {{0,1,1,1,0},{1,0,0,0,1},{0,1,1,1,0},{1,0,0,0,1},{0,1,1,1,0}},
    ninerec[5][5]= {{0,1,1,1,0},{1,0,0,0,1},{0,1,1,1,1},{0,0,0,0,1},{0,1,1,1,0}},
    zerorec[5][5]= {{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}};
    int zerotrust=0,onetrust=0,twotrust=0,threetrust=0,fourtrust=0,fivetrust=0,sixtrust=0,seventrust=0,eighttrust=0,ninetrust=0;
    for(int i=0; i<=5; ++i)
    {
        for(int o=0; o<=5; ++o)
        {
            if(finrec[i][o]==zerorec[i][o])
            {
                zerotrust++;
            }
            if(finrec[i][o]==onerec[i][o])
            {
                onetrust++;
            }
            if(finrec[i][o]==tworec[i][o])
            {
                twotrust++;
            }
            if(finrec[i][o]==threerec[i][o])
            {
                threetrust++;
            }
            if(finrec[i][o]==fourrec[i][o])
            {
                fourtrust++;
            }
            if(finrec[i][o]==fiverec[i][o])
            {
                fivetrust++;
            }
            if(finrec[i][o]==sixrec[i][o])
            {
                sixtrust++;
            }
            if(finrec[i][o]==sevenrec[i][o])
            {
                seventrust++;
            }
            if(finrec[i][o]==eightrec[i][o])
            {
                eighttrust++;
            }
            if(finrec[i][o]==ninerec[i][o])
            {
                ninetrust++;
            }
        }
    }
    cout << zerotrust << " " << onetrust << " " << twotrust << " " << threetrust << " " << fourtrust << " " << fivetrust << " " << sixtrust << " " << seventrust << " " << eighttrust << " " << ninetrust;
    int tmp=zerotrust;
    char num='0';
    if(onetrust>=tmp)
    {
        num='1';
        tmp=onetrust;
    }
    else if(twotrust>=tmp)
    {
        num='2';
        tmp=twotrust;
    }
    else if(threetrust>=tmp)
    {
        num='3';
        tmp=threetrust;
    }
    else if(fourtrust>=tmp)
    {
        num='4';
        tmp=fourtrust;
    }
    else if(fivetrust>=tmp)
    {
        num='5';
        tmp=fivetrust;
    }
    else if(sixtrust>=tmp)
    {
        num='6';
        tmp=sixtrust;
    }
    else if(seventrust>=tmp)
    {
        num='7';
        tmp=seventrust;
    }
    else if(eighttrust>=tmp)
    {
        num='8';
        tmp=eighttrust;
    }
    else if(ninetrust>=tmp)
    {
        num='9';
        tmp=ninetrust;
    }
    if(tmp<=10)
    {
        outtextxy(70,483,"无匹配数字");
        return;
    }
    tmp*=4;
    outtextxy(70,483,num);
    if(tmp==100)
    {
        outtextxy(70,503,1+'0');
        outtextxy(80,503,'0');
        outtextxy(90,503,'0');
    }
    else
    {
        outtextxy(70,503,tmp/10+'0');
        outtextxy(80,503,tmp%10+'0');
    }

    outtextxy(100,503,"%");
}

void closebutton()
{
    setfillcolor(RED);
    setlinecolor(WHITE);
    setbkmode(TRANSPARENT);
    fillrectangle(380,443,430,473);
    outtextxy(387,448,"退出");
}

void resetbutton()
{
    setfillcolor(GREEN);
    setlinecolor(WHITE);
    setbkmode(TRANSPARENT);
    fillrectangle(380,507,430,537);
    outtextxy(387,512,"重置");
}

void finishbutton()
{
    setfillcolor(BLUE);
    setlinecolor(WHITE);
    setbkmode(TRANSPARENT);
    fillrectangle(380,475,430,505);
    outtextxy(387,480,"鉴别");
}

int main()
{
    ExMessage m;
    int rec[20][20] = { {0} };
    initgraph(441,441+100);
    LOGFONT f;
    settextcolor(WHITE);
    settextstyle(16,0,_T("Consolas"));
    int EXIT=0,RESET=0,YYDZ=0;
    f.lfQuality = ANTIALIASED_QUALITY;
    outtextxy(1,441,"数字识别程序v0.01  by tyx");
    outtextxy(1,457,"长按并拖动鼠标以书写");
    settextstyle(20,0,_T("Consolas"));
    outtextxy(1,457+16+10,"识别为：");
    outtextxy(1,457+16+30,"置信度：");
    closebutton();
    finishbutton();
    resetbutton();
    while(true)
    {
        ExMessage m;
        for(int i=0; i<=19; ++i)
        {
            for(int a=0; a<=19; ++a)
                rec[i][a]=0;
        }
        EXIT=0,RESET=0,YYDZ=0;
        setfillcolor(WHITE);
        setlinecolor(WHITE);
        for(int a=1; a<=440; a+=22)
        {
            for(int i=1; i<=440; i+=22)
            {
                fillrectangle(i,a,i+20,a+20);
            }
        }
        setfillcolor(BLACK);
        setlinecolor(BLACK);
        while(EXIT==0&&RESET==0&&YYDZ==0)
        {
            _sleep(0.005*1000);
            m = getmessage(EM_MOUSE);
            switch(m.message)
            {
            case WM_MOUSEMOVE:
            {
                if(m.lbutton)
                {
                    if(m.x<=1||m.x>=441||m.y<=1||m.y>=441||(m.x-1)%22<=1||(m.y-1)%22<=1)
                    {
                        break;
                    }
                    int Xaxis = (m.x-1)/22,Yaxis = (m.y-1)/22;
                    if(rec[Xaxis][Yaxis]==0)
                    {
                        rec[Xaxis][Yaxis]=1;
                    }
                    else break;
                    fillrectangle(Xaxis*22,Yaxis*22,Xaxis*22+22,Yaxis*22+22);
                }
                else break;
            }
            case WM_LBUTTONDOWN:
            {
                if(m.x>=380&&m.x<=430)
                {
                    if(m.y>=443&&m.y<=473)
                    {
                        EXIT=1;
                        break;
                    }
                    else if(m.y>=507&&m.y<=537)
                    {
                        RESET=1;
                        break;
                    }
                    else if(m.y>=475&&m.y<=505)
                    {
                        YYDZ=1;
                        break;
                    }
                }
            }
            default:
                break;
            }
        }
        if(YYDZ==1)
        {
            yydz(rec);
            while(EXIT==0&&RESET==0)
            {
                _sleep(0.005*1000);
                m = getmessage(EM_MOUSE);
                switch(m.message)
                {
                case WM_LBUTTONDOWN:
                {
                    if(m.x>=380&&m.x<=430)
                    {
                        if(m.y>=443&&m.y<=473)
                        {
                            EXIT=1;
                            break;
                        }
                        else if(m.y>=507&&m.y<=537)
                        {
                            RESET=1;
                            break;
                        }
                    }
                }
                default:
                    break;
                }
            }
        }
        if(EXIT==1)
        {
            closegraph();
            return 0;
        }
        if(RESET==1)
        {
            setfillcolor(BLACK);
            fillrectangle(70,483,200,550);
            continue;
        }
    }
}
