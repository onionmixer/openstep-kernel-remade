
void uni_2(void)

{
  undefined4 *puVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 in_A0;
  undefined4 in_A1;
  int unaff_A6;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  unkbyte10 in_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  byte in_stack_00000000;
  undefined4 uVar2;
  
  *(undefined4 *)(unaff_A6 + -0xc0) = in_D0;
  *(undefined4 *)(unaff_A6 + -0xbc) = in_D1;
  *(undefined4 *)(unaff_A6 + -0xb8) = in_A0;
  *(undefined4 *)(unaff_A6 + -0xb4) = in_A1;
  *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
  *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
  *(unkbyte10 *)(unaff_A6 + -0x98) = unaff_FP2;
  *(unkbyte10 *)(unaff_A6 + -0x8c) = unaff_FP3;
  puVar1 = *(undefined4 **)(unaff_A6 + -0x80);
  *puVar1 = in_FPCR;
  puVar1[3] = in_FPSR;
  puVar1[6] = in_FPIAR;
  if ((in_stack_00000000 & 0xf0) == 0x40) {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) & 0xff;
    *(undefined *)(unaff_A6 + -0x47) = 0;
    get_op();
    *(undefined *)(unaff_A6 + -0x4c) = 0;
    uVar2 = 0x40a547a;
    do_func();
    saveFPUStateFrame(uVar2);
    if (*(char *)(unaff_A6 + -0x4c) == '\0') {
      sto_res(uVar2);
    }
    gen_except();
    return;
  }
  return;
}

