
void _adb_mouse_init(undefined4 param_1,undefined *param_2)

{
  undefined8 *puVar1;
  undefined *apuStack_14 [3];
  int iStack_8;
  
  byte_40B4F43 = byte_40B4F43 | 1;
  _adb_talk(param_1,3,param_2,&iStack_8);
  param_2[1] = 4;
  _adb_listen(param_1,3,param_2,2);
  _adb_talk(param_1,3,param_2,&iStack_8);
  if ((param_2[1] == '\x04') && (_adb_talk(param_1,1,param_2,&iStack_8), iStack_8 == 8)) {
    apuStack_14[0] = (undefined *)&aTablet;
    apuStack_14[1] = (undefined *)&aMouse;
    apuStack_14[2] = aTrackball;
    puVar1 = &aUnknown_0;
    _printf(aFoundAdbDevice);
    _printf(aIdCCCC,*param_2,param_2[1],param_2[2],param_2[3]);
    _printf(aResolutionDUni,*(undefined2 *)(param_2 + 4));
    _printf(aClassD,param_2[6]);
    if ((byte)param_2[6] < 3) {
      puVar1 = (undefined8 *)apuStack_14[(byte)param_2[6]];
    }
    _printf(&aS_1,puVar1);
    _printf(aWithDButtons,param_2[7]);
    byte_40B4F43 = byte_40B4F43 | 8;
    return;
  }
  _adb_talk(param_1,3,param_2,&iStack_8);
  param_2[1] = 3;
  _adb_listen(param_1,3,param_2,2);
  _adb_talk(param_1,3,param_2,&iStack_8);
  if ((param_2[1] == '\x03') && (_adb_talk(param_1,1,param_2,&iStack_8), iStack_8 == 8)) {
    *param_2 = 0;
    param_2[1] = 0x83;
    _adb_listen(param_1,1,param_2,8);
    *param_2 = 1;
    param_2[1] = 0x82;
    _adb_listen(param_1,1,param_2,8);
    *param_2 = 2;
    param_2[1] = 0x81;
    _adb_listen(param_1,1,param_2,8);
    byte_40B4F43 = byte_40B4F43 | 2;
  }
  return;
}

