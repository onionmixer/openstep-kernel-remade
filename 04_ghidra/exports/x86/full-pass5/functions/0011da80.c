/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011da80 */

void __utime(void)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = _get_posix_proc((int)*(short *)(*_active_u + 0x30));
  _getthetime(&local_4c);
  _vattr_null(local_44);
  if (((*(byte *)(*_active_u + 0x16) & 2) == 0) || (puVar1[1] != 0)) {
    uVar2 = _copyin(puVar1[1],&local_54,8);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    if (*(char *)(DAT_001e875c + 0x68) != '\0') {
      return;
    }
    local_24 = local_54;
    local_1c = local_50;
    local_18 = 0;
  }
  else {
    local_1c = local_4c;
    local_24 = local_4c;
    local_18 = local_48;
    *(byte *)(iVar3 + 0x18) = *(byte *)(iVar3 + 0x18) | 1;
  }
  local_20 = local_18;
  iVar4 = _namesetattr(*puVar1,1,local_44);
  *(byte *)(iVar3 + 0x18) = *(byte *)(iVar3 + 0x18) & 0xfe;
  if ((((*(byte *)(*_active_u + 0x16) & 2) == 0) || (iVar4 != 1)) || (puVar1[1] != 0)) {
    uVar2 = (undefined1)iVar4;
  }
  else {
    uVar2 = 0xd;
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  return;
}

