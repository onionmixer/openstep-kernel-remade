
/* WARNING: Removing unreachable block (ram,0xf0031984) */
/* WARNING: Removing unreachable block (ram,0xf003195c) */
/* WARNING: Removing unreachable block (ram,0xf0031978) */
/* WARNING: Removing unreachable block (ram,0xf0031998) */
/* WARNING: Removing unreachable block (ram,0xf0031928) */

undefined8 _icmp_reflect(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
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
  
  iVar2 = _in_ifaddr;
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
  iVar3 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
  bVar6 = iVar2 == 0;
  iVar5 = (*param_1 & 0xf) * 4 + -0x14;
  if (!bVar6) {
    iVar1 = *(int *)(iVar2 + 4);
    while (bVar6 = iVar2 == 0, iVar3 != iVar1) {
      if ((*(word *)(*(int *)(iVar2 + 0x20) + 0xc) & 2) == 0) {
        iVar2 = *(int *)(iVar2 + 0x40);
      }
      else {
        bVar6 = iVar2 == 0;
        if (iVar3 == *(int *)(iVar2 + 0x14)) break;
        iVar2 = *(int *)(iVar2 + 0x40);
      }
      if (iVar2 == 0) {
        bVar6 = true;
        break;
      }
      iVar1 = *(int *)(iVar2 + 4);
    }
  }
  if (bVar6) {
    iVar2 = param_2;
    _ifptoia();
  }
  if (iVar2 == 0) {
    uVar4 = *(undefined4 *)(_in_ifaddr + 4);
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 4);
  }
  iVar3 = 0xff;
  *(undefined4 *)(param_1 + 0xc) = uVar4;
  param_1[8] = 0xff;
  iVar2 = 0;
  if (0 < iVar5) {
    _ip_srcroute();
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) - (sword)iVar5;
    _ip_stripoptions(param_1,0);
    iVar2 = iVar3;
  }
  _icmp_send(param_1,iVar2);
  if (iVar2 != 0) {
    _m_free(iVar2);
  }
  return CONCAT44(param_2,param_1);
}
