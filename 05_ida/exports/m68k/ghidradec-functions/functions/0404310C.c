
void sub_404310C(uint param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5,int *param_6
                ,undefined4 *param_7)

{
  int iVar1;
  uint uVar2;
  
  while (*(uint *)(param_2 + 0x10) != param_1) {
    if (param_1 < *(uint *)(param_2 + 0x10)) {
      iVar1 = *(int *)(param_2 + 0x18);
      if (iVar1 == 0) break;
      uVar2 = *(uint *)(iVar1 + 0x10);
      if ((param_1 < uVar2) && (*(int *)(iVar1 + 0x18) != 0)) {
        *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar1 + 0x1c);
        *(int *)(iVar1 + 0x1c) = param_2;
        param_2 = iVar1;
      }
      *param_6 = param_2;
      param_6 = (int *)(param_2 + 0x18);
      param_2 = *param_6;
      if ((uVar2 < param_1) && (*(int *)(iVar1 + 0x1c) != 0)) {
        *param_4 = param_2;
        param_4 = (int *)(param_2 + 0x1c);
        param_2 = *param_4;
      }
    }
    else {
      iVar1 = *(int *)(param_2 + 0x1c);
      if (iVar1 == 0) break;
      uVar2 = *(uint *)(iVar1 + 0x10);
      if ((uVar2 < param_1) && (*(int *)(iVar1 + 0x1c) != 0)) {
        *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar1 + 0x18);
        *(int *)(iVar1 + 0x18) = param_2;
        param_2 = iVar1;
      }
      *param_4 = param_2;
      param_4 = (int *)(param_2 + 0x1c);
      param_2 = *param_4;
      if ((param_1 < uVar2) && (*(int *)(iVar1 + 0x18) != 0)) {
        *param_6 = param_2;
        param_6 = (int *)(param_2 + 0x18);
        param_2 = *param_6;
      }
    }
  }
  *param_3 = param_2;
  *param_5 = param_4;
  *param_7 = param_6;
  return;
}
