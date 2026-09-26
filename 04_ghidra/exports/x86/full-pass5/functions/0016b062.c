/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b062 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0016b062(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  uint uVar7;
  
  *(uint *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 0xfU & 0xfffffff0;
  uVar6 = _page_mask + 0x2200 & ~_page_mask;
  uVar7 = _page_mask + unaff_ESI & ~_page_mask;
  if (uVar6 < uVar7) {
    uVar6 = uVar7;
  }
  unaff_EBX[4] = 0;
  unaff_EBX[3] = 0;
  unaff_EBX[5] = 0;
  unaff_EBX[6] = uVar6;
  unaff_EBX[7] = *(undefined4 *)(unaff_EBP + -8);
  unaff_EBX[8] = uVar7;
  *(byte *)(unaff_EBX + 0xb) = *(byte *)(unaff_EBX + 0xb) & 0xfe;
  unaff_EBX[10] = s_zones_001dfd24;
  unaff_EBX[2] = 0;
  unaff_EBX[9] = 0;
  bVar1 = *(byte *)(unaff_EBX + 0xb);
  *(byte *)(unaff_EBX + 0xb) = bVar1 & 0xf9 | 8;
  if ((bVar1 & 1) == 0) {
    *unaff_EBX = 0;
  }
  else {
    _lock_init(unaff_EBX + 0xc);
  }
  FUN_0016af6c();
  unaff_EBX[0x10] = 0;
  do {
  } while (_all_zones_lock != 0);
  LOCK();
  UNLOCK();
  *_last_zone = unaff_EBX;
  _last_zone = unaff_EBX + 0x10;
  _num_zones = _num_zones + 1;
  LOCK();
  _all_zones_lock = 0;
  UNLOCK();
  uVar6 = 0x10;
  _zone_zone = unaff_EBX;
  if (_zone_free_space_count < 8) {
    *(undefined4 **)(unaff_EBP + -8) = &_zone_free_space + _zone_free_space_count;
    _zone_free_space_count = _zone_free_space_count + 1;
    puVar4 = (undefined4 *)_zget_space(&__zone_default_space,0x1c);
    *puVar4 = 0x10;
    puVar4[1] = 0x60;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    do {
      iVar2 = puVar4[4];
      puVar4[4] = iVar2 + 1;
      uVar6 = uVar6 >> 1;
    } while ((uVar6 & 1) == 0);
    uVar6 = (uint)puVar4[1] >> ((char)iVar2 + 1U & 0x1f);
    puVar4[6] = uVar6;
    pvVar5 = (void *)_zget_space(&__zone_default_space,uVar6 << 4);
    puVar4[5] = pvVar5;
    _bzero(pvVar5,puVar4[6] << 4);
    **(undefined4 **)(unaff_EBP + -8) = puVar4;
  }
  uVar6 = 0x80;
  if (_zone_free_space_count < 8) {
    *(undefined4 **)(unaff_EBP + -8) = &_zone_free_space + _zone_free_space_count;
    _zone_free_space_count = _zone_free_space_count + 1;
    puVar4 = (undefined4 *)_zget_space(&__zone_default_space,0x1c);
    *puVar4 = 0x80;
    puVar4[1] = 0x300;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    do {
      iVar2 = puVar4[4];
      puVar4[4] = iVar2 + 1;
      uVar6 = uVar6 >> 1;
    } while ((uVar6 & 1) == 0);
    uVar6 = (uint)puVar4[1] >> ((char)iVar2 + 1U & 0x1f);
    puVar4[6] = uVar6;
    pvVar5 = (void *)_zget_space(&__zone_default_space,uVar6 << 4);
    puVar4[5] = pvVar5;
    _bzero(pvVar5,puVar4[6] << 4);
    **(undefined4 **)(unaff_EBP + -8) = puVar4;
  }
  uVar3 = _page_size;
  uVar6 = 0x400;
  *(undefined4 *)(unaff_EBP + -8) = _page_size;
  if (_zone_free_space_count < 8) {
    *(undefined4 **)(unaff_EBP + -4) = &_zone_free_space + _zone_free_space_count;
    _zone_free_space_count = _zone_free_space_count + 1;
    puVar4 = (undefined4 *)_zget_space(&__zone_default_space,0x1c);
    *puVar4 = 0x400;
    puVar4[1] = uVar3;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    do {
      iVar2 = puVar4[4];
      puVar4[4] = iVar2 + 1;
      uVar6 = uVar6 >> 1;
    } while ((uVar6 & 1) == 0);
    uVar6 = (uint)puVar4[1] >> ((char)iVar2 + 1U & 0x1f);
    puVar4[6] = uVar6;
    pvVar5 = (void *)_zget_space(&__zone_default_space,uVar6 << 4);
    puVar4[5] = pvVar5;
    _bzero(pvVar5,puVar4[6] << 4);
    **(undefined4 **)(unaff_EBP + -4) = puVar4;
  }
  return;
}

