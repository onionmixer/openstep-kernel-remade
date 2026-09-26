/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011bd6c */

int _vno_close(int param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  if ((*(short *)(param_1 + 0xe) == 1) && ((*(uint *)(param_1 + 8) & 0x180) != 0)) {
    _vno_bsd_unlock(param_1,0x180);
  }
  uVar2 = _vn_close(uVar1,*(undefined4 *)(param_1 + 8),(int)*(short *)(param_1 + 0xe));
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(short *)(param_1 + 0xe) == 1) {
    _vn_rele(uVar1);
  }
  return (int)*(char *)(DAT_001e875c + 0x68);
}

