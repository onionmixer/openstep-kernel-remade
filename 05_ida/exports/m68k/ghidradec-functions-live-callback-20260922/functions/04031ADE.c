
undefined4 * sub_4031ADE(word param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(_stable + ((uint)(byte)param_1 + (uint)(param_1 >> 8) & 0xf) * 4);
  do {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if ((param_1 == *(word *)(puVar1 + 0x10)) && (param_3 == puVar1[0xb])) {
      iVar2 = *(int *)((int)puVar1 + 0x36);
      if (iVar2 != 0) {
        if (param_2 != 0) {
          if (param_2 == iVar2) goto loc_4031B52;
          if (iVar2 == 0) goto loc_4031B4E;
          if ((*(int *)(iVar2 + 0x1c) == *(int *)(param_2 + 0x1c)) &&
             (iVar2 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x6c))(iVar2,param_2), iVar2 != 0))
          goto loc_4031B52;
        }
        if (*(int *)((int)puVar1 + 0x36) != 0) goto loc_4031B5A;
      }
loc_4031B4E:
      if (param_2 == 0) {
loc_4031B52:
        *(sword *)((int)puVar1 + 10) = *(sword *)((int)puVar1 + 10) + 1;
        return puVar1;
      }
    }
loc_4031B5A:
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

