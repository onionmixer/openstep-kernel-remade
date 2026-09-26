
/* WARNING: Removing unreachable block (ram,0xf008aef4) */
/* WARNING: Removing unreachable block (ram,0xf008af4c) */
/* WARNING: Removing unreachable block (ram,0xf008aedc) */
/* WARNING: Removing unreachable block (ram,0xf008af18) */

undefined8 sub_F008AEAC(uint *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  uVar3 = *param_1;
  if (uVar3 >> 0x18 != 0) {
    iVar2 = *(int *)(unk_F0130F70 + (uVar3 >> 0x18) * 4);
    uVar3 = uVar3 & 0xffffff;
    _lock_write(iVar2 + 0x34);
    if (*(int *)(iVar2 + 0x14) <= (int)uVar3) {
      _panic(aVnodePagerDeal);
    }
    if ((int)uVar3 < *(int *)(iVar2 + 0x24)) {
      *(uint *)(iVar2 + 0x24) = uVar3;
    }
    iVar1 = (int)uVar3 >> 3;
    *(byte *)(*(int *)(iVar2 + 0x10) + iVar1) =
         *(byte *)(*(int *)(iVar2 + 0x10) + iVar1) &
         ~(byte)(1 << ((char)uVar3 + (char)iVar1 * -8 & 0x1fU));
    *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
    _lock_done(iVar2 + 0x34);
  }
  return CONCAT44(param_2,uVar3);
}
