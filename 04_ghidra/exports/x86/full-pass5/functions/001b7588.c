/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b7588 */

void FUN_001b7588(undefined4 param_1,undefined4 param_2)

{
  if (DAT_001e5380 != '\0') {
    DAT_001e5384 = DAT_001e5384 + DAT_001e5388;
    if (DAT_001e538c != (code *)0x0) {
      (*DAT_001e538c)();
      return;
    }
  }
  _IOGetTimestamp(&DAT_001e8710);
  _IOSendInterrupt(param_1,param_2,0x232325);
  return;
}

