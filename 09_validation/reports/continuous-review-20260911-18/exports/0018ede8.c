
uint _pmap_map(uint param_1,uint param_2,uint param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_4 != 0) {
    uVar2 = ((&_kernel_prot_codes)[param_4] & 3) * 2 | 1 | param_2 & 0xfffff000;
  }
  for (; param_2 < param_3; param_2 = param_2 + 0x1000) {
    puVar1 = (uint *)((param_1 >> 0x16) * 4 + *_kernel_pmap);
    if (((*puVar1 & 1) == 0) ||
       (puVar1 = (uint *)((*puVar1 & 0xfffff000) + (param_1 >> 10 & 0xffc)), puVar1 == (uint *)0x0))
    {
      FUN_0018ecc0(param_1);
      puVar1 = (uint *)((param_1 >> 0x16) * 4 + *_kernel_pmap);
      if ((*puVar1 & 1) == 0) {
        puVar1 = (uint *)0x0;
      }
      else {
        puVar1 = (uint *)((*puVar1 & 0xfffff000) + (param_1 >> 10 & 0xffc));
      }
    }
    if (param_2 - 0xa0000 < 0x60000) {
      uVar2 = uVar2 | 8;
    }
    else {
      uVar2 = uVar2 & 0xfffffff7;
    }
    *puVar1 = uVar2;
    if (param_4 != 0) {
      uVar2 = uVar2 & 0xfff | (uVar2 & 0xfffff000) + 0x1000;
    }
    param_1 = param_1 + 0x1000;
  }
  return param_1;
}

