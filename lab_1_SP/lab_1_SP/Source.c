#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int CPUID_0() {
	system("cls");
	int i, j, k, l = 0;

	_asm {
		mov eax, 0;
		cpuid;
		mov i, eax;
		mov j, ebx;
		mov k, edx;
		mov l, ecx;
	}
	printf("The maximum basic dialing feature number allowed for this given CPU: ");
	printf("%d\n", i);

	printf("Manufacturer information:  ");

	while (j != 0) {

		printf("%c", j);
		j = j >> 8;
	};
	while (k != 0) {

		printf("%c", k);
		k = k >> 8;

	};
	while (l != 0) {

		printf("%c", l);
		l = l >> 8;

	};
	printf("\n");
	system("pause");

};

int CPUID_1() {

	system("cls");

	printf("Processor signature:\n");
	int i, j, k, l = 0;
	_asm {

		mov eax, 1;
		cpuid;
		mov i, eax;
		mov j, ebx;
		mov l, ecx;
		mov k, edx;

	}


	int temp = Splitting_Bits(i, 0, 3);
	{
		printf("Stepping ID: %xh\n", temp);

		temp = Splitting_Bits(i, 4, 7);
		printf("Model Number: %xh\n", temp);

		temp = Splitting_Bits(i, 8, 11);
		printf("Family Code: %xh\n", temp);

		temp = Splitting_Bits(i, 12, 13);
		printf("Processor Type: %xh\n", temp);

		temp = Splitting_Bits(i, 14, 15);
		printf("Reserve: %xh\n", temp);

		temp = Splitting_Bits(i, 16, 19);
		printf("Extended Model: %xh\n", temp);

		temp = Splitting_Bits(i, 20, 27);
		printf("Extended Family: %xh\n", temp);

		temp = Splitting_Bits(i, 28, 31);
		printf("Reserve: %xh\n", temp);
	}

	{
		temp = Splitting_Bits(j, 0, 7);
		printf("Brand ID: %xh\n", temp);

		temp = (Splitting_Bits(j, 8, 15)) * 8;
		printf("Chunks: %xh\n", temp);

		temp = Splitting_Bits(j, 16, 23);
		printf("Reserve: %xh\n", temp);

		temp = Splitting_Bits(j, 24, 31);
		printf("APIC ID: %xh\n", temp);
	};

	{
		printf("Num of Bits ECX: ");
		for (int m = 0; m < 31; m++) {
			temp = Splitting_Bits(l, m, m);
			printf("%xh ", temp);
		}
		printf("\n");
	}

	{
		printf("Num of Bits EDX: ");
		for (int m = 0; m < 31; m++) {
			temp = Splitting_Bits(k, m, m);
			printf("%xh ", temp);
		}
		printf("\n");


	}

	printf("\n");
	system("pause");
};

int CPUID_2() {
	system("cls");

	printf("Information about all types of processor caches: \n");
	int i, j, k, l = 0;
	_asm {
		mov eax, 2;
		cpuid;
		mov i, eax;
		mov j, ebx;
		mov l, ecx;
		mov k, edx;
	}

	//EAX
	{

		int temp = Splitting_Bits(i, 24, 31);
		printf("EAX: %xh ", temp);
		temp = Splitting_Bits(i, 16, 23);
		printf("%xh ", temp);
		temp = Splitting_Bits(i, 8, 15);
		printf("%xh ", temp);
		temp = Splitting_Bits(i, 0, 7);
		printf("%xh\n", temp);

	}

	//EBX
	{
		int temp = Splitting_Bits(j, 24, 31);
		printf("EBX: %xh ", temp);
		temp = Splitting_Bits(j, 16, 23);
		printf("%xh ", temp);
		temp = Splitting_Bits(j, 8, 15);
		printf("%xh ", temp);
		temp = Splitting_Bits(j, 0, 7);
		printf("%xh\n", temp);
		
	}

	//ECX
	{
		int temp = Splitting_Bits(l, 0, 7);
		printf("ECX: %xh ", temp);
		temp = Splitting_Bits(l, 8, 15);
		printf("%xh ", temp);
		temp = Splitting_Bits(l, 16, 23);
		printf("%xh ", temp);
		temp = Splitting_Bits(l, 24, 31);
		printf("%xh\n", temp);
	}

	//EDX
	{
		int temp = Splitting_Bits(k, 24, 31);
		printf("EDX: %xh ", temp);
		temp = Splitting_Bits(k, 16, 23);
		printf("%xh ", temp);
		temp = Splitting_Bits(k, 8, 15);
		printf("%xh ", temp);
		temp = Splitting_Bits(k, 0, 7);
		printf("%xh\n", temp);

	}

	printf("\n");
	system("pause");
};

int CPUID_3() {
	system("cls");

	printf("Proccessor Serial Number: \n");
	int i, j, k, l = 0;
	_asm {
		mov eax, 3;
		cpuid;
		mov i, eax;
		mov j, ebx;
		mov l, ecx;
		mov k, edx;
	}
	
	short  temp = Splitting_Bits(i, 0, 15);
	printf("Processor Serial Number: %04x - ", temp);
	temp = Splitting_Bits(i, 16, 31);
	printf("%04x - ", temp);
	temp = Splitting_Bits(l, 0, 15);
	printf("%04x - ", temp);
	temp = Splitting_Bits(l, 16, 31);
	printf("%04x - ", temp);
	temp = Splitting_Bits(k, 0, 15);
	printf("%04x - ", temp);
	temp = Splitting_Bits(k, 16, 31);
	printf("%04x\n", temp);

	system("pause");

}

int Splitting_Bits(int number, int begin, int end) {

	return (((1 << (end - begin + 1)) - 1) & (number >> begin));

};


int main() {
	int c = 1;

	while (c) {

		system("cls");
		printf("===MENU===\n");
		printf("|0| Exit\n");
		printf("|1| Function 0.\n");
		printf("|2| Function 1.\n");
		printf("|3| Function 2.\n");
		printf("|4| Function 3.\n");
		printf("Choose your action >> ");
		scanf("%d", &c);

		switch (c)
		{
		case 0: break;
		case 1:
			CPUID_0();
			break;
		case 2:
			CPUID_1();
			break;
		case 3:
			CPUID_2();
			break;
		case 4:
			CPUID_3();
			break;
		default:
			break;
		}
	}
	return 0;
}