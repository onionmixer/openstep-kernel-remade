/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c6e8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _vm_statistics(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    _vm_stat = _page_size;
    DAT_001f64f4 = _vm_page_free_count;
    _DAT_001f64f8 = _vm_page_active_count;
    _DAT_001f64fc = _vm_page_inactive_count;
    _DAT_001f6500 = _vm_page_wire_count;
    puVar3 = &_vm_stat;
    for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}

