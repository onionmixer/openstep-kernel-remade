
undefined4 _mach_port_server(int param_1,uint *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  *param_2 = (uint)*(byte *)(param_1 + 2);
  param_2[1] = 0x20;
  param_2[2] = *(uint *)(param_1 + 0xc);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = *(int *)(param_1 + 0x14) + 100;
  param_2[6] = dword_40B020C;
  if ((*(int *)(param_1 + 0x14) - 0xc80U < 0x13) &&
     (pcVar1 = *(code **)(*(int *)(param_1 + 0x14) * 4 + 0x40acfc0), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1,param_2);
    uVar2 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar2 = 0;
  }
  return uVar2;
}
