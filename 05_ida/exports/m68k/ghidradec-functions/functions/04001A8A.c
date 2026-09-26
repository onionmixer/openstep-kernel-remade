
/* WARNING: Control flow encountered unimplemented instructions */

undefined4 __stack_handoff(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
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
  
  *(byte *)(param_1 + 0x54) = *(byte *)(param_1 + 0x54) & 0xbf;
  saveFPUStateFrame(*(undefined4 *)(param_1 + 0x5c));
  if (*(char *)(param_1 + 0x5c) != '\0') {
    *(byte *)(param_1 + 0x54) = *(byte *)(param_1 + 0x54) | 0x40;
    puVar1 = *(undefined4 **)(param_1 + 0x194);
    *puVar1 = in_FPCR;
    puVar1[3] = in_FPSR;
    puVar1[6] = in_FPIAR;
    *(unkbyte10 *)(param_1 + 0x134) = in_FP0;
    *(unkbyte10 *)(param_1 + 0x140) = in_FP1;
    *(unkbyte10 *)(param_1 + 0x14c) = unaff_FP2;
    *(unkbyte10 *)(param_1 + 0x158) = unaff_FP3;
    *(unkbyte10 *)(param_1 + 0x164) = unaff_FP4;
    *(unkbyte10 *)(param_1 + 0x170) = unaff_FP5;
    *(unkbyte10 *)(param_1 + 0x17c) = unaff_FP6;
    *(unkbyte10 *)(param_1 + 0x188) = unaff_FP7;
    restoreFPUStateFrame(0);
  }
  restoreFPUStateFrame(*(undefined4 *)(param_2 + 0x5c));
  if (_cpu_type != '\0') {
    uVar2 = *(undefined4 *)(param_2 + 0x58);
    if (_cpu_type == '\0') {
      uVar2 = _cache;
    }
    return uVar2;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
