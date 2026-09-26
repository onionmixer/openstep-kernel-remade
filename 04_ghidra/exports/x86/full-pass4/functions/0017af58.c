/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017af58 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _vm_page_lookup(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(_vm_page_buckets +
                  ((param_2 >> ((byte)_page_shift & 0x1f)) + param_1 & __vm_page_hash_mask) * 8);
  uVar3 = _splimp();
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  for (iVar2 = piVar1[1];
      (iVar2 != 0 && ((*(int *)(iVar2 + 0x14) != param_1 || (*(uint *)(iVar2 + 0x18) != param_2))));
      iVar2 = *(int *)(iVar2 + 0x10)) {
  }
  LOCK();
  *piVar1 = 0;
  UNLOCK();
  _splx(uVar3);
  return iVar2;
}

