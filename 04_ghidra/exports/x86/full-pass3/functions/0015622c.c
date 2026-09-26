/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015622c */

undefined4
_port_status(int param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5,
            undefined4 *param_6,undefined4 *param_7)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_10 [4];
  uint local_c;
  int local_8;
  
  if (((param_1 == 0) || (iVar5 = _ipc_right_lookup_write(param_1,param_2,&local_8), iVar5 != 0)) ||
     (iVar5 = _ipc_right_info(param_1,param_2,local_8,&local_c,local_10), iVar5 != 0)) {
    return 4;
  }
  if ((local_c & 0x170000) == 0) {
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    return 4;
  }
  if ((local_c & 0x20000) == 0) {
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    *param_6 = 0;
    *param_7 = 0;
    *param_3 = 0;
    *param_4 = -1;
    *param_5 = 0;
    return 0;
  }
  piVar1 = *(int **)(local_8 + 4);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar5 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar5 == 1);
  LOCK();
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  piVar2 = (int *)piVar1[0xc];
  if (piVar2 != (int *)0x0) {
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar5 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    if (piVar2[2] < 0) {
      iVar5 = piVar2[3];
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      goto LAB_0015630e;
    }
    _ipc_pset_remove(piVar2,piVar1);
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    if (piVar2[1] == 0) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar2 + 10) & 0x7fff],piVar2);
    }
  }
  iVar5 = 0;
LAB_0015630e:
  iVar3 = piVar1[0xf];
  iVar4 = piVar1[0xe];
  LOCK();
  *piVar1 = 0;
  UNLOCK();
  *param_6 = 1;
  *param_7 = 1;
  *param_3 = iVar5;
  *param_4 = iVar4;
  *param_5 = iVar3;
  return 0;
}

