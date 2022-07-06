#include <stdio.h>


typedef struct {
	char name[20]; // 품목명은 20자 이하
	int qty;
	char size[2];
}
product;

int main(void) {
	int menu, idx = 0;
	product pro[10] = { 0 }; // 품목은 최대 10개의 종류까지 선택 가능

	printf("JUICY KIOSK");
	printf("\n====== menu ======\n");
	printf("1. SEOSON\n2. JUICE\n3. COFFEE\n4. YOGULT\n5. ADE\n\n");

	printf("보고싶은 메뉴를 선택하세요 : ");
	scanf_s("%d", &menu);
	

	if (menu == 1) {
		printf("\nSEOSON\n");

		printf("품목을 선택하세요 : ");
		scanf("%s", &pro[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &pro[idx].qty);
		printf("사이즈를 입력하세요(M) : ");
		scanf("%s", &pro[idx].size);
		idx++;
	}
	else if (menu == 2) {
		printf("\nJUICE\n");

		printf("품목을 선택하세요 : ");
		scanf("%s", &pro[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &pro[idx].qty);
		printf("사이즈를 입력하세요(M / XL) : ");
		scanf("%s", &pro[idx].size);
		idx++;
	}
	else if (menu == 3) {
		printf("\nJUICY COFFEE\n");

		printf("품목을 선택하세요 : ");
		scanf("%s", &pro[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &pro[idx].qty);
		printf("사이즈를 입력하세요(M / XL) : ");
		scanf("%s", &pro[idx].size);
		idx++;
	}
	else if (menu == 4) {
		printf("\nYOGULT\n");

		printf("품목을 선택하세요 : ");
		scanf("%s", &pro[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &pro[idx].qty);
		printf("사이즈를 입력하세요(M / XL) : ");
		scanf("%s", &pro[idx].size);
		idx++;
	}
	else if (menu == 5) {
		printf("\nADE\n");

		printf("품목을 선택하세요 : ");
		scanf("%s", &pro[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &pro[idx].qty);
		printf("사이즈를 입력하세요(M) : ");
		scanf("%s", &pro[idx].size);
		idx++;
	}
	else {
		printf("\n잘못 입력하셨습니다.\n");
	} 

	printf("\n=== 주문 리스트 ===\n");
	printf("품목     수량 사이즈\n");
	for (int i = 0; i < idx; i++) {
		printf("%s %5d %5s", pro[i].name, pro[i].qty, pro[i].size);
	}

	return 0; 
}
