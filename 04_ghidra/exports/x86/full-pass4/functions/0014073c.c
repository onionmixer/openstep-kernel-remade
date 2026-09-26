/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014073c */

void _ihinit(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &_ihead;
  iVar2 = 0x1ff;
  do {
    *puVar1 = puVar1;
    puVar1[1] = puVar1;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  _ifreeh = 0;
  _ifreet = 0;
  _inode_list = 0;
  _inode_zone = _zinit(0xe8,0x236680,0,0,s_inode_structures_001ddfc1);
  return;
}

