/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c1748 */

/* Entry confirmed from original binary metadata: IODirectDevice(IOPCIDirectDevice) isPCIPresent */

int FUN_001c1748(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = _objc_msgSend(PTR_s_KernBus_001f9d8c,PTR_s_lookupBusInstanceWithName_busId__001f9310,"PCI"
                        ,0);
  if (iVar2 != 0) {
    cVar1 = _objc_msgSend(iVar2,PTR_s_isPCIPresent_001f9680);
    return (int)cVar1;
  }
  return 0;
}

