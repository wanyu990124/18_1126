//1.��д������ unsigned int reverse_bit(unsigned int value); 
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ�� 
//�磺 ��32λ������25���ֵ�������и�λ�� 00000000000000000000000000011001 
//��ת�󣺣�2550136832�� 10011000000000000000000000000000 ���������أ� 2550136832

#include<stdio.h>
#include<stdlib.h>
unsigned int get_value(unsigned int N) {
	unsigned int value = 1;
	for (unsigned int i = 0; i<N; ++i) {
		value *= 2;
	}
	return value;
}

unsigned int reverse_bit(unsigned int value) {
	char arr[32] = { 0 };
	int i = 31;
	unsigned int result = 0;
	while (value) {
		arr[i--] = value % 2 + '0';
		value >>= 1;          
	}
	for (; i >= 0; i--) {
		arr[i] = arr[i] + '0';
	}
	for (int j = 0; j<32; ++j) {
		unsigned int ret = arr[j] - '0';
		result += ret*get_value(j);   
	}
	return result;
}

void main() {
	unsigned int value = 25;
	printf("%u\n", reverse_bit(value));
	system("pause");
}

//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 0, b = 0;
	int avg = 0;
	scanf("%d%d", &a, &b);
	avg = (a + b) >> 1;
	printf("%d", avg);
	system("pause");
	return 0;
}

//3.���ʵ�֣� һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
//���ҳ�������֡���ʹ��λ���㣩

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main() {
	int arr[] = { 1, 3, 3, 1, 4, 6, 4, 5, 5 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 1; i<len; i++) {
		arr[0] = arr[0] ^ arr[i];
	}
	printf("%d\n", arr[0]);
	system("pause");
	return 0;
}

//4. ��һ���ַ����������Ϊ:"student a am i", ���㽫��������ݸ�Ϊ"i am a student".
//Ҫ�� ����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>

void reverse_arr(char* left, char* right) {
	assert(left);
	assert(right);
	while (left<right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

char* reverse(char arr[]) {
	int len = strlen(arr);
	char *start = arr;
	char *end = NULL;
	char *ret = arr;
	reverse_arr(arr, arr + len - 1);
	while (*arr) {
		start = arr;
		while ((*arr != ' ') && (*arr != '\0')) {
			arr++;
		}
		end = arr - 1;
		reverse_arr(start, end);
		if (*arr == ' ') {
			arr++;
		}
	}
	return ret;
}

int main() {
	char arr[] = "student a am i";
	printf("%s\n", reverse(arr));
	system("pause");
	return 0;
}
