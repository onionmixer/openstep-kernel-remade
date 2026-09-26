/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ac54 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011ac54(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(unaff_EBP + 0xc);
  *(uint *)(unaff_EBP + -0xc) =
       (*(uint *)(unaff_EBP + 0x10) / *(uint *)(unaff_EBP + -0x10) - 1) + *(int *)(unaff_EBP + -8);
  iVar2 = *(int *)(unaff_EBP + -8);
  if (*(int *)(unaff_EBP + -8) < 0) {
    iVar2 = iVar2 + 7;
  }
  *(undefined **)(unaff_EBP + -4) =
       &_bufhash + ((iVar2 >> 3) + *(int *)(unaff_EBP + 8) & 0xfU) * 0xc;
LAB_0011ac8f:
  puVar4 = (uint *)(*(uint **)(unaff_EBP + -4))[1];
  if (puVar4 == *(uint **)(unaff_EBP + -4)) {
    return;
  }
  do {
    if ((((puVar4[0x10] == *(uint *)(unaff_EBP + 8)) && ((*puVar4 & 0x10000) == 0)) &&
        (puVar4[5] != 0)) &&
       (((int)puVar4[9] <= *(int *)(unaff_EBP + -0xc) &&
        (*(int *)(unaff_EBP + -8) < (int)((int)puVar4[5] / *(int *)(unaff_EBP + -0x10) + puVar4[9]))
        ))) {
      uVar3 = _splhigh();
      uVar1 = *puVar4;
      if ((uVar1 & 8) != 0) {
        *puVar4 = uVar1 | 0x40;
        _sleep((uint)puVar4);
        _splx(uVar3);
        goto LAB_0011ac8f;
      }
      if ((uVar1 & 0x200) != 0) break;
      _splx();
    }
    puVar4 = (uint *)puVar4[1];
    if (*(uint **)(unaff_EBP + -4) == puVar4) {
      return;
    }
  } while( true );
  _splx();
  uVar3 = _splbio();
  *(uint *)(puVar4[4] + 0xc) = puVar4[3];
  *(uint *)(puVar4[3] + 0x10) = puVar4[4];
  *(byte *)puVar4 = (byte)*puVar4 | 8;
  _splx(uVar3);
  uVar1 = *puVar4;
  *puVar4 = uVar1 & 0xfffffdf8;
  if ((uVar1 & 0x200) == 0) {
    *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
  }
  if ((int)puVar4[6] < (int)puVar4[5]) {
                    /* WARNING: Subroutine does not return */
    _panic(s_bwrite_001db583);
  }
  (**(code **)(*(int *)(puVar4[0x10] + 0x1c) + 0x54))();
  if ((uVar1 & 0x100) == 0) {
    _biowait();
    _brelse(puVar4);
  }
  else if ((uVar1 & 0x200) != 0) {
    *(byte *)puVar4 = (byte)*puVar4 | 0x80;
  }
  goto LAB_0011ac8f;
}

