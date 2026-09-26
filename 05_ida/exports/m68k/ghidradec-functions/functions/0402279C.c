
void _ip_freemoptions(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 4) + param_1;
    iVar1 = 0;
    if (*(sword *)(iVar2 + 6) != 0) {
      do {
        _in_delmulti(*(undefined4 *)(iVar2 + 8 + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)(uint)*(word *)(iVar2 + 6));
    }
    _m_free(param_1);
  }
  return;
}
