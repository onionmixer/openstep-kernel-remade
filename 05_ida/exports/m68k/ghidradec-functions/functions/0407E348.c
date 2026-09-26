
uint sub_407E348(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined auStack_a6 [2];
  int iStack_a4;
  undefined uStack_9f;
  undefined uStack_9e;
  undefined4 uStack_9a;
  undefined4 uStack_96;
  undefined4 uStack_92;
  undefined4 uStack_8e;
  uint uStack_8a;
  
  iVar2 = *param_1;
  uVar1 = sub_407E572(param_1,*(undefined4 *)((int)param_1 + 0xca),param_2);
  if (uVar1 == 0) {
    if (*(int *)(*(int *)((int)param_1 + 0xca) + 4) == 0) {
      _printf(aErrorInvalidDe);
      if ((**(byte **)(iVar2 + 0xb2) & 0x1f) == 5) {
        *(undefined4 *)(*(int *)((int)param_1 + 0xca) + 4) = 0x800;
      }
      else {
        *(undefined4 *)(*(int *)((int)param_1 + 0xca) + 4) = 0x200;
      }
    }
    uVar4 = *(uint *)(*(int *)((int)param_1 + 0xca) + 4);
    uVar4 = (uVar4 + 0x1c47) / uVar4;
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) & 0xfbff;
    *(uint *)(*param_1 + 0xc) = *(uint *)(*param_1 + 0xc) | 8;
    *(undefined *)(*param_1 + 0x15) = 2;
    iVar3 = 0;
    iVar2 = 0;
    do {
      _bzero(*(undefined4 *)((int)param_1 + 0xd2),0x1c48);
      _bzero(auStack_a6,0x52);
      auStack_a6[0] = 0x28;
      uStack_9f = (undefined)(uVar4 >> 8);
      uStack_9e = (undefined)uVar4;
      uStack_96 = *(undefined4 *)((int)param_1 + 0xd2);
      uStack_92 = 0x1c48;
      uStack_9a = 0;
      uStack_8e = 0x3c;
      iStack_a4 = iVar2;
      uVar1 = sub_407E678(param_1,auStack_a6,param_2);
      uVar1 = uStack_8a | uVar1;
      if (uVar1 == 0) {
        *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x400;
        uVar1 = _sdchecklabel(*(undefined4 *)((int)param_1 + 0xd2),iStack_a4);
        if (uVar1 != 0) {
          param_1[2] = param_1[2] | 4;
          break;
        }
      }
      iVar2 = uVar4 + iVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    *(uint *)(*param_1 + 0xc) = *(uint *)(*param_1 + 0xc) & 0xfffffff7;
    *(undefined *)(*param_1 + 0x15) = 10;
  }
  else {
    *(undefined4 *)(*(int *)((int)param_1 + 0xca) + 4) = 0x200;
    param_1[2] = param_1[2] & 0xfffffffb;
  }
  return uVar1;
}
