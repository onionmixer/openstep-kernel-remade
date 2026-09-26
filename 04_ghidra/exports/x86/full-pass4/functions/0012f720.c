/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f720 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rp_rmhash(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = (&_rtable)
          [(byte)(*(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x4b) ^ *(byte *)(param_1 + 0x4c)
                  ^ *(byte *)(param_1 + 0x4d) ^ *(byte *)(param_1 + 0x4e) ^
                  *(byte *)(param_1 + 0x4f) ^ *(byte *)(param_1 + 0x50) ^ *(byte *)(param_1 + 0x51)
                  ^ *(byte *)(param_1 + 0x54) ^ *(byte *)(param_1 + 0x55) ^
                  *(byte *)(param_1 + 0x56) ^ *(byte *)(param_1 + 0x57) ^ *(byte *)(param_1 + 0x58)
                  ^ *(byte *)(param_1 + 0x59) ^ *(byte *)(param_1 + 0x5a) ^
                 *(byte *)(param_1 + 0x5b)) & 0x3f];
  while( true ) {
    if (iVar2 == 0) {
      return;
    }
    if (iVar2 == param_1) break;
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar2 + 8);
  }
  if (iVar1 == 0) {
    (&_rtable)
    [(byte)(*(byte *)(iVar2 + 0x4a) ^ *(byte *)(iVar2 + 0x4b) ^ *(byte *)(iVar2 + 0x4c) ^
            *(byte *)(iVar2 + 0x4d) ^ *(byte *)(iVar2 + 0x4e) ^ *(byte *)(iVar2 + 0x4f) ^
            *(byte *)(iVar2 + 0x50) ^ *(byte *)(iVar2 + 0x51) ^ *(byte *)(iVar2 + 0x54) ^
            *(byte *)(iVar2 + 0x55) ^ *(byte *)(iVar2 + 0x56) ^ *(byte *)(iVar2 + 0x57) ^
            *(byte *)(iVar2 + 0x58) ^ *(byte *)(iVar2 + 0x59) ^ *(byte *)(iVar2 + 0x5a) ^
           *(byte *)(iVar2 + 0x5b)) & 0x3f] = *(undefined4 *)(iVar2 + 8);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
  }
  __rnhash = __rnhash + -1;
  return;
}

