
/* WARNING: Removing unreachable block (ram,0xf00201b4) */
/* WARNING: Removing unreachable block (ram,0xf0020170) */
/* WARNING: Removing unreachable block (ram,0xf00201bc) */
/* WARNING: Removing unreachable block (ram,0xf0020110) */

undefined8 _sonewconn(undefined2 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  if (((sword)param_1[0x11] * 3) / 2 < (int)(sword)param_1[0x10] + (int)(sword)param_1[0xc]) {
    iVar3 = 0;
  }
  else {
    iVar1 = 0;
    _m_getclr(0,3);
    if (iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 4);
      *(undefined2 *)(iVar1 + iVar3) = *param_1;
      iVar3 = iVar1 + iVar3;
      *(word *)(iVar3 + 2) = param_1[1] & 0xfffd;
      *(undefined2 *)(iVar3 + 4) = param_1[2];
      *(word *)(iVar3 + 6) = param_1[3] | 1;
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 6);
      *(undefined2 *)(iVar3 + 0x54) = param_1[0x2a];
      *(undefined2 *)(iVar3 + 0x5a) = param_1[0x2d];
      _soqinsque(param_1,iVar3,0);
      iVar2 = iVar3;
      (**(code **)(*(int *)(iVar3 + 0xc) + 0x1c))(iVar3,0,0,0,0);
      if (iVar2 == 0) goto locret_F00201C8;
      if (*(int *)(iVar3 + 0x10) != 0) {
        _soqremque(iVar3,0);
      }
      _m_free(iVar1);
    }
    iVar3 = 0;
  }
locret_F00201C8:
  return CONCAT44(param_2,iVar3);
}
