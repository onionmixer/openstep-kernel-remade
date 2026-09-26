/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00195558 */

undefined4 _createEventShmem(undefined4 param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  *param_3 = 0;
  iVar1 = _IOGetKernPort(param_1);
  if (iVar1 == 0) {
    uVar2 = 4;
  }
  else {
    iVar3 = _convert_port_to_map(iVar1);
    if (iVar3 == 0) {
      _port_release(iVar1);
      uVar2 = 4;
    }
    else {
      _port_release(iVar1);
      uVar5 = param_2 + _page_mask & ~_page_mask;
      iVar1 = _kmem_alloc_wired(_kernel_map,param_5,uVar5);
      if (iVar1 == 0) {
        *param_4 = *(int *)(iVar3 + 0x14);
        iVar1 = _vm_map_find(iVar3,0,0,param_4,uVar5,1);
        if (iVar1 == 0) {
          uVar4 = 0;
          if (uVar5 != 0) {
            do {
              iVar1 = _pmap_extract(_kernel_pmap,*param_5 + uVar4);
              if (iVar1 == 0) {
                _IOLog(s_createEventShmem__no_paddr_for_v_001e373a,*param_5 + uVar4);
                _kmem_free(_kernel_map,*param_5,param_2);
                _vm_map_deallocate(iVar3);
                return 3;
              }
              _pmap_enter(*(undefined4 *)(iVar3 + 0x24),*param_4 + uVar4,iVar1,3,1);
              uVar4 = uVar4 + _page_size;
            } while (uVar4 < uVar5);
          }
          *param_3 = iVar3;
          uVar2 = 0;
        }
        else {
          _IOLog(s_createEventShmem__vm_map_find___r_001e370d,iVar1);
          _vm_map_deallocate(iVar3);
          uVar2 = 3;
        }
      }
      else {
        _vm_map_deallocate(iVar3);
        uVar2 = 3;
      }
    }
  }
  return uVar2;
}

