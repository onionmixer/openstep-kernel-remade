
undefined4 _mbuf_read(undefined4 *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (param_1 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    if ((uVar2 <= param_3) && (param_3 < (int)*(sword *)(param_1 + 2) + uVar2)) {
      uVar1 = (int)*(sword *)(param_1 + 2) - (param_3 - uVar2);
      if (param_4 < uVar1) {
        uVar1 = param_4;
      }
      _bcopy((int)param_1 + (param_3 - uVar2) + param_1[1],param_2,uVar1);
      param_2 = uVar1 + param_2;
      param_3 = uVar1 + param_3;
      param_4 = param_4 - uVar1;
      if (param_4 == 0) {
        return 0;
      }
    }
    uVar2 = (int)*(sword *)(param_1 + 2) + uVar2;
    param_1 = (undefined4 *)*param_1;
  } while( true );
}
