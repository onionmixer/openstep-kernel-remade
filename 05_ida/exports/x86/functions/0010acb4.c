/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10acb4. */
int __cdecl adjtime(const timeval *a1, timeval *a2)
{
  _DWORD *v2; // edi
  int result; // eax
  _DWORD v4[2]; // [esp+Ch] [ebp-18h] BYREF
  _DWORD v5[2]; // [esp+14h] [ebp-10h] BYREF
  _DWORD v6[2]; // [esp+1Ch] [ebp-8h] BYREF

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x10acc3*/
  result = suser(); /*0x10acc6*/
  if ( result ) /*0x10accd*/
  {
    result = copyin(*v2, v6, 8); /*0x10acd8*/
    *(_BYTE *)(dword_1E875C + 104) = result; /*0x10ace3*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10acef*/
    {
      result = host_adjust_time(dword_1E97B4, v6[0], v6[1], v5); /*0x10ad08*/
      if ( v2[1] ) /*0x10ad10*/
      {
        v4[0] = v5[0]; /*0x10ad19*/
        v4[1] = v5[1]; /*0x10ad1f*/
        return copyout(v4, v2[1], 8); /*0x10ad2c*/
      }
    }
  }
  return result; /*0x10ad34*/
}
