
uint _vik_pte_rmw(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_1 & ~param_2 | param_3;
  return uVar1;
}

