/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001849a0 */

void _IOAddDDMEntry(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_001f74c4 != (undefined4 *)0x0) {
    uVar3 = _splhigh();
    iVar2 = _xpr_lock;
    LOCK();
    _xpr_lock = 1;
    UNLOCK();
    if (iVar2 != 1) {
      if (_xprLocked == 0) {
        DAT_001f74c8 = DAT_001f74c8 + 9;
        if (DAT_001e7580 < DAT_001f74c8) {
          DAT_001f74c8 = DAT_001f74c4;
        }
        puVar1 = DAT_001f74c8;
        *DAT_001f74c8 = param_1;
        puVar1[1] = param_2;
        puVar1[2] = param_3;
        puVar1[3] = param_4;
        puVar1[4] = param_5;
        puVar1[5] = param_6;
        puVar1[8] = 0;
        _IOGetTimestamp(puVar1 + 6);
        if (DAT_001f74cc < _uxprGlobal) {
          DAT_001f74cc = DAT_001f74cc + 1;
        }
      }
      LOCK();
      _xpr_lock = 0;
      UNLOCK();
    }
    _splx(uVar3);
  }
  return;
}

