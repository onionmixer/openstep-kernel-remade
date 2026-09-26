/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155a9c */

int _mach_port_get_receive_status(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *local_8;
  
  if (param_1 == 0) {
    return 0x10;
  }
  iVar2 = _ipc_object_translate(param_1,param_2,1,&local_8);
  if (iVar2 != 0) {
    return iVar2;
  }
  piVar3 = (int *)local_8[0xc];
  if (piVar3 != (int *)0x0) {
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar2 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (piVar3[2] < 0) {
      *param_3 = piVar3[3];
      piVar1 = piVar3 + 4;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      param_3[1] = local_8[0xd];
      LOCK();
      piVar3[4] = 0;
      UNLOCK();
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      goto LAB_00155b8a;
    }
    _ipc_pset_remove(piVar3,local_8);
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    if (piVar3[1] == 0) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar3 + 10) & 0x7fff],piVar3);
    }
  }
  *param_3 = 0;
  piVar3 = local_8 + 0x10;
  do {
    do {
    } while (*piVar3 != 0);
    LOCK();
    iVar2 = *piVar3;
    *piVar3 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  param_3[1] = local_8[0xd];
  LOCK();
  local_8[0x10] = 0;
  UNLOCK();
LAB_00155b8a:
  param_3[2] = local_8[6];
  param_3[3] = local_8[0xf];
  param_3[4] = local_8[0xe];
  param_3[5] = local_8[8];
  param_3[6] = (uint)(local_8[7] != 0);
  param_3[7] = (uint)(local_8[10] != 0);
  param_3[8] = (uint)(local_8[9] != 0);
  LOCK();
  *local_8 = 0;
  UNLOCK();
  return 0;
}

