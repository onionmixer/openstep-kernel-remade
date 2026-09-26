/* GHIDRADEC_FUNCTION index=1025 start=0x40393e8 */

void _bufstats(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int aiStack_c [2];
  
  puVar5 = &_bfreelist;
  iVar3 = 0;
  do {
    iVar4 = 0;
    for (iVar2 = 0; iVar2 <= 0x2000 / _m68k_page_size; iVar2 = iVar2 + 1) {
      aiStack_c[iVar2] = 0;
    }
    for (puVar1 = (undefined4 *)puVar5[3]; puVar5 != puVar1; puVar1 = (undefined4 *)puVar1[3]) {
      aiStack_c[(int)puVar1[6] / _m68k_page_size] = aiStack_c[(int)puVar1[6] / _m68k_page_size] + 1;
      iVar4 = iVar4 + 1;
    }
    _printf(aSTotalD,*(undefined4 *)(unk_40AF326 + iVar3 * 4),iVar4);
    for (iVar2 = 0; iVar2 <= 0x2000 / _m68k_page_size; iVar2 = iVar2 + 1) {
      if (aiStack_c[iVar2] != 0) {
        _printf(&aDD,iVar2 * _m68k_page_size,aiStack_c[iVar2]);
      }
    }
    _printf(&asc_40A6049);
    puVar5 = puVar5 + 0x11;
    iVar3 = iVar3 + 1;
  } while (puVar5 < &_buf);
  return;
}
/* GHIDRADEC_FUNCTION index=1026 start=0x40394d0 */

int _scanc(int param_1,byte *param_2,int param_3,byte param_4)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = param_2 + param_1;
  if (param_2 < pbVar2) {
    bVar1 = *(byte *)(param_3 + (uint)*param_2);
    while (((param_4 & bVar1) == 0 && (param_2 = param_2 + 1, param_2 < pbVar2))) {
      bVar1 = *(byte *)(param_3 + (uint)*param_2);
    }
  }
  return (int)pbVar2 - (int)param_2;
}
/* GHIDRADEC_FUNCTION index=1027 start=0x403951c */

int _skpc(char param_1,int param_2,char *param_3)

{
  char *pcVar1;
  
  pcVar1 = param_3 + param_2;
  for (; (param_3 < pcVar1 && (param_1 == *param_3)); param_3 = param_3 + 1) {
  }
  return (int)pcVar1 - (int)param_3;
}
/* GHIDRADEC_FUNCTION index=1028 start=0x4039542 */

int _locc(char param_1,int param_2,char *param_3)

{
  char *pcVar1;
  
  pcVar1 = param_3 + param_2;
  for (; (param_3 < pcVar1 && (param_1 != *param_3)); param_3 = param_3 + 1) {
  }
  return (int)pcVar1 - (int)param_3;
}
/* GHIDRADEC_FUNCTION index=1029 start=0x4039e24 */

void _sbupdate(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + 10) + 0x20);
  iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 6) + 0x1c) + 0x80))(*(int *)(param_1 + 6));
  if (-1 < iVar2) {
    iVar2 = _getblk(*(undefined4 *)(param_1 + 6),0x2000 / iVar2,*(undefined4 *)(iVar1 + 0x68));
    _bcopy(iVar1,*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar1 + 0x68));
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x8c) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x88) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x94) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x90) = 0;
    *(undefined *)(*(int *)(iVar2 + 0x20) + 0xd3) = 0;
    _bwrite(iVar2);
    iVar6 = (*(int *)(iVar1 + 0x34) + *(int *)(iVar1 + 0x9c) + -1) / *(int *)(iVar1 + 0x34);
    iVar2 = *(int *)(iVar1 + 0x2d8);
    iVar5 = 0;
    if (0 < iVar6) {
      do {
        iVar4 = *(int *)(iVar1 + 0x30);
        if (iVar6 < *(int *)(iVar1 + 0x38) + iVar5) {
          iVar4 = *(int *)(iVar1 + 0x34) * (iVar6 - iVar5);
        }
        iVar3 = _getblk(*(undefined4 *)(param_1 + 6),
                        iVar5 + *(int *)(iVar1 + 0x98) << (*(uint *)(iVar1 + 100) & 0x3f),iVar4);
        _bcopy(iVar2,*(undefined4 *)(iVar3 + 0x20),iVar4);
        iVar2 = iVar4 + iVar2;
        _bwrite(iVar3);
        iVar5 = *(int *)(iVar1 + 0x38) + iVar5;
      } while (iVar5 < iVar6);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1030 start=0x403b6a2 */

undefined4
_rdwri(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
      undefined4 param_6,int *param_7)

{
  undefined4 uVar1;
  undefined4 uStack_22;
  int iStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  uStack_22 = param_3;
  iStack_1e = param_4;
  puStack_1a = &uStack_22;
  uStack_16 = 1;
  uStack_12 = param_5;
  uStack_e = param_6;
  iStack_8 = param_4;
  uVar1 = sub_403A0F2(param_2 + 0xc,&puStack_1a,param_1,0,*(undefined4 *)(_active_u + 0x1a));
  if (param_7 == (int *)0x0) {
    if (iStack_8 != 0) {
      uVar1 = 5;
    }
  }
  else {
    *param_7 = iStack_8;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1031 start=0x403bfda */

undefined4 _ufs_nlinks(int param_1,int *param_2)

{
  *param_2 = (int)*(sword *)(*(int *)(param_1 + 0x2e) + 100);
  return 0;
}
/* GHIDRADEC_FUNCTION index=1032 start=0x403bff6 */

undefined4 _ipc_entry_tree_collision(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uStack_c;
  uint uStack_8;
  
  _ipc_splay_tree_bounds(param_1 + 0x18,param_2,&uStack_8,&uStack_c);
  uVar1 = 0;
  if (((uStack_8 != 0xffffffff) && (param_2 >> 8 == uStack_8 >> 8)) ||
     ((uStack_c != 0 && (param_2 >> 8 == uStack_c >> 8)))) {
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1033 start=0x403c04a */

uint * _ipc_entry_lookup(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  
  if (param_2 >> 8 < *(uint *)(param_1 + 0x10)) {
    puVar2 = (uint *)((param_2 >> 8) * 0x10 + *(int *)(param_1 + 0xc));
    uVar1 = *puVar2;
    if (param_2 << 0x18 == (uVar1 & 0xff000000)) {
      if ((uVar1 & 0x1f0000) == 0) {
        return (uint *)0x0;
      }
      return puVar2;
    }
    uVar1 = uVar1 & 0x800000;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x30);
  }
  if (uVar1 == 0) {
    return (uint *)0x0;
  }
  puVar2 = (uint *)_ipc_splay_tree_lookup(param_1 + 0x18,param_2);
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=1034 start=0x403c0b6 */

undefined4 _ipc_entry_get(int param_1,uint *param_2,int *param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(iVar3 + 8);
  if (iVar4 == 0) {
    uVar5 = 3;
  }
  else {
    puVar1 = (uint *)(iVar3 + iVar4 * 0x10);
    *(uint *)(iVar3 + 8) = puVar1[2];
    uVar2 = *puVar1;
    *puVar1 = uVar2 + 0x1000000;
    puVar1[2] = 0;
    *param_2 = uVar2 + 0x1000000 >> 0x18 | iVar4 << 8;
    *param_3 = (int)puVar1;
    uVar5 = 0;
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=1035 start=0x403c10c */

int _ipc_entry_alloc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  while( true ) {
    if (*(int *)(param_1 + 4) == 0) {
      return 0x10;
    }
    iVar1 = _ipc_entry_get(param_1,param_2,param_3);
    if (iVar1 == 0) break;
    iVar1 = _ipc_entry_grow_table(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1036 start=0x403c15a */

int _ipc_entry_alloc_name(int param_1,uint param_2,int *param_3)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  uVar6 = param_2 >> 8;
  puVar7 = (undefined4 *)0x0;
  do {
    while( true ) {
      if (*(int *)(param_1 + 4) == 0) {
        if (puVar7 != (undefined4 *)0x0) {
          _zfree(_ipc_tree_entry_zone,puVar7);
        }
        return 0x10;
      }
      if ((uVar6 != 0) && (uVar6 < *(uint *)(param_1 + 0x10))) {
        iVar5 = *(int *)(param_1 + 0xc);
        puVar1 = (uint *)(iVar5 + uVar6 * 0x10);
        if ((*puVar1 & 0x1f0000) == 0) {
          uVar3 = 0;
          for (uVar4 = *(uint *)(iVar5 + 8); uVar6 != uVar4;
              uVar4 = *(uint *)(iVar5 + 8 + uVar4 * 0x10)) {
            uVar3 = uVar4;
          }
          *(undefined4 *)(iVar5 + 8 + uVar3 * 0x10) = *(undefined4 *)(iVar5 + 8 + uVar4 * 0x10);
          *puVar1 = param_2 << 0x18;
          puVar1[2] = 0;
          *param_3 = (int)puVar1;
          if (puVar7 != (undefined4 *)0x0) {
            _zfree(_ipc_tree_entry_zone,puVar7);
          }
          return 0;
        }
        if (param_2 << 0x18 == (*puVar1 & 0xff000000)) {
          *param_3 = (int)puVar1;
          if (puVar7 == (undefined4 *)0x0) {
            return 0;
          }
          _zfree(_ipc_tree_entry_zone,puVar7);
          return 0;
        }
      }
      if ((*(int *)(param_1 + 0x30) != 0) &&
         (iVar5 = _ipc_splay_tree_lookup(param_1 + 0x18,param_2), iVar5 != 0)) {
        *param_3 = iVar5;
        if (puVar7 == (undefined4 *)0x0) {
          return 0;
        }
        _zfree(_ipc_tree_entry_zone,puVar7);
        return 0;
      }
      if (((uVar6 < *(uint *)(param_1 + 0x10)) ||
          (uVar3 = **(uint **)(param_1 + 0x14), uVar3 <= uVar6)) ||
         ((uint)((*(int *)(param_1 + 0x34) + 1) * 0x20) <=
          (uVar3 - *(uint *)(param_1 + 0x10)) * 0x10)) break;
      iVar5 = _ipc_entry_grow_table(param_1);
      if (iVar5 != 0) {
        if (puVar7 != (undefined4 *)0x0) {
          _zfree(_ipc_tree_entry_zone,puVar7);
          return iVar5;
        }
        return iVar5;
      }
    }
    if (puVar7 != (undefined4 *)0x0) {
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      if (uVar6 < *(uint *)(param_1 + 0x10)) {
        pbVar2 = (byte *)(*(int *)(param_1 + 0xc) + 1 + uVar6 * 0x10);
        *pbVar2 = *pbVar2 | 0x80;
      }
      else if ((uVar6 < **(uint **)(param_1 + 0x14)) &&
              (iVar5 = _ipc_entry_tree_collision(param_1,param_2), iVar5 == 0)) {
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
      }
      _ipc_splay_tree_insert(param_1 + 0x18,param_2,puVar7);
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[5] = param_1;
      *param_3 = (int)puVar7;
      return 0;
    }
    puVar7 = (undefined4 *)_zalloc(_ipc_tree_entry_zone);
  } while (puVar7 != (undefined4 *)0x0);
  return 6;
}
/* GHIDRADEC_FUNCTION index=1037 start=0x403c314 */

void _ipc_entry_dealloc(int param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puStack_3c;
  int iStack_38;
  undefined auStack_34 [24];
  undefined auStack_1c [24];
  
  uVar6 = param_2 >> 8;
  iVar5 = *(int *)(param_1 + 0xc);
  uVar1 = *(uint *)(param_1 + 0x10);
  if ((uVar6 < uVar1) && ((uint *)(iVar5 + uVar6 * 0x10) == param_3)) {
    if ((*param_3 & 0x800000) == 0) {
      *param_3 = *param_3 & 0xff000000;
      param_3[2] = *(uint *)(iVar5 + 8);
      *(uint *)(iVar5 + 8) = uVar6;
    }
    else {
      iVar5 = param_1 + 0x18;
      _ipc_splay_tree_split(iVar5,uVar6 * 0x100 + 0x100,auStack_34);
      _ipc_splay_tree_split(auStack_34,uVar6 << 8,auStack_1c);
      _ipc_splay_tree_pick(auStack_34,&iStack_38,&puStack_3c);
      uVar1 = *puStack_3c;
      *param_3 = uVar1 | iStack_38 << 0x18;
      uVar2 = puStack_3c[1];
      param_3[1] = uVar2;
      param_3[2] = puStack_3c[2];
      if ((uVar1 & 0x1f0000) == 0x10000) {
        _ipc_hash_global_delete(param_1,uVar2,iStack_38,puStack_3c);
        _ipc_hash_local_insert(param_1,uVar2,uVar6,param_3);
      }
      _ipc_splay_tree_delete(auStack_34,iStack_38,puStack_3c);
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
      iVar4 = _ipc_splay_tree_pick(auStack_34,&iStack_38,&puStack_3c);
      if (iVar4 != 0) {
        *(byte *)((int)param_3 + 1) = *(byte *)((int)param_3 + 1) | 0x80;
        _ipc_splay_tree_join(iVar5,auStack_34);
      }
      _ipc_splay_tree_join(iVar5,auStack_1c);
    }
  }
  else {
    _ipc_splay_tree_delete(param_1 + 0x18,param_2,param_3);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
    if (uVar6 < uVar1) {
      iVar4 = _ipc_entry_tree_collision(param_1,param_2);
      if (iVar4 == 0) {
        pbVar3 = (byte *)(uVar6 * 0x10 + iVar5 + 1);
        *pbVar3 = *pbVar3 & 0x7f;
      }
    }
    else if (uVar6 < **(uint **)(param_1 + 0x14)) {
      iVar5 = _ipc_entry_tree_collision(param_1,param_2);
      if (iVar5 == 0) {
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + -1;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1038 start=0x403c4a0 */

undefined4 _ipc_entry_grow_table(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined auStack_4c [24];
  undefined auStack_34 [24];
  undefined auStack_1c [24];
  
  while( true ) {
    if (*(int *)(param_1 + 8) != 0) {
      _assert_wait(param_1,0);
      _thread_block_with_continuation(0);
      return 0;
    }
    uVar5 = *(undefined4 *)(param_1 + 0xc);
    puVar10 = *(uint **)(param_1 + 0x14);
    uVar2 = *puVar10;
    puVar7 = puVar10 + -1;
    uVar3 = *puVar7;
    puVar8 = puVar10 + 1;
    uVar4 = *puVar8;
    if (uVar2 == uVar3) {
      return 3;
    }
    *(undefined4 *)(param_1 + 8) = 1;
    if (*puVar7 << 4 < _page_size) {
      puVar9 = (uint *)_ipc_table_alloc(*puVar10 << 4);
    }
    else {
      puVar9 = (uint *)_ipc_table_realloc(*puVar7 << 4,uVar5,*puVar10 << 4);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    if (puVar9 == (uint *)0x0) {
      _thread_wakeup_prim(param_1,0,0);
      return 6;
    }
    if (*(int *)(param_1 + 4) == 0) {
      _thread_wakeup_prim(param_1,0,0);
      _ipc_table_free(*puVar10 << 4,puVar9);
      return 0;
    }
    *(uint **)(param_1 + 0xc) = puVar9;
    *(uint *)(param_1 + 0x10) = uVar2;
    *(uint **)(param_1 + 0x14) = puVar8;
    if (*puVar7 << 4 < _page_size) {
      _bcopy(uVar5,puVar9,uVar3 << 4);
    }
    uVar14 = 0;
    if (uVar3 != 0) {
      do {
        puVar9[uVar14 * 4 + 3] = 0;
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar3);
    }
    _bzero(puVar9 + uVar3 * 4,(uVar2 - uVar3) * 0x10);
    uVar14 = 0;
    puVar10 = puVar9;
    if (uVar3 != 0) {
      do {
        if ((*puVar10 & 0x1f0000) == 0x10000) {
          _ipc_hash_local_insert(param_1,puVar10[1],uVar14,puVar10);
        }
        uVar14 = uVar14 + 1;
        puVar10 = puVar10 + 4;
      } while (uVar14 < uVar3);
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      _ipc_splay_tree_split(param_1 + 0x18,uVar4 << 8,auStack_4c);
      _ipc_splay_tree_split(auStack_4c,uVar2 << 8,auStack_34);
      _ipc_splay_tree_split(auStack_34,uVar3 << 8,auStack_1c);
      puVar10 = (uint *)_ipc_splay_traverse_start(auStack_34);
      while (puVar10 != (uint *)0x0) {
        uVar14 = puVar10[4];
        puVar1 = puVar9 + (uVar14 >> 8) * 4;
        if (*puVar1 == 0) {
          uVar13 = *puVar10;
          *puVar1 = uVar14 << 0x18 | uVar13;
          uVar6 = puVar10[1];
          puVar1[1] = uVar6;
          puVar1[2] = puVar10[2];
          if ((uVar13 & 0x1f0000) == 0x10000) {
            _ipc_hash_global_delete(param_1,uVar6,uVar14,puVar10);
            _ipc_hash_local_insert(param_1,uVar6,uVar14 >> 8,puVar1);
          }
          *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
          uVar11 = 1;
        }
        else {
          *puVar1 = *puVar1 | 0x800000;
          uVar11 = 0;
        }
        puVar10 = (uint *)_ipc_splay_traverse_next(auStack_34,uVar11);
      }
      _ipc_splay_traverse_finish(auStack_34);
      iVar15 = 0;
      uVar14 = 0;
      iVar12 = _ipc_splay_traverse_start(auStack_4c);
      while (iVar12 != 0) {
        uVar13 = *(uint *)(iVar12 + 0x10) >> 8;
        if (uVar14 != uVar13) {
          iVar15 = iVar15 + 1;
          uVar14 = uVar13;
        }
        iVar12 = _ipc_splay_traverse_next(auStack_4c,0);
      }
      _ipc_splay_traverse_finish(auStack_4c);
      *(int *)(param_1 + 0x34) = iVar15;
      iVar15 = param_1 + 0x18;
      _ipc_splay_tree_join(iVar15,auStack_4c);
      _ipc_splay_tree_join(iVar15,auStack_34);
      _ipc_splay_tree_join(iVar15,auStack_1c);
    }
    uVar14 = puVar9[2];
    uVar13 = uVar2 - 1;
    if (uVar3 <= uVar13) {
      puVar10 = puVar9 + uVar13 * 4;
      do {
        if (*puVar10 == 0) {
          *puVar10 = 0xff000000;
          puVar10[2] = uVar14;
          uVar14 = uVar13;
        }
        puVar10 = puVar10 + -4;
        uVar13 = uVar13 - 1;
      } while (uVar3 <= uVar13);
    }
    puVar9[2] = uVar14;
    _thread_wakeup_prim(param_1,0,0);
    _ipc_table_free(*puVar7 << 4,uVar5);
    if (*(int *)(param_1 + 4) == 0) break;
    if (puVar8 != *(uint **)(param_1 + 0x14)) {
      return 0;
    }
    if (*(int *)(param_1 + 0x34) == 0) {
      return 0;
    }
    if ((uint)(*(int *)(param_1 + 0x34) << 5) <= (uVar4 - uVar2) * 0x10) {
      return 0;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1039 start=0x403c7e4 */

undefined4 _ipc_hash_lookup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = _ipc_hash_local_lookup(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x38) == 0) {
      return 0;
    }
    iVar1 = _ipc_hash_global_lookup(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=1040 start=0x403c83a */

void _ipc_hash_insert(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_3 >> 8;
  if ((uVar1 < *(uint *)(param_1 + 0x10)) && (*(int *)(param_1 + 0xc) + uVar1 * 0x10 == param_4)) {
    _ipc_hash_local_insert(param_1,param_2,uVar1,param_4);
  }
  else {
    _ipc_hash_global_insert(param_1,param_2,param_3,param_4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1041 start=0x403c892 */

void _ipc_hash_delete(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_3 >> 8;
  if ((uVar1 < *(uint *)(param_1 + 0x10)) && (*(int *)(param_1 + 0xc) + uVar1 * 0x10 == param_4)) {
    _ipc_hash_local_delete(param_1,param_2,uVar1,param_4);
  }
  else {
    _ipc_hash_global_delete(param_1,param_2,param_3,param_4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1042 start=0x403c8ea */

int _ipc_hash_global_lookup(uint param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)(_ipc_hash_global_table +
                  (_ipc_hash_global_mask & (param_2 >> 6) + (param_1 >> 4)) * 4);
  iVar3 = *piVar1;
  if (iVar3 != 0) {
    if ((param_2 != *(uint *)(iVar3 + 4)) || (param_1 != *(uint *)(iVar3 + 0x14))) {
      do {
        piVar2 = (int *)(iVar3 + 0xc);
        iVar3 = *piVar2;
        if (iVar3 == 0) goto loc_403C958;
      } while ((param_2 != *(uint *)(iVar3 + 4)) || (param_1 != *(uint *)(iVar3 + 0x14)));
      *piVar2 = *(int *)(iVar3 + 0xc);
      *(int *)(iVar3 + 0xc) = *piVar1;
      *piVar1 = iVar3;
    }
    *param_3 = *(undefined4 *)(iVar3 + 0x10);
    *param_4 = iVar3;
  }
loc_403C958:
  return -(int)-(iVar3 != 0);
}
/* GHIDRADEC_FUNCTION index=1043 start=0x403c96a */

void _ipc_hash_global_insert(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  piVar1 = (int *)(_ipc_hash_global_table +
                  (_ipc_hash_global_mask & (param_2 >> 6) + (param_1 >> 4)) * 4);
  *(int *)(param_4 + 0xc) = *piVar1;
  *piVar1 = param_4;
  return;
}
/* GHIDRADEC_FUNCTION index=1044 start=0x403c9a0 */

void _ipc_hash_global_delete(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
  piVar2 = (int *)(_ipc_hash_global_table +
                  (_ipc_hash_global_mask & (param_2 >> 6) + (param_1 >> 4)) * 4);
  while( true ) {
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      return;
    }
    if (param_4 == iVar1) break;
    piVar2 = (int *)(iVar1 + 0xc);
  }
  *piVar2 = *(int *)(iVar1 + 0xc);
  return;
}
/* GHIDRADEC_FUNCTION index=1045 start=0x403c9ec */

undefined4 _ipc_hash_local_lookup(int param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (param_2 >> 6) % *(uint *)(param_1 + 0x10);
  while( true ) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0xc + uVar3 * 0x10);
    if (iVar2 == 0) {
      return 0;
    }
    puVar1 = (undefined *)(*(int *)(param_1 + 0xc) + iVar2 * 0x10);
    if (param_2 == *(uint *)(puVar1 + 4)) break;
    uVar3 = uVar3 + 1;
    if (*(uint *)(param_1 + 0x10) == uVar3) {
      uVar3 = 0;
    }
  }
  *param_3 = CONCAT31((int3)iVar2,*puVar1);
  *param_4 = (int)puVar1;
  return 1;
}
/* GHIDRADEC_FUNCTION index=1046 start=0x403ca50 */

void _ipc_hash_local_insert(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (param_2 >> 6) % *(uint *)(param_1 + 0x10);
  while (*(int *)(*(int *)(param_1 + 0xc) + 0xc + uVar1 * 0x10) != 0) {
    uVar1 = uVar1 + 1;
    if (*(uint *)(param_1 + 0x10) == uVar1) {
      uVar1 = 0;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc + uVar1 * 0x10) = param_3;
  return;
}
/* GHIDRADEC_FUNCTION index=1047 start=0x403ca92 */

void _ipc_hash_local_delete(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0xc);
  uVar2 = *(uint *)(param_1 + 0x10);
  uVar5 = (param_2 >> 6) % uVar2;
  while (param_3 != *(int *)(iVar1 + 0xc + uVar5 * 0x10)) {
    uVar5 = uVar5 + 1;
    if (uVar2 == uVar5) {
      uVar5 = 0;
    }
  }
  do {
    uVar4 = uVar5;
    if (param_3 == 0) {
      return;
    }
    do {
      while( true ) {
        uVar4 = uVar4 + 1;
        if (uVar2 == uVar4) {
          uVar4 = 0;
        }
        param_3 = *(int *)(iVar1 + 0xc + uVar4 * 0x10);
        if (param_3 == 0) goto loc_403CB04;
        uVar3 = (*(uint *)(iVar1 + 4 + param_3 * 0x10) >> 6) % uVar2;
        if (uVar4 < uVar5) break;
        if ((uVar4 < uVar3) || (uVar3 <= uVar5)) goto loc_403CB04;
      }
    } while ((uVar3 <= uVar4) || (uVar5 < uVar3));
loc_403CB04:
    *(int *)(iVar1 + 0xc + uVar5 * 0x10) = param_3;
    uVar5 = uVar4;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1048 start=0x403cb1c */

void _ipc_hash_init(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((_ipc_hash_global_size == 0) &&
     (_ipc_hash_global_size = _ipc_tree_entry_max >> 8, _ipc_hash_global_size < 0x20)) {
    _ipc_hash_global_size = 0x20;
  }
  _ipc_hash_global_mask = _ipc_hash_global_size - 1;
  if ((_ipc_hash_global_mask & _ipc_hash_global_size) != 0) {
    uVar3 = 1;
    while( true ) {
      _ipc_hash_global_mask = uVar3 | _ipc_hash_global_mask;
      _ipc_hash_global_size = _ipc_hash_global_mask + 1;
      if ((_ipc_hash_global_mask & _ipc_hash_global_size) == 0) break;
      uVar3 = uVar3 * 2;
    }
  }
  puVar2 = (undefined4 *)_kalloc(_ipc_hash_global_size << 2);
  uVar1 = _ipc_hash_global_size;
  uVar3 = 0;
  _ipc_hash_global_table = puVar2;
  if (_ipc_hash_global_size != 0) {
    do {
      *puVar2 = 0;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1049 start=0x403cbb6 */

uint _ipc_hash_info(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if (_ipc_hash_global_size < param_2) {
    param_2 = _ipc_hash_global_size;
  }
  uVar3 = 0;
  piVar4 = _ipc_hash_global_table;
  if (param_2 != 0) {
    do {
      iVar2 = 0;
      for (iVar1 = *piVar4; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        iVar2 = iVar2 + 1;
      }
      *param_1 = iVar2;
      uVar3 = uVar3 + 1;
      param_1 = param_1 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < param_2);
  }
  return _ipc_hash_global_size;
}

