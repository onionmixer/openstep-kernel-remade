
void _vik_vac_init_asm(uint param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 & ~param_1 | param_2;
  return;
}

