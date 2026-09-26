/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011aa3c */

int _getnewbuf_count(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar2 = _splbio();
  puVar3 = (undefined4 *)&DAT_001e87e8;
  do {
    for (puVar1 = (undefined4 *)puVar3[3]; puVar1 != puVar3; puVar1 = (undefined4 *)puVar1[3]) {
      iVar4 = iVar4 + 1;
    }
    puVar3 = puVar3 + -0x11;
  } while (&_bfreelist < puVar3);
  _splx(uVar2);
  return iVar4;
}

