/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0e48 */

int _PCcreate(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_c;
  uint local_8;
  
  iVar4 = *(int *)(_active_threads + 0xc);
  iVar1 = _suser();
  if (iVar1 == 0) {
    return 5;
  }
  if (param_3 == 0) {
    iVar1 = _copyin(param_2,&local_8,4);
    if (iVar1 != 0) {
      return 4;
    }
    local_8 = local_8 & ~_page_mask;
  }
  else {
    local_8 = *(uint *)(*(int *)(iVar4 + 0xc) + 0x14);
  }
  iVar1 = _object_copyin(iVar4,param_1,6,0,&local_c);
  if (iVar1 != 0) {
    iVar1 = _convert_port_to_thread(local_c);
    _port_release(local_c);
    if (iVar1 != 0) {
      iVar2 = *(int *)(*(int *)(iVar1 + 0x28) + 0xec);
      if (iVar2 != 0) {
        if (param_3 == 0) {
          iVar4 = 1;
          if (local_8 == *(uint *)(iVar2 + 8)) {
            iVar4 = 0;
          }
        }
        else {
          local_8 = *(uint *)(iVar2 + 8);
          iVar2 = _copyout(&local_8,param_2,4);
          iVar4 = 0;
          if (iVar2 != 0) {
            iVar4 = 4;
          }
        }
        _thread_deallocate(iVar1);
        return iVar4;
      }
      iVar2 = _vm_map_find(*(undefined4 *)(iVar4 + 0xc),0,0,&local_8,
                           _page_mask + 0x51c & ~_page_mask,param_3);
      if (iVar2 == 0) {
        if ((param_3 != 0) && (iVar2 = _copyout(&local_8,param_2,4), iVar2 != 0)) {
          _thread_deallocate(iVar1);
          return 4;
        }
        _vm_map_reference(*(undefined4 *)(iVar4 + 0xc));
        piVar3 = (int *)_kalloc(0xc);
        _memset(piVar3,0,0xc);
        *piVar3 = 0;
        _kmem_alloc_wired(_kernel_map,piVar3,0x51c);
        piVar3[1] = *(int *)(iVar4 + 0xc);
        piVar3[2] = local_8;
        _pmap_enter_shared_range(*(undefined4 *)(piVar3[1] + 0x24),local_8,0x51c,*piVar3);
        *(undefined4 *)*piVar3 = 0xf;
        *(undefined4 *)(*piVar3 + 0x4a8) = 1;
        *(int **)(*(int *)(iVar1 + 0x28) + 0xec) = piVar3;
        _thread_deallocate(iVar1);
        return 0;
      }
      _thread_deallocate(iVar1);
      return iVar2;
    }
  }
  return 4;
}

