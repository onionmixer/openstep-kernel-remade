
/* WARNING: Removing unreachable block (ram,0xf00b19a8) */
/* WARNING: Removing unreachable block (ram,0xf00b1898) */
/* WARNING: Removing unreachable block (ram,0xf00b19d8) */
/* WARNING: Removing unreachable block (ram,0xf00b1878) */

undefined8 _cnopen(undefined2 param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
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
  iVar2 = _cons_tp;
  _ttynty();
  iVar6 = *_active_u;
  iVar3 = (int)*(sword *)(iVar6 + 0x30);
  wVar1 = *(word *)(_cons_tp + 0x38);
  _get_posix_proc();
  iVar4 = _cons_tp;
  if ((*(uint *)(iVar6 + 0x14) & 0x4000) == 0) {
    if ((*(uint *)(iVar6 + 0x28) & 0x40000000) == 0) {
      _active_u[0x59] = _cons_tp;
      *(undefined2 *)(_active_u + 0x5a) = param_1;
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(*(int *)(iVar3 + 0x10) + 8);
      *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + 8) + 8) = iVar4;
      iVar4 = (int)*(sword *)(iVar4 + 0x44);
      if (iVar4 == 0) {
        _enterpgrp(iVar6,(int)*(sword *)(iVar6 + 0x30),0);
        iVar4 = _cons_tp;
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0x10);
        *(sword *)(iVar4 + 0x44) = (sword)*(undefined4 *)(*(int *)(iVar3 + 0x10) + 0xc);
      }
      else if (iVar4 != *(sword *)(iVar6 + 0x2e)) {
        _enterpgrp(iVar6,iVar4,0);
      }
    }
  }
  else {
    iVar5 = *(int *)(*(int *)(iVar3 + 0x10) + 8);
    if ((((*(int *)(iVar5 + 4) == iVar6) && (*(int *)(iVar5 + 8) == 0)) &&
        (*(int *)(iVar2 + 8) == 0)) && ((*(uint *)(iVar3 + 0x18) & 0x40000000) == 0)) {
      _active_u[0x59] = _cons_tp;
      *(undefined2 *)(_active_u + 0x5a) = param_1;
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(*(int *)(iVar3 + 0x10) + 8);
      *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + 8) + 8) = iVar4;
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0x10);
      *(sword *)(iVar4 + 0x44) = (sword)*(undefined4 *)(*(int *)(iVar3 + 0x10) + 0xc);
      *(uint *)(iVar6 + 0x28) = *(uint *)(iVar6 + 0x28) | 0x40000000;
    }
  }
  iVar4 = (int)(sword)wVar1;
  (**(code **)(_cdevsw + (uint)(wVar1 >> 8) * 0x2c))(iVar4,param_2);
  return CONCAT44(param_2,iVar4);
}

