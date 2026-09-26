/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18991c. */
int (**dbf_init())()
{
  _BYTE *v0; // eax
  int (**result)(); // eax

  dword_1F79AC = *(_DWORD *)(pmap_kernel() + 4); /*0x189927*/
  dword_1F7994 = (int)&dbf_state; /*0x18992c*/
  word_1F7998 = 16; /*0x189936*/
  dword_1F79CC = (int)&dbf_state; /*0x18993f*/
  dword_1F79C8 = (int)&dbf_state; /*0x189949*/
  word_1F79E0 = 16; /*0x189953*/
  dword_1F79B0 = (int)dbf_handler_; /*0x18995c*/
  word_1F79DC = 8; /*0x189966*/
  word_1F79E4 = 16; /*0x18996f*/
  word_1F79D8 = 16; /*0x189978*/
  word_1F79F6 = 104; /*0x189981*/
  v0 = gdt; /*0x18998a*/
  *((_WORD *)gdt + 57) = 31120; /*0x189994*/
  v0[116] = 31; /*0x18999b*/
  v0[119] = -64; /*0x1899a6*/
  v0[117] = -119; /*0x1899a9*/
  v0[118] &= ~0x80u; /*0x1899ad*/
  *((_WORD *)v0 + 56) = 103; /*0x1899b1*/
  v0[118] &= 0xF0u; /*0x1899b7*/
  result = idt; /*0x1899bb*/
  *((_WORD *)idt + 33) = 112; /*0x1899c0*/
  *((_BYTE *)result + 69) = -123; /*0x1899c6*/
  return result; /*0x1899cc*/
}
