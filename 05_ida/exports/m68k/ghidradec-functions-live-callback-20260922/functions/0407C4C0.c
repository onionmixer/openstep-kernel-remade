
void _scsi_msg(int param_1,undefined param_2,undefined4 param_3)

{
  _printf(aSCDDDSOp0xXSdS,*(undefined *)(param_1 + 0x1e),
          (int)*(sword *)(*(int *)(param_1 + 0x10) + 4),*(undefined *)(param_1 + 0x1c),
          *(undefined *)(param_1 + 0x1d),param_3,param_2,*(undefined *)(param_1 + 0x4f),
          *(byte *)(param_1 + 0x4e) & 0x1e);
  return;
}

