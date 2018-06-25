void it (void);
void it_int0();
void it_int1();
void it_tmr0();
// Initialisation du vecteur d’interruption
#pragma code adresse_it=0x08 //Place le code à l’adresse 0x08
void int_vect(void)
{
 _asm 
	goto it 
_endasm // Branchement au S/P d’it
}
#pragma code // retour à la section par défaut
//sous programme de traitement de l’interruption
#pragma interrupt it
void it (void)
{
/* placer le code de traitement de l'IT ici */
if (INTCON3bits.INT1IF) {
it_int1();
INTCON3bits.INT1IF=0; // efface drapreau d'ITx
}
if (INTCONbits.INT0IF) {
it_int0();
INTCONbits.INT0IF=0; // efface drapreau d'ITx
}
if (INTCONbits.TMR0IF) {
it_tmr0();
TMR0H = 0x3C;                    //clear timer
TMR0L = 0x95;    
INTCONbits.TMR0IF=0; // efface drapreau d'ITx
}
}

void init_it_int0()
{
INTCONbits.INT0IE = 1;
INTCONbits.GIEH = 1; 
}

void init_it_int1()
{
INTCON3bits.INT1IE = 1;
INTCONbits.GIEH = 1; 
}

void init_it_tmr0()
{
INTCON2bits.TMR0IP=1;
INTCONbits.TMR0IE = 1;
TMR0H = 0x3C;                    //clear timer
TMR0L = 0x95;                    //clear timer
T0CON = 0x80;  
INTCONbits.GIEH = 1; 
}
