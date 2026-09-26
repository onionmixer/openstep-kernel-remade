/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134d93 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00134d93(void)

{
  int iVar1;
  boolean_t bVar2;
  undefined4 uVar3;
  undefined4 *unaff_EBX;
  char *pcVar4;
  int unaff_ESI;
  XDR *unaff_EDI;
  
  *(undefined2 *)((int)unaff_EBX + 10) = 1;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e917e = _DAT_001e917e + 1;
  _mfree = *unaff_EBX;
  *unaff_EBX = 0;
  unaff_EBX[1] = 0xc;
  _splx();
  if (unaff_EBX == (undefined4 *)0x0) {
    _printf(s_xdr_rrok__FAILED__can_t_get_mbuf_001dcd13);
LAB_00134e5c:
    uVar3 = 0;
  }
  else {
    pcVar4 = (char *)((int)unaff_EBX + unaff_EBX[1]);
    *(code **)pcVar4 = FUN_00134e98;
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    *(undefined4 *)(pcVar4 + 8) = *(undefined4 *)(unaff_ESI + 0x50);
    *(undefined4 *)(pcVar4 + 0xc) = *(undefined4 *)(unaff_ESI + 0x4c);
    *(undefined4 *)(pcVar4 + 0x10) = *(undefined4 *)(unaff_ESI + 0x48);
    *(undefined4 *)(pcVar4 + 0x14) = *(undefined4 *)(unaff_ESI + 0x44);
    unaff_EDI->x_public = pcVar4;
    iVar1 = _xdrmbuf_putbuf();
    if (iVar1 == 0) {
      pcVar4[4] = '\x01';
      pcVar4[5] = '\0';
      pcVar4[6] = '\0';
      pcVar4[7] = '\0';
      bVar2 = _xdr_bytes(unaff_EDI,(char **)(unaff_ESI + 0x48),(uint *)(unaff_ESI + 0x44),0x2000);
      if (bVar2 == 0) goto LAB_00134e5c;
    }
    uVar3 = 1;
  }
  return uVar3;
}

