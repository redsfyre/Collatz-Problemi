#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    int sayi = 0;
    int pid, status;
 
    printf("Baslangic icin bir sayi giriniz: ");
    scanf("%d", &sayi);

    if(sayi <= 0){
	    while(sayi <= 0){
	    	printf("Sayi sifirdan kucuk olamaz! Lutfen sifirdan buyuk bir sayi giriniz: ");
	    	scanf("%d", &sayi);
	    }
	    //TO DO: Tekrar tekrar kontrol edilmesindense while döngüsüne alınabilir...
	    /*
	    if(sayi < 0){
		    printf("Girdiginiz sayilar gereklilikleri karsilamiyor. Lutfen programi tekrar calistirin! \n");
		    exit(-1);
	    }
	    if(sayi == 0){
		    printf("Sayi sifira esit olamaz! \n");
		    return -1;
	    }
	    */
	    //Dediğimi yaptım ama ibret olması açısından yukarıyı silmiyorum :(
	    
    }
 
    pid = fork();
 
    if(pid < 0){
	    printf("Child process olusturulamadi! \n");
	    return -1;
    }
 
    else if(pid == 0){
        do{

        	if(sayi % 2 != 0){
          	sayi = (sayi * 3) + 1;
       	 	}
         
        	else if(sayi % 2 == 0){
          	sayi = sayi / 2;
        	}

 		printf("%d\n", sayi);
        }
	while(sayi != 1);
    }
 
    else{
        	printf("pid %d \n", pid);
        	printf("Child process bekleniyor.\n");
        	wait(&status);
    }
    
    return 1;   
}
