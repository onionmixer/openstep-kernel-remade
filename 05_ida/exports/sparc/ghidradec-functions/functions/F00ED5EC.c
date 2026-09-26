
/* WARNING: Removing unreachable block (ram,0xf00ed604) */

undefined8 _NXHashMember(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1[4];
  (**(code **)*param_1)(iVar1,param_2);
  .urem();
  iVar2 = *(int *)(iVar1 * 8 + param_1[3]);
  iVar1 = iVar1 * 8 + param_1[3];
  if (iVar2 == 0) {
loc_F00ED6B0:
    uVar4 = 0;
  }
  else if (iVar2 == 1) {
    if (param_2 != *(int *)(iVar1 + 4)) {
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      uVar4 = 0;
      if (iVar1 == 0) goto locret_F00ED6B4;
    }
    uVar4 = 1;
  }
  else {
    piVar3 = *(int **)(iVar1 + 4);
    do {
      iVar2 = iVar2 + -1;
      if (iVar2 == -1) goto loc_F00ED6B0;
      if (param_2 == *piVar3) {
        uVar4 = 1;
        goto locret_F00ED6B4;
      }
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      piVar3 = piVar3 + 1;
    } while (iVar1 == 0);
    uVar4 = 1;
  }
locret_F00ED6B4:
  return CONCAT44(param_2,uVar4);
}
