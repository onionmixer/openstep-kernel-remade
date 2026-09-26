
void _pagemove(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_3 % _page_size != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aPagemove);
  }
  uVar1 = *(undefined4 *)(_kernel_map + 0x20);
  for (; 0 < (int)param_3; param_3 = param_3 - _m68k_page_size) {
    while (puVar2 = (undefined4 *)_pmap_pte(uVar1,param_1), (int)puVar2 < 0) {
      _pmap_expand_kernel(param_1,puVar2);
    }
    while (puVar3 = (undefined4 *)_pmap_pte(uVar1,param_2), (int)puVar3 < 0) {
      _pmap_expand_kernel(param_2,puVar3);
    }
    *puVar3 = *puVar2;
    *puVar2 = 0;
    _pflush_user();
    _pflush_user();
    param_1 = _m68k_page_size + param_1;
    param_2 = _m68k_page_size + param_2;
  }
  return;
}

