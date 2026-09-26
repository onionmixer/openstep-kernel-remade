/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d978 */

int _chown(char *param_1,uid_t param_2,gid_t param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 local_44 [6];
  undefined2 local_3e;
  undefined2 local_3c;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  _vattr_null(local_44);
  local_3e = *(undefined2 *)(puVar1 + 1);
  local_3c = *(undefined2 *)(puVar1 + 2);
  uVar2 = _namesetattr(*puVar1,0,local_44);
  iVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  return iVar3;
}

