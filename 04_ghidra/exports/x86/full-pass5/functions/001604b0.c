/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001604b0 */

void _ns_timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  
  lVar1 = _clock_value(1);
  _calloutDispatchDelayed(param_1,param_2,lVar1 + CONCAT44(param_4,param_3));
  return;
}

