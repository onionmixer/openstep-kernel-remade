/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10cd8c. */
ssize_t __cdecl readv(int a1, const iovec *a2, int a3)
{
  ssize_t result; // eax
  int v4; // ecx
  _BYTE v5[128]; // [esp+4h] [ebp-98h] BYREF
  int v6[6]; // [esp+84h] [ebp-18h] BYREF

  result = dword_1E875C; /*0x10cd96*/
  v4 = *(_DWORD *)(dword_1E875C + 36); /*0x10cd9b*/
  if ( *(_DWORD *)(v4 + 8) <= 0x10u ) /*0x10cda2*/
  {
    v6[0] = (int)v5; /*0x10cdb2*/
    v6[1] = *(_DWORD *)(v4 + 8); /*0x10cdb8*/
    *(_BYTE *)(dword_1E875C + 104) = copyin(*(_DWORD *)(v4 + 4), v5, 8 * *(_DWORD *)(v4 + 8)); /*0x10cdd7*/
    result = dword_1E875C; /*0x10cdda*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10cde2*/
      return rwuio(v6, 0); /*0x10cdee*/
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10cda4*/
  }
  return result; /*0x10cdf3*/
}
