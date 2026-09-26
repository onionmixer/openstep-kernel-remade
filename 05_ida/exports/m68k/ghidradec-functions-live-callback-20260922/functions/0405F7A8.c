
undefined4 _vm_valid_page(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = _mem_region;
  while( true ) {
    if (_mem_region + _num_regions * 0x1c <= puVar1) {
      return 0;
    }
    if ((*(uint *)(puVar1 + 0x14) <= param_1) && (param_1 < *(uint *)(puVar1 + 0x18))) break;
    puVar1 = puVar1 + 0x1c;
  }
  return 1;
}

