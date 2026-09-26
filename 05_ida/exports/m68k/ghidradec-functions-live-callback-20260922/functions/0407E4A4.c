
undefined4 sub_407E4A4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined auStack_a6 [2];
  int iStack_a4;
  undefined uStack_9f;
  undefined uStack_9e;
  undefined4 uStack_9a;
  undefined4 uStack_96;
  undefined4 uStack_92;
  undefined4 uStack_8e;
  
  iVar1 = sub_407E572(param_1,*(undefined4 *)(param_1 + 0xca),0);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
    sub_407CA92(param_1);
    uVar2 = 5;
    uVar5 = *(uint *)(*(int *)(param_1 + 0xca) + 4);
    uVar5 = (uVar5 + 0x1c47) / uVar5;
    iVar4 = 0;
    iVar1 = 0;
    do {
      _bzero(auStack_a6,0x52);
      auStack_a6[0] = 0x2a;
      uStack_9f = (undefined)(uVar5 >> 8);
      uStack_9e = (undefined)uVar5;
      uStack_96 = *(undefined4 *)(param_1 + 0xd2);
      uStack_92 = 0x1c48;
      uStack_9a = 1;
      uStack_8e = 0x3c;
      *(int *)(*(int *)(param_1 + 0xd2) + 4) = iVar1;
      iStack_a4 = iVar1;
      iVar3 = sub_407E678(param_1,auStack_a6,0);
      if (iVar3 == 0) {
        uVar2 = 0;
      }
      iVar1 = uVar5 + iVar1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}

