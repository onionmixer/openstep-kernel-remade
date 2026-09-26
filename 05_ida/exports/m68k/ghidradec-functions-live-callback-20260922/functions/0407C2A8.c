
undefined4 _scsi_ioctl(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (param_2 == 0x20006409) {
    (**(code **)(*(int *)(iVar1 + 0x14) + 8))(iVar1,1,aBusReset);
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x14) + 4))(iVar1,param_2,param_3,param_4);
  }
  return uVar2;
}

