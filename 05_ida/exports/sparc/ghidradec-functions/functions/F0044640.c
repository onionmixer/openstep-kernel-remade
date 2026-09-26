
/* WARNING: Removing unreachable block (ram,0xf00446f4) */
/* WARNING: Removing unreachable block (ram,0xf00446e0) */
/* WARNING: Removing unreachable block (ram,0xf004472c) */
/* WARNING: Removing unreachable block (ram,0xf004471c) */
/* WARNING: Removing unreachable block (ram,0xf00446bc) */
/* WARNING: Removing unreachable block (ram,0xf00446a8) */
/* WARNING: Removing unreachable block (ram,0xf0044714) */
/* WARNING: Removing unreachable block (ram,0xf0044724) */
/* WARNING: Removing unreachable block (ram,0xf00446d4) */
/* WARNING: Removing unreachable block (ram,0xf00446ec) */
/* WARNING: Removing unreachable block (ram,0xf0044670) */
/* WARNING: Removing unreachable block (ram,0xf004465c) */

undefined8 _ku_sendto_mbuf(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar5;
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
  iVar1 = 1;
  iVar3 = *(int *)(param_1 + 8);
  _Sendtries = _Sendtries + 1;
  _m_get(1,8);
  if (iVar1 == 0) {
    _m_freem(param_2);
    iVar4 = 0x37;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(undefined2 *)(iVar1 + 8) = 0x10;
    *(undefined4 *)(iVar1 + iVar4) = *param_3;
    iVar4 = iVar1 + iVar4;
    *(undefined4 *)(iVar4 + 4) = param_3[1];
    *(undefined4 *)(iVar4 + 8) = param_3[2];
    uVar2 = param_3[3];
    *(undefined4 *)(iVar4 + 0xc) = uVar2;
    _splnet();
    uVar5 = *(undefined4 *)(iVar3 + 0x14);
    iVar4 = iVar3;
    _in_pcbconnect(iVar3,iVar1);
    if (iVar4 == 0) {
      iVar4 = iVar3;
      _udp_output(iVar3,param_2);
      _in_pcbdisconnect(iVar3);
      *(undefined4 *)(iVar3 + 0x14) = uVar5;
      _splx(uVar2);
      _m_free(iVar1);
      _Sendok = _Sendok + 1;
    }
    else {
      _printf(aPcbsetaddrFail,iVar4);
      _splx(uVar2);
      _m_freem(param_2);
      _m_free(iVar1);
    }
  }
  return CONCAT44(param_2,iVar4);
}
