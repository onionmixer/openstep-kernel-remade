/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a4a8. */
char sub_18A4A8()
{
  int v0; // esi
  unsigned int v3; // edx
  char v5; // dl
  char v7; // bl
  int v8; // ecx
  int *v9; // eax
  char v11; // bl
  thread_act_t v13; // ebx
  int *v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  char v17; // dl
  char v20; // cl

  v0 = active_threads; /*0x18a4ad*/
  if ( active_threads == dword_1E75F8 ) /*0x18a4ba*/
  {
    _EAX = *(int **)(*(_DWORD *)(active_threads + 40) + 236); /*0x18a4c3*/
    _ECX = 0; /*0x18a4c9*/
    if ( _EAX ) /*0x18a4cd*/
      _ECX = *_EAX; /*0x18a4cf*/
    if ( _ECX ) /*0x18a4d3*/
    {
      v3 = *(_DWORD *)(_ECX + 132); /*0x18a4d9*/
      if ( v3 > 7 ) /*0x18a4e2*/
        _EAX = nullptr; /*0x18a4f4*/
      else
        _EAX = (int *)(_ECX + 132 * v3 + 136); /*0x18a4eb*/
      if ( _EAX[18] ) /*0x18a4f6*/
      {
        if ( (*(_BYTE *)(_ECX + 1304) & 1) != 0 ) /*0x18a503*/
          goto LABEL_56; /*0x18a503*/
        if ( (cpu_config & 3) == 2 ) /*0x18a513*/
        {
          _EAX = *(_DWORD *)(active_threads + 40) + 124; /*0x18a518*/
          __asm /*0x18a51b*/
          {
            clts
            fnsave byte ptr [eax]
          }
        }
        *(_BYTE *)(*(_DWORD *)(v0 + 40) + 240) |= 2u; /*0x18a523*/
        goto LABEL_42; /*0x18a52a*/
      }
      v5 = *(_BYTE *)(_ECX + 1304); /*0x18a530*/
      if ( (v5 & 1) != 0 ) /*0x18a539*/
      {
        if ( (cpu_config & 3) == 2 ) /*0x18a549*/
        {
          __asm /*0x18a54b*/
          {
            clts
            fnsave byte ptr [ecx+4ACh]
          }
        }
        *(_BYTE *)(_ECX + 1304) = v5 | 2; /*0x18a557*/
        _EDX = *(_DWORD *)(v0 + 40); /*0x18a55d*/
        v7 = *(_BYTE *)(_EDX + 240); /*0x18a560*/
        if ( (v7 & 2) != 0 ) /*0x18a569*/
        {
          LOBYTE(_EAX) = cpu_config & 3; /*0x18a571*/
          if ( (cpu_config & 3) == 2 ) /*0x18a575*/
          {
            __asm /*0x18a577*/
            {
              clts
              frstor byte ptr [edx+7Ch]
            }
          }
          *(_BYTE *)(_EDX + 240) = v7 & 0xFD; /*0x18a57f*/
        }
        else
        {
          *(_WORD *)(_EDX + 124) = 639; /*0x18a588*/
          *(_WORD *)(_EDX + 128) = 0; /*0x18a58e*/
          *(_WORD *)(_EDX + 132) = -1; /*0x18a597*/
          *(_DWORD *)(_EDX + 136) = 0; /*0x18a5a0*/
          *(_WORD *)(_EDX + 142) = 0; /*0x18a5aa*/
          *(_WORD *)(_EDX + 140) = 0; /*0x18a5b3*/
          *(_DWORD *)(_EDX + 144) = 0; /*0x18a5bc*/
          *(_WORD *)(_EDX + 148) = 0; /*0x18a5c6*/
          LOBYTE(_EAX) = cpu_config & 3; /*0x18a5d5*/
          if ( (cpu_config & 3) == 2 ) /*0x18a5d9*/
          {
            _EAX = (int *)(*(_DWORD *)(v0 + 40) + 124); /*0x18a5de*/
            __asm /*0x18a5e1*/
            {
              clts
              frstor byte ptr [eax]
            }
          }
        }
        *(_BYTE *)(_ECX + 1304) &= ~1u; /*0x18a5e5*/
      }
    }
  }
  else
  {
    v8 = dword_1E75F8; /*0x18a5f4*/
    if ( dword_1E75F8 ) /*0x18a5f8*/
    {
      v9 = *(int **)(*(_DWORD *)(dword_1E75F8 + 40) + 236); /*0x18a5fd*/
      _EDX = 0; /*0x18a603*/
      if ( v9 ) /*0x18a607*/
        _EDX = *v9; /*0x18a609*/
      if ( _EDX && (v11 = *(_BYTE *)(_EDX + 1304), (v11 & 1) != 0) ) /*0x18a618*/
      {
        if ( (cpu_config & 3) == 2 ) /*0x18a624*/
        {
          __asm /*0x18a626*/
          {
            clts
            fnsave byte ptr [edx+4ACh]
          }
        }
        *(_BYTE *)(_EDX + 1304) = v11 | 2; /*0x18a632*/
      }
      else
      {
        if ( (cpu_config & 3) == 2 ) /*0x18a646*/
        {
          _EAX = *(_DWORD *)(dword_1E75F8 + 40) + 124; /*0x18a64b*/
          __asm /*0x18a64e*/
          {
            clts
            fnsave byte ptr [eax]
          }
        }
        *(_BYTE *)(*(_DWORD *)(v8 + 40) + 240) |= 2u; /*0x18a656*/
      }
      sub_18A7E4(); /*0x18a65d*/
    }
    dword_1E75F8 = v0; /*0x18a662*/
    v13 = active_threads; /*0x18a668*/
    v14 = *(int **)(*(_DWORD *)(active_threads + 40) + 236); /*0x18a671*/
    _ECX = 0; /*0x18a677*/
    if ( v14 ) /*0x18a67b*/
      _ECX = *v14; /*0x18a67d*/
    if ( _ECX ) /*0x18a681*/
    {
      v15 = *(_DWORD *)(_ECX + 132); /*0x18a687*/
      if ( v15 > 7 ) /*0x18a690*/
        v16 = 0; /*0x18a6a4*/
      else
        v16 = _ECX + 132 * v15 + 136; /*0x18a699*/
      if ( *(_DWORD *)(v16 + 72) ) /*0x18a6a6*/
      {
LABEL_42:
        v17 = *(_BYTE *)(_ECX + 1304); /*0x18a6b0*/
        if ( (v17 & 2) != 0 ) /*0x18a6b9*/
        {
          LOBYTE(_EAX) = cpu_config & 3; /*0x18a6c1*/
          if ( (cpu_config & 3) == 2 ) /*0x18a6c5*/
          {
            __asm /*0x18a6c7*/
            {
              clts
              frstor byte ptr [ecx+4ACh]
            }
          }
          *(_BYTE *)(_ECX + 1304) = v17 & 0xFD; /*0x18a6d2*/
        }
        else
        {
          _EDX = _ECX + 1196; /*0x18a6dc*/
          *(_WORD *)(_ECX + 1196) = 895; /*0x18a6e2*/
          *(_WORD *)(_ECX + 1200) = 0; /*0x18a6eb*/
          *(_WORD *)(_ECX + 1204) = -1; /*0x18a6f4*/
          *(_DWORD *)(_ECX + 1208) = 0; /*0x18a6fd*/
          *(_WORD *)(_ECX + 1214) = 0; /*0x18a707*/
          *(_WORD *)(_ECX + 1212) = 0; /*0x18a710*/
          *(_DWORD *)(_ECX + 1216) = 0; /*0x18a719*/
          *(_WORD *)(_ECX + 1220) = 0; /*0x18a723*/
          LOBYTE(_EAX) = cpu_config & 3; /*0x18a732*/
          if ( (cpu_config & 3) == 2 ) /*0x18a736*/
          {
            __asm /*0x18a738*/
            {
              clts
              frstor byte ptr [edx]
            }
          }
        }
        *(_BYTE *)(_ECX + 1304) |= 1u; /*0x18a73c*/
        goto LABEL_56; /*0x18a743*/
      }
      *(_BYTE *)(_ECX + 1304) &= ~1u; /*0x18a748*/
    }
    _EDX = *(_DWORD *)(v13 + 40); /*0x18a74f*/
    v20 = *(_BYTE *)(_EDX + 240); /*0x18a752*/
    if ( (v20 & 2) != 0 ) /*0x18a75b*/
    {
      LOBYTE(_EAX) = cpu_config & 3; /*0x18a763*/
      if ( (cpu_config & 3) == 2 ) /*0x18a767*/
      {
        __asm /*0x18a769*/
        {
          clts
          frstor byte ptr [edx+7Ch]
        }
      }
      *(_BYTE *)(_EDX + 240) = v20 & 0xFD; /*0x18a771*/
    }
    else
    {
      *(_WORD *)(_EDX + 124) = 639; /*0x18a77c*/
      *(_WORD *)(_EDX + 128) = 0; /*0x18a782*/
      *(_WORD *)(_EDX + 132) = -1; /*0x18a78b*/
      *(_DWORD *)(_EDX + 136) = 0; /*0x18a794*/
      *(_WORD *)(_EDX + 142) = 0; /*0x18a79e*/
      *(_WORD *)(_EDX + 140) = 0; /*0x18a7a7*/
      *(_DWORD *)(_EDX + 144) = 0; /*0x18a7b0*/
      *(_WORD *)(_EDX + 148) = 0; /*0x18a7ba*/
      LOBYTE(_EAX) = cpu_config & 3; /*0x18a7c9*/
      if ( (cpu_config & 3) == 2 ) /*0x18a7cd*/
      {
        _EAX = (int *)(*(_DWORD *)(v13 + 40) + 124); /*0x18a7d2*/
        __asm /*0x18a7d5*/
        {
          clts
          frstor byte ptr [eax]
        }
      }
    }
  }
LABEL_56:
  __asm { clts } /*0x18a7d9*/
  return (char)_EAX; /*0x18a7de*/
}
