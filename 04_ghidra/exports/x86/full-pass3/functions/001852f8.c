/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001852f8 */

int _vol_panel_disk_num(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                       undefined4 param_5,int param_6,undefined4 *param_7)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  
  uVar7 = 0;
  if (param_6 != 0) {
    uVar7 = 2;
  }
  if (_panel_req_port != 0) {
    puVar2 = (undefined4 *)_kalloc(0x8c);
    puVar3 = &DAT_001e1480;
    puVar8 = puVar2;
    for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
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
    puVar2[10] = param_2;
    puVar2[0xb] = param_3;
    puVar2[0xc] = param_4;
    puVar2[0xd] = 0;
    uVar5 = 0xffffffff;
    pcVar6 = &DAT_001e1693;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (0x27 < ~uVar5 - 1) {
      s_vol_thread__msg_receive___return_001e1696[0x24] = '\0';
    }
    uVar5 = 0xffffffff;
    pcVar6 = &DAT_001e1694;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (0x27 < ~uVar5 - 1) {
      s_vol_thread__msg_receive___return_001e1696[0x25] = '\0';
    }
    _strcpy((char *)(puVar2 + 0xf),&DAT_001e1693);
    _strcpy((char *)(puVar2 + 0x19),&DAT_001e1694);
    iVar4 = _msg_send_from_kernel(puVar2,1,0);
    if (iVar4 == 0) {
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
    return iVar4;
  }
  if (param_3 == 1) {
    pcVar6 = s_Optical_001e1533;
  }
  else {
    if (param_3 < 2) {
      if (param_3 == 0) {
        pcVar6 = s_Floppy_001e152c;
        goto LAB_00185355;
      }
    }
    else if (param_3 == 2) {
      pcVar6 = &DAT_001e153b;
      goto LAB_00185355;
    }
    pcVar6 = &DAT_001e1540;
  }
LAB_00185355:
  switch(uVar7) {
  case 0:
    _printf(s_Please_Insert__s_Disk__d_in_Driv_001e1541,pcVar6,param_2,param_4);
    break;
  case 2:
    _printf(s_Wrong_Disk__Please_Insert__s_Dis_001e158f,pcVar6,param_2,param_4);
    break;
  default:
    _printf(s_vol_panel_request__bogus_panel_t_001e1641,uVar7);
  }
  return 0;
}

