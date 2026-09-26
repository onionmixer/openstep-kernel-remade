
/* WARNING: Removing unreachable block (ram,0xf00374cc) */
/* WARNING: Removing unreachable block (ram,0xf00374b0) */

undefined8 _tcp_newtcpcb(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
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
  iVar3 = 0x6c;
  _kalloc();
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    _bzero(iVar3,0x6c);
    *(int *)(iVar3 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(iVar3 + 0x20) = param_1;
    *(undefined2 *)(iVar3 + 100) = 2;
    *(undefined2 *)(iVar3 + 0x14) = 0xc;
    *(undefined2 *)(iVar3 + 0x54) = 0xffff;
    *(undefined2 *)(iVar3 + 0x56) = 0xffff;
    uVar1 = _tcp_mssdflt;
    *(undefined2 *)(iVar3 + 0x60) = 0;
    *(undefined *)(iVar3 + 0x1b) = 0;
    iVar2 = _tcp_rttdflt;
    *(sword *)(iVar3 + 0x18) = (sword)uVar1;
    *(sword *)(iVar3 + 0x62) = (sword)(iVar2 << 3);
    *(int *)(param_1 + 0x20) = iVar3;
  }
  return CONCAT44(param_2,iVar3);
}

