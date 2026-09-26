
/* WARNING: Removing unreachable block (ram,0xf0076a64) */
/* WARNING: Removing unreachable block (ram,0xf00769c0) */
/* WARNING: Removing unreachable block (ram,0xf00769ec) */
/* WARNING: Removing unreachable block (ram,0xf0076a6c) */
/* WARNING: Removing unreachable block (ram,0xf007699c) */

undefined8 _calloutDispatch(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 unaff_l0;
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
  if (dword_F0110BB0 != 0) {
    iVar1 = dword_F0110BB0;
    _splusclock();
    do {
      do {
      } while (dword_F0130F20 != 0);
      puVar2 = &dword_F0130F20;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    if ((int **)dword_F0130F24 == &dword_F0130F24) {
      _panic(aInternalentrya);
    }
    if ((int **)dword_F0130F24 == &dword_F0130F24) {
      piVar3 = (int *)0x0;
    }
    else {
      *(int ***)(*dword_F0130F24 + 4) = &dword_F0130F24;
      piVar3 = dword_F0130F24;
      dword_F0130F24 = (int *)*dword_F0130F24;
    }
    piVar3[2] = param_1;
    piVar3[3] = param_2;
    piVar3[4] = 0;
    piVar3[6] = 0;
    piVar3[7] = 0;
    *piVar3 = (int)&dword_F0130F2C;
    piVar3[1] = (int)DAT_f0130f30;
    *DAT_f0130f30 = (int)piVar3;
    dword_F0130F3C = dword_F0130F3C + 1;
    DAT_f0130f30 = piVar3;
    piVar3[8] = 1;
    sub_F00773A8();
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
