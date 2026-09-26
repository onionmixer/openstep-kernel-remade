/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146d54 */

uint _ipc_hash_info(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  if (_ipc_hash_global_size < param_2) {
    param_2 = _ipc_hash_global_size;
  }
  uVar4 = 0;
  piVar3 = _ipc_hash_global_table;
  if (param_2 != 0) {
    do {
      iVar2 = 0;
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      for (iVar1 = piVar3[1]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        iVar2 = iVar2 + 1;
      }
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      *(int *)(param_1 + uVar4 * 4) = iVar2;
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 2;
    } while (uVar4 < param_2);
  }
  return _ipc_hash_global_size;
}

