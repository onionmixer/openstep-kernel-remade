
/* WARNING: Removing unreachable block (ram,0xf001e644) */
/* WARNING: Removing unreachable block (ram,0xf001e600) */
/* WARNING: Removing unreachable block (ram,0xf001e6c8) */
/* WARNING: Removing unreachable block (ram,0xf001e610) */

undefined8 _socreate(sword *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  if (param_4 == 0) {
    _pffindtype(param_1,param_3);
  }
  else {
    _pffindproto(param_1,param_4,param_3);
  }
  if (param_1 == (sword *)0x0) {
    iVar1 = 0x2b;
  }
  else {
    iVar1 = 1;
    if (*param_1 == param_3) {
      _m_getclr(1,3);
      iVar2 = *(int *)(iVar1 + 4);
      iVar3 = iVar1 + iVar2;
      *(undefined2 *)(iVar3 + 2) = 0x20;
      *(undefined2 *)(iVar3 + 6) = 0;
      *(sword *)(iVar1 + iVar2) = (sword)param_3;
      if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
        *(undefined2 *)(iVar3 + 6) = 0x80;
        *(sword **)(iVar3 + 0xc) = param_1;
      }
      else {
        *(sword **)(iVar3 + 0xc) = param_1;
      }
      iVar1 = iVar3;
      (**(code **)(param_1 + 0xe))(iVar3,0,0,param_4,0);
      if (iVar1 == 0) {
        *param_2 = iVar3;
        iVar1 = 0;
      }
      else {
        *(word *)(iVar3 + 6) = *(word *)(iVar3 + 6) | 1;
        _sofree();
      }
    }
    else {
      iVar1 = 0x29;
    }
  }
  return CONCAT44(param_2,iVar1);
}
