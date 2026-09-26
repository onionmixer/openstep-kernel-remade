
void _pmap_init(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_8;
  
  iVar3 = 0;
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar3 = *(int *)(param_1 + 0xc) + iVar3;
      param_1 = param_1 + 0x1c;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  uVar1 = ~_page_mask & _page_mask + iVar3 * 0xc;
  _kmem_alloc_wired(_kernel_map,&uStack_8,uVar1);
  _bzero(uStack_8,uVar1);
  _pmap_zone = _zinit(0x18,0x2580,0,0,&aPmap);
  _pv_list_zone = _zinit(0xc,1200000,0,0,&aPvList);
  _pv_head_table = uStack_8;
  _managed_page_count = iVar3;
  return;
}

