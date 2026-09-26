/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196c1c */

void FUN_00196c1c(void)

{
  char local_68 [100];
  
  _printf(s_Really_Shut_down__y_n___001e3e38);
  _gets(local_68);
  if (local_68[0] != 'y') {
    _printf(s____aborting_shutdown_001e3e52);
    return;
  }
  _boot(1,0x90000,&DAT_001e3e68);
  return;
}

