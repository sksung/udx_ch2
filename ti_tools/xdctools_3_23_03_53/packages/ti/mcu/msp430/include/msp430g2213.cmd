/******************************************************************************/
/* msp430g2213.cmd                                                            */
/*    - Linker Command File for defintions in the header file                 */
/*    Please do not change !                                                  */
/*                                                                            */
/******************************************************************************/


/************************************************************
* STANDARD BITS
************************************************************/
/************************************************************
* STATUS REGISTER BITS
************************************************************/
/************************************************************
* PERIPHERAL FILE MAP
************************************************************/
/************************************************************
* SPECIAL FUNCTION REGISTER ADDRESSES + CONTROL BITS
************************************************************/
IE1                = 0x0000;
IFG1               = 0x0002;
IE2                = 0x0001;
IFG2               = 0x0003;
/************************************************************
* Basic Clock Module
************************************************************/
DCOCTL             = 0x0056;
BCSCTL1            = 0x0057;
BCSCTL2            = 0x0058;
BCSCTL3            = 0x0053;
/************************************************************
* Comparator A
************************************************************/
CACTL1             = 0x0059;
CACTL2             = 0x005A;
CAPD               = 0x005B;
/*************************************************************
* Flash Memory
*************************************************************/
FCTL1              = 0x0128;
FCTL2              = 0x012A;
FCTL3              = 0x012C;
/************************************************************
* DIGITAL I/O Port1/2 Pull up / Pull down Resistors
************************************************************/
P1IN               = 0x0020;
P1OUT              = 0x0021;
P1DIR              = 0x0022;
P1IFG              = 0x0023;
P1IES              = 0x0024;
P1IE               = 0x0025;
P1SEL              = 0x0026;
P1SEL2             = 0x0041;
P1REN              = 0x0027;
P2IN               = 0x0028;
P2OUT              = 0x0029;
P2DIR              = 0x002A;
P2IFG              = 0x002B;
P2IES              = 0x002C;
P2IE               = 0x002D;
P2SEL              = 0x002E;
P2SEL2             = 0x0042;
P2REN              = 0x002F;
/************************************************************
* DIGITAL I/O Port3 Pull up / Pull down Resistors
************************************************************/
P3IN               = 0x0018;
P3OUT              = 0x0019;
P3DIR              = 0x001A;
P3SEL              = 0x001B;
P3SEL2             = 0x0043;
P3REN              = 0x0010;
/************************************************************
* Timer0_A3
************************************************************/
TA0IV              = 0x012E;
TA0CTL             = 0x0160;
TA0CCTL0           = 0x0162;
TA0CCTL1           = 0x0164;
TA0CCTL2           = 0x0166;
TA0R               = 0x0170;
TA0CCR0            = 0x0172;
TA0CCR1            = 0x0174;
TA0CCR2            = 0x0176;
/************************************************************
* Timer1_A3
************************************************************/
TA1IV              = 0x011E;
TA1CTL             = 0x0180;
TA1CCTL0           = 0x0182;
TA1CCTL1           = 0x0184;
TA1CCTL2           = 0x0186;
TA1R               = 0x0190;
TA1CCR0            = 0x0192;
TA1CCR1            = 0x0194;
TA1CCR2            = 0x0196;
/************************************************************
* USCI
************************************************************/
UCA0CTL0           = 0x0060;
UCA0CTL1           = 0x0061;
UCA0BR0            = 0x0062;
UCA0BR1            = 0x0063;
UCA0MCTL           = 0x0064;
UCA0STAT           = 0x0065;
UCA0RXBUF          = 0x0066;
UCA0TXBUF          = 0x0067;
UCA0ABCTL          = 0x005D;
UCA0IRTCTL         = 0x005E;
UCA0IRRCTL         = 0x005F;
UCB0CTL0           = 0x0068;
UCB0CTL1           = 0x0069;
UCB0BR0            = 0x006A;
UCB0BR1            = 0x006B;
UCB0I2CIE          = 0x006C;
UCB0STAT           = 0x006D;
UCB0RXBUF          = 0x006E;
UCB0TXBUF          = 0x006F;
UCB0I2COA          = 0x0118;
UCB0I2CSA          = 0x011A;
/************************************************************
* WATCHDOG TIMER
************************************************************/
WDTCTL             = 0x0120;
/************************************************************
* Calibration Data in Info Mem
************************************************************/
CALDCO_16MHZ       = 0x10F8;
CALBC1_16MHZ       = 0x10F9;
CALDCO_12MHZ       = 0x10FA;
CALBC1_12MHZ       = 0x10FB;
CALDCO_8MHZ        = 0x10FC;
CALBC1_8MHZ        = 0x10FD;
CALDCO_1MHZ        = 0x10FE;
CALBC1_1MHZ        = 0x10FF;
/************************************************************
* Interrupt Vectors (offset from 0xFFE0)
************************************************************/
/************************************************************
* End of Modules
************************************************************/
