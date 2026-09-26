
void _scsi_docmd(int param_1)

{
  if (_scsi_ndevices == 1) {
    *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & 0xef;
  }
  (*(code *)**(undefined4 **)(*(int *)(param_1 + 0x18) + 0x14))(param_1);
  return;
}
