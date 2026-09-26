/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00184f50 */

void _vol_notify_cancel(ushort param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  if (DAT_001e7589 == '\0') {
    _lock_init(&DAT_001e758c,1);
    DAT_001e7589 = '\x01';
  }
  _lock_write(&DAT_001e758c);
  ppuVar1 = (undefined **)PTR_LOOP_001e13fc;
  while (ppuVar3 = ppuVar1, ppuVar3 != &PTR_LOOP_001e13fc) {
    ppuVar1 = (undefined **)*ppuVar3;
    if ((*(ushort *)(ppuVar3 + 3) == (param_1 & 0xfff8)) ||
       (*(ushort *)((int)ppuVar3 + 0xe) == (param_1 & 0xfff8))) {
      ppuVar2 = (undefined **)ppuVar3[1];
      ppuVar4 = ppuVar2;
      if (ppuVar1 != &PTR_LOOP_001e13fc) {
        ppuVar1[1] = (undefined *)ppuVar2;
        ppuVar4 = (undefined **)PTR_LOOP_001e1400;
      }
      PTR_LOOP_001e1400 = (undefined *)ppuVar4;
      ppuVar4 = ppuVar1;
      if (ppuVar2 != &PTR_LOOP_001e13fc) {
        *ppuVar2 = (undefined *)ppuVar1;
        ppuVar4 = (undefined **)PTR_LOOP_001e13fc;
      }
      PTR_LOOP_001e13fc = (undefined *)ppuVar4;
      _kfree(ppuVar3,100);
    }
  }
  _lock_done(&DAT_001e758c);
  return;
}

