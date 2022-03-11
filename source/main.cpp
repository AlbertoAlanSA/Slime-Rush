
#include <nds.h>
#include <stdio.h>
#include <iostream>
#include <utility>
#include <time.h>
#include <vector>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"
#include "portada.h"


using namespace std;

#define Sky      			0
#define BigCloudBL 		1
#define BigCloudBR		2
#define BigCloudTL		3
#define BigCloudTR 		4
#define SmallCloudL 	5
#define SmallCloudR 	6
#define SlimeTL0L			7
#define SlimeTR0L			8
#define SlimeBL0L			9
#define SlimeBR0L			10
#define Floor 				11
#define Floor2 				12
#define SlimeTL0R			13
#define SlimeTR0R			14
#define SlimeBL0R			15
#define SlimeBR0R			16
#define SlimeTL1L			17
#define SlimeTR1L			18
#define SlimeBL1L			19
#define SlimeBR1L			20
#define SlimeTL1R			21
#define SlimeTR1R			22
#define SlimeBL1R			23
#define SlimeBR1R			24
#define SlimeTL0I			25
#define SlimeTR0I			26
#define SlimeBL0I			27
#define SlimeBR0I			28
#define SlimeTL1I			29
#define SlimeTR1I			30
#define SlimeBL1I			31
#define SlimeBR1I			32
#define RedFly				33

#define BigBush1			34
#define BigBush2			35
#define BigBush3			36

#define Grass1				37
#define Grass2				38
#define Grass3				39
#define Grass4				40
#define Fence1				41
#define Fence2				42
#define Fence3				43
#define RedFly2				44
#define BlueFly 			45
#define BlueFly2			46
#define	Fence4				47

#define RedShield1		48
#define RedShield2		49
#define RedShield3		50
#define RedShield4		51
#define RedShield5		52
#define RedShield6		53
#define RedShield7		54
#define RedShield8		55
#define RedShield9		56
#define RedShield10		57
#define RedShield11		58
#define RedShield12		59


#define BlueShield1			60
#define BlueShield2			61
#define BlueShield3			62
#define BlueShield4			63
#define BlueShield5			64
#define BlueShield6			65
#define BlueShield7			66
#define BlueShield8			67
#define BlueShield9			68
#define BlueShield10		69
#define BlueShield11		70
#define BlueShield12		71

#define SlimeDead1			72
#define SlimeDead2			73

#define MoonTL					74
#define MoonTR					75
#define MoonBL					76
#define MoonBR					77

#define NightSky				78

#define SunTL						79
#define SunTR						80
#define SunBL						81
#define SunBR						82

#define Stars1					83
#define Stars2					84

#define	BigBush1N				85
#define BigBush2N				86
#define BigBush3N				87


u8 sky[64] =  
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};
u8 bigCloudBL[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	1,2,2,2,2,2,2,2,
	1,1,1,1,1,2,2,2,
	0,1,1,1,1,2,2,2,
	0,1,1,1,1,1,1,2,
	0,0,0,1,1,1,1,1,
	0,0,0,0,0,0,1,1,
};
u8 bigCloudBR[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,2,2,1,1,1,1,
	2,2,1,1,1,1,1,1,
	2,1,1,1,1,0,0,0,
	1,1,1,1,0,0,0,0,
	1,1,1,1,0,0,0,0,
	1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};
u8 bigCloudTL[64] =
{
	0,0,0,2,2,2,2,3,
	0,0,0,2,2,2,3,3,
	0,0,0,2,2,2,3,3,
	0,0,2,2,2,2,2,2,
	0,0,2,2,2,2,2,2,
	0,0,2,2,2,2,2,2,
	0,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};

u8 bigCloudTR[64] =
{
	3,3,3,0,0,0,0,0,
	3,3,3,3,0,0,0,0,
	3,3,3,3,0,0,0,0,
	3,3,3,2,2,2,0,0,
	2,2,2,2,2,2,0,0,
	2,2,2,2,2,2,2,0,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};
u8 smallCloudL[64] =
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,2,
	0,0,1,1,2,2,2,2,
	0,0,1,1,2,2,2,2,
	0,0,0,0,1,1,1,1,
	0,0,0,0,0,0,1,1,
	0,0,0,0,0,0,0,0,
};
u8 smallCloudR[64] =
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	2,2,3,3,0,0,0,0,
	2,3,3,3,2,2,0,0,
	2,2,1,1,1,1,1,0,
	1,1,1,1,0,0,0,0,
	1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};
u8 slimeTL0L[64] = //-
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,6,6,6,
	0,0,0,6,6,6,6,6,
	0,0,6,6,6,6,6,6,
	0,6,6,7,7,6,6,6,
	0,6,6,6,6,6,6,6,
	0,6,6,6,7,6,7,6,

};
u8 slimeTR0L[64] =//-
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	6,6,0,0,0,0,0,0,
	6,6,6,6,5,0,0,0,
	6,6,6,6,5,5,0,0,
	6,7,7,7,6,5,0,0,
	6,6,6,6,6,5,5,0,
	7,6,6,6,6,5,4,0,
};
u8 slimeBL0L[64] =//-
{
	0,6,6,6,6,7,6,7,
	0,6,6,6,6,6,6,6,
	0,6,6,6,6,6,6,6,
	0,6,6,6,6,6,6,6,
	0,0,6,6,6,6,5,5,
	0,0,6,5,5,5,5,4,
	0,0,0,5,5,4,4,4,
	0,0,0,0,0,0,0,0,
};
u8 slimeBR0L[64] =//-
{
	6,6,6,5,5,5,4,0,
	6,6,6,5,5,5,4,4,
	6,6,5,5,5,5,4,4,
	5,5,5,5,5,5,4,4,
	5,5,5,5,5,4,4,0,
	4,4,4,4,4,4,4,0,
	4,4,4,4,4,0,0,0,
	0,0,0,0,0,0,0,0,
};

u8 floor[64]=
{
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,
};
u8 floor2[64]=
{
	9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,
};


u8 slimeTL0R[64] =
{
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,6,6,
	13,13,13,5,6,6,6,6,
	13,13,5,5,6,6,6,6,
	13,13,5,6,7,7,7,6,
	13,5,5,6,6,6,6,6,
	13,4,5,6,6,6,6,7,
};
u8 slimeTR0R[64] =
{
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	6,6,6,13,13,13,13,13,
	6,6,6,6,6,13,13,13,
	6,6,6,6,6,6,13,13,
	6,6,6,7,7,6,6,13,
	6,6,6,6,6,6,6,13,
	6,7,6,7,6,6,6,13,


};

u8 slimeBL0R[64] =
{
	13,4,5,5,5,6,6,6,
	4,4,5,5,5,6,6,6,
	4,4,5,5,5,5,6,6,
	4,4,5,5,5,5,5,5,
	13,4,4,5,5,5,5,5,
	13,4,4,4,4,4,4,4,
	13,13,13,4,4,4,4,4,
	13,13,13,13,13,13,13,13,
};
u8 slimeBR0R[64] =
{
	7,6,7,6,6,6,6,13,
	6,6,6,6,6,6,6,13,
	6,6,6,6,6,6,6,13,
	6,6,6,6,6,6,6,13,
	5,5,6,6,6,6,13,13,
	4,5,5,5,5,6,13,13,
	4,4,4,5,5,13,13,13,
	13,13,13,13,13,13,13,13,
};

u8 slimeTL1L[64] =//-
{
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,6,
	13,13,13,13,13,13,6,6,

};
u8 slimeTR1L[64] =//-
{
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,6,6,6,13,13,13,
	6,6,6,6,6,6,6,13,
	7,6,6,6,6,6,5,5,
};
u8 slimeBL1L[64] =//-
{
	13,13,13,13,6,6,6,6,
	13,13,13,6,6,6,6,6,
	13,13,6,6,7,6,6,6,
	13,6,6,7,6,7,6,6,
	13,6,6,7,7,6,5,5,
	13,13,6,5,5,5,5,4,
	13,13,13,5,5,4,4,4,
	13,13,13,13,13,13,13,13,
};
u8 slimeBR1L[64] =//-
{
	6,7,6,6,6,6,5,5,
	6,6,6,7,6,6,5,4,
	6,6,6,6,7,6,5,4,
	6,6,6,6,5,5,4,4,
	5,5,5,5,5,4,4,4,
	4,5,5,4,4,4,4,4,
	4,4,4,4,4,4,4,13,
	13,13,13,13,13,13,13,13,
};

u8 slimeTL1R[64] =
{
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,6,6,6,13,13,
	13,6,6,6,6,6,6,6,
	5,5,6,6,6,6,6,7,
};
u8 slimeTR1R[64] =
{
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	6,13,13,13,13,13,13,13,
	6,6,13,13,13,13,13,13,

};

u8 slimeBL1R[64] =
{
	5,5,6,6,6,6,7,6,
	4,5,6,6,7,6,6,6,
	4,5,6,7,6,6,6,6,
	4,4,5,5,6,6,6,6,
	4,4,4,5,5,5,5,5,
	4,4,4,4,4,5,5,4,
	13,4,4,4,4,4,4,4,
	13,13,13,13,13,13,13,13,
};
u8 slimeBR1R[64] =
{
	6,6,6,6,13,13,13,13,
	6,6,6,6,6,13,13,13,
	6,6,6,7,6,6,13,13,
	6,6,7,6,7,6,6,13,
	5,5,6,7,7,6,6,13,
	4,5,5,5,5,6,13,13,
	4,4,4,5,5,13,13,13,
	13,13,13,13,13,13,13,13,
};

u8 slimeTL0I[64] =  //-
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,6,6,6,
	0,0,0,6,6,6,6,6,
	0,0,6,6,6,6,6,6,
	0,6,6,6,7,7,6,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,7,6,7,
};
u8 slimeTR0I[64] =  //-
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	6,6,0,0,0,0,0,0,
	6,6,6,6,6,0,0,0,
	6,6,6,6,6,6,0,0,
	6,6,7,7,6,6,0,0,
	6,6,6,6,6,6,5,0,
	6,7,6,6,6,5,4,0,
};
u8 slimeBL0I[64] = //- 
{
	6,6,6,6,6,6,7,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,6,6,
	0,6,6,6,6,6,5,5,
	0,0,6,5,5,5,5,4,
	0,0,0,5,5,4,4,4,
	0,0,0,0,0,0,0,0,
};
u8 slimeBR0I[64] =  //-
{
	7,6,6,6,6,5,4,0,
	6,6,6,6,5,5,4,4,
	6,6,6,6,5,5,4,4,
	5,5,6,5,5,5,4,4,
	5,5,5,5,5,4,4,0,
	4,4,4,4,4,4,4,0,
	4,4,4,4,4,0,0,0,
	0,0,0,0,0,0,0,0,
};

u8 slimeTL1I[64] =  //-//-
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,6,6,6,
	0,0,0,6,6,6,6,6,
	0,0,6,6,6,6,6,6,
	0,6,6,6,7,7,6,6,
};
u8 slimeTR1I[64] =  //-
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	6,6,0,0,0,0,0,0,
	6,6,6,6,6,0,0,0,
	6,6,6,6,6,6,0,0,
	6,6,7,7,6,6,0,0,
};
u8 slimeBL1I[64] =  //-
{
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,7,6,7,
	6,6,6,6,6,6,7,6,
	6,6,6,6,6,6,6,6,
	6,6,6,6,6,6,5,5,
	6,6,5,5,5,5,5,4,
	0,5,5,5,5,4,4,4,
	0,0,0,0,0,0,0,0,
};
u8 slimeBR1I[64] =  //-
{
	6,6,6,6,6,5,4,0,
	6,7,6,6,5,5,4,4,
	7,6,6,6,5,5,4,4,
	6,6,6,5,5,5,4,4,
	5,5,5,5,5,4,4,4,
	4,4,4,4,4,4,4,4,
	4,4,4,4,4,4,4,0,
	0,0,0,0,0,0,0,0,
};

u8 redFly[64] =  
{
	13,13,13,13,13,13,13,13,
	10,18,13,13,13,13,10,18,
	10,18,13,13,13,13,10,18,
	10,10,18,13,13,10,18,18,
	13,10,10,13,13,10,10,13,
	13,13,13, 8, 9,13,13,13,
	13,13,13, 8, 8,13,13,13,
	13,13,13,13,13,13,13,13,
};

u8 bigBush1[64]={
	0,0,0,0,0,0,12,13,
	0,0,0,0,12,12,13,13,
	0,0,0,11,12,12,13,13,
	0,0,11,11,12,13,13,13,
	0,11,11,11,12,13,13,13,
	11,11,11,11,12,12,13,13,
	11,11,11,11,12,12,12,12,
	11,11,11,11,11,11,12,12,
};

u8 bigBush2[64]={
	14,14,0,0,0,0,0,0,
	13,13,13,14,14,0,0,0,
	14,13,13,14,14,0,0,0,
	13,13,13,13,13,0,0,0,
	13,13,14,13,13,13,14,0,
	12,13,13,13,13,12,13,11,
	12,12,12,12,12,11,11,11,
	12,12,11,11,11,11,11,11,
};

u8 bigBush3[64]={
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,13,14,14,14,0,0,
	0,11,13,13,13,13,13,0,
	11,11,12,13,13,13,13,13,
	11,11,12,12,13,13,13,13,
	11,11,11,12,12,12,12,12,
};

u8 grass1[64]={
	13,13,13,14,13,13,13,13,
	13,13,13,13,14,14,14,14,
	13,11,11,13,13,14,14,14,
	13,11,12,13,13,13,13,14,
	11,11,12,13,13,13,13,14,
	11,11,12,12,12,12,11,13,
	13,13,11,11,11,11,13,13,
	13,13,13,13,13,13,13,13,
};

u8 grass2[64]={
	13,13,13,13,14,13,13,13,
	13,13,13,13,13,13,13,13,
	13,11,13,13,13,13,13,13,
	13,11,12,12,13,13,13,14,
	13,11,11,12,12,12,13,13,
	13,13,13,11,11,12,13,13,
	13,13,13,13,13,12,12,12,
	13,13,13,13,13,13,13,13,
};

u8 grass3[64]={
	13,13,14,13,13,13,13,13,
	13,13,13,14,13,13,13,13,
	14,14,14,14,13,13,13,13,
	13,12,12,12,11,13,13,13,
	13,12,12,12,11,11,13,13,
	12,12,11,11,11,13,13,13,
	12,12,12,11,13,13,13,13,
	13,13,13,13,13,13,13,13,
};

u8 grass4[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};

u8 fence1[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,17,17,17,17,13,13,
	13,13,16,16,17,17,13,13,
	13,13,16,16,17,16,13,13,
	13,13,16,16,16,16,13,13,
	13,13,15,17,17,15,13,13,
	13,13,15,16,17,15,13,13,
};

u8 fence2[64]={
	13,13,13,16,17,13,13,13,
	13,13,13,16,17,13,13,13,
	13,13,13,16,17,13,13,13,
	13,13,13,16,17,13,13,13,
	13,13,13,16,17,13,13,13,
	13,13,13,16,17,13,13,13,
	13,13,13,16,16,13,13,13,
	13,13,13,16,16,13,13,13,
};

u8 fence3[64]={
	13,13,13,16,16,13,13,13,
	13,13,13,16,16,13,13,13,
	13,13,17,17,17,17,13,13,
	13,13,16,17,17,17,13,13,
	13,13,16,16,16,17,13,13,
	13,13,16,16,16,16,13,13,
	13,13,15,15,15,15,13,13,
	13,13,15,15,15,15,13,13,
};
u8 redFly2[64] =  
{
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	18,18,13,13,13,13,18,18,
	10,18,18,13,13,18,18,18,   
	10,10,18, 8, 9,10,18,10,
	13,10,10, 8, 8,10,10,13,
	13,13,13,13,13,13,13,13,
};
u8 blueFly[64] =  
{
	13,13,13,13,13,13,13,13,
	19,20,13,13,13,13,19,20,
	19,20,13,13,13,13,19,20,
	19,19,20,13,13,19,20,20,
	13,19,19,13,13,19,19,13,
	13,13,13, 8, 9,13,13,13,
	13,13,13, 8, 8,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 blueFly2[64] =  
{
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	20,20,13,13,13,13,20,20,
	19,20,20,13,13,20,20,20,   
	19,19,20, 8, 9,19,20,19,
	13,19,19, 8, 8,19,19,13,
	13,13,13,13,13,13,13,13,
};


u8 fence4[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,17,17,17,17,13,13,
	13,13,16,16,17,17,13,13,
	13,13,16,16,17,16,13,13,
	13,13,16,16,16,16,13,13,
	13,13,15,15,15,15,13,13,
	13,13,15,15,15,15,13,13,
};
u8 redShield1[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,10,
	13,13,13,13,13,13,10,18,
	13,13,13,13,13,10,18,13,
	13,13,13,13,10,18,13,13,
};
u8 redShield2[64]={
	13,13,13,10,18,13,13,13,
	13,13,10,18,13,13,13,13,
	13,13,10,18,13,13,13,13,
	13,13,10,18,13,13,13,13,
	13,10,18,13,13,13,13,13,
	13,10,18,13,13,13,13,13,
	13,10,18,13,13,13,13,13,
	13,10,18,13,13,13,13,13,
};
u8 redShield3[64]={
	13,10,18,13,13,13,13,13,
	13,10,18,13,13,13,13,13,
	13,10,18,13,13,13,13,13,
	13,13,10,18,13,13,13,13,
	13,13,10,18,13,13,13,13,
	13,13,10,18,13,13,13,13,
	13,13,13,10,18,13,13,13,
	13,13,13,13,10,18,13,13,
};
u8 redShield4[64]={
	13,13,13,13,10,18,13,13,
	13,13,13,13,13,10,18,13,
	13,13,13,13,13,13,10,18,
	13,13,13,13,13,13,13,10,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 redShield5[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	18,13,13,13,13,13,13,13,
	10,18,18,18,13,13,13,13,
	13,10,10,10,18,18,18,18,
	13,13,13,13,10,10,10,10,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 redShield6[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,18,
	13,13,13,13,13,13,18,10,
	13,13,13,18,18,18,10,13,
	18,18,18,10,10,10,13,13,
	10,10,10,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 redShield7[64]={
	18,10,13,13,13,13,13,13,
	10,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 redShield8[64]={
	13,13,13,13,18,10,13,13,
	13,13,13,13,18,10,13,13,
	13,13,13,13,18,10,13,13,
	13,13,13,18,10,13,13,13,
	13,13,13,18,10,13,13,13,
	13,13,13,18,10,13,13,13,
	13,13,18,10,13,13,13,13,
	13,18,10,13,13,13,13,13,
};
u8 redShield9[64]={
	13,13,10,18,13,13,13,13,
	13,13,13,10,18,13,13,13,
	13,13,13,10,18,13,13,13,
	13,13,13,10,18,13,13,13,
	13,13,13,13,18,10,13,13,
	13,13,13,13,18,10,13,13,
	13,13,13,13,18,10,13,13,
	13,13,13,13,18,10,13,13,
};
u8 redShield10[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	18,13,13,13,13,13,13,13,
	10,18,13,13,13,13,13,13,
	13,10,18,13,13,13,13,13,
};
u8 redShield11[64]={
	13,13,13,13,13,13,13,13,
	18,18,18,13,13,13,13,13,
	10,10,10,18,18,18,13,13,
	13,13,13,10,10,10,18,13,
	13,13,13,13,13,13,10,18,
	13,13,13,13,13,13,13,10,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 redShield12[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,18,18,18,18,
	13,10,10,10,10,10,10,10,
	10,18,18,18,13,13,13,13,
	18,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};






u8 blueShield1[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,19,
	13,13,13,13,13,13,19,20,
	13,13,13,13,13,19,20,13,
	13,13,13,13,19,20,13,13,
};
u8 blueShield2[64]={
	13,13,13,19,20,13,13,13,
	13,13,19,20,13,13,13,13,
	13,13,19,20,13,13,13,13,
	13,13,19,20,13,13,13,13,
	13,19,20,13,13,13,13,13,
	13,19,20,13,13,13,13,13,
	13,19,20,13,13,13,13,13,
	13,19,20,13,13,13,13,13,
};
u8 blueShield3[64]={
	13,19,20,13,13,13,13,13,
	13,19,20,13,13,13,13,13,
	13,19,20,13,13,13,13,13,
	13,13,19,20,13,13,13,13,
	13,13,19,20,13,13,13,13,
	13,13,19,20,13,13,13,13,
	13,13,13,19,20,13,13,13,
	13,13,13,13,19,20,13,13,
};
u8 blueShield4[64]={
	13,13,13,13,19,20,13,13,
	13,13,13,13,13,19,20,13,
	13,13,13,13,13,13,19,20,
	13,13,13,13,13,13,13,19,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 blueShield5[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	20,13,13,13,13,13,13,13,
	19,20,20,20,13,13,13,13,
	13,19,19,19,20,20,20,20,
	13,13,13,13,19,19,19,19,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 blueShield6[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,20,
	13,13,13,13,13,13,20,19,
	13,13,13,20,20,20,19,13,
	20,20,20,19,19,19,13,13,
	19,19,19,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 blueShield7[64]={
	20,19,13,13,13,13,13,13,
	19,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 blueShield8[64]={
	13,13,13,13,20,19,13,13,
	13,13,13,13,20,19,13,13,
	13,13,13,13,20,19,13,13,
	13,13,13,20,19,13,13,13,
	13,13,13,20,19,13,13,13,
	13,13,13,20,19,13,13,13,
	13,13,20,19,13,13,13,13,
	13,20,19,13,13,13,13,13,
};
u8 blueShield9[64]={
	13,13,19,20,13,13,13,13,
	13,13,13,19,20,13,13,13,
	13,13,13,19,20,13,13,13,
	13,13,13,19,20,13,13,13,
	13,13,13,13,20,19,13,13,
	13,13,13,13,20,19,13,13,
	13,13,13,13,20,19,13,13,
	13,13,13,13,20,19,13,13,
};
u8 blueShield10[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	20,13,13,13,13,13,13,13,
	19,20,13,13,13,13,13,13,
	13,19,20,13,13,13,13,13,
};
u8 blueShield11[64]={
	13,13,13,13,13,13,13,13,
	20,20,20,13,13,13,13,13,
	19,19,19,20,20,20,13,13,
	13,13,13,19,19,19,20,13,
	13,13,13,13,13,13,19,20,
	13,13,13,13,13,13,13,19,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};
u8 blueShield12[64]={
	13,13,13,13,13,13,13,13,
	13,13,13,13,20,20,20,20,
	13,19,19,19,19,19,19,19,
	19,20,20,20,13,13,13,13,
	20,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
	13,13,13,13,13,13,13,13,
};


u8 slimeDead1[64] =
{
	13,13,13,6,6,6,6,6,
	13,6,6,6,7,6,6,6,
	13,6,6,7,6,6,7,7,
	4,5,5,6,6,6,7,6,
	4,4,5,5,5,5,5,5,
	4,4,4,4,4,5,5,4,
	13,4,4,4,4,4,4,4,
	13,13,13,13,13,13,13,13,
};
u8 slimeDead2[64] =
{
	6,13,13,13,13,13,13,13,
	6,6,6,13,13,13,13,13,
	6,6,7,6,6,6,6,13,
	7,6,6,7,6,6,6,5,
	6,5,6,6,6,6,6,5,
	5,5,5,5,5,6,5,5,
	4,4,4,5,5,5,5,13,
	13,13,13,13,13,13,13,13,
};

u8 moonTL[64]={
	19,19,19,19,19,19,19,19,
	19,19,19,19,9,9,9,9,
	19,19,19,9,9,9,9,9,
	19,19,9,9,1,1,1,9,
	19,9,9,9,1,1,1,9,
	19,9,9,9,9,9,9,9,
	19,9,9,9,9,9,9,9,
	19,9,9,9,9,9,9,9,
};
u8 moonTR[64]={
	19,19,19,19,19,19,19,19,
	 9,19,19,19,19,19,19,19,
	 9, 9,19,19,19,19,19,19,
	 9, 9, 9,19,19,19,19,19,
	 9, 9, 9, 9,19,19,19,19,
	 9, 1, 9, 9,19,19,19,19,
	 9, 9, 9, 9,19,19,19,19,
	 9, 9, 9, 9,19,19,19,19,
};
u8 moonBL[64]={
	19, 9, 9, 9, 9, 9, 9, 9,
	19,19, 9, 9, 1, 1, 9, 9,
	19,19,19, 9, 1, 1, 9, 9,
	19,19,19,19, 9, 1, 9, 9,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
};
u8 moonBR[64]={
	 9, 1, 9, 9,19,19,19,19,
	 9, 9, 9,19,19,19,19,19,
	 9, 9,19,19,19,19,19,19,
	 9,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
};
u8 nightSky[64]={
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
};



u8 sunTL[64]={
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0,21,21,21,21,
	 0, 0, 0, 0,21,21,21,21,
	 0, 0,21,21,21,21,21,21,
	 0,21,21,21,21,21,21,21,
	 0,21,21,21,21,21,21,21,
	 0,21,21,21,21,21,21,21,
	 0,21,21,21,21,21,21,21,
};
u8 sunTR[64]={
	 0, 0, 0, 0, 0, 0, 0, 0,
	21, 0, 0, 0, 0, 0, 0, 0,
	21,21, 0, 0, 0, 0, 0, 0,
	21,21,21, 0, 0, 0, 0, 0,
	21,21,21,21, 0, 0, 0, 0,
	21,21,21,21, 0, 0, 0, 0,
	21,21,21,21, 0, 0, 0, 0,
	21,21,21,21, 0, 0, 0, 0,
};
u8 sunBL[64]={
	 0,21,21,21,21,21,21,21,
	 0, 0,21,21,21,21,21,21,
	 0, 0, 0,21,21,21,21,21,
	 0, 0, 0, 0,21,21,21,21,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
};
u8 sunBR[64]={
	21,21,21,21, 0, 0, 0, 0,
	21,21,21, 0, 0, 0, 0, 0,
	21,21, 0, 0, 0, 0, 0, 0,
	21, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
};

u8 stars1[64]={
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,9,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,9,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,9,19,19,19,
};
u8 stars2[64]={
	19,19,19,19,19,19,19,19,
	19,19,19,9,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,9,19,19,19,19,19,19,
	19,19,19,19,9,19,19,19,
	19,19,19,19,19,19,19,19,
};


u8 bigBush1N[64]={
	19,19,19,19,19,19,12,13,
	19,19,19,19,12,12,13,13,
	19,19,19,11,12,12,13,13,
	19,19,11,11,12,13,13,13,
	19,11,11,11,12,13,13,13,
	11,11,11,11,12,12,13,13,
	11,11,11,11,12,12,12,12,
	11,11,11,11,11,11,12,12,
};

u8 bigBush2N[64]={
	14,14,19,19,19,19,19,19,
	13,13,13,14,14,19,19,19,
	14,13,13,14,14,19,19,19,
	13,13,13,13,13,19,19,19,
	13,13,14,13,13,13,14,19,
	12,13,13,13,13,12,13,11,
	12,12,12,12,12,11,11,11,
	12,12,11,11,11,11,11,11,
};

u8 bigBush3N[64]={
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,19,19,19,19,19,19,
	19,19,13,14,14,14,19,19,
	19,11,13,13,13,13,13,19,
	11,11,12,13,13,13,13,13,
	11,11,12,12,13,13,13,13,
	11,11,11,12,12,12,12,12,
};





u16 mapData[768] =
{
	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
	
	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
	
	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,79,80,0,0,0,
	36,34,35,36,0,0,0,0, 34,35,36,0,0,0,0,34,  35,36,0,0,34,35,36,0, 0,0,0,0,0,0,34,35,
	40,40,40,40,40,40,40,40, 	40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
	40,40,40,40,40,40,40,40, 	40,40,39,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 

	40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,37,38,39,40,40, 40,40,40,40,40,40,40,40, 
	40,40,40,40,40,40,40,40, 40,40,40,40,40,37,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
	40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
	40,37,38,39,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 

	40,40,40,39,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
	40,40,40,40,40,40,40,40, 40,40,40,37,38,39,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,38,40, 
	40,40,39,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,39,40,40,40, 40,40,37,38,39,40,40,40,
	40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 

	40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,37,38,39,40,40,40,40, 
	40,37,40,40,40,40,40,40, 37,38,39,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
	40,40,40,40,40,40,40,40, 40,40,40,38,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
	40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,38,40, 40,40,40,40,40,40,40,40,  

};


u16 mapFloor[448]={
40,40,40,40,40,40,40,40, 	40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
40,40,40,40,40,40,40,40, 	40,40,39,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 

40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,37,38,39,40,40, 40,40,40,40,40,40,40,40, 
40,40,40,40,40,40,40,40, 40,40,40,40,40,37,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
40,37,38,39,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 

40,40,40,39,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
40,40,40,40,40,40,40,40, 40,40,40,37,38,39,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,38,40, 
40,40,39,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,39,40,40,40, 40,40,37,38,39,40,40,40,
40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 

40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,37,38,39,40,40,40,40, 
40,37,40,40,40,40,40,40, 37,38,39,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
40,40,40,40,40,40,40,40, 40,40,40,38,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 
40,40,40,40,40,40,40,40, 40,40,40,40,40,40,40,40, 40,40,40,40,40,40,38,40, 40,40,40,40,40,40,40,40, 


};



//nubes
pair<int,int> smallCloud1;
pair<int,int> smallCloud2;
pair<int,int> bigCloud1;

//slime
bool animator;
int slimePosition;
bool redShield;
bool blueShield;
int lifes;

//moscas 
pair<int,int> fly1;
pair<int,int> fly2;
bool thereIsAFly1;
bool thereIsAFly2;
bool animatorFly;
bool red;
bool animatorFly2;
bool red2;


//utilidad

static u16* mapMemory  = (u16*) BG_MAP_RAM(0);
int lastTile;

bool day;
bool invulnerability;

int score;
int highestScore = 0;
int previous;


bool gameover=true;
pair<int,int> sun;

static u8*  tileMemory;
//static u16* mapMemory;

bool framebufferMode=true;

//efectos
mm_sound_effect effect1 = {
	{ SFX_EFECTO1 } ,			// id
	(int)(1.0f * (1<<10)),	// rate
	0,		// handle
	255,	// volume
	255,		// panning
};

mm_sound_effect effect2 = {
	{ SFX_EFECTO2 } ,			// id
	(int)(1.0f * (1<<10)),	// rate
	0,		// handle
	150,	// volume
	255,	// panning
};

mm_sound_effect effect3 = {
	{ SFX_EFECTO3 } ,			// id
	(int)(1.0f * (1<<10)),	// rate
	0,		// handle
	255,	// volume
	255,	// panning
};    


mm_sound_effect effect4 = {
	{ SFX_EFECTO4 } ,			// id
	(int)(1.0f * (1<<10)),	// rate
	0,		// handle
	255,	// volume
	255,	// panning
};    



//definir funciones
// Las funciones estan explicadas a continuación

//pintar
void paintSky();
void paintStars();
void paintSun();
void paintMoon();
void paintClouds();
void paintSlime();
void changeBush();
void clearSky();
//void clearFloor();
void eraseShield();

//timers
void bigTimer();
void smallTimer();
void mediumTimer();

//mover
void moveBigClouds();
void moveSmallClouds();
void moveFloor();
void moveSunMoon();
void moveSlime();
void moveFly();

//utilidad
void reset();
void interruptions();
void gameOver();
void collision();
void configurationFramebuffer();
void configurationTeselas();

//generar
void generateClouds();
void generateFloor();
void generateFlys();

//musica
void PlayMusic1();
void PlayMusic2();

void moveEffect();
void flyEffect();
void loseEffect();
void hitEffect();


//--------------------------------------------------------------
//-----------funciones----------------------------
//------------------------------------------

//-------------------------------------------------------------------------------------------------------------
//pintar
//-------------------------------------------------------------------------------------------------------------
/*	
		Limpia el cielo (clearSky()) y en función de si es de día o de noche (indicado por booleano day),
		pinta las nubes y el Sol, o las estrellas y la luna.		
*/
void paintSky(){
	clearSky();
	if(day){
		paintClouds();
		paintSun();
	}else{
		paintStars();
		paintMoon();
	}
}

/*
		Pinta las estrellas en el cielo. Se elige un numero aleatorio de estrellas (random). Dentro del bucle se 
		selecciona una posición aleatoria con randomRow y randomColumn. Por último, si randomStar es 0 se pintará
		un tipo de estrella, sino, el otro tipo.	
*/
void paintStars(){
	int random=rand()%150;
	for(int i=0; i<random;i++){
		int randomRow=rand()%8;
		int randomColumn=rand()%31;
		int randomStar=rand()%2;
		if(randomStar==0)mapMemory[randomRow*32+randomColumn]=Stars1;
		else mapMemory[randomRow*32+randomColumn]=Stars2;
	}

}

/*
		Pinta el sol. Si el sol esta bajo(cuando la x, sun.first, del sol sea = 9), por ende 
		solo se ve la parte superior, se pintara solo esa parte. Si eso no sucede, se pintará
		el sol entero.
*/

void paintSun(){
	
	if(!(sun.first>=9) ){
		mapMemory[sun.first*32+sun.second]=SunTL;
		mapMemory[sun.first*32+sun.second+1]=SunTR;
		mapMemory[(sun.first +1)*32+sun.second]=SunBL;
		mapMemory[(sun.first+1)*32+sun.second+1]=SunBR;
	}
	else{
		mapMemory[sun.first*32+sun.second]=SunTL;
		mapMemory[sun.first*32+sun.second+1]=SunTR;
	}
}

/*
		Pinta la luna. La lógica es similar a la función paintSun().
*/
void paintMoon(){
	

	if(!(sun.first>=9) ){
		mapMemory[sun.first*32+sun.second]=MoonTL;
		mapMemory[sun.first*32+sun.second+1]=MoonTR;
		mapMemory[(sun.first +1)*32+sun.second]=MoonBL;
		mapMemory[(sun.first+1)*32+sun.second+1]=MoonBR;
	}
	else{
		mapMemory[sun.first*32+sun.second]=MoonTL;
		mapMemory[sun.first*32+sun.second+1]=MoonTR;
	}

}

/*
		Pinta las nubes. En este caso hay tres nubes, una grande y dos pequeñas. Para la grande se pintará
		la parte izquerda de la nube, pero, en caso de que la y de la nube (bigCloud1.second) sea 31, se pintará
		en una linea más arriba, para que no haya un salto. 
		Una logica similar se emplea con las nubes pequeñas.
*/

void paintClouds(){

	

	mapMemory[bigCloud1.first*32+bigCloud1.second]=BigCloudTL;
	mapMemory[(bigCloud1.first+1)*32+bigCloud1.second]=BigCloudBL;

	if(bigCloud1.second==31){ 
		mapMemory[(bigCloud1.first-1)*32+bigCloud1.second+1]=BigCloudTR;
		mapMemory[(bigCloud1.first+1-1)*32+bigCloud1.second+1]=BigCloudBR;
	}else{
		mapMemory[bigCloud1.first*32+bigCloud1.second+1]=BigCloudTR;
		mapMemory[(bigCloud1.first+1)*32+bigCloud1.second+1]=BigCloudBR;
	}

	mapMemory[smallCloud1.first*32+smallCloud1.second]=SmallCloudL;
	if(smallCloud1.second==31) mapMemory[(smallCloud1.first-1)*32+smallCloud1.second+1]=SmallCloudR;
	else mapMemory[smallCloud1.first*32+smallCloud1.second+1]=SmallCloudR;

	mapMemory[smallCloud2.first*32+smallCloud2.second]=SmallCloudL;
	if(smallCloud2.second==31) mapMemory[(smallCloud2.first-1)*32+smallCloud2.second+1]=SmallCloudR;
	else mapMemory[smallCloud2.first*32+smallCloud2.second+1]=SmallCloudR;
}

/*
		Pinta el Slime y sus escudos. En este caso, el slime solo tiene dos posiciones que
		se alternan cada vez que el personaje se mueve (destacar que el slime solo se mueve en vertical, por
		lo que su y siempre será la misma).
		Además, tambien se pinta el escudo del color adecuado alrededor del slime tal que:
		O O O O
		O S S O
		O S S O
		O O O O
		(las O son el escudo, las S el slime).
*/
void paintSlime(){
	if(animator){
			mapMemory[slimePosition*32 +16]=			SlimeTL0R;
			mapMemory[slimePosition*32 +16+1]=		SlimeTR0R;
			mapMemory[(slimePosition+1)*32+16]=		SlimeBL0R;
			mapMemory[(slimePosition+1)*32+16+1]=	SlimeBR0R;
	}
	else{
	
			mapMemory[slimePosition*32 +16]=			SlimeTL1R;
			mapMemory[slimePosition*32 +16+1]=		SlimeTR1R;
			mapMemory[(slimePosition+1)*32+16]=		SlimeBL1R;
			mapMemory[(slimePosition+1)*32+16+1]=	SlimeBR1R;
	}

	if(redShield){
		
		mapMemory[(slimePosition-1)*32 +16-1]=RedShield1;
		mapMemory[(slimePosition+0)*32 +16-1]=RedShield2;
		mapMemory[(slimePosition+1)*32 +16-1]=RedShield3;
		mapMemory[(slimePosition+2)*32 +16-1]=RedShield4;

		mapMemory[(slimePosition+2)*32 +16+0]=RedShield5;
		mapMemory[(slimePosition+2)*32 +16+1]=RedShield6;

		mapMemory[(slimePosition+2)*32 +16+2]=RedShield7;
		mapMemory[(slimePosition+1)*32 +16+2]=RedShield8;
		mapMemory[(slimePosition+0)*32 +16+2]=RedShield9;
		mapMemory[(slimePosition-1)*32 +16+2]=RedShield10;

		mapMemory[(slimePosition-1)*32 +16+1]=RedShield11;
		mapMemory[(slimePosition-1)*32 +16+0]=RedShield12;
	}
	if(blueShield){
		mapMemory[(slimePosition-1)*32 +16-1]=BlueShield1;
		mapMemory[(slimePosition+0)*32 +16-1]=BlueShield2;
		mapMemory[(slimePosition+1)*32 +16-1]=BlueShield3;
		mapMemory[(slimePosition+2)*32 +16-1]=BlueShield4;

		mapMemory[(slimePosition+2)*32 +16+0]=BlueShield5;
		mapMemory[(slimePosition+2)*32 +16+1]=BlueShield6;

		mapMemory[(slimePosition+2)*32 +16+2]=BlueShield7;
		mapMemory[(slimePosition+1)*32 +16+2]=BlueShield8;
		mapMemory[(slimePosition+0)*32 +16+2]=BlueShield9;
		mapMemory[(slimePosition-1)*32 +16+2]=BlueShield10;

		mapMemory[(slimePosition-1)*32 +16+1]=BlueShield11;
		mapMemory[(slimePosition-1)*32 +16+0]=BlueShield12;
	}
}


/*

	Cambia el fondo del arbusto de dia a noche y viceversa
*/
void changeBush(){
	if(!day){
		for(int column=0; column<31;column++){
			
			if(mapMemory[9*32+column] == BigBush1) mapMemory[9*32+column]=BigBush1N;
			else if(mapMemory[9*32+column]==BigBush2) mapMemory[9*32+column]=BigBush2N;
			else if(mapMemory[9*32+column]==BigBush3) mapMemory[9*32+column]=BigBush3N;
			else if(mapMemory[9*32+column]==Sky)mapMemory[9*32+column]=NightSky;
		}
	}else{
		for(int column=0; column<31;column++){
		
			if(mapMemory[9*32+column] == BigBush1N) mapMemory[9*32+column]=BigBush1;
			else if(mapMemory[9*32+column]==BigBush2N) mapMemory[9*32+column]=BigBush2;
			else if(mapMemory[9*32+column]==BigBush3N) mapMemory[9*32+column]=BigBush3;
			else if(mapMemory[9*32+column]==NightSky)mapMemory[9*32+column]=Sky;
		}
	}
	
}

/*
		Se limpia el cielo volviendolo a pintar, en el caso del día de azul claro, en el de la
		noche en azul oscuro.
*/

void clearSky(){
	if(day){
		for(int row=0;row<10;row++){
			for(int column=0;column<32;column++)
			{
				if(mapMemory[row*32+column]!=BigBush1 && mapMemory[row*32+column] !=BigBush2
					&& mapMemory[row*32+column]!=BigBush3) mapMemory[row*32+column] = Sky;
				
		  }
		}	

	}else{
		for(int row=0;row<10;row++){
			for(int column=0;column<32;column++)
			{
				if(mapMemory[row*32+column]!=BigBush1N && mapMemory[row*32+column]!=BigBush2N
					&& mapMemory[row*32+column]!=BigBush3N) mapMemory[row*32+column] = NightSky;
		  }
		}	
	}
	
}


/*
		Se borra el escudo y se sustituye por lo que hubiese en el suelo antes (que se
		guarda en mapFloor). Esta funcion vale para borrar ambos escudos, ya que solo cambian
		el color, no la posición.
*/
void eraseShield(){
			mapMemory[(slimePosition-1)*32 +16-1]=mapFloor[(slimePosition-1-10)*32 +16-1];
			mapMemory[(slimePosition+0)*32 +16-1]=mapFloor[(slimePosition+0-10)*32 +16-1];
			mapMemory[(slimePosition+1)*32 +16-1]=mapFloor[(slimePosition+1-10)*32 +16-1];
			mapMemory[(slimePosition+2)*32 +16-1]=mapFloor[(slimePosition+2-10)*32 +16-1];

			mapMemory[(slimePosition+2)*32 +16+0]=mapFloor[(slimePosition+2-10)*32 +16+0];
			mapMemory[(slimePosition+2)*32 +16+1]=mapFloor[(slimePosition+2-10)*32 +16+1];

			mapMemory[(slimePosition+2)*32 +16+2]=mapFloor[(slimePosition+2-10)*32 +16+2];
			mapMemory[(slimePosition+1)*32 +16+2]=mapFloor[(slimePosition+1-10)*32 +16+2];
			mapMemory[(slimePosition+0)*32 +16+2]=mapFloor[(slimePosition+0-10)*32 +16+2];
			mapMemory[(slimePosition-1)*32 +16+2]=mapFloor[(slimePosition-1-10)*32 +16+2];

			mapMemory[(slimePosition-1)*32 +16+1]=mapFloor[(slimePosition-1-10)*32 +16+1];
			mapMemory[(slimePosition-1)*32 +16+0]=mapFloor[(slimePosition-1-10)*32 +16+0];
}



//-------------------------------------------------------------------------------------------------------------
//timers
//-------------------------------------------------------------------------------------------------------------

/*
		Debido a la gran cantidad de funciones que necesitaban un timer, he visto más práctico definir tres timers 
		en los que se llaman a las funciones que deben realizar su acción en dicho momento.

		Ademas hay algunas variables, como la invulnerabilidad o los escudos que cambaian con el tiempo, por lo que
		las he incluido en dichos timers.
*/
void fastTimer(){
	moveSmallClouds();
	moveFloor();
	moveFly();
	//moveSunMoon();  //Descomentar esta linea y comentar la similar en la función slowTimer() para que vaya más rapido el ciclo dia-noche
}

void mediumTimer(){
	moveBigClouds();
	if(invulnerability) invulnerability=false;
	score++;
}


void slowTimer(){
	moveSunMoon();
	generateFloor();
	generateFlys();
	
	if(blueShield){
		blueShield=false;
		eraseShield();
	
	}
	if(redShield){
		redShield=false;
		eraseShield();
	}
}

//-------------------------------------------------------------------------------------------------------------
//mover
//-------------------------------------------------------------------------------------------------------------

/*
		Mueve la nube grande y a continuación llama a la función paintSky() para actualizar
		la pantalla.
*/
void moveBigClouds(){
	if(bigCloud1.second>=31) bigCloud1.second=0;
	else bigCloud1.second+=1;

	paintSky();
}

/*
		Mueve las nubes pequeñas y, como la función anterior, llama a paintSky() para actualizar
		la pantalla.
*/
void moveSmallClouds(){
	if(smallCloud1.second<=0) smallCloud1.second=31;
	else smallCloud1.second-=1;
	

	if(smallCloud2.second<=0) smallCloud2.second=31;
	else smallCloud2.second-=1;
	paintSky();
}


/*
		Mueve el suelo hacia la izquierda, de manera que en la posicion actual se copia la posición de la derecha.
		Ademas se guarda en una variable temporal la primera tesela (columna=0) para copiarla en la ultima tesela (columna=31).

		En esta función, al moverse el suelo, debemos repintar el Slime y comprobar si al mover el suelo, ha habido alguna
		colision con el slime.
*/
void moveFloor(){
	int column;
	for(int row=10; row<24; row++){
		column=0;
		int temp= mapFloor[(row-10)*32+column];
		for(column=0; column<32-1; column++){
			mapFloor[(row-10)*32+column]=mapFloor[(row-10)*32+column+1];
			mapMemory[row*32+column]=mapFloor[(row-10)*32+column];	
		}
		column=32-1;
		mapFloor[(row-10)*32+column]=temp;
		mapMemory[row*32+column]=mapFloor[(row-10)*32+column];
	}
	paintSlime();
	collision();
}


/*
		Se encarga de mover el sol o luna, ya que la variable de la posición usada es la misma, por 
		lo que la luna es una "skin" del sol. 
		Moveremos el sol (o luna) de manera parabolica, de derecha a izquierda. Por lo que, si estamos a la izquierda
		de la pantalla, y en el horizonte ( en la posicion (3,9) ), el sol se pondrá, será de noche y la luna saldrá
		en la posicion (27,9) (pasará de igual manera con la luna).
		Si la columna en la que se encuentra el sol es menor a 20, este ascenderá, y descenderá si es menor a 11. En el resto
		de casos, ira horizontal, siempre moviendose hacia la izquierda.
*/

void moveSunMoon(){
	if(sun.second<=3 && sun.first>=9){
		day=!day;
		changeBush();
		sun.second=27;
		sun.first=9;
	}
	else if(sun.second>20){
		sun.first--;
		sun.second--;
	}else if(sun.second<11){
		sun.first++;
		sun.second--;
	}else{
		sun.second--;
	}
}


/*
		Esta función es la encargada del movimiento de nuestro slime.
		Primeramente comprobamos si el escudo esta puesto y nos estamos moviendo, para borrarlo.
		Tras eso, si vamos hacia arriba borraremos al slime por abajo, haremos que suene un sonido y se moverá
		la posicion del slime. Cambiamos el animator para que cambie la animación y comprobamos colisiones.
		Haremos lo mismo para ir en direccion contraria.

		La tecla A tiene doble función, la de reiniciar el juego, si el booleano
		gameover es true, y la de colocar el escudo, si es false. La tecla B colocará
		el escudo del otro color.

		Como nos hemos movido, necesitamos volver a pintar el slime (si los escudos estan puestos,
		por ende sus variables son true, también se pintarán).
*/

void moveSlime(){
	if((REG_KEYINPUT== 0x03BF || REG_KEYINPUT == 0x037F) && (blueShield || redShield)){
		eraseShield();
	}
	if ( REG_KEYINPUT == 0x03BF) { //up
    	if(slimePosition-1 > 10){
    		mapMemory[(slimePosition+1)*32+16]=mapFloor[(slimePosition+1-10)*32+16];
    		mapMemory[(slimePosition+1)*32+17]=mapFloor[(slimePosition+1-10)*32+17];

    		moveEffect();
    		slimePosition-=1;
    		animator=!animator;

    		collision();
    		
    	}
    }
    
  if (REG_KEYINPUT ==0x037F ){ //down
    	if(slimePosition+1 < 23){
    		mapMemory[(slimePosition)*32+16]=mapFloor[(slimePosition-10)*32+16];
    		mapMemory[(slimePosition)*32+17]=mapFloor[(slimePosition-10)*32+17];
    		slimePosition+=1;
    		moveEffect();
    		animator=!animator;
    		collision();
    		
    	}
    }
	
	    
    

  if(!gameover && REG_KEYINPUT == 0x3FE){ //A, escudo rojo
  	
  	
  	redShield=true;
  	blueShield=false;

   
  }else if(REG_KEYINPUT == 0x03FD){ //B, escudo azul
  	
  	
  	blueShield=true;
  	redShield=false;
  }else if(gameover && REG_KEYINPUT == 0x03FE)reset();

   if(!gameover)paintSlime();
}


/*
		Esta funcion se encarga de mover a las moscas y de comprobar su hitbox con el Slime.
		Como debemos encargarnos de la hitbox, necesitamos calcularla. En esencia disminuirá 1 si el slime
		tiene el escudo (ya que lo hace más grande por ambos lados, pero solo estamos teniendo en cuenta le lado izquierdo).

		Como hay dos posibles moscas, la función realizará acciones similares para cada una de las moscas. Si existe una mosca, 
		comprobamos si ha llegado a la linea 16 (o 15 con el escudo). Si no ha llegado, borraremos la mosca y calcularemos
		la nueva posición:
				Si la fila en la que estamos es mas pequeña que la posicion del slime, le sumaremos 1 y avanzaremos.
				Si la fila en la que estamos es mas grande, le restaremos 1 y avanzaremos.
				Si es igual, avanzaremos.
				(siempre teniendo en cuenta no irnos de los limites)

		En caso de que ya estemos en la columna 16, si estamos por encima del slime bajaremos, si estamos por debajo, subiremos
		y, si estamos justo encima, la mosca morirá. Entonces calculamos el daño, y llamamos a gameOver() en caso de no tener
		el escudo del color correcto puesto.
		
		Por ultimo, si nos hemos movido cambiamos el animador para alternar posiciones y pintamos la mosca del color adecuado
*/


	


void moveFly(){
	int shieldHitbox=0;
	if(blueShield||redShield) shieldHitbox=1;
	if (thereIsAFly1){
		
		if(fly1.second<(16-shieldHitbox) ){

			mapMemory[(fly1.first)*32+fly1.second]=mapFloor[(fly1.first-10)*32+fly1.second];
			
			if(fly1.first<slimePosition){
						if(fly1.first+1<23 ){
							
						 	fly1.first++;
						 	fly1.second++;
						}
			}
			else if(fly1.first>slimePosition){
						if(fly1.first-1>9){
							
						 	fly1.first--;
						 	fly1.second++;

						}
			}
			else{
						
						fly1.second++;
			}
			
		}

		else if(fly1.second>=(16-shieldHitbox)){
			if(fly1.first<(slimePosition-shieldHitbox))fly1.first++;
			else if (fly1.first>(slimePosition +1+shieldHitbox)) fly1.first--;
			else {
				thereIsAFly1=false;
				if((red && !redShield) || (!red && !blueShield)){
				 gameOver();
				 fly1.first=0;
				 fly1.second=0;
				}
				
			}
		}
		if(thereIsAFly1 && red){
			if(!animatorFly) mapMemory[(fly1.first)*32+fly1.second]=RedFly2;
			else mapMemory[(fly1.first)*32+fly1.second]=RedFly;	
		}else if(thereIsAFly1 && !red){
			if(!animatorFly) mapMemory[(fly1.first)*32+fly1.second]=BlueFly2;
			else mapMemory[(fly1.first)*32+fly1.second]=BlueFly;	
		}
		
		animatorFly=!animatorFly;

	}
	if(thereIsAFly2 && !day){ //las segundas moscas solo aparecen de noche

		if(fly2.second<(16-shieldHitbox) ){

				mapMemory[(fly2.first)*32+fly2.second]=mapFloor[(fly2.first-10)*32+fly2.second];
				
				if(fly2.first<slimePosition){
							if(fly2.first+1<23 ){
								
							 	fly2.first++; 
							 	fly2.second++;
							}
				}
				else if(fly2.first>slimePosition){
							if(fly2.first-1>9){
								
							 	fly2.first--;
							 	fly2.second++;

							}
				}
				else{
							
							fly2.second++;
				}
				
			
			}

			else if(fly2.second>=(16-shieldHitbox)){
				if(fly2.first<(slimePosition-shieldHitbox))fly2.first++;
				else if (fly2.first>(slimePosition +1+shieldHitbox)) fly2.first--;
				else {
					thereIsAFly2=false;
					fly2.second=0;
					 	fly2.first=0;
					 	
					if((red2 && !redShield) || (!red2 && !blueShield)){
					 	gameOver();
					 	
					}
					
				}
			}
			if(thereIsAFly2 && red2){
				if(!animatorFly2) mapMemory[(fly2.first)*32+fly2.second]=RedFly2;
				else mapMemory[(fly2.first)*32+fly2.second]=RedFly;	
			}else if(thereIsAFly2 && !red2){
				if(!animatorFly2) mapMemory[(fly2.first)*32+fly2.second]=BlueFly2;
				else mapMemory[(fly2.first)*32+fly2.second]=BlueFly;	
			}
			
			animatorFly2=!animatorFly2;

	}
}



//-------------------------------------------------------------------------------------------------------------
//utilidad
//-------------------------------------------------------------------------------------------------------------


/*
		Resetea el juego. Coloca todas las variables necesarias a su valor inicial, vuelve a poner la musica, pinta de nuevo
		el escenario y limpia el mapa de suelo(mapFloor). Por ultimo genera nuevas nubes, pinta el Slime y habilita las teclas
		y timers necesarios. Limpia tambien la pantalla superior.
*/
void reset(){
	gameover=false;
	PlayMusic1();
	animator=false;
	slimePosition=16;
	thereIsAFly1=false;
	thereIsAFly2=false;
	day=true;
	invulnerability=false;
	score=0;
	previous=-1;
	animatorFly=false;
	
	lastTile=32;
	lifes=3;
	sun.first=9;
	sun.second=27;

	framebufferMode= false;

	//limpia pantalla
	for(int row=0; row<24; row++){
		for(int column=0;column<32; column++){
			mapMemory[row*32+column]= mapData[row*32+column];
		}
	}

	//limpia mapa
	for(int row=10; row<24; row++){
		for(int column=0; column<32;column++){
		
			mapFloor[(row-10)*32+column]= mapData[row*32+column];
		}
	}
	generateClouds();
	paintSlime();

	REG_KEYCNT = 0x40C3; //bits 0(a), 1 (b), 6(up), 7(down) -> 1111 0000 1100 0011 
	irqEnable(IRQ_TIMER0);
	irqEnable(IRQ_TIMER1);
	irqEnable(IRQ_TIMER2);

	consoleClear();
}

/*
		Inicializa las interrupciones y los botones necesarios.
*/

void interruptions(){

	//timers
	irqEnable(IRQ_TIMER0);
    irqSet(IRQ_TIMER0,fastTimer);
    TIMER_DATA(0)=49152;
    TIMER_CR(0) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;

    irqEnable(IRQ_TIMER1);
    irqSet(IRQ_TIMER1,mediumTimer);
    TIMER_DATA(1)=32764;
    TIMER_CR(1) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;
    
    irqEnable(IRQ_TIMER2);
    irqSet(IRQ_TIMER2,slowTimer);
    TIMER_DATA(2)=0;
    TIMER_CR(2) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;

    //buttons
    irqSet(IRQ_KEYS,moveSlime);
    irqEnable(IRQ_KEYS);
    REG_KEYCNT = 0x4001; 
   
}

/*
		Maneja el sistema de vidas y muerte. Si no eres invulnerable, tus vidas bajan. Si estas llegan
		a 0, mueres. Por ello, sonará un sonido indicando tu muerte y habrá "skin" especial de muerte para
		el slime (como solo ocupa 1x2, las dos teselas de arriba serán suelo ya definido).

		Además se pararán todos los timers del juego y solo se podrá pulsar la tecla A para reiniciarlo. Un booleano
		servirá para indicar que ha sido el fin de la partida.

		Si no morimos, se nos resta una vida y se nos concede un segundo de invulnerabilidad que se desactiva con el tiempo.
*/


void gameOver(){
	if(!invulnerability && lifes-1<=0){
		lifes=0;
		loseEffect();

		mapMemory[slimePosition*32 +16]=			mapFloor[(slimePosition-10)*32 +16];
		mapMemory[slimePosition*32 +16+1]=	mapFloor[(slimePosition-10)*32 +16+1];
		mapMemory[(slimePosition+1)*32+16]=		SlimeDead1;
		mapMemory[(slimePosition+1)*32+16+1]=	SlimeDead2;


		irqDisable(IRQ_TIMER0);
		irqDisable(IRQ_TIMER1);
		irqDisable(IRQ_TIMER2);
		REG_KEYCNT = 0x4001; 


		gameover=true;

	}else if(!invulnerability) {
		lifes--;
		hitEffect();
		invulnerability=true;
	}
}

/*
		Se comprueba si alguna de las teselas en las que esta situado el slime es distinto de suelo, por ende, nos hace daño.
		Como el slime esta solo en memoria, pero el suelo esta tambien en el mapFloor, se puede comprobar sin problemas.
*/
void collision(){
	if((mapFloor[(slimePosition-10)*32 +16] 	!=Grass1 		&& mapFloor[(slimePosition-10)*32 +16]!=Grass2 		&& mapFloor[(slimePosition-10)*32 +16]	!=Grass3 		&& mapFloor[(slimePosition-10)*32 +16]	!=Grass4) 	||
		 (mapFloor[(slimePosition-10)*32 +16+1]	!=Grass1 		&& mapFloor[(slimePosition-10)*32 +16+1]!=Grass2 	&& mapFloor[(slimePosition-10)*32 +16+1]	!=Grass3 	&& mapFloor[(slimePosition-10)*32 +16+1]	!=Grass4)	||
		 (mapFloor[(slimePosition+1-10)*32+16]	!=Grass1 		&& mapFloor[(slimePosition+1-10)*32+16]!=Grass2 	&& mapFloor[(slimePosition+1-10)*32+16]	!=Grass3 		&& mapFloor[(slimePosition+1-10)*32+16]	!=Grass4)	 ||
		 (mapFloor[(slimePosition+1-10)*32+16+1]	!=Grass1  && mapFloor[(slimePosition+1-10)*32+16+1]!=Grass2	&& mapFloor[(slimePosition+1-10)*32+16+1]	!=Grass3	&& mapFloor[(slimePosition+1-10)*32+16+1]	!=Grass4)){
		gameOver();
		
	}

}

/*
		Configura el modo framebuffer para poder mostrar imagenes.
*/
void configurationFramebuffer(){

	REG_POWERCNT = POWER_LCD | POWER_2D_A ;
	REG_DISPCNT = MODE_FB0 ;
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_LCD ;
	dmaCopy ( portadaBitmap , VRAM_A , 256*192*2); 
}

/*
		Configura el modo teselas
*/

void configurationTeselas(){



	REG_POWERCNT = POWER_ALL_2D;
	REG_DISPCNT  = MODE_0_2D   | DISPLAY_BG0_ACTIVE ;
	VRAM_A_CR    = VRAM_ENABLE | VRAM_A_MAIN_BG ;
	VRAM_B_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	BGCTRL [0]   = BG_32x32    | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);

	tileMemory = (u8*)  BG_TILE_RAM(1);
	mapMemory  = (u16*) BG_MAP_RAM(0);

	//colors
	BG_PALETTE[0]=RGB15( 11, 27, 31); // Azul cielo
	BG_PALETTE[1]=RGB15( 22, 29, 31); // Azul1
	BG_PALETTE[2]=RGB15( 25, 30, 31); // Azul2
	BG_PALETTE[3]=RGB15( 29, 31, 31); // Azul3

	BG_PALETTE[4]=RGB15( 31, 14, 17); // Rosa
	BG_PALETTE[5]=RGB15( 31, 18, 20); // Rosa
	BG_PALETTE[6]=RGB15( 31, 21, 23); // Rosa
	BG_PALETTE[7]=RGB15( 30, 10, 14); // Rosa
	BG_PALETTE[8]=RGB15( 0, 0, 0); // negro
	BG_PALETTE[9]=RGB15( 31, 31, 31); // blanco

	BG_PALETTE[10]=RGB15( 22, 3, 3); // rojo oscuro
	BG_PALETTE[18]=RGB15(30, 8, 7);  //rojo claro  

	BG_PALETTE[11]=RGB15(3, 11, 4); //verde oscuro
	BG_PALETTE[12]=RGB15(6, 15, 6); //sombra verde
	BG_PALETTE[13]=RGB15(9, 21, 10); //verde neutro
	BG_PALETTE[14]=RGB15(17, 24, 9);  //verde claro

	BG_PALETTE[15]=RGB15(28, 10, 0);  //marron oscuro  
	BG_PALETTE[16]=RGB15(31, 22, 9);  //marron medio
	BG_PALETTE[17]=RGB15(31, 25, 16);  //marron claro  

	BG_PALETTE[19]=RGB15(0,18,16); //azul oscuro
	BG_PALETTE[20]=RGB15(4,18,30); //azul normal

	BG_PALETTE[21]=RGB15(31, 23, 1); //amarillo





	//tiles
	dmaCopy(sky,        tileMemory + 0,     sizeof(sky));  //0

	dmaCopy(bigCloudBL, tileMemory + 64,  	sizeof(bigCloudBL)); //1
	dmaCopy(bigCloudBR, tileMemory + 128, 	sizeof(bigCloudBR)); //2
	dmaCopy(bigCloudTL, tileMemory + 192, 	sizeof(bigCloudTL)); //3
	dmaCopy(bigCloudTR, tileMemory + 256, 	sizeof(bigCloudTR)); //4

	dmaCopy(smallCloudL,tileMemory + 320, 	sizeof(smallCloudL)); //5
	dmaCopy(smallCloudR,tileMemory + 384, 	sizeof(smallCloudR)); //6

	dmaCopy(slimeTL0L, 	tileMemory + 448, 	sizeof(slimeTL0L)); //7
	dmaCopy(slimeTR0L,	tileMemory + 512,	sizeof(slimeTR0L)); //8
	dmaCopy(slimeBL0L,	tileMemory + 576, 	sizeof(slimeBL0L)); //9
	dmaCopy(slimeBR0L,	tileMemory + 640, 	sizeof(slimeBR0L)); //10

	dmaCopy(floor,		tileMemory + 704, 	sizeof(floor)); //11
	dmaCopy(floor2,		tileMemory + 768, 	sizeof(floor2)); //12

	dmaCopy(slimeTL0R, 	tileMemory + 832, 	sizeof(slimeTL0R)); //13
	dmaCopy(slimeTR0R,	tileMemory + 896, 	sizeof(slimeTR0R)); //14
	dmaCopy(slimeBL0R,	tileMemory + 960, 	sizeof(slimeBL0R)); //15
	dmaCopy(slimeBR0R,	tileMemory + 1024, 	sizeof(slimeBR0R)); //16

	dmaCopy(slimeTL1L, 	tileMemory + 1088, 	sizeof(slimeTL1L)); //17
	dmaCopy(slimeTR1L,	tileMemory + 1152, 	sizeof(slimeTR1L)); //18
	dmaCopy(slimeBL1L,	tileMemory + 1216, 	sizeof(slimeBL1L)); //19
	dmaCopy(slimeBR1L,	tileMemory + 1280, 	sizeof(slimeBR1L)); //20

	dmaCopy(slimeTL1R, 	tileMemory + 1344, 	sizeof(slimeTL1R)); //21
	dmaCopy(slimeTR1R,	tileMemory + 1408, 	sizeof(slimeTR1R)); //22
	dmaCopy(slimeBL1R,	tileMemory + 1472, 	sizeof(slimeBL1R)); //23
	dmaCopy(slimeBR1R,	tileMemory + 1536, 	sizeof(slimeBR1R)); //24

	dmaCopy(slimeTL0I, 	tileMemory + 1600, 	sizeof(slimeTL0I)); //21
	dmaCopy(slimeTR0I,	tileMemory + 1664, 	sizeof(slimeTR0I)); //22
	dmaCopy(slimeBL0I,	tileMemory + 1728, 	sizeof(slimeBL0I)); //23
	dmaCopy(slimeBR0I,	tileMemory + 1792, 	sizeof(slimeBR0I)); //24

	dmaCopy(slimeTL1I, 	tileMemory + 1856, 	sizeof(slimeTL1I)); //21
	dmaCopy(slimeTR1I,	tileMemory + 1920, 	sizeof(slimeTR1I)); //22
	dmaCopy(slimeBL1I,	tileMemory + 1984, 	sizeof(slimeBL1I)); //23
	dmaCopy(slimeBR1I,	tileMemory + 2048, 	sizeof(slimeBR1I)); //24

	dmaCopy(redFly,	tileMemory + 2112, 	sizeof(redFly)); //25
	

	dmaCopy(bigBush1,	tileMemory + 2176, 	sizeof(bigBush1)); //25
	dmaCopy(bigBush2,	tileMemory + 2240, 	sizeof(bigBush2)); //25
	dmaCopy(bigBush3,	tileMemory + 2304, 	sizeof(bigBush3)); //25

	dmaCopy(grass1,	tileMemory + 2368, 	sizeof(grass1)); //25
	dmaCopy(grass2,	tileMemory + 2432, 	sizeof(grass2)); //25
	dmaCopy(grass3,	tileMemory + 2496, 	sizeof(grass3)); //25
	dmaCopy(grass4,	tileMemory + 2560, 	sizeof(grass4)); //25

	dmaCopy(fence1,	tileMemory + 2624, 	sizeof(fence1)); //25
	dmaCopy(fence2,	tileMemory + 2689, 	sizeof(fence2));
	dmaCopy(fence3,	tileMemory + 2753, 	sizeof(fence3));

	dmaCopy(redFly2,	tileMemory + 2817, 	sizeof(redFly2));

	dmaCopy(blueFly,	tileMemory + 2881, 	sizeof(blueFly));
	dmaCopy(blueFly2,	tileMemory + 2945, 	sizeof(blueFly2));

	dmaCopy(fence4,	tileMemory + 3009, 	sizeof(fence4));

	dmaCopy(redShield1,	tileMemory + 3073, 	sizeof(redShield1));
	dmaCopy(redShield2,	tileMemory + 3137, 	sizeof(redShield2));
	dmaCopy(redShield3,	tileMemory + 3201, 	sizeof(redShield3));
	dmaCopy(redShield4,	tileMemory + 3265, 	sizeof(redShield4));
	dmaCopy(redShield5,	tileMemory + 3329, 	sizeof(redShield5));
	dmaCopy(redShield6,	tileMemory + 3393, 	sizeof(redShield6));
	dmaCopy(redShield7,	tileMemory + 3457, 	sizeof(redShield7));
	dmaCopy(redShield8,	tileMemory + 3521, 	sizeof(redShield8));
	dmaCopy(redShield9,	tileMemory + 3585, 	sizeof(redShield9));
	dmaCopy(redShield10,	tileMemory + 3649, 	sizeof(redShield10));
	dmaCopy(redShield11,	tileMemory + 3713, 	sizeof(redShield11));
	dmaCopy(redShield12,	tileMemory + 3777, 	sizeof(redShield12));

	dmaCopy(blueShield1,	tileMemory + 3841, 	sizeof(blueShield1));
	dmaCopy(blueShield2,	tileMemory + 3905, 	sizeof(blueShield2));
	dmaCopy(blueShield3,	tileMemory + 3969, 	sizeof(blueShield3));
	dmaCopy(blueShield4,	tileMemory + 4033, 	sizeof(blueShield4));
	dmaCopy(blueShield5,	tileMemory + 4097, 	sizeof(blueShield5));
	dmaCopy(blueShield6,	tileMemory + 4161, 	sizeof(blueShield6));
	dmaCopy(blueShield7,	tileMemory + 4225, 	sizeof(blueShield7));
	dmaCopy(blueShield8,	tileMemory + 4289, 	sizeof(blueShield8));
	dmaCopy(blueShield9,	tileMemory + 4353, 	sizeof(blueShield9));
	dmaCopy(blueShield10,	tileMemory + 4417, 	sizeof(blueShield10));
	dmaCopy(blueShield11,	tileMemory + 4481, 	sizeof(blueShield11));
	dmaCopy(blueShield12,	tileMemory + 4545, 	sizeof(blueShield12));

	dmaCopy(slimeDead1, tileMemory +4609, sizeof(slimeDead1));
	dmaCopy(slimeDead2, tileMemory+4673, sizeof(slimeDead2));

	dmaCopy(moonTL, tileMemory+4737, sizeof(moonTL));
	dmaCopy(moonTR, tileMemory+4801, sizeof(moonTR));
	dmaCopy(moonBL, tileMemory+4865, sizeof(moonBL));
	dmaCopy(moonBR, tileMemory+4929, sizeof(moonBR));

	dmaCopy(nightSky, tileMemory+4993, sizeof(nightSky));

	dmaCopy(sunTL, tileMemory+5057, sizeof(sunTL));
	dmaCopy(sunTR, tileMemory+5121, sizeof(sunTR));
	dmaCopy(sunBL, tileMemory+5185, sizeof(sunBL));
	dmaCopy(sunBR, tileMemory+5249, sizeof(sunBR));

	dmaCopy(stars1, tileMemory+5313, sizeof(stars1));
	dmaCopy(stars2, tileMemory+5377, sizeof(stars2));

	dmaCopy(bigBush1N, tileMemory+5441, sizeof(bigBush1N));
	dmaCopy(bigBush2N, tileMemory+5505, sizeof(bigBush2N));
	dmaCopy(bigBush3N, tileMemory+5569, sizeof(bigBush3N));

	consoleDemoInit();
}

//-------------------------------------------------------------------------------------------------------------
//generar
//-------------------------------------------------------------------------------------------------------------


/*
		Genera nubes de manera aleatoria, siempre en el cielo.
*/
void generateClouds(){
	smallCloud1.first=rand()%7;
	smallCloud1.second=rand()%31;

	smallCloud2.first=rand()%7;
	smallCloud2.second=rand()%31;

	bigCloud1.first=rand()%7;
	bigCloud1.second=rand()%31;
}

/*
		Se genera el suelo de manera aleatoria. Se tiene siempre en consideración que el número de vallas por columna no supere las 14
		(aunque este numero se puede aumentar y disminuir para cambiar la dificultad), asi como que haya un hueco de minimo 2 teselas para
		poder pasar.

		Además, como hay 4 tipos de vallas, se detecta cual hay que colocar: 
				El primer tipo si es un inicio de valla, por lo que la anterior casillla era suelo o -1.
				El segundo tipo si es el medio de una valla, por lo que la anterior sería la primera valla o la segunda.

				Y una vez se ha realizado toda la vaya, se coloca el final de vaya(habiendo anteriormente una valla del 
				segundo tipo), o se coloca la valla unica, si solo hay una tesela de valla por lo que habia 
				anteriormente una vaya del primer tipo. 

			Si no se colocan vallas, estamos haciendo un hueco (doingGap) y se colocará lo que sea que hubiese en el mapa
			inicial (teniendo en cuenta que el mapa incial, mapData, no se mueve, sino que usaremos lastTile para movernos por él).
*/
void generateFloor(){
	int walls=0;
	int gap=0;
	bool doingGap=false;
	for(int row=10; row<24; row++){
		int random=rand()%2;

		if(random ==1 && walls < 14 && !doingGap){
			walls++;
			if(previous==Grass1 || previous==Grass2 || previous==Grass3 || previous==Grass4 || previous==-1) mapFloor[(row-10)*32+32]=Fence1;
			else if(previous==Fence1 || previous==Fence2) mapFloor[(row-10)*32+32]=Fence2;
		}
		else {
			
			if(previous ==Fence1) mapFloor[(row-10-1)*32+32]=Fence4;
			else if(previous==Fence2) mapFloor[(row-10-1)*32+32]=Fence3;
			

			doingGap=true;
			
			mapFloor[(row-10)*32+32]=mapData[row*32+lastTile]; 
			gap++; 
			if(lastTile++>33)lastTile=0;
			if(gap==2 && doingGap) {doingGap=false; gap=0;}
		}
		previous=mapFloor[(row-10)*32+32];
	}
	previous=-1;
}

/*
		Como moveFly(), esta funcion sirve para dos moscas. 
		Si no hay una mosca, se generará en una linea aleatoria, en el suelo, de la primera columna.
		
		De manera aleatoria se decdirá si es azul o roja. Reiniciamos el animador de la mosca.
*/


void generateFlys(){
	if(!thereIsAFly1){
		flyEffect();
		thereIsAFly1=true;
		int random=rand()%13; 
		
		fly1.first=random+10; //(para que solo aparezcan donde haya suelo)
		fly1.second=0;

		random= rand()%2;
		if(random==0){
		 mapMemory[(fly1.first)*32+fly1.second]=BlueFly;
		 red=false;
		}
		else {
			mapMemory[(fly1.first)*32+fly1.second]=RedFly;
			red=true;
		}
		animatorFly=false;
	}
	else if(!thereIsAFly2 && !day){ //Si es de dia solo aparece una mosca, no dos
		flyEffect();
		thereIsAFly2=true;
		int random=rand()%13; //(para que solo aparezcan donde haya suelo)
		
		fly2.first=random+10;
		fly2.second=0;

		random= rand()%2;
		if(random==0){
		 mapMemory[(fly2.first)*32+fly2.second]=BlueFly;
		 red2=false;
		}
		else {
			mapMemory[(fly2.first)*32+fly2.second]=RedFly;
			red2=true;
		}
		animatorFly2=false;
	}
	
}


//-------------------------------------------------------------------------------------------------------------
//generar
//-------------------------------------------------------------------------------------------------------------


void PlayMusic1() {mmStart( MOD_MUSICA, MM_PLAY_LOOP ); } //played=true; }

void PlayMusic2(){ mmStart( MOD_MUSICA2, MM_PLAY_LOOP ); }  // played=true; }

void moveEffect() { mmEffectEx(&effect2); }
void flyEffect() { mmEffectEx(&effect3); }
void loseEffect() { mmEffectEx(&effect1); }
void hitEffect() { mmEffectEx(&effect4); }


//programa principal

int main(void){
	framebufferMode=true;
	srand(time(NULL));
	

	interruptions();

	//sounds
	mmInitDefaultMem((mm_addr)soundbank_bin);
	//mmSetModuleVolume(200);
	// load the module
	mmLoad( MOD_MUSICA );
	mmLoad( MOD_MUSICA2 );

	// load sound effects	
	mmLoadEffect( SFX_EFECTO1 );
	mmLoadEffect( SFX_EFECTO2 );
	mmLoadEffect( SFX_EFECTO3 );
	mmLoadEffect(SFX_EFECTO4);

	
	//cargar la imagen de la portada

	if(framebufferMode){
			
			configurationFramebuffer();
			irqDisable(IRQ_TIMER0);
			irqDisable(IRQ_TIMER1);
			irqDisable(IRQ_TIMER2);


			while(framebufferMode ){

				if(REG_KEYINPUT== 0x03FE) {
					framebufferMode=false;
					configurationTeselas();
					reset();
				}
			}
			
		}

	while(1){
		

		
		swiWaitForVBlank();

		
		iprintf("\x1b[2;2HMaxima puntuacion:  %d", highestScore);
		iprintf("\x1b[4;2HPuntuacion:  %d", score);
		iprintf("\x1b[4;20HVidas  %d", lifes);
		if(gameover){
			iprintf("\x1b[6;2HHas muerto.");
			if(highestScore<=score){
			 iprintf("\x1b[8;2HEnhorabuena, has superado");
			 iprintf("\xb1b[9;2H la maxima puntuacion.");
			 highestScore=score;
			}

			iprintf("\x1b[12;2HPulsa A para volver a jugar.");

		}
	}
}

