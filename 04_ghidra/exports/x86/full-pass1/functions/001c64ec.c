/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c64ec */

void FUN_001c64ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  
  cVar1 = *(char *)(param_4 + 8);
  if ((cVar1 != '\0') && (*(char *)(param_4 + 8) = cVar1 + -1, cVar1 == '\x01')) {
    _objc_msgSend(param_1,PTR_s__displayCursor_shmem__001f95ac,param_3,param_4);
  }
  return;
}

