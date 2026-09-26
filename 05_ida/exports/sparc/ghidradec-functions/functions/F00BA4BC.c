
/* WARNING: Removing unreachable block (ram,0xf00ba564) */
/* WARNING: Removing unreachable block (ram,0xf00ba4e4) */
/* WARNING: Removing unreachable block (ram,0xf00ba56c) */
/* WARNING: Removing unreachable block (ram,0xf00ba4c0) */

undefined8 _zsmctl(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  byte bVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  uint uVar5;
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
  iVar3 = *(int *)(param_1 + 0x34);
  _splzs();
  uVar4 = *(byte *)(iVar3 + 0x25) & 0x82;
  **(undefined **)(iVar3 + 0x10) = 0x10;
  _us_spin(2);
  uVar5 = uVar4 | **(byte **)(iVar3 + 0x10) & 0x28;
  if (param_3 == 1) {
    uVar1 = uVar5 | param_2;
loc_F00BA544:
    uVar4 = uVar1 & 0xffffff82;
    uVar5 = uVar1;
  }
  else if (param_3 < 2) {
    uVar1 = param_2;
    if (param_3 == 0) goto loc_F00BA544;
  }
  else {
    if (param_3 == 2) {
      uVar1 = uVar5 & ~param_2;
      goto loc_F00BA544;
    }
    if (param_3 == 3) goto loc_F00BA56C;
  }
  uVar1 = *(byte *)(iVar3 + 0x25) & 0x7d;
  bVar2 = (byte)uVar1;
  *(byte *)(iVar3 + 0x25) = bVar2;
  *(byte *)(iVar3 + 0x25) = bVar2 | (byte)uVar4;
  _zszwrite(*(undefined4 *)(iVar3 + 0x10),5,uVar1 | uVar4 & 0xff);
loc_F00BA56C:
  _splx(param_1);
  return CONCAT44(param_2,uVar5);
}
