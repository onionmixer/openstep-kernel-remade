
undefined4 _thread_resume(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    uVar4 = 4;
  }
  else {
    uVar4 = 0;
    iVar1 = *(int *)(param_1 + 0x88);
    if (iVar1 < 1) {
      uVar4 = 5;
    }
    else {
      *(int *)(param_1 + 0x88) = iVar1 + -1;
      if ((iVar1 == 1) &&
         (iVar1 = *(int *)(param_1 + 0x3c), *(int *)(param_1 + 0x3c) = iVar1 + -1, iVar1 == 1)) {
        uVar2 = *(uint *)(param_1 + 0x48);
        uVar3 = uVar2 & 0xffffffed;
        *(uint *)(param_1 + 0x48) = uVar3;
        if ((uVar2 & 5) == 0) {
          *(uint *)(param_1 + 0x48) = uVar3 | 4;
          _thread_setrun(param_1,1);
        }
      }
    }
  }
  return uVar4;
}
