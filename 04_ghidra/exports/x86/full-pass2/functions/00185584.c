/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185584 */

int _vol_panel_disk_label
              (undefined4 param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5,
              int param_6,undefined4 *param_7)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  
  uVar7 = 1;
  if (param_6 != 0) {
    uVar7 = 3;
  }
  if (_panel_req_port != 0) {
    puVar2 = (undefined4 *)_kalloc(0x8c);
    puVar3 = &DAT_001e1480;
    puVar8 = puVar2;
    for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar2[3] = DAT_001e13f4;
    puVar2[4] = _panel_req_port;
    puVar2[7] = uVar7;
    puVar2[8] = 2;
    puVar2[9] = DAT_001e7598;
    DAT_001e7598 = DAT_001e7598 + 1;
    puVar2[10] = 0;
    puVar2[0xb] = param_3;
    puVar2[0xc] = param_4;
    puVar2[0xd] = 0;
    uVar6 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (0x27 < ~uVar6 - 1) {
      param_2[0x27] = '\0';
    }
    uVar6 = 0xffffffff;
    pcVar4 = &DAT_001e1695;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (0x27 < ~uVar6 - 1) {
      s_vol_thread__msg_receive___return_001e1696[0x26] = '\0';
    }
    _strcpy((char *)(puVar2 + 0xf),param_2);
    _strcpy((char *)(puVar2 + 0x19),&DAT_001e1695);
    iVar5 = _msg_send_from_kernel(puVar2,1,0);
    if (iVar5 == 0) {
      *param_7 = puVar2[9];
      puVar3 = (undefined4 *)_kalloc(0x14);
      if (puVar3 != (undefined4 *)0x0) {
        puVar3[2] = puVar2[9];
        puVar3[3] = param_1;
        puVar3[4] = param_5;
        puVar8 = puVar3;
        if (DAT_001e1408 != &PTR_LOOP_001e1404) {
          *DAT_001e1408 = (undefined *)puVar3;
          puVar8 = (undefined4 *)PTR_LOOP_001e1404;
        }
        PTR_LOOP_001e1404 = (undefined *)puVar8;
        puVar3[1] = DAT_001e1408;
        *puVar3 = &PTR_LOOP_001e1404;
        DAT_001e1408 = (undefined **)puVar3;
        return 0;
      }
      return 6;
    }
    return iVar5;
  }
  if (param_3 == 1) {
    pcVar4 = s_Optical_001e1533;
  }
  else {
    if (param_3 < 2) {
      if (param_3 == 0) {
        pcVar4 = s_Floppy_001e152c;
        goto LAB_001855e1;
      }
    }
    else if (param_3 == 2) {
      pcVar4 = &DAT_001e153b;
      goto LAB_001855e1;
    }
    pcVar4 = &DAT_001e1540;
  }
LAB_001855e1:
  switch(uVar7) {
  case 0:
    _printf(s_Please_Insert__s_Disk__d_in_Driv_001e1541,pcVar4,0,param_4);
    break;
  case 1:
    _printf(s_Please_Insert__s_Disk___s__in_Dr_001e1567,pcVar4,param_2,param_4);
    break;
  case 2:
    _printf(s_Wrong_Disk__Please_Insert__s_Dis_001e158f,pcVar4,0,param_4);
    break;
  case 3:
    _printf(s_Wrong_Disk__Please_Insert__s_Dis_001e15c1,pcVar4,param_2,param_4);
    break;
  default:
    _printf(s_vol_panel_request__bogus_panel_t_001e1641,uVar7);
  }
  return 0;
}

