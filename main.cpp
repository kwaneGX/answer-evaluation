#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <errno.h>
#include <process.h>
#include <wchar.h>
#include <locale.h>
int main() {

	FILE *voicef;
	char *p;
	voicef = fopen("voicefile.txt", "r");

	if (voicef == NULL)
	{
		printf("voicefile.txt cannot open!\n ");

	}

	else {
	
		printf("####�򿪴������ļ�####\n\n");
	
	}
	//ͳ���ܴ���
	int temp,words_num = 0;
	while ((temp = fgetc(voicef)) != EOF)
		if (temp == ' ')
			words_num++;
	//��ʾtxt����
	rewind(voicef);
	char voice_file;
	while (1) {
		voice_file = fgetc(voicef);
		if (voice_file == EOF) break;
		putc(voice_file, stdout);
	}
	//��ò
	//��Ȩֵ�ļ�
	FILE *W_lm;
	W_lm = fopen("W_lm_keywords.txt", "r");

	if (W_lm == NULL)
	{
		printf("W_lm_keywords.txt cannot open!\n ");

	}

	//�򿪹ؼ���Ŀ¼
	FILE *K_lm;
	K_lm = fopen("lm_keywords.txt", "r");

	if (K_lm == NULL)
	{
		printf("lm_keywords.txt cannot open!\n ");

	}
	else {
		printf("\n####�򿪹ؼ��ʱ�####\n");


	}
	char voicefile_line[1000] = { 0 };
	char K_lm_line[1000] = { 0 };
	char W_lm_line[1000] = { 0 };

	double q_lm = 0;


	printf("\n####��ò����####\n");

	//��ò��
	{	printf("��⵽�ؼ��ʣ�");
	//���ж�ȡ�����ļ� 
	rewind(voicef);
	while (!feof(voicef))
	{//���ж�ȡ�������ļ�
		memset(voicefile_line, 0, sizeof(voicefile_line));
		fgets(voicefile_line, sizeof(voicefile_line) - 1, voicef); // ������\n  

																   //ȥ���س�
		if ((p = strchr(voicefile_line, '\n')) != NULL)
			*p = '\0';//�ֶ���\nλ�ô���ֵ��Ϊ0  

		rewind(K_lm);//�ѵ�ǰ�Ķ�дλ�ûص��ļ���ʼ
		while (!feof(K_lm))
		{
			memset(K_lm_line, 0, sizeof(K_lm_line));
			fgets(K_lm_line, sizeof(K_lm_line) - 1, K_lm); // ������\n  

														   //ȥ���س�
			if ((p = strchr(K_lm_line, '\n')) != NULL)
				*p = '\0';//�ֶ���\nλ�ô���ֵ��Ϊ0  
			if (strstr(voicefile_line, K_lm_line) != NULL) {
				printf(",");
				printf("%s", K_lm_line);
				fgets(W_lm_line, sizeof(K_lm_line) - 1, W_lm);
				//(double)(char (W_lm_line));
				q_lm = atof(W_lm_line) + q_lm;


			}
		}

	}
	fclose(K_lm);
	printf("\n");
	printf("��ò��%f\n", q_lm);
	}

	//ҵ��

	//��Ȩֵ�ļ�
	FILE *W_yw;
	W_yw = fopen("W_yw_keywords.txt", "r");

	if (W_yw == NULL)
	{
		printf("W_yw_keywords.txt cannot open!\n ");

	}

	//�򿪹ؼ���Ŀ¼
	FILE *K_yw;
	K_yw = fopen("yw_keywords.txt", "r");

	if (K_yw == NULL)
	{
		printf("lm_keywords.txt cannot open!\n ");

	}

	char K_yw_line[1000] = { 0 };
	char W_yw_line[1000] = { 0 };
	int Vv_num = 0, VV_num = 0;//ҵ��ʸ���
	int yw_num = 0;
	float yw_sentence_num = 0, Vv_sentence_num = 0;
	double q_yw = 0;

	printf("\n####ҵ������####\n");

	{
		printf("��⵽�ؼ��ʣ�");
		//���ж�ȡ�����ļ� 
		rewind(voicef);
		while (!feof(voicef))
		{//���ж�ȡ�������ļ�
			memset(voicefile_line, 0, sizeof(voicefile_line));
			fgets(voicefile_line, sizeof(voicefile_line) - 1, voicef); // ������\n  
																	   //ȥ���س�
			if ((p = strchr(voicefile_line, '\n')) != NULL)
				*p = '\0';//�ֶ���\nλ�ô���ֵ��Ϊ0  

			rewind(K_yw);//�ѵ�ǰ�Ķ�дλ�ûص��ļ���ʼ
			if (yw_num > 0)//����ҵ��ʵľ�����
				yw_sentence_num++;
			yw_num = 0;
			if (Vv_num > 0)//����ҵ��ʵľ��ӵĶ�����
				Vv_sentence_num++;
			Vv_num = 0;

			while (!feof(K_yw))
			{
				memset(K_yw_line, 0, sizeof(K_yw_line));
				fgets(K_yw_line, sizeof(K_yw_line) - 1, K_yw); // ������\n  

															   //ȥ���س�
				if ((p = strchr(K_yw_line, '\n')) != NULL)
					*p = '\0';//�ֶ���\nλ�ô���ֵ��Ϊ0  
							  //�������


				if (strstr(voicefile_line, K_yw_line) != NULL) {
					fgets(W_yw_line, sizeof(K_yw_line) - 1, W_yw);
					q_yw = atof(W_yw_line) + q_yw;
					printf(","); 
					printf(K_yw_line);
					if(strstr(voicefile_line, K_yw_line)){
					yw_num++;}
					VV_num++;
					if (p = strstr(voicefile_line, "/VV"))
					{
						Vv_num++;

					}


				}

			}

		}
		fclose(K_yw);
		printf("\n");
		printf("ҵ��ʣ�%f\n", q_yw);
	
	}

	//���

	//�򿪼��Դ��ļ�
	FILE *JX_qg;
	JX_qg = fopen("JX_qg_keywords.txt", "r");

	if (JX_qg == NULL)
	{
		printf("JX_qg_keywords.txt cannot open!\n ");

	}
	//��Ȩֵ�ļ�
	FILE *W_qg;
	W_qg = fopen("W_qg_keywords.txt", "r");

	if (W_qg == NULL)
	{
		printf("W_qg_keywords.txt cannot open!\n ");

	}

	//�򿪹ؼ���Ŀ¼
	FILE *K_qg;
	K_qg = fopen("qg_keywords.txt", "r");

	if (K_qg == NULL)
	{
		printf("qg_keywords.txt cannot open!\n ");

	}

	char K_qg_line[1000] = { 0 };
	char W_qg_line[1000] = { 0 };
	char JX_qg_line[1000] = { 0 };
	double q_qg = 0;
	int JX_num = 1;

	printf("\n####��������####\n");

	//��д�
	{	printf("��⵽�ؼ��ʣ�");
	//���ж�ȡ�����ļ� 
	rewind(voicef);
	while (!feof(voicef))
	{//���ж�ȡ�������ļ�
		memset(voicefile_line, 0, sizeof(voicefile_line));
		fgets(voicefile_line, sizeof(voicefile_line) - 1, voicef); // ������\n  

																   //ȥ���س�
		if ((p = strchr(voicefile_line, '\n')) != NULL)
			*p = '\0';//�ֶ���\nλ�ô���ֵ��Ϊ0  
		JX_num = 1;//��ʼ�����Դ�
				   //���Դ�
		while (!feof(JX_qg))
		{
			memset(JX_qg_line, 0, sizeof(JX_qg_line));
			fgets(JX_qg_line, sizeof(JX_qg_line) - 1, JX_qg); // ������\n  

															  //ȥ���س�
			if ((p = strchr(JX_qg_line, '\n')) != NULL)
				*p = '\0';//�ֶ���\nλ�ô���ֵ��Ϊ0  
			if (strstr(voicefile_line, JX_qg_line) != NULL) {
				JX_num = -1;
			}
		}
		rewind(K_qg);//�ѵ�ǰ�Ķ�дλ�ûص��ļ���ʼ
		while (!feof(K_qg))
		{
			memset(K_qg_line, 0, sizeof(K_qg_line));
			fgets(K_qg_line, sizeof(K_qg_line) - 1, K_qg); // ������\n  

														   //ȥ���س�
			if ((p = strchr(K_qg_line, '\n')) != NULL)
				*p = '\0';//�ֶ���\nλ�ô���ֵ��Ϊ0  
			if (strstr(voicefile_line, K_qg_line) != NULL) {
				printf(",");
				printf("%s", K_qg_line);
				fgets(W_qg_line, sizeof(K_qg_line) - 1, W_qg);
				//(double)(char (W_qg_line));
				q_qg = JX_num *atof(W_qg_line) + q_qg;


			}
		}

	}

	printf("\n");
	printf("��д�%f\n", q_qg);
	}
	printf("\n####������####\n");
	float rate_yw = Vv_sentence_num / yw_sentence_num;
	float rate_cp = (float)VV_num / (float)words_num;
	printf("ҵ�������������%f\n", rate_yw);
	printf("ҵ��ʱ�����%f\n", rate_cp);



	fclose(K_qg);
	fclose(K_yw);
	fclose(K_lm);
	fclose(voicef);

	_getch();
	return 0;
}