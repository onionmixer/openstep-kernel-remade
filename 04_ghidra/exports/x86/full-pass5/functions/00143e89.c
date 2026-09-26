/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143e89 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00143e89(void)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EBP;
  uint uVar7;
  int unaff_EDI;
  
  iVar3 = *(int *)(*(int *)(unaff_EBP + 0xc) + 8);
  if (-1 < iVar3) {
    iVar1 = *(int *)(*(int *)(unaff_EBP + 0xc) + 0x14);
    uVar5 = iVar3 + iVar1;
    if (-1 < (int)uVar5) {
      if (iVar1 == 0) {
        return 0;
      }
      if (*(int *)(unaff_EBP + 0x10) == 1) {
        if ((*(int *)(unaff_EBP + -0x18) == 0x8000) && (_active_u[0x9b] < uVar5)) {
          _psignal(*_active_u,(char *)0x19);
          return 0x1b;
        }
      }
      else {
        *(byte *)(unaff_EDI + 0x44) = *(byte *)(unaff_EDI + 0x44) | 4;
      }
      *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(unaff_EDI + 0x40);
      iVar3 = *(int *)(unaff_EDI + 0x50);
      *(int *)(unaff_EBP + -0xc) = iVar3;
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar3 + 0x30);
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      while( true ) {
        uVar5 = *(uint *)(*(int *)(unaff_EBP + 0xc) + 8);
        uVar6 = uVar5 % *(uint *)(unaff_EBP + -0x1c);
        *(uint *)(unaff_EBP + -0x14) = uVar6;
        *(uint *)(unaff_EBP + -0x10) = uVar5 / *(uint *)(unaff_EBP + -0x1c);
        uVar6 = *(int *)(unaff_EBP + -0x1c) - uVar6;
        uVar7 = *(uint *)(*(int *)(unaff_EBP + 0xc) + 0x14);
        if (uVar6 < uVar7) {
          uVar7 = uVar6;
        }
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          uVar5 = *(int *)(unaff_EDI + 0x6c) - uVar5;
          if ((int)uVar5 < 1) {
            *(undefined4 *)(unaff_EBP + -0x20) = 0;
            goto LAB_0014425a;
          }
          if ((int)uVar5 < (int)uVar7) {
            uVar7 = uVar5;
          }
        }
        iVar3 = _bmap();
        iVar3 = iVar3 << ((byte)*(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 100) & 0x1f);
        if ((((*(char *)(DAT_001e875c + 0x68) == '\x1c') && (*(int *)(unaff_EBP + 0x10) == 1)) &&
            (iVar1 = *(int *)(*(int *)(unaff_EBP + 0xc) + 0x14),
            *(int *)(unaff_EBP + -0x24) != iVar1 && -1 < *(int *)(unaff_EBP + -0x24) - iVar1)) &&
           ((*(byte *)(*_active_u + 0x16) & 2) != 0)) break;
        if (*(char *)(DAT_001e875c + 0x68) != '\0') {
LAB_00143fe7:
          *(int *)(unaff_EBP + -0x20) = (int)*(char *)(DAT_001e875c + 0x68);
          goto LAB_0014425a;
        }
        if (*(int *)(unaff_EBP + 0x10) == 1) {
          if (iVar3 < 0) goto LAB_00143fe7;
          if ((*(uint *)(unaff_EDI + 0x6c) < *(int *)(*(int *)(unaff_EBP + 0xc) + 8) + uVar7) &&
             (((*(int *)(unaff_EBP + -0x18) == 0x4000 || (*(int *)(unaff_EBP + -0x18) == 0x8000)) ||
              (*(int *)(unaff_EBP + -0x18) == 0xa000)))) {
            uVar5 = *(int *)(*(int *)(unaff_EBP + 0xc) + 8) + uVar7;
            *(uint *)(unaff_EDI + 0x6c) = uVar5;
            iVar1 = *(int *)(unaff_EDI + 0xc);
            *(int *)(unaff_EBP + -0x2c) = iVar1;
            if (*(uint *)(iVar1 + 0x14) < uVar5) {
              *(uint *)(iVar1 + 0x14) = uVar5;
            }
            if ((*(byte *)(unaff_EBP + 0x14) & 4) != 0) {
              *(undefined4 *)(unaff_EBP + -4) = 1;
            }
          }
        }
        if ((*(int *)(unaff_EBP + -0x10) < 0xc) &&
           (*(uint *)(unaff_EDI + 0x6c) <
            (uint)(*(int *)(unaff_EBP + -0x10) + 1 <<
                  ((byte)*(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x50) & 0x1f)))) {
          uVar5 = ((*(uint *)(unaff_EDI + 0x6c) & ~*(uint *)(*(int *)(unaff_EBP + -0xc) + 0x48)) +
                  *(int *)(*(int *)(unaff_EBP + -0xc) + 0x34)) - 1 &
                  *(uint *)(*(int *)(unaff_EBP + -0xc) + 0x4c);
        }
        else {
          uVar5 = *(uint *)(*(int *)(unaff_EBP + -0xc) + 0x30);
        }
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          if (iVar3 < 0) {
            puVar4 = (uint *)_geteblk();
            _blkclr(puVar4[8],puVar4[5]);
            puVar4[10] = 0;
          }
          else if (*(int *)(unaff_EBP + -0x10) == *(int *)(unaff_EDI + 0x58) + 1) {
            puVar4 = (uint *)_breada(*(undefined4 *)(unaff_EBP + -8),iVar3,uVar5,_rablock);
          }
          else {
            puVar4 = (uint *)_bread(*(undefined4 *)(unaff_EBP + -8),iVar3);
          }
          *(undefined4 *)(unaff_EDI + 0x58) = *(undefined4 *)(unaff_EBP + -0x10);
        }
        else if (*(uint *)(unaff_EBP + -0x1c) == uVar7) {
          puVar4 = (uint *)_getblk(*(undefined4 *)(unaff_EBP + -8),iVar3);
        }
        else {
          puVar4 = (uint *)_bread(*(undefined4 *)(unaff_EBP + -8),iVar3);
        }
        uVar5 = puVar4[5];
        *(uint *)(unaff_EBP + -0x2c) = uVar5;
        uVar5 = uVar5 - puVar4[10];
        if ((int)uVar5 < (int)uVar7) {
          uVar7 = uVar5;
        }
        if ((*puVar4 & 4) != 0) {
          *(undefined4 *)(unaff_EBP + -0x20) = 5;
          _brelse();
          goto LAB_0014425a;
        }
        if ((*(ushort *)(unaff_EDI + 100) & 0xf000) == 0x4000) {
          _byte_swap_dir_block_in(puVar4[8]);
        }
        uVar2 = _uiomove(*(int *)(unaff_EBP + -0x14) + puVar4[8],uVar7,
                         *(undefined4 *)(unaff_EBP + 0x10));
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
        if ((*(ushort *)(unaff_EDI + 100) & 0xf000) == 0x4000) {
          _byte_swap_dir_block_out();
        }
        if (((((*(byte *)(unaff_EBP + 0x14) & 4) != 0) &&
             ((*(ushort *)(unaff_EDI + 100) & 0x200) != 0)) && (_stickyhack != 0)) &&
           ((*(ushort *)(unaff_EDI + 100) & 0x49) == 0)) {
          *puVar4 = *puVar4 | 0x400000;
        }
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          if ((*(int *)(unaff_EBP + -0x1c) == *(int *)(unaff_EBP + -0x14) + uVar7) ||
             (*(int *)(*(int *)(unaff_EBP + 0xc) + 8) == *(int *)(unaff_EDI + 0x6c))) {
            *(byte *)puVar4 = (byte)*puVar4 | 0x80;
          }
          _brelse();
        }
        else {
          if (((*(byte *)(unaff_EBP + 0x14) & 4) == 0) &&
             ((*(ushort *)(unaff_EDI + 100) & 0xf000) != 0x4000)) {
            if (*(int *)(unaff_EBP + -0x1c) == *(int *)(unaff_EBP + -0x14) + uVar7) {
              *(byte *)puVar4 = (byte)*puVar4 | 0x80;
              _bawrite();
            }
            else {
              _bdwrite();
            }
          }
          else {
            _bwrite();
          }
          *(byte *)(unaff_EDI + 0x44) = *(byte *)(unaff_EDI + 0x44) | 0x42;
          if (*(short *)(_active_u[7] + 6) != 0) {
            *(ushort *)(unaff_EDI + 100) = *(ushort *)(unaff_EDI + 100) & 0xf3ff;
          }
        }
        if (((*(char *)(DAT_001e875c + 0x68) != '\0') ||
            (*(int *)(*(int *)(unaff_EBP + 0xc) + 0x14) < 1)) || (uVar7 == 0)) goto LAB_0014423a;
      }
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
LAB_0014423a:
      if (*(int *)(unaff_EBP + -4) != 0) {
        _iupdat();
      }
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(int *)(unaff_EBP + -0x20) = (int)*(char *)(DAT_001e875c + 0x68);
      }
LAB_0014425a:
      return *(undefined4 *)(unaff_EBP + -0x20);
    }
  }
  return 0x16;
}

