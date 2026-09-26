/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a15c4. */
void PCresume()
{
  thread_act_t v0; // esi
  int v1; // eax
  int v2; // ebx
  int *v3; // eax
  int v4; // ecx
  int v5; // esi
  unsigned int v6; // edi
  int v7; // edi
  unsigned __int32 v8; // eax
  int v9; // edx

  v0 = active_threads; /*0x1a15ca*/
  v1 = *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 112); /*0x1a15d3*/
  if ( v1 ) /*0x1a15d8*/
    v2 = v1 + 132; /*0x1a15da*/
  else
    v2 = thread_user_state(active_threads); /*0x1a15ed*/
  v3 = *(int **)(*(_DWORD *)(v0 + 40) + 236); /*0x1a15f2*/
  v4 = 0; /*0x1a15f8*/
  if ( v3 ) /*0x1a15fc*/
    v4 = *v3; /*0x1a15fe*/
  if ( v4 ) /*0x1a1602*/
  {
    v5 = v4 + 64; /*0x1a1604*/
    if ( (*(_BYTE *)(v4 + 128) & 1) == 0 || (*(_BYTE *)(v4 + 108) & 4) != 0 ) /*0x1a1614*/
    {
      v6 = *(_DWORD *)(v4 + 132); /*0x1a1620*/
      if ( v6 > 7 ) /*0x1a1629*/
        v7 = 0; /*0x1a163c*/
      else
        v7 = v4 + 132 * v6 + 136; /*0x1a1632*/
      *(_DWORD *)(v7 + 104) = (*(_DWORD *)(v4 + 100) >> 9) & 1; /*0x1a1647*/
      *(_DWORD *)(v7 + 108) = (*(_BYTE *)(v4 + 128) & 4) != 0; /*0x1a1655*/
      *(_WORD *)(v7 + 112) = *(_WORD *)(v4 + 100) & 0x7000; /*0x1a1661*/
      PCscheduleTimers(v7); /*0x1a1666*/
      *(_DWORD *)(v7 + 72) = 1; /*0x1a166b*/
      v8 = __readcr0(); /*0x1a1675*/
      LOBYTE(v8) = v8 | 8; /*0x1a1678*/
      __writecr0(v8); /*0x1a167a*/
      *(_DWORD *)(v2 + 44) = *(_DWORD *)v5; /*0x1a167f*/
      *(_DWORD *)(v2 + 32) = *(_DWORD *)(v5 + 4); /*0x1a1685*/
      *(_DWORD *)(v2 + 40) = *(_DWORD *)(v5 + 8); /*0x1a168b*/
      *(_DWORD *)(v2 + 36) = *(_DWORD *)(v5 + 12); /*0x1a1691*/
      *(_DWORD *)(v2 + 16) = *(_DWORD *)(v5 + 16); /*0x1a1697*/
      *(_DWORD *)(v2 + 20) = *(_DWORD *)(v5 + 20); /*0x1a169d*/
      *(_DWORD *)(v2 + 24) = *(_DWORD *)(v5 + 24); /*0x1a16a3*/
      *(_DWORD *)(v2 + 68) = *(_DWORD *)(v5 + 28); /*0x1a16a9*/
      *(_WORD *)(v2 + 72) = *(_WORD *)(v5 + 32); /*0x1a16b0*/
      v9 = *(_DWORD *)(v5 + 36); /*0x1a16b4*/
      *(_DWORD *)(v2 + 64) = v9; /*0x1a16b7*/
      *(_DWORD *)(v2 + 64) = v9 & 0x50DD5 | 0x202; /*0x1a16c6*/
      *(_DWORD *)(v2 + 56) = *(_DWORD *)(v5 + 40); /*0x1a16cc*/
      *(_WORD *)(v2 + 60) = *(_WORD *)(v5 + 44); /*0x1a16d3*/
      if ( (*(_BYTE *)(v5 + 64) & 1) != 0 ) /*0x1a16db*/
      {
        *(_WORD *)(v2 + 12) = *(_WORD *)(v5 + 48); /*0x1a16e1*/
        *(_WORD *)(v2 + 8) = *(_WORD *)(v5 + 52); /*0x1a16e9*/
        *(_WORD *)(v2 + 4) = *(_WORD *)(v5 + 56); /*0x1a16f1*/
        *(_WORD *)v2 = *(_WORD *)(v5 + 60); /*0x1a16f9*/
      }
      else
      {
        *(_DWORD *)(v2 + 64) |= 0x20000u; /*0x1a1700*/
        *(_WORD *)(v2 + 12) = 0; /*0x1a1707*/
        *(_WORD *)(v2 + 8) = 0; /*0x1a170d*/
        *(_WORD *)(v2 + 4) = 0; /*0x1a1713*/
        *(_WORD *)v2 = 0; /*0x1a1719*/
        *(_WORD *)(v2 + 80) = *(_WORD *)(v5 + 48); /*0x1a1722*/
        *(_WORD *)(v2 + 76) = *(_WORD *)(v5 + 52); /*0x1a172a*/
        *(_WORD *)(v2 + 84) = *(_WORD *)(v5 + 56); /*0x1a1732*/
        *(_WORD *)(v2 + 88) = *(_WORD *)(v5 + 60); /*0x1a173a*/
      }
      thread_exception_return(); /*0x1a173e*/
    }
  }
}
