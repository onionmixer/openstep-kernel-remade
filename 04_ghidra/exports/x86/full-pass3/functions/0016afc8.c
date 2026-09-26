/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016afc8 */

void _zone_bootstrap(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  
  _all_zones_lock = 0;
  _first_zone = 0;
  _last_zone = &_first_zone;
  _num_zones = 0;
  _zget_space_lock = 0;
  DAT_001f6dc4 = &__zone_default_space_hint;
  DAT_001f6dc8 = 1;
  _zone_free_space = &__zone_default_space;
  _zone_free_space_count = 1;
  _zone_zone = (undefined4 *)0x0;
  puVar4 = (undefined4 *)_zget_space(&__zone_default_space,0x44,0);
  if (puVar4 != (undefined4 *)0x0) {
    uVar7 = _page_mask + 0x2200 & ~_page_mask;
    uVar8 = _page_mask + 0x44 & ~_page_mask;
    if (uVar7 < uVar8) {
      uVar7 = uVar8;
    }
    puVar4[4] = 0;
    puVar4[3] = 0;
    puVar4[5] = 0;
    puVar4[6] = uVar7;
    puVar4[7] = 0x50;
    puVar4[8] = uVar8;
    *(byte *)(puVar4 + 0xb) = *(byte *)(puVar4 + 0xb) & 0xfe;
    puVar4[10] = s_zones_001dfd24;
    puVar4[2] = 0;
    puVar4[9] = 0;
    bVar1 = *(byte *)(puVar4 + 0xb);
    *(byte *)(puVar4 + 0xb) = bVar1 & 0xf9 | 8;
    if ((bVar1 & 1) == 0) {
      *puVar4 = 0;
    }
    else {
      _lock_init(puVar4 + 0xc,1);
    }
    FUN_0016af6c(puVar4);
    puVar4[0x10] = 0;
    do {
    } while (_all_zones_lock != 0);
    LOCK();
    UNLOCK();
    *_last_zone = puVar4;
    _last_zone = puVar4 + 0x10;
    _num_zones = _num_zones + 1;
    LOCK();
    _all_zones_lock = 0;
    UNLOCK();
    uVar7 = 0x10;
    _zone_zone = puVar4;
    if (_zone_free_space_count < 8) {
      puVar4 = &_zone_free_space + _zone_free_space_count;
      _zone_free_space_count = _zone_free_space_count + 1;
      puVar5 = (undefined4 *)_zget_space(&__zone_default_space,0x1c,0);
      *puVar5 = 0x10;
      puVar5[1] = 0x60;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
      do {
        iVar2 = puVar5[4];
        puVar5[4] = iVar2 + 1;
        uVar7 = uVar7 >> 1;
      } while ((uVar7 & 1) == 0);
      uVar7 = (uint)puVar5[1] >> ((char)iVar2 + 1U & 0x1f);
      puVar5[6] = uVar7;
      pvVar6 = (void *)_zget_space(&__zone_default_space,uVar7 << 4,0);
      puVar5[5] = pvVar6;
      _bzero(pvVar6,puVar5[6] << 4);
      *puVar4 = puVar5;
    }
    uVar7 = 0x80;
    if (_zone_free_space_count < 8) {
      puVar4 = &_zone_free_space + _zone_free_space_count;
      _zone_free_space_count = _zone_free_space_count + 1;
      puVar5 = (undefined4 *)_zget_space(&__zone_default_space,0x1c,0);
      *puVar5 = 0x80;
      puVar5[1] = 0x300;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
      do {
        iVar2 = puVar5[4];
        puVar5[4] = iVar2 + 1;
        uVar7 = uVar7 >> 1;
      } while ((uVar7 & 1) == 0);
      uVar7 = (uint)puVar5[1] >> ((char)iVar2 + 1U & 0x1f);
      puVar5[6] = uVar7;
      pvVar6 = (void *)_zget_space(&__zone_default_space,uVar7 << 4,0);
      puVar5[5] = pvVar6;
      _bzero(pvVar6,puVar5[6] << 4);
      *puVar4 = puVar5;
    }
    uVar3 = _page_size;
    uVar7 = 0x400;
    if (_zone_free_space_count < 8) {
      puVar4 = &_zone_free_space + _zone_free_space_count;
      _zone_free_space_count = _zone_free_space_count + 1;
      puVar5 = (undefined4 *)_zget_space(&__zone_default_space,0x1c,0);
      *puVar5 = 0x400;
      puVar5[1] = uVar3;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
      do {
        iVar2 = puVar5[4];
        puVar5[4] = iVar2 + 1;
        uVar7 = uVar7 >> 1;
      } while ((uVar7 & 1) == 0);
      uVar7 = (uint)puVar5[1] >> ((char)iVar2 + 1U & 0x1f);
      puVar5[6] = uVar7;
      pvVar6 = (void *)_zget_space(&__zone_default_space,uVar7 << 4,0);
      puVar5[5] = pvVar6;
      _bzero(pvVar6,puVar5[6] << 4);
      *puVar4 = puVar5;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_zinit_001dfcf8);
}

