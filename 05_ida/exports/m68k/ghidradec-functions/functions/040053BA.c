
int _check_exec_access(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined auStack_3e [4];
  word wStack_3a;
  
  uVar1 = *(undefined4 *)((int)_active_u + 0x1a);
  iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))(param_1,auStack_3e,uVar1);
  if ((iVar2 == 0) &&
     (iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40,uVar1), iVar2 == 0)) {
    if (((*(byte *)(*_active_u + 0x2b) & 0x10) != 0) &&
       (iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x100,uVar1), iVar2 != 0)) {
      return iVar2;
    }
    if ((*(int *)(param_1 + 0x28) == 1) && ((wStack_3a & 0x49) != 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0xd;
    }
  }
  return iVar2;
}
