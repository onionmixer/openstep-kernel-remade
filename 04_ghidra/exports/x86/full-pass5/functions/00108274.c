/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108274 */

undefined4 _entergroup(short param_1)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = *(int *)(_active_u + 0x1c);
  psVar2 = (short *)(iVar1 + 10);
  while( true ) {
    if ((short *)(iVar1 + 0x2a) <= psVar2) {
      return 0xffffffff;
    }
    if (*psVar2 == param_1) break;
    if (*psVar2 == -1) {
      *psVar2 = param_1;
      return 0;
    }
    psVar2 = psVar2 + 1;
    iVar1 = *(int *)(_active_u + 0x1c);
  }
  return 0;
}

