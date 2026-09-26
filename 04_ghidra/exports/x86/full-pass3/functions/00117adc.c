/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117adc */

int _setsockopt(int param_1,int param_2,int param_3,void *param_4,socklen_t param_5)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar6 = 0;
  iVar3 = _getsock(*puVar1);
  iVar4 = DAT_001e875c;
  iVar5 = 0;
  if (iVar3 != 0) {
    if ((int)puVar1[4] < 0x71) {
      if (puVar1[3] != 0) {
        iVar6 = _m_get(1,10);
        iVar4 = DAT_001e875c;
        if (iVar6 == 0) {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x37;
          return iVar4;
        }
        uVar2 = _copyin(puVar1[3],iVar6 + *(int *)(iVar6 + 4),puVar1[4]);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
        if (*(char *)(DAT_001e875c + 0x68) != '\0') {
          iVar4 = _m_free(iVar6);
          return iVar4;
        }
        *(undefined2 *)(iVar6 + 8) = *(undefined2 *)(puVar1 + 4);
      }
      uVar2 = _sosetopt(*(undefined4 *)(iVar3 + 0x18),puVar1[1],puVar1[2],iVar6);
      iVar5 = DAT_001e875c;
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    }
    else {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      iVar5 = iVar4;
    }
  }
  return iVar5;
}

