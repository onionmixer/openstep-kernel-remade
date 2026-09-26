/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146a98 */

int _ipc_hash_global_insert(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  piVar1 = (int *)(_ipc_hash_global_table +
                  ((param_1 >> 4) + (param_2 >> 6) & _ipc_hash_global_mask) * 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  *(int *)(param_4 + 0xc) = piVar1[1];
  piVar1[1] = param_4;
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = 0;
  UNLOCK();
  return iVar2;
}

