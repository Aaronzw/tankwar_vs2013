#include "mysucai.h"
#include "game.h"
#include<conio.h>
game::game()
{
}
game::~game()
{
}
void game::initgamewindow()
{
	//���ô��ڴ�С�ͱ���
	m_draw.setwindowssize("Tank War v0.1", 100, 39);
	while (true)
	{
		char ch;
		m_draw.drawmenu();
		getinput(ch,menu,true);
	}
}
void game::initsingleplayergame()
{
	m_draw.drawmap();
	tank::stank stank{ 0, 13, 37, 10, 1 };
	m_tank.inittankinfo(stank);
	m_draw.drawtank(0, 13, 37, "��", tank_pic[1]);
}
bool game::singleplayerloop()
{
	DWORD dwplayerbegin = GetTickCount(), dwbullebegin = GetTickCount(), dwplayerend, dwbulletend;
	while (true)
	{
		dwplayerend = GetTickCount();
		if (dwplayerend - dwplayerbegin > 100)
		{
			dwplayerbegin = dwplayerend;
			player1time();
		}
		dwbulletend = GetTickCount();
		if (dwbulletend-dwbullebegin>50)
		{
			dwbullebegin = dwbulletend;
			bullet1time();
		}
		//ʣ�µĽ����о�����
	}
	return false;
}
void game::initdoubleplayergame()
{
	initsingleplayergame();
	tank::stank stank2{ 0, 27, 37, 10, 1 };
	m_tank2.inittankinfo(stank2);
	m_draw.drawtank(0, 27, 37, "��", tank_pic[2]);
}
bool game::doubleplayerloop()
{
	DWORD dwplayerbegin = GetTickCount(), dwbulletbegin = GetTickCount(),
		dwplayerend, dwbulletend;
	while (true)
	{
		dwplayerend = GetTickCount();
		if (dwplayerend - dwplayerbegin > 100)
		 {
			dwplayerbegin = dwplayerend;
			player1time();
			player2time();
		}
		dwbulletend = GetTickCount();
		if (dwbulletend - dwbulletbegin > 50)
		{
			dwbulletbegin = dwbulletend;
			bullet1time();
			bullet2time();
		}
		
		//ʣ�µĽ����о�����
	}
	return false;
}
bool game::player1time()
{
	char ch;
	m_draw.cleartank(m_tank.m_obj.ndirection, m_tank.m_obj.nx, m_tank.m_obj.ny);
	setmapvaluetank(m_tank.m_obj.nx, m_tank.m_obj.ny, 0);
	getinput(ch, control,true);
	m_draw.drawtank(m_tank.m_obj.ndirection, m_tank.m_obj.nx, m_tank.m_obj.ny, "��", tank_pic[1]);
	setmapvaluetank(m_tank.m_obj.nx, m_tank.m_obj.ny, m_tank.m_obj.nid);
	return true;
}
bool game::player2time()
{
	char ch;
	m_draw.cleartank(m_tank2.m_obj.ndirection, m_tank2.m_obj.nx, m_tank2.m_obj.ny);
	setmapvaluetank(m_tank2.m_obj.nx, m_tank2.m_obj.ny, 0);
	getinput(ch, control,false);
	m_draw.drawtank(m_tank2.m_obj.ndirection, m_tank2.m_obj.nx, m_tank2.m_obj.ny, "��", tank_pic[2]);
	setmapvaluetank(m_tank2.m_obj.nx, m_tank2.m_obj.ny, m_tank2.m_obj.nid);
	return true;
}
bool game::getinput(_Out_ char &KEYDOWN, _In_ int leixing, bool isplayer1)
{
	if (leixing == control)
	{
		if (isplayer1==true)
		{
			if (KEYDOWN('w') || KEYDOWN('W'))
			{
				if (tankmovecrash(UP, m_tank))
				{
					m_tank.tankmove(UP);
				}
			}
			if (KEYDOWN('S') || KEYDOWN('s'))
			{
				if (tankmovecrash(DOWN, m_tank))
				{
					m_tank.tankmove(DOWN);
				}
			}
			if (KEYDOWN('A') || KEYDOWN('a'))
			{
				if (tankmovecrash(LEFT, m_tank))
				{
					m_tank.tankmove(LEFT);
				}
			}
			if (KEYDOWN('D') || KEYDOWN('d'))
			{
				if (tankmovecrash(RIGHT, m_tank))
				{
					m_tank.tankmove(RIGHT);
				}
			}
			if (KEYDOWN(VK_SPACE))
			{
				bullet bullet_;
				if (createbullet(m_tank, BULLET_ID_MINE, bullet_))
				{
					m_vecbullet1.push_back(bullet_);
					m_draw.drawbullet(bullet_.m_obj.nx, bullet_.m_obj.ny, bullet_pic[1]);
					setmapvaluebullet(bullet_.m_obj.nx, bullet_.m_obj.ny, BULLET_ID_MINE);
				}
			}
			if (KEYDOWN(VK_ESCAPE))
			{
				initgamewindow();
			}
			return true;
		}
		if (isplayer1==false)
		{
			if (KEYDOWN('i') || (KEYDOWN('I')))
			{
				if (tankmovecrash(UP, m_tank2))
				{
					m_tank2.tankmove(UP);
				}
			}
			if (KEYDOWN('K') || KEYDOWN('k'))
			{
				if (tankmovecrash(DOWN, m_tank2))
				{
					m_tank2.tankmove(DOWN);
				}
			}
			if (KEYDOWN('j') || KEYDOWN('J'))
			{
				if (tankmovecrash(LEFT, m_tank2))
				{
					m_tank2.tankmove(LEFT);
				}
			}
			if (KEYDOWN('L') || KEYDOWN('l'))
			{
				if (tankmovecrash(RIGHT, m_tank2))
				{
					m_tank2.tankmove(RIGHT);
				}
			}
			if (KEYDOWN(VK_ESCAPE))
			{
				initgamewindow();
			}
			if (KEYDOWN('o') || KEYDOWN('O'))
			{
				bullet bullet_2;
				if (createbullet(m_tank2, BULLET_MINE, bullet_2))
				{
					m_vecbullet2.push_back(bullet_2);
					m_draw.drawbullet(bullet_2.m_obj.nx, bullet_2.m_obj.ny, bullet_pic[2]);
					setmapvaluebullet(bullet_2.m_obj.nx, bullet_2.m_obj.ny, BULLET_MINE);
				}
			}
		}
	}
	else if (leixing==menu)
	{
		if (KEYDOWN('1'))
		{
			issingle = true;
			initsingleplayergame();
			singleplayerloop();
		}
		if (KEYDOWN('2'))
		{
			issingle = false;
			initdoubleplayergame();
			doubleplayerloop();
		}
		if (KEYDOWN('3'))
		{
			
		}
		if (KEYDOWN('4'))
		{
			exit(0);
		}
	}
	return true;
}
bool game::bullet1time()
{
	for (UINT i = 0; i < m_vecbullet1.size();i++)
	{
		bullet &bullet_1 = m_vecbullet1[i];
		m_draw.clearbullet(bullet_1.m_obj.nx, bullet_1.m_obj.ny);
		setmapvaluebullet(bullet_1.m_obj.nx, bullet_1.m_obj.ny, 0);
		CPoint ptforward;
		bullet_1.getforwardpoint(ptforward);
		if (bulletcrashall(ptforward))
		{
			m_vecbullet1.erase(m_vecbullet1.begin() + i);
			i--;
		}
		else
		{
			bullet_1.bulletmove();
			m_draw.drawbullet(bullet_1.m_obj.nx, bullet_1.m_obj.ny, bullet_pic[1]);
			setmapvaluebullet(bullet_1.m_obj.nx, bullet_1.m_obj.ny, bullet_1.m_obj.nid | OBJ_TYPE_BULLET);
		}
	}
	return true;
}
bool game::bullet2time()
{
	for (UINT i = 0; i < m_vecbullet2.size(); i++)
	{
		bullet &bullet_2 = m_vecbullet2[i];
		m_draw.clearbullet(bullet_2.m_obj.nx, bullet_2.m_obj.ny);
		setmapvaluebullet(bullet_2.m_obj.nx, bullet_2.m_obj.ny, 0);
		CPoint ptforward;
		bullet_2.getforwardpoint(ptforward);
		if (bulletcrashall(ptforward))
		{
			m_vecbullet2.erase(m_vecbullet2.begin() + i);
			i--;
		}
		else
		{
			bullet_2.bulletmove();
			m_draw.drawbullet(bullet_2.m_obj.nx, bullet_2.m_obj.ny, bullet_pic[2]);
			setmapvaluebullet(bullet_2.m_obj.nx, bullet_2.m_obj.ny, bullet_2.m_obj.nid | OBJ_TYPE_BULLET);
		}
	}
	return true;
}
bool game::tankmovecrash(DWORD dwdir,tank &tank_)
{
	CPoint pt[3] = {};
	if (dwdir != tank_.m_obj.ndirection)
	{
		return true;
	}
	else
	{
		tank_.getthreepoint(pt);
	}
	for (int i= 0; i < 3;i++)
	{
		if (m_draw.m_gnmap[pt[i].y][pt[i].x])
		{
			return false;
		}
	}
	return true;
}
void game::setmapvaluetank(int x, int y, int nvalue)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_draw.m_gnmap[y - 1 + i][x - 1 + j] = nvalue;
		}
	}
}
void game::setmapvaluebullet(int x, int y, int nvalue)
{
	m_draw.m_gnmap[y][x] = nvalue;
}
bool game::createbullet(tank &tank_, unsigned int nid, bullet &bullet_)
{
	CPoint pt[3] = {};
	tank_.getthreepoint(pt);
	bullet_ = { tank_.m_obj.ndirection, (unsigned int)pt[0].x, (unsigned int)pt[0].y, nid };
	if (!bulletcrashall(pt[0]))
	{
		return true;
	}
	return false;
}
bool game::bulletcrashall(CPoint &ptbullet)
{
	int &nvalue = m_draw.m_gnmap[ptbullet.y][ptbullet.x];
	if (!nvalue)
	{
		return false;
	}
	if (nvalue&OBJ_TYPE_WALL)
	{
		bulletcrashwall(nvalue, ptbullet);
	}
	else if (nvalue&OBJ_TYPE_TANK)
	{
		//�ӵ�ײ̹�˵ļ�⺯��
	}
	return true;
}
bool game::bulletcrashwall(int &nvalue, CPoint &ptbullet)
{
	if (nvalue&WALL_ID_DIA)
	{
		return true;
	}
	else
	{
		nvalue--;
		if ((nvalue&WALL_BLOOD)==0)
		{
			nvalue = 0;
			m_draw.drawblank(ptbullet.x, ptbullet.y);
		}
	}
	return true;
}

