/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010aa64 */

bool _rpsleep(code *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5)

{
  int iVar1;
  undefined1 local_3c [56];
  
  if (-1 < (char)*(byte *)(DAT_001e875c + 0x70)) {
    *(byte *)(DAT_001e875c + 0x70) = *(byte *)(DAT_001e875c + 0x70) | 0x80;
    _uprintf(s___s___s_s__pausing______001daaa5,_active_u + 8,param_4,param_5);
  }
  _bcopy((void *)(DAT_001e875c + 0x28),local_3c,0x38);
  iVar1 = _set_label((int *)(DAT_001e875c + 0x28));
  if (iVar1 == 0) {
    (*param_1)(param_2,param_3);
  }
  _bcopy(local_3c,(void *)(DAT_001e875c + 0x28),0x38);
  if (-1 < *(char *)(DAT_001e875c + 0x70)) {
    _rpcont();
  }
  return iVar1 == 0;
}

