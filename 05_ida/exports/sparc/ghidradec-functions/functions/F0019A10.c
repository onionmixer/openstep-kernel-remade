
/* WARNING: Removing unreachable block (ram,0xf0019a80) */
/* WARNING: Removing unreachable block (ram,0xf0019a50) */
/* WARNING: Removing unreachable block (ram,0xf0019a64) */
/* WARNING: Removing unreachable block (ram,0xf0019a98) */
/* WARNING: Removing unreachable block (ram,0xf0019a28) */

undefined8 _ttycheckoutq(int param_1,int param_2)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  iVar2 = (*(byte *)(param_1 + 0x4a) & 0x1f) * 2;
  sVar1 = *(sword *)(_tthiwat + iVar2);
  _spltty();
  iVar3 = *(int *)(param_1 + 0x18);
  if (sVar1 + 200 < iVar3) {
    while (sVar1 < iVar3) {
      _ttstart(param_1);
      if (param_2 == 0) {
        _splx(iVar2);
        uVar4 = 0;
        goto locret_F0019AA4;
      }
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x40;
      _sleep(param_1 + 0x18,0x1d);
      iVar3 = *(int *)(param_1 + 0x18);
    }
  }
  _splx(iVar2);
  uVar4 = 1;
locret_F0019AA4:
  return CONCAT44(param_2,uVar4);
}
