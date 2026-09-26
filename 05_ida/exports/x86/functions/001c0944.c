/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0944. */
void __cdecl -[IODirectDevice reserveDMALock](IODirectDevice *self, SEL a2)
{
  IODirectDevice **v2; // eax
  int v3; // esi
  volatile __int32 *v4; // edx
  int v5; // ebx
  volatile __int32 *v6; // edx
  volatile __int32 *v7; // edx

  if ( !-[IODirectDevice isEISAPresent](self, sel_isEISAPresent) && !dmaLockDisable ) /*0x1c096c*/
  {
    v2 = (IODirectDevice **)IOMalloc(0xCu); /*0x1c0974*/
    v2[1] = (IODirectDevice *)1; /*0x1c0979*/
    *v2 = self; /*0x1c0980*/
    v2[2] = nullptr; /*0x1c0982*/
    v3 = (int)v2; /*0x1c0989*/
    v4 = (volatile __int32 *)dword_1E8728; /*0x1c098e*/
    do /*0x1c09a6*/
    {
      while ( *v4 ) /*0x1c0994*/
        ; /*0x1c0996*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1c09a6*/
    if ( dword_1E871C ) /*0x1c09af*/
    {
      v5 = dword_1E871C; /*0x1c09c4*/
      if ( *(IODirectDevice **)dword_1E871C != self || *(_DWORD *)(dword_1E871C + 8) ) /*0x1c09ca*/
      {
        do /*0x1c09da*/
        {
          v5 = *(_DWORD *)(v5 + 8); /*0x1c0a34*/
          if ( !v5 ) /*0x1c0a39*/
          {
            *(_DWORD *)(dword_1E8720 + 8) = v2; /*0x1c0a40*/
            dword_1E8720 = (int)v2; /*0x1c0a43*/
            if ( (IODirectDevice **)dword_1E871C != v2 ) /*0x1c0a4f*/
            {
              do /*0x1c0a8a*/
              {
                thread_sleep((int)&unk_1E8724, (volatile __int32 *)dword_1E8728, 0); /*0x1c0a62*/
                v7 = (volatile __int32 *)dword_1E8728; /*0x1c0a67*/
                do /*0x1c0a82*/
                {
                  while ( *v7 ) /*0x1c0a70*/
                    ; /*0x1c0a72*/
                }
                while ( _InterlockedExchange(v7, 1) == 1 ); /*0x1c0a82*/
              }
              while ( dword_1E871C != v3 ); /*0x1c0a8a*/
            }
            goto LABEL_24; /*0x1c0a8a*/
          }
        }
        while ( *(IODirectDevice **)v5 != self ); /*0x1c09da*/
        ++*(_DWORD *)(v5 + 4); /*0x1c09dc*/
        while ( dword_1E871C != v5 ) /*0x1c09e5*/
        {
          thread_sleep((int)&unk_1E8724, (volatile __int32 *)dword_1E8728, 0); /*0x1c09f6*/
          v6 = (volatile __int32 *)dword_1E8728; /*0x1c09fb*/
          do /*0x1c0a16*/
          {
            while ( *v6 ) /*0x1c0a04*/
              ; /*0x1c0a06*/
          }
          while ( _InterlockedExchange(v6, 1) == 1 ); /*0x1c0a16*/
        }
      }
      else
      {
        ++*(_DWORD *)(dword_1E871C + 4); /*0x1c09d0*/
      }
      _InterlockedExchange((volatile __int32 *)dword_1E8728, 0); /*0x1c0a27*/
      IOFree(v3, 12); /*0x1c0a2c*/
    }
    else
    {
      dword_1E8720 = (int)v2; /*0x1c09b1*/
      dword_1E871C = (int)v2; /*0x1c09b7*/
LABEL_24:
      _InterlockedExchange((volatile __int32 *)dword_1E8728, 0); /*0x1c0a8c*/
    }
  }
}
