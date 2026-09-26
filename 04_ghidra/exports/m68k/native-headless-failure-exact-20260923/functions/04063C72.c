
int _vol_panel_request(undefined4 param_1,char *param_2,int param_3,undefined4 param_4,int param_5,
                      undefined4 param_6,undefined4 param_7,char *param_8,char *param_9,
                      undefined4 param_10,undefined4 *param_11)

{
  char *pcVar1;
  void *pvVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (_panel_req_port != 0) {
    pvVar2 = (void *)_kalloc(0x8c);
    _bcopy(&DAT_040b0780,pvVar2,0x8c);
    *(undefined4 *)((int)pvVar2 + 0xc) = DAT_040b06f4;
    *(int *)((int)pvVar2 + 0x10) = _panel_req_port;
    *(char **)((int)pvVar2 + 0x1c) = param_2;
    *(int *)((int)pvVar2 + 0x20) = param_3;
    *(int *)((int)pvVar2 + 0x24) = DAT_040b4e8a;
    DAT_040b4e8a = DAT_040b4e8a + 1;
    *(undefined4 *)((int)pvVar2 + 0x28) = param_4;
    *(int *)((int)pvVar2 + 0x2c) = param_5;
    *(undefined4 *)((int)pvVar2 + 0x30) = param_6;
    *(undefined4 *)((int)pvVar2 + 0x34) = param_7;
    sVar3 = _strlen(param_8);
    if (0x27 < sVar3) {
      param_8[0x27] = '\0';
    }
    sVar3 = _strlen(param_9);
    if (0x27 < sVar3) {
      param_9[0x27] = '\0';
    }
    _strcpy((char *)((int)pvVar2 + 0x3c),param_8);
    _strcpy((char *)((int)pvVar2 + 100),param_9);
    iVar4 = _msg_send_from_kernel(pvVar2,1,0);
    if (iVar4 != 0) {
      return iVar4;
    }
    *param_11 = *(undefined4 *)((int)pvVar2 + 0x24);
    if (param_3 == 0) {
      return 0;
    }
    puVar5 = (undefined4 *)_kalloc(0x14);
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[2] = *(undefined4 *)((int)pvVar2 + 0x24);
      puVar5[3] = param_1;
      puVar5[4] = param_10;
      *DAT_040b0708 = puVar5;
      puVar5[1] = DAT_040b0708;
      *puVar5 = &PTR_LOOP_040b0704;
      DAT_040b0708 = puVar5;
      return 0;
    }
    return 6;
  }
  if (param_5 == 1) {
    pcVar1 = "Optical";
  }
  else if (param_5 < 2) {
    if (param_5 == 0) {
      pcVar1 = "Floppy";
    }
    else {
LAB_04063cce:
      pcVar1 = "";
    }
  }
  else {
    if (param_5 != 2) goto LAB_04063cce;
    pcVar1 = "SCSI";
  }
  switch(param_2) {
  case (char *)0x0:
    _printf("Please Insert %s Disk %d in Drive %d\n",pcVar1,param_4,param_6);
    break;
  case (char *)0x1:
    _printf("Please Insert %s Disk \'%s\' in Drive %d\n",pcVar1,param_8,param_6);
    break;
  case (char *)0x2:
    _printf("Wrong Disk: Please Insert %s Disk %d in Drive %d\n",pcVar1,param_4,param_6);
    break;
  case (char *)0x3:
    _printf("Wrong Disk: Please Insert %s Disk \'%s\' in Drive %d\n",pcVar1,param_8,param_6);
    break;
  case (char *)0x4:
    _printf("***Swap Device Full***\n");
    break;
  case (char *)0x5:
    pcVar1 = "***File System %s Full***\n";
    param_2 = param_8;
    goto LAB_04063d92;
  case (char *)0x6:
    _printf("Please Eject %s Disk %d\n",pcVar1,param_6);
    break;
  default:
    pcVar1 = "vol_panel_request: bogus panel_type (%d)\n";
LAB_04063d92:
    _printf(pcVar1,param_2);
  }
  return 0;
}

