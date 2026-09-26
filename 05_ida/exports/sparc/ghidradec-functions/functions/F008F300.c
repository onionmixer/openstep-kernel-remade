
/* WARNING: Removing unreachable block (ram,0xf008f37c) */
/* WARNING: Removing unreachable block (ram,0xf008f34c) */
/* WARNING: Removing unreachable block (ram,0xf008f324) */
/* WARNING: Removing unreachable block (ram,0xf008f36c) */
/* WARNING: Removing unreachable block (ram,0xf008f38c) */
/* WARNING: Removing unreachable block (ram,0xf008f310) */

sqword -[KernDeviceDescription removeResourcesForKey:](int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar4;
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
  uVar1 = *(uint *)(param_1 + 0xc);
  _objc_msgSend(uVar1,paRemovekey,param_3);
  if (uVar1 != 0) {
    sub_F008EEA8();
    uVar4 = 0;
    if ((param_3 & 0xff) != 0) {
      for (; uVar2 = uVar1, _objc_msgSend(uVar1,paCount_0), uVar4 < uVar2; uVar4 = uVar4 + 1) {
        uVar3 = *(undefined4 *)(param_1 + 0x14);
        uVar2 = uVar1;
        _objc_msgSend(uVar1,paObjectat,uVar4);
        _objc_msgSend(uVar3,paRemoveobject,uVar2);
      }
    }
    sub_F008EE7C(uVar1);
  }
  return (qword)param_2 << 0x20;
}
