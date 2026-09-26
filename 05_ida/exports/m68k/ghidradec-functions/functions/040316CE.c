
int _specvp(int param_1,sword param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined auStack_3e [28];
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  
  iVar1 = sub_4031ADE((int)param_2,param_1,param_3);
  if (iVar1 == 0) {
    if ((param_1 == 0) || (*(int *)(param_1 + 0x28) != 8)) {
      iVar1 = _kalloc(0x66);
      _bzero(iVar1,0x66);
      *(undefined **)(iVar1 + 0x20) = _spec_vnodeops;
      if (param_1 != 0) {
        iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
                          (param_1,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
        if (iVar2 == 0) {
          *(undefined4 *)(iVar1 + 0x4a) = uStack_22;
          *(undefined4 *)(iVar1 + 0x4e) = uStack_1e;
          *(undefined4 *)(iVar1 + 0x52) = uStack_1a;
          *(undefined4 *)(iVar1 + 0x56) = uStack_16;
          *(undefined4 *)(iVar1 + 0x5a) = uStack_12;
          *(undefined4 *)(iVar1 + 0x5e) = uStack_e;
        }
      }
    }
    else {
      iVar1 = _fifosp(param_1);
    }
    *(int *)(iVar1 + 0x36) = param_1;
    *(sword *)(iVar1 + 0x40) = param_2;
    *(sword *)(iVar1 + 0x30) = param_2;
    *(undefined2 *)(iVar1 + 10) = 1;
    *(int *)(iVar1 + 0x32) = iVar1;
    if (param_1 == 0) {
      *(undefined4 *)(iVar1 + 0x2c) = 3;
      *(undefined4 *)(iVar1 + 0x28) = 0;
      *(int *)(iVar1 + 0x3a) = iVar1 + 4;
    }
    else {
      *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
      *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      if (*(int *)(param_1 + 0x28) == 3) {
        iVar2 = _bdevvp((int)param_2);
        *(int *)(iVar1 + 0x3a) = iVar2;
        *(undefined4 *)(iVar1 + 0x46) = *(undefined4 *)(*(int *)(iVar2 + 0x2e) + 0x46);
      }
    }
    sub_40318CE(iVar1);
  }
  _set_blocksize(iVar1,(int)param_2);
  return iVar1 + 4;
}
