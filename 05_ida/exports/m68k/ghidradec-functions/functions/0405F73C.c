
int _vm_mem_ppi(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = _mem_region;
  while( true ) {
    if (_mem_region + _num_regions * 0x1c <= puVar1) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMemPpi);
    }
    if ((*(uint *)(puVar1 + 0x14) <= param_1) && (param_1 < *(uint *)(puVar1 + 0x18))) break;
    iVar2 = *(int *)(puVar1 + 0xc) + iVar2;
    puVar1 = puVar1 + 0x1c;
  }
  return iVar2 + (param_1 - *(uint *)(puVar1 + 0x14) >> (_page_shift & 0x3f));
}
