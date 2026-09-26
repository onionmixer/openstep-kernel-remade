
undefined8 _vafsidtovfs(int param_1,int *param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
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
  undefined auStackX_0 [92];
  
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
  if (_rootvfs == (int *)0x0) {
    piVar3 = (int *)0x16;
  }
  else {
    iVar1 = _rootvfs[1];
    piVar2 = _rootvfs;
    while (piVar3 = piVar2,
          (**(code **)(iVar1 + 8))(piVar2,(undefined *)((int)register0x00000038 + -0x4c)),
          piVar3 == (int *)0x0) {
      piVar3 = *(int **)((int)register0x00000038 + -0x4c);
      (**(code **)(piVar3[7] + 0x14))
                (piVar3,(undefined *)((int)register0x00000038 + -0x48),
                 *(undefined4 *)(_active_u + 0x1c));
      if (piVar3 != (int *)0x0) break;
      if (param_1 == *(int *)((int)register0x00000038 + -0x3c)) {
        *param_2 = (int)piVar2;
        piVar3 = (int *)0x0;
        break;
      }
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0) {
        piVar3 = (int *)0x16;
        break;
      }
      iVar1 = piVar2[1];
    }
  }
  return CONCAT44(param_2,piVar3);
}
