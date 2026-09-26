/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012b1c4 */

int _tcp_disconnect(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x1c);
  if (*(short *)(param_1 + 8) < 4) {
    iVar1 = _tcp_close(param_1);
  }
  else if ((*(char *)(iVar1 + 2) < '\0') && (*(short *)(iVar1 + 4) == 0)) {
    iVar1 = _tcp_drop(param_1,0);
  }
  else {
    _soisdisconnecting(iVar1);
    _sbflush(iVar1 + 0x24);
    iVar1 = _tcp_usrclosed(param_1);
    if (iVar1 != 0) {
      _tcp_output(iVar1);
    }
  }
  return iVar1;
}

