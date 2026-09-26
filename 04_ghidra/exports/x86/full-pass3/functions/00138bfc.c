/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138bfc */

undefined4 FUN_00138bfc(int param_1,uint param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x30);
  if (param_3 < 2) {
    if (((param_2 & 1) != 0) &&
       (sVar1 = *(short *)(iVar2 + 0x82), *(short *)(iVar2 + 0x82) = sVar1 + -1, sVar1 == 1)) {
      if ((*(ushort *)(iVar2 + 0x88) & 2) != 0) {
        *(ushort *)(iVar2 + 0x88) = *(ushort *)(iVar2 + 0x88) & 0xfffd;
        _wakeup(iVar2 + 0x80);
      }
      if (*(int *)(iVar2 + 0x78) != 0) {
        _selwakeup(*(int *)(iVar2 + 0x78),*(byte *)(iVar2 + 0x88) & 0x10);
        _thread_deallocate(*(undefined4 *)(iVar2 + 0x78));
        *(byte *)(iVar2 + 0x88) = *(byte *)(iVar2 + 0x88) & 0xef;
        *(undefined4 *)(iVar2 + 0x78) = 0;
      }
    }
    if (*(int *)(iVar2 + 0x74) != 0) {
      _thread_deallocate(*(int *)(iVar2 + 0x74));
      *(undefined4 *)(iVar2 + 0x74) = 0;
    }
    if (*(int *)(iVar2 + 0x70) != 0) {
      _thread_deallocate(*(int *)(iVar2 + 0x70));
      *(undefined4 *)(iVar2 + 0x70) = 0;
    }
    if ((((param_2 & 2) != 0) &&
        (sVar1 = *(short *)(iVar2 + 0x80), *(short *)(iVar2 + 0x80) = sVar1 + -1, sVar1 == 1)) &&
       ((*(ushort *)(iVar2 + 0x88) & 1) != 0)) {
      *(ushort *)(iVar2 + 0x88) = *(ushort *)(iVar2 + 0x88) & 0xfffe;
      _wakeup(iVar2 + 0x82);
    }
    if (*(int *)(iVar2 + 0x80) == 0) {
      for (iVar3 = *(int *)(iVar2 + 0x68); iVar3 != 0; iVar3 = FUN_00139560(iVar3,iVar2)) {
      }
      if (*(int *)(iVar2 + 0x7c) != 0) {
        _smark(iVar2,0x42);
      }
      *(undefined4 *)(iVar2 + 0x68) = 0;
      *(undefined2 *)(iVar2 + 0x86) = 0;
      *(undefined2 *)(iVar2 + 0x84) = 0;
      *(undefined4 *)(iVar2 + 0x7c) = 0;
    }
  }
  return 0;
}

