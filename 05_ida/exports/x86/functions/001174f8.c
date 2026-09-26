/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1174f8. */
ssize_t __cdecl sendmsg(int a1, const msghdr *a2, int a3)
{
  _DWORD *v3; // esi
  char v4; // dl
  ssize_t result; // eax
  _BYTE v6[128]; // [esp+Ch] [ebp-98h] BYREF
  _BYTE v7[8]; // [esp+8Ch] [ebp-18h] BYREF
  _BYTE *v8; // [esp+94h] [ebp-10h]
  unsigned __int32 v9; // [esp+98h] [ebp-Ch]

  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x117509*/
  v4 = copyin(v3[1], v7, 24); /*0x11751b*/
  result = dword_1E875C; /*0x11751d*/
  *(_BYTE *)(dword_1E875C + 104) = v4; /*0x117522*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11752e*/
  {
    result = v9; /*0x117534*/
    if ( v9 <= 0xF ) /*0x11753a*/
    {
      *(_BYTE *)(dword_1E875C + 104) = copyin(v8, v6, 8 * v9); /*0x11755f*/
      result = dword_1E875C; /*0x117562*/
      if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11756a*/
      {
        v8 = v6; /*0x117570*/
        return sendit(*v3, v7, v3[2]); /*0x11757b*/
      }
    }
    else
    {
      *(_BYTE *)(dword_1E875C + 104) = 40; /*0x11753c*/
    }
  }
  return result; /*0x117586*/
}
