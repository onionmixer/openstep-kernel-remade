/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013149d */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0013149d(void)

{
  byte *pbVar1;
  short sVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int unaff_EBP;
  uint uVar7;
  uint unaff_EDI;
  undefined4 uVar8;
  
  *(int *)(unaff_EBP + -100) = unaff_EBP + -0x44;
  do {
    uVar7 = *(uint *)(*(int *)(unaff_EBP + 0xc) + 8);
    uVar6 = uVar7 % unaff_EDI;
    *(uint *)(unaff_EBP + -0x54) = uVar6;
    *(uint *)(unaff_EBP + -0x60) = uVar7 / unaff_EDI;
    uVar6 = unaff_EDI - uVar6;
    uVar7 = *(uint *)(*(int *)(unaff_EBP + 0xc) + 0x14);
    if (uVar6 < uVar7) {
      uVar7 = uVar6;
    }
    (**(code **)(*(int *)(*(int *)(unaff_EBP + 8) + 0x1c) + 0x50))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x60),
               *(undefined4 *)(unaff_EBP + -100));
    if ((*(byte *)(*(int *)(unaff_EBP + 8) + 4) & 0x40) == 0) {
      if (*(int *)(unaff_EBP + 0x10) == 0) {
        if (*(int *)(unaff_EBP + -0x60) < 0) {
          pbVar3 = (byte *)_geteblk();
          _blkclr(*(undefined4 *)(pbVar3 + 0x20),*(undefined4 *)(pbVar3 + 0x14));
          pbVar3[0x28] = 0;
          pbVar3[0x29] = 0;
          pbVar3[0x2a] = 0;
          pbVar3[0x2b] = 0;
        }
        else {
          iVar4 = _incore(*(undefined4 *)(unaff_EBP + -0x44));
          if (iVar4 != 0) {
            _nfs_validate_caches
                      (*(undefined4 *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + 0x18));
          }
          iVar4 = *(int *)(*(int *)(unaff_EBP + -0x50) + 100);
          if (*(int *)(unaff_EBP + -0x60) == iVar4 + 1) {
            *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x1c);
            (**(code **)(*(int *)(unaff_EBP + -0x68) + 0x50))
                      (*(undefined4 *)(unaff_EBP + 8),iVar4 + 2,*(undefined4 *)(unaff_EBP + -100));
            pbVar3 = (byte *)_breada(*(undefined4 *)(unaff_EBP + -0x44),
                                     *(undefined4 *)(unaff_EBP + -0x48));
          }
          else {
            uVar5 = *(undefined4 *)(unaff_EBP + -0x48);
            uVar8 = *(undefined4 *)(unaff_EBP + -0x44);
LAB_00131621:
            pbVar3 = (byte *)_bread(uVar8,uVar5);
          }
        }
      }
      else {
        sVar2 = *(short *)(*(int *)(unaff_EBP + -0x50) + 0x62);
        if (sVar2 != 0) {
          iVar4 = (int)sVar2;
          goto LAB_00131746;
        }
        if (uVar7 != unaff_EDI) {
          uVar5 = *(undefined4 *)(unaff_EBP + -0x48);
          uVar8 = *(undefined4 *)(unaff_EBP + -0x44);
          goto LAB_00131621;
        }
        pbVar3 = (byte *)_getblk(*(undefined4 *)(unaff_EBP + -0x44),
                                 *(undefined4 *)(unaff_EBP + -0x48));
      }
    }
    else {
      pbVar3 = (byte *)_geteblk();
      if (*(int *)(unaff_EBP + 0x10) == 0) {
        iVar4 = FUN_001318d4(*(undefined4 *)(unaff_EBP + 8),
                             *(int *)(unaff_EBP + -0x54) + *(int *)(pbVar3 + 0x20),
                             *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 8),uVar7,pbVar3 + 0x28,
                             *(undefined4 *)(unaff_EBP + 0x18));
        *(int *)(unaff_EBP + -0x58) = iVar4;
        if (iVar4 != 0) {
          _brelse();
          goto LAB_00131749;
        }
      }
    }
    if ((*pbVar3 & 4) != 0) {
      uVar5 = _geterror();
      *(undefined4 *)(unaff_EBP + -0x58) = uVar5;
      _brelse(pbVar3);
      goto LAB_00131749;
    }
    if (*(int *)(unaff_EBP + 0x10) == 0) {
      iVar4 = *(int *)(unaff_EBP + -0x50);
      *(undefined4 *)(iVar4 + 100) = *(undefined4 *)(unaff_EBP + -0x60);
      uVar6 = *(int *)(iVar4 + 0x98) - *(int *)(*(int *)(unaff_EBP + 0xc) + 8);
      if ((int)uVar6 < 1) {
        _brelse();
        *(undefined4 *)(unaff_EBP + -0x58) = 0;
        goto LAB_00131749;
      }
      if ((int)uVar6 < (int)uVar7) {
        *(undefined4 *)(unaff_EBP + -0x5c) = 1;
        uVar7 = uVar6;
      }
    }
    uVar5 = _uiomove(*(int *)(unaff_EBP + -0x54) + *(int *)(pbVar3 + 0x20),uVar7,
                     *(undefined4 *)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP + -0x6c) = uVar5;
    *(undefined1 *)(DAT_001e875c + 0x68) = *(undefined1 *)(unaff_EBP + -0x6c);
    if (*(int *)(unaff_EBP + 0x10) == 0) {
      _brelse();
    }
    else {
      uVar6 = *(uint *)(*(int *)(unaff_EBP + 0xc) + 8);
      if (*(uint *)(*(int *)(unaff_EBP + -0x50) + 0x98) < uVar6) {
        *(uint *)(*(int *)(unaff_EBP + -0x50) + 0x98) = uVar6;
        iVar4 = **(int **)(unaff_EBP + 8);
        *(int *)(unaff_EBP + -0x6c) = iVar4;
        if (*(uint *)(iVar4 + 0x14) < uVar6) {
          *(uint *)(iVar4 + 0x14) = uVar6;
        }
      }
      if ((*(byte *)(*(int *)(unaff_EBP + 8) + 4) & 0x40) == 0) {
        pbVar1 = (byte *)(*(int *)(unaff_EBP + -0x50) + 0x60);
        *pbVar1 = *pbVar1 | 0x10;
        if (*(int *)(unaff_EBP + -0x54) + uVar7 == unaff_EDI) {
          *pbVar3 = *pbVar3 | 0x80;
          _bawrite();
        }
        else {
          _bdwrite();
        }
      }
      else {
        uVar5 = _nfswrite(*(undefined4 *)(unaff_EBP + 8),
                          *(int *)(unaff_EBP + -0x54) + *(int *)(pbVar3 + 0x20),
                          *(int *)(*(int *)(unaff_EBP + 0xc) + 8) - uVar7,uVar7);
        *(undefined4 *)(unaff_EBP + -0x58) = uVar5;
        _brelse(pbVar3);
      }
    }
  } while (((*(char *)(DAT_001e875c + 0x68) == '\0') &&
           (0 < *(int *)(*(int *)(unaff_EBP + 0xc) + 0x14))) && (*(int *)(unaff_EBP + -0x5c) == 0));
  if (*(int *)(unaff_EBP + -0x58) == 0) {
    iVar4 = (int)*(char *)(DAT_001e875c + 0x68);
LAB_00131746:
    *(int *)(unaff_EBP + -0x58) = iVar4;
  }
LAB_00131749:
  _runlock();
  return *(undefined4 *)(unaff_EBP + -0x58);
}

