/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a490 */

undefined4 * _zinit(int param_1,int param_2,int param_3,byte param_4,undefined4 param_5)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (_zone_zone == 0) {
    puVar2 = (undefined4 *)_zget_space(&__zone_default_space,0x44,0);
  }
  else {
    puVar2 = (undefined4 *)_zalloc(_zone_zone);
  }
  if (puVar2 != (undefined4 *)0x0) {
    if (param_3 == 0) {
      param_3 = _page_size;
    }
    if (param_1 == 0) {
      param_1 = 4;
    }
    uVar4 = _page_mask + param_2 & ~_page_mask;
    uVar3 = _page_mask + param_3 & ~_page_mask;
    if (uVar4 < uVar3) {
      uVar4 = uVar3;
    }
    puVar2[4] = 0;
    puVar2[3] = 0;
    puVar2[5] = 0;
    puVar2[6] = uVar4;
    puVar2[7] = param_1 + 0xfU & 0xfffffff0;
    puVar2[8] = uVar3;
    *(byte *)(puVar2 + 0xb) = *(byte *)(puVar2 + 0xb) & 0xfe | param_4 & 1;
    puVar2[10] = param_5;
    puVar2[2] = 0;
    puVar2[9] = 0;
    bVar1 = *(byte *)(puVar2 + 0xb);
    *(byte *)(puVar2 + 0xb) = bVar1 & 0xf9 | 8;
    if ((bVar1 & 1) == 0) {
      *puVar2 = 0;
    }
    else {
      _lock_init(puVar2 + 0xc,1);
    }
    FUN_0016af6c(puVar2);
    puVar2[0x10] = 0;
    do {
    } while (_all_zones_lock != 0);
    LOCK();
    UNLOCK();
    *_last_zone = puVar2;
    _last_zone = puVar2 + 0x10;
    _num_zones = _num_zones + 1;
    LOCK();
    _all_zones_lock = 0;
    UNLOCK();
    return puVar2;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_zinit_001dfcf8);
}

