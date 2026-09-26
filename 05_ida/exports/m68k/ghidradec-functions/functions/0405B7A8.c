
undefined4 _mach_server_routine(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(int *)(param_1 + 0x14) - 2000;
  if (uVar1 < 0x68) {
    uVar2 = *(undefined4 *)(unk_40B03F0 + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
