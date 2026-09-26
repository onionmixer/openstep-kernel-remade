/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ede8. */
unsigned int __cdecl pmap_map(unsigned int a1, unsigned int a2, unsigned int a3, int a4)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  _BYTE *v7; // eax
  unsigned int *v8; // edx
  _DWORD *v9; // eax
  unsigned __int32 v10; // eax

  v5 = a2; /*0x18edf4*/
  v6 = 0; /*0x18edf7*/
  if ( a4 ) /*0x18edfd*/
    v6 = a2 & 0xFFFFF000 | (unsigned __int8)(2 * (kernel_prot_codes[a4] & 3)) | 1; /*0x18ee1f*/
  while ( a3 > v5 ) /*0x18eece*/
  {
    v7 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * (a1 >> 22)); /*0x18ee36*/
    if ( (*v7 & 1) == 0 || (v8 = (unsigned int *)(((a1 >> 10) & 0xFFC) + (*(_DWORD *)v7 & 0xFFFFF000))) == nullptr ) /*0x18ee51*/
    {
      sub_18ECC0(a1); /*0x18ee54*/
      v9 = (_DWORD *)(*(_DWORD *)kernel_pmap + 4 * (a1 >> 22)); /*0x18ee6a*/
      if ( (*(_BYTE *)v9 & 1) != 0 ) /*0x18ee6f*/
        v8 = (unsigned int *)(((a1 >> 10) & 0xFFC) + (*v9 & 0xFFFFF000)); /*0x18ee8a*/
      else
        v8 = nullptr; /*0x18ee71*/
    }
    if ( v5 - 655360 > 0x5FFFF ) /*0x18ee97*/
      LOBYTE(v6) = v6 & 0xF7; /*0x18eea0*/
    else
      LOBYTE(v6) = v6 | 8; /*0x18ee99*/
    *v8 = v6; /*0x18eea3*/
    if ( a4 ) /*0x18eea9*/
      v6 = ((v6 & 0xFFFFF000) + 4096) | v6 & 0xFFF; /*0x18eebd*/
    a1 += 4096; /*0x18eebf*/
    v5 += 4096; /*0x18eec5*/
  }
  v10 = __readcr3(); /*0x18eed4*/
  __writecr3(v10); /*0x18eed7*/
  return a1; /*0x18eedf*/
}
