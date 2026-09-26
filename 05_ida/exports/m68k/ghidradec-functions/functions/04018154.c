
void _biodone(uint *param_1)

{
  uint uVar1;
  
  if ((*param_1 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aDupBiodone);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 | 2;
  if ((uVar1 & 0x200000) == 0) {
    if ((uVar1 & 0x100) == 0) {
      *param_1 = uVar1 & 0xffffffbf | 2;
      _wakeup(param_1);
    }
    else {
      _brelse(param_1);
    }
  }
  else {
    *param_1 = uVar1 & 0xffdfffff | 2;
    (*(code *)param_1[0xc])(param_1);
  }
  return;
}
