
undefined4 sub_4071A12(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(dword_40B6974 + param_1 * byte_40B6966 * 4);
  if (byte_40B6966 == '\x04') {
    uVar2 = CONCAT31((uint3)(byte)((uint)puVar1[2] >> 0x18) |
                     (uint3)((word)((uint)puVar1[1] >> 0x10) & 0xff00) |
                     (uint3)((uint)*puVar1 >> 8) & 0xff0000,*(undefined *)(puVar1 + 3));
  }
  else {
    if (byte_40B6966 < '\x05') {
      if (byte_40B6966 == '\x01') {
        return *puVar1;
      }
    }
    else if (byte_40B6966 == '\b') {
      return CONCAT31((uint3)(byte)((word)*(undefined2 *)(puVar1 + 4) >> 8) |
                      (uint3)((word)((uint)puVar1[2] >> 0x10) & 0xff00) |
                      (uint3)((uint)*puVar1 >> 8) & 0xff0000,*(undefined *)(puVar1 + 6));
    }
    uVar2 = 0;
  }
  return uVar2;
}

