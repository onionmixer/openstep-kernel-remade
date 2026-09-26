/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014ce18 */

undefined4 _ipc_port_check_circularity(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (param_1 == param_2) {
LAB_0014cedd:
    uVar3 = 1;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    LOCK();
    iVar1 = *param_2;
    *param_2 = 1;
    UNLOCK();
    if (iVar1 == 1) {
LAB_0014ce74:
      LOCK();
      *param_1 = 0;
      UNLOCK();
      do {
      } while (_ipc_port_multiple_lock_data != 0);
      LOCK();
      UNLOCK();
      piVar2 = param_2;
      do {
        piVar4 = piVar2;
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
        piVar2 = piVar4;
      } while ((iVar1 == 1) ||
              (((piVar4[2] < 0 && (piVar4[4] == 0)) &&
               (piVar2 = (int *)piVar4[3], (int *)piVar4[3] != (int *)0x0))));
      if (param_1 == piVar4) {
        LOCK();
        _ipc_port_multiple_lock_data = 0;
        UNLOCK();
        while (param_2 != (int *)0x0) {
          LOCK();
          *param_2 = 0;
          UNLOCK();
          param_2 = (int *)param_2[3];
        }
        goto LAB_0014cedd;
      }
      do {
        do {
        } while (*param_1 != 0);
        LOCK();
        iVar1 = *param_1;
        *param_1 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      LOCK();
      _ipc_port_multiple_lock_data = 0;
      UNLOCK();
    }
    else {
      piVar4 = param_2;
      if (((param_2[2] < 0) && (param_2[4] == 0)) && (param_2[3] != 0)) {
        LOCK();
        *param_2 = 0;
        UNLOCK();
        goto LAB_0014ce74;
      }
    }
    param_2[1] = param_2[1] + 1;
    param_1[3] = (int)param_2;
    while (param_1 != piVar4) {
      LOCK();
      *param_1 = 0;
      UNLOCK();
      param_1 = (int *)param_1[3];
    }
    LOCK();
    *piVar4 = 0;
    UNLOCK();
    uVar3 = 0;
  }
  return uVar3;
}

