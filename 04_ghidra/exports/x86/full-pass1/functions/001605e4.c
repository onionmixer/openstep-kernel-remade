/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001605e4 */

undefined8 _timeval_to_ns_time(int *param_1)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = (longlong)*param_1 * 1000000 + (longlong)param_1[1];
  lVar1 = lVar1 + CONCAT44((int)((ulonglong)lVar1 >> 0x20) * 4 | (uint)lVar1 >> 0x1e,(uint)lVar1 * 4
                          );
  lVar1 = lVar1 + CONCAT44((int)((ulonglong)lVar1 >> 0x20) * 4 | (uint)lVar1 >> 0x1e,(uint)lVar1 * 4
                          );
  lVar1 = lVar1 + CONCAT44((int)((ulonglong)lVar1 >> 0x20) * 4 | (uint)lVar1 >> 0x1e,(uint)lVar1 * 4
                          );
  uVar2 = (uint)lVar1;
  return CONCAT44((int)((ulonglong)lVar1 >> 0x20) * 8 | uVar2 >> 0x1d,uVar2 * 8);
}

