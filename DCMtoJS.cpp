#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp;
	unsigned int offset=5894,datalength=120000;
	unsigned char buf[120000];
	fp=fopen("123456_2019_05_02_14_04_06.dcm","rb");
	fseek(fp,5894,SEEK_SET);//5894����Ʀ�m 
	fread(buf,1,120000,fp);//120000����Ƽ� 
	short x1;
	FILE * pFile2;
     pFile2 = fopen ("001.js", "w");//�]�w��XJS�W�� 
     fprintf(pFile2,"var waveone =[");
     for(int i=0; i<120000;i=i+24)
         {
         x1=buf[i]+buf[i+1]*256;//2��bytes��ܤ@�Ӽƾ� 
         fprintf(pFile2,"%d",x1-4096);//4096���߹q�ϸ�ƪ�����I 
		 if(i+24<120000){
		 fprintf(pFile2,",\n");
	}
         }
    fprintf(pFile2,"];");
    fclose (pFile2);
    fclose(fp);
    system("pause");
	return 0;	
}

