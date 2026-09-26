/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011cf7c */

int _mkdir(char *param_1,mode_t param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 local_48;
  undefined4 local_44;
  ushort local_40;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  _vattr_null(&local_44);
  local_44 = 2;
  local_40 = *(ushort *)(puVar1 + 1) & 0x1ff & ~*(ushort *)(_active_u + 0x16e);
  uVar2 = _vn_create(*puVar1,0,&local_44,1,0,&local_48);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  iVar3 = DAT_001e875c;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    iVar3 = _vn_rele(local_48);
  }
  return iVar3;
}

