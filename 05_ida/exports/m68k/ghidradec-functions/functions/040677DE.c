
void _vcopy(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4,uint param_5)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_3 < param_1) {
    for (; param_5 != 0; param_5 = param_5 - uVar2) {
      uVar3 = _m68k_page_size - (_m68k_page_mask & param_1);
      uVar2 = param_5;
      if (uVar3 <= param_5) {
        uVar2 = uVar3;
      }
      uVar3 = _m68k_page_size - (_m68k_page_mask & param_3);
      if (uVar3 <= uVar2) {
        uVar2 = uVar3;
      }
      uVar1 = _pmap_resident_extract(param_4,param_3,uVar2);
      uVar1 = _pmap_resident_extract(param_2,param_1,uVar1);
      _bcopy(uVar1);
      param_1 = uVar2 + param_1;
      param_3 = uVar2 + param_3;
    }
  }
  else {
    param_1 = param_5 + param_1;
    param_3 = param_5 + param_3;
    for (; param_5 != 0; param_5 = param_5 - uVar3) {
      uVar2 = _m68k_page_mask & param_1;
      if ((_m68k_page_mask & param_1) == 0) {
        uVar2 = _m68k_page_size;
      }
      uVar3 = param_5;
      if ((int)uVar2 < (int)param_5) {
        uVar3 = uVar2;
      }
      uVar2 = _m68k_page_mask & param_3;
      if ((_m68k_page_mask & param_3) == 0) {
        uVar2 = _m68k_page_size;
      }
      if ((int)uVar2 < (int)uVar3) {
        uVar3 = uVar2;
      }
      param_1 = param_1 - uVar3;
      param_3 = param_3 - uVar3;
      uVar1 = _pmap_resident_extract(param_4,param_3,uVar3);
      uVar1 = _pmap_resident_extract(param_2,param_1,uVar1);
      _bcopy(uVar1);
    }
  }
  return;
}
