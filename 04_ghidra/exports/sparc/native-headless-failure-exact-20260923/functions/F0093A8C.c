
/* WARNING: Removing unreachable block (ram,0xf0093ac0) */
/* WARNING: Removing unreachable block (ram,0xf0093b5c) */
/* WARNING: Removing unreachable block (ram,0xf0093a8c) */
/* WARNING: Removing unreachable block (ram,0xf0093b40) */
/* WARNING: Removing unreachable block (ram,0xf0093aac) */

undefined8 _vol_notify_cancel(uint param_1,undefined4 param_2)

{
  short sVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  ppuVar5 = (undefined **)(param_1 & 0xfffffff8);
  if (DAT_f0131251 == '\0') {
    _lock_init(&DAT_f0131254,1);
    DAT_f0131251 = '\x01';
  }
  _lock_write(&DAT_f0131254);
  if ((undefined **)PTR_LOOP_f0112520 != &PTR_LOOP_f0112520) {
    sVar1 = *(short *)(PTR_LOOP_f0112520 + 0xc);
    ppuVar4 = (undefined **)PTR_LOOP_f0112520;
    while( true ) {
      ppuVar6 = (undefined **)*ppuVar4;
      if ((sVar1 == (short)ppuVar5) || (*(short *)((int)ppuVar4 + 0xe) == (short)ppuVar5)) {
        ppuVar3 = (undefined **)ppuVar4[1];
        ppuVar2 = ppuVar3;
        if (ppuVar6 != &PTR_LOOP_f0112520) {
          ppuVar6[1] = (undefined *)ppuVar3;
          ppuVar2 = (undefined **)PTR_LOOP_f0112524;
        }
        PTR_LOOP_f0112524 = (undefined *)ppuVar2;
        ppuVar2 = ppuVar6;
        if (ppuVar3 != &PTR_LOOP_f0112520) {
          *ppuVar3 = (undefined *)ppuVar6;
          ppuVar2 = (undefined **)PTR_LOOP_f0112520;
        }
        PTR_LOOP_f0112520 = (undefined *)ppuVar2;
        _kfree(ppuVar4,100);
      }
      if (ppuVar6 == &PTR_LOOP_f0112520) break;
      sVar1 = *(short *)(ppuVar6 + 3);
      ppuVar4 = ppuVar6;
    }
    ppuVar5 = &PTR_LOOP_f0112520;
  }
  _lock_done(&DAT_f0131254);
  return CONCAT44(param_2,ppuVar5);
}

