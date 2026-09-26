
void _sofree(uint param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 8) == 0) && ((*(byte *)(param_1 + 7) & 1) != 0)) {
    if (*(int *)(param_1 + 0x10) != 0) {
      iVar1 = _soqremque(param_1,0);
      if (iVar1 == 0) {
        iVar1 = _soqremque(param_1,1);
        if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aSofreeDq);
        }
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    _sbrelease(param_1 + 0x38);
    _sorflush(param_1);
    _m_free(param_1 & 0xffffff80);
  }
  return;
}

