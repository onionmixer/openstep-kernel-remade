
void _bwrite(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffdf8;
  if ((uVar1 & 0x200) == 0) {
    *(int *)(_active_u + 0x196) = *(int *)(_active_u + 0x196) + 1;
  }
  if ((int)param_1[6] < (int)param_1[5]) {
                    /* WARNING: Subroutine does not return */
    _panic(&aBwrite);
  }
  (**(code **)(*(int *)(param_1[0x10] + 0x1c) + 0x54))(param_1);
  if ((uVar1 & 0x100) == 0) {
    _biowait(param_1);
    _brelse(param_1);
  }
  else if ((uVar1 & 0x200) != 0) {
    *(word *)((int)param_1 + 2) = *(word *)((int)param_1 + 2) | 0x80;
  }
  return;
}

