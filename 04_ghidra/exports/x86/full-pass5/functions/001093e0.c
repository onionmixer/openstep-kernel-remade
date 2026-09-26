/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001093e0 */

int _sigblock(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  iVar3 = *_active_u;
  _splhigh();
  *(undefined4 *)(DAT_001e875c + 0x60) = *(undefined4 *)(iVar3 + 0x1c);
  if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
    uVar2 = *puVar1 & 0xfffafeff;
  }
  else {
    uVar2 = *puVar1 & 0xfffefeff;
  }
  *(uint *)(iVar3 + 0x1c) = uVar2 | *(uint *)(iVar3 + 0x1c);
  iVar3 = _spl0();
  return iVar3;
}

