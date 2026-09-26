
void _fc_flpctl_bclr(int *param_1,byte param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)((int)param_1 + 0x25) & ~param_2;
  *(byte *)((int)param_1 + 0x25) = bVar1;
  *(byte *)(*param_1 + 8) = bVar1;
  return;
}
