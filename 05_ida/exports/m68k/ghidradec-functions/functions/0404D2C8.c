
undefined4 _remap_vnode(int *param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uStack_8;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1[3] != 0) {
    _mfs_map_remove(puVar1,puVar1[2],puVar1[3] + puVar1[2],1);
  }
  uVar2 = ~_page_mask & param_2;
  uVar6 = (~_page_mask & _page_mask + param_3 + param_2) - uVar2;
  if (uVar6 < 0x10000) {
    uVar6 = 0x10000;
  }
  do {
    uStack_8 = *(undefined4 *)(_mfs_map + 0x10);
    _lock_write(&_mfs_alloc_lock_data);
    iVar4 = _vm_allocate_with_pager(_mfs_map,&uStack_8,uVar6,1,*puVar1,uVar2);
    puVar3 = _vm_info_queue;
    if (iVar4 == 3) {
      puVar5 = (undefined4 *)0x0;
      if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
        _vm_info_dequeue(_vm_info_queue);
        puVar5 = puVar3;
      }
      if (puVar5 == (undefined4 *)0x0) {
        _mfs_alloc_wanted = 1;
        _assert_wait(&_mfs_map,0);
        _mfs_alloc_blocks = _mfs_alloc_blocks + 1;
        _lock_done(&_mfs_alloc_lock_data);
        _thread_block();
      }
      else {
        _lock_done(&_mfs_alloc_lock_data);
        _mfs_memfree(puVar5,1);
      }
      _lock_write(&_mfs_alloc_lock_data);
    }
    else if (iVar4 != 0) {
      _printf(aUnexpectedErro,iVar4);
                    /* WARNING: Subroutine does not return */
      _panic(aRemapVnode);
    }
    _lock_done(&_mfs_alloc_lock_data);
  } while (iVar4 != 0);
  puVar1[2] = uStack_8;
  puVar1[3] = uVar6;
  puVar1[4] = uVar2;
  return 1;
}
