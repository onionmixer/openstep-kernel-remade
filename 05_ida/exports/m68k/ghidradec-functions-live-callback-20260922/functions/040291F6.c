
void _rp_rmhash(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = *(int *)(_rtable +
                  ((byte)(*(byte *)(param_1 + 0x59) ^
                         *(byte *)(param_1 + 0x58) ^
                         *(byte *)(param_1 + 0x57) ^
                         *(byte *)(param_1 + 0x56) ^
                         *(byte *)(param_1 + 0x55) ^
                         *(byte *)(param_1 + 0x54) ^
                         *(byte *)(param_1 + 0x53) ^
                         *(byte *)(param_1 + 0x52) ^
                         *(byte *)(param_1 + 0x4f) ^
                         *(byte *)(param_1 + 0x4e) ^
                         *(byte *)(param_1 + 0x4d) ^
                         *(byte *)(param_1 + 0x4c) ^
                         *(byte *)(param_1 + 0x4b) ^
                         *(byte *)(param_1 + 0x4a) ^
                         *(byte *)(param_1 + 0x49) ^ *(byte *)(param_1 + 0x48)) & 0x3f) * 4);
  while( true ) {
    if (iVar2 == 0) {
      return;
    }
    if (param_1 == iVar2) break;
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar2 + 8);
  }
  if (iVar1 == 0) {
    *(undefined4 *)
     (_rtable +
     ((byte)(*(byte *)(iVar2 + 0x59) ^
            *(byte *)(iVar2 + 0x58) ^
            *(byte *)(iVar2 + 0x57) ^
            *(byte *)(iVar2 + 0x56) ^
            *(byte *)(iVar2 + 0x55) ^
            *(byte *)(iVar2 + 0x54) ^
            *(byte *)(iVar2 + 0x53) ^
            *(byte *)(iVar2 + 0x52) ^
            *(byte *)(iVar2 + 0x4f) ^
            *(byte *)(iVar2 + 0x4e) ^
            *(byte *)(iVar2 + 0x4d) ^
            *(byte *)(iVar2 + 0x4c) ^
            *(byte *)(iVar2 + 0x4b) ^
            *(byte *)(iVar2 + 0x4a) ^ *(byte *)(iVar2 + 0x49) ^ *(byte *)(iVar2 + 0x48)) & 0x3f) * 4
     ) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
  }
  _rnhash = _rnhash + -1;
  return;
}

