
/* WARNING: Removing unreachable block (ram,0xf00c6bc8) */
/* WARNING: Removing unreachable block (ram,0xf00c6bf8) */
/* WARNING: Removing unreachable block (ram,0xf00c6b94) */

undefined8
-[IOLogicalDisk writeAsyncAt:length:buffer:pending:client:]
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined4 unaff_l0;
  undefined4 uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
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
  uVar1 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar2 = param_1;
  _objc_msgSend(param_1,paIswriteprotect);
  if ((uVar2 & 0xff) == 0) {
    uVar2 = param_1;
    _objc_msgSend(param_1,paDiskparamcommo,param_3,param_4,
                  (undefined *)((int)register0x00000038 + -0x14),
                  (undefined *)((int)register0x00000038 + -0x18));
    if (uVar2 == 0) {
      uVar2 = *(uint *)(param_1 + 0x184);
      _objc_msgSend(uVar2,paWriteasyncatLe,*(undefined4 *)((int)register0x00000038 + -0x14),
                    *(undefined4 *)((int)register0x00000038 + -0x18),param_5,param_6,uVar1);
    }
  }
  else {
    uVar2 = 0xfffffd31;
  }
  return CONCAT44(param_2,uVar2);
}
