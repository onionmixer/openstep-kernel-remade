
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
