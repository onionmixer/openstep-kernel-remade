
/* WARNING: Removing unreachable block (ram,0xf001fa34) */
/* WARNING: Removing unreachable block (ram,0xf001f9f0) */
/* WARNING: Removing unreachable block (ram,0xf001f9c0) */
/* WARNING: Removing unreachable block (ram,0xf001f9cc) */
/* WARNING: Removing unreachable block (ram,0xf001fa2c) */
/* WARNING: Removing unreachable block (ram,0xf001fa68) */
/* WARNING: Removing unreachable block (ram,0xf001f9a0) */

undefined8 _sorflush(int param_1,undefined4 param_2)

{
  word wVar1;
  uint uVar2;
  code *pcVar3;
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
  iVar4 = *(int *)(param_1 + 0xc);
  wVar1 = *(word *)(param_1 + 0x38);
  while ((wVar1 & 1) != 0) {
    *(word *)(param_1 + 0x38) = *(word *)(param_1 + 0x38) | 2;
    _sleep(param_1 + 0x38,0x1a);
    wVar1 = *(word *)(param_1 + 0x38);
  }
  uVar2 = *(word *)(param_1 + 0x38) | 1;
  *(sword *)(param_1 + 0x38) = (sword)uVar2;
  _spltty();
  _socantrcvmore(param_1);
  wVar1 = *(word *)(param_1 + 0x38);
  *(word *)(param_1 + 0x38) = wVar1 & 0xfffe;
  if ((wVar1 & 2) != 0) {
    *(word *)(param_1 + 0x38) = wVar1 & 0xfffc;
    _wakeup(param_1 + 0x38);
  }
  *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x38);
  _bzero((undefined4 *)(param_1 + 0x24),0x18);
  _splx(uVar2);
  if (((*(word *)(iVar4 + 10) & 0x10) != 0) &&
     (pcVar3 = *(code **)(*(int *)(iVar4 + 4) + 0x10), pcVar3 != (code *)0x0)) {
    (*pcVar3)(*(undefined4 *)((int)register0x00000038 + -0x14));
  }
  _sbrelease((undefined *)((int)register0x00000038 + -0x20));
  return CONCAT44(param_2,param_1);
}

