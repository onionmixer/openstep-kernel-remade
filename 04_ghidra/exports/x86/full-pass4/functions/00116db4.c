/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116db4 */

int _socket(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = _falloc();
  iVar4 = 0;
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 8) = 3;
    *(undefined2 *)(iVar3 + 0xc) = 2;
    *(undefined ***)(iVar3 + 0x14) = &_socketops;
    uVar2 = _socreate(*puVar1,&local_8,puVar1[1],puVar1[2]);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      *(undefined4 *)(iVar3 + 0x18) = local_8;
      iVar4 = *(int *)(_active_u + 0x150);
      *(int *)(iVar4 + *(int *)(DAT_001e875c + 0x60) * 4) = iVar3;
    }
    else {
      iVar4 = *(int *)(_active_u + 0x150);
      *(undefined4 *)(iVar4 + *(int *)(DAT_001e875c + 0x60) * 4) = 0;
      *(undefined2 *)(iVar3 + 0xe) = 0;
    }
  }
  return iVar4;
}

