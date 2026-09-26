
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _pmap_extract(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar4 = (uint *)_pmap_pte(param_1,param_2);
  if (((int)puVar4 < 0) || ((*puVar4 & 3) != 1)) {
    bVar3 = _m68k_kernel_mmu_030_tt._1_1_;
    bVar1 = _m68k_kernel_mmu_030_tt._0_1_;
    iVar2 = ram0x040b57b6;
    if (_cpu_type != '\0') {
      bVar3 = _m68k_kernel_mmu_040_tt._1_1_;
      bVar1 = _m68k_kernel_mmu_040_tt._0_1_;
      iVar2 = ram0x040b57be;
    }
    uVar5 = 0;
    if (((param_1 == _kernel_pmap) && (iVar2 < 0)) &&
       ((uint)bVar1 == (~(uint)bVar3 & param_2 >> 0x18))) {
      uVar5 = param_2;
    }
  }
  else {
    if (_cpu_type == '\0') {
      uVar5 = *puVar4 >> 8;
    }
    else {
      uVar5 = *puVar4 >> 0xc;
    }
    uVar5 = (_m68k_page_mask & param_2) + (uVar5 << (_m68k_pte_pfn & 0x3f));
  }
  return uVar5;
}
