/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017b540 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _vm_page_free(int param_1)

{
  undefined4 *puVar1;
  short *psVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  if ((*(byte *)(param_1 + 0x20) & 4) != 0) {
    piVar3 = (int *)(_vm_page_buckets +
                    ((*(uint *)(param_1 + 0x18) >> ((byte)_page_shift & 0x1f)) +
                     *(int *)(param_1 + 0x14) & __vm_page_hash_mask) * 8);
    uVar4 = _splimp();
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar5 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    iVar5 = piVar3[1];
    if (iVar5 == param_1) {
      piVar3[1] = *(int *)(param_1 + 0x10);
    }
    else {
      do {
        puVar1 = (undefined4 *)(iVar5 + 0x10);
        iVar5 = *(int *)(iVar5 + 0x10);
      } while (iVar5 != param_1);
      *puVar1 = *(undefined4 *)(iVar5 + 0x10);
    }
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    _splx(uVar4);
    iVar5 = *(int *)(param_1 + 8);
    piVar3 = *(int **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x14) == iVar5) {
      *(int **)(iVar5 + 4) = piVar3;
    }
    else {
      *(int **)(iVar5 + 0xc) = piVar3;
    }
    if (*(int **)(param_1 + 0x14) == piVar3) {
      *piVar3 = iVar5;
    }
    else {
      piVar3[2] = iVar5;
    }
    psVar2 = (short *)(*(int *)(param_1 + 0x14) + 0x1a);
    *psVar2 = *psVar2 + -1;
    *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) & 0xfb;
  }
  if ((*(byte *)(param_1 + 0x1e) & 8) == 0) {
    _vm_page_addfree(param_1);
  }
  return;
}

