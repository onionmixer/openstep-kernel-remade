
int _vm_phys_to_vm_page(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    do {
      if ((*(uint *)((int)puVar1 + 0x14) <= param_1) && (param_1 < *(uint *)((int)puVar1 + 0x18))) {
        return *(int *)puVar1 +
               ((param_1 >> (_page_shift & 0x3f)) - *(int *)((int)puVar1 + 4)) * 0x2e;
      }
      puVar1 = (undefined *)((int)puVar1 + 0x1c);
    } while (puVar1 < _mem_region + _num_regions * 0x1c);
  }
  return 0;
}
