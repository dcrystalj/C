typedef  : definiramo svoj tip
static spremenljivka  :v metodi je kot globalna
strcmp - enako=0; prvo manjše = -1

*/POINTERJI*/
int  *p;
p = 103;  //kaže v pomnilnik
*p = 42;  //na mesto 103 vpiše 42

int x;
int *p;
p = &x; //p kaže na celico v pomnilniku kjer je x
*p = 15 // ==  x=15

*/TABELE IN POINTERJI*/
a == &a[0] //ime tabele kaže na prvi element

int a[10];
int *pa;

pa = a; //== pa = &a[0]
*(pa+5) = 15; //a[5]=15

pa +=3;
*pa = 7 //a[3]=7

*/KLIC FUNCKCIJE
//spreminjanje vrednosti int preko funkcije
int x;
int y;
int z;
void fun(int *x, int*y, int z){ ... }
->
fun(&x,&y,z); //klic

//spreminjanje vrednosti kazalca preko funkcije
//prenos tabele kot parameter
int *a;
rezerviraj (&a);

void rezerviraj(int **x){
	*x = (int *) malloc(100);
}

*/STRUKTURE
struct kompleksno *z;
(*z).re = 3;
z -> im=2;

typdef struct a
{
	int * a  = (int *) malloc(100 * sizeof(int));
}alfa;   //dejasnko ime

*/DATOTEKE
• Branje (fgetc, fgets, fscanf, fread)
• Pisanje (fputc, fprintf, fwrite)
• Dodajanje (datoteko odpremo s stikalom ”a”)
• Mesto v datoteki (fgetpos)
• Konec datoteke (feof)
• Splakovanje (fflush)

ročice
• stdin (standardni vhod - tipkovnica)
• stdout (standardni izhod - zaslon)
• stderr (standardna napaka - zaslon)

//branje iz vhoda
  char *niz = malloc(100);
  scanf("%s", niz);

 *//fscanf- branje s tabulatorjev

  FILE *f;
  f = fopen("e:\\files.txt", "r");
  if (f == NULL) {
    printf("Datoteka ne obstaja!\n");
    exit(1);
  }

  char vrstica[200];
  char n1[30], n2[30], n3[30];
  int s1, s2;
  int vsota = 0, n = 0;
  while (!feof(f)) {
    int p = fscanf(f, "%s%d%s%s%d", n1, &s1, n2, n3, &s2);
    if (p == 5) {
      fgets(vrstica, 200, f);
      vsota = vsota + s2; n++;
      a = 2;
    }    
  }
  fclose(f);

  *//branje pisanje po znak
  fVhod  = fopen("test.txt",   "r");
  fIzhod = fopen("velike.txt", "w");

  while(feof(fVhod) == 0) {  //int d; while((d=fgetc(fIN)) != EOF) {
    int c = fgetc(fVhod);
    fputc(c, fIzhod);
  }
  fclose(fIzhod);
  fclose(fVhod);

  */stream buffer reader
   char buffer[N];
  int koliko;
  while((koliko = fread(buffer, 1,N, fIN))>0) { //bere iz streama v buffer, koliko bajtov, kolikovkrat po tok bajtov, pointer iz file
    fwrite(buffer,1,koliko, fOUT);
  }

  fclose(fIN);
  fclose(fOUT);
  
*/strtok
  char vrstica[] = "abc:def:xzy";
  char locila[]  = ":";
  char *rezultat;

  rezultat = strtok(vrstica, locila);
  while (rezultat != NULL) {
    printf("%s\n", rezultat);
    rezultat = strtok(NULL, locila);
  }


