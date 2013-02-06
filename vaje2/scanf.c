int main(){
	int n=0;		// stevilo prebranih ocen
	int vsota=0;	// vsota prebranih stevil
	int ocena;	// trenutna ocena
	
	do{
		printf("vpisi oceno: ");
		scanf("%d", &ocena);
		if( ocena != 0) {
			vsota+=ocena;
			n+=1;
		}
	} while(ocena!=0);
	printf("povprecje: %.2f",(float)vsota/n);
	return 0;
}
