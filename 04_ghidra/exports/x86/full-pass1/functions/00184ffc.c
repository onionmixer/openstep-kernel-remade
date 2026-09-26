/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00184ffc */

int _vol_panel_request(undefined4 param_1,char *param_2,int param_3,undefined4 param_4,int param_5,
                      undefined4 param_6,undefined4 param_7,char *param_8,char *param_9,
                      undefined4 param_10,undefined4 *param_11)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  if (_panel_req_port != 0) {
    puVar2 = (undefined4 *)_kalloc(0x8c);
    puVar3 = &DAT_001e1480;
    puVar7 = puVar2;
    for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar2[3] = DAT_001e13f4;
    puVar2[4] = _panel_req_port;
    puVar2[7] = param_2;
    puVar2[8] = param_3;
    puVar2[9] = DAT_001e7598;
    DAT_001e7598 = DAT_001e7598 + 1;
    puVar2[10] = param_4;
    puVar2[0xb] = param_5;
    puVar2[0xc] = param_6;
    puVar2[0xd] = param_7;
    uVar6 = 0xffffffff;
    pcVar4 = param_8;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (0x27 < ~uVar6 - 1) {
      param_8[0x27] = '\0';
    }
    uVar6 = 0xffffffff;
    pcVar4 = param_9;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (0x27 < ~uVar6 - 1) {
      param_9[0x27] = '\0';
    }
    _strcpy((char *)(puVar2 + 0xf),param_8);
    _strcpy((char *)(puVar2 + 0x19),param_9);
    iVar5 = _msg_send_from_kernel(puVar2,1,0);
    if (iVar5 != 0) {
      return iVar5;
    }
    *param_11 = puVar2[9];
    if (param_3 == 0) {
      return 0;
    }
    puVar3 = (undefined4 *)_kalloc(0x14);
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[2] = puVar2[9];
      puVar3[3] = param_1;
      puVar3[4] = param_10;
      puVar7 = puVar3;
      if (DAT_001e1408 != &PTR_LOOP_001e1404) {
        *DAT_001e1408 = (undefined *)puVar3;
        puVar7 = (undefined4 *)PTR_LOOP_001e1404;
      }
      PTR_LOOP_001e1404 = (undefined *)puVar7;
      puVar3[1] = DAT_001e1408;
      *puVar3 = &PTR_LOOP_001e1404;
      DAT_001e1408 = (undefined **)puVar3;
      return 0;
    }
    return 6;
  }
  if (param_5 == 1) {
    pcVar4 = s_Optical_001e1533;
  }
  else if (param_5 < 2) {
    if (param_5 == 0) {
      pcVar4 = s_Floppy_001e152c;
    }
    else {
LAB_00185048:
      pcVar4 = &DAT_001e1540;
    }
  }
  else {
    if (param_5 != 2) goto LAB_00185048;
    pcVar4 = &DAT_001e153b;
  }
  switch(param_2) {
  case (char *)0x0:
    _printf(s_Please_Insert__s_Disk__d_in_Driv_001e1541,pcVar4,param_4,param_6);
    break;
  case (char *)0x1:
    _printf(s_Please_Insert__s_Disk___s__in_Dr_001e1567,pcVar4,param_8,param_6);
    break;
  case (char *)0x2:
    _printf(s_Wrong_Disk__Please_Insert__s_Dis_001e158f,pcVar4,param_4,param_6);
    break;
  case (char *)0x3:
    _printf(s_Wrong_Disk__Please_Insert__s_Dis_001e15c1,pcVar4,param_8,param_6);
    break;
  case (char *)0x4:
    _printf(s____Swap_Device_Full____001e15f5);
    break;
  case (char *)0x5:
    pcVar4 = s____File_System__s_Full____001e160d;
    param_2 = param_8;
    goto LAB_00185119;
  case (char *)0x6:
    _printf(s_Please_Eject__s_Disk__d_001e1628,pcVar4,param_6);
    break;
  default:
    pcVar4 = s_vol_panel_request__bogus_panel_t_001e1641;
LAB_00185119:
    _printf(pcVar4,param_2);
  }
  return 0;
}

