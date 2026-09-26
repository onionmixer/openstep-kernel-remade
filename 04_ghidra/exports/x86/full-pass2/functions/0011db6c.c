/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011db6c */

int _truncate(char *param_1,off_t param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 local_44 [24];
  undefined4 local_2c;
  
  iVar3 = DAT_001e875c;
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  if ((int)puVar1[1] < 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  else {
    _vattr_null(local_44);
    local_2c = puVar1[1];
    uVar2 = _namesetattr(*puVar1,1,local_44);
    iVar3 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  }
  return iVar3;
}

