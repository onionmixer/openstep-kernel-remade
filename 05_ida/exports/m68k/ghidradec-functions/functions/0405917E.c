
undefined4 _mach_host_server(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  *param_2 = (uint)*(byte *)(param_1 + 2);
  param_2[1] = 0x20;
  param_2[2] = *(uint *)(param_1 + 0xc);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = *(int *)(param_1 + 0x14) + 100;
  param_2[6] = dword_40B0104;
  if ((*(int *)(param_1 + 0x14) - 0xa28U < 0x2a) &&
     (*(code **)(unk_40AD7BC + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(unk_40AD7BC + *(int *)(param_1 + 0x14) * 4))(param_1,param_2);
    uVar1 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar1 = 0;
  }
  return uVar1;
}
