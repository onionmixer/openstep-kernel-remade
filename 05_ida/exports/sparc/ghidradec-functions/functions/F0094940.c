
/* WARNING: Removing unreachable block (ram,0xf0094948) */

sqword _save_context(int param_1,uint param_2)

{
  undefined4 in_o7;
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined8 *puVar2;
  undefined4 unaff_l3;
  undefined4 *puVar3;
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
  undefined4 uVar4;
  undefined4 extraout_fs1;
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
  uVar1 = *(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                    (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c);
  uVar4 = _flush_windows();
  puVar3 = *(undefined4 **)(param_1 + 0x28);
  puVar3[2] = uVar1;
  *puVar3 = in_o7;
  puVar3[1] = register0x00000038;
  if ((uVar1 & 0x1000) != 0) {
    puVar2 = (undefined8 *)puVar3[0xa1];
    *(undefined4 *)(puVar2 + 0x10) = in_fsr;
    *puVar2 = CONCAT44(uVar4,extraout_fs1);
    puVar2[1] = in_fd2;
    puVar2[2] = in_fd4;
    puVar2[3] = in_fd6;
    puVar2[4] = in_fd8;
    puVar2[5] = in_fd10;
    puVar2[6] = in_fd12;
    puVar2[7] = in_fd14;
    puVar2[8] = in_fd16;
    puVar2[9] = in_fd18;
    puVar2[10] = in_fd20;
    puVar2[0xb] = in_fd22;
    puVar2[0xc] = in_fd24;
    puVar2[0xd] = in_fd26;
    puVar2[0xe] = in_fd28;
    puVar2[0xf] = in_fd30;
    puVar3[0x8d] = puVar3[0x8d] & 0xffffefff;
  }
  return (qword)param_2 << 0x20;
}
