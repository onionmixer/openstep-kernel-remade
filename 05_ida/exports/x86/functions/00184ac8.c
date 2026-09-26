/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x184ac8. */
int __cdecl IOGetDDMEntry(unsigned int a1, unsigned int a2, char *__dst, _DWORD *a4, _DWORD *a5)
{
  unsigned int v6; // ebx
  char __src[300]; // [esp+Ch] [ebp-12Ch] BYREF

  if ( dword_1F74CC <= a1 ) /*0x184add*/
    return -1; /*0x184adf*/
  v6 = dword_1F74C8 - 36 * a1; /*0x184af8*/
  if ( dword_1F74C4 > v6 ) /*0x184b00*/
    v6 += 36 * uxprGlobal; /*0x184b0b*/
  sprintf( /*0x184b2c*/
    __src,
    *(const char **)v6,
    *(_DWORD *)(v6 + 4),
    *(_DWORD *)(v6 + 8),
    *(_DWORD *)(v6 + 12),
    *(_DWORD *)(v6 + 16),
    *(_DWORD *)(v6 + 20));
  if ( a2 < strlen(__src) ) /*0x184b48*/
    __src[a2 - 1] = 0; /*0x184b4d*/
  strcpy(__dst, __src); /*0x184b5a*/
  *a4 = *(_DWORD *)(v6 + 24); /*0x184b65*/
  a4[1] = *(_DWORD *)(v6 + 28); /*0x184b6a*/
  *a5 = *(_DWORD *)(v6 + 32); /*0x184b73*/
  return 0; /*0x184b7d*/
}
