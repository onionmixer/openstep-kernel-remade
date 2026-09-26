/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117810. */
ssize_t __cdecl recvmsg(int a1, msghdr *a2, int a3)
{
  _DWORD *v3; // esi
  char v4; // dl
  ssize_t result; // eax
  _BYTE v6[128]; // [esp+8h] [ebp-98h] BYREF
  _BYTE v7[8]; // [esp+88h] [ebp-18h] BYREF
  _BYTE *v8; // [esp+90h] [ebp-10h]
  unsigned __int32 v9; // [esp+94h] [ebp-Ch]
  int v10; // [esp+98h] [ebp-8h]
  int v11; // [esp+9Ch] [ebp-4h]

  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x117820*/
  v4 = copyin(v3[1], v7, 24); /*0x117832*/
  result = dword_1E875C; /*0x117834*/
  *(_BYTE *)(dword_1E875C + 104) = v4; /*0x117839*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117845*/
  {
    result = v9; /*0x11784f*/
    if ( v9 <= 0xF ) /*0x117855*/
    {
      *(_BYTE *)(dword_1E875C + 104) = copyin(v8, v6, 8 * v9); /*0x11787b*/
      result = dword_1E875C; /*0x11787e*/
      if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117886*/
      {
        v8 = v6; /*0x11788c*/
        if ( !v10 || useracc(v10, v11, 0) ) /*0x11789d*/
        {
          return recvit(*v3, v7, v3[2], v3[1] + 4, v3[1] + 20); /*0x1178ca*/
        }
        else
        {
          result = dword_1E875C; /*0x1178a9*/
          *(_BYTE *)(dword_1E875C + 104) = 14; /*0x1178ae*/
        }
      }
    }
    else
    {
      *(_BYTE *)(dword_1E875C + 104) = 40; /*0x117857*/
    }
  }
  return result; /*0x1178d5*/
}
