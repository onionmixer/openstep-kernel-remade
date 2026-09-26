
void _adb_initialize(void)

{
  int iVar1;
  uint uVar2;
  word unaff_D3w;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint *puVar7;
  undefined *puVar8;
  undefined2 uVar9;
  int iStack_10;
  byte bStack_c;
  undefined uStack_b;
  
  iVar1 = _mon_global;
  uVar6 = 0;
  puVar5 = (undefined4 *)(_slot_id + 0x2208008);
  *(undefined4 *)(_slot_id + 0x2208018) = 0;
  *puVar5 = 0;
  sub_40645B6(1);
  uVar2 = 1;
  puVar8 = unk_40B4EA0;
  puVar7 = &unk_40B4E9C;
  uVar3 = 0;
  do {
    _adb_talk(uVar2,3,&bStack_c,&iStack_10);
    uVar4 = uVar3;
    if (iStack_10 != 0) {
      *puVar7 = uVar2;
      *puVar8 = uStack_b;
      _printf(aAdbDeviceXReg3,uVar2,bStack_c,uStack_b);
      if ((bStack_c & 0x20) == 0) {
        bStack_c = bStack_c | 0x20;
        _adb_listen(uVar2,3,&bStack_c,iStack_10);
      }
      if (uVar2 == 2) {
        _adb_keybd_init(2,&bStack_c);
      }
      else if (uVar2 == 3) {
        _adb_mouse_init(3,&bStack_c);
      }
      uVar4 = uVar2;
      if (uVar3 != 0) {
        *(uint *)((int)&dword_40B4E98 + uVar6 * 10) = uVar2;
        uVar4 = uVar3;
      }
      uVar6 = uVar2;
      if (dword_40B0830 != 3) {
        dword_40B0830 = uVar2;
      }
    }
    puVar8 = puVar8 + 10;
    puVar7 = (uint *)((int)puVar7 + 10);
    uVar2 = uVar2 + 1;
    uVar3 = uVar4;
  } while ((int)uVar2 < 8);
  if (uVar6 != 0) {
    *(uint *)((int)&dword_40B4E98 + uVar6 * 10) = uVar4;
  }
  dword_40B0834 = dword_40B0830;
  if (dword_40B0830 != 0) {
    _callout_dispatch(2,sub_40643E6,0);
    *(byte *)(iVar1 + 0x3ae) = *(byte *)(iVar1 + 0x3ae) | 0x10;
    uVar9 = 0;
    _adb_watchdog(1);
    sub_40645EA(CONCAT22(uVar9,unaff_D3w & 0xcff | (word)((dword_40B0834 & 0xf) << 0xc)) | 0xc00,0,0
                ,0);
  }
  return;
}

