/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a54f8 */

void _IOGetTimestamp(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = _clock_value(1);
  *param_1 = uVar1;
  return;
}

