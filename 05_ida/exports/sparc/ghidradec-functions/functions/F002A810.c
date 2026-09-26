
/* WARNING: Removing unreachable block (ram,0xf002a8d4) */
/* WARNING: Removing unreachable block (ram,0xf002a8b0) */
/* WARNING: Removing unreachable block (ram,0xf002a84c) */
/* WARNING: Removing unreachable block (ram,0xf002a834) */
/* WARNING: Removing unreachable block (ram,0xf002a820) */
/* WARNING: Removing unreachable block (ram,0xf002a840) */
/* WARNING: Removing unreachable block (ram,0xf002a8a8) */
/* WARNING: Removing unreachable block (ram,0xf002a8c4) */
/* WARNING: Removing unreachable block (ram,0xf002a8f0) */
/* WARNING: Removing unreachable block (ram,0xf002a814) */

undefined8 sub_F002A810(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
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
  iVar1 = param_2;
  _if_type();
  _strcmp();
  if (iVar1 == 0) {
    uVar2 = 0x10;
    _kalloc();
    iVar1 = param_2;
    _if_name(param_2);
    iVar3 = param_2;
    _if_unit();
    iVar4 = 0;
    _if_attach(0,sub_F002A640,sub_F002A26C,sub_F002A610,sub_F002A39C,iVar1,iVar3,aInternetProtoc_0,
               0x5dc,2,0x1000,uVar2);
    iVar5 = iVar4;
    _if_private();
    *(int *)(iVar5 + 0xc) = param_2;
    _if_private(iVar4);
    _if_control(param_2,&_IFCONTROL_GETADDR,iVar4);
    _printf(aIpProtocolEnab,iVar1,iVar3,a10mbEthernet_1);
  }
  return CONCAT44(param_2,param_1);
}
