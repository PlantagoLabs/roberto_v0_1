#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay_basic.h>
#include "robopoly.h"
#include <util/setbaud.h>
#include "lcd.h"

#include "robopoly.h"

int main(void)
{
	
	lcd_init(LCD_DISP_ON);
	lcd_clrscr();
	lcd_puts("Je suis");
	lcd_gotoxy(0,1);
	lcd_puts("Roberto");

	int i, pos_servo, flag_error = 0;
	
	DDRC = 0xFF;
	DDRD = 0xFF;
	DDRA = 0x80;
	PORTD = 0b01100011;
	PORTC = 0b00000000;
	set_servo(0, 20);		// moteur du bras portant le verre
	set_servo(1, 80);		// moteur du bras tenant le tuyau
	set_servo(2, 50);		// moteur du neud papillon
	set_servo(3, 50);		// moteur de l'oreille gauche
	set_servo(4, 50);		// moteur de l'oreille droite
	while(1)
	{	
		/*
		
		if(_PINA0 == 1 )
		{
			if(_PINA1 == 0)
			{
				_PORTA7 = 1;				
			}
			else _PORTA7 = 0;
		}
		else _PORTA7 = 0;	
		*/

		/*
		_PORTA7 = 1;
		waitms(3000);
		_PORTA7 = 0;
		waitms(5000);

		*/
		/*
		if(_PINA5 == 1 )
		{
			set_servo(3, 20);
		}
		else set_servo(3, 50);
		*/


		if(_PINA0 == 1) 	// Un verre a été déposé
		{

sortie: 	PORTD = 0b11000110;

			lcd_gotoxy(0,0);
			lcd_clrscr();
			lcd_puts("Payez le gentil");
			lcd_gotoxy(0,1);
			lcd_puts("serveur SVP");

			while(_PINA5 == 0); 	// Attends que le bouton annexe pour confirmer le paiement soit activé

			PORTD = 0b00100001;
			
			lcd_gotoxy(0,0);
			lcd_clrscr();
			lcd_puts("Et un Ricard");
			for(i=0; i < 69; i++)		// apporte le verre devant Roberto
			{
				set_servo(0, 20 + i);

				waitms(20);
			}

			i = 0;

			while(_PINA2 == 0)		// contact du bras droit sur le porte-gobelet
			{

				set_servo(1, 80 - i);	// apporte le tuyau au-dessus du verre

				waitms(20);

				i++;

			}
			pos_servo = i;			// enregistre la position du bras droit (inutilisé)

			while(_PINA0 == 1 && _PINA2 == 1 && _PINA1 == 0) 
			_PORTA7 = 1;			// Active la pompe jusqu'à ce que le liquide arrive à la sortie du tuyau

			if(_PINA2 == 1 && _PINA0 == 1)	// Verse le liquide tant que le verre et le tuyau sont en place
			{
			
				set_servo(2, 30);	// Oscille le noeud papillon pendant qu'il remplit le verre
				waitms(400);
				set_servo(2, 70);
				waitms(400);
				set_servo(2, 30);
				waitms(400);
				set_servo(2, 70);
				waitms(400);
				set_servo(2, 30);
				waitms(400);
				set_servo(2, 70);
				waitms(400);
				set_servo(2, 30);
				waitms(400);
				set_servo(2, 70);
				waitms(400);
				set_servo(2, 30);
				waitms(400);
				set_servo(2, 70);
				waitms(400);
				set_servo(2, 50);

				flag_error = 0;
			}
			else 		// si le verre est retiré avant la fin ou le tuyau n'est plus en place
			{
				PORTD = 0b10000100;

				lcd_gotoxy(0,0);
				lcd_clrscr();
				lcd_puts("Nous avons");
				lcd_gotoxy(0,1);
				lcd_puts("un probleme.");

				flag_error = 1;		// arrête de remplir le verre

			}
			

			_PORTA7 = 0;

			waitms(5000);

			
			for(i=0; i < 70; i++)		//remet le bras droit à sa position initiale
			{
				set_servo(1, 10 + i);

				waitms(30);
			}

			if(flag_error == 0)		// confirme que le verre est rempli et près à être pris
			{
				lcd_gotoxy(0,0);
				lcd_clrscr();
				lcd_puts("Et voila.");

				PORTD = 0b01000010;
			}

			while(	_PINA0 == 1)		// Oscille le noeud papillon en attendant que le verre soit pris
			{
				set_servo(4, 10);
				set_servo(3, 90);

				waitms(200);

				set_servo(4, 50);
				set_servo(3, 50);

				waitms(200);

				set_servo(4, 10);
				set_servo(3, 90);

				waitms(200);

				set_servo(4, 50);
				set_servo(3, 50);

				waitms(2000);


			}

			for(i=0; i < 70; i++)		// Replace le bras gauche à sa position initiale
			{
				set_servo(0, 85 - i);

				waitms(30);
			}

			

			if(flag_error == 0)		// confirme que le verre a été pris
			{
				lcd_clrscr();
				lcd_gotoxy(0,0);
				lcd_puts("A votre sante.");
			}
			
			waitms(2000);		


			
		}
		else 					// boucle d'attente tant qu'aucun verre n'est posé
		{
			PORTD = 0b01100011;

			//set_servo(0, 20);

			//set_servo(1, 80);

			lcd_gotoxy(0,0);
			lcd_clrscr();
			lcd_puts("Je suis");
			lcd_gotoxy(0,1);
			lcd_puts("Roberto");

			for(i=0; i< 100;i++)		// verifie qu'aucun verre n'est posé
			{
				waitms(20);
				if(_PINA0 == 1) goto sortie;
			}

			lcd_gotoxy(0,0);
			lcd_clrscr();
			lcd_puts("Le robot");
			lcd_gotoxy(0,1);
			lcd_puts("serveur");

			
			for(i=0; i< 100;i++)		// verifie qu'aucun verre n'est posé
			{
				waitms(20);
				if(_PINA0 == 1) goto sortie;
			}

			lcd_gotoxy(0,0);
			lcd_clrscr();
			lcd_puts("Je fais parti");
			lcd_gotoxy(0,1);
			lcd_puts("de Robopoly");

			set_servo(4, 10);
			set_servo(3, 90);

			waitms(200);

			set_servo(4, 50);
			set_servo(3, 50);

			
			for(i=0; i< 100;i++)		// verifie qu'aucun verre n'est posé
			{
				waitms(20);
				if(_PINA0 == 1) goto sortie;
			}

			lcd_gotoxy(0,0);
			lcd_clrscr();
			lcd_puts("Un Ricard");
			lcd_gotoxy(0,1);
			lcd_puts("Un vrai.");

			
			for(i=0; i< 100;i++)		// verifie qu'aucun verre n'est posé
			{
				waitms(20);
				if(_PINA0 == 1) goto sortie;
			}
		}


/*
		if(_PINA2 == 0) 
		{
			waitms(200);
			
			set_servo(1, 80);

			
		}
		else 	
		{
			waitms(200);
			
			set_servo(1, 20);
		}

*/


	
		
		/*
		set_servo(0, 30);
		set_servo(1, 30);
		set_servo(2, 30);
		set_servo(3, 40);
		set_servo(4, 40);

		waitms(500);

		set_servo(0, 70);
		set_servo(1, 70);
		set_servo(2, 70);
		set_servo(3, 60);
		set_servo(4, 60);

		waitms(500);
		*/

/*
		for(i=0; i<20;i++)
		{
			for(j=0;j<10;j++)
			{
				PORTD = 0b00000100;	
				waitms(20-i+1);
				PORTD = 0b00000001;	
				waitms((i+1));
				PORTD = 0b00000000;	
				waitms(5);
			}
			
		
		}
		for(i=0; i<20;i++)
		{

			for(j=0;j<10;j++)
			{
				PORTD = 0b00000001;	
				waitms(20-i+1);
				PORTD = 0b00000010;	
				waitms((i+1));
				PORTD = 0b00000000;	
				waitms(5);
			}
		}
		for(i=0; i<20;i++)
		{

			for(j=0;j<10;j++)
			{
				PORTD = 0b00000010;	
				waitms(20-i+1);
				PORTD = 0b00000100;	
				waitms((i+1));
				PORTD = 0b00000000;	
				waitms(5);
			}
		}
		*/
	
	}

	return 0; 
}
