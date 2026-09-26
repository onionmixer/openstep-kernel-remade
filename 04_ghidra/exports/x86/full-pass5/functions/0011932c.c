/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011932c */

int _fstatfs(int param_1,statfs *param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  uVar2 = _getvnodefp(*puVar1,&local_8);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  iVar3 = DAT_001e875c;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    iVar3 = _cstatfs(*(undefined4 *)(*(int *)(local_8 + 0x18) + 0x24),puVar1[1]);
  }
  return iVar3;
}

