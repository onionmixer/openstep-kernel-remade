/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a824. */
unsigned __int32 __cdecl fp_synch(unsigned __int32 a1)
{
  unsigned __int32 result; // eax
  int *v2; // eax
  char v4; // cl

  result = a1; /*0x18a828*/
  if ( dword_1E75F8 == a1 ) /*0x18a831*/
  {
    if ( a1 ) /*0x18a837*/
    {
      v2 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x18a840*/
      _EDX = 0; /*0x18a846*/
      if ( v2 ) /*0x18a84a*/
        _EDX = *v2; /*0x18a84c*/
      if ( _EDX && (v4 = *(_BYTE *)(_EDX + 1304), (v4 & 1) != 0) ) /*0x18a85b*/
      {
        if ( (cpu_config & 3) == 2 ) /*0x18a867*/
        {
          __asm /*0x18a869*/
          {
            clts
            fnsave byte ptr [edx+4ACh]
          }
        }
        *(_BYTE *)(_EDX + 1304) = v4 | 2; /*0x18a875*/
      }
      else
      {
        if ( (cpu_config & 3) == 2 ) /*0x18a88a*/
        {
          _EAX = *(_DWORD *)(a1 + 40) + 124; /*0x18a88f*/
          __asm /*0x18a892*/
          {
            clts
            fnsave byte ptr [eax]
          }
        }
        *(_BYTE *)(*(_DWORD *)(a1 + 40) + 240) |= 2u; /*0x18a89a*/
      }
      return sub_18A7E4(); /*0x18a8a1*/
    }
  }
  else
  {
    result = *(_DWORD *)(a1 + 40); /*0x18a8a8*/
    if ( (*(_BYTE *)(result + 240) & 2) == 0 ) /*0x18a8b2*/
    {
      *(_WORD *)(result + 124) = 639; /*0x18a8b4*/
      *(_WORD *)(result + 128) = 0; /*0x18a8ba*/
      *(_WORD *)(result + 132) = -1; /*0x18a8c3*/
      *(_DWORD *)(result + 136) = 0; /*0x18a8cc*/
      *(_WORD *)(result + 142) = 0; /*0x18a8d6*/
      *(_WORD *)(result + 140) = 0; /*0x18a8df*/
      *(_DWORD *)(result + 144) = 0; /*0x18a8e8*/
      *(_WORD *)(result + 148) = 0; /*0x18a8f2*/
    }
  }
  return result; /*0x18a8fb*/
}
