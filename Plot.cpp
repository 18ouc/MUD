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
	cout << "请输入你要设置的角色名字：" << endl;
	cin >> name;
	while (1) {
		cout << "请选择你的想获得的人物属性加成:" << endl;
		cout << "1.战士系		 2.坦克系 			3.巫术系" << endl;
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
			cout << "输入错误！请重新输入！" << endl;
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






int Plot::init1(Sorcerer * mySorcerer, int myCheckPoint, bool ifNew) {	//第一关
	//本关剧情格式化记录
	//小药水数目 中药水数目 大药水数目 技能 ifPassMaze  roomNum 0大厅 1校长室 2阁楼 3地穴四个地图的进入情况
	//bool end = 0;	//
	//开局送的礼物
	if (ifNew == 0) {
		cout << "魔法师们，为了让你们变得更加强大！我们给了你一件礼物。" << endl;
		Magicitem magicStick("魔法棍", 1);
		mySorcerer->addMagicitem(magicStick);
		//格式化操作
		system("pause");
		system("cls");
	}
	//初始化魂器
	Horcrux ring("马沃罗·冈特的戒指");
	//药水设置 1大2中2小
	//药水数目需要进行一个记录 记录的格式为 X X X分别指小中大
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("小药水", 20, 400);
	Medicine medicineTempMiddle("中药水", 40, 800);
	Medicine medicineTempLarge("大药水", 60, 1200);
	if (ifNew == 0) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
	}
	//超市里技能设置
	//咒语：盔甲护身（盔甲咒）:Protego ：15 600 门牙赛大棒（长出长牙） : Densaugeo：12  400
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Protego("Protego", 15, 600);
	Skill Densaugeo("Densaugeo", 12, 400);
	if (myCheckPoint == 0) {
		skill.push_back(Protego);
		skill.push_back(Densaugeo);
	}
	//超市设置
	//本关魔法咒语设置
	Skill Alohomora("Alohomora", 60);
	//一些判断
	bool check = 1;		//判断是否通关
	bool ifKillKerberos = 0;	//判断是否打败三头狗
	//本关地点设置
	Room hall("大厅");
	Room President_Office("校长室");
	Room Crypt("地穴");
	Room Attic("阁楼");
	int roomNum = 0; //储存当前所在的房间号
	//开局先到达一个地点
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	//地图设置 编号为0大厅 1校长室 2阁楼 3地穴
	Map map("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*大厅\t*\t<--------------->\t*阁楼\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t   /\\\t\t\t\t\t   /\\\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   ||\t\t\t\t\t   ||\n\t   \\/\t\t\t\t\t   \\/\n\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*校长室\t*\t\t\t\t*地穴\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********");
	if (myCheckPoint == 0) {
		//开局背景故事
		cout << "从小被寄养在姨妈家里的哈利波特\n饱受姨妈一家人的歧视与欺侮\n然而就在11岁生日那天\n哈利波特得知了自己原本是巫师\n并且被录取为霍格沃茨魔法学校中的一员。\n登上霍格沃茨特快列车\n哈利开始了他的魔幻旅程在这里他无意间发现了魔法石的秘密。。。。。。" << endl;
		//格式化处理
		system("pause");
		system("cls");
		//开局背景故事
		cout << "欢迎进入第一关~" << endl;
		cout << "恭喜你在开局获得了一个咒语，你可以通过它进入某个房间..." << endl;
	}
	//人物设置
	GoodPerson Dumbledore("邓布利多", "明天镜子就要搬到一个新的地方了，哈利，我请你不要再去找它了。如果你哪天碰巧看见它，你要有心理准备。\n");
	President_Office.addGoodPerson(Dumbledore);
	BadPerson Chiro(100, 30, 45, "奇洛");
	BadPerson Kerberos(50, 15, 20, "三头狗");
	Crypt.addBadPerson(Chiro);
	//使用pair绑定
	pair<string, int> hallWithNum("大厅", 0);
	pair<string, int> President_OfficeWithNum("校长室", 1);
	pair<string, int> AtticWithNum("阁楼", 2);
	pair<string, int> CryptWithNum("地穴", 3);
	//判断连通情况	link[A][B] = 1代表A->B是通的
	//邻接矩阵
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
		cout << "欢迎你再次进入游戏，继续开启第一关的征程。" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//药水初始化
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
		//技能初始化
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
		//其它杂项初始化
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
	Shop shop(medicine, skill, "西皮士魔术用品店", medicine.size(), skill.size());
	//主要程序
	while (check) {
		//如果在游戏中死亡
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//格式化处理
			system("cls");
		}
		system("pause");//格式化处理
		system("cls");
		//提示语输入
		cout << "输入 查看属性 可以查看当前自己的属性" << endl;
		cout << "输入 查用药品 可以查看或使用自己拥有的药品" << endl;
		cout << "输入 查看道具 可以查看自己目前已经拥有的魔法道具" << endl;
		cout << "输入 查看技能 可以查看自己目前已经拥有的技能" << endl;
		cout << "输入 查看魂器 可以查看自己目前已经收集的魂器" << endl;
		cout << "输入 进入店铺 可以进入关卡的店铺" << endl;
		cout << "输入 保存进度 可以保存当前进度" << endl;
		cout << "输入 退出游戏 可以退出当前游戏" << endl;
		cout << "你目前所在的位置为：" << mySorcerer->getRoom()->getName() << endl;
		cout << "输入地图上房间的名字可以进入该房间" << endl;
		cout << "此关卡的地图：" << endl;
		map.showMap();
		cout << "请输入你的选择:" << endl;
		//选择为op
		string op = " ";
		cin >> op;
		if (op == "查看属性") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "查用药品") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "查看道具 ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "查看技能") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "查看魂器") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "进入店铺") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "保存进度") {
			mySorcerer->setMyCheckPoint(1);
			//文件处理
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//保存该关卡的进度
			ofstream tempFile;
			ofstream stateFile;
			//信息保存操作
			//本身属性信息保存
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
			cout << "人物属性信息保存成功!" << endl;
			//关卡信息保存
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
				//0大厅 1校长室 2阁楼 3地穴四个地图的进入情况
			stateFile << hall.getIfIn() << " "
				<< President_Office.getIfIn() << " "
				<< Attic.getIfIn() << " "
				<< Crypt.getIfIn() << endl;
			//	//店铺
			mySorcerer->setMyCheckPoint(1);
			cout << "该关卡状态信息保存成功！" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "退出游戏") {
			cout << "你已经结束该游戏。" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "大厅" && roomNum == hallWithNum.second || op == "地穴" && roomNum == CryptWithNum.second || op == "阁楼" && roomNum == AtticWithNum.second || op == "校长室" && roomNum == President_OfficeWithNum.second) {
			system("cls");
			cout << "你已经在该位置！" << endl;
			//格式化操作	
		}
		else if (op == "校长室" && link[roomNum][President_OfficeWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&President_Office);
			system("cls");
			cout << "欢迎来到 " << President_Office.getName() << endl;
			if (President_Office.getIfIn()) {
				cout << "欢迎您再次来到 " << President_Office.getName() << endl;
			}
			else {
				cout << "\n" << Dumbledore.getName() << "：" << Dumbledore.getSentence() << endl;
				cout << "在与" << Dumbledore.getName() << "进行完谈话之后， 获得了一个咒语。" << endl;
				mySorcerer->addSkill(Alohomora);
				President_Office.inRoom();
			}
		}
		else if (op == "校长室" && !link[roomNum][President_OfficeWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达校长室，请仔细观察地图！" << endl;
			cout << "你目前能到达的位置有：" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;

					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "阁楼" && link[roomNum][AtticWithNum.second]) {
			mySorcerer->inRoom(&Attic);
			roomNum = 2;
			system("cls");
			if (Attic.getIfIn()) {
				cout << "欢迎您再次来到 " << Attic.getName() << endl;
			}
			else {
				cout << "欢迎来到 " << Attic.getName() << endl;
				cout << "此时三头狗正在看守某个房间，你是否选择与它进行战斗？" << endl;
				cout << "1.是		2.否" << endl;
				int op_Attic = 0;
				cin >> op_Attic;
				system("cls");
				if (op_Attic == 1) {
					cout << "战斗已经开始！" << endl;
					bool ifWin = 1;
					ifWin = mySorcerer->battle(mySorcerer, Kerberos);
					if (ifWin) {
						system("pause");
						system("cls");
						cout << "你通过战斗轻松解决了" << Kerberos.getName() << "。并获得了能进入地穴的咒语......" << endl;
						Attic.inRoom();
						ifKillKerberos = 1;
					}
					else {
						mySorcerer->setBlood(0);
						//输出菜
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&hall);
						roomNum = 0;
					}
				}
				else {
					cout << "你成功逃跑至大厅" << endl;
					mySorcerer->inRoom(&hall);
					roomNum = 0;
				}
			}
		}
		else if (op == "阁楼" && !link[roomNum][AtticWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达阁楼，请仔细观察地图！" << endl;
			cout << "你目前能到达的位置有：" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;

					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "地穴" && link[roomNum][CryptWithNum.second]) {
			system("cls");
			if (ifKillKerberos) {
				roomNum = 3;
				mySorcerer->inRoom(&Crypt);
				cout << "通过咒语你进入了地穴。" << endl;
				cout << "欢迎来到地穴~" << endl;
				cout << "此时奇洛正在镜子旁，你是否选择与它进行战斗？" << endl;
				cout << "1.是		2.否" << endl;
				int op_Crypt = 0;
				cin >> op_Crypt;
				system("cls");
				if (op_Crypt == 1) {
					bool ifWin = 0;
					cout << "战斗开始，你已进入战斗模式..." << endl;
					ifWin = mySorcerer->battle(mySorcerer, Chiro);
					if (ifWin) {
						cout << "恭喜你成功通过第一关并获得了1000金币和一个魂器。" << endl;
						mySorcerer->increaseMoney(1000);
						mySorcerer->addHorcrux(ring);
						check = 0;
						system("pause");
						system("cls");
					}
					else {
						mySorcerer->inRoom(&hall);
						mySorcerer->setBlood(0);
						//输出菜
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n"  << endl;
						system("pause");
						system("cls");
					}
				}
				else if (op_Crypt == 2) {
					cout << "你已经逃离战斗。" << endl;
					mySorcerer->inRoom(&Attic);
					roomNum = 2;
				}
				else {
					cout << "操作失败，你已退出该房间！" << endl;
					mySorcerer->inRoom(&Attic);
					roomNum = 2;
				}
			}
			else {
				cout << "由于你没有打败三头狗，无法进入地穴" << endl;
			}
		}
		else if (op == "地穴" && !link[roomNum][CryptWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达地穴，请仔细观察地图！" << endl;
			cout << "你目前能到达的位置有：" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()){
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;

					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作	
		}
		else if (op == "大厅" && link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "欢迎来到大厅~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&hall);
		}
		else if (op == "大厅" && !link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达大厅，请仔细观察地图！" << endl;
			cout << "你目前能到达的位置有：" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;

					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作	
		}
		else {
			system("cls");
			cout << "操作失败！" << endl;
			//格式化操作	
		}
	}
	return 1;
}




int Plot::init2(Sorcerer *mySorcerer, int myCheckPoint, bool ifNew) {
	//本关剧情格式化记录
	//小药水数目 中药水数目 大药水数目 技能 ifKillKerberos roomNum 0大厅 1校长室 2阁楼 3地穴四个地图的进入情况
	//药水设置 2大2中2小
	//药水数目需要进行一个记录 记录的格式为 X X X分别指小中大
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("小药水", 20, 400);
	Medicine medicineTempMiddle("中药水", 40, 800);
	Medicine medicineTempLarge("大药水", 60, 1200);
	if (ifNew == 0) {
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempLarge);
	}
	//超市里技能设置
	//咒语：火焰熊熊（火焰咒）:Incendio：15  600
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Incendio("Incendio", 15, 800);
	if (myCheckPoint != 2) {
		skill.push_back(Incendio);
	}
	//一些判断
	bool check = 1;
	//一些装备
	Magicitem phoenix("凤凰", 2);
	//魂器
	Horcrux diary("汤姆·里德尔的日记");
	//本关地点设置
	Room Crypt("地穴");
	Room bathroom("洗手间");
	Room hathouse("帽子屋");
	Room chamber("密室");
	int roomNum = 0;
	mySorcerer->inRoom(&Crypt);
	//地图设置 0地穴 1洗手间 2帽子屋 3密室
	Map map("\t*********\t\t\t\t*********\t\t\t*********\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*地穴\t*\t<--------------->\t*洗手间\t*\t<---------->\t*密室\t*\n\t*\t*\t\t\t\t*\t*\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t*********\n\t  /\\\t\t\t\t\t   /\\\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t*********\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*帽子屋\t*<===================================\n\t*\t*\n\t*********");
	if (ifNew == 0) {
		//开局背景故事
		cout << "学校发生了一系列“恐怖”事件—学生莫名其妙被石化\n墙上出现了恐怖的血字...\n人们怀疑是蛇怪所为\n传说中的密室被斯莱特林的继承人打开\n哈利因为会蛇佬腔被所有人怀疑。。。。。。。" << endl;
		system("pause");
		system("cls");
		cout << "欢迎进入第二关~" << endl;
		cout << "据说与洗手间的桃金娘对话可以获得神秘的东西..." << endl;
	}
	//人物设置
	GoodPerson Moaning_Myrtle("桃金娘", "盥洗池里有神奇的东西...当时我就是因为看到它的眼睛而...\n");
	bathroom.addGoodPerson(Moaning_Myrtle);
	BadPerson Basilisk(100, 20, 30, "蛇怪");
	chamber.addBadPerson(Basilisk);
	//使用pair绑定
	pair<string, int> CryptWithNum("地穴", 0);
	pair<string, int> bathroomWithNum("洗手间", 1);
	pair<string, int> hathouseWithNum("帽子屋", 2);
	pair<string, int> chamberWithNum("密室", 3);
	//判断连通情况	link[A][B] = 1代表A->B是通的
	//邻接矩阵
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
		cout << "欢迎你再次进入游戏，继续开启第二关的征程。" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//药水初始化
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
		//技能初始化
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
		//其它杂项初始化
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
	Shop shop(medicine, skill, "奥利范德魔法用品店", medicine.size(), skill.size());
	while (check) {
		//如果在游戏中死亡
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//格式化处理
			system("cls");
		}
		system("pause");
		system("cls");
		cout << "输入 查看属性 可以查看当前自己的属性" << endl;
		cout << "输入 查用药品 可以查看或使用自己拥有的药品" << endl;
		cout << "输入 查看道具 可以查看自己目前已经拥有的魔法道具" << endl;
		cout << "输入 查看技能 可以查看自己目前已经拥有的技能" << endl;
		cout << "输入 查看魂器 可以查看自己目前已经收集的魂器" << endl;
		cout << "输入 进入店铺 可以进入关卡的店铺" << endl;
		cout << "输入 保存进度 可以保存当前进度" << endl;
		cout << "输入 退出游戏 可以退出当前游戏" << endl;
		cout << "你目前所在的位置为：" << mySorcerer->getRoom()->getName() << endl;
		cout << "输入地图上房间的名字可以进入该房间" << endl;
		cout << "此关卡的地图：" << endl;
		map.showMap();
		cout << "请输入你的选择:" << endl;
		string op = " ";
		cin >> op;
		if (op == "查看属性") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "查用药品") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "查看道具") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "查看技能") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "查看魂器") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "进入店铺") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "保存进度") {
			mySorcerer->setMyCheckPoint(2);
			//文件处理
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//保存该关卡的进度
			ofstream tempFile;
			ofstream stateFile;
			//信息保存操作
			//本身属性信息保存
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
			cout << "人物属性信息保存成功!" << endl;
			//关卡信息保存
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
			//0地穴 1洗手间 2帽子屋 3密室四个地图的进入情况
			stateFile << Crypt.getIfIn() << " "
				<< bathroom.getIfIn() << " "
				<< hathouse.getIfIn() << " "
				<< chamber.getIfIn() << endl;
			//	//店铺
			mySorcerer->setMyCheckPoint(2);
			cout << "该关卡状态信息保存成功！" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "退出游戏") {
			cout << "你已经结束该游戏。" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		//0地穴 1洗手间 2帽子屋 3密室
		else if (op == "地穴" && roomNum == CryptWithNum.second || op == "洗手间" && roomNum == bathroomWithNum.second || op == "帽子屋" && roomNum == hathouseWithNum.second || op == "校长室" && roomNum == chamberWithNum.second) {
			system("cls");
			cout << "你已经在该位置！" << endl;
			//格式化操作	
		}
		else if (op == "洗手间" && link[roomNum][bathroomWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&bathroom);
			system("cls");
			if (bathroom.getIfIn()) {
				cout << "欢迎您再次来到 " << bathroom.getName() << endl;
			}
			else {
				cout << "欢迎来到 " << bathroom.getName() << endl;
				cout << "\n" << Moaning_Myrtle.getName() << "：" << Moaning_Myrtle.getSentence() << endl;
				cout << "在与" << Moaning_Myrtle.getName() << "进行完谈话之后， 发现自己拥有蛇语。" << endl;
				bathroom.inRoom();
			}
		}
		else if (op == "洗手间" && !link[roomNum][bathroomWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达洗手间，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "帽子屋" && link[roomNum][hathouseWithNum.second]) {
			roomNum = 2;
			mySorcerer->inRoom(&hathouse);
			system("cls");
			if (hathouse.getIfIn()) {
				cout << "欢迎您再次来到 " << hathouse.getName() << endl;
			}
			else {
				cout << "欢迎来到 " << hathouse.getName() << endl;
				cout << "只有真正的勇士才能得到" << phoenix.getName() << endl;
				cout << "你是真正的勇士！" << endl;
				mySorcerer->addMagicitem(phoenix);
				hathouse.inRoom();
			}
		}
		else if (op == "帽子屋" && !link[roomNum][hathouseWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达帽子屋，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "密室" && link[roomNum][chamberWithNum.second]) {
			roomNum = 3;
			mySorcerer->inRoom(&chamber);
			system("cls");
			cout << "欢迎来到 " << chamber.getName() << endl;
			cout << "此时汤姆正在密室里，你是否选择与它进行对话？" << endl;
			cout << "1.是		2.否" << endl;
			int op_chamber = 0;
			cin >> op_chamber;
			system("cls");
			if (op_chamber == 1) {
				cout << "我是 Tom Marvolo Riddle，换言之我是 Lord Voldemort(伏地魔)！！！\n丝丝斯斯~\n他通过蛇语召唤出了蛇怪。。。" << endl;
				bool ifWin = 1;
				ifWin = mySorcerer->isHasTheMagicitem(2);
				if (ifWin) {
					system("pause");
					system("cls");
					cout << "你通过凤凰戳瞎了" << Basilisk.getName() << "的眼睛。可以与它进行战斗......" << endl;
					system("pause");
					system("cls");
					cout << "此时蛇妖战斗力被大削，你是否选择与它进行战斗？" << endl;
					cout << "1.是		2.否" << endl;
					int op_Basilisk = 0;
					cin >> op_Basilisk;
					system("cls");
					if (op_Basilisk == 1) {
						bool ifWin = 0;
						cout << "战斗开始，你已进入战斗模式..." << endl;
						ifWin = mySorcerer->battle(mySorcerer, Basilisk);
						if (ifWin) {
							cout << "恭喜你成功通过第二关并获得了1500金币和一个魂器。";
							mySorcerer->increaseMoney(1500);
							mySorcerer->addHorcrux(diary);
							check = 0;
							system("pause");
							system("cls");
						}
						else {
							mySorcerer->inRoom(&Crypt);
							mySorcerer->setBlood(0);
							//输出菜
							cout << "\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\n\t\t   菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\n\t\t   菜\t\t   菜\t\t   菜\t\n\t\t    菜\t\t   菜\t\t  菜\t\n\t\t     菜\t\t   菜\t\t 菜\t\n\n\t\t\t\t   菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t\t   菜\n\t\t\t         菜菜菜\n\t\t\t       菜  菜  菜\n\t\t\t     菜    菜    菜\n\t\t\t   菜      菜      菜\n\t\t\t 菜        菜        菜\n\t\t       菜          菜          菜\n\t\t     菜            菜            菜\n\t\t   菜              菜              菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n" << endl;
							system("pause");
							system("cls");
							mySorcerer->inRoom(&bathroom);
							roomNum = bathroomWithNum.second;
						}
					}
					else if (op_Basilisk == 2) {
						cout << "你已经逃离战斗。" << endl;
						mySorcerer->inRoom(&bathroom);
						roomNum = bathroomWithNum.second;
					}
					else {
						cout << "操作失败，你已退出该房间！" << endl;
						mySorcerer->inRoom(&bathroom);
						roomNum = bathroomWithNum.second;
					}
				}
				else {
					cout << "你被蛇妖的眼睛秒杀。。。\n" << endl;
					mySorcerer->inRoom(&Crypt);
					mySorcerer->setBlood(0);
					//输出菜
					cout << "\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\n\t\t   菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\n\t\t   菜\t\t   菜\t\t   菜\t\n\t\t    菜\t\t   菜\t\t  菜\t\n\t\t     菜\t\t   菜\t\t 菜\t\n\n\t\t\t\t   菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t\t   菜\n\t\t\t         菜菜菜\n\t\t\t       菜  菜  菜\n\t\t\t     菜    菜    菜\n\t\t\t   菜      菜      菜\n\t\t\t 菜        菜        菜\n\t\t       菜          菜          菜\n\t\t     菜            菜            菜\n\t\t   菜              菜              菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n" << endl;
					system("pause");
					system("cls");
					mySorcerer->inRoom(&bathroom);
					//roomNum = 3;
					roomNum = bathroomWithNum.second;
				}
			}
			else if (op_chamber == 2) {
				cout << "你已经逃离与他对话。" << endl;
				mySorcerer->inRoom(&bathroom);
				roomNum = bathroomWithNum.second;
			}
			else {
				cout << "操作失败，你已退出该房间！" << endl;
				mySorcerer->inRoom(&bathroom);
				roomNum = bathroomWithNum.second;
			}
		}
		else if (op == "密室" && !link[roomNum][chamberWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达密室，请仔细观察地图！" << endl;
			cout << "你目前能到达的地点为：" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "地穴" && link[roomNum][CryptWithNum.second]) {
			system("cls");
			cout << "欢迎来到地穴~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&Crypt);
		}
		else if (op == "地穴" && !link[roomNum][CryptWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达地穴，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作	
		}
		else {
			system("cls");
			cout << "操作失败！" << endl;
			//格式化操作	
		}
	}
	return 1;
}






int Plot::init3(Sorcerer * mySorcerer, int myCheckPoint, bool ifNew) {
	//本关剧情格式化记录
	//小药水数目 中药水数目 大药水数目 技能 ifKillKerberos roomNum 0大厅 1校长室 2阁楼 3地穴四个地图的进入情况
	
	//药水设置
	Medicine tempMedicine(" ", 0, 0);
	vector<Medicine> medicine;
	Medicine medicineTempSmall("小药水", 20, 400);	
	Medicine medicineTempMiddle("中药水", 40, 800);
	Medicine medicineTempLarge("大药水", 60, 1200);
	if (ifNew == 0) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
	}
	//超市里技能设置
	//咒语：粉身碎骨（粉碎咒）:Reducto：20 800
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Reducto("Reducto", 20, 1000);
	if (myCheckPoint != 3) {
		skill.push_back(Reducto);
	}
	//魂器
	Horcrux locket("萨拉札·斯莱特林的挂坠盒");
	//一些判断
	bool check = 1;
	bool ifKillPettigrew = 0;
	//本关地点设置 0密室 1礼堂 2别墅 3湖泊	
	Room chamber("密室");
	Room auditorium("礼堂");
	Room villa("别墅");
	Room lakes("湖泊");
	int roomNum = 0; //储存当前所在的房间号
	mySorcerer->inRoom(&chamber);
	Map map("\t*********\t\t\t\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*别墅\t*\t<--------------->\t*礼堂\t*\t<--------------->\t*密室\t*\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t\t*********\n\t  /\\\t\t\t\t\t   /\\\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t*********\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*湖泊\t*====================================\n\t*\t*\n\t*********");
	if (!ifNew) {
		cout << "得知阿兹卡班罪犯小天狼星逃出监狱\n而哈利等人在去霍格莫德时无意中听到是小天狼星背叛了哈利的父母\n使其遭到了伏地魔的杀害\n后来小天狼星出现，点明了事情真相-他没有被判哈利的父母，而是小矮星彼得背叛后将一切罪名转移到了他的身上。。。。。。。。。。" << endl;
		//背景故事
		system("pause");
		system("cls");
		cout << "欢迎进入第三关~" << endl;
	}
	//人物设置
	GoodPerson Sirius("小天狼星", "我跟詹姆斯和莉莉在一起那么久，你却没有，是很残忍。...\n");
	GoodPerson Snape("斯内普", "事情远远没有你想象的那么简单。\n");
	villa.addGoodPerson(Sirius);
	BadPerson pettigrew(100, 20, 30, "小矮星");
	BadPerson dementor(150, 30, 40, "摄魂怪");
	villa.addBadPerson(pettigrew);
	lakes.addBadPerson(dementor);
	//使用pair绑定
	pair<string, int> chamberWithNum("密室", 0);
	pair<string, int> auditoriumWithNum("礼堂", 1);
	pair<string, int> villaWithNum("别墅", 2);
	pair<string, int> lakesWithNum("湖泊", 3);
	//判断连通情况	link[A][B] = 1代表A->B是通的
	//邻接矩阵
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
		cout << "欢迎你再次进入游戏，继续开启第三关的征程。" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//药水初始化
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
		//技能初始化
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
		//其它杂项初始化
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
	Shop shop(medicine, skill, "伊拉猫头鹰魔法用品店", medicine.size(), skill.size());

	while (check) {
		//如果在游戏中死亡
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//格式化处理
			system("cls");
		}
		system("pause");//格式化处理
		system("cls");
		//提示语输入
		cout << "输入 查看属性 可以查看当前自己的属性" << endl;
		cout << "输入 查用药品 可以查看或使用自己拥有的药品" << endl;
		cout << "输入 查看道具 可以查看自己目前已经拥有的魔法道具" << endl;
		cout << "输入 查看技能 可以查看自己目前已经拥有的技能" << endl;
		cout << "输入 查看魂器 可以查看自己目前已经收集的魂器" << endl;
		cout << "输入 进入店铺 可以进入关卡的店铺" << endl;
		cout << "输入 保存进度 可以保存当前进度" << endl;
		cout << "输入 退出游戏 可以退出当前游戏" << endl;
		cout << "你目前所在的位置为：" << mySorcerer->getRoom()->getName() << endl;
		cout << "输入地图上房间的名字可以进入该房间" << endl;
		cout << "此关卡的地图：" << endl;
		map.showMap();
		cout << "请输入你的选择:" << endl;
		string op = " ";
		cin >> op;
		if (op == "查看属性") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "查用药品") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "查看道具 ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "查看技能") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "查看魂器") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "进入店铺") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "保存进度") {
			mySorcerer->setMyCheckPoint(3);
			//文件处理
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//保存该关卡的进度
			ofstream tempFile;
			ofstream stateFile;
			//信息保存操作
			//本身属性信息保存
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
			cout << "人物属性信息保存成功!" << endl;
			//关卡信息保存
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
			//0密室 1礼堂 2别墅 3湖泊四个地图的进入情况
			stateFile << chamber.getIfIn() << " "
				<< auditorium.getIfIn() << " "
				<< villa.getIfIn() << " "
				<< lakes.getIfIn() << endl;
			//	//店铺
			mySorcerer->setMyCheckPoint(3);
			cout << "该关卡状态信息保存成功！" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "退出游戏") {
			cout << "你已经结束该游戏。" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "密室" && roomNum == chamberWithNum.second || op == "礼堂" && roomNum == auditoriumWithNum.second || op == "别墅" && roomNum == villaWithNum.second || op == "湖泊" && roomNum == lakesWithNum.second) {
			system("cls");
			cout << "你已经在该位置！" << endl;
			//格式化操作	
		}
		else if (op == "礼堂" && link[roomNum][auditoriumWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&auditorium);
			system("cls");
			cout << "欢迎来到 " << auditorium.getName() << endl;
			if (auditorium.getIfIn()) {
				cout << "欢迎您再次来到 " << auditorium.getName() << endl;
			}
			else {
				cout << "在霍格沃兹城堡外，你终于见到了传闻已久的小天狼星布莱克，虽然你与他搏斗，可他一味忍让，你感到疑惑，于是你停下和他对话" << endl;
				cout << "布莱克：我追杀的一直都是宠物斑斑，并不是你，那个斑斑是小矮星彼得变得，是他当年向伏地魔出卖你父母的行程的。" << endl;
				cout << "你听着布莱克的娓娓道来，渐渐相信了他。。。。" << endl;
				cout << "你：那我们现在该怎么办？" << endl;
				cout << "布莱克：我们需要去别墅找小矮星，我要证明自己的清白，我是你的教父" << endl;
				cout << "\n" << Snape.getName() << "：" << Snape.getSentence() << endl;
				cout << "在与" << Snape.getName() << "进行完谈话之后， 你发现这里有一个巨大的阴谋。" << endl;
				auditorium.inRoom();
			}
		}
		else if (op == "礼堂" && !link[roomNum][auditoriumWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达礼堂，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "别墅" && link[roomNum][villaWithNum.second]) {
			roomNum = 2;
			mySorcerer->inRoom(&villa);
			system("cls");
			if (villa.getIfIn()) {
				cout << "欢迎您再次来到 " << villa.getName() << endl;
			}
			else {
				cout << "欢迎来到 " << villa.getName() << endl;
				villa.inRoom();
				//与小矮星进行战斗
				cout << "此时小矮星正准备逃跑，你是否选择与它进行战斗？" << endl;
				cout << "1.是		2.否" << endl;
				int op_pettigrew = 0;
				cin >> op_pettigrew;
				system("cls");
				if (op_pettigrew == 1) {
					cout << "战斗已经开始！" << endl;
					bool ifWin = 1;
					ifWin = mySorcerer->battle(mySorcerer, pettigrew);
					if (ifWin) {
						system("pause");
						system("cls");
						cout << "你通过战斗消耗了" << pettigrew.getName() << "的大部分力量。但是小天狼星逃到了湖泊......" << endl;
						system("pause");
						system("cls");
						ifKillPettigrew = 1;
					}
					else {
						cout << "你被小矮星击败，建议再购买点儿装备进行战斗。" << endl;
						mySorcerer->setBlood(0);
						//输出菜
						cout << "\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\n\t\t   菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\n\t\t   菜\t\t   菜\t\t   菜\t\n\t\t    菜\t\t   菜\t\t  菜\t\n\t\t     菜\t\t   菜\t\t 菜\t\n\n\t\t\t\t   菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t\t   菜\n\t\t\t         菜菜菜\n\t\t\t       菜  菜  菜\n\t\t\t     菜    菜    菜\n\t\t\t   菜      菜      菜\n\t\t\t 菜        菜        菜\n\t\t       菜          菜          菜\n\t\t     菜            菜            菜\n\t\t   菜              菜              菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&auditorium);
						roomNum = auditoriumWithNum.second;
					}
				}
				else if (op_pettigrew == 2) {
					cout << "你已经逃离该房间。小矮星成功逃跑" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = auditoriumWithNum.second;
				}
				else {
					cout << "操作失败，你已退出该房间！" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = auditoriumWithNum.second;
				}
			}	
		}
		else if (op == "别墅" && !link[roomNum][villaWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达别墅，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "湖泊" && link[roomNum][lakesWithNum.second]) {
			system("cls");
			if (ifKillPettigrew) {
				roomNum = 3;
				mySorcerer->inRoom(&lakes);
				cout << "你进入了湖泊。" << endl;
				cout << "欢迎来到湖泊~" << endl;
				cout << "此时摄魂怪正在袭击小天狼星，你是否选择与它进行战斗？" << endl;
				cout << "1.是		2.否" << endl;
				int op_dementor = 0;
				cin >> op_dementor;
				system("cls");
				if (op_dementor == 1) {
					bool ifWin = 0;
					cout << "战斗开始，你已进入战斗模式..." << endl;
					ifWin = mySorcerer->battle(mySorcerer, dementor);
					if (ifWin) {
						cout << "恭喜你成功通过第三关并获得了2000金币和一个魂器。" << endl;
						mySorcerer->addHorcrux(locket);
						mySorcerer->increaseMoney(2000);
						check = 0;
						system("pause");
						system("cls");
					}
					else {
						mySorcerer->inRoom(&auditorium);
						mySorcerer->setBlood(0);
						//输出菜
						cout << "\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\t\t*****************************************\n\t\t\t   *\t\t     *\n\t\t\t   *\t\t     *\n\n\t\t   ***********************************\n\n\t\t   *\t\t   *\t\t   *\t\n\t\t    *\t\t   *\t\t  *\t\n\t\t     *\t\t   *\t\t *\t\n\n\t\t\t\t   *\n\t\t*****************************************\n\t\t\t\t   *\n\t\t\t          ***\n\t\t\t        *  *  *\n\t\t\t      *    *    *\n\t\t\t    *      *      *\n\t\t\t  *        *        *\n\t\t\t*          *          *\n\t\t      *            *            *\n\t\t    *              *              *\n\t\t\t\t   *\n\t\t\t\t   *\n\t\t\t\t   *\n" << endl;
						system("pause");
						system("cls");
						roomNum = 1;
					}
				}
				else if (op_dementor == 2) {
					cout << "你已经逃离战斗。" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = 1;
				}
				else {
					cout << "操作失败，你已退出该房间！" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = 1;
				}
			}
			else {
				cout << "由于你没有击退小矮星，无法进入湖泊" << endl;
			}
		}
		else if (op == "湖泊" && !link[roomNum][lakesWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达湖泊，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作	
		}
		else if (op == "密室" && link[roomNum][chamberWithNum.second]) {
			system("cls");
			cout << "欢迎来到密室~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&chamber);
		}
		else if (op == "密室" && !link[roomNum][chamberWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达密室，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作	
		}
		else {
			system("cls");
			cout << "操作失败！" << endl;
			//格式化操作	
		}
	}
	return 1;
}

int Plot::init4(Sorcerer *mySorcerer, int myCheckPoint, bool ifNew) {
	//本关剧情格式化记录
	//小药水数目 中药水数目 大药水数目 技能 ifKillKerberos roomNum 0.礼堂 1.迷宫 2.坟墓 3大厅 4办公室四个地图的进入情况

	//药水设置 1大2中3小
	//药水数目需要进行一个记录 记录的格式为 X X X分别指小中大
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("小药水", 20, 400);
	Medicine medicineTempMiddle("中药水", 40, 800);
	Medicine medicineTempLarge("大药水", 60, 1200);
	if (!ifNew) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);;
	}
	//超市里技能设置
	//咒语：ExpectoPatronum 30 1300	
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill ExpectoPatronum("ExpectoPatronum", 15, 600);
	if (myCheckPoint != 4) {
		skill.push_back(ExpectoPatronum);
	}
	//一些判断
	bool check = 1;
	int trueanswer = 0;
	bool ifPassMaze = 0;
	//本关地点设置 0.礼堂 1.迷宫 2.坟墓 3大厅 4办公室
	Room auditorium("礼堂");
	Room maze("迷宫");
	Room grave("坟墓");
	Room hall("大厅");
	Room office("办公室");
	int roomNum = 0; //储存当前所在的房间号
	//开局先到达一个地点
	mySorcerer->inRoom(&auditorium);
	Map map("\t*********\t\t\t\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*礼堂\t*\t<--------------->\t*迷宫\t*\t---------------->\t*坟墓\t*\n\t*\t*\t\t\t\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t   ||\n \t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   \\/\n\t\t\t\t\t\t\t\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*大厅\t*\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t   /\\\n \t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   ||\n\t\t\t\t\t\t\t\t\t\t\t   \\/\n\t\t\t\t\t\t\t\t\t\t\t*********\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*办公室\t*\n\t\t\t\t\t\t\t\t\t\t\t*\t*\n\t\t\t\t\t\t\t\t\t\t\t*********");
		//一些装备
	Magicitem The_goblet_of_fire("火焰杯", 100);
	if (!ifNew) {
		//开局背景故事
		cout << "哈利没有报名参加“三强争霸赛”却意外地成为了三强争霸赛的第四名勇士\n没想到更大的阴谋正在后面等着他。。。。。。。。" << endl;
		system("pause");
		system("cls");
		cout << "欢迎进入第四关~" << endl;
	}
	//魂器
	Horcrux najini("纳吉尼");
	//人物设置
	BadPerson voldemort(100, 10, 35, "伏地魔");
	BadPerson Little_buddy(100, 10, 15, "小巴蒂");
	grave.addBadPerson(voldemort);
	office.addBadPerson(Little_buddy);
	//使用pair绑定
	pair<string, int> auditoriumWithNum("礼堂", 0);
	pair<string, int> mazeWithNum("迷宫", 1);
	pair<string, int> graveWithNum("坟墓", 2);
	pair<string, int> hallWithNum("大厅", 3);
	pair<string, int> officeWithNum("办公室", 4);
	//判断连通情况	link[A][B] = 1代表A->B是通的
	//邻接矩阵
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
		cout << "欢迎你再次进入游戏，继续开启第四关的征程。" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//药水初始化
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
		//技能初始化
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
		//其它杂项初始化
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
	Shop shop(medicine, skill, "佐科魔术用品店", medicine.size(), skill.size());
	while (check) {
		//如果在游戏中死亡
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//格式化处理
			system("cls");
		}
		system("pause");//格式化处理
		system("cls");
		//提示语输入
		cout << "输入 查看属性 可以查看当前自己的属性" << endl;
		cout << "输入 查用药品 可以查看或使用自己拥有的药品" << endl;
		cout << "输入 查看道具 可以查看自己目前已经拥有的魔法道具" << endl;
		cout << "输入 查看技能 可以查看自己目前已经拥有的技能" << endl;
		cout << "输入 查看魂器 可以查看自己目前已经收集的魂器" << endl;
		cout << "输入 进入店铺 可以进入关卡的店铺" << endl;
		cout << "输入 保存进度 可以保存当前进度" << endl;
		cout << "输入 退出游戏 可以退出当前游戏" << endl;
		cout << "你目前所在的位置为：" << mySorcerer->getRoom()->getName() << endl;
		cout << "输入地图上房间的名字可以进入该房间" << endl;
		cout << "此关卡的地图：" << endl;
		map.showMap();
		cout << "请输入你的选择:" << endl;
		string op = " ";
		cin >> op;
		if (op == "查看属性") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "查用药品") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "查看道具 ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "查看技能") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "查看魂器") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "进入店铺") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "保存进度") {
			mySorcerer->setMyCheckPoint(4);
			//文件处理
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//保存该关卡的进度
			ofstream tempFile;
			ofstream stateFile;
			//信息保存操作
			//本身属性信息保存
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
			cout << "人物属性信息保存成功!" << endl;
			//关卡信息保存
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
			//0.礼堂 1.迷宫 2.坟墓 3大厅 4办公室
			stateFile << auditorium.getIfIn() << " "
				<< maze.getIfIn() << " "
				<< grave.getIfIn() << " "
				<< hall.getIfIn() << " "
				<< office.getIfIn() << endl;
			//	//店铺
			mySorcerer->setMyCheckPoint(4);
			cout << "该关卡状态信息保存成功！" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "退出游戏") {
			cout << "你已经结束该游戏。" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "礼堂" && roomNum == auditoriumWithNum.second || op == "迷宫" && roomNum == mazeWithNum.second || op == "坟墓" && roomNum == graveWithNum.second || op == "大厅" && roomNum == hallWithNum.second || op == "办公室" && roomNum == officeWithNum.second) {
			system("cls");
			cout << "你已经在该位置！" << endl;
			//格式化操作	
		}
		else if (op == "迷宫" && link[roomNum][mazeWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&maze);
			system("cls");
			cout << "欢迎来到 " << maze.getName() << endl;
			if (maze.getIfIn()) {
				cout << "欢迎您再次来到 " << maze.getName() << endl;
				cout << "火焰杯是去到一个地方的钥匙" << endl;
			}
			else {
				char indicatation;
				cout << "通过回答一些小问题你可以通过迷宫。" << endl;
				system("pause");
				trueanswer = 0;
				cout << "1、哈利波特的生日是几月几日？" << endl;
				cout << "A.8.31    B. 7.31    C.7.11" << endl;
				cin >> indicatation;
				if (indicatation == 'B') {
					cout << "回答正确" << endl;
					trueanswer++;
				}
				else {
					cout << "回答错误" << endl;
				}
				cout << "2.咒语Imperio是什么意思？" << endl;
				cout << "A. 魂魄出窍              B. 钻心剜骨              C. 黑魔标记" << endl;
				cin >> indicatation;
				if (indicatation == 'A') {
					cout << "回答正确" << endl;
					trueanswer++;
				}
				else {
					cout << "回答错误" << endl;
				}
				cout << "3. Bezoar 毛粪石有什么作用？" << endl;
				cout << "A. 用来解毒 B.对难缠的面疱有特别的疗效  C.在水里可以呼吸" << endl;
				cin >> indicatation;
				if (indicatation == 'A') {
					cout << "回答正确" << endl;
					trueanswer++;
				}
				else {
					cout << "回答错误" << endl;
				}
				if (trueanswer == 3) {
					cout << "恭喜你通过迷宫，获得了火焰杯。" << endl;
					mySorcerer->addMagicitem(The_goblet_of_fire);
					maze.inRoom();
					ifPassMaze = 1;
				}
				else {
					cout << "很遗憾你没有通过迷宫，被迫返回至礼堂。" << endl;
					mySorcerer->inRoom(&auditorium);
					roomNum = 0;
					//0.礼堂 1.迷宫 2.坟墓 3大厅 4办公室
				}
			}
		}
		else if (op == "迷宫" && !link[roomNum][mazeWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达迷宫，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "坟墓" && link[roomNum][graveWithNum.second]) {
			if (ifPassMaze) {
				roomNum = 2;
				mySorcerer->inRoom(&grave);
				system("cls");
				cout << "你通过神奇的火焰杯，来到了一个神奇的地方" << endl;
				if (grave.getIfIn()) {
					cout << "欢迎您再次来到 " << grave.getName() << endl;
					cout << "伏地魔他们已经离开。。。。" << endl;
				}
				else {
					system("pause");
					system("cls");
					mySorcerer->inRoom(&grave);
					cout << "欢迎来到 " << grave.getName() << endl;
					cout << "那个不能说出名字的人复活了！！！" << endl;
					system("pause");
					system("cls");
					cout << "是否选择与伏地魔进行战斗:" << endl;
					cout << "1.是		2.否" << endl;
					int op_grave = 0;
					cin >> op_grave;
					if (op_grave == 1) {
						cout << "战斗过程中，发现实力差距较大，你使用火焰杯顺利逃脱。" << endl;
					}
					else {
						cout << "你使用火焰杯顺利逃脱。" << endl;
					}
					system("pause");
					system("cls");
					mySorcerer->inRoom(&hall);
					roomNum = 3;
						//0.礼堂 1.迷宫 2.坟墓 3大厅 4办公室
				}
			}
			else {
				cout << "你缺少进入坟墓的钥匙。" << endl;
			}
		}
		else if (op == "坟墓" && !link[roomNum][graveWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达坟墓，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "大厅" && link[roomNum][hallWithNum.second]) {
			roomNum = 3;
			mySorcerer->inRoom(&hall);
			system("cls");
			cout << "欢迎来到大厅。" << endl;
		}
		else if (op == "大厅" && !link[roomNum][graveWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达大厅，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "办公室" && link[roomNum][officeWithNum.second]) {
			roomNum = 4;
			mySorcerer->inRoom(&hall);
			system("cls");
			cout << "欢迎来到" << office.getName() << endl;
			cout << "原来小巴蒂是食司徒!!!" << endl;
			cout << "你是否选择与它进行战斗？" << endl;
			cout << "1.是		2.否" << endl;
			int op_office = 0;
			cin >> op_office;
			system("cls");
			if (op_office == 1) {
				bool ifWin = 0;
				cout << "战斗开始，你已进入战斗模式..." << endl;
				ifWin = mySorcerer->battle(mySorcerer, Little_buddy);
				if (ifWin) {
					cout << "恭喜你成功通过第四关关并获得了2000金币和纳吉尼" << endl;
					mySorcerer->increaseMoney(2000);
					mySorcerer->addHorcrux(najini);
					check = 0;
					system("pause");
					system("cls");
				}
				else {
					mySorcerer->setBlood(0);
					//输出菜
					cout << "\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\n\t\t   菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\n\t\t   菜\t\t   菜\t\t   菜\t\n\t\t    菜\t\t   菜\t\t  菜\t\n\t\t     菜\t\t   菜\t\t 菜\t\n\n\t\t\t\t   菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t\t   菜\n\t\t\t         菜菜菜\n\t\t\t       菜  菜  菜\n\t\t\t     菜    菜    菜\n\t\t\t   菜      菜      菜\n\t\t\t 菜        菜        菜\n\t\t       菜          菜          菜\n\t\t     菜            菜            菜\n\t\t   菜              菜              菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n" << endl;
					system("pause");
					system("cls");
					mySorcerer->inRoom(&hall);
					roomNum = 3;
					//0.礼堂 1.迷宫 2.坟墓 3大厅 4办公室
				}
			}
			else if (op_office == 2) {
				cout << "你已经逃离战斗。" << endl;
			}
			else {
				cout << "操作失败，你已退出该房间！" << endl;
				mySorcerer->inRoom(&hall);
				roomNum = 3;
				//0.礼堂 1.迷宫 2.坟墓 3大厅 4办公室
			}
		}
		else if (op == "办公室" && !link[roomNum][officeWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达办公室，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty())
			{
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
	}
	return 1;
}


int Plot::init5(Sorcerer *mySorcerer, int myCheckPoint, bool ifNew) {
	//本关剧情格式化记录
	//小药水数目 中药水数目 大药水数目 技能 ifKillKerberos roomNum 0大厅 1校长室 2阁楼 3地穴四个地图的进入情况
	//bool end = 0;	//
	//开局送的礼物
	//药水配置待改
	//药水设置 1大2中2小
	//药水数目需要进行一个记录 记录的格式为 X X X分别指小中大
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("小药水", 20, 400);
	Medicine medicineTempMiddle("中药水", 40, 800);
	Medicine medicineTempLarge("大药水", 60, 1200);
	if (!ifNew) {
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
	}
	//超市里技能设置
	//咒语：Epliskey 40 1500
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Epliskey("Epliskey", 60, 1500);
	if (myCheckPoint != 5) {
		skill.push_back(Epliskey);
	}
	//一些判断
	bool check = 1;

	//本关地点设置 0.大厅 1.魔法部 2.有求必应屋 3.神龙阁
	Room hall("大厅");
	Room The_ministry_of_magic("魔法部");
	Room Room_of_requirement("有求必应屋");
	Room The_dragon_pavilion("神龙阁");
	int roomNum = 0; //储存当前所在的房间号
	//开局先到达一个地点
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	Map map("\t*********\n\t*\t*\n\t*魔法部\t*\n\t*\t*\n\t*********\n\t   /\\\n\t   ||\n\t   ||\n\t   ||\n\t   \\/\n\t*********\t\t\t\t*****************\n\t*\t*\t\t\t\t*\t\t*\n\t*大厅\t*<----------------------------->*有求必应屋\t*\n\t*\t*\t\t\t\t*\t\t*\n\t*********\t\t\t\t*****************\n\t   /\\\n\t   ||\n\t   ||\n\t   ||\n\t   ||\n\t   \\/\n\t*********\n\t*\t*\n\t*神龙阁\t*\n\t*\t*\n\t*********");
	if (!ifNew) {
		//背景故事
		cout << "没有人相信伏地魔回来，\n哈利被认为是个骗子，\n只有他的朋友们相信并支持着他。\n哈利于伙伴们组建邓不利多军来抵抗，\n但到后来他中了伏地魔的诡计，\n与朋友们来到魔法部解救教父小天狼星。。。。。。。" << endl;
		system("pause");
		system("cls");
		cout << "欢迎进入第五关~" << endl;
	}
	//人物设置
	GoodPerson Sirius("小天狼星", "我必须来送送你，对吧。...\n");
	BadPerson Lucius(200, 40, 50, "卢修斯");
	The_ministry_of_magic.addGoodPerson(Sirius);
	BadPerson Fire_dragon(100, 10, 35, "火龙");
	BadPerson Earth_dragon(100, 10, 35, "土龙");
	BadPerson Water_dragon(100, 10, 35, "水龙");
	BadPerson Wind_dragon(100, 10, 35, "风龙");
	BadPerson Far_from_cologne(100, 10, 35, "远古龙");
	//装备
	Magicitem Invisibility_cloak("隐形斗篷", 3);
	//魂器
	Horcrux crown("罗伊纳·拉文克劳的王冠");
	//在神龙阁可以 挑战木龙，土龙，火龙，风龙和远古龙
	if (!ifNew) {
		The_dragon_pavilion.addBadPerson(Fire_dragon);
		The_dragon_pavilion.addBadPerson(Earth_dragon);
		The_dragon_pavilion.addBadPerson(Water_dragon);
		The_dragon_pavilion.addBadPerson(Wind_dragon);
		The_dragon_pavilion.addBadPerson(Far_from_cologne);
	}
	//使用pair绑定
	pair<string, int> hallWithNum("大厅", 0);
	pair<string, int> The_ministry_of_magicWithNum("魔法部", 1);
	pair<string, int> Room_of_requirementWithNum("有求必应屋", 2);
	pair<string, int> The_dragon_pavilionWithNum("神龙阁", 3);
	//判断连通情况	link[A][B] = 1代表A->B是通的
	//邻接矩阵
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
		cout << "欢迎你再次进入游戏，继续开启第五关的征程。" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//药水初始化
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
		//技能初始化
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
		//神龙阁初始化
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
		//其它杂项初始化
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
	Shop shop(medicine, skill, "魔金夫人魔术用品店", medicine.size(), skill.size());
	while (check) {
		//如果在游戏中死亡
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//格式化处理
			system("cls");
		}
		system("pause");//格式化处理
		system("cls");
		//提示语输入
		cout << "输入 查看属性 可以查看当前自己的属性" << endl;
		cout << "输入 查用药品 可以查看或使用自己拥有的药品" << endl;
		cout << "输入 查看道具 可以查看自己目前已经拥有的魔法道具" << endl;
		cout << "输入 查看技能 可以查看自己目前已经拥有的技能" << endl;
		cout << "输入 查看魂器 可以查看自己目前已经收集的魂器" << endl;
		cout << "输入 进入店铺 可以进入关卡的店铺" << endl;
		cout << "输入 保存进度 可以保存当前进度" << endl;
		cout << "输入 退出游戏 可以退出当前游戏" << endl;
		cout << "你目前所在的位置为：" << mySorcerer->getRoom()->getName() << endl;
		cout << "输入地图上房间的名字可以进入该房间" << endl;
		cout << "此关卡的地图：" << endl;
		map.showMap();
		cout << "请输入你的选择:" << endl;
		//选择为op
		string op = " ";
		cin >> op;
		if (op == "查看属性") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "查用药品") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "查看道具 ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "查看技能") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "查看魂器") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "进入店铺") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "保存进度") {
			mySorcerer->setMyCheckPoint(5);
			//文件处理
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//保存该关卡的进度
			ofstream tempFile;
			ofstream stateFile;
			//信息保存操作
			//本身属性信息保存
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
			cout << "人物属性信息保存成功!" << endl;
			//关卡信息保存
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
			//0.大厅 1.魔法部 2.有求必应屋 3.神龙阁四个地图的进入情况
			stateFile << hall.getIfIn() << " "
				<< The_ministry_of_magic.getIfIn() << " "
				<< Room_of_requirement.getIfIn() << " "
				<< The_dragon_pavilion.getIfIn() << endl;
			//	//店铺
			mySorcerer->setMyCheckPoint(5);
			cout << "该关卡状态信息保存成功！" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "退出游戏") {
			cout << "你已经结束该游戏。" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "大厅" && roomNum == hallWithNum.second || op == "魔法部" && roomNum == The_ministry_of_magicWithNum.second || op == "有求必应屋" && roomNum == Room_of_requirementWithNum.second || op == "神龙阁" && roomNum == The_dragon_pavilionWithNum.second) {
			system("cls");
			cout << "你已经在该位置！" << endl;
			//格式化操作	
		}
		else if (op == "魔法部" && link[roomNum][The_ministry_of_magicWithNum.second]) {
			bool ifWin = 0;
			roomNum = 1;
			mySorcerer->inRoom(&The_ministry_of_magic);
			system("cls");
			cout << "欢迎来到 " << The_ministry_of_magic.getName() << endl;
			cout << "此时卢修斯正在魔法部里，你是否选择逃跑" << endl;
			cout << "1.否		2.是" << endl;
			int op_magic = 0;
			cin >> op_magic;
			system("cls");
			if (op_magic == 1) {
				cout << "卢修斯:今天你不会活着走出魔法部！\n" << endl;
				system("pause");
				system("cls");
				ifWin = mySorcerer->battle(mySorcerer, Lucius);
				if (ifWin == 1) {
					//成功打败的话
					check = 0;
					cout << "恭喜你通过第五关并获得了2500金币和一个魂器" << endl;
					mySorcerer->increaseMoney(2500);
					mySorcerer->addHorcrux(crown);
					system("pause");
					system("cls");
				}
				else if (ifWin == 0) {
					mySorcerer->setBlood(0);
					cout << "挑战失败！" << endl;
					//输出菜
					cout << "\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\n\t\t   菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\n\t\t   菜\t\t   菜\t\t   菜\t\n\t\t    菜\t\t   菜\t\t  菜\t\n\t\t     菜\t\t   菜\t\t 菜\t\n\n\t\t\t\t   菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t\t   菜\n\t\t\t         菜菜菜\n\t\t\t       菜  菜  菜\n\t\t\t     菜    菜    菜\n\t\t\t   菜      菜      菜\n\t\t\t 菜        菜        菜\n\t\t       菜          菜          菜\n\t\t     菜            菜            菜\n\t\t   菜              菜              菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n" << endl;
					system("pause");
					system("cls");
					mySorcerer->inRoom(&hall);
					roomNum = 0;
					//0.大厅 1.魔法部 2.有求必应屋 3.神龙阁
				}
			}
			else if (op_magic == 2) {
				cout << "你成功逃离。" << endl;
				mySorcerer->inRoom(&hall);
				roomNum = 0;
				//0.大厅 1.魔法部 2.有求必应屋 3.神龙阁
			}
			else {
				cout << "操作失败！你已退出该房间。" << endl;
				mySorcerer->inRoom(&hall);
				roomNum = 0;
				//0.大厅 1.魔法部 2.有求必应屋 3.神龙阁
			}
		}
		else if (op == "魔法部" && !link[roomNum][The_ministry_of_magicWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达魔法部，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "有求必应屋" && link[roomNum][Room_of_requirementWithNum.second]) {
			roomNum = 2;
			mySorcerer->inRoom(&The_ministry_of_magic);
			system("cls");
			cout << "欢迎来到 " << Room_of_requirement.getName() << endl;
			if (Room_of_requirement.getIfIn()) {
				cout << "欢迎您再次来到 " << Room_of_requirement.getName() << endl;
				cout << "你去神龙阁打完龙了么？" << endl;
			}
			else {
				//在有求必应屋获得什么等待添加。
				Room_of_requirement.inRoom();
				cout << "去神龙阁挑战大龙成为真正的勇士！" << endl;
				cout << "你获得了一个装备" << endl;
				mySorcerer->addMagicitem(Invisibility_cloak);
			}
		}
		else if (op == "有求必应屋" && !link[roomNum][Room_of_requirementWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达有求必应屋，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "神龙阁" && link[roomNum][The_dragon_pavilionWithNum.second]) {
			roomNum = 3;
			mySorcerer->inRoom(&The_dragon_pavilion);
			system("cls");
			cout << "欢迎来到 " << The_dragon_pavilion.getName() << endl;
			The_dragon_pavilion.inRoom();
			cout << "在这里你可以挑战巨龙，打败它们你可以获得相应的加成" << endl;
			string op_dragon = " ";
			bool ifWin = 0;
			cout << "神龙阁中的神龙情况如下：" << endl;
			for (int i = 0; i < The_dragon_pavilion.getBadPerson().size(); i++) {
				cout << i + 1 << ". " << The_dragon_pavilion.getBadPerson()[i].getName() << endl;
			}
			cout << "请输入编号选择你要与之战斗的龙：（0逃跑）" << endl;
			cin >> op_dragon;
			std::regex rx("[0-9]+");
			bool ifNum = std::regex_match(op_dragon.begin(), op_dragon.end(), rx);
			if (!ifNum) {
				cout << "你输入的不是数字！" << endl;
				system("pause");
				system("cls");
				mySorcerer->inRoom(&hall);
				roomNum = 0;
			}
			else {
				int op_num = 0;
				stringstream s_temp;//字符和数字转化
				s_temp << op_dragon;
				s_temp >> op_num;
				if (!(op_num < The_dragon_pavilion.getBadPerson().size() + 1 && op_num  > 0)) {
					cout << "输入错误,不存在这条龙！" << endl;
					mySorcerer->inRoom(&hall);
					roomNum = 0;
					system("pause");
					system("cls");
				}
				else if (op_num == 0) {
					cout << "你成功逃跑！" << endl;
					mySorcerer->inRoom(&hall);
					roomNum = 0;
					system("pause");
					system("cls");
				}
				else {
					cout << "你准备挑战的是" << The_dragon_pavilion.getBadPerson()[op_num - 1].getName() << "...战斗即将开始。" << endl;
					system("pause");
					system("cls");
					ifWin = mySorcerer->battle(mySorcerer, The_dragon_pavilion.getBadPerson()[op_num - 1]);

					if (ifWin == 1) {
						cout << "恭喜你击败了" << The_dragon_pavilion.getBadPerson()[op_num - 1].getName() << "并获得了属性加成。" << endl;
						The_dragon_pavilion.eraseBadPerson(op_num);
						mySorcerer->inRoom(&hall);
						roomNum = 0;
						mySorcerer->increaseMoney(500);
						mySorcerer->increaseBlood(20);
						//0.大厅 1.魔法部 2.有求必应屋 3.神龙阁
						//写属性加成商量后定
					}
					else {
						mySorcerer->setBlood(0);
						cout << "你被击败，请调整状态后再来。" << endl;
						//输出菜
						cout << "\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\n\t\t   菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\n\t\t   菜\t\t   菜\t\t   菜\t\n\t\t    菜\t\t   菜\t\t  菜\t\n\t\t     菜\t\t   菜\t\t 菜\t\n\n\t\t\t\t   菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t\t   菜\n\t\t\t         菜菜菜\n\t\t\t       菜  菜  菜\n\t\t\t     菜    菜    菜\n\t\t\t   菜      菜      菜\n\t\t\t 菜        菜        菜\n\t\t       菜          菜          菜\n\t\t     菜            菜            菜\n\t\t   菜              菜              菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&hall);
						roomNum = 0;
						//0.大厅 1.魔法部 2.有求必应屋 3.神龙阁
					}
				}
			}

		}
		else if (op == "神龙阁" && !link[roomNum][The_dragon_pavilionWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达有求神龙阁，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作
		}
		else if (op == "大厅" && link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "欢迎来到大厅~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&hall);
		}
		else if (op == "大厅" && !link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达大厅，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作	
		}
		else {
			system("cls");
			cout << "操作失败！" << endl;
			//格式化操作	
		}
	}
	return 1;
}


int Plot::init6(Sorcerer *mySorcerer, int myCheckPoint, bool ifNew) {
	//本关剧情格式化记录
	//小药水数目 中药水数目 大药水数目 技能 ifKillKerberos roomNum 0大厅 1校长室 2阁楼 3地穴四个地图的进入情况
	//bool end = 0;	//
	//开局送的礼物
	//药水设置 1大2中2小
	//药水数目需要进行一个记录 记录的格式为 X X X分别指小中大
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("小药水", 20, 400);
	Medicine medicineTempMiddle("中药水", 40, 800);
	Medicine medicineTempLarge("大药水", 60, 1200);
	if (!ifNew) {
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempMiddle);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempLarge);
		medicine.push_back(medicineTempSmall);
		medicine.push_back(medicineTempSmall);
	}
	//魂器
	Horcrux cup("海尔加·赫奇帕奇的杯子");
	//超市里技能设置
	//咒语：盔甲护身（盔甲咒）:Protego ：15 600 门牙赛大棒（长出长牙） : Densaugeo：12  400
	vector<Skill> skill;
	Skill tempSkill(" ", 0, 0);
	Skill Avada_kedavra("Protego", 100, 3600);
	if (myCheckPoint == 0) {
		skill.push_back(Avada_kedavra);
	}
	//一些判断
	bool check = 1;
	//本关地点设置 0大厅 1魔法部 2古灵阁
	Room hall("大厅");
	Room The_ministry_of_magic("魔法部");
	Room gringotts("古灵阁");
	int roomNum = 0;
	//开局先到达一个地点
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	Map map("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*魔法部\t*\t<--------------->\t*古灵阁\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********\n\t  /\\\t\t\t\t\t   ||\t\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  ||\t\t\t\t\t   ||\n\t  \\/\t\t\t\t\t   ||\t\n\t*********\t\t\t\t   ||\n\t*\t*\t\t\t\t   ||\n\t*大厅\t*<===================================\n\t*\t*\n\t*********");
	if (!ifNew) {
		//背景故事
		cout << "还有四天，哈利就要迎来自己十七岁的生日，\n成为一名真正的魔法师。\n然而，他不得不提前离开女贞路4号，\n永远离开这个他曾经生活过十六年的地方。\n凤凰社的成员精心谋划了秘密转移哈利的计划，\n以防哈利遭到伏地魔及其追随者食死徒的袭击。然而，可怕的意外还是发生了……\n " << endl;
		system("pause");
		system("cls");
		cout << "欢迎进入第六关~" << endl;
	}
	//在古灵阁需要打6个食死徒
	//人物设置
	BadPerson dolohov(100, 5, 10, "多洛霍夫");
	BadPerson rookwood(100, 10, 15, "卢克伍德");
	BadPerson bellatrix(100, 15, 20, "贝拉特里克斯");
	BadPerson travers(100, 20, 30, "特拉弗斯");
	BadPerson DoleFinn(100, 30, 35, "多尔芬");
	BadPerson malfoy(100, 36, 45, "马尔福");
	if (!ifNew) {
		gringotts.addBadPerson(dolohov);
		gringotts.addBadPerson(rookwood);
		gringotts.addBadPerson(bellatrix);
		gringotts.addBadPerson(travers);
		gringotts.addBadPerson(DoleFinn);
		gringotts.addBadPerson(malfoy);
	}
	//使用pair绑定
	pair<string, int> hallWithNum("大厅", 0);
	pair<string, int> The_ministry_of_magicWithNum("魔法部", 1);
	pair<string, int> gringottsWithNum("古灵阁", 2);
	//判断连通情况	link[A][B] = 1代表A->B是通的
	//邻接矩阵
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
		cout << "欢迎你再次进入游戏，继续开启第六关的征程。" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//药水初始化
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
		//技能初始化
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
		//古灵阁初始化
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
		//其它杂项初始化
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
	Shop shop(medicine, skill, "破斧魔术用品店", medicine.size(), skill.size());

	while (check) {
		//如果在游戏中死亡
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//格式化处理
			system("cls");
		}
		system("pause");//格式化处理
		system("cls");
		//提示语输入
		cout << "输入 查看属性 可以查看当前自己的属性" << endl;
		cout << "输入 查用药品 可以查看或使用自己拥有的药品" << endl;
		cout << "输入 查看道具 可以查看自己目前已经拥有的魔法道具" << endl;
		cout << "输入 查看技能 可以查看自己目前已经拥有的技能" << endl;
		cout << "输入 查看魂器 可以查看自己目前已经收集的魂器" << endl;
		cout << "输入 进入店铺 可以进入关卡的店铺" << endl;
		cout << "输入 保存进度 可以保存当前进度" << endl;
		cout << "输入 退出游戏 可以退出当前游戏" << endl;
		cout << "你目前所在的位置为：" << mySorcerer->getRoom()->getName() << endl;
		cout << "输入地图上房间的名字可以进入该房间" << endl;
		cout << "此关卡的地图：" << endl;
		map.showMap();
		cout << "请输入你的选择:" << endl;
		//选择为op
		string op = " ";
		cin >> op;
		if (op == "查看属性") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "查用药品") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "查看道具 ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "查看技能") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "查看魂器") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "进入店铺") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "保存进度") {
			mySorcerer->setMyCheckPoint(6);
			//文件处理
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//保存该关卡的进度
			ofstream tempFile;
			ofstream stateFile;
			//信息保存操作
			//本身属性信息保存
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
			cout << "人物属性信息保存成功!" << endl;
			//关卡信息保存
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
			//0大厅 1魔法部 2古灵阁 四个地图的进入情况
			stateFile << hall.getIfIn() << " "
				<< The_ministry_of_magic.getIfIn() << " "
				<< gringotts.getIfIn() << endl;
			//	//店铺
			mySorcerer->setMyCheckPoint(6);
			cout << "该关卡状态信息保存成功！" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "退出游戏") {
			cout << "你已经结束该游戏。" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "大厅" && roomNum == hallWithNum.second || op == "魔法部" && roomNum == The_ministry_of_magicWithNum.second || op == "古灵阁" && roomNum == gringottsWithNum.second) {
			system("cls");
			cout << "你已经在该位置！" << endl;
			//格式化操作	
		}
		else if (op == "大厅" && link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "欢迎来到大厅~" << endl;
			roomNum = 0;
			mySorcerer->inRoom(&hall);
			//本关地点设置 0大厅 1魔法部 2古灵阁
		}
		else if (op == "大厅" && !link[roomNum][hallWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达大厅，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作	
		}
		else if (op == "魔法部" && link[roomNum][The_ministry_of_magicWithNum.second]) {
			roomNum = 1;
			mySorcerer->inRoom(&The_ministry_of_magic);
			system("cls");
			cout << "欢迎来到 " << The_ministry_of_magic.getName() << endl;
			if (The_ministry_of_magic.getIfIn()) {
				cout << "欢迎您再次来到 " << The_ministry_of_magic.getName() << endl;
				cout << "古灵阁危机严重！" << endl;
			}
			else {
				//在有求必应屋获得什么等待添加。
				The_ministry_of_magic.inRoom();
				cout << "与黑魔王的决战即将来临！" << endl;
			}
		}
		else if (op == "魔法部" && !link[roomNum][The_ministry_of_magicWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达魔法部，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作	
		}
		else if (op == "古灵阁" && link[roomNum][gringottsWithNum.second]) {
			roomNum = 2;
			mySorcerer->inRoom(&gringotts);
			system("cls");
			cout << "欢迎来到 " << gringotts.getName() << endl;
			gringotts.inRoom();
			cout << "在这里你可以挑战黑魔法师，打败它们你方可通关" << endl;
			string op_person = " ";
			bool ifWin = 0;
			cout << "古灵阁中的黑魔法师情况如下：" << endl;
			for (int i = 0; i < gringotts.getBadPerson().size(); i++) {
				cout << i + 1 << ". " << gringotts.getBadPerson()[i].getName() << endl;
			}
			cout << "请输入编号选择你要与之战斗的黑魔法师：（0逃跑）" << endl;
			cin >> op_person;
			std::regex rx("[0-9]+");
			bool ifNum = std::regex_match(op_person.begin(), op_person.end(), rx);
			if (!ifNum) {
				cout << "你输入的不是数字！你已离开该房间！" << endl;
				mySorcerer->inRoom(&hall);
				roomNum = 0;
				system("pause");
				system("cls");
			}
			else {
				int op_num = 0;
				stringstream s_temp;//字符和数字转化
				s_temp << op_person;
				s_temp >> op_num;
				if (op_num == 0) {
					cout << "你成功逃跑！" << endl;
					mySorcerer->inRoom(&hall);
					roomNum = 0;
					system("pause");
					system("cls");
				}
				else if (!(op_num < gringotts.getBadPerson().size() + 1 && op_num > 0)) {
					cout << "输入错误,不存在该黑魔法师！" << endl;
					system("pause");
					system("cls");
					mySorcerer->inRoom(&hall);
					roomNum = 0;
				}
				else {
					cout << "你准备挑战的是" << gringotts.getBadPerson()[op_num - 1].getName() << "...战斗即将开始。" << endl;
					system("pause");
					system("cls");
					ifWin = mySorcerer->battle(mySorcerer, gringotts.getBadPerson()[op_num - 1]);
					if (ifWin == 1) {
						cout << "恭喜你击败了了" << gringotts.getBadPerson()[op_num - 1].getName() << "并获得了属性加成。" << endl;
						gringotts.eraseBadPerson(1);
						mySorcerer->inRoom(&hall);
						//写属性加成商量后定
						roomNum = 0;
					}
					else {
						mySorcerer->setBlood(0);
						cout << "你被击败，请调整状态后再来。" << endl;
						//输出菜
						cout << "\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t   菜\t\t     菜\n\t\t\t   菜\t\t     菜\n\n\t\t   菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\n\t\t   菜\t\t   菜\t\t   菜\t\n\t\t    菜\t\t   菜\t\t  菜\t\n\t\t     菜\t\t   菜\t\t 菜\t\n\n\t\t\t\t   菜\n\t\t菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜\n\t\t\t\t   菜\n\t\t\t         菜菜菜\n\t\t\t       菜  菜  菜\n\t\t\t     菜    菜    菜\n\t\t\t   菜      菜      菜\n\t\t\t 菜        菜        菜\n\t\t       菜          菜          菜\n\t\t     菜            菜            菜\n\t\t   菜              菜              菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n\t\t\t\t   菜\n" << endl;
						system("pause");
						system("cls");
						mySorcerer->inRoom(&hall);
						//本关地点设置 0大厅 1魔法部 2古灵阁
						roomNum = 0;
					}
					if (gringotts.getBadPersonSize() == 0) {
						check = 0;
						system("pause");
						system("cls");
						cout << "恭喜你通过第六关并获得3000金币和一个魂器海尔加·赫奇帕奇的杯子" << endl;
						mySorcerer->addHorcrux(cup);
						mySorcerer->increaseMoney(3000);
					}
				}
			}
		}
		else if (op == "古灵阁" && !link[roomNum][gringottsWithNum.second]) {
			system("cls");
			cout << "你所在的当前位置无法直接到达古灵阁，请仔细观察地图！" << endl;
			//bfs判断连通性
			int dir[4][2] = { 0,1,0,-1,1,0,-1,0 }; // 方向向量
			bool vis[10][10] = { 0 }; // 访问标记。我的习惯上，统一放在外面，不放在结构体里面。
			struct node // BFS 队列中，每一个单位结点的，状态数据结构。
			{
				int x, y;  // 坐标位置
						  //这里注意，并不是每道题的单位结点，都用x和y两个数据来标记位置。
						  //有些题，一维就足以标记自己的位置了  （比如，专题6  1004）
				int dpth; // 记录该节点的深度
			};
			node temp[10];
			queue <node> q; // BFS 队列
			node sta;   //配置起始点
			sta.dpth = 0;
			sta.x = 0;
			sta.y = 0;
			q.push(sta); // 把起始点入队
			vis[sta.x][sta.y] = 1; // 访问标记
			while (!q.empty()) {
				node pro = q.front(); // 取队首元素为本次待处理元素，作为后续扩展的起点
				q.pop();
				//找到答案，直接输出，结束程序。因为:
				//是广度优先搜索，越往后step越大，所以最先找到的step就是最小的那个。
				for (int i = 0; i < 4; i++) {    //扩展，遍历地寻找每一个相邻点。
					node tmp;             //生成下一个状态
					tmp.x = pro.x + dir[i][0];
					tmp.y = pro.y + dir[i][1];
					tmp.dpth = pro.dpth + 1;
					if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < 10 && tmp.y < 10 && vis[tmp.x][tmp.y] == 0) {    // 如果状态满足约束条件，则入队
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
						vis[tmp.x][tmp.y] = 1;   //访问标记，标记为已经走过，走过的点不再重复走。
											   //请记住：每次，只要你把某个节点加入队列了，都要标记该节点的vis。
					}
				}
			}
			//格式化操作	
		}
		else {
			system("cls");
			cout << "操作失败！" << endl;
			//格式化操作
		}
	}
	return 1;
}

int Plot::initFinal(Sorcerer * mySorcerer, int myCheckPoint, bool ifNew) {
	//药水设置 1大2中2小
	//药水数目需要进行一个记录 记录的格式为 X X X分别指小中大
	vector<Medicine> medicine;
	Medicine tempMedicine(" ", 0, 0);
	Medicine medicineTempSmall("小药水", 20, 400);
	Medicine medicineTempMiddle("中药水", 40, 800);
	Medicine medicineTempLarge("大药水", 60, 1200);
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
	//一些判断;
	bool check = 1;
	//地图
	Room hall("大厅");
	Room The_black_forest("黑森林");
	int roomNum = 0; //储存当前所在的房间号
	//开局先到达一个地点
	mySorcerer->inRoom(&hall);
	roomNum = 0;
	Map map("\t*********\t\t\t\t*********\n\t*\t*\t\t\t\t*\t*\n\t*大厅\t*\t<--------------->\t*黑森林\t*\n\t*\t*\t\t\t\t*\t*\n\t*********\t\t\t\t*********");
	//背景故事
	if (myCheckPoint != 7) {
		cout << "终局之战，你与伏地魔的最后之战即将开启！！！" << endl;
	}
	system("pause");
	system("cls");
	mySorcerer->inRoom(&hall);
	cout << "欢迎进入终局之战~" << endl;
	cout << "你目前所在的位置: " << mySorcerer->getRoom()->getName() << endl;
	//人物设置
	BadPerson voldemort(1000, 50, 60, "伏地魔");
	Shop shop(medicine, skill, "黑森林魔术用品店", medicine.size(), skill.size());
	if (ifNew) {
		cout << "欢迎你再次进入游戏，继续开启第七关的征程。" << endl;
		system("pause");
		system("cls");
		fstream infile(mySorcerer->getName() + "State" + ".txt");
		//药水初始化
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
		//技能初始化
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

		//其它杂项初始化
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
		//如果在游戏中死亡
		if (mySorcerer->getBloodValue() == 0) {
			mySorcerer->afterDead();
			system("pause");//格式化处理
			system("cls");
		}
		system("pause");//格式化处理
		system("cls");
		//提示语输入
		cout << "输入 查看属性 可以查看当前自己的属性" << endl;
		cout << "输入 查用药品 可以查看或使用自己拥有的药品" << endl;
		cout << "输入 查看道具 可以查看自己目前已经拥有的魔法道具" << endl;
		cout << "输入 查看技能 可以查看自己目前已经拥有的技能" << endl;
		cout << "输入 查看魂器 可以查看自己目前已经收集的魂器" << endl;
		cout << "输入 进入店铺 可以进入关卡的店铺" << endl;
		cout << "输入 保存进度 可以保存当前进度" << endl;
		cout << "输入 退出游戏 可以退出当前游戏" << endl;
		cout << "你目前所在的位置为：" << mySorcerer->getRoom()->getName() << endl;
		cout << "输入地图上房间的名字可以进入该房间" << endl;
		cout << "此关卡的地图：" << endl;
		map.showMap();
		cout << "请输入你的选择:" << endl;
			//选择为op
		string op = " ";
		cin >> op;
		if (op == "查看属性") {
			system("cls");
			mySorcerer->showInformation();
		}
		else if (op == "查用药品") {
			system("cls");
			mySorcerer->showMedicine();
		}
		else if (op == "查看道具 ") {
			system("cls");
			mySorcerer->showMagicItem();
		}
		else if (op == "查看技能") {
			system("cls");
			mySorcerer->showSkill();
		}
		else if (op == "查看魂器") {
			system("cls");
			mySorcerer->showHorcrux();
		}
		else if (op == "进入店铺") {
			system("cls");
			shop.showShop(mySorcerer);
		}
		else if (op == "保存进度") {
			mySorcerer->setMyCheckPoint(1);
			//文件处理
			//File myFile(mySorcerer->getName() + ".txt");
			//File checkPointFile(mySorcerer->getName() + "State" + ".txt");//保存该关卡的进度
			ofstream tempFile;
			ofstream stateFile;
				//信息保存操作
				//本身属性信息保存
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
			cout << "人物属性信息保存成功!" << endl;
			//关卡信息保存
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
				//	//店铺
			mySorcerer->setMyCheckPoint(1);
			cout << "该关卡状态信息保存成功！" << endl;
			tempFile.close();
			stateFile.close();
		}
		else if (op == "退出游戏") {
			cout << "你已经结束该游戏。" << endl;
			system("pause");
			system("cls");
			return -1;
			break;
		}
		else if (op == "大厅" && roomNum == 0 || op == "黑森林" && roomNum == 1) {
			system("cls");
			cout << "你已经在该位置！" << endl;
				//格式化操作	
		}
		else if (op == "大厅") {
			roomNum = 0;
			mySorcerer->inRoom(&hall);
			system("cls");
			cout << "欢迎来到 " << hall.getName() << endl;
			cout << "正义的魔法师们：\n勇敢地去与黑魔王战斗吧！\n" << endl;
		}
		else if (op == "黑森林") {
			roomNum = 1;
			mySorcerer->inRoom(&The_black_forest);
			system("cls");
			mySorcerer->inRoom(&The_black_forest);
			cout << "欢迎来到黑森林" << endl;
				//加一些话
			cout << "此时伏地魔正在黑森林里，你是否选择进行最终之战" << endl;
			cout << "1.是		2.否" << endl;
			int op_forest = 0;
			bool ifWin = 0;
			cin >> op_forest;
			system("cls");
			if (op_forest == 1) {
				ifWin = mySorcerer->battle(mySorcerer, voldemort);
				if (ifWin == 1) {
					//成功打败的话
					check = 0;
					cout << "你成功地摧毁了所有魂器！" << endl;
					cout << "你击败了黑魔王！" << endl;

				}
				else if (ifWin == 0) {
					mySorcerer->setBlood(0);
					cout << "挑战失败！" << endl;
					mySorcerer->inRoom(&hall);
						//本关地点设置 0大厅 1魔法部 2古灵阁
					roomNum = 0;
					}
				}
				else if (op_forest == 2) {
					cout << "你成功逃离。" << endl;
					mySorcerer->inRoom(&hall);
				}
				else {
					cout << "操作失败！你已经退出房间。" << endl;
					mySorcerer->inRoom(&hall);
				}
			}
			else {
				cout << "输入错误！" << endl;
			}
			cout << "恭喜你通过所有关卡" << endl;
			system("pause");
			system("cls");
	}
	return 1;
}