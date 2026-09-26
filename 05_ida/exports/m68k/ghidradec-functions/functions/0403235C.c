
int _spec_setattr(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  iVar3 = *(int *)(iVar1 + 0x36);
  if (iVar3 != 0) {
    *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
    iVar3 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x18))(iVar3,param_2,param_3);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  cVar4 = *(int *)(param_2 + 0x24) != -1;
  if ((bool)cVar4) {
    uVar2 = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)(iVar1 + 0x52) = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 *)(iVar1 + 0x56) = uVar2;
  }
  if (*(int *)(param_2 + 0x1c) != -1) {
    uVar2 = *(undefined4 *)(param_2 + 0x20);
    *(undefined4 *)(iVar1 + 0x4a) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(iVar1 + 0x4e) = uVar2;
    cVar4 = cVar4 + '\x01';
  }
  if (cVar4 != '\0') {
    _getthetime(&uStack_c);
    *(undefined4 *)(iVar1 + 0x5a) = uStack_c;
    *(undefined4 *)(iVar1 + 0x5e) = uStack_8;
  }
  return 0;
}
