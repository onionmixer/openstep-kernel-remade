/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a6ec */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011a6ec(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  uint *unaff_EDI;
  
  *(uint *)(unaff_EBP + -4) = unaff_EDI[9];
  *(int *)(unaff_EBP + -8) =
       *(int *)(unaff_EBP + 0xc) / *(int *)(unaff_EBP + -0x10) + -1 + *(int *)(unaff_EBP + -4);
  iVar2 = *(int *)(unaff_EBP + -4);
  if (*(int *)(unaff_EBP + -4) < 0) {
    iVar2 = iVar2 + 7;
  }
  *(undefined **)(unaff_EBP + -0xc) = &_bufhash + ((iVar2 >> 3) + unaff_EDI[0x10] & 0xf) * 0xc;
LAB_0011a726:
  puVar4 = (uint *)(*(uint **)(unaff_EBP + -0xc))[1];
  if (puVar4 == *(uint **)(unaff_EBP + -0xc)) {
LAB_0011a90f:
    _allocbuf();
    return;
  }
  do {
    if ((((puVar4 != unaff_EDI) && (puVar4[0x10] == unaff_EDI[0x10])) && ((*puVar4 & 0x10000) == 0))
       && (((puVar4[5] != 0 && ((int)puVar4[9] <= *(int *)(unaff_EBP + -8))) &&
           (*(int *)(unaff_EBP + -4) <
            (int)((int)puVar4[5] / *(int *)(unaff_EBP + -0x10) + puVar4[9]))))) {
      uVar3 = _splhigh();
      if ((*puVar4 & 8) != 0) {
        *puVar4 = *puVar4 | 0x40;
        _sleep((uint)puVar4);
        _splx(uVar3);
        goto LAB_0011a726;
      }
      _splx();
      uVar3 = _splbio();
      *(uint *)(puVar4[4] + 0xc) = puVar4[3];
      *(uint *)(puVar4[3] + 0x10) = puVar4[4];
      *(byte *)puVar4 = (byte)*puVar4 | 8;
      _splx(uVar3);
      uVar1 = *puVar4;
      if ((uVar1 & 0x200) != 0) break;
      *puVar4 = uVar1 | 0x10000;
      if ((uVar1 & 0x40) != 0) {
        _wakeup();
      }
      if ((_bfreelist & 0x40) != 0) {
        _bfreelist = _bfreelist & 0xffffffbf;
        _wakeup();
      }
      if ((*puVar4 & 0x400200) == 0x400000) {
        *puVar4 = *puVar4 | 0x10000;
      }
      uVar1 = *puVar4;
      if ((uVar1 & 4) != 0) {
        if ((uVar1 & 0x20000) == 0) {
          FUN_0011b26c();
        }
        else {
          *puVar4 = uVar1 & 0xfffffffb;
        }
      }
      _splhigh();
      if ((int)puVar4[6] < 1) {
        DAT_001e8838[4] = (uint)puVar4;
        puVar4[3] = (uint)DAT_001e8838;
        DAT_001e8838 = puVar4;
        puVar4[4] = (uint)&DAT_001e882c;
      }
      else {
        uVar1 = *puVar4;
        if ((uVar1 & 0x10004) == 0) {
          if ((uVar1 & 0x20000) == 0) {
            puVar5 = &DAT_001e87a4;
            if ((char)uVar1 < '\0') {
              puVar5 = (undefined4 *)&DAT_001e87e8;
            }
          }
          else {
            puVar5 = &_bfreelist;
          }
          *(uint **)(puVar5[4] + 0xc) = puVar4;
          puVar4[4] = puVar5[4];
          puVar5[4] = puVar4;
          puVar4[3] = (uint)puVar5;
        }
        else {
          DAT_001e87f4[4] = (uint)puVar4;
          puVar4[3] = (uint)DAT_001e87f4;
          DAT_001e87f4 = puVar4;
          puVar4[4] = (uint)&DAT_001e87e8;
        }
      }
      *puVar4 = *puVar4 & 0xffbffe37;
      _splx();
    }
    puVar4 = (uint *)puVar4[1];
    if (*(uint **)(unaff_EBP + -0xc) == puVar4) goto LAB_0011a90f;
  } while( true );
  *puVar4 = uVar1 & 0xfffffdf8;
  if ((int)puVar4[6] < (int)puVar4[5]) {
                    /* WARNING: Subroutine does not return */
    _panic(s_bwrite_001db583);
  }
  (**(code **)(*(int *)(puVar4[0x10] + 0x1c) + 0x54))();
  if ((uVar1 & 0x100) == 0) {
    _biowait();
    _brelse(puVar4);
  }
  else {
    *(byte *)puVar4 = (byte)*puVar4 | 0x80;
  }
  goto LAB_0011a726;
}

