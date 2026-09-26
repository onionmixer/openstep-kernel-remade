
void _startup_early(void)

{
  int iVar1;
  uint uVar2;
  
  _cfree = dword_40C2C40;
  _ns_callout = _nclist * 0x40 + dword_40C2C40;
  _softint = _ns_callout + _ncallout * 0x18;
  _ncache = _softint + _nsoftint * 0xc;
  _buf = _ncache + _ncsize * 0x46;
  if (_bufpages == 0) {
    _bufpages = _mem_size / 0x14 >> (_page_shift & 0x3f) & 0xfffffffe;
  }
  if ((_nbuf == 0) && (_nbuf = _bufpages, (int)_bufpages < 0x10)) {
    _nbuf = 0x10;
  }
  if (0xfe < (int)_nbuf) {
    _nbuf = 0xfe;
  }
  uVar2 = _nbuf * (0x2000 / _page_size);
  if (uVar2 < _bufpages) {
    _bufpages = uVar2;
  }
  iVar1 = _buf + _nbuf * 0x44;
  if (_nmfsbuf == 0) {
    uVar2 = _nbuf;
    if ((int)_nbuf < 0) {
      uVar2 = _nbuf + 1;
    }
    _nmfsbuf = (int)uVar2 >> 1;
  }
  _bzero(dword_40C2C40,iVar1 - dword_40C2C40);
  dword_40C2C40 = iVar1;
  return;
}
