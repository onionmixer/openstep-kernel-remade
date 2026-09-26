
/* WARNING: Removing unreachable block (ram,0xf0044fbc) */
/* WARNING: Removing unreachable block (ram,0xf0044f64) */
/* WARNING: Removing unreachable block (ram,0xf0044f58) */
/* WARNING: Removing unreachable block (ram,0xf0044fb0) */
/* WARNING: Removing unreachable block (ram,0xf0044fec) */
/* WARNING: Removing unreachable block (ram,0xf0044f48) */

undefined8 _svckudp_recv(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  iVar3 = param_1[0xc];
  iVar1 = _rsstat + 1;
  _rsstat = iVar1;
  _splnet();
  iVar2 = *param_1;
  _ku_recvfrom(iVar2,param_1 + 4);
  _splx(iVar1);
  iVar1 = iVar3 + 0xc;
  if (iVar2 == 0) {
    uVar4 = 0;
    DAT_f013ad18._0_4_ = DAT_f013ad18._0_4_ + 1;
  }
  else {
    if (*(word *)(iVar2 + 8) < 0x10) {
      DAT_f013ad18._4_4_ = DAT_f013ad18._4_4_ + 1;
    }
    else {
      _xdrmbuf_init(iVar1,iVar2,1);
      _xdr_callmsg(iVar1,param_2);
      uVar4 = 1;
      if (iVar1 != 0) {
        *(undefined4 *)(iVar3 + 4) = *param_2;
        *(int *)(iVar3 + 8) = iVar2;
        goto locret_F0045010;
      }
      DAT_f013ad18._8_4_ = DAT_f013ad18._8_4_ + 1;
    }
    _m_freem(iVar2);
    *(undefined4 *)(iVar3 + 8) = 0;
    uVar4 = 0;
    DAT_f013ad14._0_4_ = DAT_f013ad14._0_4_ + 1;
  }
locret_F0045010:
  return CONCAT44(param_2,uVar4);
}

