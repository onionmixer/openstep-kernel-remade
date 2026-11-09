/******************************************************************************

    ev_mouse.c
    Mouse-specific portion of events driver
    
    Created by Leo Hourvitz 22Dec87 from ev_routines.c
    
    Copyright 1987 NeXT, Inc.
    
    Modified:
    
    10Dec88 Leo  Added old ev_interrupt and ev_common.
    06Jan88 Ted  Modified for multiple screen testing.
    13Jan88 Ted  Modified for PostScript sharing.
    23Aug89 Ted  ANSI.
    19Feb90 Ted  Standardized with "Bounds" instead of "DevBounds"
    19Feb90 Ted  Modifed for multiple driver support.
    05Mar90 Ted  Dave and I added Dave's mouse tablet code.
    12Mar90 Ted  Added ev_unregister_screen() function.
    02Apr90 Ted  Reversed arrowData for premult. towards black framebuffers
    05Apr90 Ted  Mods to ev_unregister_screen.
    10May90 Ted  Three wait cursor data and mask images for animation.
    20May90 Ted  hideWaitCursor() and showWaitCursor().
    18Jun90 Ted  animateWaitCursor().

******************************************************************************/

/*
 * plan 736 (D165, D013, D024, D104, D158): the 1997 m68k ev_mouse.c.
 * NeXTMach mk-108.1 nextdev/ev_mouse.c with the include lines in OPENSTEP paths
 * (the 1997 SDK bsd/dev/m68k/evio.h) and these changes, from the original bytes
 * [0x4069eb8, 0x406aa70) (plans 690-735):
 *	functions that differ from NeXTMach: process_mouse_event, mouse_motion, ev_register_screen, ev_unregister_screen, InitMouseVars, InitMouse, TermMouse, ResetMouse, StartCursor, ShowWaitCursor (NeXTMach showWaitCursor), HideWaitCursor (NeXTMach hideWaitCursor), AnimateWaitCursor (NeXTMach animateWaitCursor)
 *	new functions: MoveTheCursor, evsetup_screens, evdispatch, evretry, ev_wait_frame, ev_point_to_screen
 *	removed (not in this 1997 unit): the cursor bit data and the functions SetCursor, HideCursor, ShowCursor, ObscureCursor, RevealCursor, ShieldCursor, UnShieldCursor, SetMouseMoved, ClearMouseRect, SetMouseRect, boundBounds, touchBounds, offsetBounds
 * The original has no symbols for its static data and static functions: the
 * three init statics keep the NeXTMach names (the 28 bytes of __data are their
 * values and a zero pointer); ev_shmem_cursor, ev_adb_mouse, evCoalesce,
 * evBrightness, ev_wait_frame and ev_point_to_screen are named by this project
 * (D165).  evsetup_screens, MoveTheCursor and the other bodies are forms that
 * give the original bytes, not evidence of the original source.  Lines marked
 * plan 736, and the lines of a plan 736 BEGIN/END region (which may include
 * unchanged lines), differ from NeXTMach.
 */

/* plan 736 (D024, D165) BEGIN: declarations and data */
#import <sys/types.h>
#import <sys/param.h>
#import <sys/systm.h>
#import <kern/kalloc.h>
#import <bsd/dev/m68k/evio.h>

/* plan 736 (D104, D165): struct mouse of NeXTMach nextdev/kmreg.h:100-106 (07 copy nextmach/nextdev/kmreg.h:100-106); the header itself is not included,
 * it would define the COMMON km and alert_key (D158) */
struct mouse {
	u_int	: 16,
		delta_y : 7,
		button_right : 1,
		delta_x : 7,
		button_left : 1;
};

/* plan 736 (D024, D104, D165): the names of NeXTMach nextdev/ev_vars.h that this file uses, as extern declarations; the types are those of ev_vars.h
 * (line numbers of ev_vars.h: cursorPin:148 buttonsTied:156 mouseHandedness:157 mouseDelX:169 mouseDelY:170 numMouseScales:159 mouseScaleThresholds:163 mouseScaleFactors:164 waitFrameRate:98 waitFrameTime:99 waitSusTime:97 waitSustain:96 clickTimeThresh:154 clickTime:151 clickSpaceThresh:155 clickLoc:152 clickState:153 autoDimTime:271 autoDimPeriod:267 autoDimmed:270 curBright:276 rightENum:150 leftENum:149);
 * evg, evScreen, screens, currentScreen, lastPressure, evScreenSize, totalShmemSize, evs, sessionPressure, sessionPrecision, dimmedBrightness,
 * evRetryMask and the functions are not in it (reconstructed from the original symbols and uses) */
extern EvGlobals *evg;
extern EvScreen *evScreen;
extern Bounds cursorPin;
extern int screens, currentScreen, curBright;
extern int buttonsTied, mouseHandedness, mouseDelX, mouseDelY, numMouseScales;
extern unsigned char lastPressure;
extern short mouseScaleThresholds[], mouseScaleFactors[];
extern short waitFrameRate, waitFrameTime, waitSusTime, waitSustain;
extern int evScreenSize, totalShmemSize;
extern void *evs;
extern long clickTimeThresh, clickTime;
extern Point clickSpaceThresh, clickLoc;
extern int clickState, autoDimTime, autoDimPeriod, dimmedBrightness, autoDimmed;
extern int sessionPressure, sessionPrecision;
extern short rightENum, leftENum;
extern int evRetryMask;
extern int adb_mouse_present(void);
extern void LLEventPost(int, Point, NXEventData *);
extern void SetCurBrightness(int), UndoAutoDim(void);
extern void evdispatch(EvCmd, int, int);
/* plan 736 END */

/* Implementation Constants */

#define INITX		100	/* Initial mouse position */
#define INITY		100

#define INITEVENTNUM	13	/* Where event numbers start */

#define	DCLICKTIME	30	/* Default ticks for a click */
#define	DCLICKSPACE	3	/* Default pixel threshold for clicks */

#define DAUTODIMPERIOD	(67*60*30)	/* Default dim time: Half an hour */

/* plan 736 (D024): NeXTMach lines 47-97 removed (not in the 1997 kernel) */
static int   initNumMouseScales = 5;
static short initMouseScaleThresholds[] = { 2, 3, 4, 5, 6 };
static short initMouseScaleFactors[] = { 2, 4, 6, 8, 10 };
/* plan 736 (D024, D165) BEGIN: MoveTheCursor */

static char *ev_shmem_cursor = 0;
static char evCoalesce[4][4] = {
    { EVNOP,  EVHIDE, EVSHOW, EVMOVE },
    { EVHIDE, EVHIDE, EVNOP,  EVSHOW },
    { EVSHOW, EVNOP,  EVSHOW, EVSHOW },
    { EVMOVE, EVHIDE, EVSHOW, EVMOVE }
};
static int evBrightness;
static int ev_adb_mouse;

static int ev_point_to_screen(Point);
static void ev_wait_frame(int);

void MoveTheCursor(Point p, int mask)
{
    int newscreen = -1;
    volatile Bounds *screenBounds;
    EvScreen *es;
    (void)&p;
    if (!screens) return;
    es = evScreen;
    screenBounds = &((EvScreen *)(currentScreen * sizeof(EvScreen) + (int)es))->bounds;
    if (!(p.x >= screenBounds->minx &&
          p.x < screenBounds->maxx &&
          p.y >= screenBounds->miny &&
          p.y < screenBounds->maxy)) {
        newscreen = ev_point_to_screen(p);
        if (newscreen < 0) {
            p.x = (p.x < cursorPin.minx) ? cursorPin.minx :
                  ((p.x > cursorPin.maxx) ? cursorPin.maxx : p.x);
            p.y = (p.y < cursorPin.miny) ? cursorPin.miny :
                  ((p.y > cursorPin.maxy) ? cursorPin.maxy : p.y);
        }
    }
    if (*(int *)&p == *(int *)&evg->cursorLoc) return;
    evg->cursorLoc = p;
    if (newscreen >= 0) {
        evdispatch(1, currentScreen, 0);
        currentScreen = newscreen;
        cursorPin = evScreen[currentScreen].bounds;
        cursorPin.maxx--;
        cursorPin.maxy--;
        evdispatch(2, currentScreen, 0);
    } else {
        evdispatch(3, currentScreen, 0);
    }
    if (evg->movedMask) {
        if ((evg->movedMask & (1 << 6)) && (evg->buttons & (1 << 2)))
            LLEventPost(6, p, 0);
        else if ((evg->movedMask & (1 << 7)) && (evg->buttons & 1))
            LLEventPost(7, p, 0);
        else if (evg->movedMask & (1 << 5))
            LLEventPost(5, p, 0);
    }
    if (evg->mouseRectValid &&
        !(p.x >= evg->mouseRect.minx && p.x < evg->mouseRect.maxx &&
          p.y >= evg->mouseRect.miny && p.y < evg->mouseRect.maxy)) {
        if (evg->mouseRectValid) {
            LLEventPost(9, evg->cursorLoc, 0);
            evg->mouseRectValid = 0;
        }
    }
}
/* plan 736 END */

/******************************************************************************
	process_mouse_event

	is called when a mouse event is ready to be taken
	out of the preQueue.  It can only be called when
	the cursorSema has been verified to be clear,
	and can only be called from interrupt level (i.e.,
	it cannot itself be interrupted by a mouse interrupt).
	
	A mouse event in the preQueue is basically a status
	report; it so happens we only receive it when something
	(button state or position) has changed.  Thus, this routine goes
	through and tries to find what has changed, and then
	acts on it.  It acts on button state changes by immediately
	posting the appropriate event; for motion, however,
	all it does is accumulate the motion into the globals
	mouseDelX and mouseDelY.  The vertical retrace routine
	will come along later and translate those variables into
	cursor motion.
******************************************************************************/

/* plan 736 (D024, D165) BEGIN: process_mouse_event */
void process_mouse_event(struct mouse *me)
{
    register int cursorDeltaX, cursorDeltaY;
    
    if (buttonsTied) {
    	me->button_left &= me->button_right;
	me->button_right = 1;
    }
    else
	if (mouseHandedness) {
	    int temp = me->button_left;
	    me->button_left = me->button_right;
	    me->button_right = temp;
	}

    /* Generate any button-related events */
    if (((evg->buttons & LB)!=0) != (!me->button_left)) {
	if (!me->button_left) {
	    lastPressure = 255;
	    LLEventPost(NX_LMOUSEDOWN, evg->cursorLoc, NULL);
	    evg->buttons |= LB;
	} else {
	    lastPressure = 0;
	    LLEventPost(NX_LMOUSEUP, evg->cursorLoc, NULL);
	    evg->buttons &= ~LB;
	}
        evg->dontCoalesce = evg->dontWantCoalesce;
        if (evg->dontCoalesce)
            evg->eventFlags |= NX_NONCOALSESCEDMASK;
        else
            evg->eventFlags &= ~NX_NONCOALSESCEDMASK;
    }

    if (((evg->buttons & RB)!=0) != (!me->button_right)) {
    	if (!me->button_right) {
	    LLEventPost(NX_RMOUSEDOWN, evg->cursorLoc, NULL);
	    evg->buttons |= RB;
	} else {
	    LLEventPost(NX_RMOUSEUP, evg->cursorLoc, NULL);
	    evg->buttons &= ~RB;
	}
    }

    /* Figure cursor movement */
    evg->cursorSema = 1;
    if (me->delta_x || me->delta_y) {
	cursorDeltaX = me->delta_x;
	/* Sign-extend by hand */
	if (cursorDeltaX & ((int)0x00000040))
	    cursorDeltaX |= (int)0xffffff80;
	mouseDelX -= cursorDeltaX;
	cursorDeltaY = me->delta_y;
	/* Sign-extend by hand */
	if (cursorDeltaY & ((int)0x00000040))
	    cursorDeltaY |= (int)0xffffff80;
	mouseDelY -= cursorDeltaY;
    }
    evg->cursorSema = 0;
} /* process_mouse_event */
/* plan 736 (D024): NeXTMach line 175 removed (a blank line) */
/* plan 736 END */

/******************************************************************************
	mouse_motion

	is called from the vertical retrace handler if either
	of mouseDelX or mouseDelY is nonzero.  It moves the cursor,
	and generates any appropriate events (mouse-moved,
	mouse-dragged, and mouse-exited events may all be generated).
******************************************************************************/

/* plan 736 (D024, D165) BEGIN: AnimateWaitCursor, HideWaitCursor, ShowWaitCursor, evsetup_screens, mouse_motion */
void mouse_motion(void)
{
    Point p;
    int x, y, index, shift;
    if (!evg->cursorSema) {
        if (!(evg->movedMask & (1 << 17))) {
            x = (mouseDelX < 0) ? -mouseDelX : mouseDelX;
            y = (mouseDelY < 0) ? -mouseDelY : mouseDelY;
            x += y;
            shift = ev_adb_mouse != 0;
            if (x > (mouseScaleThresholds[0] << shift)) {
                for (index = 1; index < numMouseScales; index++)
                    if (x <= (mouseScaleThresholds[index] << shift))
                        break;
                index--;
                mouseDelX *= mouseScaleFactors[index];
                mouseDelY *= mouseScaleFactors[index];
            }
        }
        evg->movedMask &= ~((1 << 16) | (1 << 17));
        p.x = evg->cursorLoc.x + mouseDelX;
        p.y = evg->cursorLoc.y + mouseDelY;
        MoveTheCursor(p, evg->movedMask);
        mouseDelX = mouseDelY = 0;
    }
}

/* The "waitFrameNum" global is passed to devices to indiacte the state of the
 * wait cursor.  If zero, it indicates the wait cursor to be "off".  Above
 * zero indicates the frame number of the cursor being set.  Some devices may
 * wish to cache these cursor images the first time they are seen to save
 * cpu cycles converting the cursor from 2 bits/pixel.
 */
void ShowWaitCursor(void)
{
    evg->waitCursorUp = 1;
    ev_wait_frame(1);
    waitFrameTime = waitFrameRate + 1;
    waitSusTime = waitSustain;
}

void HideWaitCursor(void)
{
    evg->waitCursorUp = 0;
    ev_wait_frame(0);
}

void AnimateWaitCursor(void)
{
    ev_wait_frame(evg->frame + 1);
    waitFrameTime = waitFrameRate;
}

void evsetup_screens(struct evioSetScreen *arg)
{
    register int screenIndex = arg->screenIndex;
    EvScreen *screen;
    if (!evScreen) {
        evScreenSize = arg->totalScreens * sizeof(EvScreen);
        evScreen = (EvScreen *)kalloc(evScreenSize);
        bzero((void *)evScreen, evScreenSize);
        totalShmemSize = sizeof(EvOffsets) + sizeof(EvGlobals);
    }
    evScreen[screenIndex].bounds = arg->screenBounds;
    screen = (EvScreen *)(screenIndex * sizeof (EvScreen) + (int)evScreen);
    screen->shmemSize = arg->screenShmemSize;
    totalShmemSize += screen->shmemSize;
    arg->totalShmemSize = totalShmemSize;
}
/* plan 736 END */

/******************************************************************************
	ev_register_screen adds a new screen to the screen list.  Returns
	token to be used when unregistering the driver via
	ev_unregister_screen.
******************************************************************************/

/* plan 736 (D024, D165) BEGIN: ev_register_screen */
int ev_register_screen(EvScreen **out, void *priv,
    int (*move)(struct _evScreen *, Point, int),
    int (*hide)(struct _evScreen *),
    int (*show)(struct _evScreen *, Point, int),
    int (*level)(struct _evScreen *, int))
{
    EvScreen *screen;
    if (!evg) return -1;
    if (!screens) ev_shmem_cursor = evs;
    screen = &evScreen[screens];
    *out = screen;
    screen->priv = priv;
    screen->move = move;
    screen->hide = hide;
    screen->show = show;
    screen->level = level;
    if (screen->shmemSize) screen->shmemPtr = ev_shmem_cursor;
    ev_shmem_cursor += screen->shmemSize;
    return screens++ + SCREENTOKEN;
}
/* plan 736 END */

/******************************************************************************
	ev_unregister_screen is called by device drivers when they are about
	to close.  This sets all procedure vectors in the screen array to
	NULL so they won't be called.  If the screen being disabled has the
	cursor on it, the cursor is first hidden.
******************************************************************************/

/* plan 736 (D024, D165) BEGIN: InitMouse, InitMouseVars, ResetMouse, StartCursor, TermMouse, ev_point_to_screen, ev_unregister_screen, ev_wait_frame, evdispatch, evretry */
int ev_unregister_screen(int token)
{
    if (!evg) return -1;
    token -= SCREENTOKEN;
    if (token < 0 || token >= screens) return -1;
    evdispatch(1, currentScreen, 0);
    evScreen[token].move = 0;
    evScreen[token].hide = 0;
    evScreen[token].show = 0;
    evScreen[token].level = 0;
    evdispatch(2, currentScreen, 0);
    return 0;
}

void InitMouseVars(void)
{
    short i;
    clickTimeThresh = 30;
    clickSpaceThresh.x = clickSpaceThresh.y = 3;
    clickTime = -30;
    clickLoc.x = clickLoc.y = -3;
    clickState = 1;
    autoDimTime = evg->VertRetraceClock + 120600;
    autoDimPeriod = 120600;
    dimmedBrightness = 15;
    buttonsTied = 1;
    mouseHandedness = 0;
    numMouseScales = initNumMouseScales;
    for (i = initNumMouseScales; i-- != 0;) {
        mouseScaleThresholds[i] = initMouseScaleThresholds[i];
        mouseScaleFactors[i] = initMouseScaleFactors[i];
    }
    mouseDelX = mouseDelY = 0;
}

void InitMouse(int n)
{
    short i;
    for (i = n; i-- != 0;) {
        evg->lleq[i].event.type = 0;
        evg->lleq[i].event.time = 0;
        evg->lleq[i].event.flags = 0;
        evg->lleq[i].sema = 0;
        evg->lleq[i].next = i + 1;
    }
    evg->LLELast = evg->lleq[n - 1].next = 0;
    evg->LLEHead = evg->LLETail = evg->lleq[evg->LLELast].next;
    evg->buttons = 0;
    evg->eNum = 13;
    evg->eventFlags = 0;
    evg->VertRetraceClock = 1;
    evg->cursorLoc.x = 100;
    evg->cursorLoc.y = 100;
    screens = 0;
    sessionPressure = 0;
    sessionPrecision = 0;
    lastPressure = 0;
    evg->dontCoalesce = 0;
    evg->dontWantCoalesce = 0;
    evg->wantPressure = 0;
    evg->wantPrecision = 0;
    leftENum = rightENum = 0;
    evg->mouseRectValid = 0;
    evg->movedMask = 0;
    evg->cursorSema = 0;
    autoDimmed = 0;
    mouseDelX = mouseDelY = 0;
    ev_adb_mouse = adb_mouse_present();
    InitMouseVars();
}

void TermMouse(void)
{
    if (screens) evdispatch(1, currentScreen, 0);
}

void ResetMouse(void)
{
    if (autoDimmed) UndoAutoDim();
    InitMouseVars();
}

/* StartCursor is the first call to display the initial cursor. It should
 * never be called again.
 */
int StartCursor(void)
{
    if (!screens) return -1;
    currentScreen = ev_point_to_screen(evg->cursorLoc);
    if (currentScreen < 0) return -1;
    cursorPin = evScreen[currentScreen].bounds;
    cursorPin.maxx--;
    cursorPin.maxy--;
    SetCurBrightness(curBright);
    evdispatch(2, currentScreen, 0);
    return 0;
}

void evdispatch(EvCmd cmd, int screen, int arg)
{
    EvScreen *esp = &evScreen[screen];
    int err = 0;
    int (*proc)();

    if (cmd < EVLEVEL || esp->retry.cursor) {
	esp->retry.cursor = evCoalesce[esp->retry.cursor][cmd & 3];
	switch (esp->retry.cursor) {
	case EVMOVE:
	    proc = esp->move;
	    if (proc)
		err = (*proc)(esp, evg->cursorLoc, evg->frame);
	    break;
	case EVSHOW:
	    proc = esp->show;
	    if (proc)
		err = (*proc)(esp, evg->cursorLoc, evg->frame);
	    break;
	case EVHIDE:
	    proc = esp->hide;
	    if (proc)
		err = (*proc)(esp);
	    break;
	}
	if (!err)
	    esp->retry.cursor = 0;
    }
    if (cmd == EVLEVEL)
	evBrightness = arg;
    if (cmd == EVLEVEL || esp->retry.level) {
	proc = esp->level;
	if (proc) {
	    esp->retry.level = (*proc)(esp, evBrightness);
	    err |= esp->retry.level;
	}
    }
    {
	int bit = 1 << screen;
	int mask = evRetryMask & ~bit;
	if (err)
	    mask |= bit;
	evRetryMask = mask;
    }
}

void evretry(void)
{
    unsigned i, m;

    for (i = 0, m = evRetryMask; m && i < screens; i++, m >>= 1)
	if (m & 1)
	    evdispatch(EVNOP, i, 0);
}

static void ev_wait_frame(int frame)
{
    evg->frame = frame > 3 ? 1 : frame;
    evdispatch(3, currentScreen, 0);
}

static int ev_point_to_screen(Point p)
{
    short i;
    for (i = screens; i-- != 0;) {
        if (p.x >= evScreen[i].bounds.minx && p.x < evScreen[i].bounds.maxx &&
            p.y >= evScreen[i].bounds.miny && p.y < evScreen[i].bounds.maxy)
            return i;
    }
    return -1;
}
/* plan 736 END */

/* plan 736 (D024): NeXTMach lines 571-586 removed (a blank line) */