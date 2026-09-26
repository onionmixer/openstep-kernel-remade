/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0f74. */
void __cdecl -[IODirectDevice releaseDMALock](IODirectDevice *self, SEL a2)
{
  int v2; // ebx
  int v3; // esi
  volatile __int32 *v4; // edx
  const char *v5; // eax
  int v6; // eax
  _BOOL4 v7; // [esp+Ch] [ebp-4h]

  v2 = dword_1E871C; /*0x1c0f80*/
  v3 = 0; /*0x1c0f86*/
  v7 = 0; /*0x1c0f88*/
  if ( !-[IODirectDevice isEISAPresent](self, sel_isEISAPresent) && !dmaLockDisable )
  {
    v4 = (volatile __int32 *)dword_1E8728; /*0x1c0fb4*/
    do /*0x1c0fce*/
    {
      while ( *v4 ) /*0x1c0fbc*/
        ; /*0x1c0fbe*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1c0fce*/
    if ( *(IODirectDevice **)v2 != self )
    {
      _InterlockedExchange((volatile __int32 *)dword_1E8728, 0); /*0x1c0fdb*/
      v5 = -[IODevice name](self, sel_name); /*0x1c0fe5*/
      IOLog((int)"%s: releaseDmaLock when not holding lock\n", v5);
      panic("releaseDMALock"); /*0x1c0ffa*/
    }
    v6 = *(_DWORD *)(v2 + 4); /*0x1c1002*/
    *(_DWORD *)(v2 + 4) = v6 - 1; /*0x1c1008*/
    if ( v6 == 1 ) /*0x1c100e*/
    {
      v7 = *(_DWORD *)(v2 + 8) != 0; /*0x1c101d*/
      v3 = v2; /*0x1c1020*/
      dword_1E871C = *(_DWORD *)(v2 + 8); /*0x1c1022*/
    }
    _InterlockedExchange((volatile __int32 *)dword_1E8728, 0); /*0x1c102f*/
    if ( v7 ) /*0x1c1035*/
      thread_wakeup((int)&unk_1E8724); /*0x1c103c*/
    if ( v3 ) /*0x1c1046*/
      IOFree(v3, 12); /*0x1c104b*/
  }
}
