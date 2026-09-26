
/* WARNING: Removing unreachable block (ram,0xf00c48ec) */
/* WARNING: Removing unreachable block (ram,0xf00c48c0) */
/* WARNING: Removing unreachable block (ram,0xf00c4928) */
/* WARNING: Removing unreachable block (ram,0xf00c48a0) */

undefined8 +[IODevice initialize](undefined *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined7 *puVar3;
  undefined7 *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar2 = aIodevice;
  _objc_getClass();
  if (param_1 != puVar2) {
    _objc_msgSend(paIodevice_0,paRegisterclass,param_1);
  }
  puVar4 = paNxlock;
  puVar1 = paNew;
  if (byte_F012EC30 == '\0') {
    puVar3 = paNxlock;
    _objc_msgSend(paNxlock,paNew);
    dword_F0133030 = 0;
    DAT_f0133038 = &dword_F0133034;
    dword_F0133034 = &dword_F0133034;
    DAT_f0133048 = &dword_F0133044;
    dword_F0133044 = &dword_F0133044;
    dword_F013303C = puVar3;
    _objc_msgSend(puVar4,puVar1);
    byte_F012EC30 = '\x01';
    dword_F013304C = puVar4;
  }
  return CONCAT44(param_2,param_1);
}
