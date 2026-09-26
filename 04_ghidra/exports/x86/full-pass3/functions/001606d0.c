/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001606d0 */

undefined8 _ticks_to_ns_time(uint param_1)

{
  undefined8 local_c;
  
  local_c._4_4_ = (int)((ulonglong)_ns_per_tick * (ulonglong)param_1 >> 0x20);
  local_c = CONCAT44(local_c._4_4_ + DAT_001f6534 * param_1,
                     (int)((ulonglong)_ns_per_tick * (ulonglong)param_1));
  return local_c;
}

