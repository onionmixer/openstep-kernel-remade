/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00165784 */

kern_return_t
_map_fd(int fd,vm_offset_t offset,vm_offset_t *addr,boolean_t find_space,vm_size_t numbytes)

{
  vm_map_t target_task;
  int *piVar1;
  int iVar2;
  kern_return_t kVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint size;
  undefined4 local_c;
  vm_address_t local_8;
  
  target_task = *(vm_map_t *)(*(int *)(_active_threads + 0xc) + 0xc);
  iVar2 = _getf(fd);
  if (((iVar2 == 0) || (piVar1 = *(int **)(iVar2 + 0x18), *(short *)(iVar2 + 0xc) != 1)) ||
     (piVar1[10] != 1)) {
LAB_0016587c:
    kVar3 = 4;
  }
  else {
    size = numbytes + _page_mask & ~_page_mask;
    if (find_space == 0) {
      iVar2 = _copyin(addr,&local_8,4);
      if (iVar2 != 0) {
        return 1;
      }
      uVar6 = ~_page_mask & local_8;
      if ((uVar6 != local_8) ||
         (iVar2 = _vm_map_check_protection(target_task,uVar6,size + uVar6,3), iVar2 == 0))
      goto LAB_0016587c;
    }
    else {
      kVar3 = _vm_allocate(target_task,&local_8,numbytes,1);
      if (kVar3 != 0) {
        return kVar3;
      }
      iVar2 = _copyout(&local_8,addr,4);
      if (iVar2 != 0) {
        _vm_deallocate(target_task,local_8,numbytes);
        return 1;
      }
    }
    if (numbytes == 0) {
      kVar3 = 0;
    }
    else {
      uVar4 = _vnode_pager_setup(piVar1,0,0);
      uVar5 = _pmap_create(size,0,size,1);
      uVar5 = _vm_map_create(uVar5);
      local_c = 0;
      kVar3 = _vm_allocate_with_pager(uVar5,&local_c,size,0,uVar4,offset);
      if (((kVar3 != 0) || (kVar3 = _vm_map_copy(target_task,uVar5,local_8,size,0,0,0), kVar3 != 0))
         && (find_space != 0)) {
        _vm_deallocate(target_task,local_8,size);
      }
      _vm_map_deallocate(uVar5);
      if (*(int *)(*piVar1 + 0x30) == 0) {
        **(short **)(_active_u + 0x1c) = **(short **)(_active_u + 0x1c) + 1;
        *(undefined4 *)(*piVar1 + 0x30) = *(undefined4 *)(_active_u + 0x1c);
      }
    }
  }
  return kVar3;
}

