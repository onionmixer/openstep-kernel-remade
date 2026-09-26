
/* WARNING: Removing unreachable block (ram,0xf000a0f8) */
/* WARNING: Removing unreachable block (ram,0xf000a0d4) */
/* WARNING: Removing unreachable block (ram,0xf000a0b8) */
/* WARNING: Removing unreachable block (ram,0xf000a0e0) */
/* WARNING: Removing unreachable block (ram,0xf000a110) */
/* WARNING: Removing unreachable block (ram,0xf000a070) */

undefined8 _hzto(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
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
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  uVar2 = _hz;
  iVar4 = *param_1 - *(int *)((int)register0x00000038 + -0x10);
  if (iVar4 < 0x20c0b4) {
    iVar1 = param_1[1] - *(int *)((int)register0x00000038 + -0xc);
    div(iVar1,1000);
    iVar1 = iVar4 * 1000 + iVar1;
    uVar2 = _tick;
    div(_tick,1000);
    div(iVar1,uVar2);
  }
  else {
    iVar3 = 0x7fffffff;
    div(0x7fffffff,_hz);
    iVar1 = 0x7fffffff;
    if (iVar4 <= iVar3) {
      umul(iVar4,uVar2);
      iVar1 = iVar4;
    }
  }
  return CONCAT44(param_2,iVar1);
}

