/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146284 */

void _ipc_entry_dealloc(int param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint *local_3c;
  int local_38;
  uint local_34;
  uint local_30 [5];
  undefined1 local_1c [24];
  
  uVar6 = param_2 >> 8;
  iVar7 = *(int *)(param_1 + 0x14);
  uVar1 = *(uint *)(param_1 + 0x18);
  if ((uVar6 < uVar1) && (param_3 == (uint *)(uVar6 * 0x10 + iVar7))) {
    if ((*param_3 & 0x800000) == 0) {
      *param_3 = *param_3 & 0xff000000;
      param_3[2] = *(uint *)(iVar7 + 8);
      *(uint *)(iVar7 + 8) = uVar6;
    }
    else {
      iVar7 = param_1 + 0x20;
      _ipc_splay_tree_split(iVar7,(uVar6 + 1) * 0x100,&local_34);
      _ipc_splay_tree_split(&local_34,uVar6 << 8,local_1c);
      _ipc_splay_tree_pick(&local_34,&local_38,&local_3c);
      uVar1 = *local_3c;
      *param_3 = local_38 << 0x18 | uVar1;
      uVar2 = local_3c[1];
      param_3[1] = uVar2;
      param_3[2] = local_3c[2];
      if ((uVar1 & 0x1f0000) == 0x10000) {
        _ipc_hash_global_delete(param_1,uVar2,local_38,local_3c);
        _ipc_hash_local_insert(param_1,uVar2,uVar6,param_3);
      }
      _ipc_splay_tree_delete(&local_34,local_38,local_3c);
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
      iVar4 = _ipc_splay_tree_pick(&local_34,&local_38,&local_3c);
      if (iVar4 != 0) {
        *param_3 = *param_3 | 0x800000;
        _ipc_splay_tree_join(iVar7,&local_34);
      }
      _ipc_splay_tree_join(iVar7,local_1c);
    }
  }
  else {
    iVar4 = param_1 + 0x20;
    _ipc_splay_tree_delete(iVar4,param_2,param_3);
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
    if (uVar6 < uVar1) {
      puVar5 = (uint *)(iVar7 + uVar6 * 0x10);
      _ipc_splay_tree_bounds(iVar4,param_2,local_30,&local_34);
      bVar3 = false;
      if (((local_30[0] != 0xffffffff) && (local_30[0] >> 8 == param_2 >> 8)) ||
         ((local_34 != 0 && (local_34 >> 8 == param_2 >> 8)))) {
        bVar3 = true;
      }
      if (!bVar3) {
        *puVar5 = *puVar5 & 0xff7fffff;
      }
    }
    else if (uVar6 < **(uint **)(param_1 + 0x1c)) {
      _ipc_splay_tree_bounds(iVar4,param_2,local_30,&local_34);
      bVar3 = false;
      if (((local_30[0] != 0xffffffff) && (local_30[0] >> 8 == param_2 >> 8)) ||
         ((local_34 != 0 && (local_34 >> 8 == param_2 >> 8)))) {
        bVar3 = true;
      }
      if (!bVar3) {
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
      }
    }
  }
  return;
}

