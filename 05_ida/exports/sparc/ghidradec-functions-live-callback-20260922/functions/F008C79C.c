
/* WARNING: Removing unreachable block (ram,0xf008c7f0) */
/* WARNING: Removing unreachable block (ram,0xf008c7e4) */
/* WARNING: Removing unreachable block (ram,0xf008c818) */
/* WARNING: Removing unreachable block (ram,0xf008c7c0) */

undefined8 sub_F008C79C(undefined4 param_1,undefined4 param_2)

{
  undefined (*pauVar1) [12];
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = 0;
  while( true ) {
    pauVar1 = paIodevice_0;
    _objc_msgSend(paIodevice_0,paLookupbyobject,iVar3,(undefined *)((int)register0x00000038 + -0xc))
    ;
    iVar3 = iVar3 + 1;
    if (pauVar1 == (undefined (*) [12])0xfffffd40) break;
    if (pauVar1 != (undefined (*) [12])0xfffffd29) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      _objc_msgSend(uVar2,paClass);
      _objc_msgSend();
      if ((uVar2 & 0xff) != 0) {
        _objc_msgSend(*(undefined4 *)((int)register0x00000038 + -0xc),paPerformWith,param_1,param_2)
        ;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

