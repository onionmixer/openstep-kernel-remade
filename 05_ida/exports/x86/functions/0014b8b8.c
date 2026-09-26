/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b8b8. */
int __cdecl ipc_object_translate(int a1, int a2, char a3, volatile __int32 **a4)
{
  int result; // eax
  volatile __int32 *v5; // edx
  _DWORD *v6; // [esp+Ch] [ebp-4h] BYREF

  result = ipc_right_lookup_write(a1, a2, &v6); /*0x14b8d0*/
  if ( !result ) /*0x14b8d7*/
  {
    if ( ((1 << (a3 + 16)) & *v6) != 0 ) /*0x14b8eb*/
    {
      v5 = (volatile __int32 *)v6[1]; /*0x14b8fc*/
      do /*0x14b912*/
      {
        while ( *v5 ) /*0x14b900*/
          ; /*0x14b902*/
      }
      while ( _InterlockedExchange(v5, 1) == 1 ); /*0x14b912*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14b916*/
      *a4 = v5; /*0x14b919*/
      return 0; /*0x14b91b*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14b8ef*/
      return 17; /*0x14b8f2*/
    }
  }
  return result; /*0x14b920*/
}
