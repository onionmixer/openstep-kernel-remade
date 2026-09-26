
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

