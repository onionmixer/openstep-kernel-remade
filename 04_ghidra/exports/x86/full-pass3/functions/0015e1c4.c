/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015e1c4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _map_vnode(int *param_1)

{
  short sVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar2 = (undefined4 *)*param_1;
  sVar1 = *(short *)(puVar2 + 1);
  *(short *)(puVar2 + 1) = *(short *)(puVar2 + 1) + 1;
  if ((sVar1 < 1) && ((*(byte *)(puVar2 + 0xe) & 0x10) == 0)) {
    _vmp_get(puVar2);
    uVar4 = _vnode_pager_setup(param_1,0,1);
    *puVar2 = uVar4;
    _lock_write(&_vm_alloc_lock);
    uVar5 = _vm_object_lookup(uVar4);
    puVar2[9] = uVar5;
    _DAT_001f651c = _DAT_001f651c + 1;
    if (puVar2[9] == 0) {
      uVar5 = _vm_object_allocate(0);
      puVar2[9] = uVar5;
      _vm_object_enter(uVar5,uVar4);
      _vm_object_setpager(puVar2[9],uVar4,0,0);
    }
    else {
      _DAT_001f6520 = _DAT_001f6520 + 1;
    }
    _lock_done(&_vm_alloc_lock);
    puVar2[0xd] = 0;
    uVar4 = _vnode_size(param_1);
    puVar2[5] = uVar4;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    *(byte *)(puVar2 + 0xe) = *(byte *)(puVar2 + 0xe) | 0x10;
    uVar3 = puVar2[5];
    if ((uVar3 != 0) && (uVar3 < _mfs_max_window)) {
      _remap_vnode(param_1,0,uVar3);
    }
    _vmp_put(puVar2);
  }
  return;
}

