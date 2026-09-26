/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119eed */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00119eed(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EBP;
  uint *unaff_ESI;
  
  (**(code **)(*(int *)(*(int *)(unaff_EBX + 0x40) + 0x1c) + 0x54))();
  *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
  if (unaff_ESI == (uint *)0x0) {
    __bstats = __bstats + 1;
    if (*(int *)(unaff_EBP + 0x14) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_bread__size_0_001db554);
    }
    unaff_ESI = (uint *)_getblk();
    if ((*unaff_ESI & 2) == 0) {
      *unaff_ESI = *unaff_ESI | 1;
      if ((int)unaff_ESI[6] < (int)unaff_ESI[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(s_bread_001db562);
      }
      (**(code **)(*(int *)(unaff_ESI[0x10] + 0x1c) + 0x54))();
      *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
      _biowait(unaff_ESI);
    }
    else {
      _DAT_001e99c4 = _DAT_001e99c4 + 1;
    }
  }
  else {
    _biowait();
  }
  if ((*unaff_ESI & 4) == 0) {
    _copy_to_phys(unaff_ESI[8],*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x24));
    **(undefined4 **)(unaff_EBP + 0x24) = 0;
    _brelse(unaff_ESI);
    iVar1 = *(int *)(unaff_EBP + 0x14) - unaff_ESI[10];
  }
  else {
    _brelse();
    **(int **)(unaff_EBP + 0x24) = (int)(short)unaff_ESI[7];
    iVar1 = 0;
  }
  return iVar1;
}

