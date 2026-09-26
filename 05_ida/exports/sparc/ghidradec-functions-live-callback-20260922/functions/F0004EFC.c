
undefined8
_flush_user_windows(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 in_o7;
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
  undefined4 uVar5;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined *unaff_fp;
  undefined4 unaff_i7;
  undefined in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar2 = 0;
  puVar1 = (undefined *)register0x00000038;
  if (*(int *)(*_active_pcb + 0xc) != 0) {
    do {
      puVar3 = puVar1;
      puVar1 = puVar3 + -0x40;
      if (!(bool)in_DECOMPILE_MODE) {
        *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
        *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
        *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
        *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
        *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
        *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
        *(undefined **)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
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
      unaff_l0 = 0;
      unaff_l1 = 0;
      unaff_l3 = 0;
      unaff_l4 = 0;
      unaff_l5 = 0;
      unaff_l6 = 0;
      unaff_l7 = 0;
      in_CWP = in_CWP + 1;
      iVar2 = iVar2 + 1;
      uVar4 = param_1;
      unaff_i0 = param_1;
      uVar5 = param_2;
      unaff_i1 = param_2;
      unaff_i2 = param_3;
      unaff_i3 = param_4;
      unaff_i4 = param_5;
      unaff_i5 = param_6;
      unaff_fp = puVar3;
      unaff_i7 = in_o7;
    } while (*(int *)(*_active_pcb + 0xc) != 0);
    do {
      param_2 = uVar5;
      param_1 = uVar4;
      iVar2 = iVar2 + -1;
      in_CWP = in_CWP + -1;
      uVar4 = param_1;
      uVar5 = param_2;
      if (!(bool)in_DECOMPILE_MODE) {
        uVar4 = *(undefined4 *)(in_CWP * 0x40 + 0x8000);
        uVar5 = *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000);
      }
    } while (iVar2 != 0);
  }
  return CONCAT44(param_2,param_1);
}

