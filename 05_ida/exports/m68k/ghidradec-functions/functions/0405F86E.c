
void _vm_alloc_from_regions(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  
  puVar3 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    puVar2 = &dword_40C2C40;
    do {
      uVar1 = param_1 + (-param_2 & param_2 + (*puVar2 - 1));
      if (uVar1 <= *(uint *)(puVar3 + 0x18)) {
        *puVar2 = uVar1;
        return;
      }
      puVar2 = puVar2 + 7;
      puVar3 = puVar3 + 0x1c;
    } while (puVar3 < _mem_region + _num_regions * 0x1c);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmMemAllocFrom);
}
