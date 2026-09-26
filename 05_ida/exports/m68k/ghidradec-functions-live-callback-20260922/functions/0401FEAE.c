
undefined4 *
_in_pcblookup(undefined4 *param_1,uint param_2,sword param_3,int param_4,sword param_5,byte param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar4 = (undefined4 *)0x0;
  uVar3 = 3;
  puVar1 = (undefined4 *)*param_1;
  do {
    if (param_1 == puVar1) {
      return puVar4;
    }
    if (param_5 == *(sword *)((int)puVar1 + 0x16)) {
      uVar5 = 0;
      if (*(int *)((int)puVar1 + 0x12) == 0) {
        if (param_4 != 0) goto loc_401FEF0;
      }
      else {
        if (param_4 != 0) {
          if (param_4 == *(int *)((int)puVar1 + 0x12)) goto loc_401FEF4;
          goto loc_401FF36;
        }
loc_401FEF0:
        uVar5 = 1;
      }
loc_401FEF4:
      uVar2 = puVar1[3];
      if (uVar2 == 0) {
        if (param_2 != 0) goto loc_401FF1E;
      }
      else {
        if (param_2 != 0) {
          if (((param_3 == *(sword *)(puVar1 + 4)) && ((uVar2 & 0xf0000000) != 0xe0000000)) &&
             (param_2 == uVar2)) goto loc_401FF20;
          goto loc_401FF36;
        }
loc_401FF1E:
        uVar5 = uVar5 + 1;
      }
loc_401FF20:
      if (((uVar5 == 0) || ((param_6 & 1) != 0)) &&
         ((uVar5 < uVar3 && (uVar3 = uVar5, puVar4 = puVar1, uVar5 == 0)))) {
        return puVar1;
      }
    }
loc_401FF36:
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

