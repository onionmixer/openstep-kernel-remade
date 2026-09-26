
/* WARNING: Removing unreachable block (ram,0xf0078054) */
/* WARNING: Removing unreachable block (ram,0xf0077f98) */
/* WARNING: Removing unreachable block (ram,0xf0077f5c) */
/* WARNING: Removing unreachable block (ram,0xf0077f70) */
/* WARNING: Removing unreachable block (ram,0xf0078078) */
/* WARNING: Removing unreachable block (ram,0xf0077f7c) */

undefined8 _zinit(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined *puVar1;
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
  uint uVar3;
  undefined4 unaff_i2;
  uint uVar4;
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
  if (_zone_zone == (undefined4 *)0x0) {
    puVar1 = __zone_default_space;
    _zget_space(__zone_default_space,0x44,0);
  }
  else {
    puVar1 = (undefined *)_zone_zone;
    _zalloc();
  }
  if ((undefined4 *)puVar1 == (undefined4 *)0x0) {
    _panic(&aZinit);
  }
  if (param_3 == 0) {
    param_3 = _page_size;
  }
  if (param_1 == 0) {
    param_1 = 4;
  }
  uVar3 = param_2 + _page_mask & ~_page_mask;
  uVar4 = param_3 + _page_mask & ~_page_mask;
  if (uVar3 < uVar4) {
    uVar3 = uVar4;
  }
  *(undefined4 *)((int)puVar1 + 0x10) = 0;
  *(undefined4 *)((int)puVar1 + 0xc) = 0;
  *(undefined4 *)((int)puVar1 + 0x14) = 0;
  *(uint *)((int)puVar1 + 0x18) = uVar3;
  *(uint *)((int)puVar1 + 0x1c) = param_1 + 0xfU & 0xfffffff0;
  *(uint *)((int)puVar1 + 0x20) = uVar4;
  *(undefined4 *)((int)puVar1 + 0x28) = param_5;
  *(undefined4 *)((int)puVar1 + 8) = 0;
  *(undefined4 *)((int)puVar1 + 0x24) = 0;
  *(uint *)((int)puVar1 + 0x2c) = *(uint *)((int)puVar1 + 0x2c) & 0x7fffffff | param_4 << 0x1f;
  uVar3 = *(uint *)((int)puVar1 + 0x2c) & 0x9fffffff | 0x10000000;
  *(uint *)((int)puVar1 + 0x2c) = uVar3;
  if ((int)uVar3 < 0) {
    _lock_init((undefined4 *)((int)puVar1 + 0x30),1);
  }
  else {
    *(undefined4 *)puVar1 = 0;
  }
  sub_F0078AB4(puVar1);
  *(undefined4 *)((int)puVar1 + 0x40) = 0;
  do {
    do {
    } while (_all_zones_lock != 0);
    puVar2 = &_all_zones_lock;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  *_last_zone = puVar1;
  _last_zone = (undefined4 *)((int)puVar1 + 0x40);
  _all_zones_lock = 0;
  _num_zones = _num_zones + 1;
  return CONCAT44(&_all_zones_lock,puVar1);
}
