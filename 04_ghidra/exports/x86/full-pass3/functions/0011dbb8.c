/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011dbb8 */

int _ftruncate(int param_1,off_t param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 local_48 [24];
  undefined4 local_30;
  int local_8;
  
  iVar4 = DAT_001e875c;
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  if ((int)puVar1[1] < 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  else {
    uVar3 = _getvnodefp(*puVar1,&local_8);
    iVar4 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      iVar2 = *(int *)(local_8 + 0x18);
      if ((*(byte *)(local_8 + 8) & 2) == 0) {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
        iVar4 = local_8;
      }
      else {
        iVar4 = *(int *)(iVar2 + 0x24);
        if ((*(byte *)(iVar4 + 0xc) & 1) == 0) {
          _vattr_null(local_48);
          local_30 = puVar1[1];
          uVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x18))
                            (iVar2,local_48,*(undefined4 *)(local_8 + 0x20));
          iVar4 = DAT_001e875c;
          *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
        }
        else {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x1e;
        }
      }
    }
  }
  return iVar4;
}

