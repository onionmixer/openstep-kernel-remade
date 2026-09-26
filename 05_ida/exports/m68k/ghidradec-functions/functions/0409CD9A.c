
void t_avoid_unsupp(void)

{
  uint uVar1;
  byte *extraout_A0;
  byte *extraout_A0_00;
  byte bStack_ec;
  byte bStack_e4;
  byte bStack_e0;
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  if (uStack_c8._1_1_ == '\0') {
    return;
  }
  if ((bStack_e0 & 4) != 0) {
    if ((bStack_e4 & 0x80) != 0) {
      nrm_set();
      *extraout_A0 = *extraout_A0 & 0x7f;
      uVar1 = *(uint *)(extraout_A0 + 2) >> 0x18;
      *(uint *)(extraout_A0 + 2) = uVar1;
      if (uVar1 != 0) {
        *extraout_A0 = *extraout_A0 | 0x80;
      }
      if ((bStack_ec & 0x80) == 0) goto loc_409CE42;
    }
    nrm_set();
    *extraout_A0_00 = *extraout_A0_00 & 0x7f;
    uVar1 = *(uint *)(extraout_A0_00 + 2) >> 0x18;
    *(uint *)(extraout_A0_00 + 2) = uVar1;
    if (uVar1 != 0) {
      *extraout_A0_00 = *extraout_A0_00 | 0x80;
    }
  }
loc_409CE42:
  restoreFPUStateFrame(uStack_c8);
  return;
}
