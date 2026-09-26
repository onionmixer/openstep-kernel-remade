/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011da08 */

int _utimes(char *param_1,timeval *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_54 [32];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar2 = _copyin(puVar1[1],&local_14,0x10);
  *(char *)(DAT_001e875c + 0x68) = (char)iVar2;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    _vattr_null(local_54);
    local_34 = local_14;
    local_30 = local_10;
    local_2c = local_c;
    local_28 = local_8;
    iVar2 = _namesetattr(*puVar1,1,local_54);
    *(char *)(DAT_001e875c + 0x68) = (char)iVar2;
  }
  return iVar2;
}

