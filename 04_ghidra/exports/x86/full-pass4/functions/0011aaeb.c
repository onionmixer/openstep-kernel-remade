/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011aaeb */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011aaeb(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *unaff_EBX;
  
  uVar1 = *unaff_EBX;
  *unaff_EBX = uVar1 | 2;
  if ((uVar1 & 0x200000) == 0) {
    if ((uVar1 & 0x100) == 0) {
      *unaff_EBX = CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 | 2)) & 0xffffffbf;
      _wakeup();
    }
    else {
      if ((uVar1 & 0x40) != 0) {
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
            puVar2 = &DAT_001e87a4;
            if ((char)uVar1 < '\0') {
              puVar2 = (undefined4 *)&DAT_001e87e8;
            }
          }
          else {
            puVar2 = &_bfreelist;
          }
          *(uint **)(puVar2[4] + 0xc) = unaff_EBX;
          unaff_EBX[4] = puVar2[4];
          puVar2[4] = unaff_EBX;
          unaff_EBX[3] = (uint)puVar2;
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
  }
  else {
    *unaff_EBX = uVar1 & 0xffdfffff | 2;
    (*(code *)unaff_EBX[0xc])();
  }
  return;
}

