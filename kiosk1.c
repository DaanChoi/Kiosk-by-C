#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
	char name[20]; // 품목명은 20자 이하
	int qty;
	char size[2];
}
product;

int seoson(int qty, char size[]);
int juice(int qty, char size[]);
int coffee(int qty, char size[]);
int yogult(int qty, char size[]);
int ade(int qty, char size[]);
void receipt(int idx, product prd[], int sum);

int main(void) {
	int menu, idx = 0; //메뉴
	int sum = 0; // 총 금액
	product prd[20] = { 0 }; // 품목
	char input; //추가 주문 응답
	char check; //결제 여부 응답
	char discnt; //멤버십 할인 선택 응답

	while (1) {
		printf("\n*******JUICY KIOSK*******\n");
		while(1) {
			printf("\n========= MENU =========\n");
			printf("1. SEOSON\n2. JUICE\n3. COFFEE\n4. YOGULT\n5. ADE\n=========================\n");
			printf("보고싶은 메뉴를 선택하세요 : ");
			scanf_s("%d", &menu);
			if (menu == 1) {
				printf("\n\n--------[SEOSON]--------\n");
				printf("1) 수박살사믹스\n2) 수박살사큐브\n3) 생딸라떼\n4) 봄청블라썸\n\n");
				printf("\nM : 3,500원\n-------------------------\n");
				printf("품목명을 입력하세요 : ");
				scanf("%s", &prd[idx].name);
				printf("수량을 입력하세요 : ");
				scanf("%d", &prd[idx].qty);
				printf("사이즈를 입력하세요(M) : ");
				scanf("%s", &prd[idx].size);
				sum += seoson(prd[idx].qty, prd[idx].size);
				idx++;
			}
			else if (menu == 2) {
				printf("\n---------[JUICE]---------\n");
				printf("1) 바나나\n2) 키위\n3) 파인애플\n4) 초코바나나\n5) 사과\n\n");
				printf("\nM : 1,500원 / XL : 2,800원\n-------------------------\n");
				printf("품목명을 입력하세요 : ");
				scanf("%s", &prd[idx].name);
				printf("수량을 입력하세요 : ");
				scanf("%d", &prd[idx].qty);
				printf("사이즈를 입력하세요(M / XL) : ");
				scanf("%s", &prd[idx].size);
				sum += juice(prd[idx].qty, prd[idx].size);
				idx++;
			}
			else if (menu == 3) {
				printf("\n--------[JUICY COFFEE]--------\n");
				printf("1) 바닐라라떼\n2) 카페모카\n3) 카라멜마끼야또\n4) 연유커피\n\n");
				printf("\nM : 2,000원 / XL : 3,500원\n------------------------------\n");
				printf("품목명을 입력하세요 : ");
				scanf("%s", &prd[idx].name);
				printf("수량을 입력하세요 : ");
				scanf("%d", &prd[idx].qty);
				printf("사이즈를 입력하세요(M / XL) : ");
				scanf("%s", &prd[idx].size);
				sum += coffee(prd[idx].qty, prd[idx].size);
				idx++;
			}
			else if (menu == 4) {
				printf("\n--------[YOGULT]--------\n");
				printf("1) 바나나요거트\n2) 딸기요거트\n3) 블루베리요거트\n\n");
				printf("\nM : 2,000원 / XL : 3,800원\n-------------------------\n");
				printf("품목명을 입력하세요 : ");
				scanf("%s", &prd[idx].name);
				printf("수량을 입력하세요 : ");
				scanf("%d", &prd[idx].qty);
				printf("사이즈를 입력하세요(M / XL) : ");
				scanf("%s", &prd[idx].size);
				sum += yogult(prd[idx].qty, prd[idx].size);
				idx++;
			}
			else if (menu == 5) {
				printf("\n--------[ADE]--------\n");
				printf("1) 레몬\n2) 오렌지\n3) 자몽\n4) 청포도\n\n");
				printf("\nM : 3,800원\n-------------------------\n");
				printf("품목명을 입력하세요 : ");
				scanf("%s", &prd[idx].name);
				printf("수량을 입력하세요 : ");
				scanf("%d", &prd[idx].qty);
				printf("사이즈를 입력하세요(M) : ");
				scanf("%s", &prd[idx].size);
				sum += ade(prd[idx].qty, prd[idx].size);
				idx++;
			}
			else {
				printf("\n잘못 선택하셨습니다. 다시 선택해주세요.\n");
			}
			printf("\n추가로 주문하시겠습니까?(y/n) : ");
			scanf(" %c", &input);
			if (input == 'n') {
				break;
			}
		}

		printf("주문 리스트를 확인해 주세요.");
		printf("\n\n===== 주문 리스트 =====\n");
		printf("품목  수량  사이즈\n");
		for (int i = 0; i < idx; i++) {
			printf("%s  %d  %s\n", prd[i].name, prd[i].qty, prd[i].size);
		}
		printf("\n\n총 금액 : %d원\n", sum); 
		printf("=======================\n");

		printf("결제하시겠습니까?(y/n) : ");
		scanf(" %c", &check);
		if (check == 'y') {
			break;
		}
		idx = 0;
		sum = 0;
		getchar();
	}
	
	printf("\n멤버십 할인을 하시겠습니까?(y/n) {VIP등급 10%% 할인 (월 1회만 가능)} : ");
	scanf(" %c", &discnt);
	if (discnt == 'y') {
		sum *= 0.9;
		printf("10%% 할인됐습니다. 할인된 가격 %d원으로 결제됩니다.\n", sum);
	} 
	else {
		printf("기존 가격 %d원으로 결제됩니다.\n\n", sum);
	}

	receipt(idx, prd, sum);

	return 0;
}
int seoson(int qty, char size[]) {
	if (strcmp(size, "M") == 0) {
		return 3500 * qty;
	}
}
int juice(int qty, char size[]) {
	if (strcmp(size, "M") == 0) {
		return 1500 * qty;
	}
	if (strcmp(size, "XL") == 0) {
		return 2800 * qty;
	}
}
int coffee(int qty, char size[]) {
	if (strcmp(size, "M") == 0) {
		return 2000 * qty;
	}
	if (strcmp(size, "XL") == 0) {
		return 3500 * qty;
	}
}
int yogult(int qty, char size[]) {
	if (strcmp(size, "M") == 0) {
		return 2000 * qty;
	}
	if (strcmp(size, "XL") == 0) {
		return 3800 * qty;
	}
}
int ade(int qty, char size[]) {
	if (strcmp(size, "M") == 0) {
		return 3800 * qty;
	}
}
void receipt(int idx, product prd[], int sum) {
	FILE* fp = fopen("receipt.txt", "w");
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	//콘솔창에 출력(표준 출력(화면))
	printf("=====================================\n");
	printf("               영수증                \n");
	printf("=====================================\n");
	printf("[사업장] 주씨 단국대점\n");
	printf("[사업자] 106-82-02786\n");
	printf("[주소] 경기 용인시 수지구 죽전로 152-1\n");
	printf("[전화번호] 031-262-2770\n");
	printf("[매출일] %d-%d-%d  %d:%d:%d\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("[주문번호] 0050\n");
	printf("-------------------------------------\n");
	printf("상품명           수량           금액\n");
	for (int i = 0; i < idx; i++) {
		printf("%s %10d %10s\n", prd[i].name, prd[i].qty, prd[i].size);
	}
	printf("-------------------------------------\n");
	printf("합계금액                    %d원\n", sum);
	printf("=====================================\n");
	printf("    ***신용승인정보(고객용)[1]***   \n");


	//파일에 출력(쓰기)
	fputs("=====================================\n", fp);
	fputs("               영수증                \n", fp);
	fputs("=====================================\n", fp);
	fputs("[사업장] 주씨 단국대점\n", fp);
	fputs("[사업자] 106-82-02786\n", fp);
	fputs("[주소] 경기 용인시 수지구 죽전로 152-1\n", fp);
	fputs("[전화번호] 031-262-2770\n", fp);
	fprintf(fp, "%s %d%c%d%c%d  %d%c%d%c%d\n", "[매출일]", tm.tm_year + 1900, '-', tm.tm_mon + 1, '-', tm.tm_mday, tm.tm_hour, ':', tm.tm_min, ':', tm.tm_sec);
	fputs("[주문번호] 0050\n", fp);
	fputs("-------------------------------------\n", fp);
	fputs("상품명           수량           금액\n", fp);
	for (int i = 0; i < idx; i++) {
		fprintf(fp, "%s %10d %10s\n", prd[i].name, prd[i].qty, prd[i].size);
	}
	fputs("-------------------------------------\n", fp);
	fprintf(fp, "%s                    %d%s\n", "합계금액", sum, "원");
	fputs("=====================================\n", fp);
	fputs("    ***신용승인정보(고객용)[1]***   \n", fp);
	

	fclose(fp);
}
