/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119cd9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00119cd9(void)

{
  uint *puVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  (**(code **)(*(int *)(*(int *)(unaff_EBX + 0x40) + 0x1c) + 0x54))();
  *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
  if (unaff_ESI == 0) {
    __bstats = __bstats + 1;
    if (*(int *)(unaff_EBP + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_bread__size_0_001db554);
    }
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
  }
  else {
    _biowait();
  }
  return;
}

