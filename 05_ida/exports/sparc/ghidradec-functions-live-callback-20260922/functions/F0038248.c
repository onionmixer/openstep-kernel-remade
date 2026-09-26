
/* WARNING: Removing unreachable block (ram,0xf00382b4) */
/* WARNING: Removing unreachable block (ram,0xf003829c) */
/* WARNING: Removing unreachable block (ram,0xf00382e0) */
/* WARNING: Removing unreachable block (ram,0xf0038280) */

undefined8 _tcp_attach(int param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  if ((((*(sword *)(param_1 + 0x3e) != 0) && (*(sword *)(param_1 + 0x26) != 0)) ||
      (iVar3 = param_1, _soreserve(param_1,_tcp_sendspace,_tcp_recvspace), iVar3 == 0)) &&
     (iVar3 = param_1, _in_pcballoc(param_1,&_tcb), iVar3 == 0)) {
    iVar2 = *(int *)(param_1 + 8);
    iVar3 = iVar2;
    _tcp_newtcpcb();
    if (iVar3 == 0) {
      wVar1 = *(word *)(param_1 + 6);
      *(word *)(param_1 + 6) = wVar1 & 0xfffe;
      _in_pcbdetach(iVar2);
      iVar3 = 0x37;
      *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | wVar1 & 1;
    }
    else {
      *(undefined2 *)(iVar3 + 8) = 0;
      iVar3 = 0;
    }
  }
  return CONCAT44(param_2,iVar3);
}

