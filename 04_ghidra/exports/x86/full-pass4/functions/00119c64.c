/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119c64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00119c64(void)

{
  int iVar1;
  uint *puVar2;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  (**(code **)(*(int *)(*(int *)(unaff_ESI + 0x40) + 0x1c) + 0x54))();
  *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
  if ((unaff_EBX != 0) && (iVar1 = _incore(), iVar1 == 0)) {
    puVar2 = (uint *)_getblk();
    if ((*puVar2 & 2) == 0) {
      *puVar2 = *puVar2 | 0x101;
      if ((int)puVar2[6] < (int)puVar2[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(s_breadrabp_001db56f);
      }
      (**(code **)(*(int *)(puVar2[0x10] + 0x1c) + 0x54))();
      *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
    }
    else {
      _brelse();
      _DAT_001e99d0 = _DAT_001e99d0 + 1;
    }
  }
  if (unaff_ESI == 0) {
    __bstats = __bstats + 1;
    if (*(int *)(unaff_EBP + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_bread__size_0_001db554);
    }
    puVar2 = (uint *)_getblk();
    if ((*puVar2 & 2) == 0) {
      *puVar2 = *puVar2 | 1;
      if ((int)puVar2[6] < (int)puVar2[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(s_bread_001db562);
      }
      (**(code **)(*(int *)(puVar2[0x10] + 0x1c) + 0x54))();
      *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
      _biowait(puVar2);
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

