//#include <iostream>
//
//int main(void)
//{
//	//�ش� �ڵ�� �ʱ�ȭ ����Ʈ�� ������� �ʰ� ���Ե� Ŭ������ �ʱ�ȭ ��Ű�� ����Դϴ�. �׷��� ������� �ʴ� ������ �ֽ��ϴ�.
//}
//
//class two {
//public:
//	two() {
//
//	};
//	two(int size) {
//		int x = size;
//		int lsm(size);
//	};
//
//};
////two::two(int size) {};
//
//class one {
//public:
//	one(int size);
//private:
//	int size = 3;
//	two data = two(10);//��ü�� ���� �� �����ڸ� ȣ����. data��� ��ü�� ����� �װ��� two(10)�� �����ϰڴٴ� �ǹ�. ���⼭�� data�� �⺻�����ڷ� �ʱ�ȭ�ǰ�
//						//�ٽ� two(int size)�� �ʱ�ȭ �ȴ�.(2���� �ʱ�ȭ)
//	//two data(10); -> Ŭ�������� �����ڸ� ���� ȣ���ϴ� ���� ������ �ʴ´�. ��ü�� ���� �� ȣ���ؾ��Ѵ�.(��ü ���� ������ ȣ�� ��ü�� �Ұ���)
//	//��ü�� ���� �� �����ڰ� �ڵ����� ȣ��ǹǷ�, Ŭ���� ������ �ٽ� ȣ���� �ʿ䰡 ����.
//};
//
//one::one(int size) { //�����ε� 
//	data = two(size);
//}
////
//////ȿ����: ��� ���� data�� ���� ����Ʈ �����ڷ� �ʱ�ȭ�ǰ�, �� ������ ���� �����ڸ� ���� two(size) �����ڷ� �ʱ�ȭ�˴ϴ�. �̰��� �� �ܰ��� �ʱ�ȭ ������ ��Ĩ�ϴ�. �ʱ�ȭ ����Ʈ�� ����ϸ� ���� �����ڸ� ȣ���ϹǷ� �ʱ�ȭ ������ ���ʿ��ϰ� �� �� �߻����� �ʽ��ϴ�.
// ////����Ʈ ������ ȣ�� : two Ŭ������ ����Ʈ �����ڿ� �Ű������� �޴� ������ �� ������ ���ǵǾ� �ֽ��ϴ�.��� ���� data�� ���� ����Ʈ �����ڷ� �ʱ�ȭ�ǰ�, �׷� ���� ���� �����ڸ� ���� �ٸ� �����ڷ� �ʱ�ȭ�˴ϴ�.����Ʈ �����ڰ� �ʿ����� ���� ��쿡�� ȣ��˴ϴ�.
//
//////���⼺ : �ʱ�ȭ ����Ʈ�� ����ϸ� �ڵ尡 �� �����ϰ� �б� �����ϴ�.���� �����ڸ� ����ϴ� ��� �ʱ�ȭ ���μ����� Ŭ���� ������ ������ ������ Ŭ���� ���ǿ� �ʱ�ȭ�� �и��Ǿ� �ڵ带 �����ϱ� ������� �� �ֽ��ϴ�.
//////
//////���� C++������ ������ �� �ʱ�ȭ ����Ʈ�� ����Ͽ� Ŭ������ ��� ������ �ʱ�ȭ�ϴ� ���� ����˴ϴ�.�ʱ�ȭ ����Ʈ�� ���� �� �ڵ� ������ �鿡�� ������ �����ϸ�, ���� �ڵ忡�� one Ŭ������ �����ڸ� ������ ���� ������ �� �ֽ��ϴ� :