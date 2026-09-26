
undefined4 _mach_debug_server_routine(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(int *)(param_1 + 0x14) - 3000;
  if (uVar1 < 0x16) {
    uVar2 = *(undefined4 *)(unk_40B065C + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
