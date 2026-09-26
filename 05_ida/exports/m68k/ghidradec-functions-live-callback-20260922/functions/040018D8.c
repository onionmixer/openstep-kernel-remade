
/* WARNING: Control flow encountered unimplemented instructions */

void __switch_context(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  undefined4 unaff_A6;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  unkbyte10 in_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  unkbyte10 unaff_FP4;
  unkbyte10 unaff_FP5;
  unkbyte10 unaff_FP6;
  unkbyte10 unaff_FP7;
  undefined4 in_stack_00000000;
  
  *(byte *)(param_1 + 0x15) = *(byte *)(param_1 + 0x15) & 0xbf;
  saveFPUStateFrame(param_1[0x17]);
  if (*(char *)(param_1 + 0x17) != '\0') {
    *(byte *)(param_1 + 0x15) = *(byte *)(param_1 + 0x15) | 0x40;
    puVar1 = (undefined4 *)param_1[0x65];
    *puVar1 = in_FPCR;
    puVar1[3] = in_FPSR;
    puVar1[6] = in_FPIAR;
    *(unkbyte10 *)(param_1 + 0x4d) = in_FP0;
    *(unkbyte10 *)(param_1 + 0x50) = in_FP1;
    *(unkbyte10 *)(param_1 + 0x53) = unaff_FP2;
    *(unkbyte10 *)(param_1 + 0x56) = unaff_FP3;
    *(unkbyte10 *)(param_1 + 0x59) = unaff_FP4;
    *(unkbyte10 *)(param_1 + 0x5c) = unaff_FP5;
    *(unkbyte10 *)(param_1 + 0x5f) = unaff_FP6;
    *(unkbyte10 *)(param_1 + 0x62) = unaff_FP7;
    restoreFPUStateFrame(0);
  }
  *param_1 = in_D0;
  param_1[1] = in_D1;
  param_1[2] = unaff_D2;
  param_1[3] = unaff_D3;
  param_1[4] = unaff_D4;
  param_1[5] = unaff_D5;
  param_1[6] = unaff_D6;
  param_1[7] = unaff_D7;
  param_1[8] = param_1;
  param_1[9] = in_stack_00000000;
  param_1[10] = unaff_A2;
  param_1[0xb] = unaff_A3;
  param_1[0xc] = unaff_A4;
  param_1[0xd] = unaff_A5;
  param_1[0xe] = unaff_A6;
  param_1[0xf] = &param_1;
  restoreFPUStateFrame(param_2[0x17]);
  if (_cpu_type != '\0') {
    *param_2 = param_3;
                    /* WARNING: Could not recover jumptable at 0x0400197a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)param_2[9])();
    return;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}

