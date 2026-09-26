
undefined4 _scsi_slave(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  sword sVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  
  sVar4 = 0;
  if (_scsi_sdswlist._0_4_ != 0) {
    puVar6 = _scsi_sdswlist;
    puVar5 = (undefined4 *)_scsi_sdswlist._0_4_;
    do {
      iVar2 = _strcmp(*puVar5,*(undefined4 *)(param_2 + 0x16));
      if (iVar2 == 0) break;
      puVar6 = (undefined *)((int)puVar6 + 4);
      sVar4 = sVar4 + 1;
      puVar5 = *(undefined4 **)puVar6;
    } while (puVar5 != (undefined4 *)0x0);
    if (puVar5 != (undefined4 *)0x0) {
      *(sword *)(param_2 + 0x1c) = sVar4;
      iVar2 = (**(code **)((int)puVar5 + 6))((int)*(sword *)(param_2 + 4));
      *(int *)(iVar2 + 0x18) = param_1;
      *(int *)(iVar2 + 0x10) = param_2;
      *(byte *)(iVar2 + 0x24) = *(byte *)(iVar2 + 0x24) & 0x1f;
      *(undefined4 **)(iVar2 + 0x14) = puVar5;
      if (*(word *)(param_2 + 8) != 0x3f) {
        *(byte *)(iVar2 + 0x1c) = (byte)(((uint)*(word *)(param_2 + 8) << 0x19) >> 0x1d);
        bVar1 = *(byte *)(param_2 + 9) & 7;
        *(byte *)(iVar2 + 0x1d) = bVar1;
        if (*(char *)(param_1 + (uint)*(byte *)(iVar2 + 0x1c) * 8 + 0x18 + (uint)bVar1) != '\0') {
          return 0;
        }
        iVar2 = (**(code **)((int)puVar5 + 10))(iVar2,param_2);
        if (iVar2 != 0) {
          return 1;
        }
        return 0;
      }
      do {
        if (7 < *(byte *)(puVar5 + 1)) {
          return 0;
        }
        *(byte *)(iVar2 + 0x1c) = *(byte *)(puVar5 + 1);
        bVar1 = *(byte *)((int)puVar5 + 5);
        while (bVar1 < 8) {
          *(byte *)(iVar2 + 0x1d) = bVar1;
          *(char *)((int)puVar5 + 5) = *(char *)((int)puVar5 + 5) + '\x01';
          if (*(char *)(param_1 + (uint)*(byte *)(iVar2 + 0x1c) * 8 + 0x18 +
                       (uint)*(byte *)(iVar2 + 0x1d)) == '\0') {
            iVar3 = (**(code **)((int)puVar5 + 10))(iVar2,param_2);
            if (iVar3 != 0) {
              return 1;
            }
            if (*(char *)(iVar2 + 0x4f) == '\x02') {
              *(undefined *)((int)puVar5 + 5) = 8;
            }
            if (*(char *)(iVar2 + 0x4f) == '\a') {
              *(undefined *)(puVar5 + 1) = 8;
              goto loc_407BF82;
            }
          }
          else {
loc_407BF82:
            *(undefined *)((int)puVar5 + 5) = 8;
          }
          bVar1 = *(byte *)((int)puVar5 + 5);
        }
        *(char *)(puVar5 + 1) = *(char *)(puVar5 + 1) + '\x01';
        *(undefined *)((int)puVar5 + 5) = 0;
      } while( true );
    }
  }
  _printf(aNoDriverConfig,*(undefined4 *)(param_2 + 0x16));
  return 0;
}
