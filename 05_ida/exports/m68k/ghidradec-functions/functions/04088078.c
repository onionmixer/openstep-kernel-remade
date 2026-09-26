
undefined4 sub_4088078(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1[7] != param_1[8]) {
    uVar3 = 0;
    if ((*(byte *)((int)param_1 + 0x2d) & 0x40) == 0) {
      uVar3 = 2;
    }
    sub_4087F1E(param_1[7],_page_size,uVar3,*(byte *)((int)param_1 + 0x2d) & 1);
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) - _page_size;
  }
  if ((*(byte *)((int)param_1 + 0x2d) & 0x40) == 0) {
    if (param_1[1] != 0) {
      _vm_deallocate(dword_40C6EBC,*param_1,param_1[1]);
    }
    if (*(char *)(param_1 + 0xb) < '\0') {
      _snd_reply_completed(param_1[6],*(undefined4 *)((int)param_1 + 0x2e));
    }
  }
  else if (param_1[1] != 0) {
    _snd_reply_recorded_data(param_1[6],*(undefined4 *)((int)param_1 + 0x2e),*param_1,param_1[1],0);
  }
  iVar1 = *(int *)(param_2 + 0xc);
  iVar2 = *(int *)(iVar1 + 0x32);
  if (iVar2 == param_2 + 0xc) {
    *(int *)(param_2 + 0x10) = iVar2;
  }
  else {
    *(int *)(iVar2 + 0x36) = param_2 + 0xc;
  }
  *(int *)(param_2 + 0xc) = iVar2;
  _kfree(iVar1,0x3e);
  return *(undefined4 *)(param_2 + 0xc);
}
