/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00126d24 */

void _save_rte(void *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)((int)param_1 + 1);
  if (uVar1 < 0xa4) {
    _bcopy(param_1,&DAT_001e5909,uVar1);
    _ip_nhops = uVar1 - 3 >> 2;
    *(undefined4 *)(&DAT_001e590c + _ip_nhops * 4) = param_2;
    _ip_nhops = _ip_nhops + 1;
  }
  else if (_ipprintfs != 0) {
    _printf(s_save_rte__olen__d_001dbda6,uVar1);
  }
  return;
}

