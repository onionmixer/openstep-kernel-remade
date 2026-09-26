
undefined8 _save_fpu_context(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined8 *puVar1;
  undefined4 unaff_l3;
  int iVar2;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  undefined8 in_fd0;
  undefined8 in_fd2;
  undefined8 in_fd4;
  undefined8 in_fd6;
  undefined8 in_fd8;
  undefined8 in_fd10;
  undefined8 in_fd12;
  undefined8 in_fd14;
  undefined8 in_fd16;
  undefined8 in_fd18;
  undefined8 in_fd20;
  undefined8 in_fd22;
  undefined8 in_fd24;
  undefined8 in_fd26;
  undefined8 in_fd28;
  undefined8 in_fd30;
  undefined4 in_fsr;
  bool in_DECOMPILE_MODE;
  int in_TL;
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
  iVar2 = *(int *)(param_1 + 0x28);
  if ((*(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                 (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0x1000) != 0) {
    puVar1 = *(undefined8 **)(iVar2 + 0x284);
    *(undefined4 *)(puVar1 + 0x10) = in_fsr;
    *puVar1 = in_fd0;
    puVar1[1] = in_fd2;
    puVar1[2] = in_fd4;
    puVar1[3] = in_fd6;
    puVar1[4] = in_fd8;
    puVar1[5] = in_fd10;
    puVar1[6] = in_fd12;
    puVar1[7] = in_fd14;
    puVar1[8] = in_fd16;
    puVar1[9] = in_fd18;
    puVar1[10] = in_fd20;
    puVar1[0xb] = in_fd22;
    puVar1[0xc] = in_fd24;
    puVar1[0xd] = in_fd26;
    puVar1[0xe] = in_fd28;
    puVar1[0xf] = in_fd30;
    *(uint *)(iVar2 + 0x234) = *(uint *)(iVar2 + 0x234) & 0xffffefff;
  }
  return CONCAT44(param_2,param_1);
}

