/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d8f4 */

int _chmod(char *param_1,mode_t param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 local_44 [4];
  ushort local_40;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  _vattr_null(local_44);
  local_40 = *(ushort *)(puVar1 + 1) & 0xfff;
  uVar2 = _namesetattr(*puVar1,1,local_44);
  iVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  return iVar3;
}

