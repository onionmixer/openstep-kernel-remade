/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c28c */

void _device_dealloc(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  puVar2 = (undefined4 *)*puVar1;
  while (puVar2 != puVar1) {
    _vm_page_remove(*puVar1);
    puVar2 = (undefined4 *)*puVar1;
  }
  _kfree(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  return;
}

