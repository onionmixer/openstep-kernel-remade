/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00128240 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rip_input(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + *(int *)(param_1 + 4);
  _DAT_001dbe3e = (ushort)*(byte *)(iVar1 + 9);
  _DAT_001dbe20 = *(undefined4 *)(iVar1 + 0x10);
  _DAT_001dbe30 = *(undefined4 *)(iVar1 + 0xc);
  _raw_input(param_1,&_ripproto,&_ripsrc,&_ripdst);
  return;
}

