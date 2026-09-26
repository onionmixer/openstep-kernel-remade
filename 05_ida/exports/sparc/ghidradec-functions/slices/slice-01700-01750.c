/* GHIDRADEC_FUNCTION index=1700 start=0xf00787e4 */

/* WARNING: Removing unreachable block (ram,0xf0078974) */
/* WARNING: Removing unreachable block (ram,0xf0078828) */
/* WARNING: Removing unreachable block (ram,0xf0078878) */
/* WARNING: Removing unreachable block (ram,0xf00789b4) */
/* WARNING: Removing unreachable block (ram,0xf00789e0) */
/* WARNING: Removing unreachable block (ram,0xf0078998) */
/* WARNING: Removing unreachable block (ram,0xf007885c) */

undefined8 _zget_space(undefined *param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar8;
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
  uVar7 = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  if ((uint *)param_1 == (uint *)0x0) {
    param_1 = __zone_default_space;
  }
  if (param_2 < 0x11) {
    uVar8 = 0x10;
  }
  else {
    uVar8 = param_2 + 0xf & 0xfffffff0;
  }
  do {
    do {
    } while (_zget_space_lock != 0);
    puVar1 = &_zget_space_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  do {
    puVar2 = (uint *)param_1;
    sub_F0077DDC(param_1,uVar8);
    if (puVar2 != (uint *)0x0) {
      puVar4 = (uint *)puVar2[2];
      if (puVar2[1] - uVar8 < 0x10) {
        uVar3 = *puVar2;
        *puVar4 = uVar3;
        if (uVar3 != 0) {
          *(uint **)(*puVar2 + 8) = puVar4;
        }
        *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) - 1;
        param_1 = (undefined *)puVar2;
      }
      else {
        uVar6 = (int)puVar2 + uVar8;
        *(uint *)(uVar6 + 4) = puVar2[1] - uVar8;
        uVar3 = *puVar2;
        *(uint *)((int)puVar2 + uVar8) = uVar3;
        if (uVar3 != 0) {
          *(uint *)(uVar3 + 8) = uVar6;
        }
        *(uint **)(uVar6 + 8) = puVar4;
        *puVar4 = uVar6;
        uVar3 = *(uint *)(uVar6 + 4) >> ((byte)*(uint *)((int)param_1 + 0x10) & 0x1f);
        if ((int)*(uint *)((int)param_1 + 0x18) < (int)uVar3) {
          uVar3 = *(uint *)((int)param_1 + 0x18);
        }
        iVar5 = *(uint *)((int)param_1 + 0x14) + uVar3 * 0x10;
        uVar3 = *(uint *)(iVar5 + -0x10);
        if ((uVar3 == 0) || (param_1 = (undefined *)puVar2, uVar6 < uVar3)) {
          *(uint *)(iVar5 + -0x10) = uVar6;
          param_1 = (undefined *)puVar2;
        }
      }
loc_F00789C8:
      _zget_space_lock = 0;
      if (*(int *)((int)register0x00000038 + -0xc) != 0) {
        _kmem_free(_zone_map,*(int *)((int)register0x00000038 + -0xc),uVar7);
      }
locret_F00789E8:
      return CONCAT44(uVar8,param_1);
    }
    if (*(int *)((int)register0x00000038 + -0xc) != 0) {
      _zone_free_space_add(param_1,uVar8,*(int *)((int)register0x00000038 + -0xc),uVar7);
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      goto loc_F00789C8;
    }
    uVar7 = uVar8 + _page_mask & ~_page_mask;
    uVar3 = _zdata_size - uVar7;
    if (uVar7 <= _zdata_size) {
      _zdata_size = uVar3;
      _zone_free_space_add(param_1,uVar8,_zdata + uVar3,uVar7);
      goto loc_F00789C8;
    }
    _zget_space_lock = 0;
    iVar5 = _zone_map;
    _kmem_alloc_zone(_zone_map,(undefined *)((int)register0x00000038 + -0xc),uVar7,param_3);
    if (iVar5 != 0) {
      param_1 = (undefined *)0x0;
      goto locret_F00789E8;
    }
    do {
      do {
      } while (_zget_space_lock != 0);
      puVar1 = &_zget_space_lock;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1701 start=0xf0078b38 */

/* WARNING: Removing unreachable block (ram,0xf0078bd0) */
/* WARNING: Removing unreachable block (ram,0xf0078bc4) */
/* WARNING: Removing unreachable block (ram,0xf0078be0) */
/* WARNING: Removing unreachable block (ram,0xf0078bb4) */

undefined8 _zone_bootstrap(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  _all_zones_lock = 0;
  _first_zone = 0;
  _last_zone = &_first_zone;
  _num_zones = 0;
  _zget_space_lock = 0;
  DAT_f013cb64._0_4_ = __zone_default_space_hint;
  DAT_f013cb64._4_4_ = 1;
  _zone_free_space = __zone_default_space;
  _zone_free_space_count = 1;
  _zone_zone = 0;
  uVar1 = 0x44;
  _zinit(0x44,0x2200,0x44,0,&aZones);
  _zone_zone = uVar1;
  sub_F00789F0(0x10,0x60);
  sub_F00789F0(0x80,0x300);
  sub_F00789F0(0x400,_page_size);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1702 start=0xf0078bf0 */

/* WARNING: Removing unreachable block (ram,0xf0078c14) */

undefined8 _zone_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = _kernel_map;
  _kmem_suballoc(_kernel_map,&_zone_min,&_zone_max,_zone_map_size,0);
  _zone_map = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1703 start=0xf00790cc */

/* WARNING: Removing unreachable block (ram,0xf00790d4) */

undefined8 _zalloc(undefined4 param_1,undefined4 param_2)

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
  sub_F0078C2C(param_1,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1704 start=0xf00790e4 */

/* WARNING: Removing unreachable block (ram,0xf00790ec) */

undefined8 _zalloc_noblock(undefined4 param_1,undefined4 param_2)

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
  sub_F0078C2C(param_1,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1705 start=0xf00790fc */

/* WARNING: Removing unreachable block (ram,0xf00791b0) */
/* WARNING: Removing unreachable block (ram,0xf0079154) */
/* WARNING: Removing unreachable block (ram,0xf0079138) */
/* WARNING: Removing unreachable block (ram,0xf0079128) */
/* WARNING: Removing unreachable block (ram,0xf00791c0) */
/* WARNING: Removing unreachable block (ram,0xf0079110) */

undefined8 _zget(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
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
  if (param_1 == (int *)0x0) {
    _panic(aZallocNullZone_0);
    iVar1 = iRam0000002c;
  }
  else {
    iVar1 = param_1[0xb];
  }
  if (iVar1 < 0) {
    _lock_write(param_1 + 0xc);
    piVar2 = (int *)param_1[4];
  }
  else {
    _splusclock();
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    param_1[1] = iVar1;
    piVar2 = (int *)param_1[4];
  }
  if (piVar2 == (int *)0x0) {
    iVar1 = param_1[0xb];
  }
  else {
    param_1[2] = param_1[2] + 1;
    param_1[4] = *piVar2;
    if ((int *)param_1[3] == piVar2) {
      param_1[3] = 0;
    }
    iVar1 = param_1[0xb];
  }
  if (iVar1 < 0) {
    _lock_done(param_1 + 0xc);
  }
  else {
    *param_1 = 0;
    _splx(param_1[1]);
  }
  return CONCAT44(param_2,piVar2);
}
/* GHIDRADEC_FUNCTION index=1706 start=0xf00791d0 */

/* WARNING: Removing unreachable block (ram,0xf00792d4) */
/* WARNING: Removing unreachable block (ram,0xf00791e4) */
/* WARNING: Removing unreachable block (ram,0xf0079210) */
/* WARNING: Removing unreachable block (ram,0xf0079258) */
/* WARNING: Removing unreachable block (ram,0xf00792e4) */
/* WARNING: Removing unreachable block (ram,0xf00791f4) */

undefined8 _zfree(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
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
  iVar1 = param_1[0xb];
  if (iVar1 < 0) {
    _lock_write(param_1 + 0xc);
  }
  else {
    _splusclock();
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    param_1[1] = iVar1;
  }
  if (_zone_check == 0) {
    piVar2 = (int *)param_1[3];
  }
  else {
    puVar4 = (undefined4 *)param_1[4];
    if (puVar4 == (undefined4 *)0x0) {
      piVar2 = (int *)param_1[3];
    }
    else {
      iVar1 = (int)puVar4 - (int)param_2;
      do {
        if (iVar1 == 0) {
          _panic(&aZfree);
          puVar4 = (undefined4 *)*puVar4;
        }
        else {
          puVar4 = (undefined4 *)*puVar4;
        }
        iVar1 = (int)puVar4 - (int)param_2;
      } while (puVar4 != (undefined4 *)0x0);
      piVar2 = (int *)param_1[3];
    }
  }
  if ((piVar2 == (int *)0x0) || (param_2 <= piVar2)) {
    piVar2 = param_1 + 4;
  }
  do {
    piVar3 = piVar2;
    piVar2 = (int *)*piVar3;
    if (piVar2 == (int *)0x0) {
      *param_2 = 0;
      goto loc_F00792B0;
    }
  } while (piVar2 < param_2);
  *param_2 = (int)piVar2;
loc_F00792B0:
  *piVar3 = (int)param_2;
  param_1[3] = (int)param_2;
  param_1[2] = param_1[2] + -1;
  if (param_1[0xb] < 0) {
    _lock_done(param_1 + 0xc);
  }
  else {
    *param_1 = 0;
    _splx(param_1[1]);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1707 start=0xf00792f4 */

undefined8 _zcollectable(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1708 start=0xf0079300 */

/* WARNING: Removing unreachable block (ram,0xf0079368) */

undefined8 _zchange(undefined4 *param_1,int param_2,uint param_3,uint param_4,int param_5)

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
  param_1[0xb] = param_1[0xb] & 0x1fffffff | param_2 << 0x1f | (param_3 & 1) << 0x1e |
                 (param_4 & 1) << 0x1d;
  if (param_5 == 0) {
    param_1[0xf] = __zone_default_space;
  }
  if ((int)param_1[0xb] < 0) {
    _lock_init(param_1 + 0xc,1);
  }
  else {
    *param_1 = 0;
  }
  return CONCAT44(param_2 << 0x1f,param_1);
}
/* GHIDRADEC_FUNCTION index=1709 start=0xf0079380 */

/* WARNING: Removing unreachable block (ram,0xf00794c8) */
/* WARNING: Removing unreachable block (ram,0xf007949c) */
/* WARNING: Removing unreachable block (ram,0xf0079418) */
/* WARNING: Removing unreachable block (ram,0xf0079428) */
/* WARNING: Removing unreachable block (ram,0xf00793dc) */
/* WARNING: Removing unreachable block (ram,0xf0079444) */
/* WARNING: Removing unreachable block (ram,0xf0079484) */
/* WARNING: Removing unreachable block (ram,0xf00794b0) */
/* WARNING: Removing unreachable block (ram,0xf00794f4) */
/* WARNING: Removing unreachable block (ram,0xf007939c) */

undefined8 _zone_gc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
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
    } while (_all_zones_lock != 0);
    puVar4 = &_all_zones_lock;
    _simple_lock_try();
    iVar1 = _num_zones;
    piVar5 = _first_zone;
  } while (puVar4 == (undefined4 *)0x0);
  _all_zones_lock = 0;
  do {
    do {
    } while (_zget_space_lock != 0);
    puVar4 = &_zget_space_lock;
    _simple_lock_try();
    iVar6 = 0;
  } while (puVar4 == (undefined4 *)0x0);
  if (iVar1 < 1) {
loc_F00794F4:
    _zone_free_space_reclaim();
    return CONCAT44(param_2,param_1);
  }
  uVar2 = piVar5[0xb];
  do {
    if ((uVar2 & 0x80000000) == 0) {
      _splusclock();
      do {
        do {
        } while (*piVar5 != 0);
        piVar3 = piVar5;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      piVar5[1] = uVar2;
      uVar2 = piVar5[0xb];
    }
    else {
      _lock_write(piVar5 + 0xc);
      uVar2 = piVar5[0xb];
    }
    if ((uVar2 & 0x80000000) == 0) {
      if ((undefined *)piVar5[0xf] != (undefined *)0x0) {
        if ((undefined *)piVar5[0xf] == __zone_default_space) {
          uVar2 = piVar5[0xb];
          goto loc_F0079490;
        }
        _zone_collect(piVar5);
      }
      uVar2 = piVar5[0xb];
    }
    else {
      uVar2 = piVar5[0xb];
    }
loc_F0079490:
    if ((uVar2 & 0x80000000) == 0) {
      *piVar5 = 0;
      _splx(piVar5[1]);
    }
    else {
      _lock_done(piVar5 + 0xc);
    }
    do {
      do {
      } while (_all_zones_lock != 0);
      puVar4 = &_all_zones_lock;
      _simple_lock_try();
    } while (puVar4 == (undefined4 *)0x0);
    piVar5 = (int *)piVar5[0x10];
    iVar6 = iVar6 + 1;
    _all_zones_lock = 0;
    if (iVar1 <= iVar6) goto loc_F00794F4;
    uVar2 = piVar5[0xb];
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1710 start=0xf0079504 */

/* WARNING: Removing unreachable block (ram,0xf007955c) */

undefined8 _consider_zone_gc(undefined4 param_1,undefined4 param_2)

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
  if (_zone_gc_max_rate == 0) {
    _zone_gc_max_rate = _hz;
  }
  if ((_zone_gc_allowed != 0) && (_zone_gc_last_tick + _zone_gc_max_rate < _sched_tick)) {
    _zone_gc_last_tick = _sched_tick;
    _zone_gc();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1711 start=0xf007956c */

/* WARNING: Removing unreachable block (ram,0xf007959c) */
/* WARNING: Removing unreachable block (ram,0xf0079588) */

undefined8 _zone_reclaim(undefined4 param_1,undefined4 param_2)

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
  do {
    do {
    } while (_zget_space_lock != 0);
    puVar1 = &_zget_space_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  _zone_free_space_reclaim();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1712 start=0xf00795ac */

/* WARNING: Removing unreachable block (ram,0xf00798e8) */
/* WARNING: Removing unreachable block (ram,0xf0079880) */
/* WARNING: Removing unreachable block (ram,0xf00797a4) */
/* WARNING: Removing unreachable block (ram,0xf0079778) */
/* WARNING: Removing unreachable block (ram,0xf0079718) */
/* WARNING: Removing unreachable block (ram,0xf0079728) */
/* WARNING: Removing unreachable block (ram,0xf00796b0) */
/* WARNING: Removing unreachable block (ram,0xf0079658) */
/* WARNING: Removing unreachable block (ram,0xf00796d8) */
/* WARNING: Removing unreachable block (ram,0xf0079744) */
/* WARNING: Removing unreachable block (ram,0xf0079760) */
/* WARNING: Removing unreachable block (ram,0xf007978c) */
/* WARNING: Removing unreachable block (ram,0xf00797c8) */
/* WARNING: Removing unreachable block (ram,0xf00798a4) */
/* WARNING: Removing unreachable block (ram,0xf007990c) */
/* WARNING: Removing unreachable block (ram,0xf00795f0) */

undefined8
_host_zone_info(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar11;
  undefined4 unaff_i1;
  int *piVar12;
  undefined4 unaff_i2;
  uint uVar13;
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
  *(undefined4 *)((int)register0x00000038 + -0x5c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -100) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x6c) = param_5;
  uVar9 = 0;
  uVar13 = 0;
  if (param_1 == 0) {
    iVar11 = 0x16;
  }
  else {
    do {
      do {
      } while (_all_zones_lock != 0);
      puVar5 = &_all_zones_lock;
      _simple_lock_try();
      uVar1 = _num_zones;
      piVar6 = _first_zone;
    } while (puVar5 == (undefined4 *)0x0);
    _all_zones_lock = 0;
    if (**(uint **)((int)register0x00000038 + -0x5c) < _num_zones) {
      uVar9 = _num_zones * 0x50 + _page_mask & ~_page_mask;
      iVar11 = _ipc_kernel_map;
      _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar9);
      iVar10 = *(int *)((int)register0x00000038 + -0xc);
      if (iVar11 != 0) goto locret_F007992C;
    }
    else {
      iVar10 = *param_2;
    }
    if (**(uint **)((int)register0x00000038 + -0x6c) < uVar1) {
      uVar13 = uVar1 * 0x24 + _page_mask & ~_page_mask;
      iVar11 = _ipc_kernel_map;
      _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0x10),uVar13);
      piVar12 = *(int **)((int)register0x00000038 + -0x10);
      if (iVar11 != 0) {
        iVar2 = *param_2;
        param_2 = piVar12;
        if (iVar10 != iVar2) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar9);
        }
        goto locret_F007992C;
      }
    }
    else {
      piVar12 = (int *)**(undefined4 **)((int)register0x00000038 + -100);
    }
    uVar8 = 0;
    piVar7 = piVar12;
    iVar11 = iVar10;
    if (uVar1 != 0) {
      do {
        uVar3 = piVar6[0xb];
        if ((uVar3 & 0x80000000) == 0) {
          _splusclock();
          do {
            do {
            } while (*piVar6 != 0);
            piVar4 = piVar6;
            _simple_lock_try();
          } while (piVar4 == (int *)0x0);
          piVar6[1] = uVar3;
        }
        else {
          _lock_write(piVar6 + 0xc);
        }
        _memcpy((undefined *)((int)register0x00000038 + -0x58),piVar6,0x44);
        if ((piVar6[0xb] & 0x80000000U) == 0) {
          *piVar6 = 0;
          _splx(piVar6[1]);
        }
        else {
          _lock_done(piVar6 + 0xc);
        }
        do {
          do {
          } while (_all_zones_lock != 0);
          puVar5 = &_all_zones_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        piVar6 = (int *)piVar6[0x10];
        _all_zones_lock = 0;
        _strncpy(iVar11,*(undefined4 *)((int)register0x00000038 + -0x30),0x50);
        *piVar7 = *(int *)((int)register0x00000038 + -0x50);
        piVar7[1] = *(int *)((int)register0x00000038 + -0x44);
        piVar7[2] = *(int *)((int)register0x00000038 + -0x40);
        piVar7[3] = *(int *)((int)register0x00000038 + -0x3c);
        piVar7[4] = *(int *)((int)register0x00000038 + -0x38);
        piVar7[5] = *(uint *)((int)register0x00000038 + -0x2c) >> 0x1f;
        piVar7[6] = *(uint *)((int)register0x00000038 + -0x2c) >> 0x1e & 1;
        piVar7[7] = *(uint *)((int)register0x00000038 + -0x2c) >> 0x1d & 1;
        uVar3 = 0;
        if (*(undefined **)((int)register0x00000038 + -0x1c) != (undefined *)0x0) {
          uVar3 = (uint)(*(undefined **)((int)register0x00000038 + -0x1c) != __zone_default_space);
        }
        piVar7[8] = uVar3;
        uVar8 = uVar8 + 1;
        piVar7 = piVar7 + 9;
        iVar11 = iVar11 + 0x50;
      } while (uVar8 < uVar1);
    }
    if (iVar10 != *param_2) {
      if (uVar1 * 0x50 - uVar9 != 0) {
        _bzero(*(int *)((int)register0x00000038 + -0xc) + uVar1 * 0x50,uVar9 + uVar1 * -0x50);
      }
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar9,1
               ,(undefined *)((int)register0x00000038 + -0xc));
      *param_2 = *(int *)((int)register0x00000038 + -0xc);
    }
    **(uint **)((int)register0x00000038 + -0x5c) = uVar1;
    if (piVar12 != (int *)**(undefined4 **)((int)register0x00000038 + -100)) {
      if (uVar1 * 0x24 - uVar13 != 0) {
        _bzero(*(int *)((int)register0x00000038 + -0x10) + uVar1 * 0x24,uVar13 + uVar1 * -0x24);
      }
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),_ipc_soft_map,uVar13
               ,1,(undefined *)((int)register0x00000038 + -0x10));
      **(undefined4 **)((int)register0x00000038 + -100) =
           *(undefined4 *)((int)register0x00000038 + -0x10);
    }
    iVar11 = 0;
    **(uint **)((int)register0x00000038 + -0x6c) = uVar1;
    param_2 = piVar12;
  }
locret_F007992C:
  return CONCAT44(param_2,iVar11);
}
/* GHIDRADEC_FUNCTION index=1713 start=0xf0079934 */

/* WARNING: Removing unreachable block (ram,0xf0079ae8) */
/* WARNING: Removing unreachable block (ram,0xf0079ab0) */
/* WARNING: Removing unreachable block (ram,0xf0079a58) */
/* WARNING: Removing unreachable block (ram,0xf0079cdc) */
/* WARNING: Removing unreachable block (ram,0xf0079ca0) */
/* WARNING: Removing unreachable block (ram,0xf0079c28) */
/* WARNING: Removing unreachable block (ram,0xf0079bec) */
/* WARNING: Removing unreachable block (ram,0xf0079c60) */
/* WARNING: Removing unreachable block (ram,0xf0079c0c) */
/* WARNING: Removing unreachable block (ram,0xf0079d14) */
/* WARNING: Removing unreachable block (ram,0xf0079cc0) */
/* WARNING: Removing unreachable block (ram,0xf0079a44) */
/* WARNING: Removing unreachable block (ram,0xf0079a8c) */
/* WARNING: Removing unreachable block (ram,0xf0079ac4) */
/* WARNING: Removing unreachable block (ram,0xf0079b04) */
/* WARNING: Removing unreachable block (ram,0xf0079980) */

undefined8
_host_zone_free_space_info
          (int param_1,undefined4 *param_2,uint *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  uint uVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
  uint uVar13;
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
  if (param_1 == 0) {
    uVar12 = 0x16;
  }
  else {
    uVar8 = 0;
    uVar10 = 0;
loc_F007996C:
    do {
      uVar11 = 0;
      uVar7 = 0;
      do {
        do {
        } while (_zget_space_lock != 0);
        puVar6 = &_zget_space_lock;
        _simple_lock_try();
        uVar9 = 0;
      } while (puVar6 == (undefined4 *)0x0);
      uVar13 = 0;
      if (_zone_free_space_count != 0) {
        iVar1 = 0;
        do {
          uVar13 = uVar13 + 1;
          piVar4 = (int *)((int)&_zone_free_space + iVar1);
          iVar1 = iVar1 + 4;
          uVar9 = uVar9 + *(int *)(*piVar4 + 0xc);
        } while (uVar13 < _zone_free_space_count);
      }
      if (uVar13 < *param_3) {
        uVar7 = uVar13 * 0xc + _page_mask & ~_page_mask;
      }
      if (*param_5 < uVar9) {
        uVar11 = uVar9 * 8 + _page_mask & ~_page_mask;
      }
      if ((uVar7 <= uVar8) && (uVar11 <= uVar10)) {
        puVar6 = *(undefined4 **)((int)register0x00000038 + -0xc);
        if (uVar8 == 0) {
          puVar6 = (undefined4 *)*param_2;
        }
        piVar4 = *(int **)((int)register0x00000038 + -0x10);
        if (uVar10 == 0) {
          piVar4 = (int *)*param_4;
        }
        uVar7 = 0;
        if (uVar13 != 0) {
          iVar1 = 0;
          puVar5 = puVar6 + 2;
          do {
            puVar2 = *(undefined4 **)((int)&_zone_free_space + iVar1);
            *puVar6 = *puVar2;
            puVar5[-1] = puVar2[1];
            puVar6 = puVar6 + 3;
            *puVar5 = puVar2[3];
            puVar5 = puVar5 + 3;
            for (piVar3 = (int *)puVar2[2]; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
              *piVar4 = (int)piVar3;
              piVar4[1] = piVar3[1];
              piVar4 = piVar4 + 2;
            }
            uVar7 = uVar7 + 1;
            iVar1 = iVar1 + 4;
          } while (uVar7 < uVar13);
        }
        _zget_space_lock = 0;
        if ((uVar13 == 0) || (uVar8 == 0)) {
          if ((uVar13 == 0) && (*param_2 = 0, uVar8 != 0)) {
            _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar8);
          }
        }
        else {
          uVar7 = uVar13 * 0xc + _page_mask & ~_page_mask;
          _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                           *(int *)((int)register0x00000038 + -0xc) + uVar7,1);
          _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,
                   uVar7,1,(undefined *)((int)register0x00000038 + -0x14));
          if (uVar7 != uVar8) {
            _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar7,
                       uVar8 - uVar7);
          }
          *param_2 = *(undefined4 *)((int)register0x00000038 + -0x14);
        }
        *param_3 = uVar13;
        if ((uVar9 == 0) || (uVar10 == 0)) {
          if (uVar9 == 0) {
            *param_4 = 0;
            if (uVar10 != 0) {
              _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10);
            }
            goto loc_F0079D1C;
          }
          *param_5 = uVar9;
        }
        else {
          uVar8 = uVar9 * 8 + _page_mask & ~_page_mask;
          _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10),
                           *(int *)((int)register0x00000038 + -0x10) + uVar8,1);
          _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),_ipc_soft_map,
                   uVar8,1,(undefined *)((int)register0x00000038 + -0x18));
          if (uVar8 != uVar10) {
            _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10) + uVar8,
                       uVar10 - uVar8);
          }
          *param_4 = *(undefined4 *)((int)register0x00000038 + -0x18);
loc_F0079D1C:
          *param_5 = uVar9;
        }
        uVar12 = 0;
        goto locret_F0079D24;
      }
      _zget_space_lock = 0;
      if (uVar8 < uVar7) {
        if (uVar8 != 0) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar8);
        }
        iVar1 = _ipc_kernel_map;
        _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar7);
        if (iVar1 != 0) {
          if (uVar10 == 0) goto loc_F0079AF0;
          uVar12 = *(undefined4 *)((int)register0x00000038 + -0x10);
          uVar8 = uVar10;
          goto loc_F0079AE8;
        }
        _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                         *(int *)((int)register0x00000038 + -0xc) + uVar7,0);
        uVar8 = uVar7;
      }
    } while (uVar11 <= uVar10);
    if (uVar10 != 0) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10);
    }
    iVar1 = _ipc_kernel_map;
    _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0x10),uVar11);
    if (iVar1 == 0) {
      _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10),
                       *(int *)((int)register0x00000038 + -0x10) + uVar11,0);
      uVar10 = uVar11;
      goto loc_F007996C;
    }
    if (uVar8 != 0) {
      uVar12 = *(undefined4 *)((int)register0x00000038 + -0xc);
loc_F0079AE8:
      _kmem_free(_ipc_kernel_map,uVar12,uVar8);
    }
loc_F0079AF0:
    uVar12 = 6;
  }
locret_F0079D24:
  return CONCAT44(param_2,uVar12);
}
/* GHIDRADEC_FUNCTION index=1714 start=0xf0079d2c */

/* WARNING: Removing unreachable block (ram,0xf007a094) */
/* WARNING: Removing unreachable block (ram,0xf007a1a0) */
/* WARNING: Removing unreachable block (ram,0xf007a238) */
/* WARNING: Removing unreachable block (ram,0xf007a318) */
/* WARNING: Removing unreachable block (ram,0xf007a2a4) */
/* WARNING: Removing unreachable block (ram,0xf007a140) */
/* WARNING: Removing unreachable block (ram,0xf007a040) */
/* WARNING: Removing unreachable block (ram,0xf007a004) */
/* WARNING: Removing unreachable block (ram,0xf0079fec) */
/* WARNING: Removing unreachable block (ram,0xf0079fc8) */
/* WARNING: Removing unreachable block (ram,0xf0079fa0) */
/* WARNING: Removing unreachable block (ram,0xf0079f58) */
/* WARNING: Removing unreachable block (ram,0xf0079f44) */
/* WARNING: Removing unreachable block (ram,0xf0079f24) */
/* WARNING: Removing unreachable block (ram,0xf0079f0c) */
/* WARNING: Removing unreachable block (ram,0xf0079eec) */
/* WARNING: Removing unreachable block (ram,0xf0079edc) */
/* WARNING: Removing unreachable block (ram,0xf0079ec8) */
/* WARNING: Removing unreachable block (ram,0xf0079ea8) */
/* WARNING: Removing unreachable block (ram,0xf0079e98) */
/* WARNING: Removing unreachable block (ram,0xf0079e78) */
/* WARNING: Removing unreachable block (ram,0xf0079e64) */
/* WARNING: Removing unreachable block (ram,0xf0079e50) */
/* WARNING: Removing unreachable block (ram,0xf0079e1c) */
/* WARNING: Removing unreachable block (ram,0xf0079d80) */
/* WARNING: Removing unreachable block (ram,0xf0079d48) */
/* WARNING: Removing unreachable block (ram,0xf0079d90) */
/* WARNING: Removing unreachable block (ram,0xf0079e28) */
/* WARNING: Removing unreachable block (ram,0xf0079e5c) */
/* WARNING: Removing unreachable block (ram,0xf0079e70) */
/* WARNING: Removing unreachable block (ram,0xf0079e8c) */
/* WARNING: Removing unreachable block (ram,0xf0079ea0) */
/* WARNING: Removing unreachable block (ram,0xf0079eb4) */
/* WARNING: Removing unreachable block (ram,0xf0079ed4) */
/* WARNING: Removing unreachable block (ram,0xf0079ee4) */
/* WARNING: Removing unreachable block (ram,0xf0079f00) */
/* WARNING: Removing unreachable block (ram,0xf0079f14) */
/* WARNING: Removing unreachable block (ram,0xf0079f30) */
/* WARNING: Removing unreachable block (ram,0xf0079f50) */
/* WARNING: Removing unreachable block (ram,0xf0079f68) */
/* WARNING: Removing unreachable block (ram,0xf0079f88) */
/* WARNING: Removing unreachable block (ram,0xf0079fd8) */
/* WARNING: Removing unreachable block (ram,0xf0079ff4) */
/* WARNING: Removing unreachable block (ram,0xf007a020) */
/* WARNING: Removing unreachable block (ram,0xf007a118) */
/* WARNING: Removing unreachable block (ram,0xf007a1c0) */
/* WARNING: Removing unreachable block (ram,0xf007a2ec) */
/* WARNING: Removing unreachable block (ram,0xf007a33c) */
/* WARNING: Removing unreachable block (ram,0xf007a190) */
/* WARNING: Removing unreachable block (ram,0xf007a080) */
/* WARNING: Removing unreachable block (ram,0xf007a0b4) */
/* WARNING: Removing unreachable block (ram,0xf0079d30) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf0079d48 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void _kern_server_main(void)

{
  int extraout_o0;
  undefined8 in_o0_1;
  undefined4 *puVar2;
  undefined8 uVar1;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 unaff_l0;
  int *piVar9;
  undefined4 uVar10;
  undefined4 unaff_l1;
  undefined4 *puVar11;
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
  _kalloc(0x4d4);
  extraout_o0 = (int)((qword)in_o0_1 >> 0x20);
  *(int *)((int)register0x00000038 + -0x4c) = extraout_o0;
  _memcpy((undefined *)((int)register0x00000038 + -0x48),(int)in_o0_1,0x3c);
  *(undefined **)((int)register0x00000038 + -0x48) = (undefined *)((int)register0x00000038 + -0x4c);
  if (*(int *)(_active_threads + 0xc) != _kernel_task) {
    *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x50) = 1;
  }
  _bzero(*(undefined4 *)((int)register0x00000038 + -0x4c));
  *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x4c8) = 0xffffffff;
  _task_self();
  puVar2 = *(undefined4 **)((int)register0x00000038 + -0x4c);
  iVar8 = 0x17c;
  puVar2[2] = extraout_o0;
  puVar11 = puVar2 + 0xf;
  puVar7 = puVar2 + 0x4c;
  puVar2[3] = _active_threads;
  *puVar2 = 0;
  puVar2[0xe] = puVar2 + 0xd;
  puVar2[0xd] = puVar2 + 0xd;
  puVar2[0x10] = puVar11;
  puVar2[0xf] = puVar11;
  puVar2[0x131] = puVar2 + 0x130;
  puVar2[0x130] = puVar2 + 0x130;
  do {
    puVar6 = (undefined4 *)puVar2[0x10];
    if (puVar11 == puVar6) {
      puVar2[0xf] = (int)puVar2 + iVar8;
    }
    else {
      puVar6[2] = (int)puVar2 + iVar8;
    }
    puVar7[0x16] = puVar6;
    puVar7[0x15] = puVar11;
    puVar2[0x10] = (int)puVar2 + iVar8;
    puVar7 = puVar7 + -4;
    iVar8 = iVar8 + -0x10;
  } while ((int)puVar2 <= (int)puVar7);
  _thread_self();
  _thread_get_special_port_EXTERNAL
            (extraout_o0,(int)in_o0_1,(undefined *)((int)register0x00000038 + -0x50));
  if ((extraout_o0 == 0) && (*(int *)((int)register0x00000038 + -0x50) != 0)) {
    uVar1 = CONCAT44(*(int *)((int)register0x00000038 + -0x50),
                     *(undefined4 *)((int)register0x00000038 + -0x4c));
  }
  else {
    _printf(aKServerCanTFin);
    _thread_terminate(_active_threads);
    _thread_halt_self();
    uVar1 = *(undefined8 *)((int)register0x00000038 + -0x50);
  }
  iVar3 = (int)uVar1;
  iVar8 = (int)((qword)uVar1 >> 0x20);
  *(int *)(iVar3 + 0x14) = iVar8;
  _task_self();
  _port_allocate_EXTERNAL();
  if (iVar8 != 0) {
    _printf(aKServerCanTAll);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  _thread_self();
  _thread_set_special_port_EXTERNAL(iVar8,iVar3,*(undefined4 *)((int)register0x00000038 + -0x54));
  if (iVar8 != 0) {
    _printf(aKServerCanTSet);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  _task_self();
  _port_set_allocate_EXTERNAL();
  if (iVar8 != 0) {
    _printf(aKServerCanTAll_0);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x20) =
       *(undefined4 *)((int)register0x00000038 + -0x58);
  _task_self();
  _port_set_add_EXTERNAL(iVar8,iVar3,*(undefined4 *)((int)register0x00000038 + -0x50));
  if (iVar8 != 0) {
    _printf(aKServerCanTAdd);
    _thread_terminate(_active_threads);
    _thread_halt_self();
  }
  _port_allocate_EXTERNAL(*(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 8));
  if (iVar8 == 0) {
    _port_set_add_EXTERNAL
              (*(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 8),iVar3,
               *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x1c));
  }
  else {
    _kern_serv_panic(*(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x10));
  }
  if (*(int *)(_active_threads + 0xc) != _kernel_task) {
    _task_self();
    _task_set_special_port_EXTERNAL
              (iVar8,iVar3,*(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x1c));
  }
  _kern_serv_notify((undefined *)((int)register0x00000038 + -0x4c),iVar3,
                    *(undefined4 *)(iVar8 + 0x10));
  _kern_serv_kernel_task_port();
  *(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x4cc) = iVar8;
  _kalloc(0x30);
  iVar4 = *(int *)((int)register0x00000038 + -0x4c);
  *(int *)(iVar4 + 0x44) = iVar8;
  *(undefined4 *)(iVar4 + 0x48) = 0x30;
loc_F007A020:
  _splusclock();
  piVar9 = *(int **)((int)register0x00000038 + -0x4c);
  do {
    do {
    } while (*piVar9 != 0);
    _simple_lock_try(piVar9);
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
  } while (iVar8 == 0);
  while (iVar4 + 0x34 != iVar3) {
    puVar11 = *(undefined4 **)(iVar4 + 0x34);
    iVar5 = puVar11[2];
    if (iVar4 + 0x34 == iVar5) {
      *(int *)(iVar4 + 0x38) = iVar5;
    }
    else {
      *(int *)(iVar5 + 0xc) = iVar4 + 0x34;
    }
    puVar2 = *(undefined4 **)((int)register0x00000038 + -0x4c);
    puVar2[0xd] = iVar5;
    *puVar2 = 0;
    _splx(iVar8);
    (*(code *)*puVar11)(puVar11[1]);
    _splusclock();
    piVar9 = *(int **)((int)register0x00000038 + -0x4c);
    do {
      do {
      } while (*piVar9 != 0);
      _simple_lock_try(piVar9);
      iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    } while (iVar8 == 0);
    iVar5 = *(int *)(iVar4 + 0x40);
    if (iVar4 + 0x3c == iVar5) {
      *(undefined4 **)(iVar4 + 0x3c) = puVar11;
    }
    else {
      *(undefined4 **)(iVar5 + 8) = puVar11;
    }
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    puVar11[3] = iVar5;
    puVar11[2] = iVar4 + 0x3c;
    *(undefined4 **)(iVar4 + 0x40) = puVar11;
  }
  **(undefined4 **)((int)register0x00000038 + -0x4c) = 0;
  _splx();
  while( true ) {
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0x58);
    *(undefined4 *)(iVar8 + 4) = *(undefined4 *)(iVar4 + 0x48);
    _msg_receive(iVar8,iVar3,1000);
    if (iVar8 != -0xcc) break;
    uVar10 = *(undefined4 *)(*(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x44) + 4);
    _kfree();
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x48) = uVar10;
    _kalloc();
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 0x44) = 0xffffff34;
  }
  if (-0xcc < iVar8) goto loc_F007A170;
  iVar4 = *(int *)((int)register0x00000038 + -0x4c);
  if (iVar8 != -0xcf) goto loc_F007A1B8;
  goto loc_F007A1CC;
loc_F007A170:
  if (iVar8 != -0xcb) {
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    if (iVar8 != 0) {
loc_F007A1B8:
      _kern_serv_panic(*(undefined4 *)(iVar8 + 0x10));
      iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    }
loc_F007A1CC:
    if (*(int *)(iVar8 + 0xc) != *(int *)(iVar4 + 0x1c)) {
      if ((*(int *)(iVar8 + 0x14) - 0x40U < 0xd) &&
         (puVar11 = *(undefined4 **)(iVar4 + 0x4c0), (undefined4 *)(iVar4 + 0x4c0) != puVar11)) {
        do {
          if (iVar3 == *(int *)(iVar8 + 0x1c)) {
            *(undefined4 *)(iVar8 + 0x10) = *puVar11;
            _msg_send(iVar8,iVar3,0);
            iVar5 = puVar11[2];
            iVar4 = puVar11[3];
            if (*(int *)((int)register0x00000038 + -0x4c) + 0x4c0 == iVar5) {
              *(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x4c4) = iVar4;
            }
            else {
              *(int *)(iVar5 + 0xc) = iVar4;
            }
            if (*(int *)((int)register0x00000038 + -0x4c) + 0x4c0 == iVar4) {
              *(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x4c0) = iVar5;
            }
            else {
              *(int *)(iVar4 + 8) = iVar5;
            }
            _kfree(puVar11);
          }
          puVar11 = (undefined4 *)puVar11[2];
        } while ((undefined4 *)(iVar8 + 0x4c0) != puVar11);
      }
      *(undefined4 *)(*(int *)((int)register0x00000038 + -0x4c) + 4) = *(undefined4 *)(iVar8 + 0xc);
      sub_F007A3DC();
      if ((iVar8 == -0x12f) && (iRamfffffedd == *(int *)((int)register0x00000038 + -0x50))) {
        _kern_serv_handler(0xfffffed1);
      }
      goto loc_F007A020;
    }
    if (*(int *)(iVar8 + 0x14) == 0x41) {
      if (*(code **)(iVar4 + 0x4b8) == (code *)0x0) {
        if (*(code **)(iVar4 + 0x4bc) != (code *)0x0) {
          (**(code **)(iVar4 + 0x4bc))(*(undefined4 *)(iVar8 + 0x1c));
        }
      }
      else {
        (**(code **)(iVar4 + 0x4b8))(*(undefined4 *)(iVar8 + 0x1c));
        if (iVar8 != 0) goto loc_F007A020;
      }
      _kern_serv_port_gone((undefined *)((int)register0x00000038 + -0x4c));
      goto loc_F007A020;
    }
    if (*(code **)(iVar4 + 0x4bc) != (code *)0x0) {
      (**(code **)(iVar4 + 0x4bc))(*(undefined4 *)(iVar8 + 0x1c));
    }
  }
  goto loc_F007A020;
}
/* GHIDRADEC_FUNCTION index=1715 start=0xf007a498 */

undefined8 _kern_serv_port_gone(int *param_1,int param_2)

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
  int iVar2;
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
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x4b0) == param_2) {
      *(undefined4 *)(iVar2 + 0x4b0) = 0;
    }
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      if (*(int *)(iVar2 + 0x18c) == param_2) {
        *(undefined4 *)(iVar2 + 0x18c) = 0;
        *(undefined4 *)(iVar2 + 400) = 0;
        break;
      }
      iVar2 = iVar2 + 0x10;
    } while (iVar1 < 0x32);
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1716 start=0xf007a4f0 */

sqword _kern_serv_instance_loc(undefined4 *param_1,undefined4 *param_2)

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
  *param_2 = *param_1;
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=1717 start=0xf007a504 */

undefined8 _kern_serv_version(int *param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_2 < 2) {
    uVar1 = 0x67;
  }
  else {
    *(int *)(*param_1 + 0x4c8) = param_2;
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1718 start=0xf007a52c */

/* WARNING: Removing unreachable block (ram,0xf007a53c) */

sqword _kern_serv_load_objc(int *param_1,uint param_2)

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
  *(uint *)(*param_1 + 0x4d0) = param_2;
  _objc_registerModule(param_2,0);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1719 start=0xf007a54c */

sqword _kern_serv_boot_port(int *param_1,uint param_2)

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
  *(uint *)(*param_1 + 0x10) = param_2;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1720 start=0xf007a560 */

/* WARNING: Removing unreachable block (ram,0xf007a660) */
/* WARNING: Removing unreachable block (ram,0xf007a648) */
/* WARNING: Removing unreachable block (ram,0xf007a5dc) */
/* WARNING: Removing unreachable block (ram,0xf007a628) */

undefined8 _kern_serv_notify(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar1 = *(int *)(_active_threads + 0xc);
  iVar3 = *param_1;
  if (iVar1 == _kernel_task) {
    _get_kern_port(iVar1,param_3,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      iVar1 = *(int *)(_active_threads + 0xc);
      _get_kern_port(iVar1,param_2,(undefined *)((int)register0x00000038 + -0x10));
      if (iVar1 == 0) {
        _port_request_notification
                  (*(undefined4 *)((int)register0x00000038 + -0xc),
                   *(undefined4 *)((int)register0x00000038 + -0x10));
        iVar1 = 0;
      }
    }
  }
  else if (param_2 == *(int *)(iVar3 + 0x1c)) {
    iVar1 = 0;
  }
  else {
    piVar2 = *(int **)(iVar3 + 0x4c0);
    if ((int *)(iVar3 + 0x4c0) != piVar2) {
      iVar1 = *piVar2;
      while( true ) {
        if (iVar1 == param_2) {
          if (piVar2[1] == param_3) {
            iVar1 = 5;
            goto locret_F007A66C;
          }
          piVar2 = (int *)piVar2[2];
        }
        else {
          piVar2 = (int *)piVar2[2];
        }
        if ((int *)(iVar3 + 0x4c0) == piVar2) break;
        iVar1 = *piVar2;
      }
    }
    piVar2 = (int *)0x10;
    _kalloc();
    *piVar2 = param_2;
    piVar2[1] = param_3;
    iVar1 = *(int *)(iVar3 + 0x4c4);
    if (iVar3 + 0x4c0 == iVar1) {
      *(int **)(iVar3 + 0x4c0) = piVar2;
    }
    else {
      *(int **)(iVar1 + 8) = piVar2;
    }
    piVar2[3] = iVar1;
    piVar2[2] = iVar3 + 0x4c0;
    *(int **)(iVar3 + 0x4c4) = piVar2;
    iVar1 = 0;
  }
locret_F007A66C:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1721 start=0xf007a674 */

/* WARNING: Removing unreachable block (ram,0xf007a6a0) */

undefined8 _kern_serv_wire_range(undefined4 param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
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
  uVar1 = *(undefined4 *)(_kernel_task + 0xc);
  _vm_map_pageable(uVar1,param_2 & ~_page_mask,param_2 + param_3 + _page_mask & ~_page_mask,0);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1722 start=0xf007a6b0 */

/* WARNING: Removing unreachable block (ram,0xf007a6dc) */

undefined8 _kern_serv_unwire_range(undefined4 param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
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
  uVar1 = *(undefined4 *)(_kernel_task + 0xc);
  _vm_map_pageable(uVar1,param_2 & ~_page_mask,param_2 + param_3 + _page_mask & ~_page_mask,1);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1723 start=0xf007a6ec */

/* WARNING: Removing unreachable block (ram,0xf007a768) */

undefined8 _kern_serv_port_proc(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x4ac) == param_2) {
    *(undefined4 *)(iVar3 + 0x4ac) = 0;
  }
  iVar2 = 0;
  iVar1 = iVar3;
  do {
    if (*(int *)(iVar1 + 0x18c) == param_2) {
      *(undefined4 *)(iVar1 + 0x18c) = 0;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x10;
  } while (iVar2 < 0x32);
  iVar2 = 0;
  iVar1 = iVar3;
  do {
    if (*(int *)(iVar1 + 0x18c) == 0) break;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x10;
  } while (iVar2 < 0x32);
  iVar1 = 6;
  if (iVar2 != 0x32) {
    iVar1 = *(int *)(iVar3 + 8);
    _port_set_add_EXTERNAL(iVar1,*(undefined4 *)(iVar3 + 0x20),param_2);
    if (iVar1 == 0) {
      iVar3 = iVar3 + iVar2 * 0x10;
      *(int *)(iVar3 + 0x18c) = param_2;
      *(undefined4 *)(iVar3 + 400) = param_3;
      *(undefined4 *)(iVar3 + 0x194) = param_4;
      *(undefined4 *)(iVar3 + 0x198) = 0;
      iVar1 = 0;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1724 start=0xf007a7a4 */

/* WARNING: Removing unreachable block (ram,0xf007a820) */

undefined8 _kern_serv_port_serv(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x4ac) == param_2) {
    *(undefined4 *)(iVar3 + 0x4ac) = 0;
  }
  iVar2 = 0;
  iVar1 = iVar3;
  do {
    if (*(int *)(iVar1 + 0x18c) == param_2) {
      *(undefined4 *)(iVar1 + 0x18c) = 0;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x10;
  } while (iVar2 < 0x32);
  iVar2 = 0;
  iVar1 = iVar3;
  do {
    if (*(int *)(iVar1 + 0x18c) == 0) break;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x10;
  } while (iVar2 < 0x32);
  iVar1 = 6;
  if (iVar2 != 0x32) {
    iVar1 = *(int *)(iVar3 + 8);
    _port_set_add_EXTERNAL(iVar1,*(undefined4 *)(iVar3 + 0x20),param_2);
    if (iVar1 == 0) {
      iVar3 = iVar3 + iVar2 * 0x10;
      *(int *)(iVar3 + 0x18c) = param_2;
      *(undefined4 *)(iVar3 + 400) = param_3;
      *(undefined4 *)(iVar3 + 0x194) = param_4;
      *(undefined4 *)(iVar3 + 0x198) = 1;
      iVar1 = 0;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1725 start=0xf007a860 */

sqword _kern_serv_port_death_proc(int *param_1,uint param_2)

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
  *(uint *)(*param_1 + 0x4b8) = param_2;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1726 start=0xf007a874 */

undefined8 _kern_serv_call_proc(undefined4 param_1,code *param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_2 == (code *)0x0) {
    uVar1 = 100;
  }
  else {
    uVar1 = 0;
    (*param_2)(param_3);
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1727 start=0xf007a89c */

/* WARNING: Removing unreachable block (ram,0xf007a950) */
/* WARNING: Removing unreachable block (ram,0xf007a938) */
/* WARNING: Removing unreachable block (ram,0xf007a920) */
/* WARNING: Removing unreachable block (ram,0xf007a8f0) */
/* WARNING: Removing unreachable block (ram,0xf007a8cc) */
/* WARNING: Removing unreachable block (ram,0xf007a914) */
/* WARNING: Removing unreachable block (ram,0xf007a92c) */
/* WARNING: Removing unreachable block (ram,0xf007a944) */
/* WARNING: Removing unreachable block (ram,0xf007a960) */
/* WARNING: Removing unreachable block (ram,0xf007a8b4) */

undefined8 _kern_serv_shutdown(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  iVar5 = *param_1;
  if (*(int *)(iVar5 + 0x4d0) == 0) {
    iVar1 = *(int *)(iVar5 + 0x30);
  }
  else {
    _objc_unregisterModule(*(int *)(iVar5 + 0x4d0),0);
    iVar1 = *(int *)(iVar5 + 0x30);
  }
  if (iVar1 != 0) {
    sub_F007ACEC(iVar5 + 0x24);
    *(undefined4 *)(iVar5 + 0x30) = 0;
  }
  iVar4 = 0;
  iVar1 = iVar5;
  do {
    if (*(int *)(iVar1 + 0x18c) != 0) {
      _port_deallocate_EXTERNAL(*(undefined4 *)(iVar5 + 8));
      *(undefined4 *)(iVar1 + 0x18c) = 0;
      *(undefined4 *)(iVar1 + 400) = 0;
    }
    iVar4 = iVar4 + 1;
    iVar1 = iVar1 + 0x10;
  } while (iVar4 < 0x32);
  _port_deallocate_EXTERNAL(*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0x14));
  _port_deallocate_EXTERNAL(*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0x1c));
  _port_set_deallocate_EXTERNAL(*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0x20));
  _kfree(*(undefined4 *)(iVar5 + 0x44),*(undefined4 *)(iVar5 + 0x48));
  uVar3 = 0x4d4;
  _kfree(iVar5,0x4d4);
  uVar2 = _active_threads;
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return CONCAT44(uVar3,uVar2);
}
/* GHIDRADEC_FUNCTION index=1728 start=0xf007a968 */

/* WARNING: Removing unreachable block (ram,0xf007a98c) */
/* WARNING: Removing unreachable block (ram,0xf007a9b0) */

sqword _kern_serv_log_level(int *param_1,uint param_2)

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
  int iVar2;
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
  iVar1 = *(int *)(iVar2 + 0x30);
  *(uint *)(iVar2 + 0x30) = param_2;
  if ((iVar1 == 0) && (param_2 != 0)) {
    sub_F007AC94(iVar2 + 0x24,500);
  }
  else if ((*(int *)(iVar2 + 0x30) == 0) && (iVar1 != 0)) {
    sub_F007ACEC(iVar2 + 0x24);
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1729 start=0xf007a9c0 */

/* WARNING: Removing unreachable block (ram,0xf007aa7c) */
/* WARNING: Removing unreachable block (ram,0xf007aa58) */
/* WARNING: Removing unreachable block (ram,0xf007aa3c) */
/* WARNING: Removing unreachable block (ram,0xf007aa20) */
/* WARNING: Removing unreachable block (ram,0xf007aa48) */
/* WARNING: Removing unreachable block (ram,0xf007aa60) */
/* WARNING: Removing unreachable block (ram,0xf007aa9c) */
/* WARNING: Removing unreachable block (ram,0xf007a9dc) */

undefined8 _kern_serv_get_log(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
  undefined4 uVar5;
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
  piVar4 = (int *)*param_1;
  if (piVar4[0xc] == 0) {
    _port_deallocate_EXTERNAL(piVar4[2],param_2);
    uVar5 = 0x65;
  }
  else {
    iVar2 = piVar4[9];
    if (piVar4[10] == iVar2) {
      piVar4[6] = param_2;
    }
    else {
      uVar3 = (piVar4[10] - iVar2) + _page_mask & ~_page_mask;
      _vm_read_EXTERNAL(piVar4[0x133],iVar2,uVar3,(undefined *)((int)register0x00000038 + -0xc),
                        (undefined *)((int)register0x00000038 + -0x10));
      _kern_serv_log_data(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                          piVar4[10] - piVar4[9] >> 5);
      _port_deallocate_EXTERNAL(piVar4[2],param_2);
      iVar2 = piVar4[2];
      _vm_deallocate_EXTERNAL(iVar2,*(undefined4 *)((int)register0x00000038 + -0xc),uVar3);
      _splusclock();
      do {
        do {
        } while (*piVar4 != 0);
        piVar1 = piVar4;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      *piVar4 = 0;
      piVar4[10] = piVar4[9];
      _splx(iVar2);
    }
    uVar5 = 0;
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1730 start=0xf007aab0 */

/* WARNING: Removing unreachable block (ram,0xf007ab80) */
/* WARNING: Removing unreachable block (ram,0xf007ab3c) */
/* WARNING: Removing unreachable block (ram,0xf007aaf8) */
/* WARNING: Removing unreachable block (ram,0xf007ab58) */
/* WARNING: Removing unreachable block (ram,0xf007ab2c) */
/* WARNING: Removing unreachable block (ram,0xf007aadc) */

undefined8
_kern_serv_log(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
  undefined4 unaff_l1;
  int *piVar4;
  undefined4 unaff_l3;
  undefined4 uVar5;
  undefined4 unaff_l4;
  undefined4 uVar6;
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
  piVar4 = (int *)*param_1;
  uVar6 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x60);
  if ((param_2 <= piVar4[0xc]) && (iVar1 = piVar4[9], iVar1 != 0)) {
    _splusclock();
    do {
      do {
      } while (*piVar4 != 0);
      piVar2 = piVar4;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    puVar3 = (undefined4 *)piVar4[10];
    piVar4[10] = (int)(puVar3 + 8);
    if (puVar3 + 8 == (undefined4 *)piVar4[0xb]) {
      piVar4[10] = (int)puVar3;
      *piVar4 = 0;
      _splx(iVar1);
    }
    else {
      *piVar4 = 0;
      _splx();
      *puVar3 = param_3;
      puVar3[1] = param_4;
      puVar3[2] = param_5;
      puVar3[3] = param_6;
      puVar3[4] = uVar6;
      puVar3[5] = uVar5;
      _event_get();
      puVar3[6] = iVar1;
      puVar3[7] = param_2;
      if (piVar4[6] != 0) {
        _kern_serv_callout(param_1,sub_F007AB90,piVar4);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1731 start=0xf007ad24 */

/* WARNING: Removing unreachable block (ram,0xf007ae14) */
/* WARNING: Removing unreachable block (ram,0xf007ad80) */
/* WARNING: Removing unreachable block (ram,0xf007ad3c) */
/* WARNING: Removing unreachable block (ram,0xf007ad64) */
/* WARNING: Removing unreachable block (ram,0xf007ae04) */
/* WARNING: Removing unreachable block (ram,0xf007ada8) */
/* WARNING: Removing unreachable block (ram,0xf007ad28) */

undefined8 _kern_serv_callout(undefined4 *param_1,code *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
  undefined4 uVar5;
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
  piVar4 = (int *)*param_1;
  _curipl();
  if ((param_1 == (undefined4 *)0x0) && (_task_self(), param_1 == (undefined4 *)piVar4[2])) {
    (*param_2)(param_3);
    uVar5 = 0;
  }
  else {
    _splusclock();
    do {
      do {
      } while (*piVar4 != 0);
      piVar1 = piVar4;
      _simple_lock_try();
      piVar3 = piVar4 + 0xf;
    } while (piVar1 == (int *)0x0);
    piVar1 = (int *)piVar4[0xf];
    if (piVar3 == piVar1) {
      *piVar4 = 0;
      _splx(param_1);
      uVar5 = 6;
    }
    else {
      piVar2 = (int *)piVar1[2];
      if (piVar3 == piVar2) {
        piVar4[0x10] = (int)piVar2;
      }
      else {
        piVar2[3] = (int)piVar3;
      }
      piVar4[0xf] = (int)piVar2;
      *piVar1 = (int)param_2;
      piVar1[1] = param_3;
      piVar3 = (int *)piVar4[0xe];
      if (piVar4 + 0xd == piVar3) {
        piVar4[0xd] = (int)piVar1;
      }
      else {
        piVar3[2] = (int)piVar1;
      }
      piVar1[3] = (int)piVar3;
      piVar1[2] = (int)(piVar4 + 0xd);
      piVar4[0xe] = (int)piVar1;
      *piVar4 = 0;
      _splx(param_1);
      _calloutDispatchUnique(sub_F007AE28,piVar4[3]);
      uVar5 = 0;
    }
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1732 start=0xf007ae44 */

undefined8 _kern_serv_local_port(int *param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(*param_1 + 4));
}
/* GHIDRADEC_FUNCTION index=1733 start=0xf007ae58 */

undefined8 _kern_serv_bootstrap_port(int *param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(*param_1 + 0x10));
}
/* GHIDRADEC_FUNCTION index=1734 start=0xf007ae6c */

undefined8 _kern_serv_notify_port(int *param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(*param_1 + 0x1c));
}
/* GHIDRADEC_FUNCTION index=1735 start=0xf007ae80 */

undefined8 _kern_serv_port_set(int *param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(*param_1 + 0x20));
}
/* GHIDRADEC_FUNCTION index=1736 start=0xf007ae94 */

/* WARNING: Removing unreachable block (ram,0xf007aea4) */
/* WARNING: Removing unreachable block (ram,0xf007aec8) */
/* WARNING: Removing unreachable block (ram,0xf007ae9c) */

undefined8 _kern_serv_kernel_task_port(undefined4 param_1,undefined4 param_2)

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
  _task_reference(_kernel_task);
  iVar1 = _kernel_task;
  _convert_task_to_port();
  *(int *)((int)register0x00000038 + -0xc) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    _object_copyout(*(undefined4 *)(_active_threads + 0xc),iVar1,6,
                    (undefined *)((int)register0x00000038 + -0xc));
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1737 start=0xf007aee4 */

/* WARNING: Removing unreachable block (ram,0xf007b0a0) */
/* WARNING: Removing unreachable block (ram,0xf007b084) */
/* WARNING: Removing unreachable block (ram,0xf007b00c) */
/* WARNING: Removing unreachable block (ram,0xf007aff0) */
/* WARNING: Removing unreachable block (ram,0xf007afcc) */
/* WARNING: Removing unreachable block (ram,0xf007afa8) */
/* WARNING: Removing unreachable block (ram,0xf007af84) */
/* WARNING: Removing unreachable block (ram,0xf007af5c) */
/* WARNING: Removing unreachable block (ram,0xf007af38) */
/* WARNING: Removing unreachable block (ram,0xf007af24) */
/* WARNING: Removing unreachable block (ram,0xf007af48) */
/* WARNING: Removing unreachable block (ram,0xf007af6c) */
/* WARNING: Removing unreachable block (ram,0xf007af98) */
/* WARNING: Removing unreachable block (ram,0xf007afbc) */
/* WARNING: Removing unreachable block (ram,0xf007afe0) */
/* WARNING: Removing unreachable block (ram,0xf007b004) */
/* WARNING: Removing unreachable block (ram,0xf007b050) */
/* WARNING: Removing unreachable block (ram,0xf007b0b0) */
/* WARNING: Removing unreachable block (ram,0xf007b064) */
/* WARNING: Removing unreachable block (ram,0xf007af0c) */

void _notify_server_loop(void)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
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
  *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x50) = 1;
  iVar2 = *(int *)(_active_threads + 0xc);
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_allocate(iVar1,&unk_F0130F48);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  _get_kern_port(iVar2,unk_F0130F48,&dword_F0130F4C);
  iVar1 = iVar2;
  _task_set_special_port(iVar2,2,dword_F0130F4C);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_allocate(iVar1,&_pn_register_port);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  _get_kern_port(iVar2,_pn_register_port,&_pn_register_port_k);
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_set_allocate(iVar1,&unk_F0130F50);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_set_add(iVar1,unk_F0130F50,unk_F0130F48);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_set_add(iVar1,unk_F0130F50,_pn_register_port);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  iVar1 = 0x2000;
  _kalloc();
  dword_F0130F58 = &dword_F0130F54;
  dword_F0130F54 = &dword_F0130F54;
  *(undefined4 *)(iVar1 + 4) = 0x2000;
  do {
    while( true ) {
      while( true ) {
        *(undefined4 *)(iVar1 + 0xc) = unk_F0130F50;
        iVar2 = iVar1;
        _msg_receive(iVar1,0,0);
        if (iVar2 == 0) break;
        _printf(aNotifyServerLo,iVar2);
        *(undefined4 *)(iVar1 + 4) = 0x2000;
      }
      if (*(int *)(iVar1 + 0xc) == _pn_register_port) break;
      if (*(int *)(iVar1 + 0xc) == unk_F0130F48) {
        sub_F007B17C(iVar1);
        *(undefined4 *)(iVar1 + 4) = 0x2000;
      }
      else {
        _printf(aNotifyServerLo_0);
        *(undefined4 *)(iVar1 + 4) = 0x2000;
      }
    }
    sub_F007B0F4(iVar1);
    *(undefined4 *)(iVar1 + 4) = 0x2000;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1738 start=0xf007b2b4 */

/* WARNING: Removing unreachable block (ram,0xf007b350) */
/* WARNING: Removing unreachable block (ram,0xf007b33c) */

undefined8 _port_request_notification(undefined4 param_1,undefined4 param_2)

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
  *(undefined4 *)((int)register0x00000038 + -0x38) = dword_F0110E44;
  *(undefined4 *)((int)register0x00000038 + -0x34) = DAT_f0110e48._0_4_;
  *(undefined4 *)((int)register0x00000038 + -0x30) = DAT_f0110e48._4_4_;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = DAT_f0110e48._8_4_;
  *(undefined4 *)((int)register0x00000038 + -0x28) = DAT_f0110e48._12_4_;
  *(undefined4 *)((int)register0x00000038 + -0x24) = DAT_f0110e48._16_4_;
  *(undefined4 *)((int)register0x00000038 + -0x20) = DAT_f0110e48._20_4_;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = DAT_f0110e48._24_4_;
  puVar1 = (undefined *)((int)register0x00000038 + -0x38);
  *(undefined4 *)((int)register0x00000038 + -0x18) = DAT_f0110e48._28_4_;
  *(undefined4 *)((int)register0x00000038 + -0x14) = DAT_f0110e48._32_4_;
  *(undefined4 *)((int)register0x00000038 + -0x10) = DAT_f0110e48._36_4_;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = _pn_register_port_k;
  _msg_send_from_kernel(puVar1,1,0);
  if (puVar1 != (undefined *)0x0) {
    _printf(aPortRequestNot,puVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1739 start=0xf007b360 */

/* WARNING: Removing unreachable block (ram,0xf007b39c) */
/* WARNING: Removing unreachable block (ram,0xf007b384) */
/* WARNING: Removing unreachable block (ram,0xf007b378) */
/* WARNING: Removing unreachable block (ram,0xf007b38c) */
/* WARNING: Removing unreachable block (ram,0xf007b3a4) */
/* WARNING: Removing unreachable block (ram,0xf007b370) */

undefined8 _pnotify_start(undefined4 param_1,undefined4 param_2)

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
  _task_create(_kernel_task,0,(undefined *)((int)register0x00000038 + -0xc));
  _task_deallocate(*(undefined4 *)((int)register0x00000038 + -0xc));
  _thread_create(*(undefined4 *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10));
  _thread_deallocate(*(undefined4 *)((int)register0x00000038 + -0x10));
  _thread_start(*(undefined4 *)((int)register0x00000038 + -0x10),_notify_server_loop);
  _thread_resume(*(undefined4 *)((int)register0x00000038 + -0x10));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1740 start=0xf007b3b4 */

/* WARNING: Removing unreachable block (ram,0xf007b3d8) */

undefined8 _get_kern_port(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  if (param_2 == 0) {
    *param_3 = 0;
    uVar1 = 0;
  }
  else {
    _object_copyin(param_1,param_2,6,0);
    uVar1 = (param_1 != 0) - 1 & 4;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1741 start=0xf007bb34 */

/* WARNING: Removing unreachable block (ram,0xf007bbd8) */

undefined8 _kern_serv_handler(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
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
  *(undefined *)((int)register0x00000038 + -0x25) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0x20;
  *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x10);
  *(int *)((int)register0x00000038 + -0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0xfffffed1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x28);
  if ((*(int *)(param_1 + 0x14) - 100U < 0xd) &&
     (*(code **)(unk_F00F4C58 + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(unk_F00F4C58 + *(int *)(param_1 + 0x14) * 4))(param_1,puVar1,param_2);
    if (*(int *)((int)register0x00000038 + -0xc) == -0x131) {
      puVar1 = (undefined *)0x0;
    }
    else {
      _msg_send(puVar1,~*(uint *)(param_2 + 4) >> 0x1f);
    }
  }
  else {
    puVar1 = (undefined *)0xfffffed1;
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=1742 start=0xf007bbf4 */

/* WARNING: Removing unreachable block (ram,0xf007bc6c) */
/* WARNING: Removing unreachable block (ram,0xf007bc48) */
/* WARNING: Removing unreachable block (ram,0xf007bc28) */

undefined8 _kern_serv_panic(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  puVar3 = (undefined *)((int)register0x00000038 + -0x130);
  *(undefined4 *)((int)register0x00000038 + -0x118) = 0xc;
  *(undefined4 *)((int)register0x00000038 + -0x114) = 0xc0800;
  *(undefined4 *)((int)register0x00000038 + -0x110) = 1;
  _strncpy((undefined *)((int)register0x00000038 + -0x10c),param_2,0x100);
  *(undefined *)((int)register0x00000038 + -0xd) = 0;
  *(undefined *)((int)register0x00000038 + -0x12d) = 1;
  *(undefined4 *)((int)register0x00000038 + -300) = 0x124;
  uVar1 = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x128) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x120) = param_1;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x124) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x11c) = 200;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x20,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x11c) == 300) {
      puVar2 = (undefined *)0xfffffed4;
      if (((*(int *)((int)register0x00000038 + -300) == 0x20) &&
          (((*(char *)((int)register0x00000038 + -0x12d) == '\x01' ||
            ((*(char *)((int)register0x00000038 + -0x12d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x114) != 0)))) &&
           (puVar2 = (undefined *)0xfffffed4,
           *(int *)((int)register0x00000038 + -0x118) == 0x2200018)))) &&
         (puVar2 = *(undefined **)((int)register0x00000038 + -0x114), puVar2 == (undefined *)0x0)) {
        puVar2 = (undefined *)0x0;
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=1743 start=0xf007bd14 */

/* WARNING: Removing unreachable block (ram,0xf007bd98) */
/* WARNING: Removing unreachable block (ram,0xf007bd54) */
/* WARNING: Removing unreachable block (ram,0xf007bd74) */
/* WARNING: Removing unreachable block (ram,0xf007bd34) */

undefined8
_kern_serv_section_by_name
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
          undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  puVar3 = (undefined *)((int)register0x00000038 + -0x48);
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0xc800018;
  _strncpy((undefined *)((int)register0x00000038 + -0x2c),param_2,0x10);
  *(undefined *)((int)register0x00000038 + -0x1d) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0xc800018;
  _strncpy((undefined *)((int)register0x00000038 + -0x18),param_3,0x10);
  *(undefined *)((int)register0x00000038 + -9) = 0;
  *(undefined *)((int)register0x00000038 + -0x45) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0x40;
  uVar1 = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x40) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x38) = param_1;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x3c) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0xc9;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x30,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x34) == 0x12d) {
      if (((((*(int *)((int)register0x00000038 + -0x44) == 0x30) &&
            (*(char *)((int)register0x00000038 + -0x45) == '\x01')) ||
           ((puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x44) == 0x20 &&
            ((*(char *)((int)register0x00000038 + -0x45) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x2c) != 0)))))) &&
          (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x30) == 0x2200018)
          ) && (((puVar2 = *(undefined **)((int)register0x00000038 + -0x2c),
                 puVar2 == (undefined *)0x0 &&
                 (puVar2 = (undefined *)0xfffffed4,
                 *(int *)((int)register0x00000038 + -0x28) == 0x2200018)) &&
                (*param_4 = *(undefined4 *)((int)register0x00000038 + -0x24),
                *(int *)((int)register0x00000038 + -0x20) == 0x2200018)))) {
        *param_5 = *(undefined4 *)((int)register0x00000038 + -0x1c);
        puVar2 = *(undefined **)((int)register0x00000038 + -0x2c);
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=1744 start=0xf007be80 */

/* WARNING: Removing unreachable block (ram,0xf007bed8) */

undefined8 _kern_serv_log_data(undefined4 param_1,undefined4 param_2,int param_3)

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
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_2;
  *(undefined *)((int)register0x00000038 + -0x2d) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x28;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0xca;
  puVar1 = (undefined *)((int)register0x00000038 + -0x30);
  *(undefined4 *)((int)register0x00000038 + -0x18) = 6;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0x20020;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(int *)((int)register0x00000038 + -0x10) = param_3 << 3;
  _msg_send(puVar1,0,0);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=1745 start=0xf007bfcc */

/* WARNING: Removing unreachable block (ram,0xf007c040) */

undefined8 _exc_server(int param_1,int param_2)

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
  bool bVar1;
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
  *(undefined *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x20;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(param_2 + 0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)(param_2 + 0x18) = 0x2200018;
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
  bVar1 = *(int *)(param_1 + 0x14) == 0x960;
  if (bVar1) {
    sub_F007BEE8(param_1,param_2);
  }
  return CONCAT44(param_2,(uint)bVar1);
}
/* GHIDRADEC_FUNCTION index=1746 start=0xf007d37c */

undefined8 _mach_host_server(uint *param_1,uint *param_2)

{
  code *pcVar1;
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
  *param_2 = (*param_1 & 0xff00) >> 8;
  param_2[1] = 0x20;
  param_2[2] = param_1[3];
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = param_1[5] + 100;
  param_2[6] = dword_F01111E0;
  if ((param_1[5] - 0xa28 < 0x2a) &&
     (pcVar1 = *(code **)(param_1[5] * 4 + -0xfef1768), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1,param_2);
    uVar2 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1747 start=0xf007d418 */

undefined8 _mach_host_server_routine(int param_1,undefined4 param_2)

{
  uint uVar1;
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
  uVar1 = *(int *)(param_1 + 0x14) - 0xa28;
  if (uVar1 < 0x2a) {
    uVar2 = *(undefined4 *)(unk_F0111138 + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1748 start=0xf007e080 */

undefined8 _mach_port_server(uint *param_1,uint *param_2)

{
  code *pcVar1;
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
  *param_2 = (*param_1 & 0xff00) >> 8;
  param_2[1] = 0x20;
  param_2[2] = param_1[3];
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = param_1[5] + 100;
  param_2[6] = dword_F01112E8;
  if ((param_1[5] - 0xc80 < 0x13) &&
     (pcVar1 = *(code **)(param_1[5] * 4 + -0xfef1f64), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1,param_2);
    uVar2 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1749 start=0xf007e11c */

undefined8 _mach_port_server_routine(int param_1,undefined4 param_2)

{
  uint uVar1;
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
  uVar1 = *(int *)(param_1 + 0x14) - 0xc80;
  if (uVar1 < 0x13) {
    uVar2 = *(undefined4 *)(unk_F011129C + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}

