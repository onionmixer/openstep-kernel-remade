/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125f54 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ip_init(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  short *psVar6;
  undefined2 local_c [4];
  
  iVar2 = _pffindproto(2,0xff,3);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ip_init_001dbd84);
  }
  iVar3 = 0xff;
  puVar4 = &DAT_001eacef;
  do {
    *puVar4 = (char)((iVar2 + -0x1dbb64) * -0x55555555 >> 4);
    puVar4 = puVar4 + -1;
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  if (PTR__inetsw_001dbcc8 < PTR__inetdomain_001dbccc) {
    psVar6 = (short *)(PTR__inetsw_001dbcc8 + 8);
    puVar5 = PTR__inetsw_001dbcc8;
    do {
      if (((**(int **)(psVar6 + -2) == 2) && (sVar1 = *psVar6, sVar1 != 0)) && (sVar1 != 0xff)) {
        (&_ip_protox)[sVar1] = (char)((int)(puVar5 + -0x1dbb64) * -0x55555555 >> 4);
      }
      psVar6 = psVar6 + 0x18;
      puVar5 = puVar5 + 0x30;
    } while (puVar5 < PTR__inetdomain_001dbccc);
  }
  _DAT_001eaa94 = &_ipq;
  _ipq = &_ipq;
  _getthetime(local_c);
  _ip_id = local_c[0];
  DAT_001eaa7c = _ipqmaxlen;
  return;
}

