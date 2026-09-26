/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a924. */
char gdt_init()
{
  _BYTE *v0; // edx
  _BYTE *v1; // edx
  _BYTE *v2; // edx
  _BYTE *v3; // edx
  _BYTE *v4; // edx
  _BYTE *v5; // edx
  _BYTE *v6; // eax
  _WORD *v7; // edx
  _WORD *v8; // edx
  _WORD *v9; // edx
  char result; // al

  v0 = gdt; /*0x18a927*/
  *((_WORD *)gdt + 5) = 0; /*0x18a92d*/
  v0[12] = 0; /*0x18a933*/
  v0[15] = -64; /*0x18a937*/
  v0[13] = -102; /*0x18a93b*/
  v0[14] |= 0xC0u; /*0x18a93f*/
  *((_WORD *)v0 + 4) = -1; /*0x18a943*/
  v0[14] = v0[14] & 0xF0 | 3; /*0x18a950*/
  v1 = gdt; /*0x18a953*/
  *((_WORD *)gdt + 9) = 0; /*0x18a959*/
  v1[20] = 0; /*0x18a95f*/
  v1[23] = -64; /*0x18a963*/
  v1[21] = -110; /*0x18a967*/
  v1[22] |= 0xC0u; /*0x18a96b*/
  *((_WORD *)v1 + 8) = -1; /*0x18a96f*/
  v1[22] = v1[22] & 0xF0 | 3; /*0x18a97c*/
  v2 = gdt; /*0x18a97f*/
  *((_WORD *)gdt + 37) = 0; /*0x18a985*/
  v2[76] = 0; /*0x18a98b*/
  v2[79] = 0; /*0x18a98f*/
  v2[77] = -102; /*0x18a993*/
  v2[78] |= 0xC0u; /*0x18a997*/
  *((_WORD *)v2 + 36) = -1; /*0x18a99b*/
  v2[78] = v2[78] & 0xF0 | 0xB; /*0x18a9a8*/
  v3 = gdt; /*0x18a9ab*/
  *((_WORD *)gdt + 41) = 0; /*0x18a9b1*/
  v3[84] = 0; /*0x18a9b7*/
  v3[87] = 0; /*0x18a9bb*/
  v3[85] = -110; /*0x18a9bf*/
  v3[86] |= 0xC0u; /*0x18a9c3*/
  *((_WORD *)v3 + 40) = -1; /*0x18a9c7*/
  v3[86] = v3[86] & 0xF0 | 0xB; /*0x18a9d4*/
  v4 = gdt; /*0x18a9d7*/
  *((_WORD *)gdt + 49) = 0; /*0x18a9dd*/
  v4[100] = 0; /*0x18a9e3*/
  v4[103] = 0; /*0x18a9e7*/
  v4[101] = -6; /*0x18a9eb*/
  v4[102] |= 0xC0u; /*0x18a9ef*/
  *((_WORD *)v4 + 48) = -1; /*0x18a9f3*/
  v4[102] = v4[102] & 0xF0 | 0xB; /*0x18aa00*/
  v5 = gdt; /*0x18aa03*/
  *((_WORD *)gdt + 53) = 0; /*0x18aa09*/
  v5[108] = 0; /*0x18aa0f*/
  v5[111] = 0; /*0x18aa13*/
  v5[109] = -14; /*0x18aa17*/
  v5[110] |= 0xC0u; /*0x18aa1b*/
  *((_WORD *)v5 + 52) = -1; /*0x18aa1f*/
  v5[110] = v5[110] & 0xF0 | 0xB; /*0x18aa2c*/
  v6 = gdt; /*0x18aa2f*/
  *((_WORD *)gdt + 33) = 1024; /*0x18aa34*/
  v6[68] = 0; /*0x18aa3a*/
  v6[71] = 0; /*0x18aa3e*/
  v6[69] = -14; /*0x18aa42*/
  v6[70] = v6[70] & 0x3F | 0x40; /*0x18aa4f*/
  *((_WORD *)v6 + 32) = 767; /*0x18aa52*/
  v6[70] &= 0xF0u; /*0x18aa58*/
  v7 = gdt; /*0x18aa5c*/
  *((_WORD *)gdt + 20) = (unsigned __int16)unix_syscall_; /*0x18aa67*/
  v7[23] = (unsigned int)unix_syscall_ >> 16; /*0x18aa6e*/
  v7[21] = 8; /*0x18aa72*/
  *((_BYTE *)v7 + 44) = v7[22] & 0xE0 | 1; /*0x18aa7f*/
  *((_BYTE *)v7 + 45) = -20; /*0x18aa82*/
  v8 = gdt; /*0x18aa86*/
  *((_WORD *)gdt + 24) = (unsigned __int16)mach_kernel_trap_; /*0x18aa91*/
  v8[27] = (unsigned int)mach_kernel_trap_ >> 16; /*0x18aa98*/
  v8[25] = 8; /*0x18aa9c*/
  *((_BYTE *)v8 + 52) = v8[26] & 0xE0 | 1; /*0x18aaa9*/
  *((_BYTE *)v8 + 53) = -20; /*0x18aaac*/
  v9 = gdt; /*0x18aab0*/
  *((_WORD *)gdt + 28) = (unsigned __int16)machdep_call_; /*0x18aabb*/
  v9[31] = (unsigned int)machdep_call_ >> 16; /*0x18aac2*/
  v9[29] = 8; /*0x18aac6*/
  result = v9[30] & 0xE0 | 1; /*0x18aad1*/
  *((_BYTE *)v9 + 60) = result; /*0x18aad3*/
  *((_BYTE *)v9 + 61) = -20; /*0x18aad6*/
  gdt_base = (int)gdt; /*0x18aae0*/
  gdt_limit = 255; /*0x18aae6*/
  __lgdt(&gdt_limit); /*0x18aaef*/
  return result; /*0x18aaf8*/
}
