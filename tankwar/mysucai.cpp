#include "mysucai.h"
char* wall_pic[] = { "  ", "��", "�d", "��", "��", "��", "��", "��" };
char* tank_pic[] = { "  ", "��", "��", "��", "��", "��" };
char* bullet_pic[] = { "  ", "��", "��", "��", "��", "��", "��", "��", "��", "��"};//̹����״
int singlegame[] = { play1, 0, enemy3, enemy4, enemy5 };
int doublegame[] = { play1, play2, enemy3, enemy4, enemy5 };
int m_targets;
int m_target=5;
int m_boardtype;
int player1_score=0;
int player2_score=0;
int player1life;
int player2life;
