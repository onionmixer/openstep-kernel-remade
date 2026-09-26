
/* WARNING: Removing unreachable block (ram,0xf0020040) */
/* WARNING: Removing unreachable block (ram,0xf002001c) */
/* WARNING: Removing unreachable block (ram,0xf0020008) */
/* WARNING: Removing unreachable block (ram,0xf001fff8) */
/* WARNING: Removing unreachable block (ram,0xf0020014) */
/* WARNING: Removing unreachable block (ram,0xf0020034) */
/* WARNING: Removing unreachable block (ram,0xf002004c) */
/* WARNING: Removing unreachable block (ram,0xf001ffe0) */

undefined8 _soisconnected(int param_1,undefined4 param_2)

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
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    iVar1 = param_1;
    _soqremque(param_1,0);
    if (iVar1 == 0) {
      _panic(aSoisconnected);
    }
    _soqinsque(iVar2,param_1,1);
    _sowakeup(iVar2,iVar2 + 0x24);
    _wakeup(iVar2 + 0x54);
  }
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff3 | 2;
  _wakeup(param_1 + 0x54);
  _sowakeup(param_1,param_1 + 0x24);
  _sowakeup(param_1,param_1 + 0x3c);
  return CONCAT44(param_2,param_1);
}

