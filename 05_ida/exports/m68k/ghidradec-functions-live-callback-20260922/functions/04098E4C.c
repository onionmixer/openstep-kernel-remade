
int _pmap_phys_to_index(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined *in_A1;
  
  iVar3 = 0;
  iVar2 = 0;
  if (0 < _num_regions) {
    puVar1 = _mem_region;
    do {
      in_A1 = puVar1;
      if ((*(uint *)(in_A1 + 0x14) <= param_1) && (param_1 < *(uint *)(in_A1 + 0x18))) break;
      iVar3 = *(int *)(in_A1 + 0xc) + iVar3;
      iVar2 = iVar2 + 1;
      puVar1 = in_A1 + 0x1c;
    } while (iVar2 < _num_regions);
  }
  if (iVar2 == _num_regions) {
    iVar2 = -1;
  }
  else {
    iVar3 = iVar3 + ((param_1 >> (_page_shift & 0x3f)) - *(int *)(in_A1 + 4));
    iVar2 = -1;
    if (iVar3 < _managed_page_count) {
      iVar2 = iVar3;
    }
  }
  return iVar2;
}

