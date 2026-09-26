
/* WARNING: Removing unreachable block (ram,0xf00c8bf8) */
/* WARNING: Removing unreachable block (ram,0xf00c8c48) */
/* WARNING: Removing unreachable block (ram,0xf00c8bc8) */

undefined8 sub_F00C8BC4(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined5 *puVar3;
  undefined4 *puVar4;
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
  puVar4 = (undefined4 *)0x18;
  _IOMalloc();
  *puVar4 = 5;
  puVar4[1] = param_1;
  puVar4[2] = 0;
  *(undefined2 *)(puVar4 + 3) = 0;
  puVar3 = paLock;
  uVar2 = dword_F01330B0;
  *(undefined2 *)((int)puVar4 + 0xe) = 0;
  _objc_msgSend(uVar2,puVar3);
  if ((undefined4 **)dword_F01330A8 == &dword_F01330A8) {
    dword_F01330A8 = puVar4;
    DAT_f01330ac = puVar4;
    puVar4[4] = &dword_F01330A8;
    puVar4[5] = &dword_F01330A8;
  }
  else {
    puVar4[5] = DAT_f01330ac;
    puVar4[4] = &dword_F01330A8;
    puVar1 = (undefined4 *)((int)DAT_f01330ac + 0x10);
    DAT_f01330ac = puVar4;
    *puVar1 = puVar4;
  }
  _objc_msgSend(dword_F01330B0,paUnlock);
  return CONCAT44(param_2,param_1);
}

