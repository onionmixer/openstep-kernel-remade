
/* WARNING: Removing unreachable block (ram,0xf002fba0) */
/* WARNING: Removing unreachable block (ram,0xf002fb50) */
/* WARNING: Removing unreachable block (ram,0xf002fa84) */
/* WARNING: Removing unreachable block (ram,0xf002fabc) */
/* WARNING: Removing unreachable block (ram,0xf002fafc) */
/* WARNING: Removing unreachable block (ram,0xf002fb64) */
/* WARNING: Removing unreachable block (ram,0xf002fbac) */
/* WARNING: Removing unreachable block (ram,0xf002fa44) */

undefined8 sub_F002FA30(int param_1,int param_2,int *param_3)

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
  iVar1 = 2;
  _socreate(2,param_3,2,0);
  if (iVar1 == 0) {
    if ((*(word *)(param_1 + 0xc) & 1) == 0) {
      *(word *)(param_2 + 0x10) = *(word *)(param_1 + 0xc) | 0x21;
      iVar1 = *param_3;
      _ifioctl(iVar1,0x80206910,param_2);
      if (iVar1 != 0) goto locret_F002FBD4;
    }
    else if ((int)((uint)*(word *)(param_1 + 0xc) * 0x10000) < 0) {
      iVar1 = *param_3;
      _ifioctl(iVar1,0xc020690d,param_2);
      if (iVar1 == 0) {
        iVar1 = -1;
        *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
      }
      goto locret_F002FBD4;
    }
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x4000;
    _bzero((undefined *)((int)register0x00000038 + -0x18),0x10);
    *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
    *(undefined2 *)(param_2 + 0x10) = 2;
    *(undefined2 *)(param_2 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x16);
    *(undefined2 *)(param_2 + 0x14) = *(undefined2 *)((int)register0x00000038 + -0x14);
    *(undefined2 *)(param_2 + 0x16) = *(undefined2 *)((int)register0x00000038 + -0x12);
    *(undefined2 *)(param_2 + 0x18) = *(undefined2 *)((int)register0x00000038 + -0x10);
    *(undefined2 *)(param_2 + 0x1a) = *(undefined2 *)((int)register0x00000038 + -0xe);
    *(undefined2 *)(param_2 + 0x1c) = *(undefined2 *)((int)register0x00000038 + -0xc);
    *(undefined2 *)(param_2 + 0x1e) = *(undefined2 *)((int)register0x00000038 + -10);
    iVar1 = *param_3;
    _ifioctl(iVar1,0x8020690c,param_2);
    iVar2 = 1;
    if (iVar1 == 0) {
      _m_get(1,8);
      param_2 = iVar2;
      if (iVar2 == 0) {
        iVar1 = 0x37;
      }
      else {
        *(undefined2 *)(iVar2 + 8) = 0x10;
        iVar1 = *(int *)(iVar2 + 4);
        *(undefined2 *)(iVar2 + iVar1) = 2;
        iVar1 = iVar2 + iVar1;
        *(undefined2 *)(iVar1 + 2) = 0x44;
        *(undefined4 *)(iVar1 + 4) = 0;
        iVar1 = *param_3;
        _sobind(iVar1,iVar2);
        _m_freem(iVar2);
        if (iVar1 == 0) {
          iVar1 = 0;
          *(word *)(*param_3 + 6) = *(word *)(*param_3 + 6) | 0x100;
        }
      }
    }
  }
  else {
    *param_3 = 0;
  }
locret_F002FBD4:
  return CONCAT44(param_2,iVar1);
}
