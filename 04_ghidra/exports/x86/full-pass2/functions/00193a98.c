/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00193a98 */

void _startup_early(void)

{
  void *pvVar1;
  
  _cfree = DAT_001f6e74;
  _ncache = (void *)((int)DAT_001f6e74 + _nclist * 0x40);
  _buf = (void *)((int)_ncache + _ncsize * 0x48);
  if ((_nbuf == 0) && (_nbuf = _mem_size / 0x32 >> ((byte)_page_shift & 0x1f), 0xff < (int)_nbuf)) {
    _nbuf = 0xff;
  }
  if ((int)_nbuf < 0x10) {
    _nbuf = 0x10;
  }
  _bufpages = (int)(0x2000 / (ulonglong)_page_size) * _nbuf;
  pvVar1 = (void *)((int)_buf + _nbuf * 0x44);
  if (_nmfsbuf == 0) {
    _nmfsbuf = (int)_nbuf / 2;
  }
  _bzero(DAT_001f6e74,(int)pvVar1 - (int)DAT_001f6e74);
  DAT_001f6e74 = (void *)_pmap_resident_extract(_kernel_pmap,pvVar1);
  return;
}

