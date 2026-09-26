/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1651a0. */
int __cdecl thread_wakeup(int a1)
{
  int v1; // eax
  int v2; // ebx
  int *v3; // esi
  volatile __int32 *v4; // ebx
  int *v5; // edi
  int v6; // eax
  int v7; // ecx
  int result; // eax
  volatile __int32 *v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  int *v12; // [esp+14h] [ebp-4h]

  if ( a1 < 0 ) /*0x1651ad*/
    v1 = ~a1; /*0x1651b7*/
  else
    v1 = a1; /*0x1651af*/
  v2 = v1 % 59; /*0x1651c1*/
  v12 = &wait_queue[2 * (v1 % 59)]; /*0x1651ca*/
  v11 = splsched(); /*0x1651d2*/
  v3 = &wait_lock[v2]; /*0x1651d5*/
  do /*0x1651ee*/
  {
    while ( *v3 ) /*0x1651dc*/
      ; /*0x1651de*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x1651ee*/
  v4 = (volatile __int32 *)*v12; /*0x1651f3*/
  if ( v12 != (int *)*v12 ) /*0x1651f7*/
  {
    do /*0x1652fb*/
    {
      v5 = (int *)*v4; /*0x165200*/
      if ( *((_DWORD *)v4 + 15) == a1 ) /*0x165208*/
      {
        v9 = v4 + 8; /*0x165211*/
        do /*0x16522c*/
        {
          while ( *v9 ) /*0x165217*/
            ; /*0x165219*/
        }
        while ( _InterlockedExchange(v9, 1) == 1 ); /*0x16522c*/
        *(_DWORD *)(*v4 + 4) = *((_DWORD *)v4 + 1); /*0x165233*/
        **((_DWORD **)v4 + 1) = *v4; /*0x16523b*/
        *((_DWORD *)v4 + 15) = 0; /*0x16523d*/
        if ( *((_DWORD *)v4 + 81) ) /*0x165244*/
          reset_timeout((int)(v4 + 70)); /*0x165254*/
        v10 = *((_DWORD *)v4 + 19); /*0x16525f*/
        switch ( v10 & 0xF ) /*0x16526d*/
        {
          case 1: /*0x16526d*/
          case 9: /*0x16526d*/
          case 0xB: /*0x16526d*/
            v6 = *((_DWORD *)v4 + 19); /*0x1652b0*/
            LOBYTE(v6) = v10 & 0xFA | 4; /*0x1652b5*/
            *((_DWORD *)v4 + 19) = v6; /*0x1652b7*/
            *((_DWORD *)v4 + 17) = 0; /*0x1652ba*/
            thread_setrun((char **)v4, 1); /*0x1652c4*/
            break; /*0x1652cc*/
          case 3: /*0x16526d*/
          case 5: /*0x16526d*/
          case 7: /*0x16526d*/
          case 0xD: /*0x16526d*/
          case 0xF: /*0x16526d*/
            v7 = *((_DWORD *)v4 + 19); /*0x1652d0*/
            LOBYTE(v7) = v10 & 0xFE; /*0x1652d3*/
            *((_DWORD *)v4 + 19) = v7; /*0x1652d6*/
            *((_DWORD *)v4 + 17) = 0; /*0x1652d9*/
            break; /*0x1652e0*/
          default:
            panic(aThreadWakeup); /*0x1652e9*/
            return result; /*0x1652e9*/
        }
        _InterlockedExchange(v4 + 8, 0); /*0x1652f3*/
      }
      v4 = v5; /*0x1652f6*/
    }
    while ( v12 != v5 ); /*0x1652fb*/
  }
  _InterlockedExchange(v3, 0); /*0x165303*/
  return splx(v11); /*0x165311*/
}
