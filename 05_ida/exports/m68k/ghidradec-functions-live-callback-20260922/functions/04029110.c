
void sub_4029110(int param_1)

{
  *(undefined4 *)(param_1 + 8) =
       *(undefined4 *)
        (_rtable +
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
               *(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x49) ^ *(byte *)(param_1 + 0x48)) &
        0x3f) * 4);
  *(int *)(_rtable +
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
                 *(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x49) ^ *(byte *)(param_1 + 0x48))
          & 0x3f) * 4) = param_1;
  _rnhash = _rnhash + 1;
  return;
}

