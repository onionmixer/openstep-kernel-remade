/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117cac */

int _pipe(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  uVar2 = _socreate(1,&local_8,1,0);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  iVar4 = DAT_001e875c;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    uVar2 = _socreate(1,&local_c,1,0);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      iVar4 = _falloc();
      if (iVar4 != 0) {
        iVar1 = *(int *)(DAT_001e875c + 0x60);
        *(undefined4 *)(iVar4 + 8) = 1;
        if ((*(byte *)(*_active_u + 0x16) & 2) != 0) {
          *(undefined4 *)(iVar4 + 8) = 0x2001;
        }
        *(undefined2 *)(iVar4 + 0xc) = 2;
        *(undefined ***)(iVar4 + 0x14) = &_socketops;
        *(int *)(iVar4 + 0x18) = local_8;
        *(int *)(_active_u[0x54] + *(int *)(DAT_001e875c + 0x60) * 4) = iVar4;
        iVar5 = _falloc();
        if (iVar5 != 0) {
          *(undefined4 *)(iVar5 + 8) = 2;
          if ((*(byte *)(*_active_u + 0x16) & 2) != 0) {
            *(undefined4 *)(iVar5 + 8) = 0x2002;
          }
          *(undefined2 *)(iVar5 + 0xc) = 2;
          *(undefined ***)(iVar5 + 0x14) = &_socketops;
          *(int *)(iVar5 + 0x18) = local_c;
          *(int *)(_active_u[0x54] + *(int *)(DAT_001e875c + 0x60) * 4) = iVar5;
          *(undefined4 *)(DAT_001e875c + 100) = *(undefined4 *)(DAT_001e875c + 0x60);
          *(int *)(DAT_001e875c + 0x60) = iVar1;
          cVar3 = _unp_connect2(local_c,local_8);
          *(char *)(DAT_001e875c + 0x68) = cVar3;
          if (cVar3 == '\0') {
            *(byte *)(local_c + 6) = *(byte *)(local_c + 6) | 0x20;
            *(byte *)(local_8 + 6) = *(byte *)(local_8 + 6) | 0x10;
            return local_8;
          }
          *(undefined2 *)(iVar5 + 0xe) = 0;
          *(undefined4 *)(_active_u[0x54] + *(int *)(DAT_001e875c + 100) * 4) = 0;
        }
        *(undefined2 *)(iVar4 + 0xe) = 0;
        *(undefined4 *)(_active_u[0x54] + iVar1 * 4) = 0;
      }
      _soclose(local_c);
    }
    iVar4 = _soclose(local_8);
  }
  return iVar4;
}

