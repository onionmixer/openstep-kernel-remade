/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143e24 */

int FUN_00143e24(int param_1,int param_2,uint param_3,byte param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  int local_8;
  
  local_8 = 0;
  iVar1 = *(int *)(param_2 + 0x14);
  if (1 < param_3) {
                    /* WARNING: Subroutine does not return */
    _panic(&DAT_001de510);
  }
  uVar11 = *(ushort *)(param_1 + 100) & 0xf000;
  if (((uVar11 != 0x8000) && (uVar11 != 0x4000)) && (uVar11 != 0xa000)) {
                    /* WARNING: Subroutine does not return */
    _panic(s_rwip_type_001de515);
  }
  if (-1 < *(int *)(param_2 + 8)) {
    uVar8 = *(int *)(param_2 + 8) + *(int *)(param_2 + 0x14);
    if (-1 < (int)uVar8) {
      if (*(int *)(param_2 + 0x14) == 0) {
        return 0;
      }
      if (param_3 == 1) {
        if ((uVar11 == 0x8000) && (_active_u[0x9b] < uVar8)) {
          _psignal(*_active_u,(char *)0x19);
          return 0x1b;
        }
      }
      else {
        *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 4;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x40);
      iVar3 = *(int *)(param_1 + 0x50);
      uVar8 = *(uint *)(iVar3 + 0x30);
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      while( true ) {
        uVar9 = *(uint *)(param_2 + 8);
        uVar5 = uVar9 / uVar8;
        uVar12 = uVar9 % uVar8;
        uVar13 = *(uint *)(param_2 + 0x14);
        if (uVar8 - uVar12 < *(uint *)(param_2 + 0x14)) {
          uVar13 = uVar8 - uVar12;
        }
        if (param_3 == 0) {
          uVar9 = *(int *)(param_1 + 0x6c) - uVar9;
          if ((int)uVar9 < 1) {
            return 0;
          }
          if ((int)uVar9 < (int)uVar13) {
            uVar13 = uVar9;
          }
        }
        piVar10 = (int *)0x0;
        if ((param_4 & 4) != 0) {
          piVar10 = &local_8;
        }
        iVar6 = _bmap(param_1,uVar5,param_3 != 1,uVar12 + uVar13,piVar10);
        iVar6 = iVar6 << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f);
        if (((*(char *)(DAT_001e875c + 0x68) == '\x1c') && (param_3 == 1)) &&
           ((iVar1 != *(int *)(param_2 + 0x14) && -1 < iVar1 - *(int *)(param_2 + 0x14) &&
            ((*(byte *)(*_active_u + 0x16) & 2) != 0)))) break;
        if (*(char *)(DAT_001e875c + 0x68) != '\0') {
LAB_00143fe7:
          return (int)*(char *)(DAT_001e875c + 0x68);
        }
        if (param_3 == 1) {
          if (iVar6 < 0) goto LAB_00143fe7;
          if ((*(uint *)(param_1 + 0x6c) < *(int *)(param_2 + 8) + uVar13) &&
             (((uVar11 == 0x4000 || (uVar11 == 0x8000)) || (uVar11 == 0xa000)))) {
            uVar9 = *(int *)(param_2 + 8) + uVar13;
            *(uint *)(param_1 + 0x6c) = uVar9;
            if (*(uint *)(*(int *)(param_1 + 0xc) + 0x14) < uVar9) {
              *(uint *)(*(int *)(param_1 + 0xc) + 0x14) = uVar9;
            }
            if ((param_4 & 4) != 0) {
              local_8 = 1;
            }
          }
        }
        if (((int)uVar5 < 0xc) &&
           (*(uint *)(param_1 + 0x6c) < uVar5 + 1 << ((byte)*(undefined4 *)(iVar3 + 0x50) & 0x1f)))
        {
          uVar9 = ((*(uint *)(param_1 + 0x6c) & ~*(uint *)(iVar3 + 0x48)) + *(int *)(iVar3 + 0x34))
                  - 1 & *(uint *)(iVar3 + 0x4c);
        }
        else {
          uVar9 = *(uint *)(iVar3 + 0x30);
        }
        if (param_3 == 0) {
          if (iVar6 < 0) {
            puVar7 = (uint *)_geteblk(uVar9);
            _blkclr(puVar7[8],puVar7[5]);
            puVar7[10] = 0;
          }
          else if (uVar5 == *(int *)(param_1 + 0x58) + 1U) {
            puVar7 = (uint *)_breada(uVar2,iVar6,uVar9,_rablock,_rasize);
          }
          else {
            puVar7 = (uint *)_bread(uVar2,iVar6,uVar9);
          }
          *(uint *)(param_1 + 0x58) = uVar5;
        }
        else if (uVar8 == uVar13) {
          puVar7 = (uint *)_getblk(uVar2,iVar6,uVar9);
        }
        else {
          puVar7 = (uint *)_bread(uVar2,iVar6,uVar9);
        }
        uVar9 = puVar7[5] - puVar7[10];
        if ((int)uVar9 < (int)uVar13) {
          uVar13 = uVar9;
        }
        if ((*puVar7 & 4) != 0) {
          _brelse(puVar7);
          return 5;
        }
        if ((*(ushort *)(param_1 + 100) & 0xf000) == 0x4000) {
          _byte_swap_dir_block_in(puVar7[8],puVar7[5]);
        }
        uVar4 = _uiomove(uVar12 + puVar7[8],uVar13,param_3,param_2);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
        if ((*(ushort *)(param_1 + 100) & 0xf000) == 0x4000) {
          _byte_swap_dir_block_out(puVar7);
        }
        if ((((param_4 & 4) != 0) && ((*(ushort *)(param_1 + 100) & 0x200) != 0)) &&
           ((_stickyhack != 0 && ((*(ushort *)(param_1 + 100) & 0x49) == 0)))) {
          *puVar7 = *puVar7 | 0x400000;
        }
        if (param_3 == 0) {
          if ((uVar8 == uVar12 + uVar13) || (*(int *)(param_2 + 8) == *(int *)(param_1 + 0x6c))) {
            *(byte *)puVar7 = (byte)*puVar7 | 0x80;
          }
          _brelse(puVar7);
        }
        else {
          if (((param_4 & 4) == 0) && ((*(ushort *)(param_1 + 100) & 0xf000) != 0x4000)) {
            if (uVar8 == uVar12 + uVar13) {
              *(byte *)puVar7 = (byte)*puVar7 | 0x80;
              _bawrite(puVar7);
            }
            else {
              _bdwrite(puVar7);
            }
          }
          else {
            _bwrite(puVar7);
          }
          *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
          if (*(short *)(_active_u[7] + 6) != 0) {
            *(ushort *)(param_1 + 100) = *(ushort *)(param_1 + 100) & 0xf3ff;
          }
        }
        if (((*(char *)(DAT_001e875c + 0x68) != '\0') || (*(int *)(param_2 + 0x14) < 1)) ||
           (uVar13 == 0)) goto LAB_0014423a;
      }
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
LAB_0014423a:
      if (local_8 != 0) {
        _iupdat(param_1,1);
      }
      return (int)*(char *)(DAT_001e875c + 0x68);
    }
  }
  return 0x16;
}

