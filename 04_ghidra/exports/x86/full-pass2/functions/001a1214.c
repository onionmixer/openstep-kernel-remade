/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1214 */

undefined4 _PCcopyBIOSExtData(int param_1)

{
  int iVar1;
  
  iVar1 = _bios_extdata_addr();
  if ((param_1 != 0) && (iVar1 = _copyout(iVar1,param_1,0xa0000 - iVar1), iVar1 == 0)) {
    return 0;
  }
  return 4;
}

