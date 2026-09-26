/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016032c */

undefined4 FUN_0016032c(void)

{
  undefined *puVar1;
  undefined **ppuVar2;
  
  _safe_prf(s_Mini_monitor_commands__001df192);
  _safe_prf(s___help___Print_this_message_001df1aa);
  ppuVar2 = &_miniMonCommands;
  puVar1 = _miniMonCommands;
  while (puVar1 != (undefined *)0x0) {
    if (ppuVar2[2] != (undefined *)0x0) {
      _safe_prf(s__s____s_001df1c7,*ppuVar2,ppuVar2[2]);
    }
    ppuVar2 = ppuVar2 + 3;
    puVar1 = *ppuVar2;
  }
  ppuVar2 = &_miniMonMDCommands;
  puVar1 = _miniMonMDCommands;
  while (puVar1 != (undefined *)0x0) {
    if (ppuVar2[2] != (undefined *)0x0) {
      _safe_prf(s__s____s_001df1d0,*ppuVar2,ppuVar2[2]);
    }
    ppuVar2 = ppuVar2 + 3;
    puVar1 = *ppuVar2;
  }
  return 1;
}

