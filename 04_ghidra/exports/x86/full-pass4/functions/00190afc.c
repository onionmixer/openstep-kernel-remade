/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00190afc */

void _pmap_enter_shared_range(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_2 + param_3 + _page_mask;
  uVar1 = ~_page_mask;
  for (; param_2 < (uVar3 & uVar1); param_2 = param_2 + _page_size) {
    uVar2 = _pmap_resident_extract(_kernel_pmap,param_4,3,1);
    _pmap_enter(param_1,param_2,uVar2);
    param_4 = param_4 + _page_size;
  }
  return;
}

