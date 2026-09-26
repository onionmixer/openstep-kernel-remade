/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174518 */

undefined4 _kmem_alloc_wait(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 local_8;
  
  uVar2 = param_2 + _page_mask & ~_page_mask;
  do {
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    _lock_set_recursive(param_1);
    local_8 = *(undefined4 *)(param_1 + 0x14);
    iVar1 = _vm_map_find(param_1,0,0,&local_8,uVar2,1);
    _lock_clear_recursive(param_1);
    if (iVar1 == 0) {
      _lock_done(param_1);
    }
    else {
      if ((uint)(*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14)) < uVar2) {
        _lock_done(param_1);
        return 0;
      }
      _assert_wait(param_1,1);
      _lock_done(param_1);
      _thread_block();
    }
  } while (iVar1 != 0);
  return local_8;
}

