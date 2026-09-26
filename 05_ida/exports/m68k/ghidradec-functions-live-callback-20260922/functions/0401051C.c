
void _ptsselect(byte param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  (**(code **)(DAT_40ae4d4 + *(char *)(iVar1 + 0x45) * 0x30))(iVar1,param_2);
  return;
}

