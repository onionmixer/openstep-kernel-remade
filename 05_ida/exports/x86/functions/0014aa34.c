/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14aa34. */
int __cdecl ipc_mqueue_send_interrupt(_DWORD *a1)
{
  int v1; // edi
  int v3; // eax
  _DWORD *v4; // edx
  int v5; // edx
  _DWORD *v6; // eax
  _DWORD *v7; // ecx
  int v8; // eax
  _DWORD *v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  v1 = a1[7]; /*0x14aa40*/
  if ( _InterlockedExchange((volatile __int32 *)v1, 1) == 1 ) /*0x14aa4a*/
    return 2048; /*0x14aa51*/
  if ( *(int *)(v1 + 8) < 0 ) /*0x14aa60*/
  {
    v3 = *(_DWORD *)(v1 + 48); /*0x14aa70*/
    if ( v3 ) /*0x14aa75*/
      v10 = v3 + 16; /*0x14aa83*/
    else
      v10 = v1 + 64; /*0x14aa7a*/
    if ( _InterlockedExchange((volatile __int32 *)v10, 1) != 1 ) /*0x14aa90*/
    {
      v9 = (_DWORD *)(v10 + 8); /*0x14aaae*/
      ++*(_DWORD *)(v1 + 56); /*0x14aab1*/
      _InterlockedExchange((volatile __int32 *)v1, 0); /*0x14aab6*/
      while ( 1 ) /*0x14aabb*/
      {
        v4 = (_DWORD *)*v9; /*0x14aabb*/
        if ( !*v9 ) /*0x14aabb*/
          break; /*0x14aabb*/
        v7 = (_DWORD *)v4[36]; /*0x14ab00*/
        if ( v7 == v4 ) /*0x14ab08*/
        {
          *v9 = 0; /*0x14aaf7*/
        }
        else
        {
          v8 = v4[37]; /*0x14ab0a*/
          *v9 = v7; /*0x14ab13*/
          v7[37] = v8; /*0x14ab15*/
          *(_DWORD *)(v8 + 144) = v7; /*0x14ab1b*/
          v4[36] = v4; /*0x14ab21*/
          v4[37] = v4; /*0x14ab27*/
        }
        if ( a1[6] <= v4[39] ) /*0x14ab36*/
        {
          v4[38] = 0; /*0x14ab5c*/
          v4[39] = a1; /*0x14ab66*/
          v4[40] = (*(_DWORD *)(v1 + 52))++; /*0x14ab6f*/
          _InterlockedExchange((volatile __int32 *)v10, 0); /*0x14ab7d*/
          thread_go(v4); /*0x14ab80*/
          return 0; /*0x14ab80*/
        }
        v4[38] = 268451844; /*0x14ab38*/
        v4[39] = a1[6]; /*0x14ab45*/
        thread_go(v4); /*0x14ab4c*/
      }
      v5 = *(_DWORD *)(v10 + 4); /*0x14aac4*/
      if ( v5 ) /*0x14aac9*/
      {
        v6 = *(_DWORD **)(v5 + 4); /*0x14aacb*/
        *a1 = v5; /*0x14aace*/
        a1[1] = v6; /*0x14aad0*/
        *(_DWORD *)(v5 + 4) = a1; /*0x14aad3*/
        *v6 = a1; /*0x14aad6*/
      }
      else
      {
        *(_DWORD *)(v10 + 4) = a1; /*0x14aae7*/
        *a1 = a1; /*0x14aaea*/
        a1[1] = a1; /*0x14aaec*/
      }
      _InterlockedExchange((volatile __int32 *)v10, 0); /*0x14aadd*/
      return 0; /*0x14ab85*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)v1, 0); /*0x14aa99*/
      return 2048; /*0x14aa9b*/
    }
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)v1, 0); /*0x14aa64*/
    return 268435459; /*0x14aa66*/
  }
}
