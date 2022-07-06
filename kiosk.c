#include <stdio.h>


typedef struct {
	char name[20]; // 품목명은 20자 이하
	int qty;
	char size[2];
}
product;

int main(void) {
	int menu, idx = 0;
	product prd[10] = { 0 }; // 품목은 최대 10개의 종류까지 선택 가능

	printf("JUICY KIOSK");
	printf("\n====== menu ======\n");
	printf("1. SEOSON\n2. JUICE\n3. COFFEE\n4. YOGULT\n5. ADE\n\n");

	printf("보고싶은 메뉴를 선택하세요 : ");
	scanf_s("%d", &menu);
	

	if (menu == 1) {
		printf("\n[SEOSON]\n");
		printf("\nM : 3,500원\n");
		printf("\n수박살사믹스\n수박살사큐브\n생딸라떼\n봄청블라썸\n\n");

		printf("품목명을 입력하세요 : ");
		scanf("%s", &prd[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &prd[idx].qty);
		printf("사이즈를 입력하세요(M) : ");
		scanf("%s", &prd[idx].size);
		idx++;
	}
	else if (menu == 2) {
		printf("\n[JUICE]\n");
		printf("\nM : 1,500원 / XL : 2,800원\n");
		printf("\n바나나\n키위\n파인애플\n초코바나나\n사과\n\n");

		printf("품목명을 입력하세요 : ");
		scanf("%s", &prd[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &prd[idx].qty);
		printf("사이즈를 입력하세요(M / XL) : ");
		scanf("%s", &prd[idx].size);
		idx++;
	}
	else if (menu == 3) {
		printf("\n[JUICY COFFEE]\n");
		printf("\nM : 2,000원 / XL : 3,500원\n");
		printf("\n바닐라라떼\n카페모카\n카라멜마끼야또\n연유커피\n\n");

		printf("품목명을 입력하세요 : ");
		scanf("%s", &prd[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &prd[idx].qty);
		printf("사이즈를 입력하세요(M / XL) : ");
		scanf("%s", &prd[idx].size);
		idx++;
	}
	else if (menu == 4) {
		printf("\n[YOGULT]\n");
		printf("\nM : 2,000원 / XL : 3,800원\n");
		printf("\n바나나요거트\n딸기요거트\n블루베리요거트\n\n");

		printf("품목명을 입력하세요 : ");
		scanf("%s", &prd[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &prd[idx].qty);
		printf("사이즈를 입력하세요(M / XL) : ");
		scanf("%s", &prd[idx].size);
		idx++;
	}
	else if (menu == 5) {
		printf("\n[ADE]\n");
		printf("\nM : 3,800원\n");
		printf("\n레몬\n오렌지\n자몽\n청포도\n\n");

		printf("품목명을 입력하세요 : ");
		scanf("%s", &prd[idx].name);
		printf("수량을 입력하세요 : ");
		scanf("%d", &prd[idx].qty);
		printf("사이즈를 입력하세요(M) : ");
		scanf("%s", &prd[idx].size);
		idx++;
	}
	else {
		printf("\n잘못 입력하셨습니다.\n");
	} 

	printf("\n=== 주문 리스트 ===\n");
	printf("품목  수량  사이즈\n");
	for (int i = 0; i < idx; i++) {
		printf("%s %d %s", prd[i].name, prd[i].qty, prd[i].size);
	}

	return 0; 
}
// https://dailylifestory.tistory.com/147
