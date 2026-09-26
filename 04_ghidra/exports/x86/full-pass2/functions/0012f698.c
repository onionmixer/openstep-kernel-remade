/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f698 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0012f698(int param_1)

{
  *(undefined4 *)(param_1 + 8) =
       (&_rtable)
       [(byte)(*(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x4b) ^ *(byte *)(param_1 + 0x4c) ^
               *(byte *)(param_1 + 0x4d) ^ *(byte *)(param_1 + 0x4e) ^ *(byte *)(param_1 + 0x4f) ^
               *(byte *)(param_1 + 0x50) ^ *(byte *)(param_1 + 0x51) ^ *(byte *)(param_1 + 0x54) ^
               *(byte *)(param_1 + 0x55) ^ *(byte *)(param_1 + 0x56) ^ *(byte *)(param_1 + 0x57) ^
               *(byte *)(param_1 + 0x58) ^ *(byte *)(param_1 + 0x59) ^ *(byte *)(param_1 + 0x5a) ^
              *(byte *)(param_1 + 0x5b)) & 0x3f];
  (&_rtable)
  [(byte)(*(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x4b) ^ *(byte *)(param_1 + 0x4c) ^
          *(byte *)(param_1 + 0x4d) ^ *(byte *)(param_1 + 0x4e) ^ *(byte *)(param_1 + 0x4f) ^
          *(byte *)(param_1 + 0x50) ^ *(byte *)(param_1 + 0x51) ^ *(byte *)(param_1 + 0x54) ^
          *(byte *)(param_1 + 0x55) ^ *(byte *)(param_1 + 0x56) ^ *(byte *)(param_1 + 0x57) ^
          *(byte *)(param_1 + 0x58) ^ *(byte *)(param_1 + 0x59) ^ *(byte *)(param_1 + 0x5a) ^
         *(byte *)(param_1 + 0x5b)) & 0x3f] = param_1;
  __rnhash = __rnhash + 1;
  return;
}

