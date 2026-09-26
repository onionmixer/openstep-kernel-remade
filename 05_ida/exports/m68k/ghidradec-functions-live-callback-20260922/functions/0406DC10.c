
undefined4 sub_406DC10(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined auStack_e [4];
  byte bStack_a;
  
  uVar1 = *(uint *)(param_1 + 0x186);
  iVar2 = *(int *)(param_1 + 0x140);
  sub_406E234(param_1,*(undefined4 *)(param_1 + 0x13c),auStack_e);
  if (*(int *)(param_1 + 0x18c) + 1U < (uint)bStack_a + (uVar1 + iVar2 + -1) / uVar1) {
    uVar4 = uVar1 * ((*(int *)(param_1 + 0x18c) - (uint)bStack_a) + 1);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x140);
  }
  uVar3 = *(undefined4 *)(param_1 + 0x144);
  *(undefined4 *)(param_1 + 0x164) = 0;
  if ((uVar4 & uVar1 - 1) != 0) {
    _printf(aFdDPartialSect,*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x13c);
  *(uint *)(param_1 + 0x14c) = uVar4;
  *(undefined4 *)(param_1 + 0x150) = uVar3;
  sub_406DCC0(param_1,param_1 + 0x60,*(undefined4 *)(param_1 + 0x148),
              *(undefined4 *)(param_1 + 0x14c),uVar3,*(uint *)(param_1 + 0x15c) & 1);
  return 0;
}

