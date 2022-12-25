#include "chess.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Definicia globalnej sachovnice
int chessboard[L][L];

// Funkcia na vykreslenie sachovnice (pracuje s globalnou sachovnicou)
void print_chessboard(){
	int i=0,j=0;
	printf("\n%15s%s\n","","Cierny hrac");
	while (i<L){
		printf("\n");
		printf("	%d ",i+1);
		while (j<L){
			if (chessboard[i][j] == 1 ){
				printf("[P]");
			}
			else if (chessboard[i][j] == 2){
				printf("[V]");
			}
			else if (chessboard[i][j] == 3){
				printf("[J]");
			}
			else if (chessboard[i][j] == 4){
				printf("[S]");
			}
			else if (chessboard[i][j] == 5){
				printf("[D]");
			}
			else if (chessboard[i][j] == 6){
				printf("[K]");
			}
			else if (chessboard[i][j] == -1){
				printf("[p]");
			}
			else if (chessboard[i][j] == -2){
				printf("[v]");
			}
			else if (chessboard[i][j] == -3){
				printf("[j]");
			}
			else if (chessboard[i][j] == -4){
				printf("[s]");
			}
			else if (chessboard[i][j] == -5){
				printf("[d]");
			}
			else if (chessboard[i][j] == -6){
				printf("[k]");
			}
			else{
				printf("[0]");
			}
		
			j++;
		}
		i++;
		j=0;
	}
	printf("\n\n   	   a  b  c  d  e  f  g  h \n\n");
	printf("%15s%s","","Biely hrac"); 
   // TODO: dokoncit funkciu na zobrazovanie aktualneho stavu sachovnice v konzole
}

// Funkcia na pociatocne rozostavenie figurok na sachovnici
void init_chessboard()//chessboard[L][L]
{
	int i=0;  //PESIACI
	while (i<L)
	{
		chessboard[1][i]=-1;
		chessboard[L-2][i]=1;
		i++;
	}
	chessboard[0][0]=-2;		   //VEZE
	chessboard[0][L-1]=-2;
	chessboard[L-1][0]=2;
	chessboard[L-1][L-1]=2;
								   //JAZDCI
	chessboard[0][1]=-3;
	chessboard[0][L-2]=-3;
	chessboard[L-1][1]=3;
	chessboard[L-1][L-2]=3;
									//STRELCI
	chessboard[0][2]=-4;
	chessboard[0][L-3]=-4;
	chessboard[L-1][2]=4;
	chessboard[L-1][L-3]=4;
									//DAMA
	chessboard[0][3]=-5;
	chessboard[L-1][3]=5;
									//KRAL
	chessboard[0][4]=-6;
	chessboard[L-1][4]=6;
	
	
    // TODO: dokoncit funkciu na pociatocne rozostavenie figurok na sachovnici
}
int test(int xpred, int ypred, int xpo, int ypo, int p_id)
{
	int typ_panaka,typ_panaka2;
	typ_panaka=chessboard[xpred][ypred];
	typ_panaka2=chessboard[xpo][ypo];
	int id_pred;
	int id_po;
	if (typ_panaka==0)
	{
		return 0;
	}
	if (typ_panaka>0)//zistenie id panakov
	{
		id_pred=0;
	}
	else if(typ_panaka<0){
		id_pred=1;
	}
	else{
		id_pred=2;
	}
	if (typ_panaka2>0)//
	{
		id_po=0;
	}
	else if(typ_panaka2<0){
		id_po=1;
	}
	else{
		id_po=3;
	}
	if (p_id!=id_pred || id_pred==id_po) //ak sa hrac co je na tahu nerovna prvemu vybranemu panakovy id return 0 /ak sa id pred == id novych suradnic tak return 0;
	{
		return 0;
	}
	if (xpred==xpo && ypred==ypo)
	{
		return 0;
	}
	if (xpred>L-1 || ypred>L-1 || xpred<0 || ypred<0 || xpo>L-1 || ypo>L-1 || xpo<0 || ypo<0)
	{
		return 0;
	}
	//
	if (typ_panaka==1)
	{
		if (xpo==xpred-2 && ypred==ypo && xpred==L-2)
		{
			return 1;
		}
		if (xpo==xpred-1 && ypred==ypo && (chessboard[xpo][ypo]==0))
		{
			return 1;
		}
		else if (xpo==xpred-1 && (ypo==ypred+1 || ypo==ypred-1) && id_po==1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (typ_panaka==-1)
	{
		if (xpo==xpred+2 && ypred==ypo && xpred==1)
		{
			return 1;
		}
		if (ypo==ypred && xpred+1==xpo&& (chessboard[xpo][ypo]==0))
		{
			return 1;
		}
		else if (xpred+1==xpo && (ypo==ypred+1 || ypo==ypred-1) && id_po==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}	
	}
	if (typ_panaka==2 || typ_panaka==-2)
	{
		if (xpred==xpo)
		{
			if (ypo>ypred)
			{
				int i;
				i=ypred+1;
				while (i!=ypo)
				{
					chessboard[xpred][i];
					if (chessboard[xpred][i]!=0)
					{
						return 0;
					}
					i++;
				}
				return 1;
			}
			else//
			{
				int i;
				i=ypred-1;
				while (i!=ypo)
				{
					chessboard[xpred][i];
					if (chessboard[xpred][i]!=0)
					{
						return 0;
					}
					i--;
				}
				return 1;
				
			}
		}
		else if(ypred==ypo)
		{
			if (xpo>xpred)
			{
				int i;
				i=xpred+1;
				while (i!=xpo)
				{
					chessboard[i][ypred];
					if (chessboard[i][ypred]!=0)
					{
						return 0;
					}
					i++;
				}
				return 1;
			}
			else
			{
				int i;
				i=xpred-1;
				while (i!=xpo)
				{
					chessboard[i][ypred];
					if (chessboard[i][ypred]!=0)
					{
						return 0;
					}
					i--;
				}
				return 1;
			}
		}
	}
	if (typ_panaka==3 || typ_panaka==-3)
	{
		if ((ypred-2==ypo && xpred-1==xpred)||(ypred-2==ypo && xpred+1==xpo)||(ypred+2==ypo && xpred-1==xpo)||(ypred+2==ypo && xpred+1==xpo)||(ypred+1==ypo && xpred+2==xpo)||(ypred+1==ypo && xpred-2==xpo)||(ypred-1==ypo && xpred+2==xpo)||(ypred-1==ypo && xpred-2==xpo)){
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (typ_panaka==4 || typ_panaka==-4)
	{
		if(ypred!=ypo && xpred!=xpo)
		{
			if (xpred>xpo && ypred>ypo) //1
			{
				xpred--;
				ypred--;
				while(xpred>xpo && ypred>ypo)
				{
					if(chessboard[xpred][ypred]!=0)
					{
						return 0;
					}
					xpred--;
					ypred--; 		
				}
				if(xpred!=xpo || ypred!= ypo)
				{
					return 0;
				}
				return 1;
			}
			if(xpred<xpo && ypred>ypo) //2
			{
				xpred++;
				ypred--;
				while(xpred>xpo && ypred>ypo)
				{
					if(chessboard[xpred][ypred]!=0)
					{
						return 0;
					}
					xpred++;
					ypred--; 		
				}
				if(xpred!=xpo || ypred!= ypo)
				{
					return 0;
				}
				return 1;
			}	
			if(xpred>xpo && ypred<ypo) //3
			{
				xpred--;
				ypred++;								
				while(xpred>xpo && ypred<ypo)
				{
					if(chessboard[xpred][ypred]!=0)
					{
						return 0;
					}
					xpred--;
					ypred++; 		
				}
				if(xpred!=xpo || ypred!= ypo)
				{
					return 0;
				}

				return 1;
			}
			if(xpred<xpo && ypred<ypo) //4
			{
				xpred++;
				ypred++;
				while(xpred>xpo && ypred>ypo)
				{
					if(chessboard[xpred][ypred]!=0)
					{
						return 0;
					}
					xpred++;
					ypred++; 		
				}
				if(xpred!=xpo || ypred!= ypo)
				{
					return 0;
				}
				return 1;
			}
		}
	}
	if (typ_panaka==5 || typ_panaka==-5) //funguje bez chyby?
	{
		if (xpred==xpo)
		{
			if (ypo>ypred)
			{
				int i;
				i=ypred+1;
				while (i!=ypo)
				{
					chessboard[xpred][i];
					if (chessboard[xpred][i]!=0)
					{
						return 0;
					}
					i++;
				}
				return 1;
			}
			else//
			{
				int i;
				i=ypred-1;
				while (i!=ypo)
				{
					chessboard[xpred][i];
					if (chessboard[xpred][i]!=0)
					{
						return 0;
					}
					i--;
				}
				return 1;
				
			}
		}
		else if(ypred==ypo)
		{
			if (xpo>xpred)
			{
				int i;
				i=xpred+1;
				while (i!=xpo)
				{
					chessboard[i][ypred];
					if (chessboard[i][ypred]!=0)
					{
						return 0;
					}
					i++;
				}
				return 1;
			}
			else
			{
				int i;
				i=xpred-1;
				while (i!=xpo)
				{
					chessboard[i][ypred];
					if (chessboard[i][ypred]!=0)
					{
						return 0;
					}
					i--;
				}
				return 1;
			}
		}
		else if(ypred!=ypo && xpred!=xpo)
		{
			if (xpred>xpo && ypred>ypo) //1
			{
				xpred--;
				ypred--;
				while(xpred>xpo && ypred>ypo)
				{
					if(chessboard[xpred][ypred]!=0)
					{
						return 0;
					}
					xpred--;
					ypred--; 		
				}
				if(xpred!=xpo || ypred!= ypo)
				{
					return 0;
				}
				return 1;
			}
			if(xpred<xpo && ypred>ypo) //2
			{
				xpred++;
				ypred--;
				while(xpred<xpo && ypred>ypo)
				{
					if(chessboard[xpred][ypred]!=0)
					{
						return 0;
					}
					xpred++;
					ypred--; 		
				}
				if(xpred!=xpo || ypred!= ypo)
				{
					return 0;
				}
				return 1;
			}	
			if(xpred>xpo && ypred<ypo) //3
			{
				xpred--;
				ypred++;
				while(xpred>xpo && ypred<ypo)
				{
					if(chessboard[xpred][ypred]!=0)
					{
						return 0;
					}
					xpred--;
					ypred++; 		
				}
				if(xpred!=xpo || ypred!= ypo)
				{
					return 0;
				}
				return 1;
			}
			if(xpred<xpo && ypred<ypo) //4
			{
				xpred++;
				ypred++;
				while(xpred>xpo && ypred>ypo)
				{
					if(chessboard[xpred][ypred]!=0)
					{
						return 0;
					}
					xpred++;
					ypred++; 		
				}
				if(xpred!=xpo || ypred!= ypo)
				{
					return 0;
				}
				return 1;
			}
		}
	}
	if (typ_panaka==6 || typ_panaka == -6)
	{
		if(ypred==ypo & ((xpred+1==xpo)||(xpred-1==xpo)))
		{
			return 1;
		}
		else if(xpred==xpo &((ypred+1==ypo)||(ypred-1==ypo)))
		{
			return 1;
		}
		else if((xpred-1==xpo && ypred-1==ypo)||(xpred+1==xpo && ypred+1==ypo)||(xpred+1==xpo && ypred-1==ypo)||(xpred-1==xpo && ypred+1==ypo))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
// Funkcia, ktora overi tah figurkou [srow,scol]-->[trow,tcol] a v pripade,
// ze je platny, tak ho aj zrealizuje.
//
// VSTUP:
//      srow - riadok povodneho policka
//      scol - stlpec povodneho policka
//      trow - riadok noveho policka
//      tcol - stlpec noveho policka
//      p_id - ID hraca (pozri chess.h)
//
// VYSTUP:
//      V pripade platneho/zrealizovaneho tahu funkcia vrati 1.
//      V pripade, ze bol tah neplatny funkcia vrati 0.
int pismeno_na_cislo(int y)
{
	if (y=='a'){
		return 0;
	}
	else if (y=='b'){
		return 1;
	}
	else if (y=='c'){
		return 2;
	}
	else if(y=='d'){
		return 3;
	}
	else if(y=='e'){
		return 4;
	}
	else if(y=='f'){
		return 5;
	}
	else if(y=='g'){
		return 6;
	}
	else if(y=='h'){
		return 7;
	}
	else{
		return 9999;
	}
}
int tah(int id)
{
	if(id==0)
	{
		printf("\n\nNa rade je Biely hrac");
	}
	else{
		printf("\n\nNa rade je Cierny hrac");
	}
	int pes;
	pes=0;
	int x,x2;
	char y,y2;
	while (pes!=1){
		printf("\n\nFORMAT: CISLO,PISMENO,CISLO2,PISMENO2\n");
		printf("\nZADAJ POHYB:\n");
		scanf("%d%c",&x,&y);
		x=x-1;
		y=pismeno_na_cislo(y);
		scanf("%d%c",&x2,&y2);
		x2=x2-1;
		y2=pismeno_na_cislo(y2);
		pes=test( x, y,  x2,  y2, id);
		printf("\nPODMIENKA SPLNENA?:%d",pes);
		if (pes!=1)
		{
			CLEAR_SCREEN();
			print_chessboard();
			printf("\n\nNeplatny tah!!!!!!!!!!!!!!!!!!!\nNEPLATNY TAH!!!!!!!!!!!!!!!!!!!!!!");
			if(id==0)
			{
				printf("\n\nNa rade je Biely hrac");
			}
			else{
				printf("\n\nNa rade je Cierny hrac");
			}			
		}
	}
	move(x,y,x2,y2,id,pes);
	return pes;
}
int koniec_hry()
{
	int i=0,n=0,biely=0,cierny=0;
	while(i<L)
	{
		n=0;
		while (n<L)
		{
			if (chessboard[i][n]==-6)
			{
				cierny=1;
			}
			else if (chessboard[i][n]==6)
			{
				biely=1;
			}
			n++;
		}
		i++;
	}
	if (biely==1 && cierny==1)
	{
		return 1;
	}
	else if(biely==0 && cierny ==1)
	{
		printf("\n\nCierny vyhral");
		printf("\nJe to kader");
		return 0;
	}
	else if(cierny==0 && biely==1)
	{
		printf("\n\nBiely vyhral");
		printf("\n\nJe to kader");
		return 0;
	}
}
int move(int xpred, int ypred, int xpo, int ypo, int p_id, int podm)//int srow, int scol, int trow, int tcol, int p_id
{
	if (podm==1)
	{
		int typ;
		typ=chessboard[xpred][ypred];
		chessboard[xpo][ypo]=typ;
		chessboard[xpred][ypred]=0;
	}
    // TODO: dokoncit funkciu na overenie a realizaciu tahu figurkou
    // Rady:
    //  1. Najprv skontrolujte vsetky dolezite podmienky pre platnost tahu:
    //       * su suradnice policok mimo sachovnice?
    //       * nachadza sa policku [srow,scol] figurka?
    //       * patri naozaj vybrana figurka na policku [srow,scol] hracovi p_id?
    //       * plati, ze [srow,scol] != [trow,tcol]?
    //       * je policko [srow,scol] platnym tahom figurky daneho typu?
    //       * ine ...
    //
    //  2. V pripade, ze su podmienky platnosti tahu splnene, zrealizujte tah, t.j.
    //     posunte figurku z policka [srow,scol] na [trow,tcol].
    //
    //  Pozn. 1 nezabudajte, ze figurka moze brat ine figurky protihraca.
    //  Pozn. 2 neimplementujte celu logiku v tejto funkcii, ale volajte z nej
    //        dalsie pomocne funkcie.

    return 0; // tento riadok je tu len kvoli kompilacii
}
