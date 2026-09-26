
/* WARNING: Removing unreachable block (ram,0xf00c499c) */
/* WARNING: Removing unreachable block (ram,0xf00c4a00) */
/* WARNING: Removing unreachable block (ram,0xf00c4970) */

undefined8 +[IODevice registerClass:](undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined5 *puVar3;
  int iVar4;
  undefined4 *puVar5;
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
  puVar5 = (undefined4 *)0x1c;
  _IOMalloc();
  *puVar5 = param_3;
  puVar5[3] = 0xffffffff;
  puVar5[2] = 0xffffffff;
  puVar3 = paLock;
  uVar2 = dword_F013304C;
  puVar5[4] = 0;
  _objc_msgSend(uVar2,puVar3);
  iVar4 = dword_F0133040 + 1;
  puVar5[1] = dword_F0133040;
  dword_F0133040 = iVar4;
  if ((undefined4 **)dword_F0133044 == &dword_F0133044) {
    dword_F0133044 = puVar5;
    DAT_f0133048 = puVar5;
    puVar5[5] = &dword_F0133044;
    puVar5[6] = &dword_F0133044;
  }
  else {
    puVar5[6] = DAT_f0133048;
    puVar5[5] = &dword_F0133044;
    puVar1 = (undefined4 *)((int)DAT_f0133048 + 0x14);
    DAT_f0133048 = puVar5;
    *puVar1 = puVar5;
  }
  _objc_msgSend(dword_F013304C,paUnlock);
  return CONCAT44(param_2,param_1);
}

