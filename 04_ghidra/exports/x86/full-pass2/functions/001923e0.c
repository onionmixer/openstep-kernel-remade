/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001923e0 */

void FUN_001923e0(int param_1,byte *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((_active_threads == 0) ||
     (iVar2 = *(int *)(*(int *)(_active_threads + 0xc) + 0xc),
     *(int *)(iVar2 + 0x24) != _kernel_pmap)) {
    iVar2 = _kernel_map;
  }
  uVar1 = 1;
  if ((*param_2 & 2) != 0) {
    uVar1 = 3;
  }
  _vm_fault(iVar2,param_1 + 0x40000000U & ~_page_mask,uVar1,0,0);
  return;
}

