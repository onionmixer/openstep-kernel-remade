
void _kalloc_init(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  _kalloc_map = _kernel_map;
  iVar3 = 0;
  puVar4 = unk_40B3612;
  do {
    uVar1 = *(uint *)(_k_zone_elemsize + iVar3 * 4);
    if (_page_size <= uVar1) {
      return;
    }
    _sprintf(puVar4,aKallocD,uVar1);
    uVar2 = _zinit(uVar1,0x100000,_page_size,0,puVar4);
    *(undefined4 *)(_k_zone + iVar3 * 4) = uVar2;
    puVar4 = puVar4 + 0x10;
    iVar3 = iVar3 + 1;
    _k_zone_maxsize = uVar1;
  } while (iVar3 < 0x10);
  return;
}
