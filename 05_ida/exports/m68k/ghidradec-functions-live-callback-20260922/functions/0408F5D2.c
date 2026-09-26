
void _en_bufalloc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  uint *puVar6;
  uint *puVar7;
  
  if (dword_40B5598 == 0) {
    if (param_1 == 1) {
      _dbgstack = _enbuf_get();
      piVar4 = &_en_pkt;
      do {
        iVar1 = _enbuf_get();
        *piVar4 = iVar1;
        if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aNoGdbEnetBuffe);
        }
        uVar2 = _pmap_kernel(*piVar4);
        iVar1 = _pmap_resident_extract(uVar2);
        piVar5 = piVar4 + 1;
        *piVar4 = iVar1;
        piVar4 = piVar5;
      } while ((int)piVar5 < 0x40c8f05);
    }
    else {
      _dbgstack = dword_40C2C40;
      dword_40C2C40 =
           _m68k_page_size * ((_m68k_page_size + dword_40C2C40 + 0x3ff) / _m68k_page_size);
      puVar6 = &_en_pkt;
      do {
        uVar3 = dword_40C2C40 + 0xf;
        if ((int)uVar3 < 0) {
          uVar3 = dword_40C2C40 + 0x1e;
        }
        puVar7 = puVar6 + 1;
        *puVar6 = uVar3 & 0xfffffff0;
        dword_40C2C40 = (uVar3 & 0xfffffff0) + 0x62e;
        puVar6 = puVar7;
      } while ((int)puVar7 < 0x40c8f05);
    }
    if (_dbgstack == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aNoGdbStackBuff);
    }
    __m68k_dbginit();
    dword_40B5598 = 1;
  }
  return;
}

