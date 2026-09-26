/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a394 */

undefined4 _incore(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = param_2 + 7;
  }
  uVar3 = (iVar2 >> 3) + param_1 & 0xf;
  puVar1 = (undefined *)(&DAT_001e8884)[uVar3 * 3];
  while( true ) {
    if (puVar1 == &_bufhash + uVar3 * 0xc) {
      return 0;
    }
    if (((*(int *)(puVar1 + 0x24) == param_2) && (*(int *)(puVar1 + 0x40) == param_1)) &&
       ((puVar1[2] & 1) == 0)) break;
    puVar1 = *(undefined **)(puVar1 + 4);
  }
  return 1;
}

