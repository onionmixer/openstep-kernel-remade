
/* WARNING: Removing unreachable block (ram,0xf004758c) */
/* WARNING: Removing unreachable block (ram,0xf0047544) */
/* WARNING: Removing unreachable block (ram,0xf0047538) */
/* WARNING: Removing unreachable block (ram,0xf0047564) */
/* WARNING: Removing unreachable block (ram,0xf00475ac) */
/* WARNING: Removing unreachable block (ram,0xf0047524) */

undefined8 _makespecvp(sword param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
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
  while( true ) {
    iVar2 = (int)param_1;
    iVar1 = iVar2;
    sub_F00478C4(iVar2,0,param_2);
    if (iVar1 == 0) break;
    if ((*(word *)(iVar1 + 0x40) & 1) == 0) goto locret_F00475BC;
    *(word *)(iVar1 + 0x40) = *(word *)(iVar1 + 0x40) | 0x10;
    _sleep(iVar1,10);
  }
  iVar1 = 0x68;
  _kalloc();
  _bzero();
  *(undefined **)(iVar1 + 0x20) = _spec_vnodeops;
  *(int *)(iVar1 + 0x2c) = param_2;
  if (param_2 == 3) {
    _bdevvp();
    *(int *)(iVar1 + 0x3c) = iVar2;
  }
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(sword *)(iVar1 + 0x42) = param_1;
  *(sword *)(iVar1 + 0x30) = param_1;
  *(undefined2 *)(iVar1 + 10) = 1;
  *(int *)(iVar1 + 0x34) = iVar1;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  sub_F00475C4(iVar1);
locret_F00475BC:
  return CONCAT44(param_2,iVar1 + 4);
}
