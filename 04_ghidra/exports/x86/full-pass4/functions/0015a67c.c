/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a67c */

void _kalloc_init(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  _kalloc_map = _kernel_map;
  iVar3 = 0;
  pcVar4 = &DAT_001e5a98;
  do {
    uVar1 = (&_k_zone_elemsize)[iVar3];
    if (_page_size <= uVar1) {
      return;
    }
    _sprintf(pcVar4,s_kalloc__d_001ded58,uVar1);
    uVar2 = _zinit(uVar1,0x100000,_page_size,0,pcVar4);
    (&_k_zone)[iVar3] = uVar2;
    pcVar4 = pcVar4 + 0x10;
    iVar3 = iVar3 + 1;
    _k_zone_maxsize = uVar1;
  } while (iVar3 < 0x10);
  return;
}

