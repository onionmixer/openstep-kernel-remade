/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001196bf */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001196bf(void)

{
  short *psVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 *unaff_EDI;
  
  *(int *)(_active_u + 0x160) = _rootdir;
  psVar1 = (short *)(*(int *)(_active_u + 0x160) + 6);
  *psVar1 = *psVar1 + 1;
  *(undefined4 *)(_active_u + 0x164) = 0;
  if (_rootname != '\0') {
    iVar2 = _lookupname(&_rootname,1,1,0);
    if (iVar2 == 0) {
      _rootdir = *(int *)(unaff_EBP + -4);
      _vn_rele();
      _vn_rele(*(undefined4 *)(_active_u + 0x160));
      *(int *)(_active_u + 0x160) = _rootdir;
      *(short *)(_rootdir + 6) = *(short *)(_rootdir + 6) + 1;
    }
  }
  _DAT_001e9988 = _rootvp;
  _strcpy(&_rootfs,(char *)*unaff_EDI);
  _DAT_001e9984 = 0;
  _DAT_001e9980 = 1;
  return;
}

