
void _zone_gc(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  bool bVar4;
  bool bVar5;
  
  uVar1 = _num_zones;
  uVar2 = 0;
  bVar5 = false;
  piVar3 = _first_zone;
  if (0 < (int)_num_zones) {
    do {
      bVar4 = *(char *)(piVar3 + 10) < '\0';
      if (bVar4) {
        _lock_write((int)piVar3 + 0x2a);
      }
      else {
        *piVar3 = (int)(sword)(word)(byte)(bVar5 << 4 | bVar4 << 3 |
                                          (*(char *)(piVar3 + 10) == '\0') << 2);
      }
      if (*(char *)(piVar3 + 10) < '\0') {
loc_4055D58:
        _lock_done((int)piVar3 + 0x2a);
      }
      else {
        if ((*(undefined8 **)((int)piVar3 + 0x32) != (undefined8 *)0x0) &&
           (*(undefined8 **)((int)piVar3 + 0x32) != &__zone_default_space)) {
          _zone_collect(piVar3);
        }
        if (*(char *)(piVar3 + 10) < '\0') goto loc_4055D58;
      }
      piVar3 = *(int **)((int)piVar3 + 0x36);
      uVar2 = uVar2 + 1;
      bVar5 = uVar1 < uVar2;
    } while ((int)uVar2 < (int)uVar1);
  }
  _zone_free_space_reclaim();
  return;
}

