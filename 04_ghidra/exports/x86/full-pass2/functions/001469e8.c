/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001469e8 */

bool _ipc_hash_global_lookup(uint param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
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
  iVar3 = piVar2[1];
  if (iVar3 != 0) {
    if ((*(uint *)(iVar3 + 4) == param_2) && (*(uint *)(iVar3 + 0x14) == param_1)) {
      *param_3 = *(undefined4 *)(iVar3 + 0x10);
      *param_4 = iVar3;
    }
    else {
      do {
        puVar1 = (undefined4 *)(iVar3 + 0xc);
        iVar3 = *(int *)(iVar3 + 0xc);
        if (iVar3 == 0) goto LAB_00146a7f;
      } while ((*(uint *)(iVar3 + 4) != param_2) || (*(uint *)(iVar3 + 0x14) != param_1));
      *puVar1 = *(undefined4 *)(iVar3 + 0xc);
      *(int *)(iVar3 + 0xc) = piVar2[1];
      piVar2[1] = iVar3;
      *param_3 = *(undefined4 *)(iVar3 + 0x10);
      *param_4 = iVar3;
    }
  }
LAB_00146a7f:
  LOCK();
  *piVar2 = 0;
  UNLOCK();
  return iVar3 != 0;
}

