/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018cf7c */

void _md_prepare_for_shutdown(undefined4 param_1,byte param_2)

{
  char *pcVar1;
  
  if ((param_2 & 8) != 0) {
    pcVar1 = (char *)_kmLocalizeString(s_Please_wait_until_it_s_safe_to_t_001e23eb);
    _printf(pcVar1);
    if (_prettyShutdown != 0) {
      _kmGraphicPanelString(pcVar1);
    }
  }
  return;
}

