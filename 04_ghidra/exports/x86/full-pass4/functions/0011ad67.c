/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ad67 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011ad67(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint *unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  uint unaff_EDI;
  
LAB_0011ad6a:
  (**(code **)(*(int *)(unaff_EBX[0x10] + 0x1c) + 0x54))();
  if ((unaff_ESI & 0x100) == 0) {
    _biowait();
    _brelse(unaff_EBX);
  }
  else if (unaff_EDI != 0) {
    *(byte *)unaff_EBX = (byte)*unaff_EBX | 0x80;
  }
LAB_0011ac8f:
  unaff_EBX = (uint *)(*(uint **)(unaff_EBP + -4))[1];
  if (unaff_EBX == *(uint **)(unaff_EBP + -4)) {
    return;
  }
  do {
    if ((((unaff_EBX[0x10] == *(uint *)(unaff_EBP + 8)) && ((*unaff_EBX & 0x10000) == 0)) &&
        (unaff_EBX[5] != 0)) &&
       (((int)unaff_EBX[9] <= *(int *)(unaff_EBP + -0xc) &&
        (*(int *)(unaff_EBP + -8) <
         (int)((int)unaff_EBX[5] / *(int *)(unaff_EBP + -0x10) + unaff_EBX[9]))))) {
      uVar2 = _splhigh();
      uVar1 = *unaff_EBX;
      if ((uVar1 & 8) != 0) break;
      if ((uVar1 & 0x200) != 0) {
        _splx();
        uVar2 = _splbio();
        *(uint *)(unaff_EBX[4] + 0xc) = unaff_EBX[3];
        *(uint *)(unaff_EBX[3] + 0x10) = unaff_EBX[4];
        *(byte *)unaff_EBX = (byte)*unaff_EBX | 8;
        _splx(uVar2);
        unaff_ESI = *unaff_EBX;
        *unaff_EBX = unaff_ESI & 0xfffffdf8;
        unaff_EDI = unaff_ESI & 0x200;
        if (unaff_EDI == 0) {
          *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
        }
        if ((int)unaff_EBX[6] < (int)unaff_EBX[5]) {
                    /* WARNING: Subroutine does not return */
          _panic(s_bwrite_001db583);
        }
        goto LAB_0011ad6a;
      }
      _splx();
    }
    unaff_EBX = (uint *)unaff_EBX[1];
    if (*(uint **)(unaff_EBP + -4) == unaff_EBX) {
      return;
    }
  } while( true );
  *unaff_EBX = uVar1 | 0x40;
  _sleep((uint)unaff_EBX);
  _splx(uVar2);
  goto LAB_0011ac8f;
}

