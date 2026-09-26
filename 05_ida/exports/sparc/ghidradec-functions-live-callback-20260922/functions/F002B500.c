
/* WARNING: Removing unreachable block (ram,0xf002b6f4) */
/* WARNING: Removing unreachable block (ram,0xf002b6d0) */
/* WARNING: Removing unreachable block (ram,0xf002b688) */
/* WARNING: Removing unreachable block (ram,0xf002b654) */
/* WARNING: Removing unreachable block (ram,0xf002b600) */
/* WARNING: Removing unreachable block (ram,0xf002b5e4) */
/* WARNING: Removing unreachable block (ram,0xf002b584) */
/* WARNING: Removing unreachable block (ram,0xf002b540) */
/* WARNING: Removing unreachable block (ram,0xf002b510) */
/* WARNING: Removing unreachable block (ram,0xf002b524) */
/* WARNING: Removing unreachable block (ram,0xf002b54c) */
/* WARNING: Removing unreachable block (ram,0xf002b5dc) */
/* WARNING: Removing unreachable block (ram,0xf002b664) */
/* WARNING: Removing unreachable block (ram,0xf002b618) */
/* WARNING: Removing unreachable block (ram,0xf002b6a8) */
/* WARNING: Removing unreachable block (ram,0xf002b6bc) */
/* WARNING: Removing unreachable block (ram,0xf002b6e0) */
/* WARNING: Removing unreachable block (ram,0xf002b708) */
/* WARNING: Removing unreachable block (ram,0xf002b504) */

undefined8 sub_F002B500(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined *puVar7;
  byte bVar8;
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
  uVar1 = param_2;
  _if_type();
  _strcmp();
  if ((uVar1 == 0) && (uVar1 = param_2, _if_unit(), uVar1 == *param_1)) {
    uVar2 = param_2;
    _if_name(param_2);
    uVar4 = param_2;
    _if_mtu();
    uVar3 = dword_F010C27C;
    if (param_1[2] != 0) {
      uVar3 = param_1[2];
    }
    if ((int)(uVar4 - 8) < (int)uVar3) {
      uVar3 = uVar4 - 8;
    }
    uVar4 = 0x20;
    _kalloc();
    puVar5 = (uint *)0x0;
    _if_attach(0,dword_F002AD98,sub_F002A97C,sub_F002AD28,sub_F002ABE4,uVar2,uVar1,aInternetProtoc_1
               ,uVar3,2,0x1000,uVar4 & 0xfffffffc);
    puVar6 = puVar5;
    _if_private();
    *puVar6 = 0;
    if ((param_1[1] & 1) == 0) {
      puVar6 = puVar5;
      _if_private();
      *puVar6 = *puVar6 & 0xfffffffe;
    }
    else {
      puVar6 = puVar5;
      _if_private();
      *puVar6 = *puVar6 | 1;
      puVar6 = puVar5;
      _if_private();
      puVar7 = (undefined *)((int)register0x00000038 + -0x18);
      *(code **)((int)register0x00000038 + -0x18) = _SRTablePrototype;
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0xf002a948;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0xf00edfac;
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      _NXCreateHashTable(puVar7,0,0);
      puVar6[1] = (uint)puVar7;
    }
    param_1 = (uint *)param_1[3];
    puVar6 = puVar5;
    if ((int)param_1 < 8) {
      if (6 < ((uint)param_1 & 0xff)) {
        param_1 = (uint *)0x6;
      }
      _if_private();
      bVar8 = (byte)((int)param_1 << 5) | 0x10;
    }
    else {
      _if_private();
      bVar8 = 0x10;
    }
    *(byte *)(puVar6 + 6) = bVar8;
    puVar6 = puVar5;
    _if_private();
    puVar6[5] = param_2;
    _if_private(puVar5);
    _if_control(param_2,&_IFCONTROL_GETADDR,puVar5 + 2);
    _printf(aIpProtocolEnab_0,uVar2,uVar1);
    _printf(aIeee8022NullSa,uVar2,uVar1);
  }
  return CONCAT44(param_2,param_1);
}

