/* GHIDRADEC_FUNCTION index=1450 start=0xf006b8d4 */

/* WARNING: Removing unreachable block (ram,0xf006b988) */
/* WARNING: Removing unreachable block (ram,0xf006b948) */
/* WARNING: Removing unreachable block (ram,0xf006b930) */
/* WARNING: Removing unreachable block (ram,0xf006b964) */
/* WARNING: Removing unreachable block (ram,0xf006b998) */
/* WARNING: Removing unreachable block (ram,0xf006b910) */

undefined8
_netipc_listen(undefined4 param_1,undefined *param_2,undefined4 param_3,undefined2 param_4,
              undefined2 param_5,uint param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  int *piVar6;
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
  iVar4 = *(int *)((int)register0x00000038 + 0x5c);
  if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
    if (iVar4 == 0) {
      uVar5 = 4;
    }
    else {
      puVar1 = _listener_zone;
      _zalloc();
      puVar1[1] = param_2;
      *(undefined2 *)(puVar1 + 3) = param_4;
      puVar1[2] = param_3;
      *(undefined2 *)((int)puVar1 + 0xe) = param_5;
      puVar1[4] = iVar4;
      _ipc_object_reference(iVar4);
      iVar3 = (param_6 & 0xf) * 8;
      param_2 = _listeners;
      piVar6 = (int *)(_listeners + iVar3);
      _splnet();
      do {
        do {
        } while (*piVar6 != 0);
        piVar2 = piVar6;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      *puVar1 = *(undefined4 *)(_listeners + iVar3 + 4);
      *(undefined4 **)(_listeners + iVar3 + 4) = puVar1;
      *piVar6 = 0;
      _splx(param_2);
      _ipc_kobject_set(iVar4,0,0x11);
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 8;
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1451 start=0xf006b9ac */

/* WARNING: Removing unreachable block (ram,0xf006ba84) */
/* WARNING: Removing unreachable block (ram,0xf006ba78) */
/* WARNING: Removing unreachable block (ram,0xf006ba00) */
/* WARNING: Removing unreachable block (ram,0xf006ba50) */
/* WARNING: Removing unreachable block (ram,0xf006baa8) */
/* WARNING: Removing unreachable block (ram,0xf006b9e4) */

undefined8 _netipc_ignore(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l1;
  undefined *puVar7;
  undefined4 unaff_l3;
  int *piVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
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
  uVar9 = 5;
  if (param_2 == 0) {
    uVar9 = 4;
  }
  else {
    puVar7 = _listeners;
    puVar2 = &_mach_net_kmsg_zone;
    piVar8 = (int *)(_listeners + 4);
    do {
      _splnet();
      do {
        do {
        } while (*(int *)puVar7 != 0);
        piVar4 = (int *)puVar7;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      piVar4 = (int *)*piVar8;
      if (piVar4 != (int *)0x0) {
        iVar3 = piVar4[4];
        piVar5 = piVar4;
        do {
          uVar1 = _listener_zone;
          if (iVar3 == param_2) {
            uVar9 = 0;
            if (piVar5 == (int *)*piVar8) {
              *piVar8 = *piVar5;
              _zfree(uVar1,piVar5);
              piVar4 = (int *)*piVar8;
              if (piVar4 == (int *)0x0) break;
            }
            else {
              *piVar4 = *piVar5;
              _zfree(uVar1,piVar5);
            }
            _ipc_object_release(param_2);
            piVar6 = (int *)*piVar4;
          }
          else {
            piVar6 = (int *)*piVar5;
            piVar4 = piVar5;
          }
          if (piVar6 == (int *)0x0) break;
          iVar3 = piVar6[4];
          piVar5 = piVar6;
        } while( true );
      }
      *(int *)puVar7 = 0;
      _splx(puVar2);
      puVar7 = (undefined *)((int)puVar7 + 8);
      piVar8 = piVar8 + 2;
    } while (puVar7 < &_mach_net_kmsg_zone);
  }
  return CONCAT44(param_2,uVar9);
}
/* GHIDRADEC_FUNCTION index=1452 start=0xf006bac8 */

undefined8 _find_listener(int param_1,uint param_2,int param_3,uint param_4,uint param_5)

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
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  int iVar3;
  undefined4 unaff_i5;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
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
  iVar3 = (param_5 & 0xf) * 8;
  puVar4 = *(undefined4 **)(DAT_f013c124 + iVar3);
  if (puVar4 != (undefined4 *)0x0) {
    wVar1 = *(word *)((int)puVar4 + 0xe);
    puVar5 = puVar4;
    while( true ) {
      if (((((wVar1 == 0) || ((uint)wVar1 == (param_4 & 0xffff))) &&
           ((*(word *)(puVar5 + 3) == 0 || ((uint)*(word *)(puVar5 + 3) == (param_2 & 0xffff))))) &&
          ((puVar5[1] == 0 || (puVar5[1] == param_1)))) &&
         ((puVar5[2] == 0 || (puVar5[2] == param_3)))) {
        if (puVar5 == *(undefined4 **)(DAT_f013c124 + iVar3)) {
          uVar2 = puVar5[4];
        }
        else {
          *puVar4 = *puVar5;
          *puVar5 = *(undefined4 *)(DAT_f013c124 + iVar3);
          *(undefined4 **)(DAT_f013c124 + iVar3) = puVar5;
          uVar2 = puVar5[4];
        }
        goto locret_F006BBA0;
      }
      puVar6 = (undefined4 *)*puVar5;
      if (puVar6 == (undefined4 *)0x0) break;
      wVar1 = *(word *)((int)puVar6 + 0xe);
      puVar4 = puVar5;
      puVar5 = puVar6;
    }
  }
  uVar2 = 0;
locret_F006BBA0:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1453 start=0xf006bba8 */

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
/* GHIDRADEC_FUNCTION index=1454 start=0xf006bc88 */

/* WARNING: Removing unreachable block (ram,0xf006bc94) */

undefined8 _netipc_msg_release(undefined4 param_1,undefined4 param_2)

{
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
  _zfree(_mach_net_kmsg_zone,param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1455 start=0xf006bca4 */

/* WARNING: Removing unreachable block (ram,0xf006bd50) */
/* WARNING: Removing unreachable block (ram,0xf006be48) */
/* WARNING: Removing unreachable block (ram,0xf006bdd0) */
/* WARNING: Removing unreachable block (ram,0xf006bd30) */
/* WARNING: Removing unreachable block (ram,0xf006bcf0) */
/* WARNING: Removing unreachable block (ram,0xf006bd1c) */
/* WARNING: Removing unreachable block (ram,0xf006bd3c) */
/* WARNING: Removing unreachable block (ram,0xf006bdd8) */
/* WARNING: Removing unreachable block (ram,0xf006be5c) */
/* WARNING: Removing unreachable block (ram,0xf006be64) */
/* WARNING: Removing unreachable block (ram,0xf006bcc8) */

undefined8 _receive_ip_datagram(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  byte *pbVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  uint uVar8;
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
  iVar4 = *param_1;
  pbVar6 = (byte *)(iVar4 + *(int *)(iVar4 + 4));
  if (5 < (*(byte *)(iVar4 + *(int *)(iVar4 + 4)) & 0xf)) {
    _ip_stripoptions(pbVar6,0);
  }
  if ((*(uint *)(iVar4 + 4) < 0x7d) && (0x17 < *(word *)(iVar4 + 8))) {
loc_F006BD0C:
    iVar2 = *(int *)(pbVar6 + 0xc);
    _find_listener(iVar2,*(undefined2 *)(pbVar6 + 0x14),*(undefined4 *)(pbVar6 + 0x10),
                   *(undefined2 *)(pbVar6 + 0x16),pbVar6[9]);
    uVar7 = 0;
    if (iVar2 == 0) goto locret_F006BE70;
    _spl0();
    iVar3 = _mach_net_kmsg_zone;
    _zget();
    if (iVar3 == 0) {
      _m_freem(iVar4);
    }
    else {
      *(undefined4 *)(iVar3 + 8) = 0xfffffffd;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      uVar5 = 0x7d4;
      *(word *)(pbVar6 + 2) = *(sword *)(pbVar6 + 2) + (*pbVar6 & 0xf) * 4;
      *(sword *)(pbVar6 + 6) = *(sword *)(pbVar6 + 6) >> 3;
      iVar1 = iVar3 + 0x2c;
      while (iVar4 != 0) {
        if ((int)uVar5 < 1) {
          *(uint *)(iVar3 + 0x10) = uVar5;
          goto loc_F006BDF0;
        }
        uVar8 = (int)*(sword *)(iVar4 + 8);
        if ((int)uVar5 < (int)*(sword *)(iVar4 + 8)) {
          uVar8 = uVar5;
        }
        uVar5 = uVar5 - uVar8;
        _bcopy(iVar4 + *(int *)(iVar4 + 4),iVar1);
        _m_free();
        iVar1 = iVar1 + uVar8;
      }
      *(uint *)(iVar3 + 0x10) = uVar5;
loc_F006BDF0:
      *(uint *)(iVar3 + 0x10) = (uVar5 & 0xfffffffc) - *(int *)(iVar3 + 0x10);
      *(undefined4 *)(iVar3 + 0x14) = dword_F012F684;
      *(undefined4 *)(iVar3 + 0x18) = DAT_f012f688._0_4_;
      *(undefined4 *)(iVar3 + 0x1c) = DAT_f012f688._4_4_;
      *(undefined4 *)(iVar3 + 0x20) = DAT_f012f688._8_4_;
      *(undefined4 *)(iVar3 + 0x24) = DAT_f012f688._12_4_;
      *(undefined4 *)(iVar3 + 0x28) = DAT_f012f688._16_4_;
      *(uint *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) - (uVar5 & 0xfffffffc);
      *(int *)(iVar3 + 0x1c) = iVar2;
      _ipc_object_reference();
      _ipc_mqueue_send(iVar3,0x10000,0,0);
    }
    _splnet();
  }
  else {
    _m_pullup(iVar4,0x18);
    *param_1 = iVar4;
    if (iVar4 != 0) {
      pbVar6 = (byte *)(iVar4 + *(int *)(iVar4 + 4));
      goto loc_F006BD0C;
    }
  }
  uVar7 = 1;
locret_F006BE70:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=1456 start=0xf006be78 */

sqword _xxx_host_info(undefined4 param_1,undefined4 *param_2)

{
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
  *param_2 = _machine_info;
  param_2[1] = DAT_f013c044;
  param_2[2] = dword_F013C048;
  param_2[3] = DAT_f013c04c;
  param_2[4] = dword_F013C050;
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=1457 start=0xf006beb4 */

undefined8 _xxx_slot_info(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  uVar2 = 4;
  if ((-1 < param_2) && (param_2 < 1)) {
    iVar1 = param_2 * 0x20;
    *param_3 = (&_machine_slot)[param_2 * 8];
    param_3[1] = (&dword_F0134764)[param_2 * 8];
    param_3[2] = (&dword_F0134768)[param_2 * 8];
    param_3[3] = (&dword_F013476C)[param_2 * 8];
    param_3[4] = *(undefined4 *)(DAT_f0134770 + iVar1);
    param_3[5] = *(undefined4 *)(DAT_f0134770 + iVar1 + 4);
    param_3[6] = *(undefined4 *)(DAT_f0134770 + iVar1 + 8);
    uVar2 = 0;
    param_3[7] = *(undefined4 *)(DAT_f0134770 + iVar1 + 0xc);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1458 start=0xf006bf24 */

undefined8 _xxx_cpu_control(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,5);
}
/* GHIDRADEC_FUNCTION index=1459 start=0xf006bf30 */

/* WARNING: Removing unreachable block (ram,0xf006bfd4) */
/* WARNING: Removing unreachable block (ram,0xf006bf70) */
/* WARNING: Removing unreachable block (ram,0xf006bf8c) */
/* WARNING: Removing unreachable block (ram,0xf006bfe4) */
/* WARNING: Removing unreachable block (ram,0xf006bf5c) */

undefined8 _cpu_up(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar3 = (&_processor_ptr)[param_1];
  do {
    do {
    } while (unk_F0135118._0_4_ != 0);
    puVar1 = unk_F0135118;
    _simple_lock_try();
  } while (puVar1 == (undefined *)0x0);
  _splusclock();
  do {
    do {
    } while (*(int *)(iVar3 + 0x13c) != 0);
    piVar2 = (int *)(iVar3 + 0x13c);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  (&dword_F013476C)[param_1 * 8] = 1;
  DAT_f013c04c = DAT_f013c04c + 1;
  _pset_add_processor(_default_pset,iVar3);
  *(undefined4 *)(iVar3 + 0x114) = 1;
  *(undefined4 *)(iVar3 + 0x13c) = 0;
  _splx(puVar1);
  unk_F0135118._0_4_ = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1460 start=0xf006bff8 */

/* WARNING: Removing unreachable block (ram,0xf006c02c) */
/* WARNING: Removing unreachable block (ram,0xf006c070) */
/* WARNING: Removing unreachable block (ram,0xf006bffc) */

undefined8 _cpu_down(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar1 = param_1;
  _splusclock();
  iVar3 = (&_processor_ptr)[param_1];
  do {
    do {
    } while (*(int *)(iVar3 + 0x13c) != 0);
    piVar2 = (int *)(iVar3 + 0x13c);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  (&dword_F013476C)[param_1 * 8] = 0;
  DAT_f013c04c = DAT_f013c04c + -1;
  *(undefined4 *)(iVar3 + 0x130) = 0;
  *(undefined4 *)(iVar3 + 0x114) = 0;
  *(undefined4 *)(iVar3 + 0x13c) = 0;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1461 start=0xf006c080 */

undefined8 _processor_assign(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,5);
}
/* GHIDRADEC_FUNCTION index=1462 start=0xf006c08c */

/* WARNING: Removing unreachable block (ram,0xf006c124) */
/* WARNING: Removing unreachable block (ram,0xf006c0d8) */
/* WARNING: Removing unreachable block (ram,0xf006c164) */
/* WARNING: Removing unreachable block (ram,0xf006c0b0) */

undefined8 _mfs_init(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
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
  dword_F013C21C = &_vm_info_queue;
  _vm_info_queue = &_vm_info_queue;
  _vm_info_lock_data = 0;
  _lock_init(_mfs_alloc_lock_data,1);
  _mfs_alloc_wanted = 0;
  uVar2 = _kernel_map;
  _kmem_suballoc(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10),_mfs_map_size,1);
  _mfs_map_size = dword_F013C050;
  if (0x1000000 < dword_F013C050) {
    _mfs_map_size = 0x1000000;
  }
  _mfs_map = uVar2;
  if (_mfs_max_window == 0) {
    uVar1 = _mfs_map_size;
    .udiv(_mfs_map_size,0x14);
    _mfs_max_window = uVar1;
  }
  if (_mfs_max_window < 0x10000) {
    _mfs_max_window = 0x10000;
  }
  uVar2 = 0x3c;
  _zinit(0x3c,600000,0x2000,0,aVmInfoZone);
  _vm_info_zone = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1463 start=0xf006c17c */

/* WARNING: Removing unreachable block (ram,0xf006c1f0) */
/* WARNING: Removing unreachable block (ram,0xf006c194) */

undefined8 _vm_info_init(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 *puVar1;
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
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = _vm_info_zone;
    _zalloc();
    *puVar1 = 0;
  }
  else {
    *puVar1 = 0;
  }
  *(undefined2 *)(puVar1 + 1) = 0;
  *(undefined2 *)((int)puVar1 + 6) = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[5] = 0;
  puVar1[0xe] = puVar1[0xe] & 0x37ffffff | 0x20000000;
  _lock_init(puVar1 + 6,1);
  puVar1[9] = 0;
  *param_1 = puVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1464 start=0xf006c208 */

undefined8 _vm_info_enqueue(int param_1)

{
  int iVar1;
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
  iVar1 = param_1;
  if (dword_F013C21C != &_vm_info_queue) {
    dword_F013C21C[10] = param_1;
    iVar1 = _vm_info_queue;
  }
  _vm_info_queue = iVar1;
  *(undefined4 **)(param_1 + 0x2c) = dword_F013C21C;
  *(int **)(param_1 + 0x28) = &_vm_info_queue;
  dword_F013C21C = (undefined4 *)param_1;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x80000000;
  _mfs_files_mapped = _mfs_files_mapped + 1;
  _vm_info_version = _vm_info_version + 1;
  return CONCAT44(&_mtime,_mfs_files_mapped);
}
/* GHIDRADEC_FUNCTION index=1465 start=0xf006c27c */

undefined8 _vm_info_dequeue(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(param_1 + 0x28);
  puVar2 = *(undefined4 **)(param_1 + 0x2c);
  puVar1 = puVar2;
  if ((undefined4 **)puVar3 != &_vm_info_queue) {
    puVar3[0xb] = puVar2;
    puVar1 = dword_F013C21C;
  }
  dword_F013C21C = puVar1;
  if ((undefined4 **)puVar2 != &_vm_info_queue) {
    puVar2[10] = puVar3;
    puVar3 = _vm_info_queue;
  }
  _vm_info_queue = puVar3;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0x7fffffff;
  _mfs_files_mapped = _mfs_files_mapped + -1;
  _vm_info_version = _vm_info_version + 1;
  return 0xf010fc00f010fc00;
}
/* GHIDRADEC_FUNCTION index=1466 start=0xf006c2f4 */

/* WARNING: Removing unreachable block (ram,0xf006c414) */
/* WARNING: Removing unreachable block (ram,0xf006c3c0) */
/* WARNING: Removing unreachable block (ram,0xf006c390) */
/* WARNING: Removing unreachable block (ram,0xf006c354) */
/* WARNING: Removing unreachable block (ram,0xf006c338) */
/* WARNING: Removing unreachable block (ram,0xf006c34c) */
/* WARNING: Removing unreachable block (ram,0xf006c384) */
/* WARNING: Removing unreachable block (ram,0xf006c3a4) */
/* WARNING: Removing unreachable block (ram,0xf006c3cc) */
/* WARNING: Removing unreachable block (ram,0xf006c41c) */
/* WARNING: Removing unreachable block (ram,0xf006c328) */

undefined8 _map_vnode(undefined4 *param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
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
  puVar5 = (undefined4 *)*param_1;
  wVar1 = *(word *)(puVar5 + 1);
  *(word *)(puVar5 + 1) = wVar1 + 1;
  if (((int)((uint)wVar1 * 0x10000) < 1) && ((puVar5[0xe] & 0x8000000) == 0)) {
    _vmp_get(puVar5);
    puVar2 = param_1;
    _vnode_pager_setup(param_1,0,1);
    *puVar5 = puVar2;
    _lock_write(_vm_alloc_lock);
    puVar3 = puVar2;
    _vm_object_lookup();
    puVar5[9] = puVar3;
    DAT_f013c26c._0_4_ = DAT_f013c26c._0_4_ + 1;
    if (puVar5[9] == 0) {
      uVar4 = 0;
      _vm_object_allocate();
      puVar5[9] = uVar4;
      _vm_object_enter();
      _vm_object_setpager(puVar5[9],puVar2,0,0);
    }
    else {
      DAT_f013c26c._4_4_ = DAT_f013c26c._4_4_ + 1;
    }
    _lock_done(_vm_alloc_lock);
    puVar5[0xd] = 0;
    puVar2 = param_1;
    _vnode_size();
    puVar5[5] = puVar2;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[0xe] = puVar5[0xe] | 0x8000000;
    if ((puVar5[5] != 0) && ((uint)puVar5[5] < _mfs_max_window)) {
      _remap_vnode(param_1,0);
    }
    _vmp_put(puVar5);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1467 start=0xf006c42c */

/* WARNING: Removing unreachable block (ram,0xf006c534) */
/* WARNING: Removing unreachable block (ram,0xf006c4f0) */
/* WARNING: Removing unreachable block (ram,0xf006c4d4) */
/* WARNING: Removing unreachable block (ram,0xf006c504) */
/* WARNING: Removing unreachable block (ram,0xf006c494) */
/* WARNING: Removing unreachable block (ram,0xf006c4cc) */

undefined8 _unmap_vnode(int *param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  word wVar4;
  int *piVar3;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
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
  iVar6 = *param_1;
  if ((*(uint *)(iVar6 + 0x38) & 0x8000000) != 0) {
    sVar1 = *(sword *)(iVar6 + 4);
    wVar4 = sVar1 - 1;
    *(word *)(iVar6 + 4) = wVar4;
    if ((int)((uint)wVar4 * 0x10000) < 1) {
      *(sword *)(iVar6 + 4) = sVar1;
      (**(code **)(param_1[7] + 0x7c))(param_1,(undefined *)((int)register0x00000038 + -0xc));
      sVar1 = *(sword *)(iVar6 + 4);
      iVar5 = *(int *)((int)register0x00000038 + -0xc);
      *(sword *)(iVar6 + 4) = sVar1 + -1;
      if (iVar5 == 0) {
        _mfs_memfree(iVar6,0);
      }
      else {
        iVar5 = *(int *)(iVar6 + 0x24);
        if ((_close_flush != 0) || ((*(uint *)(iVar6 + 0x38) & 0x20000000) != 0)) {
          *(sword *)(iVar6 + 4) = sVar1;
          _vmp_get(iVar6);
          _vmp_push(iVar6);
        }
        do {
          do {
            param_1 = (int *)(iVar5 + 0x10);
          } while (*param_1 != 0);
          piVar3 = param_1;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        _vm_object_deactivate_pages(iVar5);
        iVar2 = _close_flush;
        *(undefined4 *)(iVar5 + 0x10) = 0;
        if ((iVar2 != 0) || ((*(uint *)(iVar6 + 0x38) & 0x20000000) != 0)) {
          _vmp_put(iVar6);
          *(sword *)(iVar6 + 4) = *(sword *)(iVar6 + 4) + -1;
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1468 start=0xf006c550 */

/* WARNING: Removing unreachable block (ram,0xf006c69c) */
/* WARNING: Removing unreachable block (ram,0xf006c654) */
/* WARNING: Removing unreachable block (ram,0xf006c68c) */
/* WARNING: Removing unreachable block (ram,0xf006c63c) */
/* WARNING: Removing unreachable block (ram,0xf006c6c0) */
/* WARNING: Removing unreachable block (ram,0xf006c5f0) */
/* WARNING: Removing unreachable block (ram,0xf006c5d4) */
/* WARNING: Removing unreachable block (ram,0xf006c6b4) */
/* WARNING: Removing unreachable block (ram,0xf006c61c) */
/* WARNING: Removing unreachable block (ram,0xf006c678) */
/* WARNING: Removing unreachable block (ram,0xf006c694) */
/* WARNING: Removing unreachable block (ram,0xf006c660) */
/* WARNING: Removing unreachable block (ram,0xf006c6c8) */
/* WARNING: Removing unreachable block (ram,0xf006c570) */

undefined8 _remap_vnode(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar6;
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
  param_1 = (undefined4 *)*param_1;
  if (param_1[3] != 0) {
    _mfs_map_remove(param_1,param_1[2],param_1[2] + param_1[3],1);
  }
  uVar5 = (uint)param_2 & ~_page_mask;
  uVar6 = ((int)param_2 + _page_mask + param_3 & ~_page_mask) - uVar5;
  if (uVar6 < 0x10000) {
    uVar6 = 0x10000;
  }
  do {
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(_mfs_map + 0x14);
    _lock_write(_mfs_alloc_lock_data);
    iVar2 = _mfs_map;
    _vm_allocate_with_pager
              (_mfs_map,(undefined *)((int)register0x00000038 + -0xc),uVar6,1,*param_1,uVar5);
    if (iVar2 == 3) {
      do {
        do {
        } while (_vm_info_lock_data != 0);
        puVar3 = &_vm_info_lock_data;
        _simple_lock_try();
        puVar1 = _vm_info_queue;
      } while (puVar3 == (undefined4 *)0x0);
      param_2 = (undefined4 *)0x0;
      if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
        _vm_info_dequeue();
        param_2 = puVar1;
      }
      _vm_info_lock_data = 0;
      if (param_2 == (undefined4 *)0x0) {
        _mfs_alloc_wanted = 1;
        _assert_wait(&_mfs_map,0);
        _mfs_alloc_blocks = _mfs_alloc_blocks + 1;
        _lock_done(_mfs_alloc_lock_data);
        _thread_block();
      }
      else {
        _lock_done(_mfs_alloc_lock_data);
        _mfs_memfree(param_2,1);
      }
      _lock_write(_mfs_alloc_lock_data);
    }
    else if (iVar2 != 0) {
      _printf(aUnexpectedErro,iVar2);
      _panic(aRemapVnode);
    }
    _lock_done(_mfs_alloc_lock_data);
  } while (iVar2 != 0);
  param_1[3] = uVar6;
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  param_1[4] = uVar5;
  param_1[2] = uVar4;
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=1469 start=0xf006c6f4 */

/* WARNING: Removing unreachable block (ram,0xf006c804) */
/* WARNING: Removing unreachable block (ram,0xf006c7c8) */
/* WARNING: Removing unreachable block (ram,0xf006c764) */
/* WARNING: Removing unreachable block (ram,0xf006c784) */
/* WARNING: Removing unreachable block (ram,0xf006c7e0) */
/* WARNING: Removing unreachable block (ram,0xf006c818) */
/* WARNING: Removing unreachable block (ram,0xf006c71c) */

undefined8 _mfs_trunc(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  iVar2 = *param_1;
  if ((*(uint *)(iVar2 + 0x38) & 0x8000000) == 0) {
    *(uint *)(iVar2 + 0x14) = param_2;
    uVar6 = 0;
  }
  else {
    _vmp_get(iVar2);
    uVar3 = param_2 + _page_mask & ~_page_mask;
    uVar5 = 0;
    if (*(uint *)(iVar2 + 0x10) <= uVar3) {
      uVar5 = uVar3 - *(uint *)(iVar2 + 0x10);
    }
    if (uVar5 < *(uint *)(iVar2 + 0xc)) {
      _mfs_map_remove(iVar2,*(int *)(iVar2 + 8) + uVar5,*(int *)(iVar2 + 8) + *(uint *)(iVar2 + 0xc)
                      ,0);
      *(uint *)(iVar2 + 0xc) = uVar5;
    }
    if (uVar3 < *(uint *)(iVar2 + 0x14)) {
      _vno_flush(param_1,uVar3,*(uint *)(iVar2 + 0x14) - uVar3);
    }
    *(uint *)(iVar2 + 0x14) = param_2;
    if (param_2 != uVar3) {
      iVar4 = uVar3 - param_2;
      if ((param_2 < *(uint *)(iVar2 + 0x10)) ||
         (*(uint *)(iVar2 + 0x10) + *(int *)(iVar2 + 0xc) < param_2 + iVar4)) {
        _remap_vnode(param_1,param_2,iVar4);
        iVar1 = *(int *)(iVar2 + 8);
      }
      else {
        iVar1 = *(int *)(iVar2 + 8);
      }
      _bzero((iVar1 + param_2) - *(int *)(iVar2 + 0x10),iVar4);
      *(sword *)(iVar2 + 4) = *(sword *)(iVar2 + 4) + 1;
      *(uint *)(iVar2 + 0x38) = *(uint *)(iVar2 + 0x38) | 0x40000000;
      _vmp_push(iVar2);
      *(sword *)(iVar2 + 4) = *(sword *)(iVar2 + 4) + -1;
    }
    _vmp_put(iVar2);
    uVar6 = 1;
  }
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1470 start=0xf006c82c */

/* WARNING: Removing unreachable block (ram,0xf006c864) */
/* WARNING: Removing unreachable block (ram,0xf006c834) */

undefined8 _mfs_get(int *param_1,undefined4 param_2,uint param_3)

{
  undefined4 unaff_l0;
  int iVar1;
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
  iVar1 = *param_1;
  _vmp_get(iVar1);
  if (_mfs_max_window < param_3) {
    param_3 = _mfs_max_window;
  }
  if (*(uint *)(iVar1 + 0xc) < param_3) {
    _remap_vnode(param_1,param_2,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1471 start=0xf006c874 */

/* WARNING: Removing unreachable block (ram,0xf006c878) */

undefined8 _mfs_put(undefined4 *param_1,undefined4 param_2)

{
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
  _vmp_put(*param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1472 start=0xf006c888 */

/* WARNING: Removing unreachable block (ram,0xf006c8c8) */
/* WARNING: Removing unreachable block (ram,0xf006c8e4) */
/* WARNING: Removing unreachable block (ram,0xf006c8a4) */

undefined8 _vmp_get(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  sword sVar2;
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
  do {
    do {
    } while (_vm_info_lock_data != 0);
    puVar1 = &_vm_info_lock_data;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  if (*(int *)(param_1 + 0x38) < 0) {
    _vm_info_dequeue(param_1);
    sVar2 = *(sword *)(param_1 + 6);
  }
  else {
    sVar2 = *(sword *)(param_1 + 6);
  }
  *(sword *)(param_1 + 6) = sVar2 + 1;
  _vm_info_lock_data = 0;
  _lock_write(param_1 + 0x18);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1473 start=0xf006c8f4 */

/* WARNING: Removing unreachable block (ram,0xf006c974) */
/* WARNING: Removing unreachable block (ram,0xf006c940) */
/* WARNING: Removing unreachable block (ram,0xf006c950) */
/* WARNING: Removing unreachable block (ram,0xf006c994) */
/* WARNING: Removing unreachable block (ram,0xf006c910) */

undefined8 _vmp_put(int param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  uint uVar3;
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
  do {
    do {
    } while (_vm_info_lock_data != 0);
    puVar2 = &_vm_info_lock_data;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  sVar1 = *(sword *)(param_1 + 6);
  *(sword *)(param_1 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    _vm_info_enqueue(param_1);
  }
  _vm_info_lock_data = 0;
  _lock_done(param_1 + 0x18);
  if (_mfs_files_max < _mfs_files_mapped) {
    _mfs_cache_trim();
    uVar3 = *(uint *)(param_1 + 0x38);
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x38);
  }
  if ((uVar3 & 0x10000000) != 0) {
    *(uint *)(param_1 + 0x38) = uVar3 & 0xefffffff;
    _vmp_invalidate(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1474 start=0xf006c9a4 */

/* WARNING: Removing unreachable block (ram,0xf006c9d0) */

undefined8 _mfs_uncache(int *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = *param_1;
  if (((*(uint *)(iVar1 + 0x38) & 0x8000000) != 0) && (*(sword *)(iVar1 + 4) == 0)) {
    _mfs_memfree(iVar1,0);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1475 start=0xf006c9e0 */

/* WARNING: Removing unreachable block (ram,0xf006caa8) */
/* WARNING: Removing unreachable block (ram,0xf006ca6c) */
/* WARNING: Removing unreachable block (ram,0xf006ca20) */
/* WARNING: Removing unreachable block (ram,0xf006ca30) */
/* WARNING: Removing unreachable block (ram,0xf006ca9c) */
/* WARNING: Removing unreachable block (ram,0xf006cabc) */
/* WARNING: Removing unreachable block (ram,0xf006c9fc) */

undefined8 _mfs_memfree(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  do {
    do {
    } while (_vm_info_lock_data != 0);
    puVar1 = &_vm_info_lock_data;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  if (*(int *)(param_1 + 0x38) < 0) {
    _vm_info_dequeue(param_1);
  }
  _vm_info_lock_data = 0;
  _lock_write(param_1 + 0x18);
  if (*(sword *)(param_1 + 4) == 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xf7ffffff;
  }
  iVar2 = 0;
  _mfs_map_remove(param_1,*(int *)(param_1 + 8),*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc),
                  param_2);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(sword *)(param_1 + 4) == 0) {
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = 0;
    if (*(int *)(param_1 + 0x30) != 0) {
      _crfree();
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  _lock_done(param_1 + 0x18);
  if (iVar2 != 0) {
    _vm_object_deallocate(iVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1476 start=0xf006cacc */

/* WARNING: Removing unreachable block (ram,0xf006cb18) */
/* WARNING: Removing unreachable block (ram,0xf006cb28) */
/* WARNING: Removing unreachable block (ram,0xf006caf4) */

undefined8 _mfs_cache_trim(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
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
  while( true ) {
    do {
      do {
      } while (_vm_info_lock_data != 0);
      puVar2 = &_vm_info_lock_data;
      _simple_lock_try();
      uVar1 = _vm_info_queue;
    } while (puVar2 == (undefined4 *)0x0);
    if (_mfs_files_mapped <= _mfs_files_max) break;
    _vm_info_dequeue(_vm_info_queue);
    _vm_info_lock_data = 0;
    _mfs_memfree(uVar1,1);
  }
  _vm_info_lock_data = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1477 start=0xf006cb44 */

/* WARNING: Removing unreachable block (ram,0xf006cbb4) */
/* WARNING: Removing unreachable block (ram,0xf006cbd0) */
/* WARNING: Removing unreachable block (ram,0xf006cb60) */

undefined8 _mfs_cache_clear(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
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
  do {
    do {
    } while (_vm_info_lock_data != 0);
    puVar2 = &_vm_info_lock_data;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
    sVar1 = *(sword *)(_vm_info_queue + 1);
    puVar2 = _vm_info_queue;
    iVar4 = _vm_info_version;
    while( true ) {
      if (sVar1 == 0) {
        _vm_info_lock_data = 0;
        _mfs_memfree(puVar2,1);
        do {
          do {
          } while (_vm_info_lock_data != 0);
          puVar3 = &_vm_info_lock_data;
          _simple_lock_try();
        } while (puVar3 == (undefined4 *)0x0);
      }
      puVar3 = _vm_info_queue;
      iVar5 = _vm_info_version;
      if (iVar4 == _vm_info_version) {
        puVar3 = (undefined4 *)puVar2[10];
        iVar5 = iVar4;
      }
      if ((undefined4 **)puVar3 == &_vm_info_queue) break;
      sVar1 = *(sword *)(puVar3 + 1);
      puVar2 = puVar3;
      iVar4 = iVar5;
    }
  }
  _vm_info_lock_data = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1478 start=0xf006cc18 */

/* WARNING: Removing unreachable block (ram,0xf006cca4) */
/* WARNING: Removing unreachable block (ram,0xf006cc74) */
/* WARNING: Removing unreachable block (ram,0xf006cc38) */
/* WARNING: Removing unreachable block (ram,0xf006cc50) */
/* WARNING: Removing unreachable block (ram,0xf006cc7c) */
/* WARNING: Removing unreachable block (ram,0xf006ccb8) */
/* WARNING: Removing unreachable block (ram,0xf006cc28) */

undefined8 _mfs_map_remove(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  int *piVar3;
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
  if (param_4 != 0) {
    _vmp_push(param_1);
  }
  _lock_write(_mfs_alloc_lock_data);
  _vm_map_remove(_mfs_map,param_2,param_3);
  if (_mfs_alloc_wanted != 0) {
    _mfs_alloc_wanted = 0;
    _thread_wakeup_prim(&_mfs_map,0,0);
  }
  _lock_done(_mfs_alloc_lock_data);
  iVar2 = *(int *)(param_1 + 0x24);
  piVar3 = (int *)(iVar2 + 0x10);
  if (iVar2 != 0) {
    do {
      do {
      } while (*piVar3 != 0);
      piVar1 = piVar3;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    _vm_object_deactivate_pages(iVar2);
    *(undefined4 *)(iVar2 + 0x10) = 0;
  }
  return CONCAT44(piVar3,iVar2);
}
/* GHIDRADEC_FUNCTION index=1479 start=0xf006cccc */

undefined8 _vnode_size(int param_1,undefined4 param_2)

{
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
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
            (param_1,(undefined *)((int)register0x00000038 + -0x48),
             *(undefined4 *)(_active_u + 0x1c));
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0x30));
}
/* GHIDRADEC_FUNCTION index=1480 start=0xf006ccfc */

/* WARNING: Removing unreachable block (ram,0xf006d008) */
/* WARNING: Removing unreachable block (ram,0xf006cfc4) */
/* WARNING: Removing unreachable block (ram,0xf006cf34) */
/* WARNING: Removing unreachable block (ram,0xf006cec0) */
/* WARNING: Removing unreachable block (ram,0xf006ce60) */
/* WARNING: Removing unreachable block (ram,0xf006cdb8) */
/* WARNING: Removing unreachable block (ram,0xf006cd34) */
/* WARNING: Removing unreachable block (ram,0xf006ce84) */
/* WARNING: Removing unreachable block (ram,0xf006cf08) */
/* WARNING: Removing unreachable block (ram,0xf006cf44) */
/* WARNING: Removing unreachable block (ram,0xf006cff8) */
/* WARNING: Removing unreachable block (ram,0xf006d038) */
/* WARNING: Removing unreachable block (ram,0xf006cd44) */

undefined8 _mfs_io(int *param_1,uint param_2,int param_3,uint param_4,sword *param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  uint uVar8;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  int iVar11;
  undefined4 unaff_i0;
  int iVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar13;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  if (*(int *)(param_2 + 0x14) == 0) {
    iVar12 = 0;
    goto locret_F006D044;
  }
  if ((*(int *)(param_2 + 8) < 0) || (*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14) < 0)) {
    iVar12 = 0x16;
    goto locret_F006D044;
  }
  _mfs_get(param_1);
  iVar6 = *param_1;
  iVar10 = *(int *)(iVar6 + 0x14);
  if ((param_3 == 1) && ((param_4 & 2) != 0)) {
    *(int *)(param_2 + 8) = iVar10;
  }
  uVar13 = *(uint *)(param_2 + 8);
  iVar11 = *(int *)(param_2 + 0x14);
  uVar8 = *(uint *)(param_1[9] + 0x10);
  if (param_3 != 1) {
    if (param_3 != 0) {
      *(undefined4 *)(iVar6 + 0x34) = 0;
      goto loc_F006CDC8;
    }
    if (*(int *)(iVar6 + 0x30) != 0) {
      *(undefined4 *)(iVar6 + 0x34) = 0;
      goto loc_F006CDC8;
    }
  }
  *param_5 = *param_5 + 1;
  if (*(int *)(iVar6 + 0x30) == 0) {
    *(sword **)(iVar6 + 0x30) = param_5;
  }
  else {
    _crfree();
    *(sword **)(iVar6 + 0x30) = param_5;
  }
  *(undefined4 *)(iVar6 + 0x34) = 0;
loc_F006CDC8:
  iVar9 = *(int *)(param_2 + 8);
  iVar7 = 0;
  uVar1 = *(uint *)(param_2 + 0x14);
  do {
    uVar5 = uVar8;
    if (uVar1 <= uVar8) {
      uVar5 = uVar1;
    }
    if (param_3 == 0) {
      uVar1 = iVar10 - *(int *)(param_2 + 8);
      if ((int)uVar1 < 1) {
        _mfs_put(param_1);
        iVar12 = 0;
        goto locret_F006D044;
      }
      if ((int)uVar1 < (int)uVar5) {
        uVar5 = uVar1;
      }
    }
    if (param_3 == 1) {
      uVar1 = *(int *)(param_2 + 8) + uVar5;
      if (*(uint *)(iVar6 + 0x14) < uVar1) {
        *(uint *)(iVar6 + 0x14) = uVar1;
      }
      uVar1 = *(uint *)(param_2 + 8);
    }
    else {
      uVar1 = *(uint *)(param_2 + 8);
    }
    if ((uVar1 < *(uint *)(iVar6 + 0x10)) ||
       (*(uint *)(iVar6 + 0x10) + *(int *)(iVar6 + 0xc) < uVar1 + uVar5)) {
      _remap_vnode(param_1,uVar1,uVar5);
      iVar12 = *(int *)(iVar6 + 8);
    }
    else {
      iVar12 = *(int *)(iVar6 + 8);
    }
    iVar12 = (iVar12 + *(int *)(param_2 + 8)) - *(int *)(iVar6 + 0x10);
    _uiomove(iVar12,uVar5,param_3,param_2);
    if (param_3 == 1) {
      *(uint *)(iVar6 + 0x38) = *(uint *)(iVar6 + 0x38) | 0x40000000;
    }
    iVar2 = *(int *)(iVar6 + 0x34);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar6 + 0x34) = 0;
      _crfree(*(undefined4 *)(iVar6 + 0x30));
      *(undefined4 *)(iVar6 + 0x30) = 0;
      iVar12 = iVar2;
    }
    bVar14 = iVar12 == 0;
    if (param_3 == 1) {
      if ((*(uint *)(param_1[9] + 0xc) & 0x100) != 0) {
        iVar7 = iVar7 + 1;
        bVar14 = iVar12 == 0;
        if (_nmfsbuf <= iVar7) {
          if (!bVar14) {
            iVar7 = 0;
            goto loc_F006CF74;
          }
          _vmp_push(iVar6);
          iVar2 = 0;
          if (0 < iVar7) {
            do {
              iVar2 = iVar2 + 1;
              piVar3 = param_1;
              (**(code **)(param_1[7] + 0x80))(param_1);
              iVar4 = iVar9;
              .udiv(iVar9,piVar3);
              _blkflush(param_1,iVar4,uVar8);
              iVar9 = iVar9 + uVar8;
            } while (iVar2 < iVar7);
          }
          iVar2 = *(int *)(iVar6 + 0x34);
          iVar7 = 0;
          if (iVar2 != 0) {
            *(undefined4 *)(iVar6 + 0x34) = 0;
            iVar12 = iVar2;
          }
        }
      }
      bVar14 = iVar12 == 0;
    }
loc_F006CF74:
    if (!bVar14) break;
    uVar1 = *(uint *)(param_2 + 0x14);
    if (((int)uVar1 < 1) || (uVar5 == 0)) break;
  } while( true );
  if (((iVar12 == 0) && (param_3 == 1)) &&
     (((param_4 & 4) != 0 || ((*(uint *)(param_1[9] + 0xc) & 0x100) != 0)))) {
    _vmp_push(iVar6);
    uVar1 = uVar13 + iVar11;
    if (uVar13 < uVar1) {
      iVar10 = param_1[7];
      while( true ) {
        piVar3 = param_1;
        (**(code **)(iVar10 + 0x80))(param_1);
        uVar5 = uVar13;
        .udiv(uVar13,piVar3);
        _blkflush(param_1,uVar5,uVar8);
        uVar13 = uVar13 + uVar8;
        if (uVar1 <= uVar13) break;
        iVar10 = param_1[7];
      }
      iVar10 = *(int *)(iVar6 + 0x34);
    }
    else {
      iVar10 = *(int *)(iVar6 + 0x34);
    }
    param_2 = uVar13;
    if (iVar10 != 0) {
      *(undefined4 *)(iVar6 + 0x34) = 0;
      iVar12 = iVar10;
    }
  }
  _mfs_put(param_1);
locret_F006D044:
  return CONCAT44(param_2,iVar12);
}
/* GHIDRADEC_FUNCTION index=1481 start=0xf006d04c */

/* WARNING: Removing unreachable block (ram,0xf006d0cc) */
/* WARNING: Removing unreachable block (ram,0xf006d0bc) */
/* WARNING: Removing unreachable block (ram,0xf006d0c4) */
/* WARNING: Removing unreachable block (ram,0xf006d0e8) */
/* WARNING: Removing unreachable block (ram,0xf006d068) */

undefined8 _mfs_sync(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
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
  do {
    do {
    } while (_vm_info_lock_data != 0);
    puVar1 = &_vm_info_lock_data;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
    uVar2 = _vm_info_queue[0xe];
    puVar1 = _vm_info_queue;
    iVar3 = _vm_info_version;
    while( true ) {
      puVar5 = (undefined4 *)puVar1[10];
      if ((uVar2 & 0x40000000) != 0) {
        _vm_info_lock_data = 0;
        _vmp_get(puVar1);
        _vmp_push(puVar1);
        _vmp_put(puVar1);
        do {
          do {
          } while (_vm_info_lock_data != 0);
          puVar1 = &_vm_info_lock_data;
          _simple_lock_try();
        } while (puVar1 == (undefined4 *)0x0);
        iVar3 = iVar3 + 2;
      }
      puVar1 = _vm_info_queue;
      iVar4 = _vm_info_version;
      if (iVar3 == _vm_info_version) {
        puVar1 = puVar5;
        iVar4 = iVar3;
      }
      if ((undefined4 **)puVar1 == &_vm_info_queue) break;
      uVar2 = puVar1[0xe];
      iVar3 = iVar4;
    }
  }
  _vm_info_lock_data = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1482 start=0xf006d138 */

/* WARNING: Removing unreachable block (ram,0xf006d164) */
/* WARNING: Removing unreachable block (ram,0xf006d16c) */
/* WARNING: Removing unreachable block (ram,0xf006d15c) */

undefined8 _mfs_fsync(int *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = *param_1;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if ((*(uint *)(iVar1 + 0x38) & 0x8000000) == 0) {
    uVar2 = 0;
  }
  else {
    _vmp_get(iVar1);
    _vmp_push(iVar1);
    _vmp_put(iVar1);
    uVar2 = *(undefined4 *)(iVar1 + 0x34);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1483 start=0xf006d188 */

/* WARNING: Removing unreachable block (ram,0xf006d244) */
/* WARNING: Removing unreachable block (ram,0xf006d20c) */
/* WARNING: Removing unreachable block (ram,0xf006d1e4) */
/* WARNING: Removing unreachable block (ram,0xf006d22c) */
/* WARNING: Removing unreachable block (ram,0xf006d274) */
/* WARNING: Removing unreachable block (ram,0xf006d1c0) */

undefined8 _mfs_fsync_invalidate(int *param_1,uint param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar3 = *param_1;
  if ((iVar3 == 0) || ((*(uint *)(iVar3 + 0x38) & 0x8000000) == 0)) {
    uVar4 = 0;
  }
  else {
    do {
      do {
      } while (_vm_info_lock_data != 0);
      puVar2 = &_vm_info_lock_data;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    if (*(int *)(iVar3 + 0x38) < 0) {
      _vm_info_dequeue(iVar3);
      sVar1 = *(sword *)(iVar3 + 6);
    }
    else {
      sVar1 = *(sword *)(iVar3 + 6);
    }
    *(sword *)(iVar3 + 6) = sVar1 + 1;
    _vm_info_lock_data = 0;
    if ((param_2 & 1) == 0) {
      _vmp_push_all(iVar3);
    }
    if ((param_2 & 2) == 0) {
      *(uint *)(iVar3 + 0x38) = *(uint *)(iVar3 + 0x38) & 0xefffffff;
      _vmp_invalidate(iVar3);
    }
    do {
      do {
      } while (_vm_info_lock_data != 0);
      puVar2 = &_vm_info_lock_data;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    sVar1 = *(sword *)(iVar3 + 6);
    *(sword *)(iVar3 + 6) = sVar1 + -1;
    if (sVar1 == 1) {
      _vm_info_enqueue(iVar3);
    }
    _vm_info_lock_data = 0;
    uVar4 = *(undefined4 *)(iVar3 + 0x34);
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1484 start=0xf006d298 */

/* WARNING: Removing unreachable block (ram,0xf006d2e4) */
/* WARNING: Removing unreachable block (ram,0xf006d2ec) */
/* WARNING: Removing unreachable block (ram,0xf006d2dc) */

undefined8 _mfs_invalidate(int *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = *param_1;
  uVar2 = uRam00000034;
  if (iVar1 != 0) {
    if ((*(uint *)(iVar1 + 0x38) & 0x8000000) == 0) {
      uVar2 = *(undefined4 *)(iVar1 + 0x34);
    }
    else {
      if (*(sword *)(iVar1 + 6) < 1) {
        _vmp_get(iVar1);
        _vmp_invalidate(iVar1);
        _vmp_put(iVar1);
      }
      else {
        *(uint *)(iVar1 + 0x38) = *(uint *)(iVar1 + 0x38) | 0x10000000;
      }
      uVar2 = *(undefined4 *)(iVar1 + 0x34);
    }
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1485 start=0xf006d300 */

/* WARNING: Removing unreachable block (ram,0xf006d3ec) */
/* WARNING: Removing unreachable block (ram,0xf006d3c4) */
/* WARNING: Removing unreachable block (ram,0xf006d398) */
/* WARNING: Removing unreachable block (ram,0xf006d354) */
/* WARNING: Removing unreachable block (ram,0xf006d42c) */
/* WARNING: Removing unreachable block (ram,0xf006d3d4) */
/* WARNING: Removing unreachable block (ram,0xf006d414) */
/* WARNING: Removing unreachable block (ram,0xf006d32c) */

undefined8 _vno_flush(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
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
  iVar6 = *(int *)(*param_1 + 0x24);
  if (iVar6 != 0) {
    do {
      do {
      } while (_vm_page_queue_lock != 0);
      puVar2 = &_vm_page_queue_lock;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    do {
      do {
      } while (*(int *)(iVar6 + 0x10) != 0);
      piVar3 = (int *)(iVar6 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    param_3 = param_3 + param_2;
    uVar1 = ~_page_mask;
    param_2 = param_2 & uVar1;
    uVar4 = param_3 + _page_mask;
joined_r0xf006d384:
    do {
      if ((uVar4 & uVar1) <= param_2) goto loc_F006D44C;
      iVar5 = iVar6;
      _vm_page_lookup(iVar6,param_2);
      if (iVar5 != 0) {
        if ((*(uint *)(iVar5 + 0x20) & 0x80000000) != 0) {
          *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | 0x40000000;
          _assert_wait(iVar5,0);
          *(undefined4 *)(iVar6 + 0x10) = 0;
          _vm_page_queue_lock = 0;
          _thread_block();
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar2 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar2 == (undefined4 *)0x0);
          do {
            do {
            } while (*(int *)(iVar6 + 0x10) != 0);
            piVar3 = (int *)(iVar6 + 0x10);
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          goto joined_r0xf006d384;
        }
        _vm_page_free(iVar5);
      }
      param_2 = param_2 + _page_size;
    } while( true );
  }
locret_F006D458:
  return CONCAT44(param_2,param_1);
loc_F006D44C:
  param_1 = (int *)(iVar6 + 0x10);
  *param_1 = 0;
  _vm_page_queue_lock = 0;
  goto locret_F006D458;
}
/* GHIDRADEC_FUNCTION index=1486 start=0xf006d460 */

/* WARNING: Removing unreachable block (ram,0xf006d548) */
/* WARNING: Removing unreachable block (ram,0xf006d520) */
/* WARNING: Removing unreachable block (ram,0xf006d5a8) */
/* WARNING: Removing unreachable block (ram,0xf006d4b0) */
/* WARNING: Removing unreachable block (ram,0xf006d590) */
/* WARNING: Removing unreachable block (ram,0xf006d5d4) */
/* WARNING: Removing unreachable block (ram,0xf006d530) */
/* WARNING: Removing unreachable block (ram,0xf006d56c) */
/* WARNING: Removing unreachable block (ram,0xf006d488) */

undefined8 _vmp_invalidate(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int *piVar6;
  int *piVar7;
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
  piVar7 = (int *)param_1[9];
  if (piVar7 != (int *)0x0) {
    do {
      do {
      } while (_vm_page_queue_lock != 0);
      puVar1 = &_vm_page_queue_lock;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    do {
      do {
      } while (piVar7[4] != 0);
      piVar6 = piVar7 + 4;
      _simple_lock_try();
    } while (piVar6 == (int *)0x0);
    if ((int *)param_1[9] == piVar7) {
      piVar6 = (int *)*piVar7;
      if (piVar7 != piVar6) {
        uVar4 = piVar6[8];
        do {
          piVar5 = (int *)piVar6[2];
          if ((uVar4 >> 0x14 & 1) == 0) {
            if ((int)uVar4 < 0) {
              piVar6[8] = uVar4 | 0x40000000;
              _assert_wait(piVar6,0);
              piVar7[4] = 0;
              _vm_page_queue_lock = 0;
              _thread_block();
              do {
                do {
                } while (_vm_page_queue_lock != 0);
                puVar1 = &_vm_page_queue_lock;
                _simple_lock_try();
                param_1 = piVar7 + 4;
              } while (puVar1 == (undefined4 *)0x0);
              do {
                do {
                } while (*param_1 != 0);
                piVar2 = param_1;
                _simple_lock_try();
                piVar5 = piVar6;
              } while (piVar2 == (int *)0x0);
            }
            else if (*(sword *)(piVar6 + 7) == 0) {
              _pmap_remove_all(piVar6[9]);
              if ((piVar6[7] & 0x400U) != 0) {
                iVar3 = piVar6[9];
                _pmap_is_modified();
                if (iVar3 == 0) {
                  _mfs_mclean._0_4_ = _mfs_mclean._0_4_ + 1;
                  _vm_page_free(piVar6);
                  goto loc_F006D5E4;
                }
              }
              _mfs_mdirty._0_4_ = _mfs_mdirty._0_4_ + 1;
            }
          }
loc_F006D5E4:
          if (piVar7 == piVar5) break;
          uVar4 = piVar5[8];
          piVar6 = piVar5;
        } while( true );
      }
      piVar7[4] = 0;
      _vm_page_queue_lock = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1487 start=0xf006d600 */

/* WARNING: Removing unreachable block (ram,0xf006d730) */
/* WARNING: Removing unreachable block (ram,0xf006d708) */
/* WARNING: Removing unreachable block (ram,0xf006d884) */
/* WARNING: Removing unreachable block (ram,0xf006d828) */
/* WARNING: Removing unreachable block (ram,0xf006d7f0) */
/* WARNING: Removing unreachable block (ram,0xf006d788) */
/* WARNING: Removing unreachable block (ram,0xf006d670) */
/* WARNING: Removing unreachable block (ram,0xf006d6cc) */
/* WARNING: Removing unreachable block (ram,0xf006d790) */
/* WARNING: Removing unreachable block (ram,0xf006d80c) */
/* WARNING: Removing unreachable block (ram,0xf006d850) */
/* WARNING: Removing unreachable block (ram,0xf006d8b4) */
/* WARNING: Removing unreachable block (ram,0xf006d718) */
/* WARNING: Removing unreachable block (ram,0xf006d754) */
/* WARNING: Removing unreachable block (ram,0xf006d648) */

undefined8 _vmp_push(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
  undefined4 unaff_l3;
  uint uVar8;
  uint uVar9;
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
  if ((param_1[0xe] & 0x40000000U) != 0) {
    uVar8 = param_1[4];
    piVar7 = (int *)param_1[9];
    param_1[0xe] = param_1[0xe] & 0xbfffffff;
    param_1 = (int *)param_1[3];
    if (piVar7 != (int *)0x0) {
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar1 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar1 == (undefined4 *)0x0);
      do {
        do {
        } while (piVar7[4] != 0);
        piVar2 = piVar7 + 4;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      uVar9 = uVar8 & ~_page_mask;
      uVar8 = (int)param_1 + _page_mask + uVar8 & ~_page_mask;
      if (uVar9 < uVar8) {
        param_2 = 0x40000000;
        do {
          piVar2 = piVar7;
          _vm_page_lookup(piVar7,uVar9);
          if ((piVar2 == (int *)0x0) || (uVar5 = piVar2[8], (uVar5 >> 0x14 & 1) != 0)) {
loc_F006D8C0:
            uVar9 = uVar9 + _page_size;
          }
          else {
            if ((uVar5 & 0x80000000) == 0) {
              if ((piVar2[7] & 0x4000U) == 0) {
                _vm_page_activate(piVar2);
              }
              _vm_page_deactivate(piVar2);
              iVar3 = *piVar2;
              piVar6 = (int *)piVar2[1];
              *(int **)(iVar3 + 4) = piVar6;
              if (piVar6 != &_vm_page_queue_inactive) {
                *piVar6 = iVar3;
                iVar3 = _vm_page_queue_inactive;
              }
              _vm_page_queue_inactive = iVar3;
              piVar2[7] = piVar2[7] & 0xffff7fff;
              _vm_page_inactive_count = _vm_page_inactive_count + -1;
              piVar2[8] = piVar2[8] | 0x80000000;
              if ((piVar2[7] & 0x2000U) != 0) {
                _pmap_remove_all(piVar2[9]);
                piVar7[4] = 0;
                *(sword *)(piVar7 + 0x11) = *(sword *)(piVar7 + 0x11) + 1;
                _vm_page_queue_lock = 0;
                piVar6 = piVar2;
                _vnode_pageout();
                do {
                  do {
                  } while (_vm_page_queue_lock != 0);
                  puVar1 = &_vm_page_queue_lock;
                  _simple_lock_try();
                } while (puVar1 == (undefined4 *)0x0);
                param_1 = piVar7 + 4;
                do {
                  do {
                  } while (*param_1 != 0);
                  piVar4 = param_1;
                  _simple_lock_try();
                } while (piVar4 == (int *)0x0);
                *(sword *)(piVar7 + 0x11) = *(sword *)(piVar7 + 0x11) + -1;
                if (piVar6 == (int *)0x0) {
                  piVar2[7] = piVar2[7] & 0xffffdfff;
                }
              }
              _vm_page_activate(piVar2);
              uVar5 = piVar2[8];
              piVar2[8] = uVar5 & 0x7fffffff;
              if ((uVar5 & 0x40000000) != 0) {
                piVar2[8] = uVar5 & 0x3fffffff;
                _thread_wakeup_prim(piVar2,0,0);
              }
              goto loc_F006D8C0;
            }
            piVar2[8] = uVar5 | 0x40000000;
            _assert_wait(piVar2,0);
            piVar7[4] = 0;
            _vm_page_queue_lock = 0;
            _thread_block();
            do {
              do {
              } while (_vm_page_queue_lock != 0);
              puVar1 = &_vm_page_queue_lock;
              _simple_lock_try();
              param_1 = piVar7 + 4;
            } while (puVar1 == (undefined4 *)0x0);
            do {
              do {
              } while (*param_1 != 0);
              piVar2 = param_1;
              _simple_lock_try();
            } while (piVar2 == (int *)0x0);
          }
        } while (uVar9 < uVar8);
      }
      piVar7[4] = 0;
      _vm_page_queue_lock = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1488 start=0xf006d8e8 */

/* WARNING: Removing unreachable block (ram,0xf006db38) */
/* WARNING: Removing unreachable block (ram,0xf006dadc) */
/* WARNING: Removing unreachable block (ram,0xf006daa4) */
/* WARNING: Removing unreachable block (ram,0xf006da3c) */
/* WARNING: Removing unreachable block (ram,0xf006d9dc) */
/* WARNING: Removing unreachable block (ram,0xf006d9b4) */
/* WARNING: Removing unreachable block (ram,0xf006d948) */
/* WARNING: Removing unreachable block (ram,0xf006d9c4) */
/* WARNING: Removing unreachable block (ram,0xf006da04) */
/* WARNING: Removing unreachable block (ram,0xf006da44) */
/* WARNING: Removing unreachable block (ram,0xf006dac0) */
/* WARNING: Removing unreachable block (ram,0xf006db04) */
/* WARNING: Removing unreachable block (ram,0xf006db68) */
/* WARNING: Removing unreachable block (ram,0xf006d920) */

undefined8 _vmp_push_all(int *param_1,undefined *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
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
  piVar7 = (int *)param_1[9];
  param_1[0xe] = param_1[0xe] & 0xbfffffff;
  if (piVar7 == (int *)0x0) {
locret_F006DB8C:
    return CONCAT44(param_2,param_1);
  }
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar1 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  do {
    do {
    } while (piVar7[4] != 0);
    piVar6 = piVar7 + 4;
    _simple_lock_try();
  } while (piVar6 == (int *)0x0);
  piVar6 = (int *)*piVar7;
loc_F006D960:
  if (piVar7 != piVar6) {
    param_2 = DAT_f013c000;
    uVar4 = piVar6[8];
    do {
      if ((uVar4 >> 0x14 & 1) == 0) {
        if ((uVar4 & 0x80000000) != 0) goto loc_f006d9ac;
        if ((piVar6[7] & 0x4000U) == 0) {
          _vm_page_activate(piVar6);
        }
        _vm_page_deactivate(piVar6);
        iVar2 = *piVar6;
        piVar5 = (int *)piVar6[1];
        *(int **)(iVar2 + 4) = piVar5;
        if (piVar5 != &_vm_page_queue_inactive) {
          *piVar5 = iVar2;
          iVar2 = _vm_page_queue_inactive;
        }
        _vm_page_queue_inactive = iVar2;
        piVar6[7] = piVar6[7] & 0xffff7fff;
        _vm_page_inactive_count = _vm_page_inactive_count + -1;
        piVar6[8] = piVar6[8] | 0x80000000;
        if ((piVar6[7] & 0x2000U) != 0) {
          _pmap_remove_all(piVar6[9]);
          piVar7[4] = 0;
          *(sword *)(piVar7 + 0x11) = *(sword *)(piVar7 + 0x11) + 1;
          _vm_page_queue_lock = 0;
          piVar5 = piVar6;
          _vnode_pageout();
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar1 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar1 == (undefined4 *)0x0);
          param_1 = piVar7 + 4;
          do {
            do {
            } while (*param_1 != 0);
            piVar3 = param_1;
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          *(sword *)(piVar7 + 0x11) = *(sword *)(piVar7 + 0x11) + -1;
          if (piVar5 == (int *)0x0) {
            piVar6[7] = piVar6[7] & 0xffffdfff;
          }
        }
        _vm_page_activate(piVar6);
        uVar4 = piVar6[8];
        piVar6[8] = uVar4 & 0x7fffffff;
        if ((uVar4 & 0x40000000) != 0) {
          piVar6[8] = uVar4 & 0x3fffffff;
          _thread_wakeup_prim(piVar6,0,0);
        }
        piVar6 = (int *)piVar6[2];
      }
      else {
        piVar6 = (int *)piVar6[2];
      }
      if (piVar7 == piVar6) break;
      uVar4 = piVar6[8];
    } while( true );
  }
  piVar7[4] = 0;
  _vm_page_queue_lock = 0;
  goto locret_F006DB8C;
loc_f006d9ac:
  piVar6[8] = uVar4 | 0x40000000;
  _assert_wait(piVar6,0);
  piVar7[4] = 0;
  _vm_page_queue_lock = 0;
  _thread_block();
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar1 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  param_1 = piVar7 + 4;
  do {
    do {
    } while (*param_1 != 0);
    piVar6 = param_1;
    _simple_lock_try();
  } while (piVar6 == (int *)0x0);
  piVar6 = (int *)*piVar7;
  goto loc_F006D960;
}
/* GHIDRADEC_FUNCTION index=1489 start=0xf006db94 */

/* WARNING: Removing unreachable block (ram,0xf006dba8) */
/* WARNING: Removing unreachable block (ram,0xf006db98) */

undefined8 _vm_info_free(undefined4 *param_1,undefined4 param_2)

{
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
  _mfs_uncache(param_1);
  _zfree(_vm_info_zone,*param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1490 start=0xf006dbb8 */

undefined8 _vm_get_vnode_size(int *param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(*param_1 + 0x14));
}
/* GHIDRADEC_FUNCTION index=1491 start=0xf006dbcc */

undefined8 _vm_set_vnode_size(int *param_1,undefined4 param_2)

{
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
  *(undefined4 *)(*param_1 + 0x14) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1492 start=0xf006dbe0 */

undefined8 _vm_set_close_flush(int *param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = *param_1;
  *(uint *)(iVar1 + 0x38) = *(uint *)(iVar1 + 0x38) & 0xdfffffff | (uint)(param_2 != 0) << 0x1d;
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1493 start=0xf006dc10 */

undefined8 _vm_set_error(int *param_1,undefined4 param_2)

{
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
  *(undefined4 *)(*param_1 + 0x34) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1494 start=0xf006de48 */

/* WARNING: Removing unreachable block (ram,0xf006de4c) */

undefined8 _miniMonInit(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = param_1;
  _simple_lock_alloc();
  __kernDebuggerLock = puVar1;
  *puVar1 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1495 start=0xf006de68 */

/* WARNING: Removing unreachable block (ram,0xf006df14) */
/* WARNING: Removing unreachable block (ram,0xf006def0) */
/* WARNING: Removing unreachable block (ram,0xf006dec8) */
/* WARNING: Removing unreachable block (ram,0xf006deb4) */
/* WARNING: Removing unreachable block (ram,0xf006dea0) */
/* WARNING: Removing unreachable block (ram,0xf006deac) */
/* WARNING: Removing unreachable block (ram,0xf006dee4) */
/* WARNING: Removing unreachable block (ram,0xf006ded0) */
/* WARNING: Removing unreachable block (ram,0xf006df08) */
/* WARNING: Removing unreachable block (ram,0xf006df1c) */
/* WARNING: Removing unreachable block (ram,0xf006de80) */

undefined8 _miniMonLoop(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
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
  _miniMonState = param_3;
  if (param_2 != 0) {
    _safe_prf(aSystemPanic_0);
    _safe_prf(&aS_2,_panicstr);
    puVar1 = aTypeRToRebootO;
    _safe_prf();
    do {
      while( true ) {
        _miniMonTryGetchar();
        if (puVar1 != (undefined *)0x72) break;
        _safe_prf(aRebooting);
        puVar1 = DAT_f010ff80;
        _miniMonReboot();
      }
    } while (puVar1 != (undefined *)0x6d);
    _safe_prf(0xf010ff88);
  }
  _safe_prf(aNextstepMiniMo);
  do {
    _safe_prf(&aS_3,param_1);
    sub_F006DD7C(unk_F012F89C,0x80);
    puVar1 = unk_F012F89C;
    sub_F006DC90();
  } while (puVar1 != (undefined *)0x0);
  return CONCAT44(unk_F012F89C,param_1);
}
/* GHIDRADEC_FUNCTION index=1496 start=0xf006dff8 */

/* WARNING: Removing unreachable block (ram,0xf006e05c) */
/* WARNING: Removing unreachable block (ram,0xf006e028) */

undefined8
_safe_prf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
         undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  char *pcVar2;
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  *(undefined **)((int)register0x00000038 + -0xc) = unk_F012F69C;
  _prf(param_1,(undefined *)((int)register0x00000038 + 0x48),8,
       (undefined *)((int)register0x00000038 + -0xc));
  puVar1 = *(undefined **)((int)register0x00000038 + -0xc);
  *(undefined **)((int)register0x00000038 + -0xc) = puVar1 + 1;
  *puVar1 = 0;
  *(undefined **)((int)register0x00000038 + -0xc) = unk_F012F69C;
  if (unk_F012F69C[0] != '\0') {
    pcVar2 = *(char **)((int)register0x00000038 + -0xc);
    do {
      *(char **)((int)register0x00000038 + -0xc) = pcVar2 + 1;
      _miniMonPutchar((int)*pcVar2);
      pcVar2 = *(char **)((int)register0x00000038 + -0xc);
    } while (**(char **)((int)register0x00000038 + -0xc) != '\0');
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1497 start=0xf006e0e4 */

/* WARNING: Removing unreachable block (ram,0xf006e114) */
/* WARNING: Removing unreachable block (ram,0xf006e0f4) */

undefined8 _ns_hardclock_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = 1000000000;
  .div(1000000000,_hz);
  _ns_per_tick = (sqword)iVar1;
  _hardclock_init(iVar1 >> 0x1f,iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1498 start=0xf006e124 */

/* WARNING: Removing unreachable block (ram,0xf006e144) */
/* WARNING: Removing unreachable block (ram,0xf006e128) */

undefined8 _ns_timeout(undefined4 param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
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
  iVar1 = 1;
  uVar2 = param_2;
  _clock_value(1);
  _calloutDispatchDelayed
            (param_1,param_2,param_3 + iVar1 + (uint)CARRY4(param_4,uVar2),param_4 + uVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1499 start=0xf006e154 */

/* WARNING: Removing unreachable block (ram,0xf006e164) */

undefined8
_ns_abstimeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
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
  _calloutDispatchDelayed(param_1,param_2,param_3,param_4);
  return CONCAT44(param_2,param_1);
}

