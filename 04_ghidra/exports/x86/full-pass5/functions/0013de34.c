/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013de34 */

int _dirlook(uint param_1,char *param_2,uint *param_3)

{
  byte *pbVar1;
  char cVar2;
  ushort uVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  char *pcVar9;
  uint local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  uVar6 = 0xffffffff;
  pcVar9 = param_2;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  sVar4 = ~uVar6 - 1;
  if ((*(ushort *)(param_1 + 100) & 0xf000) != 0x4000) {
    return 0x14;
  }
  iVar5 = _iaccess(param_1,0x40);
  if (iVar5 != 0) {
    return iVar5;
  }
  iVar5 = _dnlc_lookup(param_1 + 0xc,param_2,0);
  if (iVar5 != 0) {
    *(short *)(iVar5 + 6) = *(short *)(iVar5 + 6) + 1;
    *param_3 = *(uint *)(iVar5 + 0x30);
    while ((*(byte *)(*param_3 + 0x44) & 1) != 0) {
      pbVar1 = (byte *)(*param_3 + 0x44);
      *pbVar1 = *pbVar1 | 0x10;
      _sleep(*param_3);
    }
    *(byte *)(*param_3 + 0x44) = *(byte *)(*param_3 + 0x44) | 1;
    return 0;
  }
  while ((*(ushort *)(param_1 + 0x44) & 1) != 0) {
    *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x10;
    _sleep(param_1);
  }
  *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 1;
  if (*(uint *)(param_1 + 0x6c) < *(uint *)(param_1 + 0x4c)) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  uVar6 = *(uint *)(param_1 + 0x4c);
  if (uVar6 == 0) {
    uVar6 = 0;
    local_10 = 1;
  }
  else {
    local_c = ~*(uint *)(*(int *)(param_1 + 0x50) + 0x48) & uVar6;
    if ((local_c != 0) && (local_8 = _blkatoff(param_1,uVar6,0), local_8 == 0)) {
LAB_0013e138:
      iVar5 = (int)*(char *)(DAT_001e875c + 0x68);
      goto LAB_0013e155;
    }
    local_10 = 2;
  }
  local_14 = *(int *)(param_1 + 0x6c) + 0x3ffU & 0xfffffc00;
LAB_0013e115:
  for (; uVar6 < local_14; uVar6 = uVar6 + uVar7) {
    if ((~*(uint *)(*(int *)(param_1 + 0x50) + 0x48) & uVar6) == 0) {
      if (local_8 != 0) {
        _byte_swap_dir_block_out(local_8);
        _brelse(local_8);
      }
      local_8 = _blkatoff(param_1,uVar6,0);
      if (local_8 == 0) goto LAB_0013e138;
      local_c = 0;
    }
    piVar8 = (int *)(local_c + *(int *)(local_8 + 0x20));
    if (((short)piVar8[1] == 0) ||
       ((_dirchk != 0 && (iVar5 = FUN_0013f52c(param_1,piVar8,local_c,uVar6), iVar5 != 0)))) {
      uVar7 = 0x400 - (local_c & 0x3ff);
    }
    else {
      if ((((*piVar8 != 0) && (sVar4 == *(ushort *)((int)piVar8 + 6))) &&
          (*param_2 == (char)piVar8[2])) && (iVar5 = _bcmp(param_2,piVar8 + 2,sVar4), iVar5 == 0)) {
        iVar5 = *piVar8;
        _byte_swap_dir_block_out(local_8);
        _brelse(local_8);
        local_8 = 0;
        *(uint *)(param_1 + 0x4c) = uVar6;
        if (((sVar4 == 2) && (*param_2 == '.')) && (param_2[1] == '.')) {
          uVar3 = *(ushort *)(param_1 + 0x44);
          *(ushort *)(param_1 + 0x44) = uVar3 & 0xfffe;
          if ((uVar3 & 0x10) != 0) {
            *(ushort *)(param_1 + 0x44) = uVar3 & 0xffee;
            _wakeup(param_1);
          }
          uVar6 = _iget((int)*(short *)(param_1 + 0x46),*(undefined4 *)(param_1 + 0x50),iVar5);
        }
        else {
          if (*(int *)(param_1 + 0x48) == iVar5) {
            *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 1;
            uVar6 = param_1;
            goto LAB_0013e0ec;
          }
          uVar6 = _iget((int)*(short *)(param_1 + 0x46),*(undefined4 *)(param_1 + 0x50),iVar5);
          uVar3 = *(ushort *)(param_1 + 0x44);
          *(ushort *)(param_1 + 0x44) = uVar3 & 0xfffe;
          if ((uVar3 & 0x10) != 0) {
            *(ushort *)(param_1 + 0x44) = uVar3 & 0xffee;
            _wakeup(param_1);
          }
        }
        if (uVar6 != 0) {
LAB_0013e0ec:
          *param_3 = uVar6;
          _dnlc_enter(param_1 + 0xc,param_2,uVar6 + 0xc,0);
          return 0;
        }
        iVar5 = (int)*(char *)(DAT_001e875c + 0x68);
        goto LAB_0013e175;
      }
      uVar7 = (uint)*(ushort *)(piVar8 + 1);
    }
    local_c = local_c + uVar7;
  }
  if (local_10 == 2) {
    local_10 = 1;
    uVar6 = 0;
    local_14 = *(uint *)(param_1 + 0x4c);
    goto LAB_0013e115;
  }
  iVar5 = 2;
LAB_0013e155:
  uVar3 = *(ushort *)(param_1 + 0x44);
  *(ushort *)(param_1 + 0x44) = uVar3 & 0xfffe;
  if ((uVar3 & 0x10) != 0) {
    *(ushort *)(param_1 + 0x44) = uVar3 & 0xffee;
    _wakeup(param_1);
  }
LAB_0013e175:
  if (local_8 != 0) {
    _byte_swap_dir_block_out(local_8);
    _brelse(local_8);
  }
  return iVar5;
}

