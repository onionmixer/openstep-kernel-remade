
/* WARNING: Removing unreachable block (ram,0xf00c44a8) */
/* WARNING: Removing unreachable block (ram,0xf00c4428) */
/* WARNING: Removing unreachable block (ram,0xf00c43ec) */
/* WARNING: Removing unreachable block (ram,0xf00c43d8) */
/* WARNING: Removing unreachable block (ram,0xf00c4408) */
/* WARNING: Removing unreachable block (ram,0xf00c445c) */
/* WARNING: Removing unreachable block (ram,0xf00c4484) */
/* WARNING: Removing unreachable block (ram,0xf00c43c0) */

undefined8
-[SPARCKernDeviceDescription allocateResourcesForKey:]
          (undefined *param_1,undefined4 param_2,uint param_3)

{
  undefined (*pauVar1) [14];
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
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
  bool bVar5;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  pauVar1 = paStringforkey;
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
  puVar2 = param_1;
  _objc_msgSend(param_1,paStringforkey,param_3);
  puVar3 = param_1;
  _objc_msgSend(param_1,pauVar1,aPromName_0);
  if (puVar3 == (undefined *)0x0) {
    bVar5 = true;
  }
  else {
    _strcmp();
    bVar5 = puVar3 == (undefined *)0x0;
  }
  uVar4 = param_3;
  sub_F00C4388();
  if (((uVar4 & 0xff) != 0) || (puVar2 != (undefined *)0x0)) {
    uVar4 = param_3;
    sub_F00C4388();
    if ((char)uVar4 == '\x01') {
      if (!bVar5) {
        puVar2 = param_1;
        _objc_msgSend(param_1,paParseintrresou,param_3);
        if (puVar2 == (undefined *)0x0) {
          param_1 = (undefined *)0x0;
        }
        else {
          _objc_msgSend(param_1,paSetresourcesFo,puVar2,param_3);
        }
        goto locret_F00C44B8;
      }
      *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    }
    else {
      *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    }
    param_1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141e70;
    _objc_msgSendSuper(param_1,paAllocateresour_0,param_3);
  }
locret_F00C44B8:
  return CONCAT44(param_2,param_1);
}
