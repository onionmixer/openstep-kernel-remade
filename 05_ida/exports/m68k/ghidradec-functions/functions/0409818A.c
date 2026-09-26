
uint _pmap_protect(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  
  if (param_1 != 0) {
    if (param_4 == 0) {
      param_4 = _pmap_remove(param_1,param_2,param_3);
    }
    else {
      uVar1 = *(undefined4 *)(_protection_codes + param_4 * 4);
      if (param_1 == _kernel_pmap) {
        param_4 = _pflush_super();
      }
      else if (_active_threads != 0) {
        param_4 = _pflush_user();
      }
      if (param_2 < param_3) {
        do {
          uVar2 = _m68k_pte_maps + (-_m68k_pte_maps & param_2);
          uVar4 = _pmap_pte(param_1,param_2);
          param_4 = uVar4;
          if (0 < (int)uVar4) {
            if (param_3 < uVar2) {
              param_4 = param_3 - param_2 >> (_m68k_page_shift & 0x3f);
              uVar5 = uVar4 + param_4 * 4;
            }
            else {
              param_4 = _pmap_pte(param_1,uVar2 - 1);
              uVar5 = param_4 + 4;
            }
            if (uVar4 < uVar5) {
              pbVar6 = (byte *)(uVar4 + 3);
              do {
                bVar3 = ((byte)uVar1 & 1) << 2 | *pbVar6 & 0xfb;
                param_4 = (uint)bVar3;
                *pbVar6 = bVar3;
                pbVar6 = pbVar6 + 4;
                uVar4 = uVar4 + 4;
              } while (uVar4 < uVar5);
            }
          }
          param_2 = uVar2;
        } while (uVar2 < param_3);
      }
      if (param_1 == _kernel_pmap) {
        param_4 = (uint)(byte)((param_1 < _kernel_pmap) << 4 |
                               ((int)(param_1 - _kernel_pmap) < 0) << 3 | 4U |
                               SBORROW4(param_1,_kernel_pmap) << 1 | param_1 < _kernel_pmap);
      }
    }
  }
  return param_4;
}
