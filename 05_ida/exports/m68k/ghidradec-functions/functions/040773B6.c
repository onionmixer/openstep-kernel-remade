
undefined4 _od_remap(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint unaff_D4;
  int unaff_D5;
  int iVar6;
  
  piVar1 = *(int **)(param_3 + 0xae);
  iVar5 = 0;
  if ((*piVar1 == 0x4e655854) || (*piVar1 == 0x646c5632)) {
    iVar6 = (int)piVar1 + 0x22e;
  }
  else {
    iVar6 = *(int *)(param_3 + 0xb2);
  }
  if (*piVar1 == 0x4e655854) {
    iVar5 = (int)*(char *)(param_1 + 0x264) % (piVar1[0x19] >> 1);
  }
  iVar3 = _od_locate_alt(param_1,param_2,param_3,0,param_4);
  if (iVar3 == -1) {
    *(undefined *)(param_1 + 599) = 0x37;
    uVar4 = 0;
  }
  else {
    *(int *)(iVar6 + iVar3 * 4) = (param_4 - *(int *)(param_3 + 0xbe)) - iVar5;
    if (*piVar1 != 0x4e655854) {
      uVar2 = param_4 - *(int *)(param_3 + 0xbe);
      unaff_D5 = (int)uVar2 >> 4;
      unaff_D4 = (uVar2 & 0xf) * 2;
    }
    uVar2 = *(uint *)(*(int *)(param_3 + 0xc6) + unaff_D5 * 4);
    *(word *)(param_3 + 0xd8) = *(word *)(param_3 + 0xd8) | 0x1000;
    if (_od_update_time == 0) {
      _od_update_time = 1;
    }
    *(uint *)(*(int *)(param_3 + 0xc6) + unaff_D5 * 4) =
         1 << (unaff_D4 & 0x3f) | ~(3 << (unaff_D4 & 0x3f)) & uVar2;
    uVar4 = 1;
  }
  return uVar4;
}
