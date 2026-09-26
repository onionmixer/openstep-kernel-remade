
/* WARNING: Removing unreachable block (ram,0xf00d3898) */
/* WARNING: Removing unreachable block (ram,0xf00d38c4) */
/* WARNING: Removing unreachable block (ram,0xf00d3824) */
/* WARNING: Removing unreachable block (ram,0xf00d3868) */
/* WARNING: Removing unreachable block (ram,0xf00d3888) */
/* WARNING: Removing unreachable block (ram,0xf00d38ec) */
/* WARNING: Removing unreachable block (ram,0xf00d3810) */

undefined8
-[EventDriver _threadOpCommon:opParams:async:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,uint param_5
          )

{
  undefined (*pauVar1) [16];
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
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
  *(undefined4 *)((int)register0x00000038 + -0x48) = dword_F012EEAC;
  *(undefined4 *)((int)register0x00000038 + -0x44) = DAT_f012eeb0._0_4_;
  *(undefined4 *)((int)register0x00000038 + -0x40) = DAT_f012eeb0._4_4_;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = DAT_f012eeb0._8_4_;
  *(undefined4 *)((int)register0x00000038 + -0x38) = DAT_f012eeb0._12_4_;
  *(undefined4 *)((int)register0x00000038 + -0x34) = DAT_f012eeb0._16_4_;
  *(undefined4 *)((int)register0x00000038 + -0x30) = DAT_f012eeb0._20_4_;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = DAT_f012eeb0._24_4_;
  *(undefined4 *)((int)register0x00000038 + -0x28) = DAT_f012eeb0._28_4_;
  *(undefined4 *)((int)register0x00000038 + -0x24) = DAT_f012eeb0._32_4_;
  *(undefined4 *)((int)register0x00000038 + -0x20) = DAT_f012eeb0._36_4_;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = DAT_f012eeb0._40_4_;
  *(undefined4 *)((int)register0x00000038 + -0x18) = DAT_f012eeb0._44_4_;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_3;
  if ((char)param_5 == '\0') {
    pauVar1 = paNxconditionloc;
    _objc_msgSend(paNxconditionloc,paAlloc);
    *(undefined (**) [16])((int)register0x00000038 + -0x28) = pauVar1;
    _objc_msgSend();
    *(undefined **)((int)register0x00000038 + -0x24) =
         (undefined *)((int)register0x00000038 + -0x4c);
    *(undefined4 *)((int)register0x00000038 + -0x4c) = 0xfffffd3e;
  }
  puVar2 = (undefined *)((int)register0x00000038 + -0x48);
  *(undefined4 *)((int)register0x00000038 + -0x20) = *param_4;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_4[1];
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_4[2];
  *(undefined4 *)((int)register0x00000038 + -0x38) = _ev_port_list;
  _msg_send_from_kernel(puVar2,0,0);
  if (puVar2 == (undefined *)0x0) {
    if ((char)param_5 == '\0') {
      _objc_msgSend(*(undefined4 *)((int)register0x00000038 + -0x28),paLockwhen,2);
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x4c) = 0;
    }
  }
  else {
    _objc_msgSend(param_1,paName);
    _IOLog(aSThreadopcommo,param_1,puVar2);
    *(undefined4 *)((int)register0x00000038 + -0x4c) = 0xfffffd41;
  }
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x4c);
  if ((param_5 & 0xff) == 0) {
    _objc_msgSend(*(undefined4 *)((int)register0x00000038 + -0x28),paFree);
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0x4c);
  }
  return CONCAT44(param_2,uVar3);
}

