/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014b9b0 */

int _ipc_object_alloc(int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,
                     undefined4 *param_6)

{
  int *piVar1;
  int iVar2;
  uint *local_8;
  
  piVar1 = (int *)_zalloc((&_ipc_object_zones)[param_2]);
  if (piVar1 == (int *)0x0) {
    iVar2 = 6;
  }
  else {
    iVar2 = _ipc_entry_alloc(param_1,param_5,&local_8);
    if (iVar2 == 0) {
      *local_8 = *local_8 | param_3 | param_4;
      local_8[1] = (uint)piVar1;
      *piVar1 = 0;
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
      piVar1[1] = 1;
      piVar1[2] = param_2 << 0x10 | 0x80000000;
      *param_6 = piVar1;
      iVar2 = 0;
    }
    else {
      _zfree((&_ipc_object_zones)[param_2],piVar1);
    }
  }
  return iVar2;
}

