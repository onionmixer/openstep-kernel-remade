
undefined4 sub_4054012(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  uVar1 = 0;
  puVar2 = dword_40B4DC0;
  if ((undefined4 **)dword_40B4DC0 != &dword_40B4DC0) {
    do {
      if ((param_1 == puVar2[2]) && (param_2 == puVar2[3])) {
        puVar3 = (undefined4 *)*puVar2;
        puVar3[1] = puVar2[1];
        *(undefined4 *)puVar2[1] = *puVar2;
        dword_40B4DD0 = dword_40B4DD0 + -1;
        puVar2[7] = 0;
        if ((&DAT_40b45b3 < puVar2) && (puVar2 < &DAT_40b4db4)) {
          *puVar2 = &dword_40B4DB8;
          puVar2[1] = dword_40B4DBC;
          *(undefined4 **)puVar2[1] = puVar2;
          dword_40B4DBC = puVar2;
        }
        uVar1 = 1;
        if (param_3 == 0) {
          return 1;
        }
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar2 = puVar3;
    } while ((undefined4 **)puVar3 != &dword_40B4DC0);
  }
  return uVar1;
}
