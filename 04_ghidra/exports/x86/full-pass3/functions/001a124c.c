/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a124c */

int _PCmapBIOSRom(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int unaff_ESI;
  undefined4 local_c;
  uint local_8;
  
  if (param_3 == 0) {
    iVar2 = _copyin(param_2,&local_8,4);
    if (iVar2 != 0) {
      return 4;
    }
    local_8 = local_8 & ~_page_mask;
  }
  else {
    local_8 = *(uint *)(*(int *)(unaff_ESI + 0xc) + 0x14);
  }
  iVar2 = _object_copyin(*(undefined4 *)(_active_threads + 0xc),param_1,6,0,&local_c);
  if (iVar2 != 0) {
    iVar2 = _convert_port_to_task(local_c);
    _port_release(local_c);
    if (iVar2 != 0) {
      iVar3 = _vm_map_find(*(undefined4 *)(iVar2 + 0xc),0,0,&local_8,
                           _page_mask + 0x10000 & ~_page_mask,param_3);
      if (iVar3 != 0) {
        _task_deallocate(iVar2);
        return iVar3;
      }
      if ((param_3 != 0) && (iVar3 = _copyout(&local_8,param_2,4), iVar3 != 0)) {
        _task_deallocate(iVar2);
        return 4;
      }
      uVar1 = local_8 + 0x10000 + _page_mask;
      uVar4 = ~_page_mask;
      uVar5 = uVar4 & 0xf0000;
      for (; local_8 < (uVar1 & uVar4); local_8 = local_8 + _page_size) {
        _pmap_enter(*(undefined4 *)(*(int *)(iVar2 + 0xc) + 0x24),local_8,uVar5,1,1);
        uVar5 = uVar5 + _page_size;
      }
      _task_deallocate(iVar2);
      return 0;
    }
  }
  return 4;
}

