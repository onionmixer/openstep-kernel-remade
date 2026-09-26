/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125f7e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00125f7e(void)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_EBX;
  undefined *puVar4;
  int unaff_EBP;
  short *psVar5;
  
  iVar2 = 0xff;
  puVar3 = &DAT_001eacef;
  do {
    *puVar3 = (char)((unaff_EBX + -0x1dbb64) * -0x55555555 >> 4);
    puVar3 = puVar3 + -1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  if (PTR__inetsw_001dbcc8 < PTR__inetdomain_001dbccc) {
    psVar5 = (short *)(PTR__inetsw_001dbcc8 + 8);
    puVar4 = PTR__inetsw_001dbcc8;
    do {
      if (((**(int **)(psVar5 + -2) == 2) && (sVar1 = *psVar5, sVar1 != 0)) && (sVar1 != 0xff)) {
        (&_ip_protox)[sVar1] = (char)((int)(puVar4 + -0x1dbb64) * -0x55555555 >> 4);
      }
      psVar5 = psVar5 + 0x18;
      puVar4 = puVar4 + 0x30;
    } while (puVar4 < PTR__inetdomain_001dbccc);
  }
  _DAT_001eaa94 = &_ipq;
  _ipq = &_ipq;
  _getthetime();
  _ip_id = *(undefined2 *)(unaff_EBP + -8);
  DAT_001eaa7c = _ipqmaxlen;
  return;
}

