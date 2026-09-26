/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b970 */

void _zone_gc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = _num_zones;
  do {
  } while (_all_zones_lock != 0);
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  do {
  } while (_zget_space_lock != 0);
  LOCK();
  _zget_space_lock = 1;
  UNLOCK();
  iVar5 = 0;
  piVar4 = _first_zone;
  if (0 < _num_zones) {
    do {
      _all_zones_lock = 0;
      if ((*(byte *)(piVar4 + 0xb) & 1) == 0) {
        iVar3 = _splhigh();
        do {
          do {
          } while (*piVar4 != 0);
          LOCK();
          iVar1 = *piVar4;
          *piVar4 = 1;
          UNLOCK();
        } while (iVar1 == 1);
        piVar4[1] = iVar3;
      }
      else {
        _lock_write(piVar4 + 0xc);
      }
      if ((*(byte *)(piVar4 + 0xb) & 1) == 0) {
        if (((undefined *)piVar4[0xf] != (undefined *)0x0) &&
           ((undefined *)piVar4[0xf] != &__zone_default_space)) {
          _zone_collect(piVar4);
        }
        if ((*(byte *)(piVar4 + 0xb) & 1) != 0) goto LAB_0016ba26;
        LOCK();
        *piVar4 = 0;
        UNLOCK();
        _splx(piVar4[1]);
      }
      else {
LAB_0016ba26:
        _lock_done(piVar4 + 0xc);
      }
      do {
      } while (_all_zones_lock != 0);
      LOCK();
      UNLOCK();
      piVar4 = (int *)piVar4[0x10];
      LOCK();
      UNLOCK();
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar2);
  }
  _all_zones_lock = 0;
  _zone_free_space_reclaim();
  return;
}

