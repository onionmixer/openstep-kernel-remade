/* GHIDRADEC_FUNCTION index=2775 start=0x40a4712 */

void reg_dest(void)

{
  int in_D1;
  
                    /* WARNING: Could not recover jumptable at 0x040a471c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&loc_40A46B2 + in_D1 * 4))();
  return;
}
/* GHIDRADEC_FUNCTION index=2776 start=0x40a47ba */

void fpsp_bsun(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  undefined4 uStack_c8;
  undefined4 *puStack_84;
  
  saveFPUStateFrame(uStack_c8);
  *puStack_84 = in_FPCR;
  puStack_84[3] = in_FPSR;
  puStack_84[6] = in_FPIAR;
  restoreFPUStateFrame(uStack_c8);
  real_bsun();
  return;
}
/* GHIDRADEC_FUNCTION index=2777 start=0x40a47f4 */

//Decompiler native message:  Low-level Error: Overlapping input varnodes
//Decompiling function: fpsp_fline @ 0x40a47f4
/* GHIDRADEC_FUNCTION index=2778 start=0x40a48d2 */

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
/* GHIDRADEC_FUNCTION index=2779 start=0x40a4c48 */

void fpsp_ovfl(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  uint uStack_e0;
  undefined4 uStack_c8;
  undefined4 *puStack_84;
  
  saveFPUStateFrame(uStack_c8);
  *puStack_84 = in_FPCR;
  puStack_84[3] = in_FPSR;
  puStack_84[6] = in_FPIAR;
  sub_40A4D76();
  if (((uint)puStack_84 & 0x1000) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_ovfl();
    return;
  }
  if (((uint)puStack_84 & 0x200) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_inex();
    return;
  }
  if ((uStack_e0 & 0x2000000) != 0) {
    b1238_fix();
    restoreFPUStateFrame(uStack_c8);
    fpsp_done();
    return;
  }
  fpsp_done();
  return;
}
/* GHIDRADEC_FUNCTION index=2780 start=0x40a4dce */

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
/* GHIDRADEC_FUNCTION index=2781 start=0x40a5024 */

void store(void)

{
  word wVar1;
  byte bVar2;
  char cVar4;
  int iVar3;
  byte *in_A0;
  byte *extraout_A0;
  int unaff_A6;
  unkbyte10 in_FP0;
  unkbyte10 extraout_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    cVar4 = g_opcls();
    if (cVar4 == '\x03') {
      iVar3 = g_dfmtou();
      if (iVar3 == 0) {
        return;
      }
      if (iVar3 != 1) {
        return;
      }
      return;
    }
    wVar1 = (word)((uint)*(undefined4 *)(unaff_A6 + -0xe4) >> 0x10);
    in_A0 = extraout_A0;
    in_FP0 = extraout_FP0;
  }
  else {
    wVar1 = (word)((uint)*(undefined4 *)(unaff_A6 + -0xf0) >> 0x10);
  }
  bVar2 = *(byte *)((int)&dword_40A501C + (int)(sword)((wVar1 & 0x3ff) >> 7));
  if (in_A0[2] != 0) {
    *in_A0 = *in_A0 | 0x80;
  }
  fmovem(*(undefined4 *)in_A0,(uint)bVar2);
  if (bVar2 == 0x80) {
    *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
    return;
  }
  if (bVar2 == 0x40) {
    *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
    return;
  }
  if (bVar2 == 0x20) {
    *(unkbyte10 *)(unaff_A6 + -0x98) = unaff_FP2;
    return;
  }
  if (bVar2 == 0x10) {
    *(unkbyte10 *)(unaff_A6 + -0x8c) = unaff_FP3;
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2782 start=0x40a50e2 */

void dest_dbl(void)

{
  uint uVar1;
  uint *in_A1;
  
  if (*(sword *)in_A1 == 0x7fff) {
    uVar1 = 0x7ff00000;
    in_A1[1] = 0;
    if (*(char *)((int)in_A1 + 2) != '\0') {
      uVar1 = 0xfff00000;
    }
    *in_A1 = uVar1;
  }
  else {
    uVar1 = (uint)(word)(*(sword *)in_A1 + 0xc400) << 0x14;
    if (*(char *)((int)in_A1 + 2) != '\0') {
      uVar1 = uVar1 | 0x80000000;
    }
    *in_A1 = (in_A1[1] & 0x7fffffff) >> 0xb | uVar1;
    in_A1[1] = in_A1[1] << 0x15;
    in_A1[1] = in_A1[2] >> 0xb | in_A1[1];
  }
  mem_write();
  return;
}
/* GHIDRADEC_FUNCTION index=2783 start=0x40a5166 */

void dest_sgl(void)

{
  uint uVar1;
  int in_A0;
  sword *in_A1;
  int unaff_A6;
  
  if (*in_A1 == 0x7fff) {
    uVar1 = 0x7f800000;
    if (*(char *)(in_A1 + 1) != '\0') {
      uVar1 = 0xff800000;
    }
  }
  else {
    uVar1 = (uint)(word)(*in_A1 + 0xc080) << 0x17;
    if (*(char *)(in_A1 + 1) != '\0') {
      uVar1 = uVar1 | 0x80000000;
    }
    uVar1 = (*(uint *)(in_A1 + 2) & 0x7fffffff) >> 8 | uVar1;
  }
  *(uint *)(unaff_A6 + -0x54) = uVar1;
  if (in_A0 != 0) {
    mem_write();
    return;
  }
  get_fline();
  reg_dest();
  return;
}
/* GHIDRADEC_FUNCTION index=2784 start=0x40a51ee */

void dest_ext(void)

{
  byte *in_A1;
  
  if (in_A1[2] != 0) {
    *in_A1 = *in_A1 | 0x80;
  }
  in_A1[2] = 0;
  mem_write();
  return;
}
/* GHIDRADEC_FUNCTION index=2785 start=0x40a520e */

void fpsp_unfl(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  uint uStack_e0;
  undefined4 uStack_c8;
  undefined4 uStack_84;
  byte bStack_7e;
  undefined4 uStack_80;
  
  saveFPUStateFrame(uStack_c8);
  *uStack_84 = in_FPCR;
  uStack_84[3] = in_FPSR;
  uStack_84[6] = in_FPIAR;
  sub_40A533C();
  if (((uint)uStack_84 & 0x800) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_unfl();
    return;
  }
  if ((bStack_7e & uStack_84._2_1_ & 3) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_inex();
    return;
  }
  if ((uStack_e0 & 0x2000000) != 0) {
    b1238_fix();
    restoreFPUStateFrame(uStack_c8);
    fpsp_done();
    return;
  }
  fpsp_done();
  return;
}
/* GHIDRADEC_FUNCTION index=2786 start=0x40a5420 */

void fpsp_unimp(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  return;
}
/* GHIDRADEC_FUNCTION index=2787 start=0x40a5426 */

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
/* GHIDRADEC_FUNCTION index=2788 start=0x40a5492 */

void fpsp_unsupp(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  undefined4 uStack_c8;
  undefined4 *puStack_84;
  
  saveFPUStateFrame(uStack_c8);
  *puStack_84 = in_FPCR;
  puStack_84[3] = in_FPSR;
  puStack_84[6] = in_FPIAR;
  if ((uStack_c8._0_1_ & 0xf0) == 0x40) {
    get_op();
    res_func();
    gen_except();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2789 start=0x40a5510 */

int _port_allocate_EXTERNAL(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  cStack_29 = '\x01';
  iStack_28 = 0x18;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x81c;
  iVar1 = _msg_rpc(auStack_2c,0,0x28,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x880) {
      if ((((iStack_28 == 0x28) && (cStack_29 == '\x01')) ||
          ((iStack_28 == 0x20 && ((cStack_29 == '\x01' && (iStack_10 != 0)))))) &&
         (iStack_14 == 0x2200018)) {
        if (iStack_10 != 0) {
          return iStack_10;
        }
        if (iStack_c == 0x2200018) {
          *param_2 = uStack_8;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2790 start=0x40a55ea */

int _port_deallocate_EXTERNAL(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined auStack_24 [3];
  char cStack_21;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_c = 0x2200018;
  iStack_8 = param_2;
  cStack_21 = '\x01';
  iStack_20 = 0x20;
  uStack_1c = 0x100;
  uStack_14 = param_1;
  uStack_18 = _mig_get_reply_port();
  iStack_10 = 0x81d;
  iVar1 = _msg_rpc(auStack_24,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_10 == 0x881) {
      if (((iStack_20 == 0x20) && (cStack_21 == '\x01')) && (iStack_c == 0x2200018)) {
        iVar1 = iStack_8;
        if (iStack_8 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2791 start=0x40a56ae */

int _port_set_add_EXTERNAL(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  uStack_c = 0x2200018;
  uStack_8 = param_3;
  cStack_29 = '\x01';
  iStack_28 = 0x28;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x822;
  iVar1 = _msg_rpc(auStack_2c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x886) {
      if (((iStack_28 == 0x20) && (cStack_29 == '\x01')) && (iStack_14 == 0x2200018)) {
        iVar1 = iStack_10;
        if (iStack_10 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2792 start=0x40a5780 */

int _port_set_allocate_EXTERNAL(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  cStack_29 = '\x01';
  iStack_28 = 0x18;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x820;
  iVar1 = _msg_rpc(auStack_2c,0,0x28,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x884) {
      if ((((iStack_28 == 0x28) && (cStack_29 == '\x01')) ||
          ((iStack_28 == 0x20 && ((cStack_29 == '\x01' && (iStack_10 != 0)))))) &&
         (iStack_14 == 0x2200018)) {
        if (iStack_10 != 0) {
          return iStack_10;
        }
        if (iStack_c == 0x2200018) {
          *param_2 = uStack_8;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2793 start=0x40a585a */

int _port_set_deallocate_EXTERNAL(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined auStack_24 [3];
  char cStack_21;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_c = 0x2200018;
  iStack_8 = param_2;
  cStack_21 = '\x01';
  iStack_20 = 0x20;
  uStack_1c = 0x100;
  uStack_14 = param_1;
  uStack_18 = _mig_get_reply_port();
  iStack_10 = 0x821;
  iVar1 = _msg_rpc(auStack_24,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_10 == 0x885) {
      if (((iStack_20 == 0x20) && (cStack_21 == '\x01')) && (iStack_c == 0x2200018)) {
        iVar1 = iStack_8;
        if (iStack_8 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2794 start=0x40a591e */

int _task_set_special_port_EXTERNAL(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  uStack_c = 0x6200018;
  uStack_8 = param_3;
  cStack_29 = '\0';
  iStack_28 = 0x28;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x80b;
  iVar1 = _msg_rpc(auStack_2c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x86f) {
      if (((iStack_28 == 0x20) && (cStack_29 == '\x01')) && (iStack_14 == 0x2200018)) {
        iVar1 = iStack_10;
        if (iStack_10 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2795 start=0x40a59ee */

int _thread_get_special_port_EXTERNAL(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  cStack_29 = '\x01';
  iStack_28 = 0x20;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x813;
  iVar1 = _msg_rpc(auStack_2c,0,0x28,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x877) {
      if ((((iStack_28 == 0x28) && (cStack_29 == '\0')) ||
          ((iStack_28 == 0x20 && ((cStack_29 == '\x01' && (iStack_10 != 0)))))) &&
         (iStack_14 == 0x2200018)) {
        if (iStack_10 != 0) {
          return iStack_10;
        }
        if (iStack_c == 0x6200018) {
          *param_3 = uStack_8;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2796 start=0x40a5ad4 */

int _thread_set_special_port_EXTERNAL(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  uStack_c = 0x6200018;
  uStack_8 = param_3;
  cStack_29 = '\0';
  iStack_28 = 0x28;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x814;
  iVar1 = _msg_rpc(auStack_2c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x878) {
      if (((iStack_28 == 0x20) && (cStack_29 == '\x01')) && (iStack_14 == 0x2200018)) {
        iVar1 = iStack_10;
        if (iStack_10 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2797 start=0x40a5ba4 */

int _vm_deallocate_EXTERNAL(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  uStack_c = 0x2200018;
  uStack_8 = param_3;
  cStack_29 = '\x01';
  iStack_28 = 0x28;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x7e7;
  iVar1 = _msg_rpc(auStack_2c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x84b) {
      if (((iStack_28 == 0x20) && (cStack_29 == '\x01')) && (iStack_14 == 0x2200018)) {
        iVar1 = iStack_10;
        if (iStack_10 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2798 start=0x40a5c76 */

int _vm_read_EXTERNAL(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,
                     undefined4 *param_5)

{
  int iVar1;
  undefined auStack_34 [3];
  char cStack_31;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_1c = 0x2200018;
  iStack_18 = param_2;
  uStack_14 = 0x2200018;
  iStack_10 = param_3;
  cStack_31 = '\x01';
  iStack_30 = 0x28;
  uStack_2c = 0x100;
  uStack_24 = param_1;
  uStack_28 = _mig_get_reply_port();
  iStack_20 = 0x7ea;
  iVar1 = _msg_rpc(auStack_34,0,0x30,0,0);
  if (iVar1 == 0) {
    if (iStack_20 == 0x84e) {
      if ((((iStack_30 == 0x30) && (cStack_31 == '\0')) ||
          ((iStack_30 == 0x20 && ((cStack_31 == '\x01' && (iStack_18 != 0)))))) &&
         (iStack_1c == 0x2200018)) {
        if (iStack_18 != 0) {
          return iStack_18;
        }
        if ((((byte)uStack_14 & 0xc) == 4) && (iStack_10 == 0x90008)) {
          *param_4 = uStack_8;
          *param_5 = uStack_c;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2799 start=0x400544e */

undefined4 sub_400544E(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case :
    uVar1 = 0;
    break;
  case :
    uVar1 = 0x54;
    break;
  case :
    uVar1 = 0x56;
    break;
  case :
    uVar1 = 0x55;
    break;
  :
    uVar1 = 0x53;
    break;
  case :
    uVar1 = 0xc;
    break;
  case :
    uVar1 = 0xd;
  }
  return uVar1;
}

