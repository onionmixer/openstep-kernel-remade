
/* WARNING: Instruction at (ram,0xf0006388) overlaps instruction at (ram,0xf0006384)
    */

void _memset(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (6 < (int)param_3) {
    for (; uVar1 = param_3 & 0xfffffffc, ((uint)param_1 & 3) != 0;
        param_1 = (uint *)((int)param_1 + 1)) {
      param_3 = param_3 - 1;
      *(char *)param_1 = (char)param_2;
    }
    param_2 = param_2 & 0xff | (param_2 & 0xff) << 8;
    param_2 = param_2 | param_2 << 0x10;
    do {
      *param_1 = param_2;
      uVar1 = uVar1 - 4;
      param_1 = param_1 + 1;
    } while (uVar1 != 0);
    param_3 = param_3 & 3;
  }
  while( true ) {
    if ((int)param_3 < 1) break;
    *(char *)param_1 = (char)param_2;
    param_3 = param_3 - 1;
    param_1 = (uint *)((int)param_1 + 1);
  }
  return;
}

