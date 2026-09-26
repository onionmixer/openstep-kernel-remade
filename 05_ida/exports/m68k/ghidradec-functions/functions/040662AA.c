
int _ioaccess(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = (~_page_mask & _page_mask + param_3) >> (_page_shift & 0x3f);
  iVar3 = param_2;
  uVar4 = param_1;
  do {
    uVar1 = _pmap_kernel(iVar3,uVar4,3,0,0,1);
    _pmap_enter_mapping(uVar1);
    uVar4 = _page_size + uVar4;
    iVar3 = _page_size + iVar3;
    uVar2 = uVar2 - 1;
  } while (0 < (int)uVar2);
  return param_2 + (_m68k_page_mask & param_1);
}
