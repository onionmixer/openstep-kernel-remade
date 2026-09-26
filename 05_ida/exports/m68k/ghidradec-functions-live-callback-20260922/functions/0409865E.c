
uint _pmap_change_wiring(uint param_1,undefined4 param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  uVar2 = _pmap_pte_valid(param_1,param_2);
  if (param_1 == _kernel_pmap) {
    uVar3 = _pflush_super();
  }
  else {
    uVar3 = uVar2;
    if (_active_threads != 0) {
      uVar3 = _pflush_user();
    }
  }
  uVar3 = CONCAT31((int3)(uVar3 >> 8),*(byte *)(uVar2 + 3)) & 0xffffff03;
  if (((*(byte *)(uVar2 + 3) & 3) == 1) &&
     (uVar1 = uVar2 + _m68k_ptes_per_page * 4, uVar3 = _m68k_ptes_per_page, uVar2 < uVar1)) {
    uVar3 = CONCAT31((int3)(_m68k_ptes_per_page >> 8),param_3) & 0xffffff01;
    pbVar6 = (byte *)(uVar2 + 3);
    pbVar5 = (byte *)(uVar2 + 2);
    do {
      if (_cpu_type == '\0') {
        bVar4 = (param_3 & 1) << 5 | *pbVar6 & 0xdf;
        *pbVar6 = bVar4;
      }
      else {
        bVar4 = (param_3 & 1) << 3 | *pbVar5 & 0xf7;
        *pbVar5 = bVar4;
      }
      uVar3 = CONCAT31((int3)(uVar3 >> 8),bVar4);
      pbVar6 = pbVar6 + 4;
      pbVar5 = pbVar5 + 4;
      uVar2 = uVar2 + 4;
    } while (uVar2 < uVar1);
  }
  if (param_1 == _kernel_pmap) {
    uVar3 = (uint)(byte)((param_1 < _kernel_pmap) << 4 | ((int)(param_1 - _kernel_pmap) < 0) << 3 |
                         4U | SBORROW4(param_1,_kernel_pmap) << 1 | param_1 < _kernel_pmap);
  }
  return uVar3;
}

