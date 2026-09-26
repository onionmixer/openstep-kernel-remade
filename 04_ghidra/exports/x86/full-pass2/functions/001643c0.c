/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001643c0 */

int * _choose_thread(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar2 = (int *)(param_1 + 0x100);
  do {
    do {
    } while (*piVar2 != 0);
    LOCK();
    iVar4 = *piVar2;
    *piVar2 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  if (*(int *)(param_1 + 0x108) < 1) {
    LOCK();
    *(undefined4 *)(param_1 + 0x100) = 0;
    UNLOCK();
    iVar4 = *(int *)(param_1 + 300);
    piVar2 = (int *)(iVar4 + 0x100);
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar3 = (int *)_choose_pset_thread(param_1,iVar4);
  }
  else {
    iVar4 = *(int *)(param_1 + 0x104);
    piVar2 = (int *)(param_1 + iVar4 * 8);
    while( true ) {
      if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_choose_thread_001df6aa);
      }
      piVar3 = (int *)*piVar2;
      if (piVar2 != piVar3) break;
      piVar2 = piVar2 + -2;
      iVar4 = iVar4 + -1;
    }
    if (piVar3 == piVar2) {
      piVar3 = (int *)0x0;
    }
    else {
      *(int **)(*piVar3 + 4) = piVar2;
      *piVar2 = *piVar3;
    }
    *(undefined4 *)((int)piVar3 + 8) = 0;
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + -1;
    *(int *)(param_1 + 0x104) = iVar4;
    LOCK();
    *(undefined4 *)(param_1 + 0x100) = 0;
    UNLOCK();
  }
  return piVar3;
}

