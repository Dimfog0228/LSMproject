//姥繕端研 隔生檎 益 照税 葵幻聖 戚遂馬糠稽 舘授廃 姥繕拭 旋杯馬陥. 
//姥繕端澗 葵 莫縦, 適掘什澗 凧繕 莫縦戚糠稽 差紫, 搾嘘澗 姥繕端亜 酔是拭 赤陥.
// 巨砺析(淫軒) vs 紗亀(反晴)
// 
// 
//c++拭辞澗 姥繕端亀 適掘什人 暗税 旭精 奄管級聖 紫遂拝 呪 赤生蟹, 葵幻 級醸汗劃 奄管戚 級醸汗劃研 姥歳背辞 床澗 依戚 左奄 疏聖 牛


#include <iostream> // 戚暗 幻窮陥壱 姥繕端 照 幻窮獣娃猿走 杯帖檎 18獣娃 劾顕;;;

struct strt_Box{
	int iData;
	strt_Box* head;
	strt_Box* tail;
	strt_Box* next;
	strt_Box* prev;

	//姥繕端亀 持失切, 敗呪研 亜霜 呪 赤陥.
	strt_Box() {
		iData = 1, head = this, tail = this, next = nullptr, prev = nullptr;
	}
	/*strt_Box(int iData, strt_Box* head, strt_Box* tail, strt_Box* next, strt_Box* prev) : head(head), tail(tail), next(next), prev(prev) {
		iData = 0, head = this, tail = this, next = nullptr, prev = nullptr;
	}*/

	void addStrt_Box() { //昔切葵 隔奄 夙嬢~せせせせせせせせせせせせせ
		tail->next = new strt_Box; //原走厳 酵什税 陥製(因娃)拭 歯稽錘 酵什 持失
		tail->next->iData = tail->iData * 2; //歯稽錘 酵什税 汽戚斗 段奄鉢(原走厳戚醸揮 酵什税 2壕梢 鞠亀系)
		tail->next->prev = tail; // 原走厳 酵什 爽社 煽舌;
		tail = tail->next; //原走厳 陥製拭 幻窮 酵什亜 原走厳 酵什
	}

	void addStrt_Box(int value) { //for庚 床奄 瑛諾焼~せせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせせ

		for (int i = 0; i < value; i++) {
			tail->next = new strt_Box; //原走厳 酵什税 陥製(因娃)拭 歯稽錘 酵什 持失
			tail->next->iData = tail->iData * 2; //歯稽錘 酵什税 汽戚斗 段奄鉢(原走厳戚醸揮 酵什税 2壕梢 鞠亀系)
			tail->next->prev = tail; // 原走厳 酵什 爽社 煽舌;
			tail = tail->next; //原走厳 陥製拭 幻窮 酵什亜 原走厳 酵什
			std::cout << tail->iData <<std::endl;
		}
	}

	void  delStrt_Box() {
		if (tail!=nullptr) {
			tail = tail->prev;
			tail->next = nullptr;
			delete tail->next; //原走厳 酵什研 背薦敗
		}
	}

	void  delStrt_Box(int value) {
		for (int i = 0; i < value; i++) {
			if (tail != nullptr) {
				tail = tail->prev;
				delete tail->next;
				tail->next = nullptr; //原走厳 酵什研 背薦敗
			}
			else i = value;
		}
	}
	
};



int main() {

	strt_Box* strt_Box_A = new strt_Box;

	strt_Box_A->addStrt_Box(2);
	strt_Box_A->delStrt_Box();
	

	std::cout << "EndLine";

}