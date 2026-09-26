/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014ab94 */

undefined4
_ipc_mqueue_copyin(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  int *piVar5;
  
  piVar1 = (int *)(param_1 + 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if ((*(int *)(param_1 + 0xc) == 0) ||
     (puVar3 = (uint *)_ipc_entry_lookup(param_1,param_2), puVar3 == (uint *)0x0)) {
LAB_0014ac94:
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    uVar4 = 0x10004002;
  }
  else {
    piVar1 = (int *)puVar3[1];
    if ((*puVar3 & 0x20000) == 0) {
      if ((*puVar3 & 0x80000) == 0) goto LAB_0014ac94;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      piVar5 = piVar1 + 4;
    }
    else {
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      piVar5 = (int *)piVar1[0xc];
      if (piVar5 != (int *)0x0) {
        do {
          do {
          } while (*piVar5 != 0);
          LOCK();
          iVar2 = *piVar5;
          *piVar5 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        if (piVar5[2] < 0) {
          LOCK();
          *piVar5 = 0;
          UNLOCK();
          LOCK();
          *piVar1 = 0;
          UNLOCK();
          return 0x1000400a;
        }
        _ipc_pset_remove(piVar5,piVar1);
        LOCK();
        *piVar5 = 0;
        UNLOCK();
        if (piVar5[1] == 0) {
          _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar5 + 10) & 0x7fff],piVar5);
        }
      }
      piVar5 = piVar1 + 0x10;
    }
    piVar1[1] = piVar1[1] + 1;
    do {
      do {
      } while (*piVar5 != 0);
      LOCK();
      iVar2 = *piVar5;
      *piVar5 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    LOCK();
    *piVar1 = 0;
    UNLOCK();
    *param_4 = piVar1;
    *param_3 = piVar5;
    uVar4 = 0;
  }
  return uVar4;
}

