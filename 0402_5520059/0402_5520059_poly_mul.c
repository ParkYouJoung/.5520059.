#include <stdio.h>
#include <stdlib.h> 

#define MAX_TERMS 101

struct terms {
    float coef;
    int expon;
} terms[MAX_TERMS] = { { 4.0, 3 }, { 3.0, 2 }, { 2.0, 1 }, { 1.0, 0 },
                        { 3.0, 2 }, { 2.0, 1 }, { 8.0, 0 } };

int avail = 7;

// 결과 확인 조건2
// 
//struct terms {
//
//	float coef;
//	int expon;
//}terms[MAX_TEARMS] = { { 7.0, 6 }, { 5.0, 3 }, { 9.0, 2 }, { 1.0, 0 },
//						{ 5.0, 3 }, { 2.0, 2 }, { 1.0, 1 }, { 10.0, 0 } };
//
//int avail = 8;


void print_poly(int s, int e) {
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d +", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

void attach(float coef, int expon) {
    if (avail >= MAX_TERMS) {
        fprintf(stderr, "Too long terms\n");
        exit(1); // 프로그램 종료
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

void poly_mul2(int As, int Ae, int Bs, int Be, int* Csp, int* Cep) {
    int C_start = avail;

    for (int i = As; i <= Ae; i++) {
        for (int j = Bs; j <= Be; j++) {
            float coef = terms[i].coef * terms[j].coef;
            int expon = terms[i].expon + terms[j].expon;

            attach(coef, expon);// 결과 다항식에 항 추가
        }
    }

    *Csp = C_start;
    *Cep = avail - 1;
}

int main() {
    int Cs, Ce;

    poly_mul2(0, 3, 4, 6, &Cs, &Ce);
    print_poly(0, 3);
    print_poly(4, 6);

    /*결과 확인값 2
    poly_mul2(0, 3, 4, 7, &Cs, &Ce);
    print_poly(0, 3);
    print_poly(4, 7);*/

    printf("=======================================================================\n");
    print_poly(Cs, Ce);

    //결과항들이 같은 항끼리 더하기가 자꾸 꼬여서 합한 값은 도출하지 못했습니다.  

    return 0;
}