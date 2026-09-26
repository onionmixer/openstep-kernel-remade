
undefined4 _ipc_kobject_notify(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffecf;
  iVar2 = *(int *)(param_1 + 0x14);
  if ((iVar2 < 0x41) ||
     (((0x42 < iVar2 && ((0x48 < iVar2 || (iVar2 < 0x45)))) || (*(sword *)(iVar1 + 6) != 0xc)))) {
    uVar3 = 0;
  }
  else {
    uVar3 = _ds_notify(param_1);
  }
  return uVar3;
}
