//��Ļ���ڻ���
#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include<time.h>

const int SCR_W = 1024;
const int SCR_H = 800;
const int MAP_W = SCR_W * 2;
const int MAP_H = SCR_H * 2;
const unsigned int ballnum = 200;

struct Ball {
    double x, y;        //Բ������
    double r;           //�뾶
    bool flag;          //�ж��Ƿ���
    COLORREF color;     //С��������ɫ
};

POINT REF_xy;

Ball FD_Ball[ballnum];//ʳ��С��
Ball PlayerBall; //���С��
IMAGE MAP(MAP_W, MAP_H);

//���������
void Camera_POS() {
    REF_xy.x = PlayerBall.x - SCR_W / 2;
    REF_xy.y = PlayerBall.y - SCR_H / 2;

    if (REF_xy.x < 0) {
        REF_xy.x = 0;
    }
    if (REF_xy.y < 0) {
        REF_xy.y = 0;
    }
    if (REF_xy.y >MAP_H) {
        REF_xy.y = MAP_H;
    }
    if (MAP_H-SCR_H<REF_xy.y ) {
        REF_xy.y = MAP_H - SCR_H;
    }
    if (MAP_W - SCR_W < REF_xy.x) {
        REF_xy.x = MAP_W - SCR_W;
    }
}

void SCR_Draw() {
    
    SetWorkingImage();
    Camera_POS();
    putimage(0, 0, SCR_W, SCR_H, &MAP, REF_xy.x, REF_xy.y);
}

//��ͼ����
void MAP_Draw() {
    SetWorkingImage(&MAP); //���õ�ͼΪ�����豸
    setbkcolor(WHITE); //���õ�ǰͼƬ����ɫ
    cleardevice(); //ʹ�õ�ǰ����ɫ���ͼƬ
}

//��ʼ��ʳ��С��
void initBall() {

    for (int i = 0; i < ballnum; i++)
    {
        FD_Ball[i].x = rand() % MAP_W;
        FD_Ball[i].y = rand() % MAP_H;
        FD_Ball[i].r = rand() % 10 + 1;
        FD_Ball[i].flag = 1;
        FD_Ball[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);
    }
}

//��ʼ�����
void Player_Init() {
    PlayerBall.x = rand() % MAP_W;
    PlayerBall.y = rand() % MAP_H;
    PlayerBall.r = rand() % 10 + 1;
    PlayerBall.flag = 1;
    PlayerBall.color = RGB(rand() % 256, rand() % 256, rand() % 256);
}

//���С����ɫ�ͻ���
void Draw_Ball() {
    for (int i = 0; i < ballnum; i++)
    {
        if (FD_Ball->flag) {
            setfillcolor(FD_Ball[i].color);
            solidcircle(FD_Ball[i].x, FD_Ball[i].y, FD_Ball[i].r);
        }

    }
}

//���С�����
void Player_Draw() {
    if (PlayerBall.flag) {
        setfillcolor(PlayerBall.color); //���������ɫ
        solidcircle(PlayerBall.x, PlayerBall.y, PlayerBall.r); //�������С��
        settextcolor(RED);
        setbkmode(TRANSPARENT); //���ñ���ģʽΪ͸��
        settextstyle(17, 0, _T("Consolas"));//����������ʽ
        outtextxy(PlayerBall.x, PlayerBall.y, _T("С��"));  //�������С������
    }
}

//��Ϸ����
void GAME_Draw() {
    MAP_Draw();
    Draw_Ball();
    Player_Draw();
    SCR_Draw();
}

//��ʼ��ʳ��С��
void GAME_Init() {
    using std::rand;
    std::srand(time(0));  //�������������
    initBall(); //ʳ��С���ʼ��
    Player_Init();//���С���ʼ��

}


//�������
void CreatPlayer() {
    using std::rand;
    std::srand(time(0));  //�������������
    Player_Init();
    Player_Draw();
}

//��ҿ���
void PL_Control(int step) {
    if (GetAsyncKeyState(VK_UP)) {
        if (PlayerBall.y - PlayerBall.r > 0) {
            PlayerBall.y -= step;
        }

    }

    if (GetAsyncKeyState(VK_DOWN)) {
        if ((PlayerBall.y + PlayerBall.r) < MAP_H) {
            PlayerBall.y += step;
        }

    }

    if (GetAsyncKeyState(VK_LEFT)) {
        if (PlayerBall.x - PlayerBall.r > 0) {
            PlayerBall.x -= step;
        }
    }

    if (GetAsyncKeyState(VK_RIGHT)) {
        if ((PlayerBall.x + PlayerBall.r) < MAP_W) {
            PlayerBall.x += step;
        }
    }
}

void initSCR() {
    initgraph(SCR_W, SCR_H, SHOWCONSOLE); //��ʼ������
}

