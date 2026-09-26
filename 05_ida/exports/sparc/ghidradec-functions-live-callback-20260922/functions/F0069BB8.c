
/* WARNING: Removing unreachable block (ram,0xf0069c98) */
/* WARNING: Removing unreachable block (ram,0xf0069c78) */
/* WARNING: Removing unreachable block (ram,0xf0069c0c) */
/* WARNING: Removing unreachable block (ram,0xf0069c1c) */
/* WARNING: Removing unreachable block (ram,0xf0069c90) */
/* WARNING: Removing unreachable block (ram,0xf0069cac) */
/* WARNING: Removing unreachable block (ram,0xf0069bf0) */

undefined8 _host_adjust_time(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined4 uVar6;
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
  if (param_1 == 0) {
    uVar6 = 0x16;
  }
  else {
    piVar1 = param_2 + 1;
    param_2 = (int *)(*param_2 * 1000000);
    uVar5 = (int)param_2 + *piVar1;
    _splusclock();
    uVar4 = _timedelta;
    uVar3 = _timedelta;
    div(_timedelta,1000000);
    *(uint *)((int)register0x00000038 + -0x10) = uVar3;
    uVar3 = uVar4;
    rem(uVar4,1000000);
    *(uint *)((int)register0x00000038 + -0xc) = uVar3;
    if (uVar4 == 0) {
      if (_bigadj < uVar5) {
        _tickdelta = _tickadj * 10;
      }
      else {
        _tickdelta = _tickadj;
      }
    }
    iVar2 = _tickdelta;
    uVar4 = uVar5;
    urem(uVar5,_tickdelta);
    if (uVar4 != 0) {
      udiv(uVar5,iVar2);
      umul();
    }
    _timedelta = uVar5;
    _splx(param_2);
    *param_3 = *(undefined4 *)((int)register0x00000038 + -0x10);
    uVar6 = 0;
    param_3[1] = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,uVar6);
}

