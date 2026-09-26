/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010cd54 */

ssize_t _read(int param_1,void *param_2,size_t param_3)

{
  ssize_t sVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  
  local_24 = *(undefined4 *)(*(int *)(DAT_001e875c + 0x24) + 4);
  local_20 = *(undefined4 *)(*(int *)(DAT_001e875c + 0x24) + 8);
  local_1c = &local_24;
  local_18 = 1;
  sVar1 = _rwuio(&local_1c,0);
  return sVar1;
}

