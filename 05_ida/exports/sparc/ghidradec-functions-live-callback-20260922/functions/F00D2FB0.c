
/* WARNING: Removing unreachable block (ram,0xf00d2ff0) */
/* WARNING: Removing unreachable block (ram,0xf00d2fd4) */
/* WARNING: Removing unreachable block (ram,0xf00d3024) */
/* WARNING: Removing unreachable block (ram,0xf00d2fc0) */

undefined8
-[EventDriver evSpecialKeyMsg:direction:flags:level:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  int iVar1;
  int iVar2;
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
  iVar1 = param_1;
  _objc_msgSend(param_1,paSpecialkeyport_0,param_3);
  if (iVar1 != 0) {
    iVar2 = 0x38;
    _IOMalloc();
    if (iVar2 != 0) {
      _bcopy(unk_F00F9688,iVar2,0x38);
      *(int *)(iVar2 + 0x10) = iVar1;
      *(undefined4 *)(iVar2 + 0x1c) = param_3;
      *(undefined4 *)(iVar2 + 0x24) = param_4;
      *(undefined4 *)(iVar2 + 0x2c) = param_5;
      *(undefined4 *)(iVar2 + 0x34) = param_6;
      _objc_msgSend(param_1,paSendiothreadas,paPerformspecial,param_1,iVar2);
    }
  }
  return CONCAT44(param_2,param_1);
}

