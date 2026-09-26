/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011cce0 */

int _open(char *param_1,int param_2,...)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = _get_posix_proc((int)*(short *)(*_active_u + 0x30));
  *(byte *)(iVar3 + 0x18) =
       *(byte *)(iVar3 + 0x18) & 0xfd | ((byte)((uint)puVar1[1] >> 4) & 1) * '\x02';
  uVar2 = _copen(*puVar1,puVar1[1] + 1,puVar1[2]);
  iVar4 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  *(byte *)(iVar3 + 0x18) = *(byte *)(iVar3 + 0x18) & 0xfd;
  return iVar4;
}

