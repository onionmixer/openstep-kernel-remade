
void _clntkudp_init(int param_1,uint *param_2,uint param_3,sword *param_4)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 8);
  puVar1[4] = param_3;
  puVar1[6] = *param_2;
  puVar1[7] = param_2[1];
  puVar1[8] = param_2[2];
  puVar1[9] = param_2[3];
  puVar1[0x1d] = (uint)param_4;
  *param_4 = *param_4 + 1;
  *puVar1 = *puVar1 & 0x18;
  return;
}

