
/* WARNING: Removing unreachable block (ram,0xf003897c) */

undefined8 _udp_ctlinput(uint param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
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
  if ((param_1 == 1) || ((param_1 < 0x16 && (_inetctlerrmap[param_1] != '\0')))) {
    if (param_3 == (byte *)0x0) {
      uVar2 = 0;
      uVar4 = 0;
      *(undefined4 *)((int)register0x00000038 + -0xc) = _zeroin_addr;
    }
    else {
      bVar1 = *param_3;
      *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_3 + 0xc);
      iVar3 = (bVar1 & 0xf) * 4;
      uVar2 = *(undefined2 *)(param_3 + iVar3 + 2);
      uVar4 = *(undefined2 *)(param_3 + iVar3);
    }
    _in_pcbnotify(&_udb,param_2,uVar2,(undefined *)((int)register0x00000038 + -0xc),uVar4,param_1,
                  _udp_notify);
  }
  return CONCAT44(param_2,param_1);
}

