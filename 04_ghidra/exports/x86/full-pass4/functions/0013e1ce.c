/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013e1ce */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013e1ce(void)

{
  byte *pbVar1;
  short *psVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 uVar8;
  int iVar9;
  undefined1 uVar10;
  int unaff_EBP;
  int unaff_EDI;
  
  if ((**(char **)(unaff_EBP + 0xc) != '.') ||
     ((unaff_EDI != 1 && ((unaff_EDI != 2 || ((*(char **)(unaff_EBP + 0xc))[1] != '.')))))) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -8) = 0;
    if (*(int *)(unaff_EBP + 0x10) != 0) {
      while (uVar5 = *(uint *)(unaff_EBP + 0x18), (*(byte *)(uVar5 + 0x44) & 1) != 0) {
        *(byte *)(uVar5 + 0x44) = *(byte *)(uVar5 + 0x44) | 0x10;
        _sleep(uVar5);
      }
      iVar9 = *(int *)(unaff_EBP + 0x18);
      uVar3 = *(ushort *)(iVar9 + 0x44);
      *(ushort *)(iVar9 + 0x44) = uVar3 | 1;
      sVar4 = *(short *)(iVar9 + 0x66);
      uVar10 = (undefined1)(uVar3 | 1);
      uVar8 = (undefined1)(uVar3 >> 8);
      if (sVar4 == 0) {
        *(ushort *)(iVar9 + 0x44) = CONCAT11(uVar8,uVar10) & 0xfffe;
        if ((uVar3 & 0x10) != 0) {
          *(ushort *)(iVar9 + 0x44) = uVar3 & 0xffee;
          _wakeup();
        }
        return 2;
      }
      if (sVar4 == 0x7fff) {
        *(ushort *)(iVar9 + 0x44) = CONCAT11(uVar8,uVar10) & 0xfffe;
        if ((uVar3 & 0x10) != 0) {
          *(ushort *)(iVar9 + 0x44) = uVar3 & 0xffee;
          _wakeup();
        }
        return 0x1f;
      }
      *(short *)(iVar9 + 0x66) = sVar4 + 1;
      *(byte *)(iVar9 + 0x44) = *(byte *)(iVar9 + 0x44) | 0x40;
      _iupdat(iVar9);
      iVar9 = *(int *)(unaff_EBP + 0x18);
      uVar3 = *(ushort *)(iVar9 + 0x44);
      *(ushort *)(iVar9 + 0x44) = uVar3 & 0xfffe;
      if ((uVar3 & 0x10) != 0) {
        *(ushort *)(iVar9 + 0x44) = uVar3 & 0xffee;
        _wakeup();
      }
    }
    while (uVar3 = *(ushort *)(*(int *)(unaff_EBP + 8) + 0x44), (uVar3 & 1) != 0) {
      uVar5 = *(uint *)(unaff_EBP + 8);
      *(ushort *)(uVar5 + 0x44) = uVar3 | 0x10;
      _sleep(uVar5);
    }
    iVar9 = *(int *)(unaff_EBP + 8);
    pbVar1 = (byte *)(iVar9 + 0x44);
    *pbVar1 = *pbVar1 | 1;
    if ((*(ushort *)(iVar9 + 100) & 0xf000) == 0x4000) {
      if (*(short *)(*(int *)(unaff_EBP + 8) + 0x66) == 0) {
        iVar9 = 2;
      }
      else {
        iVar9 = _iaccess(*(undefined4 *)(unaff_EBP + 8));
        if ((iVar9 == 0) &&
           ((((*(int *)(unaff_EBP + 0x10) != 2 ||
              ((*(ushort *)(*(int *)(unaff_EBP + 0x18) + 100) & 0xf000) != 0x4000)) ||
             (*(int *)(unaff_EBP + 0x14) == *(int *)(unaff_EBP + 8))) ||
            ((iVar9 = _iaccess(*(int *)(unaff_EBP + 0x18)), iVar9 == 0 &&
             (iVar9 = FUN_0013f66c(*(undefined4 *)(unaff_EBP + 0x18)), iVar9 == 0)))))) {
          *(int *)(unaff_EBP + -0x1c) = unaff_EBP + -0x14;
          iVar9 = FUN_0013e5c8(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
          if (iVar9 == 0) {
            if (*(int *)(unaff_EBP + -0x18) == 0) {
              uVar6 = *(undefined4 *)(unaff_EBP + 8);
              iVar9 = _iaccess(uVar6);
              if ((iVar9 == 0) &&
                 ((*(int *)(unaff_EBP + 0x10) != 0 ||
                  (iVar9 = FUN_0013ef04(uVar6,unaff_EBP + 0x18), iVar9 == 0)))) {
                iVar7 = *(int *)(unaff_EBP + 8);
                iVar9 = _diraddentry(iVar7,*(undefined4 *)(unaff_EBP + 0xc));
                if (iVar9 == 0) {
                  if (*(int *)(unaff_EBP + 0x20) == 0) {
                    if (*(int *)(unaff_EBP + 0x10) == 0) {
                      _irele();
                    }
                  }
                  else {
                    while (uVar5 = *(uint *)(unaff_EBP + 0x18), (*(byte *)(uVar5 + 0x44) & 1) != 0)
                    {
                      *(byte *)(uVar5 + 0x44) = *(byte *)(uVar5 + 0x44) | 0x10;
                      _sleep(uVar5);
                    }
                    iVar7 = *(int *)(unaff_EBP + 0x18);
                    pbVar1 = (byte *)(iVar7 + 0x44);
                    *pbVar1 = *pbVar1 | 1;
                    **(int **)(unaff_EBP + 0x20) = iVar7;
                  }
                }
                else if (*(int *)(unaff_EBP + 0x10) == 0) {
                  if ((*(ushort *)(*(int *)(unaff_EBP + 0x18) + 100) & 0xf000) == 0x4000) {
                    psVar2 = (short *)(iVar7 + 0x66);
                    *psVar2 = *psVar2 + -1;
                  }
                  iVar7 = *(int *)(unaff_EBP + 0x18);
                  *(undefined2 *)(iVar7 + 0x66) = 0;
                  pbVar1 = (byte *)(iVar7 + 0x44);
                  *pbVar1 = *pbVar1 | 0x40;
                  _irele();
                  *(undefined4 *)(unaff_EBP + 0x18) = 0;
                }
              }
            }
            else if (*(int *)(unaff_EBP + 0x10) == 1) {
              _iput();
              iVar9 = 0x11;
            }
            else if (*(int *)(unaff_EBP + 0x10) == 0) {
              if (*(int *)(unaff_EBP + 0x20) == 0) {
                _iput();
              }
              else {
                **(int **)(unaff_EBP + 0x20) = *(int *)(unaff_EBP + -0x18);
                iVar9 = 0x11;
              }
            }
            else if (*(int *)(unaff_EBP + 0x10) == 2) {
              iVar9 = FUN_0013e838(*(undefined4 *)(unaff_EBP + 0x14),
                                   *(undefined4 *)(unaff_EBP + 0x18),*(undefined4 *)(unaff_EBP + 8),
                                   *(undefined4 *)(unaff_EBP + 0xc));
              _iput(*(undefined4 *)(unaff_EBP + -0x18));
              if (*(short *)(*(int *)(unaff_EBP + -0x18) + 0x66) == 0) {
                _vnode_uncache();
              }
            }
          }
        }
      }
    }
    else {
      iVar9 = 0x14;
    }
    iVar7 = *(int *)(unaff_EBP + -8);
    if (iVar7 != 0) {
      _byte_swap_dir_block_out();
      _brelse(iVar7);
    }
    if ((iVar9 != 0) && (*(int *)(unaff_EBP + 0x10) != 0)) {
      iVar7 = *(int *)(unaff_EBP + 0x18);
      psVar2 = (short *)(iVar7 + 0x66);
      *psVar2 = *psVar2 + -1;
      pbVar1 = (byte *)(iVar7 + 0x44);
      *pbVar1 = *pbVar1 | 0x40;
    }
    iVar7 = *(int *)(unaff_EBP + 8);
    uVar3 = *(ushort *)(iVar7 + 0x44);
    *(ushort *)(iVar7 + 0x44) = uVar3 & 0xfffe;
    if ((uVar3 & 0x10) != 0) {
      *(ushort *)(iVar7 + 0x44) = uVar3 & 0xffee;
      _wakeup();
    }
    return iVar9;
  }
  if (*(int *)(unaff_EBP + 0x10) == 2) {
    return 0x42;
  }
  if ((*(int *)(unaff_EBP + 0x20) != 0) &&
     (iVar9 = _dirlook(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc)), iVar9 != 0)
     ) {
    return iVar9;
  }
  return 0x11;
}

