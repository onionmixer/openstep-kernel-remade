
undefined4 _np_close(byte param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (sword)(word)param_1 * 0x14c;
  iVar1 = *(int *)(DAT_40c3b2a + iVar3 + 0x18);
  iVar2 = *(int *)(DAT_40c3b2a + iVar3 + 0x1c);
  *(uint *)(DAT_40c3b2a + iVar3) = *(uint *)(DAT_40c3b2a + iVar3) & 0xfffffffd;
  *(undefined4 *)(DAT_40c3b2a + iVar3 + 0x18) = 0;
  *(undefined4 *)(DAT_40c3b2a + iVar3 + 0x1c) = 0;
  if (iVar1 != 0) {
    _thread_deallocate(iVar1);
  }
  if (iVar2 != 0) {
    _thread_deallocate(iVar2);
  }
  return 0;
}
