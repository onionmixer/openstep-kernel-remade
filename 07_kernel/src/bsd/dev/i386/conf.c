/*
 * bsd/dev/i386/conf.c (plan 397).
 *
 * UNIX device switch tables of the OPENSTEP 4.2 kernel, __data
 * [0x1e2cf4, 0x1e36a0): bdevsw 24 x 24 B, nblkdev, cdevsw 43 x 44 B, nchrdev.
 * Written for this project from the original bytes (D024); Darwin 0.1
 * kernel/bsd/dev/i386/conf.c was consulted for the slot plan only.  The
 * entries use the OPENSTEP SDK <sys/conf.h> structures (6 and 11 fields).
 */
#import <sys/param.h>
#import <sys/systm.h>
#import <sys/buf.h>
#import <sys/ioctl.h>
#import <sys/tty.h>
#import <sys/conf.h>

extern int	nulldev();
extern int	seltrue();

extern int	sdopen(), sdclose(), sdstrategy(), sdread(), sdwrite(), sdioctl(), sdsize();

struct bdevsw	bdevsw[] =
{
	{ nodev,	nodev,		nodev,		nodev,	
	  nodev,	0 },		/* 0*/
	NO_BDEVICE,							/* 1*/
	{ nodev,	nodev,		nodev,		nodev,	
	  nodev,	0 },		/* 2*/
	NO_BDEVICE,							/* 3*/
	{ nodev,	nodev,		nodev,		nodev,	
	  nodev,	0 },		/* 4*/
	{ nodev,	nodev,		nodev,		nodev,	
	  nodev,	0 },		/* 5*/
	{ sdopen,	sdclose,	sdstrategy,	nodev,	
	  sdsize,	0 },		/* 6*/
	{ nodev,	nodev,		nodev,		nodev,	
	  nodev,	0 },		/* 7*/
	NO_BDEVICE,							/* 8*/
	NO_BDEVICE,							/* 9*/
	NO_BDEVICE,							/*10*/
	NO_BDEVICE,							/*11*/
	NO_BDEVICE,							/*12*/
	NO_BDEVICE,							/*13*/
	NO_BDEVICE,							/*14*/
	NO_BDEVICE,							/*15*/
	NO_BDEVICE,							/*16*/
	NO_BDEVICE,							/*17*/
	NO_BDEVICE,							/*18*/
	NO_BDEVICE,							/*19*/
	NO_BDEVICE,							/*20*/
	NO_BDEVICE,							/*21*/
	NO_BDEVICE,							/*22*/
	NO_BDEVICE,							/*23*/
};

int	nblkdev = sizeof (bdevsw) / sizeof (bdevsw[0]);

extern int	cnopen(), cnread(), cnwrite(), cnioctl(), cnselect(), cngetc(), cnputc();
extern int	syopen(), syread(), sywrite(), syioctl(), syselect();
extern int	mmread(), mmwrite();
extern int	ptsopen(), ptsclose(), ptsread(), ptswrite(), ptsstop(), ptsselect();
extern int	ptcopen(), ptcclose(), ptcread(), ptcwrite(), ptcselect(), ptyioctl();
extern int	logopen(), logclose(), logread(), logioctl(), logselect();
extern int	kmopen(), kmclose(), kmread(), kmwrite(), kmioctl(), kmselect(), kmgetc(), kmputc();
extern int	sgopen(), sgclose(), sgioctl();
extern int	volopen(), volclose(), volioctl();

struct cdevsw	cdevsw[] =
{
    {	/* 0*/
	cnopen,		nulldev,	cnread,		cnwrite,
	cnioctl,	nulldev,	nulldev,	cnselect,
	nodev,		cngetc,		cnputc
    },
    NO_CDEVICE,								/* 1*/
    {	/* 2*/
	syopen,		nulldev,	syread,		sywrite,
	syioctl,	nulldev,	nulldev,	syselect,
	nodev,		nodev,		nodev
    },
    {	/* 3*/
	nulldev,	nulldev,	mmread,		mmwrite,
	nodev,		nulldev,	nulldev,	seltrue,
	nodev,		nodev,		nodev
    },
    {	/* 4*/
	ptsopen,	ptsclose,	ptsread,	ptswrite,
	ptyioctl,	ptsstop,	nulldev,	ptsselect,
	nodev,		nodev,		nodev
    },
    {	/* 5*/
	ptcopen,	ptcclose,	ptcread,	ptcwrite,
	ptyioctl,	nulldev,	nulldev,	ptcselect,
	nodev,		nodev,		nodev
    },
    {	/* 6*/
	logopen,	logclose,	logread,	nodev,
	logioctl,	nodev,		nulldev,	logselect,
	nodev,		nodev,		nodev
    },
    NO_CDEVICE,								/* 7*/
    NO_CDEVICE,								/* 8*/
    NO_CDEVICE,								/* 9*/
    NO_CDEVICE,								/*10*/
    NO_CDEVICE,								/*11*/
    {	/*12*/
	kmopen,		kmclose,	kmread,		kmwrite,
	kmioctl,	nulldev,	nulldev,	kmselect,
	nodev,		kmgetc,		kmputc
    },
    NO_CDEVICE,								/*13*/
    {	/*14*/
	sdopen,		sdclose,	sdread,		sdwrite,
	sdioctl,	nodev,		nulldev,	seltrue,
	nodev,		nodev,		nodev
    },
    NO_CDEVICE,								/*15*/
    NO_CDEVICE,								/*16*/
    NO_CDEVICE,								/*17*/
    NO_CDEVICE,								/*18*/
    NO_CDEVICE,								/*19*/
    NO_CDEVICE,								/*20*/
    NO_CDEVICE,								/*21*/
    NO_CDEVICE,								/*22*/
    NO_CDEVICE,								/*23*/
    NO_CDEVICE,								/*24*/
    NO_CDEVICE,								/*25*/
    NO_CDEVICE,								/*26*/
    NO_CDEVICE,								/*27*/
    NO_CDEVICE,								/*28*/
    NO_CDEVICE,								/*29*/
    NO_CDEVICE,								/*30*/
    NO_CDEVICE,								/*31*/
    NO_CDEVICE,								/*32*/
    {	/*33*/
	sgopen,		sgclose,	nodev,		nodev,
	sgioctl,	nodev,		nodev,		nodev,
	nodev,		nodev,		nodev
    },
    NO_CDEVICE,								/*34*/
    NO_CDEVICE,								/*35*/
    NO_CDEVICE,								/*36*/
    NO_CDEVICE,								/*37*/
    NO_CDEVICE,								/*38*/
    NO_CDEVICE,								/*39*/
    NO_CDEVICE,								/*40*/
    NO_CDEVICE,								/*41*/
    {	/*42*/
	volopen,	volclose,	nodev,		nodev,
	volioctl,	nodev,		nulldev,	seltrue,
	nodev,		nodev,		nodev
    },
};

int	nchrdev = sizeof (cdevsw) / sizeof (cdevsw[0]);
