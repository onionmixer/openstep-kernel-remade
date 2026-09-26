
undefined4 sub_40568A0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0xc) == 0) {
    uVar1 = (**(code **)(param_2 + 4))(param_1,*(undefined4 *)(param_2 + 8));
  }
  else {
    iVar2 = _kalloc(0x2000);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 8);
    (**(code **)(param_2 + 4))(param_1,iVar2);
    if (*(int *)(iVar2 + 0x1c) == -0x131) {
      uVar1 = 0;
    }
    else {
      uVar1 = _msg_send(iVar2,0,0);
    }
    _kfree(iVar2,0x2000);
  }
  return uVar1;
}

