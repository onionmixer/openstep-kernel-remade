
void _bpt_reg(uint param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)segment(0x4c);
  puVar2 = (uint *)segment(0x4c);
  *puVar2 = (param_1 | *puVar1) & ~param_2;
  return;
}
