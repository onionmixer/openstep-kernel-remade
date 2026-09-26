/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a9dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0013a9dc(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  byte bVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint local_44;
  undefined1 local_40 [36];
  undefined4 local_1c;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar9 = *(int *)(param_1 + 0x30);
  if ((*(byte *)(iVar9 + 0x79) & 1) != 0) {
    do {
      *(byte *)(iVar9 + 0x79) = *(byte *)(iVar9 + 0x79) | 2;
      _sleep(iVar9 + 0x79);
    } while ((*(byte *)(iVar9 + 0x79) & 1) != 0);
  }
  *(byte *)(iVar9 + 0x79) = *(byte *)(iVar9 + 0x79) | 1;
  uVar7 = param_3 / _page_size;
  if (uVar7 < *(uint *)(iVar9 + 0x38)) {
    if ((*(byte *)(*(int *)(iVar9 + 0x40) + 3 + uVar7 * 4) & 0xf) == 0) {
      _printf(s_pagein_from_uninitialized_data_001dd7ed);
      local_8 = param_3;
      local_c = 0;
      local_44 = _page_size;
    }
    else {
      local_8 = (*(uint *)(*(int *)(iVar9 + 0x40) + uVar7 * 4) & 0xffffff) * _page_size;
      local_c = (uint)(*(byte *)(*(int *)(iVar9 + 0x40) + 3 + uVar7 * 4) >> 4) *
                *(int *)(iVar9 + 0x34);
      local_44 = (*(byte *)(*(int *)(iVar9 + 0x40) + 3 + uVar7 * 4) & 0xf) * *(int *)(iVar9 + 0x34);
    }
  }
  else {
    if (_swapfs_cangrow == 1) {
                    /* WARNING: Subroutine does not return */
      _panic(s_paging_in_beyond_end_of_file_001dd7d0);
    }
    local_8 = param_3;
    local_c = 0;
    local_44 = _page_size;
  }
  uVar6 = local_8;
  iVar5 = local_c;
  uVar7 = _page_size;
  if (local_44 == _page_size) {
    _DAT_001e5a60 = _DAT_001e5a60 + 1;
    iVar8 = (**(code **)(*(int *)(*(int *)(iVar9 + 0x3c) + 0x1c) + 0x74))
                      (*(int *)(iVar9 + 0x3c),param_2,local_8);
    iVar9 = *(int *)(param_1 + 0x30);
    bVar2 = *(byte *)(iVar9 + 0x79);
    *(byte *)(iVar9 + 0x79) = bVar2 & 0xfe;
    if ((bVar2 & 2) == 0) {
      return iVar8;
    }
    *(byte *)(iVar9 + 0x79) = bVar2 & 0xfc;
LAB_0013ac28:
    _wakeup(iVar9 + 0x79);
  }
  else {
    _DAT_001e5a34 = _DAT_001e5a34 + 1;
    if (*(uint *)(iVar9 + 0x60) == local_8) {
      _DAT_001e5a38 = _DAT_001e5a38 + 1;
      local_10 = local_c + *(int *)(iVar9 + 0x58);
    }
    else if (*(uint *)(iVar9 + 0x74) == local_8) {
      _DAT_001e5a3c = _DAT_001e5a3c + 1;
      local_10 = local_c + *(int *)(iVar9 + 0x68);
    }
    else {
      if (*(char *)(iVar9 + 100) == '\0') {
LAB_0013abc4:
        *(undefined4 *)(iVar9 + 0x60) = 0xffffffff;
        local_1c = *(undefined4 *)(iVar9 + 0x5c);
        iVar8 = (**(code **)(*(int *)(*(int *)(iVar9 + 0x3c) + 0x1c) + 0x74))
                          (*(int *)(iVar9 + 0x3c),local_40,uVar6);
        if (iVar8 == 0) {
          *(uint *)(iVar9 + 0x60) = uVar6;
          local_10 = iVar5 + *(int *)(iVar9 + 0x58);
        }
      }
      else {
        _DAT_001e5a40 = _DAT_001e5a40 + 1;
        piVar3 = *(int **)(iVar9 + 0x3c);
        uVar4 = *(undefined4 *)(iVar9 + 0x5c);
        iVar8 = *(int *)(iVar9 + 0x60);
        uVar1 = _page_size + iVar8;
        if (*(uint *)(*piVar3 + 0x14) < uVar1) {
          *(uint *)(*piVar3 + 0x14) = uVar1;
        }
        iVar8 = (**(code **)(piVar3[7] + 0x78))(piVar3,uVar4,uVar7,iVar8);
        if (iVar8 == 0) {
          *(undefined1 *)(iVar9 + 100) = 0;
          goto LAB_0013abc4;
        }
        _printf(s_cannot_flush_input_cache__001dd80d);
      }
      if (iVar8 != 0) {
        iVar9 = *(int *)(param_1 + 0x30);
        bVar2 = *(byte *)(iVar9 + 0x79);
        *(byte *)(iVar9 + 0x79) = bVar2 & 0xfe;
        if ((bVar2 & 2) == 0) {
          return iVar8;
        }
        *(byte *)(iVar9 + 0x79) = bVar2 & 0xfc;
        goto LAB_0013ac28;
      }
    }
    uVar7 = local_8;
    if ((int)local_8 < 0) {
      uVar7 = local_8 + 0x1fff;
    }
    _uncompress_data_to_phys
              (local_10,local_44,*(undefined4 *)(param_2 + 0x24),_page_size,(int)uVar7 >> 0xd);
    iVar9 = *(int *)(param_1 + 0x30);
    bVar2 = *(byte *)(iVar9 + 0x79);
    *(byte *)(iVar9 + 0x79) = bVar2 & 0xfe;
    if ((bVar2 & 2) != 0) {
      *(byte *)(iVar9 + 0x79) = bVar2 & 0xfc;
      _wakeup(iVar9 + 0x79);
    }
    iVar8 = 0;
  }
  return iVar8;
}

