/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001313c0 */

int FUN_001313c0(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int local_5c;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [64];
  
  local_5c = 0;
  bVar2 = false;
  if (*(int *)(param_2 + 0x14) == 0) {
    local_5c = 0;
  }
  else if ((*(int *)(param_2 + 8) < 0) ||
          (uVar8 = *(int *)(param_2 + 0x14) + *(int *)(param_2 + 8), (int)uVar8 < 0)) {
    local_5c = 0x16;
  }
  else if (((param_3 == 1) && (param_1[10] == 1)) && (_active_u[0x9b] < uVar8)) {
    _psignal(*_active_u,(char *)0x19);
    local_5c = 0x1b;
  }
  else {
    iVar1 = param_1[0xc];
    _rlock(iVar1);
    uVar8 = *(uint *)(*(int *)(param_1[9] + 0x128) + 0x24) & 0xfffffc00;
    if ((int)uVar8 < 1) {
                    /* WARNING: Subroutine does not return */
      _panic(s_rwvp__zero_size_001dcaac);
    }
    do {
      uVar4 = *(uint *)(param_2 + 8) / uVar8;
      uVar7 = *(uint *)(param_2 + 8) % uVar8;
      uVar9 = *(uint *)(param_2 + 0x14);
      if (uVar8 - uVar7 < *(uint *)(param_2 + 0x14)) {
        uVar9 = uVar8 - uVar7;
      }
      (**(code **)(param_1[7] + 0x50))(param_1,uVar4,&local_48,&local_4c);
      if ((*(byte *)(param_1 + 1) & 0x40) == 0) {
        if (param_3 == 0) {
          if ((int)uVar4 < 0) {
            pbVar5 = (byte *)_geteblk(uVar8);
            _blkclr(*(undefined4 *)(pbVar5 + 0x20),*(undefined4 *)(pbVar5 + 0x14));
            pbVar5[0x28] = 0;
            pbVar5[0x29] = 0;
            pbVar5[0x2a] = 0;
            pbVar5[0x2b] = 0;
          }
          else {
            iVar6 = _incore(local_48,local_4c);
            if (iVar6 != 0) {
              _nfs_validate_caches(local_48,param_5,0);
            }
            if (uVar4 == *(int *)(iVar1 + 100) + 1U) {
              (**(code **)(param_1[7] + 0x50))
                        (param_1,*(int *)(iVar1 + 100) + 2,&local_48,&local_50);
              pbVar5 = (byte *)_breada(local_48,local_4c,uVar8,local_50,uVar8);
            }
            else {
LAB_00131621:
              pbVar5 = (byte *)_bread(local_48,local_4c,uVar8);
            }
          }
        }
        else {
          if (*(short *)(iVar1 + 0x62) != 0) {
            local_5c = (int)*(short *)(iVar1 + 0x62);
            goto LAB_00131749;
          }
          if (uVar9 != uVar8) goto LAB_00131621;
          pbVar5 = (byte *)_getblk(local_48,local_4c,uVar8);
        }
      }
      else {
        pbVar5 = (byte *)_geteblk(uVar8);
        if ((param_3 == 0) &&
           (local_5c = FUN_001318d4(param_1,uVar7 + *(int *)(pbVar5 + 0x20),
                                    *(undefined4 *)(param_2 + 8),uVar9,pbVar5 + 0x28,param_5,
                                    local_44), local_5c != 0)) {
          _brelse(pbVar5);
          goto LAB_00131749;
        }
      }
      if ((*pbVar5 & 4) != 0) {
        local_5c = _geterror(pbVar5);
        _brelse(pbVar5);
        goto LAB_00131749;
      }
      if (param_3 == 0) {
        *(uint *)(iVar1 + 100) = uVar4;
        uVar4 = *(int *)(iVar1 + 0x98) - *(int *)(param_2 + 8);
        if ((int)uVar4 < 1) {
          _brelse(pbVar5);
          local_5c = 0;
          goto LAB_00131749;
        }
        if ((int)uVar4 < (int)uVar9) {
          bVar2 = true;
          uVar9 = uVar4;
        }
      }
      uVar3 = _uiomove(uVar7 + *(int *)(pbVar5 + 0x20),uVar9,param_3,param_2);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
      if (param_3 == 0) {
        _brelse(pbVar5);
      }
      else {
        uVar4 = *(uint *)(param_2 + 8);
        if (*(uint *)(iVar1 + 0x98) < uVar4) {
          *(uint *)(iVar1 + 0x98) = uVar4;
          if (*(uint *)(*param_1 + 0x14) < uVar4) {
            *(uint *)(*param_1 + 0x14) = uVar4;
          }
        }
        if ((*(byte *)(param_1 + 1) & 0x40) == 0) {
          *(byte *)(iVar1 + 0x60) = *(byte *)(iVar1 + 0x60) | 0x10;
          if (uVar7 + uVar9 == uVar8) {
            *pbVar5 = *pbVar5 | 0x80;
            _bawrite(pbVar5);
          }
          else {
            _bdwrite(pbVar5);
          }
        }
        else {
          local_5c = _nfswrite(param_1,uVar7 + *(int *)(pbVar5 + 0x20),*(int *)(param_2 + 8) - uVar9
                               ,uVar9,param_5);
          _brelse(pbVar5);
        }
      }
    } while (((*(char *)(DAT_001e875c + 0x68) == '\0') && (0 < *(int *)(param_2 + 0x14))) &&
            (!bVar2));
    if (local_5c == 0) {
      local_5c = (int)*(char *)(DAT_001e875c + 0x68);
    }
LAB_00131749:
    _runlock(iVar1);
  }
  return local_5c;
}

