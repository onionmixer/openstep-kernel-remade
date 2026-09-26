/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f74c */

int __KernBusMemoryCreateMapping
              (uint param_1,int param_2,uint *param_3,int param_4,char param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_4 + 0xc);
  _vm_map_reference(iVar1);
  if (param_5 == '\0') {
    *param_3 = *param_3 & ~_page_mask;
  }
  else {
    *param_3 = *(uint *)(iVar1 + 0x14);
  }
  iVar2 = _vm_map_find(iVar1,0,0,param_3,param_2,(int)param_5);
  if (iVar2 == 0) {
    uVar3 = ~_page_mask & *param_3;
    uVar4 = ~_page_mask & _page_mask + param_2;
    _vm_map_inherit(iVar1,uVar3,uVar4 + uVar3,2);
    param_1 = param_1 & ~_page_mask;
    if (param_6 == 0) {
      uVar5 = 2;
    }
    else if (param_6 == 1) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    for (; uVar4 != 0; uVar4 = uVar4 - _page_size) {
      _pmap_enter_cache_spec(*(undefined4 *)(iVar1 + 0x24),uVar3,param_1,3,1,uVar5);
      uVar3 = uVar3 + _page_size;
      param_1 = param_1 + _page_size;
    }
    _vm_map_deallocate(iVar1);
    iVar2 = 0;
  }
  else {
    _vm_map_deallocate(iVar1);
  }
  return iVar2;
}

