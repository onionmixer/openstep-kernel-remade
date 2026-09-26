
void fpsp_snan(void)

{
  char cVar1;
  undefined4 *puVar2;
  sword sVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  byte bStack_e8;
  char acStack_cc [4];
  undefined4 auStack_c8 [11];
  undefined4 uStack_84;
  byte bStack_7e;
  undefined4 uStack_80;
  
  saveFPUStateFrame(auStack_c8[0]);
  *uStack_84 = in_FPCR;
  uStack_84[3] = in_FPSR;
  uStack_84[6] = in_FPIAR;
  if (((uint)uStack_84 & 0x4000) != 0) {
    if ((bStack_e8 & 0x20) != 0) {
      sub_40A4EEC();
    }
    cVar1 = auStack_c8[0]._0_1_;
    if (auStack_c8[0]._0_1_ == '@') {
      sVar3 = 0xd;
    }
    else {
      sVar3 = 0xb;
    }
    auStack_c8[0] = 0;
    puVar2 = auStack_c8;
    do {
      puVar4 = (undefined *)puVar2;
      *(undefined4 *)(puVar4 + -4) = 0;
      sVar3 = sVar3 + -1;
      puVar2 = (undefined4 *)(puVar4 + -4);
    } while (sVar3 != -1);
    puVar4[-4] = cVar1;
    puVar4[-3] = 0x60;
    restoreFPUStateFrame(*(undefined4 *)(puVar4 + -4));
    real_snan();
    return;
  }
  sub_40A4EEC();
  if ((bStack_7e & uStack_84._2_1_ & 3) == 0) {
    cVar1 = auStack_c8[0]._0_1_;
    if (auStack_c8[0]._0_1_ == '@') {
      sVar3 = 0xd;
    }
    else {
      sVar3 = 0xb;
    }
    auStack_c8[0] = 0;
    puVar2 = auStack_c8;
    do {
      puVar5 = (undefined *)puVar2;
      *(undefined4 *)(puVar5 + -4) = 0;
      sVar3 = sVar3 + -1;
      puVar2 = (undefined4 *)(puVar5 + -4);
    } while (sVar3 != -1);
    puVar5[-4] = cVar1;
    puVar5[-3] = 0x60;
    restoreFPUStateFrame(*(undefined4 *)(puVar5 + -4));
    fpsp_done();
    return;
  }
  restoreFPUStateFrame(auStack_c8[0]);
  real_inex();
  return;
}
