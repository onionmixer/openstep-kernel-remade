
void fpsp_fline(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 in_A0;
  undefined4 in_A1;
  undefined4 unaff_A6;
  undefined2 *puVar2;
  byte *pbVar3;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  unkbyte10 in_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  undefined2 in_stack_00000000;
  undefined2 in_stack_00000002;
  byte local_fc [16];
  undefined2 local_ec;
  undefined4 local_e4;
  undefined4 uStack_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  int local_5c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  if (param_1._2_2_ == 0x202c) {
    puVar2 = &local_4;
    local_4 = (undefined2)((uint)unaff_A6 >> 0x10);
    uStack_2 = (undefined2)unaff_A6;
    pbVar3 = (byte *)&local_c8;
    saveFPUStateFrame(local_c8);
    local_c8 = in_D0;
  }
  else {
    saveFPUStateFrame(local_cc);
    uStack_d0 = 0x40a4820;
    local_c8 = in_D0;
    uStack_c4 = in_D1;
    uStack_c0 = in_A0;
    uStack_bc = in_A1;
    in_FP0 = mem_read();
    puVar2 = (undefined2 *)&stack0xfffffff8;
    if (((byte)((uint)(local_5c << 4) >> 0x1d) != 1) ||
       ((byte)((byte)((uint)local_5c >> 8) >> 2) != 0x17)) {
      restoreFPUStateFrame(local_cc);
      real_fline();
      return;
    }
    if (local_cc._0_1_ == '@') {
      pbVar3 = local_fc + 8;
      local_fc[8] = 0x40;
      local_fc[9] = 0x28;
      local_fc[10] = 0;
      local_fc[0xb] = 0;
    }
    else {
      if (local_cc._0_1_ != 'A') goto fpsp_fmt_error;
      pbVar3 = local_fc;
      local_fc[0] = 0x41;
      local_fc[1] = 0x30;
      local_fc[2] = 0;
      local_fc[3] = 0;
    }
    in_FPIAR = CONCAT22(in_stack_00000002,param_1._0_2_);
    uStack_2 = (undefined2)((uint)(CONCAT22(in_stack_00000002,param_1._0_2_) + 4) >> 0x10);
    local_ec = (short)local_5c;
    local_e4 = 0x200000;
    in_D1 = uStack_c4;
    in_A0 = uStack_c0;
    in_A1 = uStack_bc;
    local_4 = in_stack_00000000;
  }
  *(undefined4 *)((int)puVar2 + -0xc0) = local_c8;
  *(undefined4 *)((int)puVar2 + -0xbc) = in_D1;
  *(undefined4 *)((int)puVar2 + -0xb8) = in_A0;
  *(undefined4 *)((int)puVar2 + -0xb4) = in_A1;
  *(unkbyte10 *)((int)puVar2 + -0xb0) = in_FP0;
  *(unkbyte10 *)((int)puVar2 + -0xa4) = in_FP1;
  *(unkbyte10 *)((int)puVar2 + -0x98) = unaff_FP2;
  *(unkbyte10 *)((int)puVar2 + -0x8c) = unaff_FP3;
  puVar1 = *(undefined4 **)((int)puVar2 + -0x80);
  *puVar1 = in_FPCR;
  puVar1[3] = in_FPSR;
  puVar1[6] = in_FPIAR;
  if ((*pbVar3 & 0xf0) == 0x40) {
    *(uint *)((int)puVar2 + -0x7c) = *(uint *)((int)puVar2 + -0x7c) & 0xff;
    *(undefined1 *)((int)puVar2 + -0x47) = 0;
    pbVar3[-0xffffffff00000004] = 4;
    pbVar3[-0xffffffff00000003] = 10;
    pbVar3[-0xffffffff00000002] = 0x54;
    pbVar3[-0xffffffff00000001] = 0x70;
    get_op();
    *(undefined1 *)((int)puVar2 + -0x4c) = 0;
    pbVar3[-0xffffffff00000004] = 4;
    pbVar3[-0xffffffff00000003] = 10;
    pbVar3[-0xffffffff00000002] = 0x54;
    pbVar3[-0xffffffff00000001] = 0x7a;
    do_func();
    saveFPUStateFrame(*(undefined4 *)(pbVar3 + -4));
    if (*(char *)((int)puVar2 + -0x4c) == '\0') {
      pbVar3[-0xffffffff00000008] = 4;
      pbVar3[-0xffffffff00000007] = 10;
      pbVar3[-0xffffffff00000006] = 0x54;
      pbVar3[-0xffffffff00000005] = 0x8c;
      sto_res();
    }
    gen_except();
    return;
  }
fpsp_fmt_error:
  fpsp_frame_err();
  return;
}

