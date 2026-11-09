#include "sys/param.h"
#include "sys/buf.h"
#include "sys/vm.h"

#include "dev/busvar.h"	/* plan 777 (D104): mkioconf writes nextdev/busvar.h */

#define C (caddr_t)

extern struct bus_driver fcdriver;
extern struct bus_driver scdriver;
extern struct bus_driver ocdriver;
extern struct bus_driver endriver;
extern struct bus_driver dspdriver;
extern struct bus_driver npdriver;
extern struct bus_driver sounddriver;

struct bus_ctrl bus_cinit[] = {
  /* driver        ctrl   ipl         address */
  {  &fcdriver,       0,    0,   C 0x02014100 },
  {  &scdriver,       0,    0,   C 0x02014000 },
  {  &ocdriver,       0,    0,   C 0x02012000 },
  0
};

struct bus_device bus_dinit[] = {
  /* driver      unit ctrl slave ipl  dk       flags       address  name */
  {  &fcdriver,     0,   0,    0,  0, -1,          0, C 0x00000000, "fd" },
  {  &scdriver,     0,   0,  '?',  0, -1,          0, C 0x00000000, "sd" },
  {  &scdriver,     1,   0,  '?',  0, -1,          0, C 0x00000000, "sd" },
  {  &scdriver,     2,   0,  '?',  0, -1,          0, C 0x00000000, "sd" },
  {  &scdriver,     3,   0,  '?',  0, -1,          0, C 0x00000000, "sd" },
  {  &scdriver,     4,   0,  '?',  0, -1,          0, C 0x00000000, "sd" },
  {  &scdriver,     5,   0,  '?',  0, -1,          0, C 0x00000000, "sd" },
  {  &scdriver,     6,   0,  '?',  0, -1,          0, C 0x00000000, "sd" },
  {  &scdriver,     0,   0,  '?',  0,  0,          0, C 0x00000000, "st" },
  {  &scdriver,     1,   0,  '?',  0,  0,          0, C 0x00000000, "st" },
  {  &scdriver,     0,   0,  '?',  0,  0,          0, C 0x00000000, "sg" },
  {  &scdriver,     1,   0,  '?',  0,  0,          0, C 0x00000000, "sg" },
  {  &scdriver,     2,   0,  '?',  0,  0,          0, C 0x00000000, "sg" },
  {  &scdriver,     3,   0,  '?',  0,  0,          0, C 0x00000000, "sg" },
  {  &ocdriver,     0,   0,    0,  0, -1,          0, C 0x00000000, "od" },
  {  &ocdriver,     1,   0,    1,  0, -1,          0, C 0x00000000, "od" },
  {  &endriver,     0,  -1,   -1,  0,  0,          0, C 0x02006000, "en" },
  {  &dspdriver,    0,  -1,   -1,  0,  0,          0, C 0x020000d0, "dsp" },
  {  &npdriver,     0,  -1,   -1,  0,  0,          0, C 0x0200f000, "np" },
  {  &sounddriver,   0,  -1,   -1,  0,  0,          0, C 0x0200e000, "sound" },
  0
};

extern pty_init();
extern venip_config();
extern zsintsetup();
extern enintsetup();

struct pseudo_init pseudo_inits[] = {
	32,	pty_init,
	1,	venip_config,
	2,	zsintsetup,
	1,	enintsetup,
	0,	0,
};
