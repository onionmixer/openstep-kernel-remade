
undefined4 _mxcc_vac_parity_chk_dis(uint param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if ((((param_1 & 0x2000) == 0) && ((param_1 & 0x4000) == 0)) && ((param_2 & 0x8000000) == 0)) {
    return 0;
  }
  iVar1 = segment(2);
  puVar2 = (uint *)segment(4);
  uVar4 = *puVar2;
  iVar3 = segment(2);
  *(uint *)(iVar3 + 0x1c00a04) = ~*(uint *)(iVar1 + 0x1c00a04) & 8;
  puVar2 = (uint *)segment(4);
  *puVar2 = ~uVar4 & 0x1000;
  return 1;
}
