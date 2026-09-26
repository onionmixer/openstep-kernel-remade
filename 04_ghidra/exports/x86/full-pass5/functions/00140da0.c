/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140da0 */

void _iinactive(uint param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  
  if ((((*(ushort *)(param_1 + 0x44) & 0x101) == 0x100) && (*(int *)(param_1 + 0x60) == 0)) &&
     (*(int *)(param_1 + 0x5c) == 0)) {
    if (*(char *)(*(int *)(param_1 + 0x50) + 0xd2) == '\0') {
      while ((*(ushort *)(param_1 + 0x44) & 1) != 0) {
        *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x10;
        _sleep(param_1);
      }
      *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 1;
      if (*(short *)(param_1 + 0x66) < 1) {
        *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + 1;
        *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x200;
        _itrunc(param_1,0);
        uVar1 = *(undefined2 *)(param_1 + 100);
        *(undefined2 *)(param_1 + 100) = 0;
        *(undefined4 *)(param_1 + 0x8c) = 0;
        *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
        _ifree(param_1,*(undefined4 *)(param_1 + 0x48),uVar1);
      }
      if ((*(byte *)(param_1 + 0x44) & 0x4e) != 0) {
        _iupdat(param_1,0);
      }
      uVar2 = *(ushort *)(param_1 + 0x44);
      *(ushort *)(param_1 + 0x44) = uVar2 & 0xfffe;
      if ((uVar2 & 0x10) != 0) {
        *(ushort *)(param_1 + 0x44) = uVar2 & 0xffee;
        _wakeup(param_1);
      }
    }
    *(undefined2 *)(param_1 + 0x44) = 0;
    if (_ifreeh == 0) {
      _ifreeh = param_1;
      *(uint **)(param_1 + 0x60) = &_ifreeh;
    }
    else {
      *_ifreet = param_1;
      *(uint **)(param_1 + 0x60) = _ifreet;
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
    _ifreet = (uint *)(param_1 + 0x5c);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_iinactive_001de029);
}

