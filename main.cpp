/**
������� ����� �������� ������, ��������� ������������ ���������������:
������, ���, ��� ��������, ���������� �����, � ����� ��������� �������
�������� �������� � ����� ������� ���������� � ������� �� ������ �����.

������ ������ ��������� � ���������� ���������� �������� �� �������� �����,
����� ������������ ����� �������� ���������� ����� �������.

������ ��������, �� ����� ����������� ���������.

�� ����� ���� ������ ��������� �� �������������� � �� ����������� ������, ����� ��������� ����� ����� �����;
��������� ��������� ������� �� ������� ���� ��������� ���������. ��
��������� ����������� ���� ������ ���������� - ������� ������ ��� ���.
���������� ���� ������������ � �������������� ����������� ������������ � �������� ����.
���� ����������� ����� ������������, �� ������ ���� ������ ������ �������� ����.
 */

#include "Client.h"

void ClientCode() {
	Play Match;
	Client *Seeker = nullptr;
	char menu;
	srand(time(NULL));
	while (true)
	{
		try
		{
			system("CLS");
			std::cout << "���� :" << std::endl
				<< "[1] �������� ����������" << std::endl
				<< "[2] ������� ����������" << std::endl
				<< "[3] ������� ������ �����������" << std::endl
				<< "[4] ������� �� �����������" << std::endl
				<< "[5] ��������� �����������" << std::endl
				<< "[6] ��������� �����������" << std::endl
				<< "[7] ���������� ������" << std::endl
				<< "[0] ����� �� ���������" << std::endl
				<< "�����: ";
			std::cin >> menu;
			if (menu > 7 && menu < 0)
				throw (std::string)"������ ������ ����";
			switch (menu)
			{
			case '1':
				Match.Add();
				break;
			case '2':
				Match.Del();
				break;
			case '3':
				Match.Print();
				break;
			case '4':
				if (!Seeker)
					Seeker = new Client(Match.getSportsman());
				else
				{
					Seeker->Subscribe(Match.getSportsman());
				}
				break;
			case '5':
				Match.Load();
				break;
			case '6':
				Match.Save();
				break;
			case '7':
				Match.Start();
				break;
			case '0':
				delete Seeker;
				return;
			default:
				break;
			}
			system("pause>>null");
		}
		catch (std::string err)
		{

		}
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	ClientCode();
	return 0;
}