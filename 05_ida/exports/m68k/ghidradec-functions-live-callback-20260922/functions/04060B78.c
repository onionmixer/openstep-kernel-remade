
void sub_4060B78(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  _lock_read(param_1);
  for (iVar5 = *(int *)(param_1 + 0xc); param_1 + 8 != iVar5; iVar5 = *(int *)(iVar5 + 4)) {
    if ((*(byte *)(iVar5 + 0x18) & 0xa0) == 0) {
      uVar1 = *(uint *)(iVar5 + 8);
      if ((uVar1 <= param_3) && (uVar2 = *(uint *)(iVar5 + 0xc), param_2 < uVar2)) {
        if (param_2 < uVar1) {
          param_2 = uVar1;
        }
        uVar4 = param_3;
        if (uVar2 < param_3) {
          uVar4 = uVar2;
        }
        iVar3 = (param_2 + *(int *)(iVar5 + 0x14)) - uVar1;
        sub_4060AF6(*(undefined4 *)(iVar5 + 0x10),iVar3,(iVar3 + uVar4) - param_2,param_4);
      }
    }
    else {
      sub_4060B78(*(undefined4 *)(iVar5 + 0x10),param_2,param_3,param_4);
    }
  }
  _lock_done(param_1);
  return;
}

