
qword _scsi_probe(undefined4 param_1,int param_2,undefined4 param_3,undefined param_4)

{
  uint uVar1;
  bool bVar2;
  
  *(undefined4 *)(param_2 + 0x10) = param_1;
  *(undefined4 *)(param_2 + 0x14) = param_3;
  *(undefined *)(param_2 + 0x58) = 7;
  _bzero(param_2 + 0x18,0x40);
  uVar1 = 0;
  do {
    *(undefined *)(uVar1 + 0x18 + param_2 + (uint)*(byte *)(param_2 + 0x58) * 8) = 1;
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 8);
  *(undefined *)(param_2 + 0x5a) = 0;
  *(undefined *)(param_2 + 0x5b) = 0;
  *(undefined *)(param_2 + 0x59) = param_4;
  *(undefined *)(param_2 + 0x60) = 0;
  *(int *)(param_2 + 4) = param_2;
  *(int *)param_2 = param_2;
  bVar2 = &dword_40B4FD2 < dword_40B4FD6;
  if (dword_40B4FD6 == &dword_40B4FD2) {
    dword_40B4FD2 = param_2;
  }
  else {
    dword_40B4FD6[2] = param_2;
  }
  *(undefined4 **)(param_2 + 0xc) = dword_40B4FD6;
  *(int **)(param_2 + 8) = &dword_40B4FD2;
  dword_40B4FD6 = (undefined4 *)param_2;
  return (qword)CONCAT14(bVar2 << 4 | (param_2 < 0) << 3 | (param_2 == 0) << 2,
                         (uint)(byte)((7 < uVar1) << 4 | (param_2 < 0) << 3 | (param_2 == 0) << 2));
}
