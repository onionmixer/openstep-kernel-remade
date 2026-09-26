
/* WARNING: Removing unreachable block (ram,0xf0031cd0) */
/* WARNING: Removing unreachable block (ram,0xf0031c94) */
/* WARNING: Removing unreachable block (ram,0xf0031c78) */
/* WARNING: Removing unreachable block (ram,0xf0031c30) */
/* WARNING: Removing unreachable block (ram,0xf0031b30) */
/* WARNING: Removing unreachable block (ram,0xf0031b04) */
/* WARNING: Removing unreachable block (ram,0xf0031b98) */
/* WARNING: Removing unreachable block (ram,0xf0031c64) */
/* WARNING: Removing unreachable block (ram,0xf0031c84) */
/* WARNING: Removing unreachable block (ram,0xf0031cc4) */
/* WARNING: Removing unreachable block (ram,0xf0031ce4) */
/* WARNING: Removing unreachable block (ram,0xf0031ae8) */

undefined8 _icmp_sendMaskPacket(int param_1,uint param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  bool bVar6;
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
  if (((*(word *)(param_1 + 0xc) & 1) == 0) || ((*(word *)(param_1 + 0xc) & 8) != 0)) {
    param_1 = 0;
    goto locret_F0031CEC;
  }
  iVar2 = param_1;
  _ifptoia();
  iVar3 = 1;
  if (iVar2 == 0) {
    param_1 = 0x33;
    iVar3 = 0;
loc_F0031CD8:
    bVar6 = iVar3 == 0;
  }
  else {
    _m_get(1,2);
    if (iVar3 != 0) {
      *(undefined2 *)(iVar3 + 8) = 0x20;
      *(undefined4 *)(iVar3 + 4) = 0x5c;
      _bzero(iVar3 + 0x5c,(int)*(sword *)(iVar3 + 8));
      *(sword *)(iVar3 + 8) = *(sword *)(iVar3 + 8) + -0x14;
      iVar4 = *(int *)(iVar3 + 4) + 0x14;
      *(int *)(iVar3 + 4) = iVar4;
      iVar5 = iVar3 + iVar4;
      if ((param_2 & 0xff) == 0x12) {
        *(undefined *)(iVar3 + iVar4) = 0x12;
        iVar4 = *(int *)(iVar2 + 0x34);
        *(int *)(iVar5 + 8) = iVar4;
        if (iVar4 == 0) {
          param_1 = 0x16;
          goto loc_F0031CD8;
        }
      }
      else {
        *(undefined *)(iVar3 + iVar4) = 0x11;
      }
      *(undefined *)(iVar5 + 1) = 0;
      *(undefined2 *)(iVar5 + 2) = 0;
      *(undefined4 *)(iVar5 + 4) = 0;
      iVar4 = iVar3;
      _in_cksum(iVar3,0xc);
      *(sword *)(iVar5 + 2) = (sword)iVar4;
      sVar1 = _ip_id;
      *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + -0x14;
      *(sword *)(iVar3 + 8) = *(sword *)(iVar3 + 8) + 0x14;
      _ip_id = _ip_id + 1;
      iVar5 = *(int *)(iVar3 + 4);
      *(uint *)(iVar3 + iVar5) = *(uint *)(iVar3 + iVar5) & 0xffffff | 0x45000000;
      iVar5 = iVar3 + iVar5;
      *(sword *)(iVar5 + 4) = sVar1;
      *(undefined *)(iVar5 + 8) = 0xff;
      *(undefined *)(iVar5 + 9) = 1;
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(iVar5 + 0x10) = 0xffffffff;
      *(undefined2 *)(iVar5 + 2) = 0x20;
      *(undefined2 *)(iVar5 + 10) = 0;
      iVar4 = iVar3;
      _in_cksum(iVar3,0x14);
      *(sword *)(iVar5 + 10) = (sword)iVar4;
      *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
      *(undefined2 *)((int)register0x00000038 + -0x16) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0xffffffff;
      if (0 < param_3) {
        umul(param_3,_hz);
        _timeout(_wakeup,iVar2 + 0x34,param_3);
        _sleep(iVar2 + 0x34,0x19);
      }
      _if_output_mbuf(param_1,iVar3,(undefined *)((int)register0x00000038 + -0x18));
      iVar3 = 0;
      if ((param_2 & 0xff) == 0x11) {
        _timeout(_wakeup,iVar2 + 0x34,_hz);
        _sleep(iVar2 + 0x34,0x19);
      }
      goto loc_F0031CD8;
    }
    param_1 = 0x37;
    bVar6 = true;
  }
  if (!bVar6) {
    _m_freem(iVar3);
  }
locret_F0031CEC:
  return CONCAT44(param_2,param_1);
}

