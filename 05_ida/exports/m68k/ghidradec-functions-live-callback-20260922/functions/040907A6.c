
int _in_bootp_noecho(int param_1)

{
  int iVar1;
  undefined auStack_a [4];
  word wStack_6;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x40067408,auStack_a,0,0);
  if (iVar1 == 0) {
    wStack_6 = wStack_6 & 0xfff7;
    iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x80067409,auStack_a,0,0);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

