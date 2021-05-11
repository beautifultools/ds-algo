#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main(void) {
	// 리스트 생성 및 초기화
	List list;
	int data;
	LisInit(&list);

	SetSortRule(WhoIsPrecede);

	LInsrt(&list, 11);	LInsrt(&list, 22);
	LInsrt(&list, 12);	LInsrt(&list, 23);
	LInsrt(&list, 13);	LInsrt(&list, 22);
	LInsrt(&list, 14);	LInsrt(&list, 25);

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d", data);
		while (LNext(&list, &data))
			printf("%d", data);
	}
	printf("\n\n");

	// 숫자 22를 검색해서 모두 삭제
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}

	// 삭제 후 남아 있는 데이터 전체 출력 
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d", data);
		while (LNext(&list, &data))
			printf("%d", data);
	}
	printf("\n\n");
	return 0;
}