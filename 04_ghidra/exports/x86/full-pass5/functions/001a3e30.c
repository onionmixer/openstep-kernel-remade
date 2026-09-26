/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a3e30 */

undefined4 FUN_001a3e30(int param_1,undefined4 *param_2)

{
  int *piVar1;
  
  _objc_msgSend(DAT_001e8684,PTR_s_lock_001f9220);
  piVar1 = DAT_001e867c;
  while( true ) {
    if ((int **)piVar1 == &DAT_001e867c) {
      _objc_msgSend(DAT_001e8684,PTR_s_unlock_001f9474);
      return 0xfffffd29;
    }
    if (*piVar1 == param_1) break;
    piVar1 = (int *)piVar1[5];
  }
  *param_2 = piVar1;
  _objc_msgSend(DAT_001e8684,PTR_s_unlock_001f9474);
  return 0;
}

