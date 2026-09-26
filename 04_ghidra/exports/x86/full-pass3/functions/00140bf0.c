/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140bf0 */

void _iput(int param_1)

{
  ushort uVar1;
  
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&DAT_001de018);
  }
  uVar1 = *(ushort *)(param_1 + 0x44);
  *(ushort *)(param_1 + 0x44) = uVar1 & 0xfffe;
  if ((uVar1 & 0x10) != 0) {
    *(ushort *)(param_1 + 0x44) = uVar1 & 0xffee;
    _wakeup(param_1);
  }
  if ((*(ushort *)(param_1 + 0x44) & 0x46) != 0) {
    *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(param_1 + 0x44) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x44) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x84) = _iuniqtime;
    }
    *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) & 0xb9;
  }
  _vn_rele(param_1 + 0xc);
  return;
}

