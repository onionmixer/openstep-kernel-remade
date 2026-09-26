
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _clock_timer_init(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  uint local_14;
  int local_10;
  undefined1 local_c [4];
  undefined4 local_8;
  
  _intr_register_irq(0,_system_timer_dispatch,0,6);
  _intr_enable_irq(0);
  local_8 = 0;
  _readtodc(local_c);
  __time_of_boot = _timeval_to_ns_time(local_c);
  uVar1 = _splusclock();
  out(0x43,0x34);
  LOCK();
  _DAT_001e75c4 = _DAT_001e75c4 + 1;
  UNLOCK();
  uVar5 = 10000000;
  uVar4 = 0x1234cf;
  iVar3 = 0;
  while ((local_10 = (int)((ulonglong)uVar5 >> 0x20), local_14 = (uint)uVar5, local_10 != 0 ||
         (1 < local_14))) {
    uVar5 = __udivdi3(uVar5,10,0);
    iVar3 = iVar3 + 1;
  }
  if (local_14 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_clock_timer_constant_1_001e17fc);
  }
  uVar2 = 9 - iVar3;
  if (5 < uVar2) {
                    /* WARNING: Subroutine does not return */
    _panic(s_clock_timer_constant_2_001e1813);
  }
  for (; 0 < (int)uVar2; uVar2 = uVar2 - 1) {
    uVar4 = uVar4 / 10;
  }
  if (0xffff < uVar4) {
                    /* WARNING: Subroutine does not return */
    _panic(s_clock_timer_constant_3_001e182a);
  }
  DAT_001e75da = (undefined2)uVar4;
  DAT_001e75d8._0_1_ = (undefined1)uVar4;
  out(0x40,(undefined1)DAT_001e75d8);
  LOCK();
  UNLOCK();
  out(0x40,(char)(uVar4 >> 8));
  LOCK();
  _DAT_001e75c4 = _DAT_001e75c4 + 2;
  UNLOCK();
  DAT_001e75d8 = DAT_001e75da;
  _splx(uVar1);
  return;
}

