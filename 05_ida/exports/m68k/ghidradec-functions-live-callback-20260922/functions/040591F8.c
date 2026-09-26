
undefined4 _mach_host_server_routine(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(int *)(param_1 + 0x14) - 0xa28;
  if (uVar1 < 0x2a) {
    uVar2 = *(undefined4 *)(unk_40B005C + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

