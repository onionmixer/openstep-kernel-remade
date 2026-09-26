/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014d79c */

undefined4 _ipc_pset_move(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  do {
    do {
    } while (*param_2 != 0);
    LOCK();
    iVar1 = *param_2;
    *param_2 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  piVar4 = (int *)param_2[0xc];
  if (piVar4 == param_3) {
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
  }
  else if (piVar4 == (int *)0x0) {
    do {
      do {
      } while (*param_3 != 0);
      LOCK();
      iVar1 = *param_3;
      *param_3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    param_2[0xc] = (int)param_3;
    param_3[1] = param_3[1] + 1;
    piVar3 = param_2 + 0x10;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar3 = param_3 + 4;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    _ipc_mqueue_move(param_3 + 4,param_2 + 0x10,param_2);
    LOCK();
    param_3[4] = 0;
    UNLOCK();
    _ipc_mqueue_changed(param_2 + 0x10,0x10004006);
    LOCK();
    param_2[0x10] = 0;
    UNLOCK();
    LOCK();
    *param_3 = 0;
    UNLOCK();
  }
  else if (param_3 == (int *)0x0) {
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar1 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    param_2[0xc] = 0;
    piVar4[1] = piVar4[1] + -1;
    piVar3 = param_2 + 0x10;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar3 = piVar4 + 4;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    _ipc_mqueue_move(param_2 + 0x10,piVar4 + 4,param_2);
    LOCK();
    piVar4[4] = 0;
    UNLOCK();
    LOCK();
    param_2[0x10] = 0;
    UNLOCK();
    if (piVar4[2] < 0) {
      LOCK();
      *piVar4 = 0;
      UNLOCK();
    }
    else {
      LOCK();
      *piVar4 = 0;
      UNLOCK();
      if (piVar4[1] == 0) {
        _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar4 + 10) & 0x7fff],piVar4);
      }
      piVar4 = (int *)0x0;
    }
  }
  else {
    if (piVar4 < param_3) {
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      do {
        do {
        } while (*param_3 != 0);
        LOCK();
        iVar1 = *param_3;
        *param_3 = 1;
        UNLOCK();
      } while (iVar1 == 1);
    }
    else {
      do {
        do {
        } while (*param_3 != 0);
        LOCK();
        iVar1 = *param_3;
        *param_3 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar1 == 1);
    }
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    param_2[0xc] = 0;
    piVar4[1] = piVar4[1] + -1;
    piVar3 = param_2 + 0x10;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar3 = piVar4 + 4;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar3 = param_2 + 0x10;
    _ipc_mqueue_move(piVar3,piVar4 + 4,param_2);
    LOCK();
    piVar4[4] = 0;
    UNLOCK();
    LOCK();
    param_2[0x10] = 0;
    UNLOCK();
    param_2[0xc] = (int)param_3;
    param_3[1] = param_3[1] + 1;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar3 = param_3 + 4;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    _ipc_mqueue_move(param_3 + 4,param_2 + 0x10,param_2);
    LOCK();
    param_3[4] = 0;
    UNLOCK();
    _ipc_mqueue_changed(param_2 + 0x10,0x10004006);
    LOCK();
    param_2[0x10] = 0;
    UNLOCK();
    LOCK();
    *param_3 = 0;
    UNLOCK();
    LOCK();
    *piVar4 = 0;
    UNLOCK();
    if (piVar4[1] == 0) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar4 + 10) & 0x7fff],piVar4);
    }
  }
  LOCK();
  *param_2 = 0;
  UNLOCK();
  uVar2 = 0;
  if ((param_3 == (int *)0x0) && (piVar4 == (int *)0x0)) {
    uVar2 = 0xc;
  }
  return uVar2;
}

