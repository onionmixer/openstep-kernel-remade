
void _dma_init(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffff8fff;
  **(undefined4 **)(param_1 + 0x1c) = 0x100000;
  _install_scanned_intr(param_2,_dma_intr,param_1);
  uVar1 = param_1 + 0x53U & 0xfffffff0;
  *(uint *)(param_1 + 0x3c) = uVar1;
  if (_m68k_page_size - (_m68k_page_size - 1U & uVar1) < 0x80) {
    iVar2 = _kalloc(0x110);
    *(int *)(param_1 + 0x38) = iVar2;
    uVar1 = iVar2 + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x3c) = uVar1;
    if (_m68k_page_size - (uVar1 & _m68k_page_size - 1U) < 0x80) {
      *(uint *)(param_1 + 0x3c) = uVar1 + 0x80;
    }
  }
  uVar3 = _pmap_kernel(*(undefined4 *)(param_1 + 0x3c));
  uVar3 = _pmap_resident_extract(uVar3);
  *(undefined4 *)(param_1 + 0x40) = uVar3;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}
