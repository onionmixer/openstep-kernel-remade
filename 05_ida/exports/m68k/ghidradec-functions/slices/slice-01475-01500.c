/* GHIDRADEC_FUNCTION index=1475 start=0x404e3f8 */

byte _ns_timer_init(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = '\0';
  cVar3 = '\x01';
  cVar4 = '\0';
  bVar5 = 0;
  __set_timer_expire_func(0,sub_404E458);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=1476 start=0x404e420 */

void _ns_hardclock_init(void)

{
  dword_40C2448 = 1000000000 / _hz;
  _ns_per_tick = (int)-(dword_40C2448 < 0);
  _hardclock_init(_ns_per_tick,dword_40C2448);
  return;
}
/* GHIDRADEC_FUNCTION index=1477 start=0x404e53a */

void _ns_timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  sqword sVar1;
  
  sVar1 = _clock_value(1);
  _ns_abstimeout(param_1,param_2,sVar1 + CONCAT44(param_3,param_4),param_5);
  return;
}
/* GHIDRADEC_FUNCTION index=1478 start=0x404e57e */

undefined4
_ns_abstimeout(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 extraout_D0u;
  undefined2 uVar4;
  undefined4 in_D0;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  byte bVar14;
  undefined8 uVar15;
  
  puVar3 = _ns_callfree;
  uVar4 = (undefined2)((uint)in_D0 >> 0x10);
  if (_ns_callfree == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aNsAbstimeoutTa);
  }
  puVar1 = _ns_callfree + 5;
  _ns_callfree = (undefined4 *)*_ns_callfree;
  *puVar1 = param_5;
  puVar3[3] = param_2;
  puVar3[4] = param_1;
  puVar1 = &_ns_calltodo;
  for (puVar2 = _ns_calltodo; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    uVar8 = puVar2[1];
    uVar4 = (undefined2)(uVar8 - (((uint)puVar2[2] < param_4) + param_3) >> 0x10);
    if (param_3 <= uVar8 && ((uint)puVar2[2] >= param_4 || uVar8 != param_3)) break;
    puVar1 = puVar2;
  }
  *puVar1 = puVar3;
  *puVar3 = puVar2;
  puVar3[1] = param_3;
  puVar3[2] = param_4;
  cVar13 = puVar3 < _ns_calltodo;
  cVar12 = SBORROW4((int)puVar3,(int)_ns_calltodo);
  cVar10 = (int)puVar3 - (int)_ns_calltodo < 0;
  cVar11 = '\0';
  bVar14 = cVar13;
  if (puVar3 == _ns_calltodo) {
    uVar15 = _clock_value(1);
    uVar5 = (uint)((qword)uVar15 >> 0x20);
    uVar7 = (uint)uVar15;
    uVar8 = 0;
    uVar9 = 0;
    if (uVar5 < param_3 || uVar7 < param_4 && uVar5 == param_3) {
      uVar9 = param_4 - uVar7;
      uVar8 = param_3 - ((param_4 < uVar7) + uVar5);
    }
    puVar6 = (uint *)_timer_attributes(0);
    uVar5 = *puVar6;
    cVar13 = uVar5 < uVar8 || puVar6[1] < uVar9 && uVar5 == uVar8;
    if (uVar5 < uVar8 || puVar6[1] < uVar9 && uVar5 == uVar8) {
      puVar6 = (uint *)_timer_attributes(0);
      uVar8 = *puVar6;
      uVar9 = puVar6[1];
    }
    cVar10 = '\0';
    cVar11 = '\x01';
    cVar12 = '\0';
    bVar14 = 0;
    __set_timer(0,uVar8,uVar9);
    uVar4 = extraout_D0u;
  }
  return CONCAT22(uVar4,(word)(byte)(cVar13 << 4 | cVar10 << 3 | cVar11 << 2 | cVar12 << 1 | bVar14)
                 );
}
/* GHIDRADEC_FUNCTION index=1479 start=0x404e664 */

undefined4 _ns_untimeout(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = &_ns_calltodo;
  puVar2 = _ns_calltodo;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      uVar3 = _callout_remove(param_1,param_2);
      return uVar3;
    }
    if ((param_1 == puVar2[4]) && (param_2 == puVar2[3])) break;
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  }
  *puVar1 = *puVar2;
  *puVar2 = _ns_callfree;
  _ns_callfree = puVar2;
  return 1;
}
/* GHIDRADEC_FUNCTION index=1480 start=0x404e6ce */

byte _ns_sleep(int param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  _ns_timeout(_wakeup,&param_1,param_1,param_2,1);
  _sleep(&param_1,0x18);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=1481 start=0x404e712 */

void _ns_time_to_timeval(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  qword qVar2;
  
  piVar1 = param_3 + 1;
  qVar2 = CONCAT44(param_1 % 1000000000,param_2);
  *piVar1 = (int)(qVar2 % 1000000000);
  *param_3 = (int)(qVar2 / 1000000000);
  *piVar1 = *piVar1 / 1000;
  return;
}
/* GHIDRADEC_FUNCTION index=1482 start=0x404e76e */

undefined8 _timeval_to_ns_time(int *param_1)

{
  uint uVar1;
  sqword sVar2;
  int iVar3;
  
  sVar2 = (sqword)*param_1 * 1000000 + CONCAT44((int)-(param_1[1] < 0),param_1[1]);
  uVar1 = (uint)sVar2;
  iVar3 = (int)((qword)sVar2 >> 0x20);
  sVar2 = sVar2 + CONCAT44((((iVar3 << 5 | uVar1 >> 0x1b) - ((uint)(uVar1 * 0x20 < uVar1) + iVar3))
                            * 2 + (uint)CARRY4(uVar1 * 0x1f,uVar1 * 0x1f)) * 2 +
                           (uint)CARRY4(uVar1 * 0x3e,uVar1 * 0x3e),uVar1 * 0x7c);
  uVar1 = (uint)sVar2;
  return CONCAT44((((int)((qword)sVar2 >> 0x20) * 2 + (uint)CARRY4(uVar1,uVar1)) * 2 +
                  (uint)CARRY4(uVar1 * 2,uVar1 * 2)) * 2 + (uint)CARRY4(uVar1 * 4,uVar1 * 4),
                  uVar1 * 8);
}
/* GHIDRADEC_FUNCTION index=1483 start=0x404e7d0 */

void _ns_time_to_tsval(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = (int)(CONCAT44(param_1 % 1000,param_2) / 1000);
  param_3[1] = param_1 / 1000;
  return;
}
/* GHIDRADEC_FUNCTION index=1484 start=0x404e81e */

undefined8 _ticks_to_ns_time(uint param_1)

{
  return CONCAT44(_ns_per_tick * param_1 + (int)((qword)dword_40C2448 * (qword)param_1 >> 0x20),
                  (int)((qword)dword_40C2448 * (qword)param_1));
}
/* GHIDRADEC_FUNCTION index=1485 start=0x404e85c */

undefined4 _sched_usec_elapsed(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar6 = _clock_value(1);
  iVar4 = (int)((qword)uVar6 >> 0x20);
  uVar5 = (uint)uVar6;
  uVar3 = CONCAT44(dword_40B39BA,dword_40B39BE);
  if (dword_40B39BE == 0 && dword_40B39BA == 0) {
    uVar3 = uVar6;
  }
  dword_40B39BA = (int)((qword)uVar3 >> 0x20);
  dword_40B39BE = (uint)uVar3;
  iVar1 = uVar5 - dword_40B39BE;
  iVar2 = (uint)(uVar5 < dword_40B39BE) + dword_40B39BA;
  dword_40B39BA = iVar4;
  dword_40B39BE = uVar5;
  return (int)(CONCAT44((uint)(iVar4 - iVar2) % 1000,iVar1) / 1000);
}
/* GHIDRADEC_FUNCTION index=1486 start=0x404e8de */

void _get_calendar_time_value(undefined4 *param_1)

{
  int *piVar1;
  qword qVar2;
  undefined8 uVar3;
  
  uVar3 = _clock_value(0);
  piVar1 = param_1 + 1;
  qVar2 = CONCAT44((uint)((qword)uVar3 >> 0x20) % 1000000000,(int)uVar3);
  *piVar1 = (int)(qVar2 % 1000000000);
  *param_1 = (int)(qVar2 / 1000000000);
  *piVar1 = *piVar1 / 1000;
  return;
}
/* GHIDRADEC_FUNCTION index=1487 start=0x404e948 */

void _set_calendar_time_value(int *param_1)

{
  _set_clock(0,(sqword)param_1[1] * 1000 + (sqword)*param_1 * 1000000000);
  return;
}
/* GHIDRADEC_FUNCTION index=1488 start=0x404e98c */

void _microtime(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = _clock_value(0);
  uVar2 = (uint)((qword)uVar4 >> 0x20);
  uVar3 = (uint)uVar4;
  if ((uVar2 < dword_40AF93C || uVar3 < dword_40AF940 && uVar2 == dword_40AF93C) &&
     (uVar1 = dword_40AF940 - uVar3, uVar2 = (dword_40AF940 < uVar3) + uVar2,
     uVar1 < 999999999 && dword_40AF93C == uVar2 ||
     dword_40AF93C - uVar2 == (uint)(uVar1 < 999999999) && uVar1 == 999999999)) {
    uVar4 = CONCAT44(dword_40AF93C,dword_40AF940);
  }
  dword_40AF93C = (uint)((qword)uVar4 >> 0x20);
  dword_40AF940 = (uint)uVar4;
  _ns_time_to_timeval(uVar4,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1489 start=0x404ea00 */

void _microboot(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = _clock_value(1);
  _ns_time_to_timeval(uVar1,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1490 start=0x404ea28 */

void _us_timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = _timeval_to_ns_time(param_3);
  _ns_timeout(param_1,param_2,uVar1,param_4);
  return;
}
/* GHIDRADEC_FUNCTION index=1491 start=0x404ea60 */

void _us_abstimeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = _timeval_to_ns_time(param_3);
  _ns_abstimeout(param_1,param_2,uVar1,param_4);
  return;
}
/* GHIDRADEC_FUNCTION index=1492 start=0x404ea98 */

void _us_untimeout(undefined4 param_1,undefined4 param_2)

{
  _ns_untimeout(param_1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1493 start=0x404eb90 */

void _power_callout(undefined4 param_1,int param_2)

{
  undefined8 uVar1;
  
  sub_404EAAE(0);
  if (param_2 == 0) {
    param_2 = _calloutEntryAllocate(_power_callout,0);
  }
  uVar1 = _calloutDeadlineFromInterval(0,1010000000);
  _calloutEntryDispatchDelayed(param_2,uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=1494 start=0x404ebe0 */

void _power_init(void)

{
  int iVar1;
  
  if (dword_40AF944 == 0) {
    iVar1 = _PMConnect();
    if (iVar1 == 0) {
      _power_callout(0,0);
    }
    dword_40B39C2 = 0;
    dword_40AF944 = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1495 start=0x404ec12 */

undefined4 _kern_PMSetPowerState(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMSetPowerState(param_2,param_3);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1496 start=0x404ec36 */

undefined4 _kern_PMGetPowerEvent(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = sub_404EAAE(param_2);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1497 start=0x404ec56 */

undefined4 _kern_PMGetPowerStatus(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMGetPowerStatus(param_2);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1498 start=0x404ec76 */

undefined4 _kern_PMSetPowerManagement(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMSetPowerManagement(param_2,param_3);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1499 start=0x404ec9a */

undefined4 _kern_PMRestoreDefaults(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMRestoreDefaults();
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}

