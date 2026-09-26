
/* WARNING: Removing unreachable block (ram,0xf00c1d34) */
/* WARNING: Removing unreachable block (ram,0xf00c1d54) */
/* WARNING: Removing unreachable block (ram,0xf00c1d08) */

undefined8 _TYPE5StealKeyEvent(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
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
  _zsstealkey();
  uVar3 = param_1 & 0xff;
  uVar1 = uVar3;
  sub_F00C1080(uVar3,_zs_tty + (uint)bRamf0120e25 * 0x88);
  if (uVar1 == 0) {
loc_F00C1DA0:
    puVar4 = (undefined *)0x0;
  }
  else {
    DAT_f0132f90._0_4_ = param_1 & 0x7f;
    _IOGetTimestamp(unk_F0132F88);
    uVar1 = uVar3 >> 7 ^ 1;
    DAT_f0132f90._4_1_ = (undefined)uVar1;
    if (uVar1 == 0) {
      iVar2 = (DAT_f0132f90._0_4_ >> 5) * 4;
      *(uint *)(unk_F0132FF8 + iVar2) =
           *(uint *)(unk_F0132FF8 + iVar2) & ~(1 << ((byte)DAT_f0132f90._0_4_ & 0x1f));
    }
    else {
      iVar2 = (DAT_f0132f90._0_4_ >> 5) * 4;
      uVar1 = 1 << ((byte)DAT_f0132f90._0_4_ & 0x1f);
      if ((*(uint *)(unk_F0132FF8 + iVar2) & uVar1) != 0) goto loc_F00C1DA0;
      *(uint *)(unk_F0132FF8 + iVar2) = *(uint *)(unk_F0132FF8 + iVar2) | uVar1;
    }
    puVar4 = unk_F0132F88;
  }
  return CONCAT44(param_2,puVar4);
}

