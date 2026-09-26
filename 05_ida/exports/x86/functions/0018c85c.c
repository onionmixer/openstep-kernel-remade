/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c85c. */
char __cdecl intr_handler(int a1)
{
  int v1; // ebx
  int *v2; // esi
  int v3; // eax
  int v4; // ecx
  int v5; // edi
  __int16 v6; // ax
  int v7; // ebx
  unsigned __int16 v8; // cx

  v1 = *(_DWORD *)(a1 + 48) - 64; /*0x18c86e*/
  v2 = &dword_1E7624[3 * v1]; /*0x18c874*/
  ++intr_cnt; /*0x18c87b*/
  if ( v1 == 7 && (LOBYTE(v3) = __inbyte(0x20u), (v3 & 0x80u) == 0)
    || v1 == 15 && (LOBYTE(v3) = __inbyte(0xA0u), (v3 & 0x80u) == 0) )
  {
    ++dword_1F7A18; /*0x18c89f*/
  }
  else
  {
    v4 = v2[2]; /*0x18c8ac*/
    v5 = dword_1E7718; /*0x18c8af*/
    if ( v4 != dword_1E7718 ) /*0x18c8b7*/
    {
      v6 = word_1E771E | word_1E76E4[v4]; /*0x18c8c1*/
      if ( word_1E771C != v6 ) /*0x18c8d3*/
      {
        word_1E771C = word_1E771E | word_1E76E4[v4]; /*0x18c8d5*/
        __outbyte(0x21u, v6); /*0x18c8e5*/
        _InterlockedIncrement(dword_1E7618); /*0x18c8e6*/
        __outbyte(0xA1u, HIBYTE(v6)); /*0x18c8fd*/
        _InterlockedIncrement(dword_1E7618); /*0x18c8fe*/
      }
      dword_1E7718 = v4; /*0x18c905*/
    }
    __outbyte(0x20u, 0x20u); /*0x18c914*/
    _InterlockedIncrement(dword_1E7618); /*0x18c915*/
    __outbyte(0xA0u, 0x20u); /*0x18c923*/
    _InterlockedIncrement(dword_1E7618); /*0x18c924*/
    if ( v2[1] )
    {
      v7 = dword_1E7714; /*0x18c944*/
      if ( dword_1E7714 >= v2[2] ) /*0x18c94f*/
      {
        ++dword_1F7A14; /*0x18c9c0*/
        v3 = v2[2]; /*0x18c9c6*/
        dword_1E76F4[v3] = (int)v2; /*0x18c9c9*/
      }
      else
      {
        dword_1E7714 = v2[2]; /*0x18c951*/
        _enable(); /*0x18c957*/
        LOBYTE(v3) = ((int (__stdcall *)(int, int, int))v2[1])(*v2, a1, v7); /*0x18c966*/
        _disable(); /*0x18c968*/
        dword_1E7714 = v7; /*0x18c969*/
        if ( dword_1E7718 != v5 ) /*0x18c975*/
        {
          v8 = word_1E771E | word_1E76E4[v5]; /*0x18c97f*/
          if ( word_1E771C != v8 ) /*0x18c98d*/
          {
            word_1E771C = word_1E771E | word_1E76E4[v5]; /*0x18c98f*/
            __outbyte(0x21u, v8); /*0x18c99d*/
            _InterlockedIncrement(dword_1E7618); /*0x18c99e*/
            LOWORD(v3) = HIBYTE(v8); /*0x18c9a7*/
            __outbyte(0xA1u, HIBYTE(v8)); /*0x18c9b0*/
            _InterlockedIncrement(dword_1E7618); /*0x18c9b1*/
          }
          dword_1E7718 = v5; /*0x18c9b8*/
        }
      }
    }
    else
    {
      LOBYTE(v3) = printf("intr: dropped IRQ %d\n", v1);
    }
  }
  return v3; /*0x18c9d3*/
}
