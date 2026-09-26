
/* WARNING: Removing unreachable block (ram,0xf0092614) */
/* WARNING: Removing unreachable block (ram,0xf00925a0) */
/* WARNING: Removing unreachable block (ram,0xf00925f4) */
/* WARNING: Removing unreachable block (ram,0xf009262c) */
/* WARNING: Removing unreachable block (ram,0xf0092550) */

undefined8 _sdstrategy(uint *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined (*pauVar4) [43];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  iVar1 = (int)*(sword *)((int)param_1 + 0x1e);
  sub_F0092E34();
  if (iVar1 == 0) {
    uVar3 = 6;
  }
  else {
    uVar5 = _kernel_map;
    if ((*param_1 & 0x4000010) == 0x10) {
      uVar5 = *(undefined4 *)(*(int *)(param_1[0xb] + 0x68) + 0xc);
    }
    iVar2 = iVar1;
    _objc_msgSend(iVar1,paBlocksize);
    if (iVar2 == 0) {
      uVar3 = 6;
    }
    else {
      pauVar4 = paWriteasyncatLe;
      if ((*param_1 & 1) != 0) {
        pauVar4 = (undefined (*) [43])paReadasyncatLen;
      }
      iVar2 = iVar1;
      _objc_msgSend(iVar1,pauVar4,param_1[9],param_1[5],param_1[8],param_1,uVar5);
      if (iVar2 == 0) {
        uVar5 = 0;
        goto locret_F0092638;
      }
      _objc_msgSend(iVar1,paErrnofromretur,iVar2);
      uVar3 = (undefined2)iVar1;
    }
  }
  *(undefined2 *)(param_1 + 7) = uVar3;
  *param_1 = *param_1 | 4;
  _biodone();
  uVar5 = 0xffffffff;
locret_F0092638:
  return CONCAT44(param_2,uVar5);
}

