
void _sbappendrecord(sword *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  sword sVar3;
  int iVar4;
  
  if (param_2 != (undefined4 *)0x0) {
    iVar4 = *(int *)(param_1 + 6);
    if (iVar4 != 0) {
      iVar2 = *(int *)(iVar4 + 0x7c);
      while (iVar2 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar2 = *(int *)(iVar4 + 0x7c);
      }
    }
    *param_1 = *(sword *)(param_2 + 2) + *param_1;
    sVar3 = param_1[2];
    param_1[2] = sVar3 + 0x80;
    if (0x7c < (uint)param_2[1]) {
      param_1[2] = sVar3 + 0x480;
    }
    if (iVar4 == 0) {
      *(undefined4 **)(param_1 + 6) = param_2;
    }
    else {
      *(undefined4 **)(iVar4 + 0x7c) = param_2;
    }
    uVar1 = *param_2;
    *param_2 = 0;
    _sbcompress(param_1,uVar1,param_2);
  }
  return;
}

