
void fpsp_operr(void)

{
  byte bVar2;
  int iVar1;
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  byte bStack_ec;
  int iStack_e8;
  uint uStack_e0;
  word wStack_dc;
  int iStack_d8;
  uint uStack_d4;
  undefined4 uStack_c8;
  undefined4 uStack_84;
  byte bStack_7e;
  undefined4 uStack_80;
  
  saveFPUStateFrame(uStack_c8);
  *uStack_84 = in_FPCR;
  uStack_84[3] = in_FPSR;
  uStack_84[6] = in_FPIAR;
  if ((uStack_e0 & 0x100000) == 0) {
loc_40A491C:
    restoreFPUStateFrame(uStack_c8);
    real_operr();
    return;
  }
  bVar2 = (byte)((uint)(iStack_e8 << 3) >> 0x1d);
  if (bVar2 != 0) {
    if (bVar2 == 4) {
      if ((bStack_ec & 0xe0) == 0x60) goto loc_40A4AD2;
      if ((uStack_d4 == 0xffff8000) && (iVar1 = sub_40A4B96(), iVar1 == 0)) {
        sub_40A4B34();
        goto loc_40A4BEC;
      }
      if ((wStack_dc & 0x7fff) == 0x3ffe) {
        sub_40A4B34();
        goto loc_40A4BEC;
      }
    }
    else {
      if (bVar2 != 6) goto loc_40A491C;
      if ((bStack_ec & 0xe0) == 0x60) goto loc_40A4AD2;
      if ((uStack_d4 == 0xffffff80) && (iVar1 = sub_40A4B96(), iVar1 == 0)) {
        sub_40A4B34();
        goto loc_40A4BEC;
      }
      if ((wStack_dc & 0x7fff) == 0x3ffe) {
        sub_40A4B34();
        goto loc_40A4BEC;
      }
    }
    goto loc_40A4AEA;
  }
  if ((bStack_ec & 0xe0) == 0x60) {
loc_40A4AD2:
    sub_40A4B34();
loc_40A4BC4:
    if (((uint)uStack_84 & 0x2000) != 0) {
      restoreFPUStateFrame(uStack_c8);
      real_operr();
      return;
    }
  }
  else {
    if ((uStack_d4 == 0x80000000) && (iVar1 = sub_40A4B96(), iVar1 == 0)) {
      sub_40A4B34();
      goto loc_40A4BEC;
    }
    if ((wStack_dc & 0x7fff) != 0x3ffe) {
      if ((0x4000 < (wStack_dc & 0x7fff)) || ((wStack_dc & 0x7fff) == 0x4000)) goto loc_40A4AEA;
      if ((uStack_d4 & 0x7fff0000) != 0x7fff0000) {
        if ((int)uStack_d4 < 0) {
          if (iStack_d8 != -1) {
loc_40A4AEA:
            bStack_7e = bStack_7e & 0xfd;
            if ((sword)wStack_dc < 0) {
              sub_40A4B34();
            }
            else {
              sub_40A4B34();
            }
            goto loc_40A4BC4;
          }
        }
        else if (iStack_d8 != 0) goto loc_40A4AEA;
      }
    }
    sub_40A4B34();
  }
loc_40A4BEC:
  if ((bStack_7e & uStack_84._2_1_ & 3) == 0) {
    fpsp_done();
    return;
  }
  restoreFPUStateFrame(uStack_c8);
  real_inex();
  return;
}
