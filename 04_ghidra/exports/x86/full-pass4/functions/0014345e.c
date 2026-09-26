/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014345e */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0014345e(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  void *pvVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 uVar10;
  int unaff_EBP;
  
  pbVar9 = (byte *)(*(int *)(unaff_EBP + 0x10) + 0xc);
  *pbVar9 = *pbVar9 | 1;
  _byte_swap_superblock();
  *(undefined4 *)(unaff_EBP + -0x50) = 0;
  iVar2 = *(int *)(*(int *)(unaff_EBP + -0x4c) + 0x20);
  uVar3 = *(uint *)(*(int *)(unaff_EBP + 0x10) + 0xc);
  if ((uVar3 & 1) == 0) {
    if (*(char *)(iVar2 + 0xd1) == '\x01') {
      *(undefined1 *)(iVar2 + 0xd1) = 2;
    }
    else {
      *(undefined1 *)(iVar2 + 0xd1) = 3;
    }
    *(undefined1 *)(iVar2 + 0xd0) = 1;
    *(undefined1 *)(iVar2 + 0xd2) = 0;
    if ((*(byte *)(*(int *)(unaff_EBP + 0x10) + 0xc) & 0x40) != 0) {
      if (*(int *)(unaff_EBP + -0x50) != 0) {
        _brelse();
      }
      puVar1 = (uint *)(*(int *)(unaff_EBP + 0x10) + 0xc);
      *puVar1 = *puVar1 & 0xffffffbf;
      _sbupdate();
      return 0;
    }
  }
  else {
    if ((uVar3 & 0x40) != 0) {
      _printf(s_mountfs__can_t_remount_ro_001de458);
      *(undefined4 *)(unaff_EBP + -0x54) = 0x16;
LAB_00143707:
      if (*(int *)(unaff_EBP + -0x54) == 0) {
        *(undefined4 *)(unaff_EBP + -0x54) = 5;
      }
      goto LAB_00143714;
    }
    *(undefined1 *)(iVar2 + 0xd0) = 0;
    *(undefined1 *)(iVar2 + 0xd2) = 1;
  }
  *(undefined4 *)(*(int *)(unaff_EBP + 0x10) + 0x10) = *(undefined4 *)(iVar2 + 0x30);
  *(int *)(unaff_EBP + -0x58) =
       (*(int *)(iVar2 + 0x34) + -1 + *(int *)(iVar2 + 0x9c)) / *(int *)(iVar2 + 0x34);
  iVar8 = _kalloc();
  *(int *)(unaff_EBP + -0x5c) = iVar8;
  if (iVar8 != 0) {
    iVar8 = 0;
    if (0 < *(int *)(unaff_EBP + -0x58)) {
      do {
        *(undefined4 *)(unaff_EBP + -0x84) = *(undefined4 *)(iVar2 + 0x30);
        if (*(int *)(unaff_EBP + -0x58) < iVar8 + *(int *)(iVar2 + 0x38)) {
          *(int *)(unaff_EBP + -0x84) =
               (*(int *)(unaff_EBP + -0x58) - iVar8) * *(int *)(iVar2 + 0x34);
        }
        sVar4 = *(size_t *)(unaff_EBP + -0x84);
        pbVar9 = (byte *)_bread(*(undefined4 *)(*(int *)(unaff_EBP + -0x48) + 8),
                                *(int *)(iVar2 + 0x98) + iVar8 <<
                                ((byte)*(undefined4 *)(iVar2 + 100) & 0x1f));
        *(byte **)(unaff_EBP + -0x50) = pbVar9;
        if ((*pbVar9 & 4) != 0) {
          _kfree(*(undefined4 *)(unaff_EBP + -0x5c));
          goto LAB_00143707;
        }
        pvVar5 = *(void **)(unaff_EBP + -0x5c);
        _bcopy(*(void **)(*(int *)(unaff_EBP + -0x50) + 0x20),pvVar5,sVar4);
        _byte_swap_ints(pvVar5,*(uint *)(unaff_EBP + -0x84) >> 2);
        iVar6 = *(int *)(unaff_EBP + -0x5c);
        *(int *)(iVar2 + 0x2d8 + (iVar8 >> ((byte)*(undefined4 *)(iVar2 + 0x60) & 0x1f)) * 4) =
             iVar6;
        *(int *)(unaff_EBP + -0x5c) = iVar6 + *(int *)(unaff_EBP + -0x84);
        _brelse(*(undefined4 *)(unaff_EBP + -0x50));
        iVar8 = iVar8 + *(int *)(iVar2 + 0x38);
      } while (iVar8 < *(int *)(unaff_EBP + -0x58));
    }
    if (*(char *)(iVar2 + 0xd2) == '\0') {
      _sbupdate();
    }
    *(byte *)(iVar2 + 0xd3) = *(byte *)(iVar2 + 0xd3) & 0xfc;
    iVar8 = (*(int *)(iVar2 + 0x28) * *(int *)(iVar2 + 0x3c)) / 100;
    *(int *)(iVar2 + 0x8c) = iVar8;
    *(int *)(iVar2 + 0x88) = iVar8;
    if (iVar8 < 0x65) {
      iVar8 = iVar8 * 2;
    }
    else {
      iVar8 = iVar8 + 100;
    }
    *(int *)(iVar2 + 0x88) = iVar8;
    iVar8 = (*(int *)(iVar2 + 0x2c) * *(int *)(iVar2 + 0xb8)) / 100;
    *(int *)(iVar2 + 0x94) = iVar8;
    if (0x32 < iVar8) {
      *(undefined4 *)(iVar2 + 0x94) = 0x32;
    }
    *(undefined4 *)(iVar2 + 0x90) = *(undefined4 *)(iVar2 + 0x94);
    iVar8 = *(int *)(unaff_EBP + -0x48);
    *(undefined2 *)(iVar8 + 4) = *(undefined2 *)(*(int *)(*(int *)(unaff_EBP + -0x48) + 8) + 0x2c);
    iVar6 = *(int *)(unaff_EBP + 0x10);
    *(int *)(iVar6 + 0x14) = (int)*(short *)(iVar8 + 4);
    *(undefined4 *)(iVar6 + 0x18) = 0;
    _copystr(*(undefined4 *)(unaff_EBP + 0xc),iVar2 + 0xd4,0x1ff);
    pvVar5 = (void *)(iVar2 + 0xd4 + *(int *)(unaff_EBP + -0x44));
    *(void **)(unaff_EBP + -100) = pvVar5;
    _bzero(pvVar5,0x200 - *(int *)(unaff_EBP + -0x44));
    return 0;
  }
  *(undefined4 *)(unaff_EBP + -0x54) = 0xc;
LAB_00143714:
  if (*(int *)(unaff_EBP + -0x48) != 0) {
    *(undefined4 *)(*(int *)(unaff_EBP + -0x48) + 0xc) = 0;
  }
  if (*(int *)(unaff_EBP + -0x4c) != 0) {
    _brelse();
  }
  if (*(int *)(unaff_EBP + -0x50) != 0) {
    _brelse();
  }
  if (*(int *)(unaff_EBP + -0x60) != 0) {
    iVar2 = **(int **)(unaff_EBP + 8);
    uVar10 = 3;
    if ((*(byte *)(*(int *)(unaff_EBP + 0x10) + 0xc) & 1) != 0) {
      uVar10 = 1;
    }
    pcVar7 = *(code **)(*(int *)(iVar2 + 0x1c) + 4);
    *(code **)(unaff_EBP + -100) = pcVar7;
    (*pcVar7)(iVar2,uVar10,1);
    _binval(**(undefined4 **)(unaff_EBP + 8));
  }
  return *(undefined4 *)(unaff_EBP + -0x54);
}

