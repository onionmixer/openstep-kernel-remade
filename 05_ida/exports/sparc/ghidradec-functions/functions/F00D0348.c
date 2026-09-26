
/* WARNING: Removing unreachable block (ram,0xf00d040c) */
/* WARNING: Removing unreachable block (ram,0xf00d03e8) */
/* WARNING: Removing unreachable block (ram,0xf00d03b8) */
/* WARNING: Removing unreachable block (ram,0xf00d03a4) */
/* WARNING: Removing unreachable block (ram,0xf00d03d0) */
/* WARNING: Removing unreachable block (ram,0xf00d03f8) */
/* WARNING: Removing unreachable block (ram,0xf00d041c) */
/* WARNING: Removing unreachable block (ram,0xf00d0384) */

sqword -[SCSIGeneric sgInit:controller:]
                 (int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined7 *puVar3;
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
  *(undefined4 *)(param_1 + 0x128) = param_4;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  puVar3 = paNxlock;
  puVar1 = paNew;
  *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0x7fffffff;
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) & 0x7fffffff;
  _objc_msgSend(puVar3,puVar1);
  *(undefined7 **)(param_1 + 300) = puVar3;
  *(undefined4 *)(param_1 + 0x130) = 0;
  _sprintf((undefined *)((int)register0x00000038 + -0x28),&aSgD,param_3);
  _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x28));
  _objc_msgSend(param_1,paSetdevicekind,aScsigeneric);
  uVar2 = paSetlocation;
  _objc_msgSend(param_4,paName);
  _objc_msgSend(param_1,uVar2,param_4);
  _objc_msgSend(param_1,paSetunit,param_3);
  _objc_msgSend(param_1,paRegisterdevice);
  return (qword)param_2 << 0x20;
}
