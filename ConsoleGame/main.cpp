#include "pch.h"


void Init();	// ����
void Input();	// ������� �Է��� �޴´�(�Է�)
void Update();	// ���� ������ ������Ʈ�Ѵ�(�ݿ�)
void Render();	// ȭ�鿡 ����Ѵ�(ǥ��)

bool shutdownFlag = false;

GameObject* player = new Player();
GameObject* enemy = new Enemy();

int main()
{
	Init();

	while (!shutdownFlag)
	{
		Input();
		Update();
		Render();
		//Sleep(20);
	}

	cout << "Exit Games" << endl;

	return 0;
}

void Init()
{
	_wsetlocale(LC_ALL, L"korean");	// L : long string(�� ���ڿ�)
	// _w : wide
	//SBCS > 1Byte ǥ��, ASCII
	//MBCS > 1~4Bytes ǥ��, ex:UTF-8
	//WBCS > 2Bytes ǥ��, ex:UTF-16(_w)
	Time::Initialize();
	Renderer::Initialize(60,35);
}

void Input()
{
	// 0x8000		ȣ�� �������� ���� ����(key-down)
	// 1(0x0001)	������ ���� ���� �ְ�(key-up)
	/*
		0x8000
	+	0x0001
	----------
		0x8001		(key-press)
	*/
	/*
	SHORT keyState = GetAsyncKeyState('K');
	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
	{
		shutdownFlag = true;
	}

	if (keyState)
	{
		//cout << keyState << endl;
		printf("%n%x", keyState);
	}*/

	Input::Update();
}

void Update()
{
	Time::Update();
	GameObject::StartAll();
	GameObject::UpdateAll();
	GameObject::GarbageCollect();
	/*
	if (Input::GetKey(Keys::ArrowUp))
	{
		printf("��");
	}
	if (Input::GetKey(Keys::ArrowDn))
	{
		printf("��");
	}
	if (Input::GetKey(Keys::ArrowRt))
	{
		printf("��");
	}
	if (Input::GetKey(Keys::ArrowLt))
	{
		printf("��");
	}
	*/
}

void Render()
{
	Renderer::Render();
	/*
	string str = "     ";
	for (int i = 0; i < 5; i++)
	{
		str.push_back('*');
		printf("%s\n", str.substr(str.size() - 5, str.size()).c_str());
	}
	*/

	/*
	int k = 5;
	for (int i=0;i<5;i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (5 - j < k)
			{
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	*/
	/*
	char arr[25] = {
		 0, 1, 2, 3, 4,
		 5, 6, 7, 8, 9,
		10,11,12,13,14,
		15,16,17,18,19,
		20,21,22,23,24
	};

	int w = 3;
	int h = 4;

	for (int i = 0; i < h;i++) {
		//1 2 3 4
		for (int j = 0; j < w; j++)
		{ //3 6 9 12
			// x,y ��ǥ�� ����������
			// 1���� �迭�� ����(index)�Ͽ� �������� ã�´�
			// 2���� ȭ�鿡 �׸���
			int index = i * w + j;
		}
	}
	*/
}