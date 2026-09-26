
/* WARNING: Removing unreachable block (ram,0xf00ed6d8) */

undefined8 _NXHashGet(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
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
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      if (param_2 == *(int *)(iVar1 + 4)) {
        iVar1 = *(int *)(iVar1 + 4);
      }
      else {
        iVar2 = param_1[4];
        (**(code **)(*param_1 + 4))(iVar2,param_2);
        if (iVar2 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(iVar1 + 4);
        }
      }
      goto locret_F00ED784;
    }
    piVar3 = *(int **)(iVar1 + 4);
    while (iVar2 = iVar2 + -1, iVar2 != -1) {
      if (param_2 == *piVar3) {
        iVar1 = *piVar3;
        goto locret_F00ED784;
      }
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 != 0) {
        iVar1 = *piVar3;
        goto locret_F00ED784;
      }
      piVar3 = piVar3 + 1;
    }
  }
  iVar1 = 0;
locret_F00ED784:
  return CONCAT44(param_2,iVar1);
}
