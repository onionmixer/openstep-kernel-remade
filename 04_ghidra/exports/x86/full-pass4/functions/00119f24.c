/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119f24 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00119f24(void)

{
  uint *puVar1;
  int iVar2;
  int unaff_EBP;
  
  puVar1 = (uint *)_getblk();
  if ((*puVar1 & 2) == 0) {
    *puVar1 = *puVar1 | 1;
    if ((int)puVar1[6] < (int)puVar1[5]) {
                    /* WARNING: Subroutine does not return */
      _panic(s_bread_001db562);
    }
    (**(code **)(*(int *)(puVar1[0x10] + 0x1c) + 0x54))();
    *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
    _biowait(puVar1);
  }
  else {
    _DAT_001e99c4 = _DAT_001e99c4 + 1;
  }
  if ((*puVar1 & 4) == 0) {
    _copy_to_phys(puVar1[8],*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x24));
    **(undefined4 **)(unaff_EBP + 0x24) = 0;
    _brelse(puVar1);
    iVar2 = *(int *)(unaff_EBP + 0x14) - puVar1[10];
  }
  else {
    _brelse();
    **(int **)(unaff_EBP + 0x24) = (int)(short)puVar1[7];
    iVar2 = 0;
  }
  return iVar2;
}

