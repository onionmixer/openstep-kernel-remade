
void _scsi_sensemsg(int param_1,int param_2)

{
  _printf(aSCDDDSenseKey0,*(undefined *)(param_1 + 0x1e),
          (int)*(sword *)(*(int *)(param_1 + 0x10) + 4),*(undefined *)(param_1 + 0x1c),
          *(undefined *)(param_1 + 0x1d),*(byte *)(param_2 + 2) & 0xf,*(undefined *)(param_2 + 0xc))
  ;
  return;
}
