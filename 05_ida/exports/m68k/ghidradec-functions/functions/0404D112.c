
void _map_vnode(int *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  sword sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)*param_1;
  sVar3 = *(sword *)(puVar1 + 1);
  *(sword *)(puVar1 + 1) = *(sword *)(puVar1 + 1) + 1;
  if ((sVar3 < 1) && ((*(byte *)(puVar1 + 0xd) & 8) == 0)) {
    _vmp_get(puVar1);
    uVar4 = _vnode_pager_setup(param_1,0,1);
    *puVar1 = uVar4;
    _lock_write(&_vm_alloc_lock);
    uVar5 = _vm_object_lookup(uVar4);
    puVar1[8] = uVar5;
    dword_40C240C = dword_40C240C + 1;
    if (puVar1[8] == 0) {
      uVar5 = _vm_object_allocate(0);
      puVar1[8] = uVar5;
      _vm_object_enter(uVar5,uVar4);
      _vm_object_setpager(puVar1[8],uVar4,0,0);
    }
    else {
      dword_40C2410 = dword_40C2410 + 1;
    }
    _lock_done(&_vm_alloc_lock);
    puVar1[0xc] = 0;
    uVar4 = _vnode_size(param_1);
    puVar1[5] = uVar4;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    *(byte *)(puVar1 + 0xd) = *(byte *)(puVar1 + 0xd) | 8;
    uVar2 = puVar1[5];
    if ((uVar2 != 0) && (uVar2 < _mfs_max_window)) {
      _remap_vnode(param_1,0,uVar2);
    }
    _vmp_put(puVar1);
  }
  return;
}
