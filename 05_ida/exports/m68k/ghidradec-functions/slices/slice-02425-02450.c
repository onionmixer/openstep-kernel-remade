/* GHIDRADEC_FUNCTION index=2425 start=0x4091b62 */

byte _rtc_real_read(char param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  *_scr2 = *_scr2 & 0xfffff9ff | 0x100;
  _delay(1);
  iVar3 = 0;
  do {
    uVar1 = *_scr2 & 0xfffffbff;
    if (param_1 < '\0') {
      uVar1 = uVar1 | 0x400;
    }
    *_scr2 = uVar1;
    _delay(1);
    *_scr2 = uVar1 | 0x200;
    _delay(1);
    *_scr2 = CONCAT22((sword)(uVar1 >> 0x10),(sword)(uVar1 | 0x200)) & 0xfffffdff;
    param_1 = param_1 << 1;
    _delay(1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  bVar2 = 0;
  iVar3 = 0;
  do {
    uVar1 = *_scr2;
    *_scr2 = uVar1 & 0xfffffbff | 0x200;
    _delay(1);
    bVar2 = bVar2 << 1;
    *_scr2 = uVar1 & 0xfffffbff;
    _delay(1);
    if ((*_scr2 & 0x400) != 0) {
      bVar2 = bVar2 | 1;
    }
    _delay(1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  *_scr2 = *_scr2 & 0xfffff8ff;
  return bVar2;
}
/* GHIDRADEC_FUNCTION index=2426 start=0x4091ca2 */

void _rtc_blkread(undefined param_1,undefined4 param_2,undefined4 param_3)

{
  _rtc_real_blkread(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=2427 start=0x4091cc0 */

undefined4 _rtc_real_blkread(char param_1,byte *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  
  *_scr2 = *_scr2 & 0xfffff9ff | 0x100;
  _delay(1);
  iVar4 = 0;
  do {
    uVar1 = *_scr2 & 0xfffffbff;
    if (param_1 < '\0') {
      uVar1 = uVar1 | 0x400;
    }
    *_scr2 = uVar1;
    _delay(1);
    *_scr2 = uVar1 | 0x200;
    _delay(1);
    *_scr2 = CONCAT22((sword)(uVar1 >> 0x10),(sword)(uVar1 | 0x200)) & 0xfffffdff;
    param_1 = param_1 << 1;
    _delay(1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  while (0 < param_3) {
    param_3 = param_3 + -1;
    bVar3 = 0;
    iVar4 = 0;
    do {
      uVar1 = *_scr2;
      *_scr2 = uVar1 & 0xfffffbff | 0x200;
      _delay(1);
      bVar3 = bVar3 << 1;
      *_scr2 = uVar1 & 0xfffffbff;
      _delay(1);
      if ((*_scr2 & 0x400) != 0) {
        bVar3 = bVar3 | 1;
      }
      _delay(1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    *param_2 = bVar3;
    param_2 = param_2 + 1;
  }
  uVar1 = *_scr2;
  uVar2 = uVar1 & 0xfffff8ff;
  *_scr2 = uVar2;
  return CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=2428 start=0x4091ea2 */

void _hardclock_init(void)

{
  sqword sVar1;
  
  sVar1 = _clock_value(1);
  sVar1 = sVar1 + CONCAT44(_ns_per_tick,dword_40C2448);
  dword_40B55B8 = (undefined4)sVar1;
  dword_40B55B4 = (undefined4)((qword)sVar1 >> 0x20);
  _ns_abstimeout(_m68k_hardclock,0,sVar1,1);
  return;
}
/* GHIDRADEC_FUNCTION index=2429 start=0x4091eea */

void _statclock_init(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2430 start=0x4091ef2 */

void _m68k_hardclock(void)

{
  uint uVar1;
  bool bVar2;
  sqword sVar3;
  
  _clock_interrupt(_tick,((word)((word)_hardclock_ps ^ 0x2000) & 0x3fff) >> 0xd,
                   -(int)-((_hardclock_ps & 0x700) == 0));
  _hardclock(_hardclock_pc,_hardclock_ps);
  bVar2 = CARRY4(dword_40C2448,dword_40B55B8);
  dword_40B55B8 = dword_40C2448 + dword_40B55B8;
  dword_40B55B4 = _ns_per_tick + dword_40B55B4 + (uint)bVar2;
  while( true ) {
    sVar3 = _clock_value(1);
    uVar1 = (uint)((qword)sVar3 >> 0x20);
    bVar2 = (uint)sVar3 < dword_40B55B8;
    if ((uVar1 < dword_40B55B4 || bVar2 && uVar1 == dword_40B55B4) ||
        sVar3 == CONCAT44(bVar2 + dword_40B55B4,dword_40B55B8)) break;
    bVar2 = CARRY4(dword_40C2448,dword_40B55B8);
    dword_40B55B8 = dword_40C2448 + dword_40B55B8;
    dword_40B55B4 = _ns_per_tick + dword_40B55B4 + (uint)bVar2;
  }
  _ns_abstimeout(_m68k_hardclock,0,dword_40B55B4,dword_40B55B8,1);
  return;
}
/* GHIDRADEC_FUNCTION index=2431 start=0x4091fca */

byte _clock_timer_init(void)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  _startrtclock();
  dword_40B55AC = 0;
  dword_40B55B0 = 0;
  uVar2 = _rtc_get();
  _time = SUB84((qword)uVar2 >> 0x20,0);
  dword_40AF7F0 = (undefined4)uVar2;
  uVar2 = _timeval_to_ns_time(_time);
  uVar3 = _clock_value(1);
  dword_40B55B0 = (uint)uVar2 - (uint)uVar3;
  dword_40B55AC =
       (int)((qword)uVar2 >> 0x20) -
       ((uint)((uint)uVar2 < (uint)uVar3) + (int)((qword)uVar3 >> 0x20));
  cVar1 = _dma_chip < 0x139;
  if (_dma_chip == 0x139) {
    *_scr2 = *_scr2 & 0xffff7fff;
  }
  _install_scanned_intr(0x1d60,sub_4091E18,0);
  *_timer_csr = 0;
  *_timer_low = 0xff;
  *_timer_high = 0xff;
  *_timer_low = 0xff;
  *_timer_csr = 0xc0;
  *_timer_low = 0xff;
  *_timer_high = 0xff;
  return cVar1 << 4 | 8;
}
/* GHIDRADEC_FUNCTION index=2432 start=0x40920aa */

undefined8 _clock_value(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  uVar1 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
          0xfffff;
  if ((((uVar1 ^ *_event_middle) & 0x80000) != 0) &&
     (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
    *_event_high = *_event_high + 1;
  }
  uVar1 = uVar1 | *_event_middle;
  uVar3 = uVar1 * 1000;
  iVar2 = ((((*_event_high << 5 | (uint)*_event_middle >> 0x1b) * 4 +
             (uint)(uVar1 * 0x20 < uVar1) * -4 + *_event_high * -3 +
             (uint)CARRY4(uVar1 * 0x1f,uVar1 * 0x1f) * 2 + (uint)CARRY4(uVar1 * 0x3e,uVar1 * 0x3e))
            * 2 + (uint)CARRY4(uVar1,uVar1 * 0x7c) * 2 + (uint)CARRY4(uVar1 * 0x7d,uVar1 * 0x7d)) *
           2 + (uint)CARRY4(uVar1 * 0xfa,uVar1 * 0xfa)) * 2 + (uint)CARRY4(uVar1 * 500,uVar1 * 500);
  if (param_1 == 0) {
    bVar4 = CARRY4(dword_40B55B0,uVar3);
    uVar3 = dword_40B55B0 + uVar3;
    iVar2 = dword_40B55AC + iVar2 + (uint)bVar4;
  }
  else if (param_1 != 1) {
    iVar2 = 0;
    uVar3 = 0;
  }
  return CONCAT44(iVar2,uVar3);
}
/* GHIDRADEC_FUNCTION index=2433 start=0x40921ce */

void _set_clock(int param_1,int param_2,uint param_3)

{
  undefined8 uVar1;
  undefined auStack_c [8];
  
  if (param_1 == 0) {
    uVar1 = _clock_value(1);
    dword_40B55B0 = param_3 - (uint)uVar1;
    dword_40B55AC = param_2 - ((uint)(param_3 < (uint)uVar1) + (int)((qword)uVar1 >> 0x20));
    _ns_time_to_timeval(param_2,param_3,auStack_c);
    _rtc_set(auStack_c);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2434 start=0x4092232 */

undefined * _clock_attributes(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined *)0x40ad8da;
  }
  else if (param_1 == 1) {
    puVar1 = DAT_40ad8ca;
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=2435 start=0x4092258 */

undefined * _timer_attributes(int param_1)

{
  undefined *puVar1;
  
  puVar1 = DAT_40ad8ea;
  if (param_1 != 0) {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=2436 start=0x409226e */

void _set_timer_expire_func(undefined4 param_1,undefined4 param_2)

{
  dword_40B55C0 = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2437 start=0x409227e */

void __set_timer_expire_func(undefined4 param_1,undefined4 param_2)

{
  dword_40B55BC = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2438 start=0x409228e */

void _set_timer(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _ns_untimeout(dword_40B55C0,0);
  _ns_timeout(dword_40B55C0,0,param_2,param_3,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2439 start=0x40922cc */

void __set_timer(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (uint)(CONCAT44(param_2 % 1000,param_3) / 1000);
  if (param_1 == 0) {
    if (uVar1 < 500) {
      uVar1 = 500;
    }
    else if (0xffff < uVar1) {
      uVar1 = 0xffff;
    }
    *_timer_csr = 0;
    *_timer_low = 0xff;
    *_timer_high = (char)(uVar1 >> 8);
    *_timer_low = (char)uVar1;
    *_timer_csr = 0xc0;
    *_timer_low = 0xff;
    *_timer_high = 0xff;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2440 start=0x4092372 */

void _clear_timer(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2441 start=0x409237a */

void _delay(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *_event_middle;
  uVar1 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
          0xfffff;
  if (((uVar1 ^ uVar3) & 0x80000) != 0) {
    uVar3 = uVar3 + 0x80000;
  }
  do {
    uVar4 = *_event_middle;
    uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
            0xfffff;
    if (((uVar2 ^ uVar4) & 0x80000) != 0) {
      uVar4 = uVar4 + 0x80000;
    }
  } while ((uVar2 | uVar4) - (uVar1 | uVar3) < param_1 + 1U);
  return;
}
/* GHIDRADEC_FUNCTION index=2442 start=0x4092436 */

void _cnopen(undefined2 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  word wVar3;
  sword sVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = _ttynty(_cons_tp);
  wVar3 = *(word *)(_cons_tp + 0x38);
  iVar1 = *_active_u;
  iVar6 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
  if ((*(byte *)(iVar1 + 0x16) & 0x40) == 0) {
    if ((*(byte *)(iVar1 + 0x28) & 0x40) != 0) goto loc_409257E;
    *(int *)((int)_active_u + 0x15e) = _cons_tp;
    *(undefined2 *)((int)_active_u + 0x162) = param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)(iVar6 + 0xe) + 8);
    *(int *)(*(int *)(*(int *)(iVar6 + 0xe) + 8) + 8) = _cons_tp;
    sVar4 = *(sword *)(_cons_tp + 0x42);
    if (sVar4 == 0) {
      _enterpgrp(iVar1,(int)*(sword *)(iVar1 + 0x30),0);
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0xe);
      *(undefined2 *)(_cons_tp + 0x42) = *(undefined2 *)(*(int *)(iVar6 + 0xe) + 0xe);
    }
    else if (sVar4 != *(sword *)(iVar1 + 0x2e)) {
      _enterpgrp(iVar1,(int)sVar4,0);
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar6 + 0xe) + 8);
    if ((((iVar1 != *(int *)(iVar2 + 4)) || (*(int *)(iVar2 + 8) != 0)) ||
        (*(int *)(iVar5 + 8) != 0)) || ((*(byte *)(iVar6 + 0x16) & 0x40) != 0)) goto loc_409257E;
    *(int *)((int)_active_u + 0x15e) = _cons_tp;
    *(undefined2 *)((int)_active_u + 0x162) = param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)(iVar6 + 0xe) + 8);
    *(int *)(*(int *)(*(int *)(iVar6 + 0xe) + 8) + 8) = _cons_tp;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0xe);
    *(undefined2 *)(_cons_tp + 0x42) = *(undefined2 *)(*(int *)(iVar6 + 0xe) + 0xe);
  }
  *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) | 0x40;
loc_409257E:
  (**(code **)(_cdevsw + (uint)(wVar3 >> 8) * 0x2c))((int)(sword)wVar3,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2443 start=0x40925ac */

void _cnread(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(DAT_40b0ac8 + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))
            ((int)(sword)*(word *)(_cons_tp + 0x38),param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2444 start=0x40925e8 */

void _cnwrite(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(DAT_40b0acc + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))
            ((int)(sword)*(word *)(_cons_tp + 0x38),param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2445 start=0x4092624 */

undefined4 _cnioctl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 == 0x20007471) {
    iVar1 = *_active_u;
    iVar3 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
    _cons_tp = _cons;
    iVar2 = *(int *)(*(int *)(iVar3 + 0xe) + 8);
    if (iVar1 == *(int *)(iVar2 + 4)) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined2 *)(*(int *)(*(int *)(iVar3 + 0xe) + 8) + 0xc) = 0;
    }
    *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) & 0xbf;
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(DAT_40b0ad0 + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))
                      ((int)(sword)*(word *)(_cons_tp + 0x38),param_2,param_3,param_4);
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2446 start=0x40926be */

void _cnselect(undefined4 param_1,undefined4 param_2)

{
  (*(code *)(&DAT_40b0adc)[(uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0xb])
            ((int)(sword)*(word *)(_cons_tp + 0x38),param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2447 start=0x40926fa */

void _cngetc(void)

{
  (**(code **)(DAT_40b0ae4 + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))
            ((int)(sword)*(word *)(_cons_tp + 0x38));
  return;
}
/* GHIDRADEC_FUNCTION index=2448 start=0x4092732 */

void _cnputc(char param_1)

{
  (**(code **)(DAT_40b0ae8 + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))
            ((int)(sword)*(word *)(_cons_tp + 0x38),(int)param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2449 start=0x4092778 */

int _isbad(int param_1,int param_2,int param_3,int param_4)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  
  param_4 = param_4 + param_3 * 0x100 + param_2 * 0x10000;
  iVar3 = 0;
  do {
    sVar1 = *(sword *)(param_1 + 8 + iVar3 * 4);
    iVar2 = CONCAT22(sVar1,*(undefined2 *)(param_1 + 10 + iVar3 * 4));
    if (iVar2 == param_4) {
      return iVar3;
    }
  } while (((iVar2 <= param_4) && (-1 < sVar1)) && (iVar3 = iVar3 + 1, iVar3 < 0x7e));
  return -1;
}

