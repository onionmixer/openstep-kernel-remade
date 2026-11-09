/* ev_vars.h -- plan 779 (D178): KeyMapping copied from 07 ev_kbd.c:66-67,75-85 (NeXTMach mk-108.1 nextdev/ev_kbd.c, Copyright 1987 NeXT, Inc.); the 50 tentative definitions written to match the original bytes (D178, D024, plan 778.15), types as the 07 externs */
#ifndef _M68K_EV_VARS_H_
#define _M68K_EV_VARS_H_
#ifndef NUMKEYCODES
#define NUMKEYCODES	128
#endif
#ifndef NUMMODIFIERS
#define NUMMODIFIERS	16
#endif
#import <dev/ev_keymap.h>	/* NX_NUMSPECIALKEYS (bsd/dev/ev_keymap.h:41) */
typedef struct KeyMappingStruct {
    short shorts;
    char keyBits[NUMKEYCODES];
    int maxMod;
    unsigned char *modDefs[NUMMODIFIERS];
    unsigned char *keyDefs[NUMKEYCODES];
    int numSeqs;
    unsigned char *seqDefs;
    unsigned char specialKeys[NX_NUMSPECIALKEYS];
    unsigned char *mapping;
} KeyMapping;
int	alphaLock;
int	autoDimPeriod;
int	autoDimTime;
int	autoDimmed;
int	buttonsTied;
Point	clickLoc;
Point	clickSpaceThresh;
int	clickState;
long	clickTime;
long	clickTimeThresh;
int	curBright;
int	curMapLen;
KeyMapping *	curMapping;
KeyMapping	curMappingStorage;
int	currentScreen;
Bounds	cursorPin;
unsigned char	deviceMods;
int	dimmedBrightness;
EvOffsets *	eop;
int	evOpenCalled;
int	evRetryMask;
EvScreen *	evScreen;
int	evScreenSize;
port_t	eventPort;
task_t	eventTask;
int	eventsOpen;
EvGlobals *	evg;
void *	evs;
int	initialKeyRepeat;
int	keyPressed;
int	keyRepeat;
int	keySema;
unsigned char	lastPressure;
short	leftENum;
int	mapNotDefault;
int	mouseDelX;
int	mouseDelY;
int	mouseHandedness;
short	mouseScaleFactors[MAXMOUSESCALINGS];
short	mouseScaleThresholds[MAXMOUSESCALINGS];
int	numMouseScales;
short	rightENum;
int	screens;
int	sessionPrecision;
int	sessionPressure;
int	totalShmemSize;
short	waitFrameRate;
short	waitFrameTime;
short	waitSusTime;
short	waitSustain;
#endif
