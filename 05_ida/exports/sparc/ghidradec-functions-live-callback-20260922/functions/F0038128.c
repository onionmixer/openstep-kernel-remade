
/* WARNING: Removing unreachable block (ram,0xf00381d8) */
/* WARNING: Removing unreachable block (ram,0xf00381ec) */
/* WARNING: Removing unreachable block (ram,0xf0038150) */

undefined8 _tcp_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar2;
  undefined4 unaff_i2;
  int iVar3;
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
  iVar3 = 0;
  iVar2 = *(int *)(*(int *)(param_2 + 8) + 0x20);
  if (param_3 == 6) {
    if (param_1 == 0) {
      iVar1 = 1;
      _m_get(1,10);
      *param_5 = iVar1;
      *(undefined2 *)(iVar1 + 8) = 4;
      if (param_4 == 1) {
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = *(byte *)(iVar2 + 0x1b) & 4;
      }
      else if (param_4 == 2) {
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)*(word *)(iVar2 + 0x18);
      }
      else {
        iVar3 = 0x16;
      }
    }
    else if (param_1 == 1) {
      iVar1 = *param_5;
      if (param_4 == 1) {
        if (iVar1 == 0) {
          iVar3 = 0x16;
        }
        else if (*(word *)(iVar1 + 8) < 4) {
          iVar3 = 0x16;
        }
        else if (*(int *)(iVar1 + *(int *)(iVar1 + 4)) == 0) {
          *(byte *)(iVar2 + 0x1b) = *(byte *)(iVar2 + 0x1b) & 0xfb;
        }
        else {
          *(byte *)(iVar2 + 0x1b) = *(byte *)(iVar2 + 0x1b) | 4;
        }
      }
      else {
        iVar3 = 0x16;
      }
      if (iVar1 != 0) {
        _m_free(iVar1);
      }
    }
    else {
      iVar3 = 0;
    }
  }
  else {
    _ip_ctloutput(param_1,param_2,param_3,param_4,param_5);
    iVar3 = param_1;
  }
  return CONCAT44(iVar2,iVar3);
}

