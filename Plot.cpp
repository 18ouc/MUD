#include "Plot.h"
#include <fstream>
#include <iostream>
#include "Magicitem.h"
#include <regex>
#include <sstream>
#include <queue>
using namespace std;
Plot::Plot() {
}

Plot::~Plot() {
}

void Plot::init_new(Sorcerer * mySorcerer) {
	//File myFiles("myFiles.txt");
	string op;
	string name;
	cout << "��������Ҫ���õĽ�ɫ���֣�" << endl;
	cin >> name;
	while (1) {
		cout << "��ѡ��������õ��������Լӳ�:" << endl;
		cout << "1.սʿϵ		 2.̹��ϵ 			3.����ϵ" << endl;
		cin >> op;
		if (op == "1") {
			mySorcerer->setValue(100, 120, 100, 100, 100, name, 3000);
			break;
		}
		else if (op == "2") {
			mySorcerer->setValue(100, 100, 120, 100, 100, name, 3000);
			break;
		}
		else if (op == "3") {
			mySorcerer->setValue(100, 100, 100, 120, 100, name, 3000);
			break;
		}
		else {
			cout << "����������������룡" << endl;
		}
	}
	//File myFile(name + ".txt");
	ofstream tempFile(name + ".txt");
	ofstream outFiles("myFiles.txt", ios::out | ios::app);
	system("cls");
	tempFile << mySorcerer->getDisguiseValue() << " "
		<< mySorcerer->getForceValue() << " "
		<< mySorcerer->getDefenceValue() << " "
		<< mySorcerer->getMagicValue() << " "
		<< mySorcerer->getBloodValue() << " "
		<< mySorcerer->getMoney() << " "
		<< mySorcerer->getName() << " "
		<< 0 << " "
		<< 0 << " "
		<< 0 << " "
		<< 0 << " "
		<< 1 << " ";
	outFiles << name + ".txt" << endl;
	tempFile.close();
	outFiles.close();
}






int Plot::init1(Sorcerer * mySorcerer, int myCheckPoint, bool ifNew) {	//��һ��
	//���ؾ����ʽ����¼
	//Сҩˮ��Ŀ ��ҩˮ��Ŀ ��ҩˮ��Ŀ ���� ifPassMaze  roomNum 0���� 1У���� 2��¥ 3��Ѩ�ĸ���ͼ�Ľ������
	//bool end = 0;	//
	//�����͵�����
	if (ifNew == 0) {
		cout << "ħ��ʦ�ǣ�Ϊ�������Ǳ�ø���ǿ�����Ǹ�����һ�����" << endl;
		Magicitem magicStick("ħ����", 1);
		mySorcerer->addMagicitem(magicStick);
		//��ʽ������
		system("pause");
		system("cls");
	}
	//��ʼ������
	Horcrux ring("�����ޡ����صĽ�ָ");
	//ҩˮ���� 1��2��2С
	//ҩˮ��Ŀ��Ҫ����һ����¼ ��¼�ĸ�ʽΪ X X X�ֱ�ָС�д�
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	if (ifNew == 0) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
	}
	//�����＼������
	//������׻��������䣩:Protego ��15 600 ��������������������� : Densaugeo��12  400
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Protego("Protego", 15, 600);
	Skill Densaugeo("Densaugeo", 12, 400);
	if (myCheckPoint == 0) {
		skill.push_back(Protego);
		skill.push_back(Densaugeo);
	}
	//��������
	//����ħ����������
	Skill Alohomora("Alohomora", 60);
	//һЩ�ж�
	bool check = 1;		//�ж��Ƿ�ͨ��
	bool ifKillKerberos = 0;	//�ж��Ƿ�����ͷ��
	//���صص�����
	Room hall("����");
	Room President_Office("У����");
	Room Crypt("��Ѩ");
	Room Attic("��¥");
	int roomNum = 0; //���浱ǰ���ڵķ����
	//�����ȵ���һ���ص�
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	//��ͼ���� ���Ϊ0���� 1У���� 2��¥ 3��Ѩ
	Map map("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*����\t*\t<--------------->\t*��¥\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t   /\\\t\t\t\t\t   /\\\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   \\/\t\t\t\t\t   \\/\n\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*У����\t*\t\t\t\t*��Ѩ\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********");
	if (myCheckPoint == 0) {
		//���ֱ�������
		cout << "��С���������������Ĺ�������\n��������һ���˵�����������\nȻ������11����������\n�������ص�֪���Լ�ԭ������ʦ\n���ұ�¼ȡΪ�����ִ�ħ��ѧУ�е�һԱ��\n���ϻ����ִ��ؿ��г�\n������ʼ������ħ���ó�������������䷢����ħ��ʯ�����ܡ�����������" << endl;
		//��ʽ������
		system("pause");
		system("cls");
		//���ֱ�������
		cout << "��ӭ�����һ��~" << endl;
		cout << "��ϲ���ڿ��ֻ����һ����������ͨ��������ĳ������..." << endl;
	}
	//��������
	GoodPerson Dumbledore("�˲�����", "���쾵�Ӿ�Ҫ�ᵽһ���µĵط��ˣ������������㲻Ҫ��ȥ�����ˡ�������������ɿ���������Ҫ������׼����\n");
	President_Office.addGoodPerson(Dumbledore);
	BadPerson Chiro(100, 30, 45, "����");
	BadPerson Kerberos(50, 15, 20, "��ͷ��");
	Crypt.addBadPerson(Chiro);
	//ʹ��pair��
	pair<string, int> hallWithNum("����", 0);
	pair<string, int> President_OfficeWithNum("У����", 1);
	pair<string, int> AtticWithNum("��¥", 2);
	pair<string, int> CryptWithNum("��Ѩ", 3);
	//�ж���ͨ���	link[A][B] = 1����A->B��ͨ��
	//�ڽӾ���
	bool link[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			link[i][j] = 0;
	}
	link[hallWithNum.second][President_OfficeWithNum.second] = 1;
	link[President_OfficeWithNum.second][hallWithNum.second] = 1;
	link[hallWithNum.second][AtticWithNum.second] = 1;
	link[AtticWithNum.second][hallWithNum.second] = 1;
	link[AtticWithNum.second][CryptWithNum.second] = 1;
	link[CryptWithNum.second][AtticWithNum.second]= 1;

	if (ifNew == 1) {
		cout << "��ӭ���ٴν�����Ϸ������������һ�ص����̡�" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//ҩˮ��ʼ��
		int medicineNum = 0;
		infile >> medicineNum;
		string medicineName = " ";
		int recoverValue = 0;
		int medicinePirce = 0;
		for (int i = 0; i < medicineNum; i++) {
			infile >> medicineName >> recoverValue >> medicinePirce;
			tempMedicine.setInformation(medicineName, recoverValue, medicinePirce);
			medicine.push_back(tempMedicine);
		}
		//���ܳ�ʼ��
		int skillNum = 0;
		infile >> skillNum;
		string skillName = " ";
		int skillDamage = 0;
		int skillPrice = 0;
		for (int i = 0; i < skillNum; i++) {
			infile >> skillName >> skillDamage >> skillPrice;
			tempSkill.setValue(skillName, skillDamage, skillPrice);
			skill.push_back(tempSkill);
		}
		//���������ʼ��
		infile >> ifKillKerberos >> roomNum;
		bool tempIsInRoom = 0;
		infile >> tempIsInRoom;
		hall.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		President_Office.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		Attic.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		Crypt.setIfIn(tempIsInRoom);
		if (roomNum == 0) {
			mySorcerer->inRoom(&hall);
		}
		else if (roomNum == 1) {
			mySorcerer->inRoom(&President_Office);
		}
		else if (roomNum == 2) {
			mySorcerer->inRoom(&Attic);
		}
		else if (roomNum == 3) {
			mySorcerer->inRoom(&Crypt);
		}
	}
	Shop shop(medicine, skill, "��Ƥʿħ����Ʒ��", medicine.size(), skill.size());
	//��Ҫ����
	while (check) {
		//�������Ϸ������
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//��ʽ������
			system("cls");
		}
		system("pause");//��ʽ������
		system("cls");
		//��ʾ������
		cout << "���� �鿴���� ���Բ鿴��ǰ�Լ�������" << endl;
		cout << "���� ����ҩƷ ���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�ħ������" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�еļ���" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ��ռ��Ļ���" << endl;
		cout << "���� ������� ���Խ���ؿ��ĵ���" << endl;
		cout << "���� ������� ���Ա��浱ǰ����" << endl;
		cout << "���� �˳���Ϸ �����˳���ǰ��Ϸ" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << mySorcerer->getRoom()->getName() << endl;
		cout << "�����ͼ�Ϸ�������ֿ��Խ���÷���" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map.showMap();
		cout << "���������ѡ��:" << endl;
		//ѡ��Ϊop
		string op = " ";
		cin >> op;
		if (op == "�鿴����") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "����ҩƷ") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "�鿴���� ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "�������") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "�������") {
			mySorcerer->setMyCheckPoint(1);
			//�ļ�����
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//����ùؿ��Ľ���
			ofstream tempFile;
			ofstream stateFile;
			//��Ϣ�������
			//����������Ϣ����
			tempFile.open(mySorcerer->getName() + ".txt");
			tempFile << mySorcerer->getDisguiseValue() << " "
				<< mySorcerer->getForceValue() << " "
				<< mySorcerer->getDefenceValue() << " "
				<< mySorcerer->getMagicValue() << " "
				<< mySorcerer->getBloodValue() << " "
				<< mySorcerer->getMoney() << " "
				<< mySorcerer->getName() << endl;
			tempFile << mySorcerer->getMagicitemNum() << " ";
			for (int i = 0; i < mySorcerer->getMagicitemNum(); i++) {
				tempFile << mySorcerer->getMagicitem()[i].getName() << " " << mySorcerer->getMagicitem()[i].getId() << endl;
			}
			tempFile << mySorcerer->getHorcruxNum() << " ";
			for (int i = 0; i < mySorcerer->getHorcruxNum(); i++) {
				tempFile << mySorcerer->getHorcrux()[i].getName() << " " << mySorcerer->getHorcrux()[i].getId() << endl;
			}
			tempFile << mySorcerer->getSkillNum() << " ";
			for (int i = 0; i < mySorcerer->getSkillNum(); i++) {
				tempFile << mySorcerer->getSkill()[i].getName() << " " << mySorcerer->getSkill()[i].getDamage() << endl;
			}
			tempFile << mySorcerer->getMedicineNum() << " ";
			for (int i = 0; i < mySorcerer->getMedicineNum(); i++) {
				tempFile << mySorcerer->getMedicine()[i].getName() << " " << mySorcerer->getMedicine()[i].getRecoverValue() << " " << mySorcerer->getMedicine()[i].getPrice() << endl;
			}
			tempFile << mySorcerer->getMyCheckpoint()  << endl;
			cout << "����������Ϣ����ɹ�!" << endl;
			//�ؿ���Ϣ����
			stateFile.open(mySorcerer->getName() + "State" + ".txt");
			stateFile << shop.getMedicineNum() << " ";
			for(int i = 0; i < shop.getMedicineNum(); i++) {
				stateFile << shop.getMedicine()[i].getName() << " "
					<< shop.getMedicine()[i].getRecoverValue() << " "
					<< shop.getMedicine()[i].getPrice() << endl;
			}
			stateFile << shop.getSkillNum() << " ";
			for (int i = 0; i < shop.getSkillNum(); i++) {
				stateFile << shop.getSkill()[i].getName() << " "
					<< shop.getSkill()[i].getDamage() << " "
					<< shop.getSkill()[i].getPrice() << endl;
			}
			stateFile << ifKillKerberos << " " << roomNum << endl;
				//0���� 1У���� 2��¥ 3��Ѩ�ĸ���ͼ�Ľ������
			stateFile << hall.getIfIn() << " "
				<< President_Office.getIfIn() << " "
				<< Attic.getIfIn() << " "
				<< Crypt.getIfIn() << endl;
			//	//����
			mySorcerer->setMyCheckPoint(1);
			cout << "�ùؿ�״̬��Ϣ����ɹ���" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "�˳���Ϸ") {
			cout << "���Ѿ���������Ϸ��" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "����" && roomNum == hallWithNum.second || op == "��Ѩ" && roomNum == CryptWithNum.second || op == "��¥" && roomNum == AtticWithNum.second || op == "У����" && roomNum == President_OfficeWithNum.second) {
			system("cls");
			cout << "���Ѿ��ڸ�λ�ã�" << endl;
			//��ʽ������	
		}
		else if (op == "У����" && link[roomNum][President_OfficeWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&President_Office);
			system("cls");
			cout << "��ӭ���� " << President_Office.getName() << endl;
			if (President_Office.getIfIn()) {
				cout << "��ӭ���ٴ����� " << President_Office.getName() << endl;
			}
			else {
				cout << "\n" << Dumbledore.getName() << "��" << Dumbledore.getSentence() << endl;
				cout << "����" << Dumbledore.getName() << "������̸��֮�� �����һ�����" << endl;
				mySorcerer->addSkill(Alohomora);
				President_Office.inRoom();
			}
		}
		else if (op == "У����" && !link[roomNum][President_OfficeWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ���У���ң�����ϸ�۲��ͼ��" << endl;
			cout << "��Ŀǰ�ܵ����λ���У�" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;

					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
						/*if (link[tmp.x][tmp.y] == 1)
							cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == President_OfficeWithNum.second) {
								cout << President_Office.getName() << endl;
							}
							else if (tmp.y == AtticWithNum.second) {
								cout << Attic.getName() << endl;
							}
							else if (tmp.y == CryptWithNum.second) {
								cout << Crypt.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "��¥" && link[roomNum][AtticWithNum.second]) {
			mySorcerer->inRoom(&Attic);
			roomNum = 2;
			system("cls");
			if (Attic.getIfIn()) {
				cout << "��ӭ���ٴ����� " << Attic.getName() << endl;
			}
			else {
				cout << "��ӭ���� " << Attic.getName() << endl;
				cout << "��ʱ��ͷ�����ڿ���ĳ�����䣬���Ƿ�ѡ����������ս����" << endl;
				cout << "1.��		2.��" << endl;
				int op_Attic = 0;
				cin >> op_Attic;
				system("cls");
				if (op_Attic == 1) {
					cout << "ս���Ѿ���ʼ��" << endl;
					bool ifWin = 1;
					ifWin = mySorcerer->battle(mySorcerer, Kerberos);
					if (ifWin) {
						system("pause");
						system("cls");
						cout << "��ͨ��ս�����ɽ����" << Kerberos.getName() << "����������ܽ����Ѩ������......" << endl;
						Attic.inRoom();
						ifKillKerberos = 1;
					}
					else {
						mySorcerer->setBlood(0);
						//�����
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&hall);
						roomNum = 0;
					}
				}
				else {
					cout << "��ɹ�����������" << endl;
					mySorcerer->inRoom(&hall);
					roomNum = 0;
				}
			}
		}
		else if (op == "��¥" && !link[roomNum][AtticWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ����¥������ϸ�۲��ͼ��" << endl;
			cout << "��Ŀǰ�ܵ����λ���У�" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;

					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*	if (link[tmp.x][tmp.y] == 1)
							cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == President_OfficeWithNum.second) {
								cout << President_Office.getName() << endl;
							}
							else if (tmp.y == AtticWithNum.second) {
								cout << Attic.getName() << endl;
							}
							else if (tmp.y == CryptWithNum.second) {
								cout << Crypt.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "��Ѩ" && link[roomNum][CryptWithNum.second]) {
			system("cls");
			if (ifKillKerberos) {
				roomNum = 3;
				mySorcerer->inRoom(&Crypt);
				cout << "ͨ������������˵�Ѩ��" << endl;
				cout << "��ӭ������Ѩ~" << endl;
				cout << "��ʱ�������ھ����ԣ����Ƿ�ѡ����������ս����" << endl;
				cout << "1.��		2.��" << endl;
				int op_Crypt = 0;
				cin >> op_Crypt;
				system("cls");
				if (op_Crypt == 1) {
					bool ifWin = 0;
					cout << "ս����ʼ�����ѽ���ս��ģʽ..." << endl;
					ifWin = mySorcerer->battle(mySorcerer, Chiro);
					if (ifWin) {
						cout << "��ϲ��ɹ�ͨ����һ�ز������1000��Һ�һ��������" << endl;
						mySorcerer->increaseMoney(1000);
						mySorcerer->addHorcrux(ring);
						check = 0;
						system("pause");
						system("cls");
					}
					else {
						mySorcerer->inRoom(&hall);
						mySorcerer->setBlood(0);
						//�����
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n"  << endl;
						system("pause");
						system("cls");
					}
				}
				else if (op_Crypt == 2) {
					cout << "���Ѿ�����ս����" << endl;
					mySorcerer->inRoom(&Attic);
					roomNum = 2;
				}
				else {
					cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
					mySorcerer->inRoom(&Attic);
					roomNum = 2;
				}
			}
			else {
				cout << "������û�д����ͷ�����޷������Ѩ" << endl;
			}
		}
		else if (op == "��Ѩ" && !link[roomNum][CryptWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ����Ѩ������ϸ�۲��ͼ��" << endl;
			cout << "��Ŀǰ�ܵ����λ���У�" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()){
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;

					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*	if(link[tmp.x][tmp.y] == 1)
							cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == President_OfficeWithNum.second) {
								cout << President_Office.getName() << endl;
							}
							else if (tmp.y == AtticWithNum.second) {
								cout << Attic.getName() << endl;
							}
							else if (tmp.y == CryptWithNum.second) {
								cout << Crypt.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������	
		}
		else if (op == "����" && link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "��ӭ��������~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&hall);
		}
		else if (op == "����" && !link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������������ϸ�۲��ͼ��" << endl;
			cout << "��Ŀǰ�ܵ����λ���У�" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;

					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
						/*if (link[tmp.x][tmp.y] == 1)
							cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == President_OfficeWithNum.second) {
								cout << President_Office.getName() << endl;
							}
							else if (tmp.y == AtticWithNum.second) {
								cout << Attic.getName() << endl;
							}
							else if (tmp.y == CryptWithNum.second) {
								cout << Crypt.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������	
		}
		else {
			system("cls");
			cout << "����ʧ�ܣ�" << endl;
			//��ʽ������	
		}
	}
	return 1;
}




int Plot::init2(Sorcerer *mySorcerer, int myCheckPoint, bool ifNew) {
	//���ؾ����ʽ����¼
	//Сҩˮ��Ŀ ��ҩˮ��Ŀ ��ҩˮ��Ŀ ���� ifKillKerberos roomNum 0���� 1У���� 2��¥ 3��Ѩ�ĸ���ͼ�Ľ������
	//ҩˮ���� 2��2��2С
	//ҩˮ��Ŀ��Ҫ����һ����¼ ��¼�ĸ�ʽΪ X X X�ֱ�ָС�д�
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	if (ifNew == 0) {
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempLarge);
	}
	//�����＼������
	//����������ܣ������䣩:Incendio��15  600
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Incendio("Incendio", 15, 800);
	if (myCheckPoint != 2) {
		skill.push_back(Incendio);
	}
	//һЩ�ж�
	bool check = 1;
	//һЩװ��
	Magicitem phoenix("���", 2);
	//����
	Horcrux diary("��ķ����¶����ռ�");
	//���صص�����
	Room Crypt("��Ѩ");
	Room bathroom("ϴ�ּ�");
	Room hathouse("ñ����");
	Room chamber("����");
	int roomNum = 0;
	mySorcerer->inRoom(&Crypt);
	//��ͼ���� 0��Ѩ 1ϴ�ּ� 2ñ���� 3����
	Map map("\t*********\t\t\t\t*********\t\t\t*********\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*��Ѩ\t*\t<--------------->\t*ϴ�ּ�\t*\t<---------->\t*����\t*\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t*********\n\t  /\\\t\t\t\t\t   /\\\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t*********\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*ñ����\t*<===================================\n\t*\t*\n\t*********");
	if (ifNew == 0) {
		//���ֱ�������
		cout << "ѧУ������һϵ�С��ֲ����¼���ѧ��Ī�����ʯ��\nǽ�ϳ����˿ֲ���Ѫ��...\n���ǻ������߹���Ϊ\n��˵�е����ұ�˹�����ֵļ̳��˴�\n������Ϊ������ǻ�������˻��ɡ�������������" << endl;
		system("pause");
		system("cls");
		cout << "��ӭ����ڶ���~" << endl;
		cout << "��˵��ϴ�ּ���ҽ���Ի����Ի�����صĶ���..." << endl;
	}
	//��������
	GoodPerson Moaning_Myrtle("�ҽ���", "��ϴ����������Ķ���...��ʱ�Ҿ�����Ϊ���������۾���...\n");
	bathroom.addGoodPerson(Moaning_Myrtle);
	BadPerson Basilisk(100, 20, 30, "�߹�");
	chamber.addBadPerson(Basilisk);
	//ʹ��pair��
	pair<string, int> CryptWithNum("��Ѩ", 0);
	pair<string, int> bathroomWithNum("ϴ�ּ�", 1);
	pair<string, int> hathouseWithNum("ñ����", 2);
	pair<string, int> chamberWithNum("����", 3);
	//�ж���ͨ���	link[A][B] = 1����A->B��ͨ��
	//�ڽӾ���
	bool link[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			link[i][j] = 0;
	}
	link[CryptWithNum.second][bathroomWithNum.second] = 1;
	link[bathroomWithNum.second][CryptWithNum.second] = 1;
	link[bathroomWithNum.second][chamberWithNum.second] = 1;
	link[chamberWithNum.second][bathroomWithNum.second] = 1;
	link[bathroomWithNum.second][hathouseWithNum.second] = 1;
	link[hathouseWithNum.second][bathroomWithNum.second] = 1;
	link[hathouseWithNum.second][CryptWithNum.second] = 1;
	link[CryptWithNum.second][hathouseWithNum.second] = 1;
	if (ifNew == 1) {
		cout << "��ӭ���ٴν�����Ϸ�����������ڶ��ص����̡�" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//ҩˮ��ʼ��
		int medicineNum = 0;
		infile >> medicineNum;
		string medicineName = " ";
		int recoverValue = 0;
		int medicinePirce = 0;
		for (int i = 0; i < medicineNum; i++) {
			infile >> medicineName >> recoverValue >> medicinePirce;
			tempMedicine.setInformation(medicineName, recoverValue, medicinePirce);
			medicine.push_back(tempMedicine);
		}
		//���ܳ�ʼ��
		int skillNum = 0;
		infile >> skillNum;
		string skillName = " ";
		int skillDamage = 0;
		int skillPrice = 0;
		for (int i = 0; i < skillNum; i++) {
			infile >> skillName >> skillDamage >> skillPrice;
			tempSkill.setValue(skillName, skillDamage, skillPrice);
			skill.push_back(tempSkill);
		}
		//���������ʼ��
		infile >> roomNum;
		bool tempIsInRoom = 0;
		infile >> tempIsInRoom;
		Crypt.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		bathroom.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		hathouse.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		chamber.setIfIn(tempIsInRoom);
		if (roomNum == 0) {
			mySorcerer->inRoom(&Crypt);
		}
		else if (roomNum == 1) {
			mySorcerer->inRoom(&bathroom);
		}
		else if (roomNum == 2) {
			mySorcerer->inRoom(&hathouse);
		}
		else if (roomNum == 3) {
			mySorcerer->inRoom(&chamber);
		}
	}
	Shop shop(medicine, skill, "��������ħ����Ʒ��", medicine.size(), skill.size());
	while (check) {
		//�������Ϸ������
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//��ʽ������
			system("cls");
		}
		system("pause");
		system("cls");
		cout << "���� �鿴���� ���Բ鿴��ǰ�Լ�������" << endl;
		cout << "���� ����ҩƷ ���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�ħ������" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�еļ���" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ��ռ��Ļ���" << endl;
		cout << "���� ������� ���Խ���ؿ��ĵ���" << endl;
		cout << "���� ������� ���Ա��浱ǰ����" << endl;
		cout << "���� �˳���Ϸ �����˳���ǰ��Ϸ" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << mySorcerer->getRoom()->getName() << endl;
		cout << "�����ͼ�Ϸ�������ֿ��Խ���÷���" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map.showMap();
		cout << "���������ѡ��:" << endl;
		string op = " ";
		cin >> op;
		if (op == "�鿴����") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "����ҩƷ") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "�������") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "�������") {
			mySorcerer->setMyCheckPoint(2);
			//�ļ�����
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//����ùؿ��Ľ���
			ofstream tempFile;
			ofstream stateFile;
			//��Ϣ�������
			//����������Ϣ����
			tempFile.open(mySorcerer->getName() + ".txt");
			tempFile << mySorcerer->getDisguiseValue() << " "
				<< mySorcerer->getForceValue() << " "
				<< mySorcerer->getDefenceValue() << " "
				<< mySorcerer->getMagicValue() << " "
				<< mySorcerer->getBloodValue() << " "
				<< mySorcerer->getMoney() << " "
				<< mySorcerer->getName() << endl;
			tempFile << mySorcerer->getMagicitemNum() << " ";
			for (int i = 0; i < mySorcerer->getMagicitemNum(); i++) {
				tempFile << mySorcerer->getMagicitem()[i].getName() << " " << mySorcerer->getMagicitem()[i].getId() << endl;
			}
			tempFile << mySorcerer->getHorcruxNum() << " ";
			for (int i = 0; i < mySorcerer->getHorcruxNum(); i++) {
				tempFile << mySorcerer->getHorcrux()[i].getName() << " " << mySorcerer->getHorcrux()[i].getId() << endl;
			}
			tempFile << mySorcerer->getSkillNum() << " ";
			for (int i = 0; i < mySorcerer->getSkillNum(); i++) {
				tempFile << mySorcerer->getSkill()[i].getName() << " " << mySorcerer->getSkill()[i].getDamage() << endl;
			}
			tempFile << mySorcerer->getMedicineNum() << " ";
			for (int i = 0; i < mySorcerer->getMedicineNum(); i++) {
				tempFile << mySorcerer->getMedicine()[i].getName() << " " << mySorcerer->getMedicine()[i].getRecoverValue() << " " << mySorcerer->getMedicine()[i].getPrice() << endl;
			}
			tempFile << mySorcerer->getMyCheckpoint() << endl;
			cout << "����������Ϣ����ɹ�!" << endl;
			//�ؿ���Ϣ����
			stateFile.open(mySorcerer->getName() + "State" + ".txt");
			stateFile << shop.getMedicineNum() << " ";
			for (int i = 0; i < shop.getMedicineNum(); i++) {
				stateFile << shop.getMedicine()[i].getName() << " "
					<< shop.getMedicine()[i].getRecoverValue() << " "
					<< shop.getMedicine()[i].getPrice() << endl;
			}
			stateFile << shop.getSkillNum() << " ";
			for (int i = 0; i < shop.getSkillNum(); i++) {
				stateFile << shop.getSkill()[i].getName() << " "
					<< shop.getSkill()[i].getDamage() << " "
					<< shop.getSkill()[i].getPrice() << endl;
			}
			stateFile << roomNum << endl;
			//0��Ѩ 1ϴ�ּ� 2ñ���� 3�����ĸ���ͼ�Ľ������
			stateFile << Crypt.getIfIn() << " "
				<< bathroom.getIfIn() << " "
				<< hathouse.getIfIn() << " "
				<< chamber.getIfIn() << endl;
			//	//����
			mySorcerer->setMyCheckPoint(2);
			cout << "�ùؿ�״̬��Ϣ����ɹ���" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "�˳���Ϸ") {
			cout << "���Ѿ���������Ϸ��" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		//0��Ѩ 1ϴ�ּ� 2ñ���� 3����
		else if (op == "��Ѩ" && roomNum == CryptWithNum.second || op == "ϴ�ּ�" && roomNum == bathroomWithNum.second || op == "ñ����" && roomNum == hathouseWithNum.second || op == "У����" && roomNum == chamberWithNum.second) {
			system("cls");
			cout << "���Ѿ��ڸ�λ�ã�" << endl;
			//��ʽ������	
		}
		else if (op == "ϴ�ּ�" && link[roomNum][bathroomWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&bathroom);
			system("cls");
			if (bathroom.getIfIn()) {
				cout << "��ӭ���ٴ����� " << bathroom.getName() << endl;
			}
			else {
				cout << "��ӭ���� " << bathroom.getName() << endl;
				cout << "\n" << Moaning_Myrtle.getName() << "��" << Moaning_Myrtle.getSentence() << endl;
				cout << "����" << Moaning_Myrtle.getName() << "������̸��֮�� �����Լ�ӵ�����" << endl;
				bathroom.inRoom();
			}
		}
		else if (op == "ϴ�ּ�" && !link[roomNum][bathroomWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ���ϴ�ּ䣬����ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == bathroomWithNum.second) {
								cout << bathroom.getName() << endl;
							}
							else if (tmp.y == hathouseWithNum.second) {
								cout << hathouse.getName() << endl;
							}
							else if (tmp.y == chamberWithNum.second) {
								cout << chamber.getName() << endl;
							}
							else if (tmp.y == CryptWithNum.second) {
								cout << Crypt.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "ñ����" && link[roomNum][hathouseWithNum.second]) {
			roomNum = 2;
			mySorcerer->inRoom(&hathouse);
			system("cls");
			if (hathouse.getIfIn()) {
				cout << "��ӭ���ٴ����� " << hathouse.getName() << endl;
			}
			else {
				cout << "��ӭ���� " << hathouse.getName() << endl;
				cout << "ֻ����������ʿ���ܵõ�" << phoenix.getName() << endl;
				cout << "������������ʿ��" << endl;
				mySorcerer->addMagicitem(phoenix);
				hathouse.inRoom();
			}
		}
		else if (op == "ñ����" && !link[roomNum][hathouseWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ���ñ���ݣ�����ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*if (link[tmp.x][tmp.y] == 1)
					cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == bathroomWithNum.second) {
								cout << bathroom.getName() << endl;
							}
							else if (tmp.y == hathouseWithNum.second) {
								cout << hathouse.getName() << endl;
							}
							else if (tmp.y == chamberWithNum.second) {
								cout << chamber.getName() << endl;
							}
							else if (tmp.y == CryptWithNum.second) {
								cout << Crypt.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "����" && link[roomNum][chamberWithNum.second]) {
			roomNum = 3;
			mySorcerer->inRoom(&chamber);
			system("cls");
			cout << "��ӭ���� " << chamber.getName() << endl;
			cout << "��ʱ��ķ������������Ƿ�ѡ���������жԻ���" << endl;
			cout << "1.��		2.��" << endl;
			int op_chamber = 0;
			cin >> op_chamber;
			system("cls");
			if (op_chamber == 1) {
				cout << "���� Tom Marvolo Riddle������֮���� Lord Voldemort(����ħ)������\n˿˿˹˹~\n��ͨ�������ٻ������߹֡�����" << endl;
				bool ifWin = 1;
				ifWin = mySorcerer->isHasTheMagicitem(2);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "��ͨ����˴�Ϲ��" << Basilisk.getName() << "���۾���������������ս��......" << endl;
					system("pause");
					system("cls");
					cout << "��ʱ����ս���������������Ƿ�ѡ����������ս����" << endl;
					cout << "1.��		2.��" << endl;
					int op_Basilisk = 0;
					cin >> op_Basilisk;
					system("cls");
					if (op_Basilisk == 1) {
						bool ifWin = 0;
						cout << "ս����ʼ�����ѽ���ս��ģʽ..." << endl;
						ifWin = mySorcerer->battle(mySorcerer, Basilisk);
						if (ifWin) {
							cout << "��ϲ��ɹ�ͨ���ڶ��ز������1500��Һ�һ��������";
							mySorcerer->increaseMoney(1500);
							mySorcerer->addHorcrux(diary);
							check = 0;
							system("pause");
							system("cls");
						}
						else {
							mySorcerer->inRoom(&Crypt);
							mySorcerer->setBlood(0);
							//�����
							cout << "\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\n\t\t   �˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\n\t\t   ��\t\t   ��\t\t   ��\t\n\t\t    ��\t\t   ��\t\t  ��\t\n\t\t     ��\t\t   ��\t\t ��\t\n\n\t\t\t\t   ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t\t   ��\n\t\t\t         �˲˲�\n\t\t\t       ��  ��  ��\n\t\t\t     ��    ��    ��\n\t\t\t   ��      ��      ��\n\t\t\t ��        ��        ��\n\t\t       ��          ��          ��\n\t\t     ��            ��            ��\n\t\t   ��              ��              ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n" << endl;
							system("pause");
							system("cls");
							mySorcerer->inRoom(&bathroom);
							roomNum = bathroomWithNum.second;
						}
					}
					else if (op_Basilisk == 2) {
						cout << "���Ѿ�����ս����" << endl;
						mySorcerer->inRoom(&bathroom);
						roomNum = bathroomWithNum.second;
					}
					else {
						cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
						mySorcerer->inRoom(&bathroom);
						roomNum = bathroomWithNum.second;
					}
				}
				else {
					cout << "�㱻�������۾���ɱ������\n" << endl;
					mySorcerer->inRoom(&Crypt);
					mySorcerer->setBlood(0);
					//�����
					cout << "\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\n\t\t   �˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\n\t\t   ��\t\t   ��\t\t   ��\t\n\t\t    ��\t\t   ��\t\t  ��\t\n\t\t     ��\t\t   ��\t\t ��\t\n\n\t\t\t\t   ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t\t   ��\n\t\t\t         �˲˲�\n\t\t\t       ��  ��  ��\n\t\t\t     ��    ��    ��\n\t\t\t   ��      ��      ��\n\t\t\t ��        ��        ��\n\t\t       ��          ��          ��\n\t\t     ��            ��            ��\n\t\t   ��              ��              ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n" << endl;
					system("pause");
					system("cls");
					mySorcerer->inRoom(&bathroom);
					//roomNum = 3;
					roomNum = bathroomWithNum.second;
				}
			}
			else if (op_chamber == 2) {
				cout << "���Ѿ����������Ի���" << endl;
				mySorcerer->inRoom(&bathroom);
				roomNum = bathroomWithNum.second;
			}
			else {
				cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
				mySorcerer->inRoom(&bathroom);
				roomNum = bathroomWithNum.second;
			}
		}
		else if (op == "����" && !link[roomNum][chamberWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������ң�����ϸ�۲��ͼ��" << endl;
			cout << "��Ŀǰ�ܵ���ĵص�Ϊ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*if (link[tmp.x][tmp.y] == 1)
					cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == bathroomWithNum.second) {
								cout << bathroom.getName() << endl;
							}
							else if (tmp.y == hathouseWithNum.second) {
								cout << hathouse.getName() << endl;
							}
							else if (tmp.y == chamberWithNum.second) {
								cout << chamber.getName() << endl;
							}
							else if (tmp.y == CryptWithNum.second) {
								cout << Crypt.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "��Ѩ" && link[roomNum][CryptWithNum.second]) {
			system("cls");
			cout << "��ӭ������Ѩ~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&Crypt);
		}
		else if (op == "��Ѩ" && !link[roomNum][CryptWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ����Ѩ������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*if (link[tmp.x][tmp.y] == 1)
					cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == bathroomWithNum.second) {
								cout << bathroom.getName() << endl;
							}
							else if (tmp.y == hathouseWithNum.second) {
								cout << hathouse.getName() << endl;
							}
							else if (tmp.y == chamberWithNum.second) {
								cout << chamber.getName() << endl;
							}
							else if (tmp.y == CryptWithNum.second) {
								cout << Crypt.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������	
		}
		else {
			system("cls");
			cout << "����ʧ�ܣ�" << endl;
			//��ʽ������	
		}
	}
	return 1;
}






int Plot::init3(Sorcerer * mySorcerer, int myCheckPoint, bool ifNew) {
	//���ؾ����ʽ����¼
	//Сҩˮ��Ŀ ��ҩˮ��Ŀ ��ҩˮ��Ŀ ���� ifKillKerberos roomNum 0���� 1У���� 2��¥ 3��Ѩ�ĸ���ͼ�Ľ������
	
	//ҩˮ����
	Medicine tempMedicine(" ", 0, 0);
	vector<Medicine> medicine;
	Medicine medicineTempSmall("Сҩˮ", 20, 400);	
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	if (ifNew == 0) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
	}
	//�����＼������
	//���������ǣ������䣩:Reducto��20 800
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Reducto("Reducto", 20, 1000);
	if (myCheckPoint != 3) {
		skill.push_back(Reducto);
	}
	//����
	Horcrux locket("��������˹�����ֵĹ�׹��");
	//һЩ�ж�
	bool check = 1;
	bool ifKillPettigrew = 0;
	//���صص����� 0���� 1���� 2���� 3����	
	Room chamber("����");
	Room auditorium("����");
	Room villa("����");
	Room lakes("����");
	int roomNum = 0; //���浱ǰ���ڵķ����
	mySorcerer->inRoom(&chamber);
	Map map("\t*********\t\t\t\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*����\t*\t<--------------->\t*����\t*\t<--------------->\t*����\t*\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t\t*********\n\t  /\\\t\t\t\t\t   /\\\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t*********\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*����\t*====================================\n\t*\t*\n\t*********");
	if (!ifNew) {
		cout << "��֪���ȿ����ﷸС�������ӳ�����\n������������ȥ����Ī��ʱ������������С�����Ǳ����˹����ĸ�ĸ\nʹ���⵽�˷���ħ��ɱ��\n����С�����ǳ��֣���������������-��û�б��й����ĸ�ĸ������С���Ǳ˵ñ��Ѻ�һ������ת�Ƶ����������ϡ�������������������" << endl;
		//��������
		system("pause");
		system("cls");
		cout << "��ӭ���������~" << endl;
	}
	//��������
	GoodPerson Sirius("С������", "�Ҹ�ղķ˹��������һ����ô�ã���ȴû�У��Ǻܲ��̡�...\n");
	GoodPerson Snape("˹����", "����ԶԶû�����������ô�򵥡�\n");
	villa.addGoodPerson(Sirius);
	BadPerson pettigrew(100, 20, 30, "С����");
	BadPerson dementor(150, 30, 40, "����");
	villa.addBadPerson(pettigrew);
	lakes.addBadPerson(dementor);
	//ʹ��pair��
	pair<string, int> chamberWithNum("����", 0);
	pair<string, int> auditoriumWithNum("����", 1);
	pair<string, int> villaWithNum("����", 2);
	pair<string, int> lakesWithNum("����", 3);
	//�ж���ͨ���	link[A][B] = 1����A->B��ͨ��
	//�ڽӾ���
	bool link[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			link[i][j] = 0;
	}
	link[chamberWithNum.second][auditoriumWithNum.second] = 1;
	link[auditoriumWithNum.second][chamberWithNum.second] = 1;
	link[auditoriumWithNum.second][villaWithNum.second] = 1;
	link[villaWithNum.second][auditoriumWithNum.second] = 1;
	//link[auditoriumWithNum.second][lakesWithNum.second] = 0;
	link[lakesWithNum.second][auditoriumWithNum.second] = 1;
	link[lakesWithNum.second][villaWithNum.second] = 1;
	link[villaWithNum.second][lakesWithNum.second] = 1;

	if (ifNew) {
		cout << "��ӭ���ٴν�����Ϸ���������������ص����̡�" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//ҩˮ��ʼ��
		int medicineNum = 0;
		infile >> medicineNum;
		string medicineName = " ";
		int recoverValue = 0;
		int medicinePirce = 0;
		for (int i = 0; i < medicineNum; i++) {
			infile >> medicineName >> recoverValue >> medicinePirce;
			tempMedicine.setInformation(medicineName, recoverValue, medicinePirce);
			medicine.push_back(tempMedicine);
		}
		//���ܳ�ʼ��
		int skillNum = 0;
		infile >> skillNum;
		string skillName = " ";
		int skillDamage = 0;
		int skillPrice = 0;
		for (int i = 0; i < skillNum; i++) {
			infile >> skillName >> skillDamage >> skillPrice;
			tempSkill.setValue(skillName, skillDamage, skillPrice);
			skill.push_back(tempSkill);
		}
		//���������ʼ��
		infile >> ifKillPettigrew >> roomNum;
		bool tempIsInRoom = 0;
		infile >> tempIsInRoom;
		chamber.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		auditorium.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		villa.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		lakes.setIfIn(tempIsInRoom);
		if (roomNum == 0) {
			mySorcerer->inRoom(&chamber);
		}
		else if (roomNum == 1) {
			mySorcerer->inRoom(&auditorium);
		}
		else if (roomNum == 2) {
			mySorcerer->inRoom(&villa);
		}
		else if (roomNum == 3) {
			mySorcerer->inRoom(&lakes);
		}
	}
	Shop shop(medicine, skill, "����èͷӥħ����Ʒ��", medicine.size(), skill.size());

	while (check) {
		//�������Ϸ������
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//��ʽ������
			system("cls");
		}
		system("pause");//��ʽ������
		system("cls");
		//��ʾ������
		cout << "���� �鿴���� ���Բ鿴��ǰ�Լ�������" << endl;
		cout << "���� ����ҩƷ ���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�ħ������" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�еļ���" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ��ռ��Ļ���" << endl;
		cout << "���� ������� ���Խ���ؿ��ĵ���" << endl;
		cout << "���� ������� ���Ա��浱ǰ����" << endl;
		cout << "���� �˳���Ϸ �����˳���ǰ��Ϸ" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << mySorcerer->getRoom()->getName() << endl;
		cout << "�����ͼ�Ϸ�������ֿ��Խ���÷���" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map.showMap();
		cout << "���������ѡ��:" << endl;
		string op = " ";
		cin >> op;
		if (op == "�鿴����") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "����ҩƷ") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "�鿴���� ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "�������") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "�������") {
			mySorcerer->setMyCheckPoint(3);
			//�ļ�����
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//����ùؿ��Ľ���
			ofstream tempFile;
			ofstream stateFile;
			//��Ϣ�������
			//����������Ϣ����
			tempFile.open(mySorcerer->getName() + ".txt");
			tempFile << mySorcerer->getDisguiseValue() << " "
				<< mySorcerer->getForceValue() << " "
				<< mySorcerer->getDefenceValue() << " "
				<< mySorcerer->getMagicValue() << " "
				<< mySorcerer->getBloodValue() << " "
				<< mySorcerer->getMoney() << " "
				<< mySorcerer->getName() << endl;
			tempFile << mySorcerer->getMagicitemNum() << " ";
			for (int i = 0; i < mySorcerer->getMagicitemNum(); i++) {
				tempFile << mySorcerer->getMagicitem()[i].getName() << " " << mySorcerer->getMagicitem()[i].getId() << endl;
			}
			tempFile << mySorcerer->getHorcruxNum() << " ";
			for (int i = 0; i < mySorcerer->getHorcruxNum(); i++) {
				tempFile << mySorcerer->getHorcrux()[i].getName() << " " << mySorcerer->getHorcrux()[i].getId() << endl;
			}
			tempFile << mySorcerer->getSkillNum() << " ";
			for (int i = 0; i < mySorcerer->getSkillNum(); i++) {
				tempFile << mySorcerer->getSkill()[i].getName() << " " << mySorcerer->getSkill()[i].getDamage() << endl;
			}
			tempFile << mySorcerer->getMedicineNum() << " ";
			for (int i = 0; i < mySorcerer->getMedicineNum(); i++) {
				tempFile << mySorcerer->getMedicine()[i].getName() << " " << mySorcerer->getMedicine()[i].getRecoverValue() << " " << mySorcerer->getMedicine()[i].getPrice() << endl;
			}
			tempFile << mySorcerer->getMyCheckpoint() << endl;
			cout << "����������Ϣ����ɹ�!" << endl;
			//�ؿ���Ϣ����
			stateFile.open(mySorcerer->getName() + "State" + ".txt");
			stateFile << shop.getMedicineNum() << " ";
			for (int i = 0; i < shop.getMedicineNum(); i++) {
				stateFile << shop.getMedicine()[i].getName() << " "
					<< shop.getMedicine()[i].getRecoverValue() << " "
					<< shop.getMedicine()[i].getPrice() << endl;
			}
			stateFile << shop.getSkillNum() << " ";
			for (int i = 0; i < shop.getSkillNum(); i++) {
				stateFile << shop.getSkill()[i].getName() << " "
					<< shop.getSkill()[i].getDamage() << " "
					<< shop.getSkill()[i].getPrice() << endl;
			}
			stateFile << ifKillPettigrew << " " << roomNum << endl;
			//0���� 1���� 2���� 3�����ĸ���ͼ�Ľ������
			stateFile << chamber.getIfIn() << " "
				<< auditorium.getIfIn() << " "
				<< villa.getIfIn() << " "
				<< lakes.getIfIn() << endl;
			//	//����
			mySorcerer->setMyCheckPoint(3);
			cout << "�ùؿ�״̬��Ϣ����ɹ���" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "�˳���Ϸ") {
			cout << "���Ѿ���������Ϸ��" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "����" && roomNum == chamberWithNum.second || op == "����" && roomNum == auditoriumWithNum.second || op == "����" && roomNum == villaWithNum.second || op == "����" && roomNum == lakesWithNum.second) {
			system("cls");
			cout << "���Ѿ��ڸ�λ�ã�" << endl;
			//��ʽ������	
		}
		else if (op == "����" && link[roomNum][auditoriumWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&auditorium);
			system("cls");
			cout << "��ӭ���� " << auditorium.getName() << endl;
			if (auditorium.getIfIn()) {
				cout << "��ӭ���ٴ����� " << auditorium.getName() << endl;
			}
			else {
				cout << "�ڻ������ȳǱ��⣬�����ڼ����˴����Ѿõ�С�����ǲ����ˣ���Ȼ����������������һζ���ã���е��ɻ�������ͣ�º����Ի�" << endl;
				cout << "�����ˣ���׷ɱ��һֱ���ǳ���߰ߣ��������㣬�Ǹ��߰���С���Ǳ˵ñ�ã��������������ħ�����㸸ĸ���г̵ġ�" << endl;
				cout << "�����Ų����˵��渵�������������������������" << endl;
				cout << "�㣺���������ڸ���ô�죿" << endl;
				cout << "�����ˣ�������Ҫȥ������С���ǣ���Ҫ֤���Լ�����ף�������Ľ̸�" << endl;
				cout << "\n" << Snape.getName() << "��" << Snape.getSentence() << endl;
				cout << "����" << Snape.getName() << "������̸��֮�� �㷢��������һ���޴����ı��" << endl;
				auditorium.inRoom();
			}
		}
		else if (op == "����" && !link[roomNum][auditoriumWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������ã�����ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*if (link[tmp.x][tmp.y] == 1)
					cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == chamberWithNum.second) {
								cout << chamber.getName() << endl;
							}
							else if (tmp.y == auditoriumWithNum.second) {
								cout << auditorium.getName() << endl;
							}
							else if (tmp.y == villaWithNum.second) {
								cout << villa.getName() << endl;
							}
							else if (tmp.y == lakesWithNum.second) {
								cout << lakes.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "����" && link[roomNum][villaWithNum.second]) {
			roomNum = 2;
			mySorcerer->inRoom(&villa);
			system("cls");
			if (villa.getIfIn()) {
				cout << "��ӭ���ٴ����� " << villa.getName() << endl;
			}
			else {
				cout << "��ӭ���� " << villa.getName() << endl;
				villa.inRoom();
				//��С���ǽ���ս��
				cout << "��ʱС������׼�����ܣ����Ƿ�ѡ����������ս����" << endl;
				cout << "1.��		2.��" << endl;
				int op_pettigrew = 0;
				cin >> op_pettigrew;
				system("cls");
				if (op_pettigrew == 1) {
					cout << "ս���Ѿ���ʼ��" << endl;
					bool ifWin = 1;
					ifWin = mySorcerer->battle(mySorcerer, pettigrew);
					if (ifWin) {
						system("pause");
						system("cls");
						cout << "��ͨ��ս��������" << pettigrew.getName() << "�Ĵ󲿷�����������С�������ӵ��˺���......" << endl;
						system("pause");
						system("cls");
						ifKillPettigrew = 1;
					}
					else {
						cout << "�㱻С���ǻ��ܣ������ٹ�����װ������ս����" << endl;
						mySorcerer->setBlood(0);
						//�����
						cout << "\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\n\t\t   �˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\n\t\t   ��\t\t   ��\t\t   ��\t\n\t\t    ��\t\t   ��\t\t  ��\t\n\t\t     ��\t\t   ��\t\t ��\t\n\n\t\t\t\t   ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t\t   ��\n\t\t\t         �˲˲�\n\t\t\t       ��  ��  ��\n\t\t\t     ��    ��    ��\n\t\t\t   ��      ��      ��\n\t\t\t ��        ��        ��\n\t\t       ��          ��          ��\n\t\t     ��            ��            ��\n\t\t   ��              ��              ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&auditorium);
						roomNum = auditoriumWithNum.second;
					}
				}
				else if (op_pettigrew == 2) {
					cout << "���Ѿ�����÷��䡣С���ǳɹ�����" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = auditoriumWithNum.second;
				}
				else {
					cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = auditoriumWithNum.second;
				}
			}	
		}
		else if (op == "����" && !link[roomNum][villaWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*if (link[tmp.x][tmp.y] == 1)
					cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == chamberWithNum.second) {
								cout << chamber.getName() << endl;
							}
							else if (tmp.y == auditoriumWithNum.second) {
								cout << auditorium.getName() << endl;
							}
							else if (tmp.y == villaWithNum.second) {
								cout << villa.getName() << endl;
							}
							else if (tmp.y == lakesWithNum.second) {
								cout << lakes.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "����" && link[roomNum][lakesWithNum.second]) {
			system("cls");
			if (ifKillPettigrew) {
				roomNum = 3;
				mySorcerer->inRoom(&lakes);
				cout << "������˺�����" << endl;
				cout << "��ӭ��������~" << endl;
				cout << "��ʱ��������Ϯ��С�����ǣ����Ƿ�ѡ����������ս����" << endl;
				cout << "1.��		2.��" << endl;
				int op_dementor = 0;
				cin >> op_dementor;
				system("cls");
				if (op_dementor == 1) {
					bool ifWin = 0;
					cout << "ս����ʼ�����ѽ���ս��ģʽ..." << endl;
					ifWin = mySorcerer->battle(mySorcerer, dementor);
					if (ifWin) {
						cout << "��ϲ��ɹ�ͨ�������ز������2000��Һ�һ��������" << endl;
						mySorcerer->addHorcrux(locket);
						mySorcerer->increaseMoney(2000);
						check = 0;
						system("pause");
						system("cls");
					}
					else {
						mySorcerer->inRoom(&auditorium);
						mySorcerer->setBlood(0);
						//�����
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n" << endl;
						system("pause");
						system("cls");
						roomNum = 1;
					}
				}
				else if (op_dementor == 2) {
					cout << "���Ѿ�����ս����" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = 1;
				}
				else {
					cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = 1;
				}
			}
			else {
				cout << "������û�л���С���ǣ��޷��������" << endl;
			}
		}
		else if (op == "����" && !link[roomNum][lakesWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*	if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == chamberWithNum.second) {
								cout << chamber.getName() << endl;
							}
							else if (tmp.y == auditoriumWithNum.second) {
								cout << auditorium.getName() << endl;
							}
							else if (tmp.y == villaWithNum.second) {
								cout << villa.getName() << endl;
							}
							else if (tmp.y == lakesWithNum.second) {
								cout << lakes.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������	
		}
		else if (op == "����" && link[roomNum][chamberWithNum.second]) {
			system("cls");
			cout << "��ӭ��������~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&chamber);
		}
		else if (op == "����" && !link[roomNum][chamberWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������ң�����ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*if (link[tmp.x][tmp.y] == 1)
					cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == chamberWithNum.second) {
								cout << chamber.getName() << endl;
							}
							else if (tmp.y == auditoriumWithNum.second) {
								cout << auditorium.getName() << endl;
							}
							else if (tmp.y == villaWithNum.second) {
								cout << villa.getName() << endl;
							}
							else if (tmp.y == lakesWithNum.second) {
								cout << lakes.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������	
		}
		else {
			system("cls");
			cout << "����ʧ�ܣ�" << endl;
			//��ʽ������	
		}
	}
	return 1;
}

int Plot::init4(Sorcerer *mySorcerer, int myCheckPoint, bool ifNew) {
	//���ؾ����ʽ����¼
	//Сҩˮ��Ŀ ��ҩˮ��Ŀ ��ҩˮ��Ŀ ���� ifKillKerberos roomNum 0.���� 1.�Թ� 2.��Ĺ 3���� 4�칫���ĸ���ͼ�Ľ������

	//ҩˮ���� 1��2��3С
	//ҩˮ��Ŀ��Ҫ����һ����¼ ��¼�ĸ�ʽΪ X X X�ֱ�ָС�д�
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	if (!ifNew) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);;
	}
	//�����＼������
	//���ExpectoPatronum 30 1300	
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill ExpectoPatronum("ExpectoPatronum", 15, 600);
	if (myCheckPoint != 4) {
		skill.push_back(ExpectoPatronum);
	}
	//һЩ�ж�
	bool check = 1;
	int trueanswer = 0;
	bool ifPassMaze = 0;
	//���صص����� 0.���� 1.�Թ� 2.��Ĺ 3���� 4�칫��
	Room auditorium("����");
	Room maze("�Թ�");
	Room grave("��Ĺ");
	Room hall("����");
	Room office("�칫��");
	int roomNum = 0; //���浱ǰ���ڵķ����
	//�����ȵ���һ���ص�
	mySorcerer->inRoom(&auditorium);
	Map map("\t*********\t\t\t\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*����\t*\t<--------------->\t*�Թ�\t*\t---------------->\t*��Ĺ\t*\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t   ||\n \t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   \\/\n\t\t\t\t\t\t\t\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*����\t*\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t   /\\\n \t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   \\/\n\t\t\t\t\t\t\t\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*�칫��\t*\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*********");
		//һЩװ��
	Magicitem The_goblet_of_fire("���汭", 100);
	if (!ifNew) {
		//���ֱ�������
		cout << "����û�б����μӡ���ǿ��������ȴ����س�Ϊ����ǿ�������ĵ�������ʿ\nû�뵽�������ı���ں������������������������" << endl;
		system("pause");
		system("cls");
		cout << "��ӭ������Ĺ�~" << endl;
	}
	//����
	Horcrux najini("�ɼ���");
	//��������
	BadPerson voldemort(100, 10, 35, "����ħ");
	BadPerson Little_buddy(100, 10, 15, "С�͵�");
	grave.addBadPerson(voldemort);
	office.addBadPerson(Little_buddy);
	//ʹ��pair��
	pair<string, int> auditoriumWithNum("����", 0);
	pair<string, int> mazeWithNum("�Թ�", 1);
	pair<string, int> graveWithNum("��Ĺ", 2);
	pair<string, int> hallWithNum("����", 3);
	pair<string, int> officeWithNum("�칫��", 4);
	//�ж���ͨ���	link[A][B] = 1����A->B��ͨ��
	//�ڽӾ���
	bool link[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			link[i][j] = 0;
	}
	link[auditoriumWithNum.second][mazeWithNum.second] = 1;
	link[mazeWithNum.second][auditoriumWithNum.second] = 1;
	link[mazeWithNum.second][graveWithNum.second] = 1;
	link[graveWithNum.second][hallWithNum.second] = 1;
	link[hallWithNum.second][officeWithNum.second] = 1;
	link[officeWithNum.second][hallWithNum.second] = 1;

	if (ifNew) {
		cout << "��ӭ���ٴν�����Ϸ�������������Ĺص����̡�" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//ҩˮ��ʼ��
		int medicineNum = 0;
		infile >> medicineNum;
		string medicineName = " ";
		int recoverValue = 0;
		int medicinePirce = 0;
		for (int i = 0; i < medicineNum; i++) {
			infile >> medicineName >> recoverValue >> medicinePirce;
			tempMedicine.setInformation(medicineName, recoverValue, medicinePirce);
			medicine.push_back(tempMedicine);
		}
		//���ܳ�ʼ��
		int skillNum = 0;
		infile >> skillNum;
		string skillName = " ";
		int skillDamage = 0;
		int skillPrice = 0;
		for (int i = 0; i < skillNum; i++) {
			infile >> skillName >> skillDamage >> skillPrice;
			tempSkill.setValue(skillName, skillDamage, skillPrice);
			skill.push_back(tempSkill);
		}
		//���������ʼ��
		infile >> ifPassMaze >> roomNum;
		bool tempIsInRoom = 0;
		infile >> tempIsInRoom;
		hall.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		auditorium.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		maze.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		grave.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		office.setIfIn(tempIsInRoom);
		if (roomNum == 0) {
			mySorcerer->inRoom(&hall);
		}
		else if (roomNum == 1) {
			mySorcerer->inRoom(&auditorium);
		}
		else if (roomNum == 2) {
			mySorcerer->inRoom(&maze);
		}
		else if (roomNum == 3) {
			mySorcerer->inRoom(&hall);
		}
		else if (roomNum == 4) {
			mySorcerer->inRoom(&office);
		}
	}
	Shop shop(medicine, skill, "����ħ����Ʒ��", medicine.size(), skill.size());
	while (check) {
		//�������Ϸ������
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//��ʽ������
			system("cls");
		}
		system("pause");//��ʽ������
		system("cls");
		//��ʾ������
		cout << "���� �鿴���� ���Բ鿴��ǰ�Լ�������" << endl;
		cout << "���� ����ҩƷ ���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�ħ������" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�еļ���" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ��ռ��Ļ���" << endl;
		cout << "���� ������� ���Խ���ؿ��ĵ���" << endl;
		cout << "���� ������� ���Ա��浱ǰ����" << endl;
		cout << "���� �˳���Ϸ �����˳���ǰ��Ϸ" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << mySorcerer->getRoom()->getName() << endl;
		cout << "�����ͼ�Ϸ�������ֿ��Խ���÷���" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map.showMap();
		cout << "���������ѡ��:" << endl;
		string op = " ";
		cin >> op;
		if (op == "�鿴����") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "����ҩƷ") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "�鿴���� ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "�������") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "�������") {
			mySorcerer->setMyCheckPoint(4);
			//�ļ�����
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//����ùؿ��Ľ���
			ofstream tempFile;
			ofstream stateFile;
			//��Ϣ�������
			//����������Ϣ����
			tempFile.open(mySorcerer->getName() + ".txt");
			tempFile << mySorcerer->getDisguiseValue() << " "
				<< mySorcerer->getForceValue() << " "
				<< mySorcerer->getDefenceValue() << " "
				<< mySorcerer->getMagicValue() << " "
				<< mySorcerer->getBloodValue() << " "
				<< mySorcerer->getMoney() << " "
				<< mySorcerer->getName() << endl;
			tempFile << mySorcerer->getMagicitemNum() << " ";
			for (int i = 0; i < mySorcerer->getMagicitemNum(); i++) {
				tempFile << mySorcerer->getMagicitem()[i].getName() << " " << mySorcerer->getMagicitem()[i].getId() << endl;
			}
			tempFile << mySorcerer->getHorcruxNum() << " ";
			for (int i = 0; i < mySorcerer->getHorcruxNum(); i++) {
				tempFile << mySorcerer->getHorcrux()[i].getName() << " " << mySorcerer->getHorcrux()[i].getId() << endl;
			}
			tempFile << mySorcerer->getSkillNum() << " ";
			for (int i = 0; i < mySorcerer->getSkillNum(); i++) {
				tempFile << mySorcerer->getSkill()[i].getName() << " " << mySorcerer->getSkill()[i].getDamage() << endl;
			}
			tempFile << mySorcerer->getMedicineNum() << " ";
			for (int i = 0; i < mySorcerer->getMedicineNum(); i++) {
				tempFile << mySorcerer->getMedicine()[i].getName() << " " << mySorcerer->getMedicine()[i].getRecoverValue() << " " << mySorcerer->getMedicine()[i].getPrice() << endl;
			}
			tempFile << mySorcerer->getMyCheckpoint() << endl;
			cout << "����������Ϣ����ɹ�!" << endl;
			//�ؿ���Ϣ����
			stateFile.open(mySorcerer->getName() + "State" + ".txt");
			stateFile << shop.getMedicineNum() << " ";
			for (int i = 0; i < shop.getMedicineNum(); i++) {
				stateFile << shop.getMedicine()[i].getName() << " "
					<< shop.getMedicine()[i].getRecoverValue() << " "
					<< shop.getMedicine()[i].getPrice() << endl;
			}
			stateFile << shop.getSkillNum() << " ";
			for (int i = 0; i < shop.getSkillNum(); i++) {
				stateFile << shop.getSkill()[i].getName() << " "
					<< shop.getSkill()[i].getDamage() << " "
					<< shop.getSkill()[i].getPrice() << endl;
			}
			stateFile << ifPassMaze << " " << roomNum << endl;
			//0.���� 1.�Թ� 2.��Ĺ 3���� 4�칫��
			stateFile << auditorium.getIfIn() << " "
				<< maze.getIfIn() << " "
				<< grave.getIfIn() << " "
				<< hall.getIfIn() << " "
				<< office.getIfIn() << endl;
			//	//����
			mySorcerer->setMyCheckPoint(4);
			cout << "�ùؿ�״̬��Ϣ����ɹ���" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "�˳���Ϸ") {
			cout << "���Ѿ���������Ϸ��" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "����" && roomNum == auditoriumWithNum.second || op == "�Թ�" && roomNum == mazeWithNum.second || op == "��Ĺ" && roomNum == graveWithNum.second || op == "����" && roomNum == hallWithNum.second || op == "�칫��" && roomNum == officeWithNum.second) {
			system("cls");
			cout << "���Ѿ��ڸ�λ�ã�" << endl;
			//��ʽ������	
		}
		else if (op == "�Թ�" && link[roomNum][mazeWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&maze);
			system("cls");
			cout << "��ӭ���� " << maze.getName() << endl;
			if (maze.getIfIn()) {
				cout << "��ӭ���ٴ����� " << maze.getName() << endl;
				cout << "���汭��ȥ��һ���ط���Կ��" << endl;
			}
			else {
				char indicatation;
				cout << "ͨ���ش�һЩС���������ͨ���Թ���" << endl;
				system("pause");
				trueanswer = 0;
				cout << "1���������ص������Ǽ��¼��գ�" << endl;
				cout << "A.8.31    B. 7.31    C.7.11" << endl;
				cin >> indicatation;
				if (indicatation == 'B') {
					cout << "�ش���ȷ" << endl;
					trueanswer++;
				}
				else {
					cout << "�ش����" << endl;
				}
				cout << "2.����Imperio��ʲô��˼��" << endl;
				cout << "A. ���ǳ���              B. �������              C. ��ħ���" << endl;
				cin >> indicatation;
				if (indicatation == 'A') {
					cout << "�ش���ȷ" << endl;
					trueanswer++;
				}
				else {
					cout << "�ش����" << endl;
				}
				cout << "3. Bezoar ë��ʯ��ʲô���ã�" << endl;
				cout << "A. �����ⶾ B.���Ѳ����������ر����Ч  C.��ˮ����Ժ���" << endl;
				cin >> indicatation;
				if (indicatation == 'A') {
					cout << "�ش���ȷ" << endl;
					trueanswer++;
				}
				else {
					cout << "�ش����" << endl;
				}
				if (trueanswer == 3) {
					cout << "��ϲ��ͨ���Թ�������˻��汭��" << endl;
					mySorcerer->addMagicitem(The_goblet_of_fire);
					maze.inRoom();
					ifPassMaze = 1;
				}
				else {
					cout << "���ź���û��ͨ���Թ������ȷ��������á�" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = 0;
					//0.���� 1.�Թ� 2.��Ĺ 3���� 4�칫��
				}
			}
		}
		else if (op == "�Թ�" && !link[roomNum][mazeWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ����Թ�������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*	if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == auditoriumWithNum.second) {
								cout << auditorium.getName() << endl;
							}
							else if (tmp.y == mazeWithNum.second) {
								cout << maze.getName() << endl;
							}
							else if (tmp.y == graveWithNum.second) {
								cout << grave.getName() << endl;
							}
							else if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == officeWithNum.second) {
								cout << office.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "��Ĺ" && link[roomNum][graveWithNum.second]) {
			if (ifPassMaze) {
				roomNum = 2;
				mySorcerer->inRoom(&grave);
				system("cls");
				cout << "��ͨ������Ļ��汭��������һ������ĵط�" << endl;
				if (grave.getIfIn()) {
					cout << "��ӭ���ٴ����� " << grave.getName() << endl;
					cout << "����ħ�����Ѿ��뿪��������" << endl;
				}
				else {
					system("pause");
					system("cls");
					mySorcerer->inRoom(&grave);
					cout << "��ӭ���� " << grave.getName() << endl;
					cout << "�Ǹ�����˵�����ֵ��˸����ˣ�����" << endl;
					system("pause");
					system("cls");
					cout << "�Ƿ�ѡ�������ħ����ս��:" << endl;
					cout << "1.��		2.��" << endl;
					int op_grave = 0;
					cin >> op_grave;
					if (op_grave == 1) {
						cout << "ս�������У�����ʵ�����ϴ���ʹ�û��汭˳�����ѡ�" << endl;
					}
					else {
						cout << "��ʹ�û��汭˳�����ѡ�" << endl;
					}
					system("pause");
					system("cls");
					mySorcerer->inRoom(&hall);
					roomNum = 3;
						//0.���� 1.�Թ� 2.��Ĺ 3���� 4�칫��
				}
			}
			else {
				cout << "��ȱ�ٽ����Ĺ��Կ�ס�" << endl;
			}
		}
		else if (op == "��Ĺ" && !link[roomNum][graveWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ����Ĺ������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*	if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == auditoriumWithNum.second) {
								cout << auditorium.getName() << endl;
							}
							else if (tmp.y == mazeWithNum.second) {
								cout << maze.getName() << endl;
							}
							else if (tmp.y == graveWithNum.second) {
								cout << grave.getName() << endl;
							}
							else if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == officeWithNum.second) {
								cout << office.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "����" && link[roomNum][hallWithNum.second]) {
			roomNum = 3;
			mySorcerer->inRoom(&hall);
			system("cls");
			cout << "��ӭ����������" << endl;
		}
		else if (op == "����" && !link[roomNum][graveWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*	if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == auditoriumWithNum.second) {
								cout << auditorium.getName() << endl;
							}
							else if (tmp.y == mazeWithNum.second) {
								cout << maze.getName() << endl;
							}
							else if (tmp.y == graveWithNum.second) {
								cout << grave.getName() << endl;
							}
							else if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == officeWithNum.second) {
								cout << office.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "�칫��" && link[roomNum][officeWithNum.second]) {
			roomNum = 4;
			mySorcerer->inRoom(&hall);
			system("cls");
			cout << "��ӭ����" << office.getName() << endl;
			cout << "ԭ��С�͵���ʳ˾ͽ!!!" << endl;
			cout << "���Ƿ�ѡ����������ս����" << endl;
			cout << "1.��		2.��" << endl;
			int op_office = 0;
			cin >> op_office;
			system("cls");
			if (op_office == 1) {
				bool ifWin = 0;
				cout << "ս����ʼ�����ѽ���ս��ģʽ..." << endl;
				ifWin = mySorcerer->battle(mySorcerer, Little_buddy);
				if (ifWin) {
					cout << "��ϲ��ɹ�ͨ�����Ĺعز������2000��Һ��ɼ���" << endl;
					mySorcerer->increaseMoney(2000);
					mySorcerer->addHorcrux(najini);
					check = 0;
					system("pause");
					system("cls");
				}
				else {
					mySorcerer->setBlood(0);
					//�����
					cout << "\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\n\t\t   �˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\n\t\t   ��\t\t   ��\t\t   ��\t\n\t\t    ��\t\t   ��\t\t  ��\t\n\t\t     ��\t\t   ��\t\t ��\t\n\n\t\t\t\t   ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t\t   ��\n\t\t\t         �˲˲�\n\t\t\t       ��  ��  ��\n\t\t\t     ��    ��    ��\n\t\t\t   ��      ��      ��\n\t\t\t ��        ��        ��\n\t\t       ��          ��          ��\n\t\t     ��            ��            ��\n\t\t   ��              ��              ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n" << endl;
					system("pause");
					system("cls");
					mySorcerer->inRoom(&hall);
					roomNum = 3;
					//0.���� 1.�Թ� 2.��Ĺ 3���� 4�칫��
				}
			}
			else if (op_office == 2) {
				cout << "���Ѿ�����ս����" << endl;
			}
			else {
				cout << "����ʧ�ܣ������˳��÷��䣡" << endl;
				mySorcerer->inRoom(&hall);
				roomNum = 3;
				//0.���� 1.�Թ� 2.��Ĺ 3���� 4�칫��
			}
		}
		else if (op == "�칫��" && !link[roomNum][officeWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ���칫�ң�����ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty())
			{
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == auditoriumWithNum.second) {
								cout << auditorium.getName() << endl;
							}
							else if (tmp.y == mazeWithNum.second) {
								cout << maze.getName() << endl;
							}
							else if (tmp.y == graveWithNum.second) {
								cout << grave.getName() << endl;
							}
							else if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == officeWithNum.second) {
								cout << office.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
	}
	return 1;
}


int Plot::init5(Sorcerer *mySorcerer, int myCheckPoint, bool ifNew) {
	//���ؾ����ʽ����¼
	//Сҩˮ��Ŀ ��ҩˮ��Ŀ ��ҩˮ��Ŀ ���� ifKillKerberos roomNum 0���� 1У���� 2��¥ 3��Ѩ�ĸ���ͼ�Ľ������
	//bool end = 0;	//
	//�����͵�����
	//ҩˮ���ô���
	//ҩˮ���� 1��2��2С
	//ҩˮ��Ŀ��Ҫ����һ����¼ ��¼�ĸ�ʽΪ X X X�ֱ�ָС�д�
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	if (!ifNew) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
	}
	//�����＼������
	//���Epliskey 40 1500
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Epliskey("Epliskey", 60, 1500);
	if (myCheckPoint != 5) {
		skill.push_back(Epliskey);
	}
	//һЩ�ж�
	bool check = 1;

	//���صص����� 0.���� 1.ħ���� 2.�����Ӧ�� 3.������
	Room hall("����");
	Room The_ministry_of_magic("ħ����");
	Room Room_of_requirement("�����Ӧ��");
	Room The_dragon_pavilion("������");
	int roomNum = 0; //���浱ǰ���ڵķ����
	//�����ȵ���һ���ص�
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	Map map("\t*********\n\t*\t*\n\t*ħ����\t*\n\t*\t*\n\t*********\n\t   /\\\n\t   ||\n\t   ||\n\t   ||\n\t   \\/\n\t*********\t\t\t\t*****************\n\t*\t*\t\t\t\t*\t\t*\n\t*����\t*<----------------------------->*�����Ӧ��\t*\n\t*\t*\t\t\t\t*\t\t*\n\t*********\t\t\t\t*****************\n\t   /\\\n\t   ||\n\t   ||\n\t   ||\n\t   ||\n\t   \\/\n\t*********\n\t*\t*\n\t*������\t*\n\t*\t*\n\t*********");
	if (!ifNew) {
		//��������
		cout << "û�������ŷ���ħ������\n��������Ϊ�Ǹ�ƭ�ӣ�\nֻ���������������Ų�֧��������\n�����ڻ�����齨�˲���������ֿ���\n�������������˷���ħ�Ĺ�ƣ�\n������������ħ������Ƚ̸�С�����ǡ�������������" << endl;
		system("pause");
		system("cls");
		cout << "��ӭ��������~" << endl;
	}
	//��������
	GoodPerson Sirius("С������", "�ұ����������㣬�԰ɡ�...\n");
	BadPerson Lucius(200, 40, 50, "¬��˹");
	The_ministry_of_magic.addGoodPerson(Sirius);
	BadPerson Fire_dragon(100, 10, 35, "����");
	BadPerson Earth_dragon(100, 10, 35, "����");
	BadPerson Water_dragon(100, 10, 35, "ˮ��");
	BadPerson Wind_dragon(100, 10, 35, "����");
	BadPerson Far_from_cologne(100, 10, 35, "Զ����");
	//װ��
	Magicitem Invisibility_cloak("���ζ���", 3);
	//����
	Horcrux crown("�����ɡ����Ŀ��͵�����");
	//����������� ��սľ����������������������Զ����
	if (!ifNew) {
		The_dragon_pavilion.addBadPerson(Fire_dragon);
		The_dragon_pavilion.addBadPerson(Earth_dragon);
		The_dragon_pavilion.addBadPerson(Water_dragon);
		The_dragon_pavilion.addBadPerson(Wind_dragon);
		The_dragon_pavilion.addBadPerson(Far_from_cologne);
	}
	//ʹ��pair��
	pair<string, int> hallWithNum("����", 0);
	pair<string, int> The_ministry_of_magicWithNum("ħ����", 1);
	pair<string, int> Room_of_requirementWithNum("�����Ӧ��", 2);
	pair<string, int> The_dragon_pavilionWithNum("������", 3);
	//�ж���ͨ���	link[A][B] = 1����A->B��ͨ��
	//�ڽӾ���
	bool link[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			link[i][j] = 0;
	}
	link[hallWithNum.second][The_ministry_of_magicWithNum.second] = 1;
	link[The_ministry_of_magicWithNum.second][hallWithNum.second] = 1;
	link[hallWithNum.second][Room_of_requirementWithNum.second] = 1;
	link[Room_of_requirementWithNum.second][hallWithNum.second] = 1;
	link[hallWithNum.second][The_dragon_pavilionWithNum.second] = 1;
	link[The_dragon_pavilionWithNum.second][hallWithNum.second] = 1;
	if (ifNew) {
		cout << "��ӭ���ٴν�����Ϸ��������������ص����̡�" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//ҩˮ��ʼ��
		int medicineNum = 0;
		infile >> medicineNum;
		string medicineName = " ";
		int recoverValue = 0;
		int medicinePirce = 0;
		for (int i = 0; i < medicineNum; i++) {
			infile >> medicineName >> recoverValue >> medicinePirce;
			tempMedicine.setInformation(medicineName, recoverValue, medicinePirce);
			medicine.push_back(tempMedicine);
		}
		//���ܳ�ʼ��
		int skillNum = 0;
		infile >> skillNum;
		string skillName = " ";
		int skillDamage = 0;
		int skillPrice = 0;
		for (int i = 0; i < skillNum; i++) {
			infile >> skillName >> skillDamage >> skillPrice;
			tempSkill.setValue(skillName, skillDamage, skillPrice);
			skill.push_back(tempSkill);
		}
		//�������ʼ��
		BadPerson tempBadPerson(0, 0, 0, " ");
		int dragonNum = 0;
		int dragonDown = 0;
		int dragonUp = 0;
		int dragonBlood = 0;
		infile >> dragonNum;
		string dragonName = " ";
		for (int i = 0; i < dragonNum; i++) {
			infile >> dragonName >> dragonDown >> dragonUp >> dragonBlood;
			tempBadPerson.setValue(dragonBlood, dragonDown, dragonUp, dragonName);
			The_dragon_pavilion.addBadPerson(tempBadPerson);
		}
		//���������ʼ��
		infile  >> roomNum;
		bool tempIsInRoom = 0;
		infile >> tempIsInRoom;
		hall.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		The_ministry_of_magic.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		Room_of_requirement.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		The_dragon_pavilion.setIfIn(tempIsInRoom);
		if (roomNum == 0) {
			mySorcerer->inRoom(&hall);
		}
		else if (roomNum == 1) {
			mySorcerer->inRoom(&The_ministry_of_magic);
		}
		else if (roomNum == 2) {
			mySorcerer->inRoom(&Room_of_requirement);
		}
		else if (roomNum == 3) {
			mySorcerer->inRoom(&The_dragon_pavilion);
		}
	}
	Shop shop(medicine, skill, "ħ�����ħ����Ʒ��", medicine.size(), skill.size());
	while (check) {
		//�������Ϸ������
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//��ʽ������
			system("cls");
		}
		system("pause");//��ʽ������
		system("cls");
		//��ʾ������
		cout << "���� �鿴���� ���Բ鿴��ǰ�Լ�������" << endl;
		cout << "���� ����ҩƷ ���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�ħ������" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�еļ���" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ��ռ��Ļ���" << endl;
		cout << "���� ������� ���Խ���ؿ��ĵ���" << endl;
		cout << "���� ������� ���Ա��浱ǰ����" << endl;
		cout << "���� �˳���Ϸ �����˳���ǰ��Ϸ" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << mySorcerer->getRoom()->getName() << endl;
		cout << "�����ͼ�Ϸ�������ֿ��Խ���÷���" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map.showMap();
		cout << "���������ѡ��:" << endl;
		//ѡ��Ϊop
		string op = " ";
		cin >> op;
		if (op == "�鿴����") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "����ҩƷ") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "�鿴���� ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "�������") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "�������") {
			mySorcerer->setMyCheckPoint(5);
			//�ļ�����
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//����ùؿ��Ľ���
			ofstream tempFile;
			ofstream stateFile;
			//��Ϣ�������
			//����������Ϣ����
			tempFile.open(mySorcerer->getName() + ".txt");
			tempFile << mySorcerer->getDisguiseValue() << " "
				<< mySorcerer->getForceValue() << " "
				<< mySorcerer->getDefenceValue() << " "
				<< mySorcerer->getMagicValue() << " "
				<< mySorcerer->getBloodValue() << " "
				<< mySorcerer->getMoney() << " "
				<< mySorcerer->getName() << endl;
			tempFile << mySorcerer->getMagicitemNum() << " ";
			for (int i = 0; i < mySorcerer->getMagicitemNum(); i++) {
				tempFile << mySorcerer->getMagicitem()[i].getName() << " " << mySorcerer->getMagicitem()[i].getId() << endl;
			}
			tempFile << mySorcerer->getHorcruxNum() << " ";
			for (int i = 0; i < mySorcerer->getHorcruxNum(); i++) {
				tempFile << mySorcerer->getHorcrux()[i].getName() << " " << mySorcerer->getHorcrux()[i].getId() << endl;
			}
			tempFile << mySorcerer->getSkillNum() << " ";
			for (int i = 0; i < mySorcerer->getSkillNum(); i++) {
				tempFile << mySorcerer->getSkill()[i].getName() << " " << mySorcerer->getSkill()[i].getDamage() << endl;
			}
			tempFile << mySorcerer->getMedicineNum() << " ";
			for (int i = 0; i < mySorcerer->getMedicineNum(); i++) {
				tempFile << mySorcerer->getMedicine()[i].getName() << " " << mySorcerer->getMedicine()[i].getRecoverValue() << " " << mySorcerer->getMedicine()[i].getPrice() << endl;
			}
			tempFile << mySorcerer->getMyCheckpoint() << endl;
			cout << "����������Ϣ����ɹ�!" << endl;
			//�ؿ���Ϣ����
			stateFile.open(mySorcerer->getName() + "State" + ".txt");
			stateFile << shop.getMedicineNum() << " ";
			for (int i = 0; i < shop.getMedicineNum(); i++) {
				stateFile << shop.getMedicine()[i].getName() << " "
					<< shop.getMedicine()[i].getRecoverValue() << " "
					<< shop.getMedicine()[i].getPrice() << endl;
			}
			stateFile << shop.getSkillNum() << " ";
			for (int i = 0; i < shop.getSkillNum(); i++) {
				stateFile << shop.getSkill()[i].getName() << " "
					<< shop.getSkill()[i].getDamage() << " "
					<< shop.getSkill()[i].getPrice() << endl;
			}
			stateFile << The_dragon_pavilion.getBadPersonSize() << " ";
			for (int i = 0; i < The_dragon_pavilion.getBadPersonSize(); i++) {
				stateFile << The_dragon_pavilion.getBadPerson()[i].getName() << " "
					<< The_dragon_pavilion.getBadPerson()[i].getDown() << " "
					<< The_dragon_pavilion.getBadPerson()[i].getUp() << " "
					<< The_dragon_pavilion.getBadPerson()[i].getblood() << endl;
			}
			stateFile  << " " << roomNum << endl;
			//0.���� 1.ħ���� 2.�����Ӧ�� 3.�������ĸ���ͼ�Ľ������
			stateFile << hall.getIfIn() << " "
				<< The_ministry_of_magic.getIfIn() << " "
				<< Room_of_requirement.getIfIn() << " "
				<< The_dragon_pavilion.getIfIn() << endl;
			//	//����
			mySorcerer->setMyCheckPoint(5);
			cout << "�ùؿ�״̬��Ϣ����ɹ���" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "�˳���Ϸ") {
			cout << "���Ѿ���������Ϸ��" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "����" && roomNum == hallWithNum.second || op == "ħ����" && roomNum == The_ministry_of_magicWithNum.second || op == "�����Ӧ��" && roomNum == Room_of_requirementWithNum.second || op == "������" && roomNum == The_dragon_pavilionWithNum.second) {
			system("cls");
			cout << "���Ѿ��ڸ�λ�ã�" << endl;
			//��ʽ������	
		}
		else if (op == "ħ����" && link[roomNum][The_ministry_of_magicWithNum.second]) {
			bool ifWin = 0;
			roomNum = 1;
			mySorcerer->inRoom(&The_ministry_of_magic);
			system("cls");
			cout << "��ӭ���� " << The_ministry_of_magic.getName() << endl;
			cout << "��ʱ¬��˹����ħ��������Ƿ�ѡ������" << endl;
			cout << "1.��		2.��" << endl;
			int op_magic = 0;
			cin >> op_magic;
			system("cls");
			if (op_magic == 1) {
				cout << "¬��˹:�����㲻������߳�ħ������\n" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Lucius);
				if (ifWin == 1) {
					//�ɹ���ܵĻ�
					check = 0;
					cout << "��ϲ��ͨ������ز������2500��Һ�һ������" << endl;
					mySorcerer->increaseMoney(2500);
					mySorcerer->addHorcrux(crown);
					system("pause");
					system("cls");
				}
				else if (ifWin == 0) {
					mySorcerer->setBlood(0);
					cout << "��սʧ�ܣ�" << endl;
					//�����
					cout << "\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\n\t\t   �˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\n\t\t   ��\t\t   ��\t\t   ��\t\n\t\t    ��\t\t   ��\t\t  ��\t\n\t\t     ��\t\t   ��\t\t ��\t\n\n\t\t\t\t   ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t\t   ��\n\t\t\t         �˲˲�\n\t\t\t       ��  ��  ��\n\t\t\t     ��    ��    ��\n\t\t\t   ��      ��      ��\n\t\t\t ��        ��        ��\n\t\t       ��          ��          ��\n\t\t     ��            ��            ��\n\t\t   ��              ��              ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n" << endl;
					system("pause");
					system("cls");
					mySorcerer->inRoom(&hall);
					roomNum = 0;
					//0.���� 1.ħ���� 2.�����Ӧ�� 3.������
				}
			}
			else if (op_magic == 2) {
				cout << "��ɹ����롣" << endl;
				mySorcerer->inRoom(&hall);
				roomNum = 0;
				//0.���� 1.ħ���� 2.�����Ӧ�� 3.������
			}
			else {
				cout << "����ʧ�ܣ������˳��÷��䡣" << endl;
				mySorcerer->inRoom(&hall);
				roomNum = 0;
				//0.���� 1.ħ���� 2.�����Ӧ�� 3.������
			}
		}
		else if (op == "ħ����" && !link[roomNum][The_ministry_of_magicWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ���ħ����������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == The_ministry_of_magicWithNum.second) {
								cout << The_ministry_of_magic.getName() << endl;
							}
							else if (tmp.y == Room_of_requirementWithNum.second) {
								cout << Room_of_requirement.getName() << endl;
							}
							else if (tmp.y == The_dragon_pavilionWithNum.second) {
								cout << The_dragon_pavilion.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "�����Ӧ��" && link[roomNum][Room_of_requirementWithNum.second]) {
			roomNum = 2;
			mySorcerer->inRoom(&The_ministry_of_magic);
			system("cls");
			cout << "��ӭ���� " << Room_of_requirement.getName() << endl;
			if (Room_of_requirement.getIfIn()) {
				cout << "��ӭ���ٴ����� " << Room_of_requirement.getName() << endl;
				cout << "��ȥ�������������ô��" << endl;
			}
			else {
				//�������Ӧ�ݻ��ʲô�ȴ���ӡ�
				Room_of_requirement.inRoom();
				cout << "ȥ��������ս������Ϊ��������ʿ��" << endl;
				cout << "������һ��װ��" << endl;
				mySorcerer->addMagicitem(Invisibility_cloak);
			}
		}
		else if (op == "�����Ӧ��" && !link[roomNum][Room_of_requirementWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ��������Ӧ�ݣ�����ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == The_ministry_of_magicWithNum.second) {
								cout << The_ministry_of_magic.getName() << endl;
							}
							else if (tmp.y == Room_of_requirementWithNum.second) {
								cout << Room_of_requirement.getName() << endl;
							}
							else if (tmp.y == The_dragon_pavilionWithNum.second) {
								cout << The_dragon_pavilion.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "������" && link[roomNum][The_dragon_pavilionWithNum.second]) {
			roomNum = 3;
			mySorcerer->inRoom(&The_dragon_pavilion);
			system("cls");
			cout << "��ӭ���� " << The_dragon_pavilion.getName() << endl;
			The_dragon_pavilion.inRoom();
			cout << "�������������ս�����������������Ի����Ӧ�ļӳ�" << endl;
			string op_dragon = " ";
			bool ifWin = 0;
			cout << "�������е�����������£�" << endl;
			for (int i = 0; i < The_dragon_pavilion.getBadPerson().size(); i++) {
				cout << i + 1 << ". " << The_dragon_pavilion.getBadPerson()[i].getName() << endl;
			}
			cout << "��������ѡ����Ҫ��֮ս����������0���ܣ�" << endl;
			cin >> op_dragon;
			std::regex rx("[0-9]+");
			bool ifNum = std::regex_match(op_dragon.begin(), op_dragon.end(), rx);
			if (!ifNum) {
				cout << "������Ĳ������֣�" << endl;
				system("pause");
				system("cls");
				mySorcerer->inRoom(&hall);
				roomNum = 0;
			}
			else {
				int op_num = 0;
				stringstream s_temp;//�ַ�������ת��
				s_temp << op_dragon;
				s_temp >> op_num;
				if (!(op_num < The_dragon_pavilion.getBadPerson().size() + 1 && op_num  > 0)) {
					cout << "�������,��������������" << endl;
					mySorcerer->inRoom(&hall);
					roomNum = 0;
					system("pause");
					system("cls");
				}
				else if (op_num == 0) {
					cout << "��ɹ����ܣ�" << endl;
					mySorcerer->inRoom(&hall);
					roomNum = 0;
					system("pause");
					system("cls");
				}
				else {
					cout << "��׼����ս����" << The_dragon_pavilion.getBadPerson()[op_num - 1].getName() << "...ս��������ʼ��" << endl;
					system("pause");
					system("cls");
					ifWin = mySorcerer->battle(mySorcerer, The_dragon_pavilion.getBadPerson()[op_num - 1]);

					if (ifWin == 1) {
						cout << "��ϲ�������" << The_dragon_pavilion.getBadPerson()[op_num - 1].getName() << "����������Լӳɡ�" << endl;
						The_dragon_pavilion.eraseBadPerson(op_num);
						mySorcerer->inRoom(&hall);
						roomNum = 0;
						mySorcerer->increaseMoney(500);
						mySorcerer->increaseBlood(20);
						//0.���� 1.ħ���� 2.�����Ӧ�� 3.������
						//д���Լӳ�������
					}
					else {
						mySorcerer->setBlood(0);
						cout << "�㱻���ܣ������״̬��������" << endl;
						//�����
						cout << "\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\n\t\t   �˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\n\t\t   ��\t\t   ��\t\t   ��\t\n\t\t    ��\t\t   ��\t\t  ��\t\n\t\t     ��\t\t   ��\t\t ��\t\n\n\t\t\t\t   ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t\t   ��\n\t\t\t         �˲˲�\n\t\t\t       ��  ��  ��\n\t\t\t     ��    ��    ��\n\t\t\t   ��      ��      ��\n\t\t\t ��        ��        ��\n\t\t       ��          ��          ��\n\t\t     ��            ��            ��\n\t\t   ��              ��              ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&hall);
						roomNum = 0;
						//0.���� 1.ħ���� 2.�����Ӧ�� 3.������
					}
				}
			}

		}
		else if (op == "������" && !link[roomNum][The_dragon_pavilionWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ�����������������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
				/*	if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == The_ministry_of_magicWithNum.second) {
								cout << The_ministry_of_magic.getName() << endl;
							}
							else if (tmp.y == Room_of_requirementWithNum.second) {
								cout << Room_of_requirement.getName() << endl;
							}
							else if (tmp.y == The_dragon_pavilionWithNum.second) {
								cout << The_dragon_pavilion.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������
		}
		else if (op == "����" && link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "��ӭ��������~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&hall);
		}
		else if (op == "����" && !link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == The_ministry_of_magicWithNum.second) {
								cout << The_ministry_of_magic.getName() << endl;
							}
							else if (tmp.y == Room_of_requirementWithNum.second) {
								cout << Room_of_requirement.getName() << endl;
							}
							else if (tmp.y == The_dragon_pavilionWithNum.second) {
								cout << The_dragon_pavilion.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������	
		}
		else {
			system("cls");
			cout << "����ʧ�ܣ�" << endl;
			//��ʽ������	
		}
	}
	return 1;
}


int Plot::init6(Sorcerer *mySorcerer, int myCheckPoint, bool ifNew) {
	//���ؾ����ʽ����¼
	//Сҩˮ��Ŀ ��ҩˮ��Ŀ ��ҩˮ��Ŀ ���� ifKillKerberos roomNum 0���� 1У���� 2��¥ 3��Ѩ�ĸ���ͼ�Ľ������
	//bool end = 0;	//
	//�����͵�����
	//ҩˮ���� 1��2��2С
	//ҩˮ��Ŀ��Ҫ����һ����¼ ��¼�ĸ�ʽΪ X X X�ֱ�ָС�д�
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	if (!ifNew) {
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
	}
	//����
	Horcrux cup("�����ӡ���������ı���");
	//�����＼������
	//������׻��������䣩:Protego ��15 600 ��������������������� : Densaugeo��12  400
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Avada_kedavra("Protego", 100, 3600);
	if (myCheckPoint == 0) {
		skill.push_back(Avada_kedavra);
	}
	//һЩ�ж�
	bool check = 1;
	//���صص����� 0���� 1ħ���� 2�����
	Room hall("����");
	Room The_ministry_of_magic("ħ����");
	Room gringotts("�����");
	int roomNum = 0;
	//�����ȵ���һ���ص�
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	Map map("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*ħ����\t*\t<--------------->\t*�����\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t  /\\\t\t\t\t\t   ||\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t*********\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*����\t*<===================================\n\t*\t*\n\t*********");
	if (!ifNew) {
		//��������
		cout << "�������죬������Ҫӭ���Լ�ʮ��������գ�\n��Ϊһ��������ħ��ʦ��\nȻ���������ò���ǰ�뿪Ů��·4�ţ�\n��Զ�뿪��������������ʮ����ĵط���\n�����ĳ�Ա����ı��������ת�ƹ����ļƻ���\n�Է������⵽����ħ����׷����ʳ��ͽ��Ϯ����Ȼ�������µ����⻹�Ƿ����ˡ���\n " << endl;
		system("pause");
		system("cls");
		cout << "��ӭ���������~" << endl;
	}
	//�ڹ������Ҫ��6��ʳ��ͽ
	//��������
	BadPerson dolohov(100, 5, 10, "�������");
	BadPerson rookwood(100, 10, 15, "¬�����");
	BadPerson bellatrix(100, 15, 20, "���������˹");
	BadPerson travers(100, 20, 30, "������˹");
	BadPerson DoleFinn(100, 30, 35, "�����");
	BadPerson malfoy(100, 36, 45, "�����");
	if (!ifNew) {
		gringotts.addBadPerson(dolohov);
		gringotts.addBadPerson(rookwood);
		gringotts.addBadPerson(bellatrix);
		gringotts.addBadPerson(travers);
		gringotts.addBadPerson(DoleFinn);
		gringotts.addBadPerson(malfoy);
	}
	//ʹ��pair��
	pair<string, int> hallWithNum("����", 0);
	pair<string, int> The_ministry_of_magicWithNum("ħ����", 1);
	pair<string, int> gringottsWithNum("�����", 2);
	//�ж���ͨ���	link[A][B] = 1����A->B��ͨ��
	//�ڽӾ���
	bool link[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			link[i][j] = 0;
	}
	link[hallWithNum.second][The_ministry_of_magicWithNum.second] = 1;
	link[The_ministry_of_magicWithNum.second][hallWithNum.second] = 1;
	link[The_ministry_of_magicWithNum.second][gringottsWithNum.second] = 1;
	link[gringottsWithNum.second][The_ministry_of_magicWithNum.second] = 1;
	if (ifNew) {
		cout << "��ӭ���ٴν�����Ϸ���������������ص����̡�" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//ҩˮ��ʼ��
		int medicineNum = 0;
		infile >> medicineNum;
		string medicineName = " ";
		int recoverValue = 0;
		int medicinePirce = 0;
		for (int i = 0; i < medicineNum; i++) {
			infile >> medicineName >> recoverValue >> medicinePirce;
			tempMedicine.setInformation(medicineName, recoverValue, medicinePirce);
			medicine.push_back(tempMedicine);
		}
		//���ܳ�ʼ��
		int skillNum = 0;
		infile >> skillNum;
		string skillName = " ";
		int skillDamage = 0;
		int skillPrice = 0;
		for (int i = 0; i < skillNum; i++) {
			infile >> skillName >> skillDamage >> skillPrice;
			tempSkill.setValue(skillName, skillDamage, skillPrice);
			skill.push_back(tempSkill);
		}
		//������ʼ��
		BadPerson tempBadPerson(0, 0, 0, " ");
		int badpersonNum = 0;
		int badpersonDown = 0;
		int badpersonUp = 0;
		int badpersonBlood = 0;
		infile >> badpersonNum;
		string badpersonName = " ";
		for (int i = 0; i < badpersonNum; i++) {
			infile >> badpersonName >> badpersonDown >> badpersonUp >> badpersonBlood;
			tempBadPerson.setValue(badpersonBlood, badpersonDown, badpersonUp, badpersonName);
			gringotts.addBadPerson(tempBadPerson);
		}
		//���������ʼ��
		infile  >> roomNum;
		bool tempIsInRoom = 0;
		infile >> tempIsInRoom;
		hall.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		The_ministry_of_magic.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		gringotts.setIfIn(tempIsInRoom);
		if (roomNum == 0) {
			mySorcerer->inRoom(&hall);
		}
		else if (roomNum == 1) {
			mySorcerer->inRoom(&The_ministry_of_magic);
		}
		else if (roomNum == 2) {
			mySorcerer->inRoom(&gringotts);
		}
	}
	Shop shop(medicine, skill, "�Ƹ�ħ����Ʒ��", medicine.size(), skill.size());

	while (check) {
		//�������Ϸ������
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//��ʽ������
			system("cls");
		}
		system("pause");//��ʽ������
		system("cls");
		//��ʾ������
		cout << "���� �鿴���� ���Բ鿴��ǰ�Լ�������" << endl;
		cout << "���� ����ҩƷ ���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�ħ������" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�еļ���" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ��ռ��Ļ���" << endl;
		cout << "���� ������� ���Խ���ؿ��ĵ���" << endl;
		cout << "���� ������� ���Ա��浱ǰ����" << endl;
		cout << "���� �˳���Ϸ �����˳���ǰ��Ϸ" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << mySorcerer->getRoom()->getName() << endl;
		cout << "�����ͼ�Ϸ�������ֿ��Խ���÷���" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map.showMap();
		cout << "���������ѡ��:" << endl;
		//ѡ��Ϊop
		string op = " ";
		cin >> op;
		if (op == "�鿴����") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "����ҩƷ") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "�鿴���� ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "�������") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "�������") {
			mySorcerer->setMyCheckPoint(6);
			//�ļ�����
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//����ùؿ��Ľ���
			ofstream tempFile;
			ofstream stateFile;
			//��Ϣ�������
			//����������Ϣ����
			tempFile.open(mySorcerer->getName() + ".txt");
			tempFile << mySorcerer->getDisguiseValue() << " "
				<< mySorcerer->getForceValue() << " "
				<< mySorcerer->getDefenceValue() << " "
				<< mySorcerer->getMagicValue() << " "
				<< mySorcerer->getBloodValue() << " "
				<< mySorcerer->getMoney() << " "
				<< mySorcerer->getName() << endl;
			tempFile << mySorcerer->getMagicitemNum() << " ";
			for (int i = 0; i < mySorcerer->getMagicitemNum(); i++) {
				tempFile << mySorcerer->getMagicitem()[i].getName() << " " << mySorcerer->getMagicitem()[i].getId() << endl;
			}
			tempFile << mySorcerer->getHorcruxNum() << " ";
			for (int i = 0; i < mySorcerer->getHorcruxNum(); i++) {
				tempFile << mySorcerer->getHorcrux()[i].getName() << " " << mySorcerer->getHorcrux()[i].getId() << endl;
			}
			tempFile << mySorcerer->getSkillNum() << " ";
			for (int i = 0; i < mySorcerer->getSkillNum(); i++) {
				tempFile << mySorcerer->getSkill()[i].getName() << " " << mySorcerer->getSkill()[i].getDamage() << endl;
			}
			tempFile << mySorcerer->getMedicineNum() << " ";
			for (int i = 0; i < mySorcerer->getMedicineNum(); i++) {
				tempFile << mySorcerer->getMedicine()[i].getName() << " " << mySorcerer->getMedicine()[i].getRecoverValue() << " " << mySorcerer->getMedicine()[i].getPrice() << endl;
			}
			tempFile << mySorcerer->getMyCheckpoint() << endl;
			cout << "����������Ϣ����ɹ�!" << endl;
			//�ؿ���Ϣ����
			stateFile.open(mySorcerer->getName() + "State" + ".txt");
			stateFile << shop.getMedicineNum() << " ";
			for (int i = 0; i < shop.getMedicineNum(); i++) {
				stateFile << shop.getMedicine()[i].getName() << " "
					<< shop.getMedicine()[i].getRecoverValue() << " "
					<< shop.getMedicine()[i].getPrice() << endl;
			}
			stateFile << shop.getSkillNum() << " ";
			for (int i = 0; i < shop.getSkillNum(); i++) {
				stateFile << shop.getSkill()[i].getName() << " "
					<< shop.getSkill()[i].getDamage() << " "
					<< shop.getSkill()[i].getPrice() << endl;
			}

			stateFile << gringotts.getBadPersonSize() << " ";
			for (int i = 0; i < gringotts.getBadPersonSize(); i++) {
				stateFile << gringotts.getBadPerson()[i].getName() << " "
					<< gringotts.getBadPerson()[i].getDown() << " "
					<< gringotts.getBadPerson()[i].getUp() << " "
					<< gringotts.getBadPerson()[i].getblood() << endl;
			}
			stateFile << " " << roomNum << endl;
			//0���� 1ħ���� 2����� �ĸ���ͼ�Ľ������
			stateFile << hall.getIfIn() << " "
				<< The_ministry_of_magic.getIfIn() << " "
				<< gringotts.getIfIn() << endl;
			//	//����
			mySorcerer->setMyCheckPoint(6);
			cout << "�ùؿ�״̬��Ϣ����ɹ���" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "�˳���Ϸ") {
			cout << "���Ѿ���������Ϸ��" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "����" && roomNum == hallWithNum.second || op == "ħ����" && roomNum == The_ministry_of_magicWithNum.second || op == "�����" && roomNum == gringottsWithNum.second) {
			system("cls");
			cout << "���Ѿ��ڸ�λ�ã�" << endl;
			//��ʽ������	
		}
		else if (op == "����" && link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "��ӭ��������~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&hall);
			//���صص����� 0���� 1ħ���� 2�����
		}
		else if (op == "����" && !link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ������������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == The_ministry_of_magicWithNum.second) {
								cout << The_ministry_of_magic.getName() << endl;
							}
							else if (tmp.y == gringottsWithNum.second) {
								cout << gringotts.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������	
		}
		else if (op == "ħ����" && link[roomNum][The_ministry_of_magicWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&The_ministry_of_magic);
			system("cls");
			cout << "��ӭ���� " << The_ministry_of_magic.getName() << endl;
			if (The_ministry_of_magic.getIfIn()) {
				cout << "��ӭ���ٴ����� " << The_ministry_of_magic.getName() << endl;
				cout << "�����Σ�����أ�" << endl;
			}
			else {
				//�������Ӧ�ݻ��ʲô�ȴ���ӡ�
				The_ministry_of_magic.inRoom();
				cout << "���ħ���ľ�ս�������٣�" << endl;
			}
		}
		else if (op == "ħ����" && !link[roomNum][The_ministry_of_magicWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ���ħ����������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == The_ministry_of_magicWithNum.second) {
								cout << The_ministry_of_magic.getName() << endl;
							}
							else if (tmp.y == gringottsWithNum.second) {
								cout << gringotts.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������	
		}
		else if (op == "�����" && link[roomNum][gringottsWithNum.second]) {
			roomNum = 2;
			mySorcerer->inRoom(&gringotts);
			system("cls");
			cout << "��ӭ���� " << gringotts.getName() << endl;
			gringotts.inRoom();
			cout << "�������������ս��ħ��ʦ����������㷽��ͨ��" << endl;
			string op_person = " ";
			bool ifWin = 0;
			cout << "������еĺ�ħ��ʦ������£�" << endl;
			for (int i = 0; i < gringotts.getBadPerson().size(); i++) {
				cout << i + 1 << ". " << gringotts.getBadPerson()[i].getName() << endl;
			}
			cout << "��������ѡ����Ҫ��֮ս���ĺ�ħ��ʦ����0���ܣ�" << endl;
			cin >> op_person;
			std::regex rx("[0-9]+");
			bool ifNum = std::regex_match(op_person.begin(), op_person.end(), rx);
			if (!ifNum) {
				cout << "������Ĳ������֣������뿪�÷��䣡" << endl;
				mySorcerer->inRoom(&hall);
				roomNum = 0;
				system("pause");
				system("cls");
			}
			else {
				int op_num = 0;
				stringstream s_temp;//�ַ�������ת��
				s_temp << op_person;
				s_temp >> op_num;
				if (op_num == 0) {
					cout << "��ɹ����ܣ�" << endl;
					mySorcerer->inRoom(&hall);
					roomNum = 0;
					system("pause");
					system("cls");
				}
				else if (!(op_num < gringotts.getBadPerson().size() + 1 && op_num > 0)) {
					cout << "�������,�����ڸú�ħ��ʦ��" << endl;
					system("pause");
					system("cls");
					mySorcerer->inRoom(&hall);
					roomNum = 0;
				}
				else {
					cout << "��׼����ս����" << gringotts.getBadPerson()[op_num - 1].getName() << "...ս��������ʼ��" << endl;
					system("pause");
					system("cls");
					ifWin = mySorcerer->battle(mySorcerer, gringotts.getBadPerson()[op_num - 1]);
					if (ifWin == 1) {
						cout << "��ϲ���������" << gringotts.getBadPerson()[op_num - 1].getName() << "����������Լӳɡ�" << endl;
						gringotts.eraseBadPerson(1);
						mySorcerer->inRoom(&hall);
						//д���Լӳ�������
						roomNum = 0;
					}
					else {
						mySorcerer->setBlood(0);
						cout << "�㱻���ܣ������״̬��������" << endl;
						//�����
						cout << "\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t   ��\t\t     ��\n\t\t\t   ��\t\t     ��\n\n\t\t   �˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\n\t\t   ��\t\t   ��\t\t   ��\t\n\t\t    ��\t\t   ��\t\t  ��\t\n\t\t     ��\t\t   ��\t\t ��\t\n\n\t\t\t\t   ��\n\t\t�˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲˲�\n\t\t\t\t   ��\n\t\t\t         �˲˲�\n\t\t\t       ��  ��  ��\n\t\t\t     ��    ��    ��\n\t\t\t   ��      ��      ��\n\t\t\t ��        ��        ��\n\t\t       ��          ��          ��\n\t\t     ��            ��            ��\n\t\t   ��              ��              ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n\t\t\t\t   ��\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&hall);
						//���صص����� 0���� 1ħ���� 2�����
						roomNum = 0;
					}
					if (gringotts.getBadPersonSize() == 0) {
						check = 0;
						system("pause");
						system("cls");
						cout << "��ϲ��ͨ�������ز����3000��Һ�һ�����������ӡ���������ı���" << endl;
						mySorcerer->addHorcrux(cup);
						mySorcerer->increaseMoney(3000);
					}
				}
			}
		}
		else if (op == "�����" && !link[roomNum][gringottsWithNum.second]) {
			system("cls");
			cout << "�����ڵĵ�ǰλ���޷�ֱ�ӵ�����������ϸ�۲��ͼ��" << endl;
			//bfs�ж���ͨ��
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // ��������
			bool vis[10][10] = { 0 }; // ���ʱ�ǡ��ҵ�ϰ���ϣ�ͳһ�������棬�����ڽṹ�����档
			struct node // BFS �����У�ÿһ����λ���ģ�״̬���ݽṹ��
			{
				int x, y;  // ����λ��
						  //����ע�⣬������ÿ����ĵ�λ��㣬����x��y�������������λ�á�
						  //��Щ�⣬һά�����Ա���Լ���λ����  �����磬ר��6  1004��
				int dpth; // ��¼�ýڵ�����
			};
			node temp[10];
			queue <node> q; // BFS ����
			node sta;   //������ʼ��
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // ����ʼ�����
			vis[sta.x][sta.y] = 1; // ���ʱ��
			while (!q.empty()) {
				node pro = q.front(); // ȡ����Ԫ��Ϊ���δ�����Ԫ�أ���Ϊ������չ�����
				q.pop();
				//�ҵ��𰸣�ֱ�����������������Ϊ:
				//�ǹ������������Խ����stepԽ�����������ҵ���step������С���Ǹ���
				for (int i = 0; i < 4; i++) {    //��չ��������Ѱ��ÿһ�����ڵ㡣
					node tmp;             //������һ��״̬
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // ���״̬����Լ�������������
					/*if (link[tmp.x][tmp.y] == 1)
						cout << tmp.x << " " << tmp.y << endl;*/
						if (tmp.x == roomNum && link[tmp.x][tmp.y] == 1) {
							if (tmp.y == hallWithNum.second) {
								cout << hall.getName() << endl;
							}
							else if (tmp.y == The_ministry_of_magicWithNum.second) {
								cout << The_ministry_of_magic.getName() << endl;
							}
							else if (tmp.y == gringottsWithNum.second) {
								cout << gringotts.getName() << endl;
							}
						}
						q.push(tmp);
						vis[tmp.x][tmp.y] = 1;   //���ʱ�ǣ����Ϊ�Ѿ��߹����߹��ĵ㲻���ظ��ߡ�
											   //���ס��ÿ�Σ�ֻҪ���ĳ���ڵ��������ˣ���Ҫ��Ǹýڵ��vis��
					}
				}
			}
			//��ʽ������	
		}
		else {
			system("cls");
			cout << "����ʧ�ܣ�" << endl;
			//��ʽ������
		}
	}
	return 1;
}

int Plot::initFinal(Sorcerer * mySorcerer, int myCheckPoint, bool ifNew) {
	//ҩˮ���� 1��2��2С
	//ҩˮ��Ŀ��Ҫ����һ����¼ ��¼�ĸ�ʽΪ X X X�ֱ�ָС�д�
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("Сҩˮ", 20, 400);
	Medicine medicineTempMiddle("��ҩˮ", 40, 800);
	Medicine medicineTempLarge("��ҩˮ", 60, 1200);
	if (!ifNew) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempLarge);
	}
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Imperio("Imperio", 100, 2500);
	Skill Crucio("Crucio", 70, 1200);
	if (myCheckPoint == 0) {
		skill.push_back(Imperio);
		skill.push_back(Crucio);
	}
	//һЩ�ж�;
	bool check = 1;
	//��ͼ
	Room hall("����");
	Room The_black_forest("��ɭ��");
	int roomNum = 0; //���浱ǰ���ڵķ����
	//�����ȵ���һ���ص�
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	Map map("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*����\t*\t<--------------->\t*��ɭ��\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********");
	//��������
	if (myCheckPoint != 7) {
		cout << "�վ�֮ս���������ħ�����֮ս��������������" << endl;
	}
	system("pause");
	system("cls");
	mySorcerer->inRoom(&hall);
	cout << "��ӭ�����վ�֮ս~" << endl;
	cout << "��Ŀǰ���ڵ�λ��: " << mySorcerer->getRoom()->getName() << endl;
	//��������
	BadPerson voldemort(1000, 50, 60, "����ħ");
	Shop shop(medicine, skill, "��ɭ��ħ����Ʒ��", medicine.size(), skill.size());
	if (ifNew) {
		cout << "��ӭ���ٴν�����Ϸ�������������߹ص����̡�" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//ҩˮ��ʼ��
		int medicineNum = 0;
		infile >> medicineNum;
		string medicineName = " ";
		int recoverValue = 0;
		int medicinePirce = 0;
		for (int i = 0; i < medicineNum; i++) {
			infile >> medicineName >> recoverValue >> medicinePirce;
			tempMedicine.setInformation(medicineName, recoverValue, medicinePirce);
			medicine.push_back(tempMedicine);
		}
		//���ܳ�ʼ��
		int skillNum = 0;
		infile >> skillNum;
		string skillName = " ";
		int skillDamage = 0;
		int skillPrice = 0;
		for (int i = 0; i < skillNum; i++) {
			infile >> skillName >> skillDamage >> skillPrice;
			tempSkill.setValue(skillName, skillDamage, skillPrice);
			skill.push_back(tempSkill);
		}

		//���������ʼ��
		infile >> roomNum;
		bool tempIsInRoom = 0;
		infile >> tempIsInRoom;
		hall.setIfIn(tempIsInRoom);
		infile >> tempIsInRoom;
		The_black_forest.setIfIn(tempIsInRoom);

		if (roomNum == 0) {
			mySorcerer->inRoom(&hall);
		}
		else if (roomNum == 1) {
			mySorcerer->inRoom(&The_black_forest);
		}
	}
	while (check) {
		//�������Ϸ������
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//��ʽ������
			system("cls");
		}
		system("pause");//��ʽ������
		system("cls");
		//��ʾ������
		cout << "���� �鿴���� ���Բ鿴��ǰ�Լ�������" << endl;
		cout << "���� ����ҩƷ ���Բ鿴��ʹ���Լ�ӵ�е�ҩƷ" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�е�ħ������" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ�ӵ�еļ���" << endl;
		cout << "���� �鿴���� ���Բ鿴�Լ�Ŀǰ�Ѿ��ռ��Ļ���" << endl;
		cout << "���� ������� ���Խ���ؿ��ĵ���" << endl;
		cout << "���� ������� ���Ա��浱ǰ����" << endl;
		cout << "���� �˳���Ϸ �����˳���ǰ��Ϸ" << endl;
		cout << "��Ŀǰ���ڵ�λ��Ϊ��" << mySorcerer->getRoom()->getName() << endl;
		cout << "�����ͼ�Ϸ�������ֿ��Խ���÷���" << endl;
		cout << "�˹ؿ��ĵ�ͼ��" << endl;
		map.showMap();
		cout << "���������ѡ��:" << endl;
			//ѡ��Ϊop
		string op = " ";
		cin >> op;
		if (op == "�鿴����") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "����ҩƷ") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "�鿴���� ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "�鿴����") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "�������") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "�������") {
			mySorcerer->setMyCheckPoint(1);
			//�ļ�����
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//����ùؿ��Ľ���
			ofstream tempFile;
			ofstream stateFile;
				//��Ϣ�������
				//����������Ϣ����
			tempFile.open(mySorcerer->getName() + ".txt");
			tempFile << mySorcerer->getDisguiseValue() << " "
				<< mySorcerer->getForceValue() << " "
				<< mySorcerer->getDefenceValue() << " "
				<< mySorcerer->getMagicValue() << " "
				<< mySorcerer->getBloodValue() << " "
				<< mySorcerer->getMoney() << " "
				<< mySorcerer->getName() << endl;
			tempFile << mySorcerer->getMagicitemNum() << " ";
			for (int i = 0; i < mySorcerer->getMagicitemNum(); i++) {
				tempFile << mySorcerer->getMagicitem()[i].getName() << " " << mySorcerer->getMagicitem()[i].getId() << endl;
			}
			tempFile << mySorcerer->getHorcruxNum() << " ";
			for (int i = 0; i < mySorcerer->getHorcruxNum(); i++) {
				tempFile << mySorcerer->getHorcrux()[i].getName() << " " << mySorcerer->getHorcrux()[i].getId() << endl;
			}
			tempFile << mySorcerer->getSkillNum() << " ";
			for (int i = 0; i < mySorcerer->getSkillNum(); i++) {
				tempFile << mySorcerer->getSkill()[i].getName() << " " << mySorcerer->getSkill()[i].getDamage() << endl;
			}
			tempFile << mySorcerer->getMedicineNum() << " ";
			for (int i = 0; i < mySorcerer->getMedicineNum(); i++) {
				tempFile << mySorcerer->getMedicine()[i].getName() << " " << mySorcerer->getMedicine()[i].getRecoverValue() << " " << mySorcerer->getMedicine()[i].getPrice() << endl;
			}
			tempFile << mySorcerer->getMyCheckpoint() << endl;
			cout << "����������Ϣ����ɹ�!" << endl;
			//�ؿ���Ϣ����
			stateFile.open(mySorcerer->getName() + "State" + ".txt");
			stateFile << shop.getMedicineNum() << " ";
			for (int i = 0; i < shop.getMedicineNum(); i++) {
				stateFile << shop.getMedicine()[i].getName() << " "
					<< shop.getMedicine()[i].getRecoverValue() << " "
					<< shop.getMedicine()[i].getPrice() << endl;
			}
			stateFile << shop.getSkillNum() << " ";
			for (int i = 0; i < shop.getSkillNum(); i++) {
				stateFile << shop.getSkill()[i].getName() << " "
					<< shop.getSkill()[i].getDamage() << " "
					<< shop.getSkill()[i].getPrice() << endl;
			}
			stateFile << " " << roomNum << endl;
			stateFile << hall.getIfIn() << " "
				<< The_black_forest.getIfIn() << endl;
				//	//����
			mySorcerer->setMyCheckPoint(1);
			cout << "�ùؿ�״̬��Ϣ����ɹ���" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "�˳���Ϸ") {
			cout << "���Ѿ���������Ϸ��" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "����" && roomNum == 0 || op == "��ɭ��" && roomNum == 1) {
			system("cls");
			cout << "���Ѿ��ڸ�λ�ã�" << endl;
				//��ʽ������	
		}
		else if (op == "����") {
			roomNum = 0;
			mySorcerer->inRoom(&hall);
			system("cls");
			cout << "��ӭ���� " << hall.getName() << endl;
			cout << "�����ħ��ʦ�ǣ�\n�¸ҵ�ȥ���ħ��ս���ɣ�\n" << endl;
		}
		else if (op == "��ɭ��") {
			roomNum = 1;
			mySorcerer->inRoom(&The_black_forest);
			system("cls");
			mySorcerer->inRoom(&The_black_forest);
			cout << "��ӭ������ɭ��" << endl;
				//��һЩ��
			cout << "��ʱ����ħ���ں�ɭ������Ƿ�ѡ���������֮ս" << endl;
			cout << "1.��		2.��" << endl;
			int op_forest = 0;
			bool ifWin = 0;
			cin >> op_forest;
			system("cls");
			if (op_forest == 1) {
				ifWin = mySorcerer->battle(mySorcerer, voldemort);
				if (ifWin == 1) {
					//�ɹ���ܵĻ�
					check = 0;
					cout << "��ɹ��شݻ������л�����" << endl;
					cout << "������˺�ħ����" << endl;

				}
				else if (ifWin == 0) {
					mySorcerer->setBlood(0);
					cout << "��սʧ�ܣ�" << endl;
					mySorcerer->inRoom(&hall);
						//���صص����� 0���� 1ħ���� 2�����
					roomNum = 0;
					}
				}
				else if (op_forest == 2) {
					cout << "��ɹ����롣" << endl;
					mySorcerer->inRoom(&hall);
				}
				else {
					cout << "����ʧ�ܣ����Ѿ��˳����䡣" << endl;
					mySorcerer->inRoom(&hall);
				}
			}
			else {
				cout << "�������" << endl;
			}
			cout << "��ϲ��ͨ�����йؿ�" << endl;
			system("pause");
			system("cls");
	}
	return 1;
}