
undefined4 sub_4038BEC(int param_1,int param_2,uint param_3,undefined4 *param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  
  *param_5 = param_1;
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_2 + 4);
    uVar2 = *(uint *)(param_2 + 8);
    do {
      if ((((param_3 & 1) == 0) || (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc))) &&
         (((param_3 & 2) == 0 || (*(int *)(param_1 + 0xc) != *(int *)(param_2 + 0xc))))) {
        if (((*(uint *)(param_1 + 8) == 0xffffffff) || (uVar1 <= *(uint *)(param_1 + 8))) &&
           ((uVar2 == 0xffffffff || (*(uint *)(param_1 + 4) <= uVar2)))) {
          if ((uVar1 == *(uint *)(param_1 + 4)) && (uVar2 == *(uint *)(param_1 + 8))) {
            return 1;
          }
          if (((*(uint *)(param_1 + 4) <= uVar1) && (uVar2 != 0xffffffff)) &&
             ((uVar2 <= *(uint *)(param_1 + 8) || (*(uint *)(param_1 + 8) == 0xffffffff)))) {
            return 2;
          }
          if ((uVar1 <= *(uint *)(param_1 + 4)) &&
             ((uVar2 == 0xffffffff ||
              ((*(uint *)(param_1 + 8) != 0xffffffff && (*(uint *)(param_1 + 8) <= uVar2)))))) {
            return 3;
          }
          if ((*(uint *)(param_1 + 4) < uVar1) &&
             ((uVar1 <= *(uint *)(param_1 + 8) || (*(uint *)(param_1 + 8) == 0xffffffff)))) {
            return 4;
          }
          if (((uVar1 < *(uint *)(param_1 + 4)) && (uVar2 != 0xffffffff)) &&
             ((uVar2 < *(uint *)(param_1 + 8) || (*(uint *)(param_1 + 8) == 0xffffffff)))) {
            return 5;
          }
                    /* WARNING: Subroutine does not return */
          _panic(aLfFindoverlapD);
        }
        if ((((param_3 & 1) != 0) && (uVar2 != 0xffffffff)) && (uVar2 < *(uint *)(param_1 + 4))) {
          return 0;
        }
      }
      *param_4 = (int *)(param_1 + 0x14);
      param_1 = *(int *)(param_1 + 0x14);
      *param_5 = param_1;
    } while (param_1 != 0);
  }
  return 0;
}
