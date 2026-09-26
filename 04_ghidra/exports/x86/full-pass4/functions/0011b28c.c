/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b28c */

void _dnlc_init(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  DAT_001e9be8 = &_nc_lru;
  DAT_001e9bec = &_nc_lru;
  iVar5 = 0;
  if (0 < _ncsize) {
    iVar6 = 0;
    do {
      puVar1 = DAT_001e9be8;
      puVar3 = (undefined *)(_ncache + iVar6);
      puVar2 = puVar3;
      *(undefined **)(puVar3 + 8) = DAT_001e9be8;
      DAT_001e9be8 = puVar2;
      *(undefined **)(puVar1 + 0xc) = puVar3;
      *(undefined **)(puVar3 + 0xc) = &_nc_lru;
      *(undefined **)(puVar3 + 4) = puVar3;
      *(undefined **)puVar3 = puVar3;
      *(undefined4 *)(puVar3 + 0x10) = 0;
      *(undefined4 *)(puVar3 + 0x14) = 0;
      puVar3[0x44] = 0;
      iVar6 = iVar6 + 0x48;
      iVar5 = iVar5 + 1;
    } while (iVar5 < _ncsize);
  }
  puVar4 = &_nc_hash;
  iVar5 = 0;
  do {
    *(undefined4 **)((int)&DAT_001e99e4 + iVar5) = puVar4;
    *puVar4 = puVar4;
    puVar4 = puVar4 + 2;
    iVar5 = iVar5 + 8;
  } while ((int)puVar4 < 0x1e9bd9);
  return;
}

