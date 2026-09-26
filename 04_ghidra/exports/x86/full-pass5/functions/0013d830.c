/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013d830 */

uint _bmap(int param_1,int param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int local_1c;
  int local_18;
  int local_10;
  int local_8;
  
  iVar4 = param_2;
  local_8 = 0;
  local_18 = 0;
  if (param_2 < 0) {
LAB_0013dba6:
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x1b;
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  _rablock = 0;
  _rasize = 0;
  if ((param_3 & 0x20) != 0) {
    param_3 = param_3 & 0xffffffdf;
  }
  uVar5 = *(uint *)(param_1 + 0x6c);
  bVar8 = (byte)*(undefined4 *)(iVar1 + 0x50);
  uVar9 = uVar5 >> (bVar8 & 0x1f);
  if ((((param_3 == 0) && ((int)uVar9 < 0xc)) && ((int)uVar9 < param_2)) &&
     (*(int *)(param_1 + 0x8c + uVar9 * 4) != 0)) {
    if (((int)uVar9 < 0xc) && (uVar5 < uVar9 + 1 << (bVar8 & 0x1f))) {
      uVar5 = ((uVar5 & ~*(uint *)(iVar1 + 0x48)) + *(int *)(iVar1 + 0x34)) - 1 &
              *(uint *)(iVar1 + 0x4c);
    }
    else {
      uVar5 = *(uint *)(iVar1 + 0x30);
    }
    if ((uVar5 < *(uint *)(iVar1 + 0x30)) && (uVar5 != 0)) {
      uVar2 = _blkpref(param_1,uVar9,uVar9,param_1 + 0x8c,uVar5,*(uint *)(iVar1 + 0x30));
      iVar3 = _realloccg(param_1,*(undefined4 *)(param_1 + 0x8c + uVar9 * 4),uVar2);
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      *(uint *)(param_1 + 0x6c) = (uVar9 + 1) * *(int *)(iVar1 + 0x30);
      *(int *)(param_1 + 0x8c + uVar9 * 4) =
           *(int *)(iVar3 + 0x24) >> ((byte)*(undefined4 *)(iVar1 + 100) & 0x1f);
      *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
      if (param_5 == (undefined4 *)0x0) {
        _bdwrite(iVar3);
      }
      else {
        _bwrite(iVar3);
        _iupdat(param_1,1);
      }
    }
  }
  if (param_2 < 0xc) {
    uVar5 = *(uint *)(param_1 + 0x8c + param_2 * 4);
    if (param_3 == 1) {
      if (uVar5 == 0) {
        return 0xffffffff;
      }
      goto LAB_0013dae7;
    }
    if (uVar5 == 0) {
      uVar5 = *(uint *)(iVar1 + 0x30);
      if (*(uint *)(param_1 + 0x6c) < (param_2 + 1) * uVar5) {
        uVar5 = (param_4 + *(int *)(iVar1 + 0x34)) - 1U & *(uint *)(iVar1 + 0x4c);
      }
      uVar2 = _blkpref(param_1,param_2,param_2,param_1 + 0x8c,uVar5);
      iVar4 = _alloc(param_1,uVar2);
    }
    else {
      if ((uint)((param_2 + 1) * *(int *)(iVar1 + 0x30)) <= *(uint *)(param_1 + 0x6c))
      goto LAB_0013dae7;
      uVar9 = *(int *)(iVar1 + 0x34) + -1 + (*(uint *)(param_1 + 0x6c) & ~*(uint *)(iVar1 + 0x48)) &
              *(uint *)(iVar1 + 0x4c);
      uVar10 = *(int *)(iVar1 + 0x34) + -1 + param_4 & *(uint *)(iVar1 + 0x4c);
      if (uVar10 <= uVar9) goto LAB_0013dae7;
      uVar2 = _blkpref(param_1,param_2,param_2,param_1 + 0x8c,uVar9,uVar10);
      iVar4 = _realloccg(param_1,uVar5,uVar2);
    }
    if (iVar4 != 0) {
      uVar5 = *(int *)(iVar4 + 0x24) >> ((byte)*(undefined4 *)(iVar1 + 100) & 0x1f);
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 1;
      }
      if ((*(ushort *)(param_1 + 100) & 0xf000) == 0x4000) {
        _bwrite(iVar4);
      }
      else {
        _bdwrite(iVar4);
      }
      *(uint *)(param_1 + 0x8c + param_2 * 4) = uVar5;
      *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
LAB_0013dae7:
      if (10 < param_2) {
        return uVar5;
      }
      _rablock = *(int *)(param_1 + 0x90 + param_2 * 4) <<
                 ((byte)*(undefined4 *)(iVar1 + 100) & 0x1f);
      if ((param_2 + 1 < 0xc) &&
         (*(uint *)(param_1 + 0x6c) <
          (uint)(param_2 + 2 << ((byte)*(undefined4 *)(iVar1 + 0x50) & 0x1f)))) {
        _rasize = ((*(uint *)(param_1 + 0x6c) & ~*(uint *)(iVar1 + 0x48)) + *(int *)(iVar1 + 0x34))
                  - 1 & *(uint *)(iVar1 + 0x4c);
        return uVar5;
      }
      _rasize = *(undefined4 *)(iVar1 + 0x30);
      return uVar5;
    }
  }
  else {
    local_1c = 0;
    local_10 = 1;
    param_2 = param_2 + -0xc;
    iVar3 = 3;
    do {
      local_10 = local_10 * *(int *)(iVar1 + 0x74);
      if (param_2 < local_10) break;
      param_2 = param_2 - local_10;
      iVar3 = iVar3 + -1;
    } while (0 < iVar3);
    if (iVar3 == 0) goto LAB_0013dba6;
    uVar5 = *(uint *)(param_1 + 0xbc + (3 - iVar3) * 4);
    if (uVar5 != 0) {
LAB_0013ddc6:
      do {
        if (3 < iVar3) {
          if (local_8 < *(int *)(iVar1 + 0x74) + -1) {
            uVar9 = *(uint *)(local_18 + 4 + local_8 * 4);
            _rablock = (uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 |
                       uVar9 << 0x18) << ((byte)*(undefined4 *)(iVar1 + 100) & 0x1f);
            _rasize = *(undefined4 *)(iVar1 + 0x30);
            return uVar5;
          }
          return uVar5;
        }
        pbVar7 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),
                                uVar5 << ((byte)*(undefined4 *)(iVar1 + 100) & 0x1f),
                                *(undefined4 *)(iVar1 + 0x30));
        if ((*pbVar7 & 4) != 0) {
          _brelse(pbVar7);
          return 0;
        }
        local_18 = *(int *)(pbVar7 + 0x20);
        local_10 = local_10 / *(int *)(iVar1 + 0x74);
        local_8 = (param_2 / local_10) % *(int *)(iVar1 + 0x74);
        uVar5 = *(uint *)(local_18 + local_8 * 4);
        uVar5 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
        if (uVar5 == 0) {
          if (param_3 == 1) {
            _brelse(pbVar7);
            return 0xffffffff;
          }
          if (local_1c == 0) {
            iVar6 = local_8;
            iVar11 = local_18;
            if (iVar3 < 3) {
              iVar6 = 0;
              iVar11 = 0;
            }
            local_1c = _blkpref(param_1,iVar4,iVar6,iVar11);
          }
          iVar6 = _alloc(param_1,local_1c,*(undefined4 *)(iVar1 + 0x30));
          if (iVar6 == 0) {
            _brelse(pbVar7);
            return 0xffffffff;
          }
          uVar5 = *(int *)(iVar6 + 0x24) >> ((byte)*(undefined4 *)(iVar1 + 100) & 0x1f);
          if (((iVar3 < 3) || ((*(ushort *)(param_1 + 100) & 0xf000) == 0x4000)) ||
             (param_5 != (undefined4 *)0x0)) {
            _bwrite(iVar6);
          }
          else {
            _bdwrite(iVar6);
          }
          *(uint *)(local_18 + local_8 * 4) =
               uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
          if (param_5 == (undefined4 *)0x0) {
            _bdwrite(pbVar7);
          }
          else {
            _bwrite(pbVar7);
          }
        }
        else {
          _brelse(pbVar7);
        }
        iVar3 = iVar3 + 1;
      } while( true );
    }
    if (param_3 != 1) {
      local_1c = _blkpref(param_1,iVar4,0,0);
      iVar6 = _alloc(param_1,local_1c,*(undefined4 *)(iVar1 + 0x30));
      if (iVar6 != 0) {
        uVar5 = *(int *)(iVar6 + 0x24) >> ((byte)*(undefined4 *)(iVar1 + 100) & 0x1f);
        _bwrite(iVar6);
        *(uint *)(param_1 + 0xbc + (3 - iVar3) * 4) = uVar5;
        *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = 1;
        }
        goto LAB_0013ddc6;
      }
    }
  }
  return 0xffffffff;
}

