/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010bd48 */

undefined4 _logopen(void)

{
  int *piVar1;
  uint uVar2;
  
  if (_log_open != 0) {
    return 0x10;
  }
  DAT_001e97c4 = 0;
  DAT_001e97c8 = (int)*(short *)(*_active_u + 0x2e);
  DAT_001e97cc = _calloutEntryAllocate(FUN_0010bf90,0);
  piVar1 = _pmsgbuf;
  _log_open = 1;
  if (*_pmsgbuf != 0x63061) {
    *_pmsgbuf = 0x63061;
    piVar1[2] = 0;
    piVar1[1] = 0;
    uVar2 = 0;
    do {
      *(undefined1 *)(uVar2 + 0xc + (int)_pmsgbuf) = 0;
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0xff4);
  }
  return 0;
}

