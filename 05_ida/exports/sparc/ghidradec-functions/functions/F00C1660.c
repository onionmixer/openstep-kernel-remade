
/* WARNING: Removing unreachable block (ram,0xf00c174c) */
/* WARNING: Removing unreachable block (ram,0xf00c16b0) */
/* WARNING: Removing unreachable block (ram,0xf00c17a8) */
/* WARNING: Removing unreachable block (ram,0xf00c1690) */

undefined8 _kbdIntHandler(undefined8 *param_1,undefined *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 uVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar7;
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
  iVar5 = *(int *)(*(int *)(param_2 + 0x34) + 0x34);
  uVar6 = *(undefined4 *)(*(int *)(param_2 + 0x34) + 0x38);
  puVar7 = (undefined *)param_1;
  if ((iVar5 == 0) || (puVar7 = (undefined *)((uint)param_1 & 0xff), unk_F0132FF4._0_1_ == '\x01'))
  goto locret_F00C17B0;
  puVar1 = (undefined8 *)puVar7;
  sub_F00C1080();
  if (puVar1 == (undefined8 *)0x0) {
loc_F00C16FC:
    puVar7 = (undefined *)0x0;
  }
  else {
    param_2 = unk_F0132F88;
    DAT_f0132f90._0_4_ = (uint)param_1 & 0x7f;
    _IOGetTimestamp(unk_F0132F88);
    uVar2 = (uint)puVar7 >> 7 ^ 1;
    DAT_f0132f90._4_1_ = (undefined)uVar2;
    if (uVar2 == 0) {
      iVar4 = (DAT_f0132f90._0_4_ >> 5) * 4;
      *(uint *)(unk_F0132FF8 + iVar4) =
           *(uint *)(unk_F0132FF8 + iVar4) & ~(1 << ((byte)DAT_f0132f90._0_4_ & 0x1f));
    }
    else {
      iVar4 = (DAT_f0132f90._0_4_ >> 5) * 4;
      uVar2 = 1 << ((byte)DAT_f0132f90._0_4_ & 0x1f);
      if ((*(uint *)(unk_F0132FF8 + iVar4) & uVar2) != 0) goto loc_F00C16FC;
      *(uint *)(unk_F0132FF8 + iVar4) = *(uint *)(unk_F0132FF8 + iVar4) | uVar2;
    }
    puVar7 = unk_F0132F88;
  }
  if ((undefined8 *)puVar7 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)puVar7;
    sub_F00C0C30(puVar7,uVar6);
    if (((uint)puVar1 & 0xff) == 0) {
      if (dword_F0132FF0 == 5) goto locret_F00C17B0;
      iVar3 = dword_F0132FF0 * 0x10;
      iVar4 = dword_F0132FF0 * 2;
      dword_F0132FF0 = dword_F0132FF0 + 1;
      (&qword_F0132FA0)[iVar4] = *(undefined8 *)puVar7;
      *(undefined8 *)(DAT_f0132fa8 + iVar3) = *(undefined8 *)((int)puVar7 + 8);
    }
    _IOSendInterrupt(iVar5,uVar6,0x232325);
  }
locret_F00C17B0:
  return CONCAT44(param_2,puVar7);
}
