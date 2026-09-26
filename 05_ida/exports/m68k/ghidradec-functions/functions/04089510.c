
int sub_4089510(int param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3c) = 0xc;
  iVar3 = sub_40889C2(param_1,*(undefined4 *)(param_1 + 0xc),param_3);
  if (iVar3 == 0) {
    puVar1 = *(undefined **)(param_1 + 0xc);
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = puVar1[2] & 0x7f;
    puVar1[3] = 8;
    puVar2 = (uint *)(*(int *)(param_1 + 0xc) + 9);
    *puVar2 = *puVar2 & 0xff | param_2 << 8;
    puVar2 = (uint *)(*(int *)(param_1 + 0xc) + 4);
    *puVar2 = *puVar2 & 0xff000000;
    iVar3 = sub_4088958(param_1,*(undefined4 *)(param_1 + 0xc),param_3);
    if (iVar3 == 0) {
      if (param_2 == 0) {
        *(word *)(param_1 + 0x66) = *(word *)(param_1 + 0x66) & 0xfffb;
      }
      else {
        *(word *)(param_1 + 0x66) = *(word *)(param_1 + 0x66) | 4;
        *(int *)(param_1 + 0x70) = param_2;
      }
      iVar3 = 0;
    }
  }
  return iVar3;
}
