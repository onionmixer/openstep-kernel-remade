
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _gdt_init(void)

{
  undefined *puVar1;
  
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 10) = 0;
  puVar1[0xc] = 0;
  puVar1[0xf] = 0xc0;
  puVar1[0xd] = 0x9a;
  puVar1[0xe] = puVar1[0xe] | 0xc0;
  *(undefined2 *)(puVar1 + 8) = 0xffff;
  puVar1[0xe] = puVar1[0xe] & 0xf0 | 3;
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 0x12) = 0;
  puVar1[0x14] = 0;
  puVar1[0x17] = 0xc0;
  puVar1[0x15] = 0x92;
  puVar1[0x16] = puVar1[0x16] | 0xc0;
  *(undefined2 *)(puVar1 + 0x10) = 0xffff;
  puVar1[0x16] = puVar1[0x16] & 0xf0 | 3;
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 0x4a) = 0;
  puVar1[0x4c] = 0;
  puVar1[0x4f] = 0;
  puVar1[0x4d] = 0x9a;
  puVar1[0x4e] = puVar1[0x4e] | 0xc0;
  *(undefined2 *)(puVar1 + 0x48) = 0xffff;
  puVar1[0x4e] = puVar1[0x4e] & 0xf0 | 0xb;
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 0x52) = 0;
  puVar1[0x54] = 0;
  puVar1[0x57] = 0;
  puVar1[0x55] = 0x92;
  puVar1[0x56] = puVar1[0x56] | 0xc0;
  *(undefined2 *)(puVar1 + 0x50) = 0xffff;
  puVar1[0x56] = puVar1[0x56] & 0xf0 | 0xb;
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 0x62) = 0;
  puVar1[100] = 0;
  puVar1[0x67] = 0;
  puVar1[0x65] = 0xfa;
  puVar1[0x66] = puVar1[0x66] | 0xc0;
  *(undefined2 *)(puVar1 + 0x60) = 0xffff;
  puVar1[0x66] = puVar1[0x66] & 0xf0 | 0xb;
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 0x6a) = 0;
  puVar1[0x6c] = 0;
  puVar1[0x6f] = 0;
  puVar1[0x6d] = 0xf2;
  puVar1[0x6e] = puVar1[0x6e] | 0xc0;
  *(undefined2 *)(puVar1 + 0x68) = 0xffff;
  puVar1[0x6e] = puVar1[0x6e] & 0xf0 | 0xb;
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 0x42) = 0x400;
  puVar1[0x44] = 0;
  puVar1[0x47] = 0;
  puVar1[0x45] = 0xf2;
  puVar1[0x46] = puVar1[0x46] & 0x7f | 0x40;
  *(undefined2 *)(puVar1 + 0x40) = 0x2ff;
  puVar1[0x46] = puVar1[0x46] & 0xf0;
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 0x28) = 0x6e9c;
  *(undefined2 *)(puVar1 + 0x2e) = 0x18;
  *(undefined2 *)(puVar1 + 0x2a) = 8;
  puVar1[0x2c] = puVar1[0x2c] & 0xe0 | 1;
  puVar1[0x2d] = 0xec;
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 0x30) = 0x6e3c;
  *(undefined2 *)(puVar1 + 0x36) = 0x18;
  *(undefined2 *)(puVar1 + 0x32) = 8;
  puVar1[0x34] = puVar1[0x34] & 0xe0 | 1;
  puVar1[0x35] = 0xec;
  puVar1 = _gdt;
  *(undefined2 *)(_gdt + 0x38) = 0x6ddc;
  *(undefined2 *)(puVar1 + 0x3e) = 0x18;
  *(undefined2 *)(puVar1 + 0x3a) = 8;
  puVar1[0x3c] = puVar1[0x3c] & 0xe0 | 1;
  puVar1[0x3d] = 0xec;
  __gdt_base = SUB42(_gdt,0);
  uRam001e17b4 = (undefined2)((uint)_gdt >> 0x10);
  __gdt_limit = 0xff;
  GlobalDescriptorTableRegister(CONCAT22(__gdt_base,0xff));
  return;
}

