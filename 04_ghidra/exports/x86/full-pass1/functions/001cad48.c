/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cad48 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _NXDefaultExceptionRaiser(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *unaff_EBX;
  uint uVar5;
  
  iVar2 = _current_thread_EXTERNAL();
  piVar3 = &DAT_001e551c;
  do {
    if (piVar3[4] == iVar2) goto LAB_001cad84;
    piVar3 = (int *)piVar3[5];
  } while (piVar3 != (int *)0x0);
  piVar3 = (int *)FUN_001ca960(iVar2);
LAB_001cad84:
  while( true ) {
    piVar4 = (int *)*piVar3;
    if (piVar4 == (int *)0x0) {
      if (__NXUncaughtExceptionHandler != (code *)0x0) {
        (*__NXUncaughtExceptionHandler)(param_1,param_2,param_3);
      }
                    /* WARNING: Subroutine does not return */
      _panic("Uncaught exception");
    }
    if (((uint)piVar4 & 1) == 0) break;
    piVar4 = (int *)((((int)piVar4 + -1) / 2) * 0xc + piVar3[1]);
    *piVar3 = *piVar4;
    piVar3[3] = ((int)piVar4 - piVar3[1]) * -0x55555555 >> 2;
    (*(code *)piVar4[1])(piVar4[2],param_1,param_2,param_3);
  }
  piVar4[0x13] = param_1;
  piVar4[0x14] = param_2;
  piVar4[0x15] = param_3;
  *piVar3 = piVar4[0x12];
  iVar2 = 1;
  _jump_label(piVar4,1);
  do {
  } while (DAT_001e5540 != 0);
  LOCK();
  DAT_001e5540 = 1;
  UNLOCK();
  uVar5 = iVar2 + _DAT_001e553c + 7 & 0xfffffff8;
  if ((int)DAT_001e5454 < (int)uVar5) {
    DAT_001e5538 = _realloc(DAT_001e5538,uVar5);
    DAT_001e5454 = uVar5;
  }
  *unaff_EBX = (int)DAT_001e5538 + _DAT_001e553c;
  uVar1 = DAT_001e5540;
  _DAT_001e553c = uVar5;
  LOCK();
  DAT_001e5540 = 0;
  UNLOCK();
  return uVar1;
}

