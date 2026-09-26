/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016448c */

int * _choose_pset_thread(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_c;
  
  if (*(int *)(param_2 + 0x108) < 1) {
    LOCK();
    *(undefined4 *)(param_2 + 0x100) = 0;
    UNLOCK();
    piVar3 = (int *)(param_2 + 0x118);
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (*(int *)(param_1 + 0x114) == 1) {
      *(undefined4 *)(param_1 + 0x114) = 2;
      if (_master_processor == param_1) {
        iVar1 = *(int *)(param_2 + 0x110);
        if (param_2 + 0x10c == iVar1) {
          *(int *)(param_2 + 0x10c) = param_1;
        }
        else {
          *(int *)(iVar1 + 0x10c) = param_1;
        }
        *(int *)(param_1 + 0x110) = iVar1;
        *(int *)(param_1 + 0x10c) = param_2 + 0x10c;
        *(int *)(param_2 + 0x110) = param_1;
      }
      else {
        iVar1 = *(int *)(param_2 + 0x10c);
        if (param_2 + 0x10c == iVar1) {
          *(int *)(param_2 + 0x110) = param_1;
        }
        else {
          *(int *)(iVar1 + 0x110) = param_1;
        }
        *(int *)(param_1 + 0x10c) = iVar1;
        *(int *)(param_1 + 0x110) = param_2 + 0x10c;
        *(int *)(param_2 + 0x10c) = param_1;
      }
      *(int *)(param_2 + 0x114) = *(int *)(param_2 + 0x114) + 1;
    }
    LOCK();
    *(undefined4 *)(param_2 + 0x118) = 0;
    UNLOCK();
    piVar3 = *(int **)(param_1 + 0x11c);
  }
  else {
    local_c = *(int *)(param_2 + 0x104);
    piVar2 = (int *)(param_2 + local_c * 8);
    while( true ) {
      if (local_c < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_choose_pset_thread_001df6b8);
      }
      piVar3 = (int *)*piVar2;
      if (piVar2 != piVar3) break;
      piVar2 = piVar2 + -2;
      local_c = local_c + -1;
    }
    if (piVar3 == piVar2) {
      piVar3 = (int *)0x0;
    }
    else {
      *(int **)(*piVar3 + 4) = piVar2;
      *piVar2 = *piVar3;
    }
    *(undefined4 *)((int)piVar3 + 8) = 0;
    iVar1 = *(int *)(param_2 + 0x108);
    *(int *)(param_2 + 0x108) = iVar1 + -1;
    if (((iVar1 != 1 && -1 < iVar1 + -1) && ((*(byte *)(param_2 + 0x168) & 2) != 0)) &&
       ((int *)*piVar2 == piVar2)) {
      do {
        piVar2 = piVar2 + -2;
        local_c = local_c + -1;
      } while ((int *)*piVar2 == piVar2);
    }
    *(int *)(param_2 + 0x104) = local_c;
    LOCK();
    *(undefined4 *)(param_2 + 0x100) = 0;
    UNLOCK();
  }
  return piVar3;
}

