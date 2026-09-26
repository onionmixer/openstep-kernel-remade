/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146ae8 */

int _ipc_hash_global_delete(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -1;
  piVar2 = (int *)(_ipc_hash_global_table +
                  ((param_1 >> 4) + (param_2 >> 6) & _ipc_hash_global_mask) * 8);
  do {
    do {
    } while (*piVar2 != 0);
    LOCK();
    iVar3 = *piVar2;
    *piVar2 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  piVar1 = piVar2 + 1;
  iVar3 = piVar2[1];
  do {
    if (iVar3 == 0) {
LAB_00146b46:
      LOCK();
      iVar3 = *piVar2;
      *piVar2 = 0;
      UNLOCK();
      return iVar3;
    }
    if (iVar3 == param_4) {
      *piVar1 = *(int *)(iVar3 + 0xc);
      goto LAB_00146b46;
    }
    piVar1 = (int *)(iVar3 + 0xc);
    iVar3 = *(int *)(iVar3 + 0xc);
  } while( true );
}

