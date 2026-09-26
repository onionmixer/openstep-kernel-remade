
/* WARNING: Removing unreachable block (ram,0xf006bc54) */
/* WARNING: Removing unreachable block (ram,0xf006bc78) */
/* WARNING: Removing unreachable block (ram,0xf006bc08) */
/* WARNING: Removing unreachable block (ram,0xf006bc68) */
/* WARNING: Removing unreachable block (ram,0xf006bc38) */
/* WARNING: Removing unreachable block (ram,0xf006bbc0) */

undefined8 _mach_net_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
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
  uVar1 = 0x14;
  _zinit(0x14,2000,0x14,0,aNetListenerZon);
  dword_F012F684 = 0x11;
  DAT_f012f688._0_4_ = 0x7ec;
  DAT_f012f688._4_4_ = 0;
  DAT_f012f688._8_4_ = 0;
  DAT_f012f688._16_4_ = 0x7a7;
  puVar2 = _listeners;
  _listener_zone = uVar1;
  do {
    *(undefined4 *)puVar2 = 0;
    puVar2 = (undefined *)((int)puVar2 + 8);
  } while (puVar2 < &_mach_net_kmsg_zone);
  uVar1 = 0x800;
  _zinit(0x800,0x2000,0x800,0,aMachNetMessage);
  _mach_net_kmsg_zone = uVar1;
  _zchange();
  _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),0x2000);
  _zcram(_mach_net_kmsg_zone,*(undefined4 *)((int)register0x00000038 + -0xc),0x2000);
  return CONCAT44(param_2,param_1);
}

