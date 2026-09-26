/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00194890 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00194890(void)

{
  mach_header *mhp;
  section *psVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < _DAT_00011154) {
    do {
      mhp = *(mach_header **)(&DAT_00011168 + iVar2 * 8);
      psVar1 = _getsectbynamefromheader(mhp,s___DATA_001e2cea,s___bss_001e2ce4);
      if (psVar1 != (section *)0x0) {
        _bzero((void *)psVar1->addr,psVar1->size);
      }
      _objc_registerModule(mhp,0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < _DAT_00011154);
  }
  return;
}

