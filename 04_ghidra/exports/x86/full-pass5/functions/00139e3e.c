/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139e3e */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00139e3e(void)

{
  int iVar1;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  ushort unaff_BX;
  int *piVar6;
  int unaff_EBP;
  int unaff_ESI;
  int iVar7;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  code *pcVar2;
  
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    if (*(int *)(*(int *)(unaff_EBP + 0xc) + 0x14) == 0) {
      return 0;
    }
    iStack_4 = *(int *)(unaff_EBP + -4);
    iStack_8 = 0x139e5f;
    _smark();
  }
  if (*(int *)(unaff_ESI + 0x28) == 4) {
    if (*(int *)(unaff_EBP + 0x10) == 0) {
      *(int *)(unaff_EBP + -0x10) = (short)(unaff_BX >> 8) * 0xb;
      iStack_4 = (int)(short)unaff_BX;
      piVar6 = &iStack_4;
      pcVar2 = (code *)(&PTR__cnread_001e2f40)[*(int *)(unaff_EBP + -0x10)];
    }
    else {
      iStack_4 = *(int *)(unaff_EBP + -4);
      iStack_8 = 0x139e9f;
      _smark();
      *(int *)(unaff_EBP + -0x10) = (short)(unaff_BX >> 8) * 0xb;
      iStack_8 = *(int *)(unaff_EBP + 0xc);
      iStack_c = (int)(short)unaff_BX;
      piVar6 = &iStack_c;
      pcVar2 = (code *)(&PTR__cnwrite_001e2f44)[*(int *)(unaff_EBP + -0x10)];
    }
    *(undefined4 *)((int)piVar6 + -4) = 0x139ec3;
    iVar1 = (*pcVar2)();
    return iVar1;
  }
  if (*(int *)(unaff_ESI + 0x28) != 3) {
    return 0x2d;
  }
  if (*(int *)(*(int *)(unaff_EBP + 0xc) + 0x14) == 0) {
    return 0;
  }
  *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(*(int *)(unaff_EBP + -4) + 0x3c);
  do {
    uVar5 = *(uint *)(*(int *)(unaff_EBP + 0xc) + 8);
    uVar3 = uVar5 / 0x2000;
    uVar5 = uVar5 % 0x2000;
    *(uint *)(unaff_EBP + -0xc) = uVar5;
    iVar7 = 0x2000 - uVar5;
    iVar1 = *(int *)(*(int *)(unaff_EBP + 0xc) + 0x14);
    if (iVar1 < iVar7) {
      iVar7 = iVar1;
    }
    iVar1 = (int)(0x2000 / (ulonglong)*(uint *)(*(int *)(unaff_EBP + -4) + 0x48));
    iStack_4 = uVar3 * iVar1;
    _rablock = iVar1 + iStack_4;
    *(int *)(unaff_EBP + -0x14) = _rablock;
    _rasize = 0x2000;
    if (*(int *)(unaff_EBP + 0x10) == 0) {
      if (iStack_4 < 0) {
        iStack_4 = 0x139f69;
        pbVar4 = (byte *)_geteblk();
        iStack_4 = *(int *)(pbVar4 + 0x14);
        iStack_8 = *(int *)(pbVar4 + 0x20);
        iStack_c = 0x139f78;
        _blkclr();
        pbVar4[0x28] = 0;
        pbVar4[0x29] = 0;
        pbVar4[0x2a] = 0;
        pbVar4[0x2b] = 0;
      }
      else if (*(int *)(*(int *)(unaff_EBP + -4) + 0x44) + 1U == uVar3) {
        iStack_8 = 0x2000;
        iStack_c = iStack_4;
        iStack_4 = *(int *)(unaff_EBP + -0x14);
        pbVar4 = (byte *)_breada(*(undefined4 *)(unaff_EBP + -8));
      }
      else {
        iStack_8 = *(undefined4 *)(unaff_EBP + -8);
        iStack_c = 0x139fbf;
        pbVar4 = (byte *)_bread();
      }
      *(uint *)(*(int *)(unaff_EBP + -4) + 0x44) = uVar3;
    }
    else if (iVar7 == 0x2000) {
      iStack_8 = *(undefined4 *)(unaff_EBP + -8);
      iStack_c = 0x139fdf;
      pbVar4 = (byte *)_getblk();
    }
    else {
      iStack_8 = *(undefined4 *)(unaff_EBP + -8);
      iStack_c = 0x139ff3;
      pbVar4 = (byte *)_bread();
    }
    if (*(int *)(pbVar4 + 0x14) - *(int *)(pbVar4 + 0x28) < iVar7) {
      iVar7 = *(int *)(pbVar4 + 0x14) - *(int *)(pbVar4 + 0x28);
    }
    if ((*pbVar4 & 4) != 0) {
      iStack_4 = 0x139ef7;
      _brelse();
      return 5;
    }
    iStack_4 = *(int *)(unaff_EBP + 0x10);
    iStack_c = *(int *)(unaff_EBP + -0xc) + *(int *)(pbVar4 + 0x20);
    iStack_8 = iVar7;
    iVar1 = _uiomove();
    if (*(int *)(unaff_EBP + 0x10) == 0) {
      if (*(int *)(unaff_EBP + -0xc) + iVar7 == 0x2000) {
        *pbVar4 = *pbVar4 | 0x80;
      }
      iStack_4 = 0x13a042;
      _brelse();
    }
    else {
      if ((*(byte *)(unaff_EBP + 0x14) & 4) == 0) {
        if (*(int *)(unaff_EBP + -0xc) + iVar7 == 0x2000) {
          *pbVar4 = *pbVar4 | 0x80;
          iStack_4 = 0x13a06d;
          _bawrite();
        }
        else {
          iStack_4 = 0x13a076;
          _bdwrite();
        }
      }
      else {
        iStack_4 = 0x13a054;
        _bwrite();
      }
      iStack_4 = *(int *)(unaff_EBP + -4);
      iStack_8 = 0x13a084;
      _smark();
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)(*(int *)(unaff_EBP + 0xc) + 0x14) < 1) {
      return 0;
    }
  } while (iVar7 != 0);
  return 0;
}

