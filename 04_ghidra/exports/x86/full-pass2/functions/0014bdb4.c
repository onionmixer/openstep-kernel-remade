/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014bdb4 */

int _ipc_object_copyout(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  piVar1 = (int *)(param_1 + 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  while( true ) {
    if (*(int *)(param_1 + 0xc) == 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0x10;
    }
    if ((param_3 != 0x12) &&
       (iVar2 = _ipc_right_reverse(param_1,param_2,&local_8,&local_c), iVar2 != 0)) break;
    iVar2 = _ipc_entry_get(param_1,&local_8,&local_c);
    if (iVar2 == 0) goto LAB_0014be40;
    iVar2 = _ipc_entry_grow_table(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
LAB_0014be7e:
  iVar2 = _ipc_right_copyout(param_1,local_8,local_c,param_3,param_4,param_2);
  LOCK();
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  if (iVar2 != 0) {
    return iVar2;
  }
  *param_5 = local_8;
  return 0;
LAB_0014be40:
  do {
    do {
    } while (*param_2 != 0);
    LOCK();
    iVar2 = *param_2;
    *param_2 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (-1 < param_2[2]) {
    LOCK();
    *param_2 = 0;
    UNLOCK();
    _ipc_entry_dealloc(param_1,local_8,local_c);
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    return 0x14;
  }
  *(int **)(local_c + 4) = param_2;
  goto LAB_0014be7e;
}

