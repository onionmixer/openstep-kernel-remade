
/* WARNING: Removing unreachable block (ram,0xf0093ce4) */
/* WARNING: Removing unreachable block (ram,0xf0093d40) */
/* WARNING: Removing unreachable block (ram,0xf0093d64) */
/* WARNING: Removing unreachable block (ram,0xf0093d9c) */
/* WARNING: Removing unreachable block (ram,0xf0093cc4) */
/* WARNING: Removing unreachable block (ram,0xf0093c68) */
/* WARNING: Removing unreachable block (ram,0xf0093b6c) */
/* WARNING: Removing unreachable block (ram,0xf0093c7c) */
/* WARNING: Removing unreachable block (ram,0xf0093ca8) */
/* WARNING: Removing unreachable block (ram,0xf0093d74) */
/* WARNING: Removing unreachable block (ram,0xf0093d58) */
/* WARNING: Removing unreachable block (ram,0xf0093d2c) */
/* WARNING: Removing unreachable block (ram,0xf0093cd0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
_vol_panel_request(undefined *param_1,char *param_2,int param_3,char *param_4,int param_5,
                  undefined4 param_6,undefined4 param_7,char *param_8,char *param_9,
                  undefined *param_10,undefined4 *param_11)

{
  int iVar1;
  undefined **ppuVar2;
  char *pcVar3;
  void *pvVar4;
  size_t sVar5;
  undefined **ppuVar6;
  char *pcVar7;
  void *pvVar8;
  
  if (_panel_req_port != 0) {
    pvVar4 = (void *)0x8c;
    _kalloc();
    _memcpy(pvVar4,&DAT_f01125a4,0x8c);
    *(char **)((int)pvVar4 + 0x1c) = param_2;
    *(int *)((int)pvVar4 + 0x20) = param_3;
    *(char **)((int)pvVar4 + 0x28) = param_4;
    *(int *)((int)pvVar4 + 0x2c) = param_5;
    *(undefined4 *)((int)pvVar4 + 0x30) = param_6;
    *(undefined4 *)((int)pvVar4 + 0x34) = param_7;
    *(undefined4 *)((int)pvVar4 + 0xc) = DAT_f0112518;
    iVar1 = _panel_req_port;
    *(int *)((int)pvVar4 + 0x24) = DAT_f0131260;
    *(int *)((int)pvVar4 + 0x10) = iVar1;
    DAT_f0131260 = DAT_f0131260 + 1;
    sVar5 = _strlen(param_8);
    if (0x27 < sVar5) {
      param_8[0x27] = '\0';
    }
    sVar5 = _strlen(param_9);
    if (0x27 < sVar5) {
      param_9[0x27] = '\0';
    }
    _strcpy((char *)((int)pvVar4 + 0x3c),param_8);
    _strcpy((char *)((int)pvVar4 + 100),param_9);
    pvVar8 = pvVar4;
    _msg_send_from_kernel(pvVar4,1,0);
    if (pvVar8 == (void *)0x0) {
      *param_11 = *(undefined4 *)((int)pvVar4 + 0x24);
      if (param_3 != 0) {
        ppuVar6 = (undefined **)0x14;
        _kalloc();
        if (ppuVar6 == (undefined **)0x0) {
          pvVar8 = (void *)0x6;
          goto LAB_f0093dfc;
        }
        ppuVar6[2] = *(undefined **)((int)pvVar4 + 0x24);
        ppuVar6[3] = param_1;
        ppuVar6[4] = param_10;
        ppuVar2 = ppuVar6;
        if (_DAT_f011252c != &PTR_LOOP_f0112528) {
          *_DAT_f011252c = (undefined *)ppuVar6;
          ppuVar2 = (undefined **)PTR_LOOP_f0112528;
        }
        PTR_LOOP_f0112528 = (undefined *)ppuVar2;
        ppuVar6[1] = (undefined *)_DAT_f011252c;
        *ppuVar6 = (undefined *)&PTR_LOOP_f0112528;
        _DAT_f011252c = ppuVar6;
      }
      pvVar8 = (void *)0x0;
    }
    goto LAB_f0093dfc;
  }
  if (param_5 == 1) {
    pcVar7 = s_Optical_f0112658;
  }
  else if (param_5 < 2) {
    if (param_5 == 0) {
      pcVar7 = s_Floppy_f0112650;
    }
    else {
LAB_f0093be4:
      pcVar7 = (char *)0xf0112668;
    }
  }
  else {
    if (param_5 != 2) goto LAB_f0093be4;
    pcVar7 = (char *)0xf0112660;
  }
  switch(param_2) {
  case (char *)0x0:
    pcVar3 = s_Please_Insert__s_Disk__d_in_Driv_f0112670;
    break;
  case (char *)0x1:
    pcVar3 = s_Please_Insert__s_Disk___s__in_Dr_f0112698;
    param_4 = param_8;
    break;
  case (char *)0x2:
    pcVar3 = s_Wrong_Disk__Please_Insert__s_Dis_f01126c0;
    break;
  case (char *)0x3:
    pcVar3 = s_Wrong_Disk__Please_Insert__s_Dis_f01126f8;
    param_4 = param_8;
    break;
  case (char *)0x4:
    _printf(s____Swap_Device_Full____f0112730);
    pvVar8 = (void *)0x0;
    goto LAB_f0093dfc;
  case (char *)0x5:
    pcVar7 = s____File_System__s_Full____f0112748;
    goto LAB_f0093cc4;
  case (char *)0x6:
    _printf(s_Please_Eject__s_Disk__d_f0112768,pcVar7,param_6);
    pvVar8 = (void *)0x0;
    goto LAB_f0093dfc;
  default:
    pcVar7 = s_vol_panel_request__bogus_panel_t_f0112788;
    param_8 = param_2;
LAB_f0093cc4:
    pvVar8 = (void *)0x0;
    _printf(pcVar7,param_8);
    goto LAB_f0093dfc;
  }
  _printf(pcVar3,pcVar7,param_4,param_6);
  pvVar8 = (void *)0x0;
LAB_f0093dfc:
  return CONCAT44(param_2,pvVar8);
}

