/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a7da */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011a7da(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint *unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  undefined4 *puVar3;
  uint *unaff_EDI;
  
LAB_0011a7dd:
  (**(code **)(*(int *)(unaff_EBX[0x10] + 0x1c) + 0x54))();
  if ((unaff_ESI & 0x100) == 0) {
    _biowait();
    _brelse(unaff_EBX);
  }
  else {
    *(byte *)unaff_EBX = (byte)*unaff_EBX | 0x80;
  }
LAB_0011a726:
  unaff_EBX = (uint *)(*(uint **)(unaff_EBP + -0xc))[1];
  if (unaff_EBX == *(uint **)(unaff_EBP + -0xc)) {
LAB_0011a90f:
    _allocbuf();
    return;
  }
  do {
    if ((((unaff_EBX != unaff_EDI) && (unaff_EBX[0x10] == unaff_EDI[0x10])) &&
        ((*unaff_EBX & 0x10000) == 0)) &&
       (((unaff_EBX[5] != 0 && ((int)unaff_EBX[9] <= *(int *)(unaff_EBP + -8))) &&
        (*(int *)(unaff_EBP + -4) <
         (int)((int)unaff_EBX[5] / *(int *)(unaff_EBP + -0x10) + unaff_EBX[9]))))) {
      uVar2 = _splhigh();
      if ((*unaff_EBX & 8) != 0) break;
      _splx();
      uVar2 = _splbio();
      *(uint *)(unaff_EBX[4] + 0xc) = unaff_EBX[3];
      *(uint *)(unaff_EBX[3] + 0x10) = unaff_EBX[4];
      *(byte *)unaff_EBX = (byte)*unaff_EBX | 8;
      _splx(uVar2);
      unaff_ESI = *unaff_EBX;
      if ((unaff_ESI & 0x200) != 0) {
        *unaff_EBX = unaff_ESI & 0xfffffdf8;
        if ((int)unaff_EBX[6] < (int)unaff_EBX[5]) {
                    /* WARNING: Subroutine does not return */
          _panic(s_bwrite_001db583);
        }
        goto LAB_0011a7dd;
      }
      *unaff_EBX = unaff_ESI | 0x10000;
      if ((unaff_ESI & 0x40) != 0) {
        _wakeup();
      }
      if ((_bfreelist & 0x40) != 0) {
        _bfreelist = _bfreelist & 0xffffffbf;
        _wakeup();
      }
      if ((*unaff_EBX & 0x400200) == 0x400000) {
        *unaff_EBX = *unaff_EBX | 0x10000;
      }
      uVar1 = *unaff_EBX;
      if ((uVar1 & 4) != 0) {
        if ((uVar1 & 0x20000) == 0) {
          FUN_0011b26c();
        }
        else {
          *unaff_EBX = uVar1 & 0xfffffffb;
        }
      }
      _splhigh();
      if ((int)unaff_EBX[6] < 1) {
        DAT_001e8838[4] = (uint)unaff_EBX;
        unaff_EBX[3] = (uint)DAT_001e8838;
        DAT_001e8838 = unaff_EBX;
        unaff_EBX[4] = (uint)&DAT_001e882c;
      }
      else {
        uVar1 = *unaff_EBX;
        if ((uVar1 & 0x10004) == 0) {
          if ((uVar1 & 0x20000) == 0) {
            puVar3 = &DAT_001e87a4;
            if ((char)uVar1 < '\0') {
              puVar3 = (undefined4 *)&DAT_001e87e8;
            }
          }
          else {
            puVar3 = &_bfreelist;
          }
          *(uint **)(puVar3[4] + 0xc) = unaff_EBX;
          unaff_EBX[4] = puVar3[4];
          puVar3[4] = unaff_EBX;
          unaff_EBX[3] = (uint)puVar3;
        }
        else {
          DAT_001e87f4[4] = (uint)unaff_EBX;
          unaff_EBX[3] = (uint)DAT_001e87f4;
          DAT_001e87f4 = unaff_EBX;
          unaff_EBX[4] = (uint)&DAT_001e87e8;
        }
      }
      *unaff_EBX = *unaff_EBX & 0xffbffe37;
      _splx();
    }
    unaff_EBX = (uint *)unaff_EBX[1];
    if (*(uint **)(unaff_EBP + -0xc) == unaff_EBX) goto LAB_0011a90f;
  } while( true );
  *unaff_EBX = *unaff_EBX | 0x40;
  _sleep((uint)unaff_EBX);
  _splx(uVar2);
  goto LAB_0011a726;
}

