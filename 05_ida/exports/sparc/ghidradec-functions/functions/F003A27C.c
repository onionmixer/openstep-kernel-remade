
/* WARNING: Removing unreachable block (ram,0xf003a320) */
/* WARNING: Removing unreachable block (ram,0xf003a2d0) */
/* WARNING: Removing unreachable block (ram,0xf003a304) */
/* WARNING: Removing unreachable block (ram,0xf003a330) */
/* WARNING: Removing unreachable block (ram,0xf003a344) */

undefined8 _makefh(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  word *pwVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = param_2;
  (**(code **)(*(int *)(param_2 + 0x1c) + 100))
            (param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    pwVar3 = *(word **)((int)register0x00000038 + -0xc);
    if (pwVar3 == (word *)0x0) {
      uVar4 = 0x47;
    }
    else if ((uint)*pwVar3 + (uint)**(word **)(param_3 + 0x28) + 8 < 0x21) {
      _bzero(param_1,0x20);
      *param_1 = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x14);
      puVar2 = *(undefined2 **)((int)register0x00000038 + -0xc);
      param_1[1] = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x18);
      *(undefined2 *)(param_1 + 2) = *puVar2;
      _bcopy(puVar2 + 1,(int)param_1 + 10,*puVar2);
      *(undefined2 *)(param_1 + 5) = **(undefined2 **)(param_3 + 0x28);
      _bcopy(*(int *)(param_3 + 0x28) + 2,(int)param_1 + 0x16);
      _kfree(*(word **)((int)register0x00000038 + -0xc),
             **(word **)((int)register0x00000038 + -0xc) + 2);
      uVar4 = 0;
    }
    else {
      _kfree(pwVar3,*pwVar3 + 2);
      uVar4 = 0x47;
    }
  }
  else {
    uVar4 = 0x47;
  }
  return CONCAT44(param_2,uVar4);
}
