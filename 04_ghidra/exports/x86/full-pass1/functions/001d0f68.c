/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001d0f68 */

undefined8 __muldi3(uint param_1,int param_2,uint param_3,int param_4)

{
  undefined4 local_14;
  undefined4 local_10;
  
  local_14 = (undefined4)((ulonglong)param_1 * (ulonglong)param_3);
  local_10 = (int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20);
  return CONCAT44(param_1 * param_4 + param_3 * param_2 + local_10,local_14);
}

