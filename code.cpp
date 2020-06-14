#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "console.h"
#include <conio.h>
//1 ham console.h
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void TextColor (int color)
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
//2	
//dinh nghia man hinh console
#define consoleWidth 80
#define consoleHeight 29
#define roadWidth	39

//3. Khai báo cau trúc struct và các bien thành phan 
struct HDxe{
	char hdxe[4][6];
};
  struct TDxe{
	int x,y;
  };
  struct Xe{
  	HDxe hd;
  	TDxe td;
  	int diem;
  };

//4.Hinh dang xe	
void demoXe(Xe &xe){
#define TD xe.hd.hdxe
    xe.td.y = consoleHeight - 3;
	xe.td.x = 14 ;
	xe.diem = 0;
	TD[0][0]=TD[0][1]=TD[0][4]=TD[0][5]= (NULL);
	TD[0][2]=TD[0][3] = putchar(176) ;
	TD[1][0]=TD[1][1]=TD[1][2]=TD[1][3]=TD[1][4]=TD[1][5]= putchar(176);
	TD[2][0]=TD[2][1]=TD[2][4]=TD[2][5]= (NULL);
	TD[2][2]=TD[2][3] = putchar(176) ;
	TD[3][0]=TD[3][1]=TD[3][4]=TD[3][5]= putchar(176);
	TD[3][2]=TD[3][3]= (NULL);

}

//hien thi xe
void hienthixe(Xe xe){
  for(int c= 0;c<6;c++){	
   for(int h= 0;h<4;h++){
    	int x = c + xe.td.x;
    	int y = h + xe.td.y;
    	gotoXY(x,y);
    	putchar(xe.hd.hdxe[h][c]);
    }
  }
}

//dieu khien
int dieukhien(Xe &xe){
	if(kbhit()){
	 int dk=getch();
	   if(dk == 'a' && xe.td.x>2)
	     xe.td.x-=2;
	   if(dk== 'd' && xe.td.x< roadWidth-8 )
	     xe.td.x+=2;
	   if(dk == 'w' && xe.td.y > 2)
	     xe.td.y-=2;
	   if(dk == 's' && xe.td.y<consoleHeight-3)
	     xe.td.y+=2;
	   if( dk == putchar(13) )
	     system("pause");
}
return 0;
}



	
//vat can
struct HDvc{
	char hdvc[4][6];
	char hdvc2[4][6];
};
  struct TDvc{
	int x,y;
  };
  struct vatcan{
  	HDvc hd;
  	TDvc td;
  };
  
//hinh dang vat can
void demovc(vatcan &vc,vatcan &vc2){
	 srand(time(NULL));
	 vc.td.x = 2 + rand() % (roadWidth -8);
	 vc.td.y = -1;
	 vc2.td.x = 2 + rand() % (roadWidth -8);
	 vc2.td.y = -15;
	 
	 
	#define TDvc vc.hd.hdvc 
	//vat can 1
   TDvc[0][0]=TDvc[0][1]=TDvc[0][3]=TDvc[0][4]=TDvc[0][5]= putchar(176);
   TDvc[1][0]=TDvc[1][1]=TDvc[1][2]=TDvc[1][4]=TDvc[1][5]= putchar(176);
   TDvc[2][0]=TDvc[2][2]=TDvc[2][3]=TDvc[2][4]=TDvc[2][5]= putchar(176);
   TDvc[3][0]=TDvc[3][1]=TDvc[3][2]=TDvc[3][4]=TDvc[3][5]= putchar(176);
   TDvc[0][2]=TDvc[1][3]=TDvc[2][1]=TDvc[3][3]= (NULL);
   #define TDvc vc2.hd.hdvc2
   //vatcan2
   TDvc[0][0]=TDvc[0][1]=TDvc[0][3]=TDvc[0][4]=TDvc[0][5]= putchar(176);
   TDvc[1][0]=TDvc[1][1]=TDvc[1][2]=TDvc[1][4]=TDvc[1][5]= putchar(176);
   TDvc[2][0]=TDvc[2][2]=TDvc[2][3]=TDvc[2][4]=TDvc[2][5]= putchar(176);
   TDvc[3][0]=TDvc[3][1]=TDvc[3][2]=TDvc[3][4]=TDvc[3][5]= putchar(176);
   TDvc[0][2]=TDvc[1][3]=TDvc[2][1]=TDvc[3][3]= (NULL);
}


void hienthivc(vatcan vc,vatcan vc2){
	
	for(int c= 0;c<6;c++){	
     for(int h= 0;h<4;h++){
     
	 	//toa do vat can 1
    	int x = c + vc.td.x;
    	int y = h + vc.td.y;
    	
		//toa do vat can 2
    	int x2 = c + vc2.td.x;
    	int y2 = h + vc2.td.y;
    
	//	in vat can 1
    if (y>=0 && y <=consoleHeight ){
				gotoXY (x, y);
				putchar (vc.hd.hdvc[h][c]);
}
    // in vat can 2
    if (y2>=0 && y2<=consoleHeight)	{
				gotoXY (x2,y2);
				putchar(vc2.hd.hdvc2[h][c]);	
	  }
}
}
}







//in bien doc
void inbiendoc(){
	
 //in bien trai
 for(int i=1;i < consoleHeight+1;i++){
    printf("%c\n",124);
    }
    
// in bien phai
  for(int i=0;i < consoleHeight;i++){
    gotoXY(roadWidth,i);	
    putchar (124);
    }
}


// in diem 	
void indiem(Xe &xe){
	gotoXY(roadWidth+5, 15);
	printf("DIEM: %d ",xe.diem);
	gotoXY (roadWidth +5, 6) ;
	printf ("ENTER	- Tam dung va nhan phim bat ki de tiep tuc!"); 
}


int xuli(Xe &xe, vatcan &vc, vatcan &vc2, int &tdgame){
	//vat can	 di chuyen
	vc.td.y+=2;
	vc2.td.y+=2;


	//xu li vatcan 1    
	if(vc.td.y >= consoleHeight ) {
	//	vc2.td.y+=2;
	    xe.diem+=100; 
		vc.td.x = 2 + rand() % (roadWidth - 8);
	    vc.td.y = -2;
    }
    
    //xu li vatcan 2
    if(vc2.td.y >= consoleHeight){
	  //  vc.td.y+=2;
    	xe.diem+=100; 
		vc2.td.x = 2 + rand() % (roadWidth - 8);
	    vc2.td.y = -2;
	 //xu li toc do cua game 
	  if (tdgame >50)
	    tdgame -= 10;
	}
	
	// xu li khi va cham
	int dX = abs (xe.td.x - vc.td.x);
	int dY = abs (xe.td.y - vc.td.y);
	int dX2 = abs (xe.td.x - vc2.td.x);
	int dY2 = abs (xe.td.y - vc2.td.y);
	if ((dX < 6 && dY < 3) || (dX2 <6 && dY2 <3)){
	 	return 1;
	}
	return 0;
}


//in ten game va muc luc
void tengame(){
  	
	srand(time(NULL));
	TextColor( 1+rand() % 15 );

	gotoXY(20,0);
	printf("@@@@@     @    @   @  @@@@@       @@@@   @   @    @        @   @  @@@@@");
	gotoXY(20,1);
	printf("@   @    @ @   @@ @@  @           @   @  @   @   @ @        @ @   @");
	gotoXY(20,2);
	printf("@       @   @  @ @ @  @@@@@      @@@  @  @   @  @   @        @    @@@@@");
	gotoXY(20,3);
	printf("@  @@@  @@@@@  @   @  @           @   @  @   @  @@@@@       @ @   @");
	gotoXY(20,4);
	printf("@   @   @   @  @   @  @           @   @  @   @  @   @      @   @  @");
	gotoXY(20,5);
	printf("@@@@@   @   @  @   @  @@@@@       @@@@@  @@@@@  @   @     @     @ @@@@@");
	gotoXY(20,6);
	printf("-----------------------------------------------------------------------");
	printf("\n\n\t\t1. Bat Dau Choi ");
 	printf("\n\t\t2. Huong Dan Choi");
 	printf("\n\t\t3. Thoat\n"); 
}


 //ham menu	
 int menu(int a){
  do{
	printf("\n\t\Lua chon cua ban la:  ");
	scanf("%d",&a);
	
	switch(a) {
	  case 1:  
		return 1;
		break;
	    
	  case 2: 
	    printf ("\n\t\t\tA: Xe sang trai\n\t\t\tD: Xe sang phai\n\t\t\tW: Xe len tren\n\t\t\tS: Xe xuong duoi  ") ; 
	    printf ("\n\t\t\tLuu y: Dung de xe cham vat can.\n ") ;
	    break ;
	  case 3: 
		printf("Cam on va hen gap lai!!! "); 
		break;
		default: printf("Chon muc ban muon: "); break;
	}
  }while(a!=4);
}




	
	
int main(){
	tengame();
//khai bao cau truc
    int a;
    int vacham = 0;
    Xe xe;
	 vatcan vc;
	 vatcan vc2;
	 demoXe(xe);
	 demovc(vc,vc2);
//toc do game
	int tdgame=200;
	 
	 
	 
//tuy chon trong game
 int chon=menu(a);	    

	 if (chon==1){
	 	while(true){
		clrscr();
		inbiendoc();
	    hienthixe(xe);
		hienthivc(vc,vc2);
	 	indiem(xe);
	  int dk = dieukhien(xe);

     //game over
	  vacham=xuli(xe,vc,vc2,tdgame);
	  if ( vacham == 1 ){
	  	 
		gotoXY(roadWidth+11,13); 
	   	printf("---GAME OVER! BAM ESC  DE THOAT GAME---");
	   	while(getch() != 27 );
	   	break;
	   	
	   	
	  }
	
    Sleep(tdgame);
    } 
}
}


