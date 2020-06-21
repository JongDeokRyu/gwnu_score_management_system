#include <stdio.h>

#define OUTPUT "topten.txt"  

void main()

{

	struct student {    

		char name[10];

		float sub[3];

		float total;

		int rank;

	} s[10];

	int i, j;

	char filename[20];

	FILE* fp1, * fp2;   



	while (1) 

	{

		printf("입력할 파일명을 입력하세요(예: *.txt):"); 

		scanf_s("%s", filename, 20);       

									  

		fopen_s(&fp1, filename, "r");  



		if (fp1 == NULL)     

			printf("해당 파일이 없습니다."); 

		else       
			break;        

	}

	for (i = 0; i < 10; i++) {   

		fscanf_s(fp1, "%s", s[i].name, 20);

		fscanf_s(fp1, "%f %f %f", &s[i].sub[0], &s[i].sub[1], &s[i].sub[2]);

	}



	fclose(fp1);    



	for (i = 0; i < 10; i++)  

		s[i].total = s[i].sub[0] + s[i].sub[1] + s[i].sub[2];	



	for (i = 0; i < 10; i++)   

	{

		s[i].rank = 1; 

		for (j = 0; j < 10; j++)  

		{

			if (s[i].total < s[j].total)  

				s[i].rank++;   

		}

	}



	printf("┌──────【 입력된 성적표 】──────┐\n");

	printf("│    이름        국어      수학      영어 │\n");

	for (j = 0; j < 10; j++)       

		printf("│%10s%10.1f%10.1f%10.1f  │\n", s[j].name, s[j].sub[0], s[j].sub[1], s[j].sub[2]);

	printf("└─────────────────────┘\n\n");



	fopen_s(&fp2, OUTPUT, "w");  



	printf("┌───────────【 순위별 성적표 】───────────┐\n");

	fprintf(fp2, "┌───────────【 순위별 성적표 】───────────┐\n");

	printf("│     이 름      국어      수학      영어     합계       등수 │\n");

	fprintf(fp2, "│     이 름      국어      수학      영어     합계       등수 │\n");



	



	for (i = 1; i <= 10; i++)  

	{

		for (j = 0; j < 10; j++)  

		{

			if (s[j].rank == i)

			{

				printf("├───────────────────────────────┤\n");

				fprintf(fp2, "├───────────────────────────────┤\n");

				printf("│%10s%10.1f%10.1f%10.1f%10.1f%10d  │\n", s[j].name, s[j].sub[0], s[j].sub[1], s[j].sub[2], s[j].total, s[j].rank);

				fprintf(fp2, "│%10s%10.1f%10.1f%10.1f%10.1f%10d  │\n", s[j].name, s[j].sub[0], s[j].sub[1], s[j].sub[2], s[j].total, s[j].rank);

			} 

		}

	}

	printf("└───────────────────────────────┘\n");

	fprintf(fp2, "└───────────────────────────────┘\n");

	fclose(fp2); 

}

