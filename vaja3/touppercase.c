#include <stdio.h>

int main(){
	FILE *fVhod, *fIzhod;
	fVhod = fopen("C:\\Users\\Crystal\\Desktop\\test.txt","r");
	fIzhod = fopen("velike.txt", "w");

	while( feof(fVhod)==0 ){
		int c = fgetc(fVhod);

		//male crke v velike
		if (c >= 'a' && c <= 'z'){
			c = c - ' ' ;
		}
		fputc(c, fIzhod);
	}

	fclose(fIzhod);
	fclose(fVhod);

	return 0;
}
