/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145848 */

undefined4 FUN_00145848(int *param_1,int param_2,uint param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint *local_30;
  uint local_24;
  int local_c;
  int local_8;
  
  uVar3 = param_1[0xc];
  while ((*(ushort *)(uVar3 + 0x44) & 1) != 0) {
    *(ushort *)(uVar3 + 0x44) = *(ushort *)(uVar3 + 0x44) | 0x10;
    _sleep(uVar3);
  }
  *(byte *)(uVar3 + 0x44) = *(byte *)(uVar3 + 0x44) | 5;
  local_c = 0;
  uVar4 = *(undefined4 *)(uVar3 + 0x40);
  iVar5 = *(int *)(uVar3 + 0x50);
  uVar6 = *(uint *)(iVar5 + 0x30);
  local_24 = _page_size;
  if (*(uint *)(uVar3 + 0x6c) < param_3 + _page_size) {
    _vm_page_zero_fill(param_2);
  }
  while( true ) {
    uVar11 = param_3 >> ((byte)*(undefined4 *)(iVar5 + 0x50) & 0x1f);
    uVar7 = ~*(uint *)(iVar5 + 0x48) & param_3;
    uVar8 = uVar6 - uVar7;
    uVar12 = local_24;
    if (uVar8 < local_24) {
      uVar12 = uVar8;
    }
    uVar8 = *(uint *)(uVar3 + 0x6c) - param_3;
    if (*(uint *)(uVar3 + 0x6c) <= param_3) break;
    if (uVar8 < uVar12) {
      uVar12 = uVar8;
    }
    uVar1 = *(undefined1 *)(DAT_001e875c + 0x68);
    *(undefined1 *)(DAT_001e875c + 0x68) = 0;
    iVar9 = _bmap(uVar3,uVar11,1,uVar7 + uVar12,0);
    iVar9 = iVar9 << ((byte)*(undefined4 *)(iVar5 + 100) & 0x1f);
    iVar10 = (int)*(char *)(DAT_001e875c + 0x68);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
    if (iVar10 != 0) {
      *(int *)(*param_1 + 0x34) = iVar10;
      _printf(s_IO_error_on_pagein__error____d__001de532,iVar10);
LAB_00145b21:
      uVar2 = *(ushort *)(uVar3 + 0x44);
      *(ushort *)(uVar3 + 0x44) = uVar2 & 0xfffe;
      if ((uVar2 & 0x10) != 0) {
        *(ushort *)(uVar3 + 0x44) = uVar2 & 0xffee;
        _wakeup(uVar3);
      }
      return 2;
    }
    if (iVar9 < 0) {
      uVar2 = *(ushort *)(uVar3 + 0x44);
      *(ushort *)(uVar3 + 0x44) = uVar2 & 0xfffe;
      goto LAB_00145983;
    }
    if (((int)uVar11 < 0xc) &&
       (*(uint *)(uVar3 + 0x6c) < uVar11 + 1 << ((byte)*(undefined4 *)(iVar5 + 0x50) & 0x1f))) {
      uVar8 = ((~*(uint *)(iVar5 + 0x48) & *(uint *)(uVar3 + 0x6c)) + *(int *)(iVar5 + 0x34)) - 1 &
              *(uint *)(iVar5 + 0x4c);
    }
    else {
      uVar8 = *(uint *)(iVar5 + 0x30);
    }
    if (((_page_size == uVar8) && (local_c == 0)) && (uVar7 == 0)) {
      if (uVar11 != *(int *)(uVar3 + 0x58) + 1U) {
        _rablock = 0;
        _rasize = 0;
      }
      local_8 = 0;
      uVar7 = _breadDirect(uVar4,param_2,iVar9,uVar8,uVar12,_rablock,_rasize,&local_8);
      *(uint *)(uVar3 + 0x58) = uVar11;
      if (local_8 != 0) {
        *(int *)(*param_1 + 0x34) = local_8;
        uVar2 = *(ushort *)(uVar3 + 0x44);
        *(ushort *)(uVar3 + 0x44) = uVar2 & 0xfffe;
        if ((uVar2 & 0x10) != 0) {
          *(ushort *)(uVar3 + 0x44) = uVar2 & 0xffee;
          _wakeup(uVar3);
        }
        _printf(s_IO_error_on_pagein__breadDirect__001de553);
        return 2;
      }
      if ((int)uVar7 < (int)uVar12) {
        uVar12 = uVar7;
      }
    }
    else {
      if (uVar11 == *(int *)(uVar3 + 0x58) + 1U) {
        local_30 = (uint *)_breada(uVar4,iVar9,uVar8,_rablock,_rasize);
      }
      else {
        local_30 = (uint *)_bread(uVar4,iVar9,uVar8);
      }
      *(uint *)(uVar3 + 0x58) = uVar11;
      if ((int)(uVar8 - local_30[10]) < (int)uVar12) {
        uVar12 = uVar8 - local_30[10];
      }
      if ((*local_30 & 4) != 0) {
        *(int *)(*param_1 + 0x34) = (int)(short)local_30[7];
        _brelse(local_30);
        _printf(s_IO_error_on_pagein__bread__001de575);
        goto LAB_00145b21;
      }
      _copy_to_phys(uVar7 + local_30[8],local_c + *(int *)(param_2 + 0x24),uVar12);
      if (uVar6 == uVar12) {
        *local_30 = *local_30 | 0x400000;
      }
      _brelse(local_30);
    }
    local_24 = local_24 - uVar12;
    local_c = local_c + uVar12;
    param_3 = param_3 + uVar12;
    if (((int)local_24 < 1) || (uVar12 == 0)) goto LAB_00145b93;
  }
  if (local_c == 0) {
    uVar2 = *(ushort *)(uVar3 + 0x44);
    *(ushort *)(uVar3 + 0x44) = uVar2 & 0xfffe;
LAB_00145983:
    if ((uVar2 & 0x10) != 0) {
      *(ushort *)(uVar3 + 0x44) = uVar2 & 0xffee;
      _wakeup(uVar3);
    }
    return 1;
  }
LAB_00145b93:
  uVar2 = *(ushort *)(uVar3 + 0x44);
  *(ushort *)(uVar3 + 0x44) = uVar2 & 0xfffe;
  if ((uVar2 & 0x10) != 0) {
    *(ushort *)(uVar3 + 0x44) = uVar2 & 0xffee;
    _wakeup(uVar3);
  }
  return 0;
}

