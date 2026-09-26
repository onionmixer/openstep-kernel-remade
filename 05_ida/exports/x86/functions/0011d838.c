/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d838. */
ssize_t __cdecl readlink(const char *a1, char *a2, size_t a3)
{
  int *v3; // ebx
  ssize_t result; // eax
  _DWORD v5[2]; // [esp+8h] [ebp-24h] BYREF
  int v6; // [esp+10h] [ebp-1Ch] BYREF
  _DWORD v7[5]; // [esp+14h] [ebp-18h] BYREF
  int v8; // [esp+28h] [ebp-4h]

  v3 = *(int **)(dword_1E875C + 36); /*0x11d845*/
  *(_BYTE *)(dword_1E875C + 104) = lookupname(*v3, 0, 0, 0, (int)&v6); /*0x11d861*/
  result = dword_1E875C; /*0x11d864*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11d86c*/
  {
    if ( *(_DWORD *)(v6 + 40) == 5 ) /*0x11d879*/
    {
      v5[0] = v3[1]; /*0x11d887*/
      v5[1] = v3[2]; /*0x11d88d*/
      v7[0] = v5; /*0x11d893*/
      v7[1] = 1; /*0x11d896*/
      v7[2] = 0; /*0x11d89d*/
      v7[3] = 0; /*0x11d8a4*/
      v8 = v3[2]; /*0x11d8ae*/
      *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(int, _DWORD *, _DWORD))(*(_DWORD *)(v6 + 28) + 68))( /*0x11d8ce*/
                                         v6,
                                         v7,
                                         *(_DWORD *)(active_u + 28));
    }
    else
    {
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x11d87b*/
    }
    vn_rele(v6); /*0x11d8d8*/
    result = dword_1E875C; /*0x11d8dd*/
    *(_DWORD *)(dword_1E875C + 96) = v3[2] - v8; /*0x11d8e8*/
  }
  return result; /*0x11d8ee*/
}
