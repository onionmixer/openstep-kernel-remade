/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x109870. */
void __cdecl psignal(unsigned int a1, const char *a2)
{
  task_t v2; // edi
  thread_act_t v3; // ebx
  volatile __int32 *v4; // ebx
  int v5; // eax
  int v6; // [esp+Ch] [ebp-10h]
  thread_act_t target_act; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h]

  if ( (unsigned int)a2 > 0x20 ) /*0x109880*/
    return; /*0x109880*/
  v6 = 1 << ((_BYTE)a2 - 1); /*0x109893*/
  v2 = *(_DWORD *)(a1 + 104); /*0x109896*/
  if ( !v2 || *(_DWORD *)(v2 + 80) ) /*0x1098a1*/
    return; /*0x1098a5*/
  if ( (*(_BYTE *)(a1 + 40) & 0x10) != 0 ) /*0x1098af*/
  {
    v8 = 0; /*0x1098b1*/
  }
  else
  {
    if ( ((*(_BYTE *)(a1 + 22) & 2) == 0 || v6 != 0x40000) && (v6 & *(_DWORD *)(a1 + 32)) != 0 ) /*0x1098d1*/
      return; /*0x1098d1*/
    if ( (*(_BYTE *)(a1 + 22) & 2) != 0 && v6 == 0x40000 || (v6 & *(_DWORD *)(a1 + 28)) == 0 ) /*0x1098ec*/
    {
      v8 = 0; /*0x1098f8*/
      if ( (v6 & *(_DWORD *)(a1 + 36)) != 0 ) /*0x109905*/
        v8 = 2; /*0x109907*/
    }
    else
    {
      v8 = 3; /*0x1098ee*/
    }
  }
  if ( a2 ) /*0x109912*/
  {
    *(_DWORD *)(a1 + 24) |= v6; /*0x109917*/
    switch ( (unsigned int)a2 ) /*0x109925*/
    {
      case 0xFu: /*0x109925*/
        if ( (*(_BYTE *)(a1 + 40) & 0x10) == 0 && !v8 ) /*0x109956*/
          goto LABEL_19; /*0x109956*/
        break; /*0x109956*/
      case 0x11u: /*0x109925*/
      case 0x12u: /*0x109925*/
      case 0x15u: /*0x109925*/
      case 0x16u: /*0x109925*/
        *(_DWORD *)(a1 + 24) &= ~0x40000u; /*0x109964*/
        break; /*0x109964*/
      case 0x13u: /*0x109925*/
LABEL_19:
        *(_DWORD *)(a1 + 24) &= 0xFFCCFFFF; /*0x109958*/
        break; /*0x10995f*/
      default:
        break;
    }
  }
  if ( v8 != 3 ) /*0x10996f*/
  {
    v9 = splhigh(); /*0x10997a*/
    target_act = active_threads; /*0x109983*/
    if ( *(_DWORD *)(active_threads + 12) == v2 ) /*0x109989*/
    {
      v3 = active_threads; /*0x10998b*/
    }
    else
    {
      v4 = (volatile __int32 *)(v2 + 40); /*0x109990*/
      do /*0x1099a6*/
      {
        while ( *v4 ) /*0x109994*/
          ; /*0x109996*/
      }
      while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1099a6*/
      v3 = *(_DWORD *)(v2 + 28); /*0x1099ab*/
      if ( v2 + 28 == v3 ) /*0x1099b0*/
      {
        _InterlockedExchange((volatile __int32 *)(v2 + 40), 0); /*0x1099b4*/
        splx(v9); /*0x1099bb*/
        return; /*0x1099c0*/
      }
      thread_reference(*(_DWORD *)(v2 + 28)); /*0x1099c9*/
      _InterlockedExchange((volatile __int32 *)(v2 + 40), 0); /*0x1099d3*/
    }
    if ( a2 == (const char *)9 && *(char *)(a1 + 21) > 0 ) /*0x1099e0*/
    {
      *(_BYTE *)(a1 + 21) = 0; /*0x1099e2*/
      thread_max_priority(v3, *(_DWORD *)(v3 + 384), 10); /*0x1099f0*/
      thread_priority(v3, 10, 0); /*0x1099fa*/
    }
    if ( (*(_BYTE *)(a1 + 40) & 0x10) != 0 ) /*0x109a06*/
    {
      if ( *(_BYTE *)(a1 + 19) == 6 ) /*0x109a0c*/
      {
LABEL_58:
        splx(v9); /*0x109bb1*/
        if ( target_act != v3 ) /*0x109bc0*/
          thread_deallocate_interrupt(v3); /*0x109bc3*/
        return; /*0x109bc3*/
      }
LABEL_57:
      clear_wait(v3, 2, 1); /*0x109ba4*/
      goto LABEL_58; /*0x109ba9*/
    }
    if ( v8 ) /*0x109a1c*/
    {
      if ( a2 == (const char *)19 ) /*0x109a22*/
      {
        task_resume(v2); /*0x109a29*/
        *(_BYTE *)(a1 + 19) = 3; /*0x109a2e*/
      }
      goto LABEL_57; /*0x109a35*/
    }
    switch ( (unsigned int)a2 ) /*0x109a4b*/
    {
      case 9u: /*0x109a4b*/
        while ( *(int *)(v2 + 68) > 0 ) /*0x109b49*/
          task_resume(v2); /*0x109b3d*/
        *(_BYTE *)(a1 + 19) = 3; /*0x109b4b*/
        while ( *(int *)(v3 + 140) > 0 ) /*0x109b56*/
          thread_resume(v3); /*0x109b59*/
        clear_wait(v3, 3, 0); /*0x109b6f*/
        splx(v9); /*0x109b78*/
        if ( target_act != v3 ) /*0x109b83*/
        {
          mach_msg_abort_rpc(v3); /*0x109b86*/
          thread_deallocate(v3); /*0x109b8c*/
        }
        break; /*0x109b91*/
      case 0x10u: /*0x109a4b*/
      case 0x14u: /*0x109a4b*/
      case 0x17u: /*0x109a4b*/
      case 0x1Cu: /*0x109a4b*/
        *(_DWORD *)(a1 + 24) &= ~v6; /*0x109b35*/
        goto LABEL_58; /*0x109b38*/
      case 0x11u: /*0x109a4b*/
      case 0x12u: /*0x109a4b*/
      case 0x15u: /*0x109a4b*/
      case 0x16u: /*0x109a4b*/
        if ( a2 == (const char *)17 || *(_DWORD *)(a1 + 68) != init_proc ) /*0x109ab2*/
        {
          if ( (*(_BYTE *)(v3 + 76) & 4) != 0 ) /*0x109ad0*/
          {
            if ( *(_DWORD *)active_u == a1 && *(_BYTE *)(a1 + 19) != 5 ) /*0x109b11*/
            {
              v5 = need_ast; /*0x109b17*/
              LOBYTE(v5) = need_ast | 0x20; /*0x109b1c*/
              need_ast = v5; /*0x109b1e*/
            }
          }
          else
          {
            *(_DWORD *)(a1 + 24) &= ~v6; /*0x109ad7*/
            if ( !*(_DWORD *)(v2 + 68) ) /*0x109ada*/
            {
              *(_DWORD *)(a1 + 60) = a2; /*0x109ae7*/
              psignal(*(_DWORD *)(a1 + 68), (const char *)0x14); /*0x109af0*/
              stop(a1); /*0x109af6*/
            }
          }
        }
        else
        {
          psignal(a1, (const char *)9); /*0x109ab7*/
          *(_DWORD *)(a1 + 24) &= ~v6; /*0x109ac1*/
        }
        goto LABEL_58; /*0x109ac7*/
      case 0x13u: /*0x109a4b*/
        task_resume(v2); /*0x109b95*/
        *(_BYTE *)(a1 + 19) = 3; /*0x109b9a*/
        goto LABEL_58; /*0x109ba1*/
      default:
        goto LABEL_57;
    }
  }
}
